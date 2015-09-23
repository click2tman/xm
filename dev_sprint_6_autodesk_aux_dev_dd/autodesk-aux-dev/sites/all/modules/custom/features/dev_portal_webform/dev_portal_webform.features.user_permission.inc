<?php
/**
 * @file
 * dev_portal_webform.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dev_portal_webform_user_default_permissions() {
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
