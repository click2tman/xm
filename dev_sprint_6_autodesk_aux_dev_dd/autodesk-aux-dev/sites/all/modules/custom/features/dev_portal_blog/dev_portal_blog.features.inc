<?php
/**
 * @file
 * dev_portal_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dev_portal_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dev_portal_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dev_portal_blog_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog_audio' => array(
      'name' => t('Audio'),
      'base' => 'node_content',
      'description' => t('Use Audio to add a blog post with an Audio attached'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog_image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => t('Use Image to add a blog post with an image attached'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog_video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Use Video to add a blog post with a video attached'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
