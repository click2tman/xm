<?php
/**
 * @file
 * dev_portal_faqs.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dev_portal_faqs_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_detailed_question'
  $field_bases['field_detailed_question'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_detailed_question',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
