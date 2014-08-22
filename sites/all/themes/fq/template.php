<?php

/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   fq_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: fq_field()
 *
 *   where fq is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */


/**
 * change the MailChimp module's default "save" button to SIGN UP
 * by TZ 6/18/13
 */
function fq_form_emma_block_subscribe_form_alter(&$form, &$form_state, $form_id) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('SIGN UP'),
    );
    $output = '<p>'. t('<a href="@privacy-page&width=600&height=400" target="_window" class="colorbox-node privacy-link">We respect your privacy.</a>', array('@privacy-page' => url('privacy'))) .'</p>';
    $form['my_markup'] = array('#markup' => $output, '#weight' => 100,);
}


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function fq_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  fq_preprocess_html($variables, $hook);
  fq_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function fq_preprocess_html(&$variables, $hook) {
  $extra_classes =& drupal_static('fq_extra_body_class', array());
  $variables['classes_array'] = array_merge($variables['classes_array'], $extra_classes);

  // Figure out the right background image
  // Possible sources (highest priority first):
  // - `page` node `field_basic_page_background` field
  // - cms section override
  // - default section
  // - default site

  // `page` node `field_basic_page_background` field - see fq_preprocess_page
  // cms section override - see fq_preprocess_page
  $background_image =& drupal_static('fq_background_image', NULL);

  if (empty($background_image) && !drupal_is_front_page()) {

    // default section
    $section_bg = array(
      'insights*' => '/sites/default/files/insights-section-bg-full.jpg',
      'people*' => '/sites/default/files/people-section-bg.jpg',
      'strategy*' => '/sites/default/files/strategy-section-bg-full.jpg',
    );
    $path = drupal_strtolower(drupal_get_path_alias($_GET['q']));
    foreach ($section_bg as $match_path => $section_bg) {
      if (drupal_match_path($path, $match_path)) {
        $background_image = $section_bg;
        break;
      }
    }

    // default site
    if (empty($background_image)) {
      $background_image = '/sites/all/themes/fq/images/bg_cafe.jpg';
    }
  }

  $variables['background_image'] = '<div class="background-image transition" style="background: url(\''. $background_image .'\') no-repeat center center fixed; background-position: 0 0; background-size: cover;">'.
    '<img src="'. $background_image .'" style="display:none;">'
    .'</div>';

}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function fq_preprocess_page(&$variables, $hook) {
  global $user;
  if (user_is_anonymous()) {

    $variables['ham'] = false;

    $variables['account_links'] = ''
      . '<div id="user_login" class="logged-out border-left blue_gredient">'
      .   l(t('Login'), 'user')
      . '</div>';
  }
  else {
    $variables['ham'] = ''.
      '<ul class="menu">'.
      '<li class="menu__item is-leaf first leaf">'.
      l(t('Hi, @name', array('@name' => format_username($user))), 'user/dashboard', array('attributes' => array('class' => array('user-welcome')))) .
      '</li><li class="menu__item is-leaf leaf">'.
      l(t('Settings'), "user/$user->uid/edit").
      '</li>'.
      '</li><li class="menu__item is-leaf leaf">'.
      l(t('Logout'), 'user/logout') .
      '</li>'.
      '<li class="menu__item is-leaf leaf"><a href="/?q=ajax-loader/nojs/people/contact-page" class="menu__link use-ajax ajax-processed">Contact Us</a></li>' .
      '<li class="menu__item is-leaf leaf"><a href="/?q=ajax-loader/nojs/who-we-are/careers" class="menu__link use-ajax ajax-processed">Careers</a></li>' .
      '<li class="menu__item is-leaf leaf"><a href="/?q=system/files/fq-firmfactsheet-111313.pdf" target="_blank" class="menu__link">FQ At A Glance</a></li>' .
      '<li class="menu__item is-leaf leaf"><a href="/?q=ajax-loader/nojs/people/legal" class="menu__link use-ajax ajax-processed">Legal</a></li>' .
      '<li class="menu__item is-leaf last leaf"><a href="/?q=ajax-loader/nojs/people/legal" class="menu__link use-ajax ajax-processed">© 2013 First Quadrant LP</a></li>' .
      '</ul>';



    $variables['account_links'] = ''
      . '<div id="user_login" class="logged-in border-left blue_gredient">'
      .   l(t('Hi, @name', array('@name' => format_username($user))), 'user/dashboard', array('attributes' => array('class' => array('user-welcome'))))
      .   '<div class="user-links">'
      .     l(t('Settings'), "user/$user->uid/edit")
      .     l(t('Logout'), 'user/logout')
      .   '</div>'
      . '</div>';
  }

  $background_image =& drupal_static('fq_background_image', NULL);
  // section background from view
  $section_views = array(
    'insights*' => 'insights',
    'people*' => 'people',
    'strategy*' => 'strategy',
  );
  $path = drupal_strtolower(drupal_get_path_alias($_GET['q']));
  foreach ($section_views as $match_path => $display) {
    if (drupal_match_path($path, $match_path)) {
      $result = views_get_view_result('background_image_default', $display);
      if (!empty($result) && !empty($result[0]->field_field_background_image)) {
        if ($uri = $result[0]->field_field_background_image[0]['raw']['uri']) {
          $background_image = file_create_url($uri);
          break;
        }
      }
    }
  }

  $section_title_override = false;
  // node page background override
  if (!empty($variables['node'])) {
    $node = $variables['node'];
    if ($node->type == 'page') {
      if(!empty($node->field_basic_page_background)) {
        if ($uri = $node->field_basic_page_background[LANGUAGE_NONE][0]['uri']) {
          $background_image = file_create_url($uri);
        }
      }

      if(!empty($node->field_section_title_override)) {
        if (sizeof($node->field_section_title_override[LANGUAGE_NONE][0]['value'])>0) {
          $section_title_override = $node->field_section_title_override[LANGUAGE_NONE][0]['value'];
          $node->field_section_title_override = null;
          $variables['section_title_override'] = $section_title_override;
        }
        $node->field_section_title_override = null;
      }
    }
  }

  ///var_dump($variables['page']->field_section_title_override);

}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function fq_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // fq_preprocess_node_page() or fq_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function fq_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function fq_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function fq_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
 * Implements hook_preprocess().
 */
function fq_preprocess_views_view(&$variables, $hook) {
  $extra_classes =& drupal_static('fq_extra_body_class', array());
  $classes = implode(' ', $variables['classes_array']);
  if (strpos($classes, 'layout-2-column') !== FALSE) {
    $extra_classes['layout-2-column'] = 'layout-2-column';
  }
}


function fq_theme(&$existing, $type, $theme, $path) {
  $hooks['user_login'] = array(
	'render element' => 'form',
	'path' => drupal_get_path('theme', 'fq') . '/templates',
	'template' => 'templates/user-login',
	'preprocess functions' => array(
           'fq_preprocess_user_login'
        ),
       );
  return $hooks;
}  


function fq_preprocess_user_login(&$variables) {
  $variables['intro_text'] = t('This is my awesome login form');
  $variables['rendered'] = drupal_render_children($variables['form']);
}
