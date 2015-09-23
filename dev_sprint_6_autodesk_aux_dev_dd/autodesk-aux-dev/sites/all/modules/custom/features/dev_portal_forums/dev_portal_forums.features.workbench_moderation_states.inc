<?php
/**
 * @file
 * dev_portal_forums.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function dev_portal_forums_workbench_moderation_export_states() {
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
