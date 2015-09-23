<?php
/**
 * @file
 * dev_portal_apiproducts_by_role.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dev_portal_apiproducts_by_role_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
