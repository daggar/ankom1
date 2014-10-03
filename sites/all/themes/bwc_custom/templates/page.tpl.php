<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
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
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
 
 /*
 	WHAT THE HELL IS A TARG?
 	See terms.txt
 
 	WHY MAKE UP WORDS?  
 	Because every other word in techspeak has a million different meanings.  
 	I'm tired of wraps and meta-wraps and outer-wraps and inner-wraps.  And
 	blocks and subblocks and things.
 	
 	WHERE ARE THE TABS?  THE LOGO?  THE SITENAME?
 	They are not built into the templates.  
 	This theme requires the use of the Blockify module for such things
 	http://drupal.org/project/blockify
  */
?>
  <div id="targ" class="targ <?php print implode(' ', $variables['classes_array']); ?>"><div id="subtarg" class="subtarg">
  	<?php if ($page['admin_blocks']): ?>
  	<div id="admin-blocks">
  	<?php print render($page['admin_blocks']); ?>
  	</div>
  	<?php endif; /* if ($page['admin_blocks'] */ ?>

    <div id="header" class="header hork targhork region"><div id="header-bg-left"></div><div id="header-bg-center"></div><div id="header-bg-right"></div><div id="header-targverk" class="header targverk"><div class="conk clearfix">
    <?php if ($page['header_first']): ?>
    <div id="header-first"><div class="region conk targverk"><?php print render($page['header_first']); ?></div></div>
    <?php endif; /* if ($page['header_first'] */ ?>
    <?php if ($page['header_second']): ?>
    <div id="header-second"><div class="region conk targverk"><?php print render($page['header_second']); ?></div></div>
    <?php endif; /* if ($page['header_second'] */ ?>
    </div></div><!-- header-verk -->
    <?php if ($page['header_ribbon']): ?>
    <div id="header-ribbon" class="targhorklet targhork hork"><div class="region header"><div class="conk"><?php print render($page['header_ribbon']); ?></div></div></div>
    <?php endif; /* if ($page['header_ribbon'] */ ?>
		</div><!-- header-targhork -->

    <?php if ($page['header_ribbon2']): ?>
    <div id="header-ribbon2" class="targhorklet targhork hork"><div class="region header"><div class="conk"><?php print render($page['header_ribbon2']); ?></div></div></div>
    <?php endif; /* if ($page['header_ribbon2'] */ ?>

    <div id="maincontent" class="maincontent targhork"><div id="maincontent-targverk" class="maincontent targverk"><div class="conk clearfix">
        <a id="main-content-start"></a>
        <div class="content-main-center verk transverk transverk-1"><div class="conk">
        <?php if($page['content_above']): ?>
        <div id="maincontent-above" class="maincontent hork">
        	<?php print render($page['content_above']); ?>
        </div><!-- /content-main-above -->
        <?php endif; /* if($page['content_above']) */ ?>
				<div class="maincontent-main" class="maincontent hork">
        <?php print render($page['content']); ?>
      	</div><!-- content-main-main -->
      	<?php if($page['content_below']): ?>
        <div class="maincontent-below" class="maincontent hork">
        	<?php print render($page['content_below']); ?>
        </div><!-- /content-main-below -->
        <?php endif; /* if($page['content_below']) */ ?>
     	
      	</div></div><!-- /content-main-center -->

      <?php if ($page['sidebar_first']): ?>
        <div id="maincontent-left" class="column sidebar maincontent maincontent-left verk transverk transverk-side transverk-2"><div class="region conk">
          <?php print render($page['sidebar_first']); ?>
       </div></div> <!-- /.section, /#maincontent-left -->
      <?php endif; /* if ($page['sidebar_first']) */?>

      <?php if ($page['sidebar_second']): ?>
        <div id="maincontent-right" class="column sidebar maincontent maincontent-right verk transverk transverk-side transverk-3"><div class="region conk">
          <?php print render($page['sidebar_second']); ?>
        </div></div> <!-- /.section, /#sidebar-right -->
      <?php endif; /* if ($page['sidebar_second']) */ ?>

  	</div></div></div><!-- maincontent-targhork -->
  	
  	<?php if ($page['lower_content_left'] || $page['lower_content_right']): ?>
  	<div id="lowercontent" class="targhork"><div class="targverk"><div class="conk clearfix">
  		<div id="sidebar-left-lower" class="sidebar-left transverk-2"><div class="conk">
  		<?php if ($page['lower_content_left']) print render($page['lower_content_left']); ?>
  		</div></div>
			
			<div id="sidebar-right-lower" class="sidebar-left"><div class="conk">
  		<?php if ($page['lower_content_right']) print render($page['lower_content_right']); ?>
  	</div></div></div>
  	
  		
  	</div></div>
  	<?php endif; /* if ($page['lower_content_left'] || $page['lower_content_rightt']) */ ?>

		<?php if ($page['pagebottom_fullwidth']): ?>
			<div id="pagebottom-fullwidth" class="pagebottom targhork"><div id="pagebottom-targverk" class="pagebottom targverk"><div class="conk clearfix"><?php print render($page['pagebottom_fullwidth']); ?>
			</div></div></div>
		<?php endif; /* if ($page['pagebottom_fullwidth']) */ ?>

		<div class="pagebottom-padding"></div>

		<div id="footer" class="footer hork targhork region">
		<?php if ($page['footer_ribbon']): ?>
    <div id="footer-ribbon" class="targhorklet targhork hork"><div class="region footer targverk"><div class="conk"><?php print render($page['footer_ribbon']); ?></div></div></div>
    <?php endif; /* if ($page['header_ribbon'] */ ?>
    <div id="footer-verk" class="footer targverk"><div class="conk clearfix">
    <?php if ($page['footer_first']): ?>
    <div id="footer-first"><div class="region conk"><?php print render($page['footer_first']); ?></div></div>
    <?php endif; /* if ($page['footer_first'] */ ?>
    <?php if ($page['footer_second']): ?>
    <div id="footer-second"><div class="region conk"><?php print render($page['footer_second']); ?></div></div>
    <?php endif; /* if ($page['footer_second'] */ ?>
  	</div></div></div><!-- footer-targhork -->
    
  </div><!-- subtarg-->

  <?php if($page['fixed']): ?>
	<div id="fixed-position">
		<?php print render($page['fixed']); ?>
	</div>	
	<?php endif; /* if($page['fixed']) */ ?>
	<?php if($page['toolbar']): ?>
	<div id="bwc-toolbar">
		<?php print render($page['toolbar']); ?>
	</div>
	<?php endif; /* if($page['toolbar']) */ ?>
	<div id="screen-format"></div>
</div><!-- targ -->
