<?php
/**
 * @file
 * fq_page_backgrounds.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fq_page_backgrounds_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'background_image_insights';
  $context->description = '';
  $context->tag = 'background';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'insights*' => 'insights*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ebb961872327d2c00d0b263f50323094' => array(
          'module' => 'views',
          'delta' => 'ebb961872327d2c00d0b263f50323094',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('background');
  $export['background_image_insights'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'background_image_people';
  $context->description = '';
  $context->tag = 'background';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'people*' => 'people*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-background_image_default-people' => array(
          'module' => 'views',
          'delta' => 'background_image_default-people',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('background');
  $export['background_image_people'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'background_image_strategy';
  $context->description = '';
  $context->tag = 'background';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'strategy*' => 'strategy*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-9ce32f80ac2247a519ebaf38bb46b7e5' => array(
          'module' => 'views',
          'delta' => '9ce32f80ac2247a519ebaf38bb46b7e5',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('background');
  $export['background_image_strategy'] = $context;

  return $export;
}
