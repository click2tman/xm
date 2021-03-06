<?php
/**
 * @file
 * dev_portal_theme_settings.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function dev_portal_theme_settings_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'home_page_callouts';
  $bean_type->label = 'Home Page callouts';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['home_page_callouts'] = $bean_type;

  return $export;
}
