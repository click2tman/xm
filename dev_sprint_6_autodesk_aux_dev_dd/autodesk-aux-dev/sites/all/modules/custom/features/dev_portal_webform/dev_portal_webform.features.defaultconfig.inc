<?php
/**
 * @file
 * dev_portal_webform.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function dev_portal_webform_defaultconfig_features() {
  return array(
    'dev_portal_webform' => array(
      'strongarm' => 'strongarm',
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function dev_portal_webform_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sfweb2lead_webform_debug';
  $strongarm->value = 0;
  $export['sfweb2lead_webform_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sfweb2lead_webform_mapping_settings';
  $strongarm->value = array(
    'contact_first_name' => '00N300000052Vjq',
    'contact_last_name' => '00N300000052VkJ',
    'contact_email_address' => 'email',
    'contact_product_service' => '00NV0000000o16A',
    'contact_message' => '00NV0000000o16F',
    'contact_telephone' => 'phone',
    'orgid' => 'orgid',
    'external' => 'external',
  );
  $export['sfweb2lead_webform_mapping_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sfweb2lead_webform_oid';
  $strongarm->value = '00DV00000087wPu';
  $export['sfweb2lead_webform_oid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sfweb2lead_webform_url';
  $strongarm->value = 'https://autodesk--ADSKSFDCDV.cs12.my.salesforce.com/servlet/servlet.WebToCase?encoding=UTF-8';
  $export['sfweb2lead_webform_url'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function dev_portal_webform_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer salesforce webform'.
  $permissions['administer salesforce webform'] = array(
    'name' => 'administer salesforce webform',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'sfweb2lead_webform',
  );

  return $permissions;
}
