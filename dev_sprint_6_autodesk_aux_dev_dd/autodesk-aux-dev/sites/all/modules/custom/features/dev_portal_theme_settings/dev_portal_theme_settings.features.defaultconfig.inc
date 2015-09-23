<?php
/**
 * @file
 * dev_portal_theme_settings.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function dev_portal_theme_settings_defaultconfig_features() {
  return array(
    'dev_portal_theme_settings' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function dev_portal_theme_settings_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'autodesk';
  $export['theme_default'] = $strongarm;

  return $export;
}
