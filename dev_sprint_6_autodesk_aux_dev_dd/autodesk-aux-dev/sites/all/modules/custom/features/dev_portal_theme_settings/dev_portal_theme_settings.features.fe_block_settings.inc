<?php
/**
 * @file
 * dev_portal_theme_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dev_portal_theme_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-building-an-app-home'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'building-an-app-home',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'autodesk' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'autodesk',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bean-dev-homepage-header'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dev-homepage-header',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'autodesk' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'autodesk',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bean-footer'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'footer',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'autodesk' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'autodesk',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['superfish-1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 1,
    'module' => 'superfish',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'autodesk' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'autodesk',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
