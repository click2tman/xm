<?php
/**
 * @file
 * dev_portal_base_fields.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dev_portal_base_fields_taxonomy_default_vocabularies() {
  return array(
    'smartdocs_models' => array(
      'name' => 'SmartDocs models',
      'machine_name' => 'smartdocs_models',
      'description' => 'Enumerates all API models',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'smartdocs_tags' => array(
      'name' => 'SmartDocs tags',
      'machine_name' => 'smartdocs_tags',
      'description' => 'Enables tagging of methods',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'smartdocs_verbs' => array(
      'name' => 'SmartDocs verbs',
      'machine_name' => 'smartdocs_verbs',
      'description' => 'Enumerates all possible HTTP verbs for your API',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
