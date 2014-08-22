<?php
/**
 * @file
 * fq_page_backgrounds.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fq_page_backgrounds_taxonomy_default_vocabularies() {
  return array(
    'blog' => array(
      'name' => 'Blog',
      'machine_name' => 'blog',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'footer' => array(
      'name' => 'Footer',
      'machine_name' => 'footer',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'homepage' => array(
      'name' => 'Homepage',
      'machine_name' => 'homepage',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'insights' => array(
      'name' => 'Insights',
      'machine_name' => 'insights',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'people' => array(
      'name' => 'People',
      'machine_name' => 'people',
      'description' => 'A vocabulary for the people section',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'strategy' => array(
      'name' => 'Strategy',
      'machine_name' => 'strategy',
      'description' => 'A vocabulary for the strategy section',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'team' => array(
      'name' => 'Team',
      'machine_name' => 'team',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
