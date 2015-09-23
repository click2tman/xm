<?php
/**
 * @file
 * dev_portal_partner_developer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dev_portal_partner_developer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dev_portal_partner_developer_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function dev_portal_partner_developer_eck_bundle_info() {
  $items = array(
    'partner_developers_developers' => array(
      'machine_name' => 'partner_developers_developers',
      'entity_type' => 'partner_developers',
      'name' => 'developers',
      'label' => 'Developers',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function dev_portal_partner_developer_eck_entity_type_info() {
  $items = array(
    'partner_developers' => array(
      'name' => 'partner_developers',
      'label' => 'Partner Developers',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
        'uuid' => array(
          'label' => 'UUID',
          'type' => 'text',
          'behavior' => 'uuid',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function dev_portal_partner_developer_default_rules_link() {
  $items = array();
  $items['disable_developer_account'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Disable",
      "link_type" : "confirm",
      "bundles" : { "developers" : "developers" },
      "entity_link" : 1,
      "view_mode" : { "full" : "full" },
      "confirm_question" : "Do you really want to disable this developer account?",
      "confirm_description" : "The developer wont be able to login and create apps if you disable the account"
    },
    "name" : "disable_developer_account",
    "label" : "Disable Developer Account",
    "path" : "disable_developer_account",
    "entity_type" : "partner_developers",
    "rdf_mapping" : []
  }');
  $items['enable_developer_account'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Enable",
      "link_type" : "confirm",
      "bundles" : { "developers" : "developers" },
      "entity_link" : 1,
      "view_mode" : { "full" : "full" },
      "confirm_question" : "Do you really want to enable this developer account?",
      "confirm_description" : "If you enable the account, the developer will be able to login and create apps"
    },
    "name" : "enable_developer_account",
    "label" : "Enable Developer Account",
    "path" : "enable_developers_account_01",
    "entity_type" : "partner_developers",
    "rdf_mapping" : []
  }');
  return $items;
}
