<?php
/**
 * @file
 * dev_portal_partner_developer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dev_portal_partner_developer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_partner_developers_developers';
  $strongarm->value = '1';
  $export['auto_entitylabel_partner_developers_developers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_partner_developers_developers';
  $strongarm->value = '[partner_developers:field_first_name] [partner_developers:field-last-name]';
  $export['auto_entitylabel_pattern_partner_developers_developers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_partner_developers_developers';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_partner_developers_developers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eck_clear_caches';
  $strongarm->value = FALSE;
  $export['eck_clear_caches'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_partner_developers__developers';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(
        'rules_links_disable_developer_account' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_partner_developers__developers'] = $strongarm;

  return $export;
}
