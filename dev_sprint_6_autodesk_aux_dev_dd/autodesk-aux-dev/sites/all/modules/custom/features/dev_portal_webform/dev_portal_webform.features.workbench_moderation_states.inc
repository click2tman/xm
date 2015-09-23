<?php
/**
 * @file
 * dev_portal_webform.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function dev_portal_webform_workbench_moderation_export_states() {
  $items = array(
    'unpublished' => array(
      'name' => 'unpublished',
      'label' => 'Unpublished',
      'description' => 'Unpublish this version',
      'weight' => -7,
    ),
  );
  return $items;
}
