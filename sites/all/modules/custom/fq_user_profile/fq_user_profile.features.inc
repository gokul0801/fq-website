<?php
/**
 * @file
 * fq_user_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fq_user_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
