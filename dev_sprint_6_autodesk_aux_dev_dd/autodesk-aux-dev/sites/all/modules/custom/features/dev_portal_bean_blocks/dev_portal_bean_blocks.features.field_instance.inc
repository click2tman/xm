<?php
/**
 * @file
 * dev_portal_bean_blocks.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dev_portal_bean_blocks_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bean-home_page_callouts-field_callout_description'
  $field_instances['bean-home_page_callouts-field_callout_description'] = array(
    'bundle' => 'home_page_callouts',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_callout_description',
    'label' => 'Callout description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Callout description');

  return $field_instances;
}
