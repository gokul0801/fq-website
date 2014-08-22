<?php
/**
 * @file
 * fq_white_paper.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fq_white_paper_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fq_white_paper_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function fq_white_paper_node_info() {
  $items = array(
    'white_paper_factsheet' => array(
      'name' => t('White paper / Factsheet'),
      'base' => 'node_content',
      'description' => t('Use <em>white papers or factsheets</em> for premium data reports.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
