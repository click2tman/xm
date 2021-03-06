<?php

/**
 * @file
 * Definition of ModuleBuider\Task\Collect.
 */

namespace ModuleBuider\Task;

/**
 * Task handler for collecting and processing definitions for Drupal components.
 *
 * This will do different things depending on the core Drupal version:
 *  - on D5/6, this downloads documentation files from drupal.org containing
 *    definitions of hooks.
 *  - on D7, this collects hook documentation files from the current site.
 *  - on D8, this collects data about plugins as well as hooks.
 */
class Collect extends Base {

  /**
   * The sanity level this task requires to operate.
   */
  protected $sanity_level = 'hook_directory';

  /**
   * Collect data about Drupal components from the current site's codebase.
   */
  public function collectComponentData() {
    $this->collectHooks();
  }

  /**
   * Collect hook api.php documentation files from sources and process them.
   */
  protected function collectHooks() {
    // Update the hook documentation.
    $hook_files = $this->gatherHookDocumentationFiles();

    // Process the hook files.
    $this->processHookData($hook_files);
  }

  /**
   * Gather hook documentation files.
   *
   * @return
   *  Array of data about hook files suitable for passing to processHookData().
   *  The array keys are the source filenames, and therefore must be unique. If
   *  there is a possibility of filename clash these must be rendered safe, for
   *  example by prefixing the module name.
   *  Each item has the following properties:
   *  - path: The full path to this file
   *  - url: (internal to this handler) URL to download this file from.
   *  - original: (probably not used; just here for interest) the full path this
   *    file was copied from.
   *  - destination: The module code file where the hooks from this hook data
   *    file should be saved by code generation. This may contain placeholders,
   *    for instance, '%module.views.inc'.
   *  - hook_destinations: Per-hook overrides to destination.
   *  - group: The group this file's hooks belong to. Usually this just the
   *    name of the source file with the 'api.php' suffix removed.
   *  - module: The module that provided this file. WARNING: this is not
   *    entirely reliable!
   * Example:
   * @code
   *  [system.core.php] => array(
   *    [path]        => /Users/you/data/drupal_hooks/7/system.api.php
   *    [url]         => (not used on 7)
   *    [original]    => /Users/joachim/Sites/7-drupal/modules/system/system.api.php
   *    [destination] => %module.module
   *    [group]       => core
   *    [module]      => node
   * @endcode
   */
  protected function gatherHookDocumentationFiles() {
    // Needs to be overridden by subclasses.
  }

  /**
   * Builds complete hook data array from downloaded files and stores in a file.
   *
   * (Replaces module_builder_process_hook_data().)
   *
   * @param hook_file_data
   *  An array of data about the files to process, keyed by (safe) filename:
   *   -[MODULE.FILENAME] => Array // eg system.core.php
   *     - [path] => full path to the file
   *     - [destination] => %module.module
   *     - [group] => GROUP  // eg core
   *     - [hook_destinations] => array(%module.foo => hook_foo, etc)
   *     - [hook_dependencies] => array()
   *  This is the same format as returned by update.inc.
   *
   * @return
   *  An array keyed by originating file of the following form:
   *     [GROUP] => array(  // grouping for UI.
           [hook_foo] => array(
             [name] => hook_foo
             [definition] => function hook_foo($node, $teaser = FALSE, $page = FALSE)
             [description] => Description.
             [destination] => Destination module file for hook code from this file.
             ... further properties:

             'type' => $hook_data_raw['type'][$key],
             'name' => $hook,
             'definition'  => $hook_data_raw['definitions'][$key],
             'description' => $hook_data_raw['descriptions'][$key],
             // TODO: Don't store this, just use it to figure out
             // callback dependencies!
             //'documentation' => $hook_data_raw['documentation'][$key],
             'destination' => $destination,
             'dependencies'  => $hook_dependencies,
             'group'       => $group,
             'file_path'   => $file_data['path'],
             'body'        => $hook_data_raw['bodies'][$key],

   */
  protected function processHookData($hook_file_data) {
    //print_r($hook_file_data);

    // check file_exists?

    /*
    // Developer trapdoor for generating the sample hook definitions file for
    // our tests. This limits the number of files to just a few from core.
    $intersect = array(
      'system.api.php',
      'node.api.php',
    );
    $hook_file_data = array_intersect_key($hook_file_data, array_fill_keys($intersect, TRUE));
    // End.
    */

    // Sort the files into a better order than just random.
    // TODO: allow for some control over this, eg frequently used core,
    // then rarer core, then contrib in the order defined by the MB hook.
    ksort($hook_file_data);

    // Build list of hooks
    $hook_groups = array();
    foreach ($hook_file_data as $file => $file_data) {
      $hook_data_raw = $this->processHookFile($file_data['path']);

      $file_name = basename($file, '.php');
      $group = $file_data['group'];

      // Get info about hooks from Drupal.
      $hook_info = $this->getHookInfo($file_data);

      // Create an array in the form of:
      // array(
      //   'filename' => array(
      //     array('hook' => 'hook_foo', 'description' => 'hook_foo description'),
      //     ...
      //   ),
      //   ...
      // );
      foreach ($hook_data_raw['names'] as $key => $hook) {
        // The destination is possibly specified per-hook; if not, then given
        // for the whole file.
        if (isset($file_data['hook_destinations'][$hook])) {
          $destination = $file_data['hook_destinations'][$hook];
        }
        else {
          $destination = $file_data['destination'];
        }

        // Also try to get destinations from hook_hook_info().
        // Argh why don't we have the short name here yet????
        // @todo: clean up!
        $short_name = substr($hook, 5);
        if (isset($hook_info[$short_name])) {
          //print_r($hook_info);
          $destination = '%module.' . $hook_info[$short_name]['group'] . '.inc';
        }

        // Process hook dependendies for the file.
        $hook_dependencies = array();
        if (isset($file_data['hook_dependencies'])) {
          // Incoming data is of the form:
          //  'required hook' => array('dependent hooks')
          // where the latter may be a regexp.
          foreach ($file_data['hook_dependencies'] as $required_hook => $dependency_data) {
            foreach ($dependency_data as $match) {
              if (preg_match("@$match@", $hook)) {
                $hook_dependencies[] = $required_hook;
              }
            }
          }
        }

        // See if the hook has any callbacks as dependencies. We assume that
        // mention of a string of the form 'callback_foo()' means it's needed
        // for the hook.
        // TODO: see if there's a way to label this in the resulting source
        // as associated with the hook that requested this.
        $matches = array();
        preg_match_all("@(callback_\w+)\(\)@", $hook_data_raw['documentation'][$key], $matches);
        if (!empty($matches[1])) {
          $hook_dependencies += $matches[1];
        }

        // Because we're working through the raw data array, we keep the incoming
        // sort order.
        // But if there are multiple hook files for one module / group, then
        // they will go sequentially one after the other.
        // TODO: should this be improved, eg to group also by filename?
        $hook_groups[$group][$hook] = array(
          'type' => $hook_data_raw['type'][$key],
          'name' => $hook,
          'definition'  => $hook_data_raw['definitions'][$key],
          'description' => $hook_data_raw['descriptions'][$key],
          // Don't store this!! TODO!! just use it for callback dependencies!!!
          //'documentation' => $hook_data_raw['documentation'][$key],
          'destination' => $destination,
          'dependencies'  => $hook_dependencies,
          'group'       => $group,
          'file_path'   => $file_data['path'],
          'body'        => $hook_data_raw['bodies'][$key],
        );
        //dsm($hook_groups);
        //drush_print_r($hook_groups);

      } // foreach hook_data
    } // foreach files

    //dsm($hook_groups);
    //print_r($hook_groups);

    // Write the processed data to a file.
    $directory = $this->environment->hooks_directory;
    $serialized = serialize($hook_groups);
    file_put_contents("$directory/hooks_processed.php", $serialized);

    return $hook_groups;
  }

  /**
   * Extracts raw hook data from a downloaded hook documentation file.
   *
   * @param string $filepath
   *   Path to hook file.
   *
   * @return array
   *   Array of hook data, in different arrays, where each array is keyed
   *   numerically and all the indexes match up. The arrays are:
   *    - 'type': Whether this is a hook or a callback.
   *    - 'descriptions': Each hook's user-friendly description, taken from the
   *      first line of the PHPdoc.
   *    - 'documentation': The rest of the PHPdoc.
   *    - 'definitions: Each hook's entire function declaration: "function name($params)"
   *    - 'names': The long names of the hooks, i.e. 'hook_foo'.
   *    - 'bodies': The function bodies of each hook.
   */
  protected function processHookFile($filepath) {
    $contents = file_get_contents("$filepath");

    // The pattern for extracting function data: capture first line of doc,
    // function declaration, and hook name.
    $pattern = '[
             / \* \* \n     # start phpdoc
            \  \* \  ( .* ) \n  # first line of phpdoc: capture the text for the description
      ( (?: \  \* .* \n )* )  # lines of phpdoc: capture the documentation
            \  \* /  \n     # end phpdoc
           ( function \ ( ( hook | callback ) \w+ ) .* ) \ { # function declaration: capture...
      #    ^ entire definition and name
      #                 ^ function name
      #                   ^ whether this is a hook or a callback
       ( (?: .* \n )*? )    # function body: capture example code
           ^ }
    ]mx';

    preg_match_all($pattern, $contents, $matches);

    // We don't care about the full matches.
    //array_shift($matches);

    $data = array(
      'descriptions'  => $matches[1],
      'documentation' => $matches[2],
      'definitions'   => $matches[3],
      'names'         => $matches[4],
      'type'          => $matches[5],
      'bodies'        => $matches[6],
    );

    return $data;
  }

  /**
   * Get info about hooks from Drupal.
   *
   * This invokes hook_hook_info().
   *
   * @param $file_data
   *  An array of file data for a hook documentation file.
   *
   * @return
   *  The data from the implementation of hook_hook_info() for the module that
   *  provided the documentation file.
   */
  protected function getHookInfo($file_data) {
    // Note that the 'module' key is flaky: some modules use a different name
    // for their api.php file.
    $module = $file_data['module'];
    $hook_info = array();
    if (module_hook($module, 'hook_info')) {
      $hook_info = module_invoke($module, 'hook_info');
    }

    return $hook_info;
  }

}
