<?php
/**
 * @file
 * fq_user_profile.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function fq_user_profile_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-dashboard:private-uploads
  $menu_links['menu-dashboard:private-uploads'] = array(
    'menu_name' => 'menu-dashboard',
    'link_path' => 'private-uploads',
    'router_path' => 'private-uploads',
    'link_title' => 'Your Documents',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-dashboard:white-papers-factsheets/factsheets
  $menu_links['menu-dashboard:white-papers-factsheets/factsheets'] = array(
    'menu_name' => 'menu-dashboard',
    'link_path' => 'white-papers-factsheets/factsheets',
    'router_path' => 'white-papers-factsheets/factsheets',
    'link_title' => 'Factsheets',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-dashboard:white-papers-factsheets/white-papers
  $menu_links['menu-dashboard:white-papers-factsheets/white-papers'] = array(
    'menu_name' => 'menu-dashboard',
    'link_path' => 'white-papers-factsheets/white-papers',
    'router_path' => 'white-papers-factsheets/white-papers',
    'link_title' => 'White Papers',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Factsheets');
  t('White Papers');
  t('Your Documents');


  return $menu_links;
}
