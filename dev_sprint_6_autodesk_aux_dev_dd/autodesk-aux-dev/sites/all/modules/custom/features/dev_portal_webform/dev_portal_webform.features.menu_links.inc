<?php
/**
 * @file
 * dev_portal_webform.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dev_portal_webform_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_salesforce-webform:admin/config/services/salesforce_webform
  $menu_links['management_salesforce-webform:admin/config/services/salesforce_webform'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/salesforce_webform',
    'router_path' => 'admin/config/services/salesforce_webform',
    'link_title' => 'Salesforce Webform',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure webform salesforce integration settings.',
      ),
      'identifier' => 'management_salesforce-webform:admin/config/services/salesforce_webform',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_web-services:admin/config/services',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Salesforce Webform');

  return $menu_links;
}
