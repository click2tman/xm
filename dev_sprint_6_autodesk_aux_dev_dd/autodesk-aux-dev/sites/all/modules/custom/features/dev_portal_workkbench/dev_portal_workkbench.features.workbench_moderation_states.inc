<?php
/**
 * @file
 * dev_portal_workkbench.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function dev_portal_workkbench_workbench_moderation_export_states() {
  $items = array(
    'draft' => array(
      'name' => 'draft',
      'label' => 'Draft',
      'description' => 'Work in progress',
      'weight' => -99,
    ),
    'needs_review' => array(
      'name' => 'needs_review',
      'label' => 'Needs Review',
      'description' => 'Ready for moderation',
      'weight' => 0,
    ),
    'published' => array(
      'name' => 'published',
      'label' => 'Published',
      'description' => 'Make this version live',
      'weight' => 99,
    ),
    'unpublished' => array(
      'name' => 'unpublished',
      'label' => 'Unpublished',
      'description' => 'Unpublish this version',
      'weight' => -7,
    ),
  );
  return $items;
}
