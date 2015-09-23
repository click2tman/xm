<?php
/**
 * @file
 * dev_portal_webform.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dev_portal_webform_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_autodesk_forms';
  $strongarm->value = 'edit-workflow';
  $export['additional_settings__active_tab_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_autodesk_forms';
  $strongarm->value = 0;
  $export['comment_anonymous_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_autodesk_forms';
  $strongarm->value = '0';
  $export['comment_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_autodesk_forms';
  $strongarm->value = 1;
  $export['comment_default_mode_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_autodesk_forms';
  $strongarm->value = '50';
  $export['comment_default_per_page_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_autodesk_forms';
  $strongarm->value = 1;
  $export['comment_form_location_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_autodesk_forms';
  $strongarm->value = '1';
  $export['comment_preview_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_autodesk_forms';
  $strongarm->value = 1;
  $export['comment_subject_field_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__autodesk_forms';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_autodesk_forms';
  $strongarm->value = array();
  $export['menu_options_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_autodesk_forms';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_autodesk_forms';
  $strongarm->value = array(
    0 => 'revision',
    1 => 'moderation',
  );
  $export['node_options_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_autodesk_forms';
  $strongarm->value = '1';
  $export['node_preview_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_autodesk_forms';
  $strongarm->value = 0;
  $export['node_submitted_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_autodesk_forms_pattern';
  $strongarm->value = 'form/[node:title]';
  $export['pathauto_node_autodesk_forms_pattern'] = $strongarm;

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

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_autodesk_forms';
  $strongarm->value = 1;
  $export['webform_node_autodesk_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_autodesk_forms';
  $strongarm->value = 'needs_review';
  $export['workbench_moderation_default_state_autodesk_forms'] = $strongarm;

  return $export;
}
