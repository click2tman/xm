<?php
/**
 * @file
 * dev_portal_partner_developer.features.content_menu_links.inc
 */

/**
 * Implements hook_content_menu_links_defaults().
 */
function dev_portal_partner_developer_content_menu_links_defaults() {
  $menu_links = array();

  // Exported menu link: management:admin/structure/entity-type
  $menu_links['management:admin/structure/entity-type'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/entity-type',
    'router_path' => 'admin/structure/entity-type',
    'link_title' => 'Entity types',
    'options' => array(
      'attributes' => array(
        'title' => 'A centralized administrative section for entity types',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management_add-developers:admin/structure/entity-type/partner_developers/developers/add
  $menu_links['management_add-developers:admin/structure/entity-type/partner_developers/developers/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/entity-type/partner_developers/developers/add',
    'router_path' => 'admin/structure/entity-type/partner_developers/developers/add',
    'link_title' => 'Add Developers',
    'options' => array(
      'attributes' => array(
        'title' => 'Add an entity of type Partner Developers with bundle Developers',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: management_developers:admin/structure/entity-type/partner_developers/developers
  $menu_links['management_developers:admin/structure/entity-type/partner_developers/developers'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/entity-type/partner_developers/developers',
    'router_path' => 'admin/structure/entity-type/partner_developers/developers',
    'link_title' => 'Developers',
    'options' => array(
      'attributes' => array(
        'title' => 'View all entites of type Partner Developers with bundle Developers',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: management_partner-developers:admin/structure/entity-type/partner_developers
  $menu_links['management_partner-developers:admin/structure/entity-type/partner_developers'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/entity-type/partner_developers',
    'router_path' => 'admin/structure/entity-type/partner_developers',
    'link_title' => 'Partner Developers',
    'options' => array(
      'attributes' => array(
        'title' => 'View all the bundles for \'Partner Developers\'',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_path' => 'admin/structure/entity-type',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add Developers');
  t('Developers');
  t('Entity types');
  t('Partner Developers');


  return $menu_links;
}
