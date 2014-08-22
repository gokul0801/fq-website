<?php
/**
 * @file
 * fq_page_backgrounds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fq_page_backgrounds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fq_page_backgrounds_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function fq_page_backgrounds_node_info() {
  $items = array(
    'background_image' => array(
      'name' => t('Background image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
