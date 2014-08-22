<?php
/**
 * @file
 * Zen theme's implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top class.
 * - $region: The name of the region variable as defined in the theme's .info file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see zen_preprocess_region()
 * @see template_process()
 */
?>
<?php if ($content): ?>
  <footer id="footer" class="<?php print $classes; ?>">
    <div class="insights">
      <div class="bigger_on_the_inside insights-closed">
        <div class="block block_1"><a href="#" id="insights" alt="Insights"><span>FEATURED INSIGHTS +</span></a><?php echo views_embed_view('News_Footer', 'block_1');?></div>
        <div class="block block_2"><?php echo views_embed_view('News_Footer', 'block_2');?></div>
        <div class="block block_3"><?php echo views_embed_view('News_Footer', 'block_3');?></div>
        <div class="block block_4"></div>
      </div>
    </div>
    <?php print $content; ?>
  </footer><!-- region__footer -->
<?php endif; ?>
