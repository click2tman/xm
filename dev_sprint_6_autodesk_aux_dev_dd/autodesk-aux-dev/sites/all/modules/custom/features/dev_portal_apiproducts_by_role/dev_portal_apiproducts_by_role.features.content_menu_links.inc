<?php
/**
 * @file
 * dev_portal_apiproducts_by_role.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function dev_portal_apiproducts_by_role_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: management_api-product-role-access:admin/config/devconnect/apiproduct-access
  $menu_links['management_api-product-role-access:admin/config/devconnect/apiproduct-access'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/devconnect/apiproduct-access',
    'router_path' => 'admin/config/devconnect/apiproduct-access',
    'link_title' => 'API Product Role Access',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings controlling which roles may access which API Products.',
      ),
      'identifier' => 'management_api-product-role-access:admin/config/devconnect/apiproduct-access',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_path' => 'admin/config/devconnect',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('API Product Role Access');


  return $menu_links;
}
