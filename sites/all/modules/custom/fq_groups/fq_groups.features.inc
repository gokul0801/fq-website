<?php
/**
 * @file
 * fq_groups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fq_groups_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function fq_groups_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_og_membership_type().
 */
function fq_groups_default_og_membership_type() {
  $items = array();
  $items['group'] = entity_import('og_membership_type', '{ "name" : "group", "description" : "Group", "language" : "" }');
  return $items;
}
