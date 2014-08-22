<?php
/**
 * @file
 * Zen theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
?>
<!-- Initialize Drupal.behavior.settings -->
<?php
$path = ''; $full_path = '';
  $settings = array(
    'ajax_loader' => array(
      'these_settings' => false,
      'url' => $path,
      'full_path' => $full_path,
    ),
  );
  drupal_add_js($settings, 'setting');
?>
<div id="page">
  <header id="header" role="banner">
    <?php if ($logo): ?>
     <img src="<?php print $logo; ?>" />
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <hgroup id="name-and-slogan">
        <?php if ($site_name): ?>
          <h1 id="site-name">
            <span><?php print $site_name; ?></span>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
      </hgroup><!-- /#name-and-slogan -->
    <?php endif; ?>

    <?php if ($secondary_menu): ?>
      <nav id="secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('links', 'inline', 'clearfix'),
          ),
          'heading' => array(
            'text' => $secondary_menu_heading,
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>

      </nav>
    <?php endif; ?>

    <?php print render($page['header']); ?>

  </header>
    <div id="navigation">
    <!-- Custom Menu -->
    <ol>
      <li class="custom-menu-section float-left">
      <a href="/ajax-loader/nojs/home" class="use-ajax fq-logo" id="home"><div id="fq_logo"> </div></a>
      <!-- <div id="fq_logo"></div> -->
      </li>
      <li class="custom-menu-section client-login float-right">
        <?php print $account_links; ?>
      </li>
      <li class="custom-hamburger-section hamburger float-right gray_gredient border-left">
        <input type="radio" id="hamburger_radio" name="radios" value="false">
        <label for="hamburger_radio"> </label>
      </li>
        <div class="hamburger-wrapper">
          <div class="hamburger-submenu">
            <?php
              if($ham!==false) {
                print $ham;
              }
              else {
                $tree = menu_tree('menu-footer-and-hamburger-menu');
                //echo "<br/><br/>\n\nMENU TREE<br/>\n";
                //var_dump($tree);
                //echo "<br/><br/>\n\nEND MENU TREE<br/>\n";
                //exit();
                print drupal_render($tree);
              }
            ?>
          </div>
        </div>
      <li class="custom-menu-section float-right">
        <input type="radio" id="strategy_radio" name="radios" value="false">
        <!-- @TODO make this label a drupal title. -->
        <label for="strategy_radio" class="border-left">Investments</label>
        <ol class="submenu strategy_submenu">
          <li class="left_half_strategy">
            <ul>
              <li class="strategy_submenu_1"><?php echo views_embed_view('header_menu', 'block_menu_strategy');?></li>
              <li class="strategy_submenu_2"><?php echo views_embed_view('header_menu', 'block_menu_summary');?></li>
           </ul>
          </li>
          <li class="right_half_strategy">
            <?php echo views_embed_view('header_menu', 'block_4');?>
          </li>
        </ol>
      </li>
      <li class="custom-menu-section float-right">
        <input type="radio" id="people_radio" name="radios" value="false">
        <!-- @TODO make this label a drupal title. -->
        <label for="people_radio" class="border-left">Firm</label>
        <ol class="submenu people_submenu">
          <li class="left_half_people">
            <ul>
              <li class="people_submenu_1"><?php echo views_embed_view('header_menu', 'block_menu_people');?></li>
              <li class="people_submenu_2"><?php echo views_embed_view('header_menu', 'block_menu_teams');?></li>
              <li class="people_submenu_3"><?php echo views_embed_view('header_menu', 'block_menu_partners');?></li>
            </ul>
          </li>
          <li class="right_half_people">
            <ul>
              <li class="people_submenu_4"><?php echo views_embed_view('header_menu', 'block_5');?></li>
            </ul>
          </li>
        </ol>
      </li>
      <li class="custom-menu-section float-right">
        <input type="radio" id="close_radio" name="radios" value="false" checked>
        <label for="close_radio">Close Menu</label>
      </li>
    </ol>
    <!-- custom menu -->
    <?php if ($main_menu): ?>
      <nav id="main-menu" role="navigation">
      </nav>
    <?php endif; ?>

    <?php print render($page['navigation']); ?>
  </div><!-- /#navigation -->

  <div id="main">
      <div id="content" class="column <?php $URL = current_path(); $URL_pieces = parse_url($URL); $path = str_replace('/', '-', $URL_pieces['path']); $content_class = ltrim ($path,'-'); print_r($content_class);?>" role="main">

      <div id="section-title">
        <?php
          $section_title = '';
          $URL = current_path();
          if (strpos(strtolower($URL), 'node') !== FALSE){
            $URL = drupal_get_path_alias($URL);
          }
          if (strpos(strtolower($URL), 'people') !== FALSE){
            $section_title = 'PEOPLE';
          }elseif (strpos(strtolower($URL), 'strategy') !== FALSE){
            $section_title = 'STRATEGY';
            if (strpos(strtolower($URL), 'webinars') !== FALSE){
            $section_title = 'WEBINARS';
            }
          }elseif (strpos(strtolower($URL), 'insights') !== FALSE){
            $section_title = 'INSIGHTS';
          }elseif (strpos(strtolower($URL), 'white-papers-factsheets/white-papers') !== FALSE){
            $section_title = 'WHITE PAPERS';
          }elseif (strpos(strtolower($URL), 'white-papers-factsheets/factsheets') !== FALSE){
            $section_title = 'FACTSHEETS';
          }elseif (strpos(strtolower($URL), 'user/dashboard') !== FALSE){
            $section_title = 'YOUR HOME';
          }elseif (strpos(strtolower($URL), 'user') !== FALSE){
            $section_title = 'SECURE CLIENT LOGIN';
          }elseif (strpos(strtolower($URL), 'contact') !== FALSE){
            $section_title = 'People';
          }elseif (strpos(strtolower($URL), 'private-uploads') !== FALSE){
            $section_title = 'SECURE CLIENT ACCESS';
          }
          $section_title = $section_title_override ? $section_title_override : $section_title;
          print $section_title;
        //var_dump($page['content']);
        //exit();
        ?>
      </div>



      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>


      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>

      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div><!-- /#content -->

    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside><!-- /.sidebars -->
    <?php else: ?>
      <aside class="sidebars">
        <section class="region region-sidebar-second column sidebar">
        </section>
      </aside>
    <?php endif; ?>

  </div><!-- /#main -->
</div><!-- /#page -->
  <?php print render($page['footer']); ?>

<?php print render($page['bottom']); ?>
