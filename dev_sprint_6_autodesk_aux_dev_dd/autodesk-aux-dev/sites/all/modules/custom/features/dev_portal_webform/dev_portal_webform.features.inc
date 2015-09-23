<?php
/**
 * @file
 * dev_portal_webform.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dev_portal_webform_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dev_portal_webform_node_info() {
  $items = array(
    'autodesk_forms' => array(
      'name' => t('Autodesk Forms'),
      'base' => 'node_content',
      'description' => t('Use Autodesk Forms to add a webform to be submitted by users'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
