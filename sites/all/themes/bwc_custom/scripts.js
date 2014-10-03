/*
 * IMPORTANT: The usual jquery '$' shorthand does not work well with Drupal's 
 * built-in functions.  Wherever you would use '$' use 'jQuery' instead.
 *
 * Currently Drupal uses JQ 1.4.  If that changes, the .live() function may need
 * to change to .on()
 */
jQuery.noConflict(); // Tell jQuery you are going with noConflict mode.
var formFactor;

jQuery(document).ready(function() {
	/* 
	 * Add the 'script-enabled' class.  If this class is missing, you know that
	 * scripts are not, in fact, enabled.  Use this as a root selector to 
	 * style/display/hide script-sensitive markup.
	 */
	jQuery('#targ').addClass('script-enabled');
	jQuery(document.body).addClass('script-enabled');
	/*
	 * Detect if the current page is the top level, or if it is in-iframe.
	 */
	var isInIFrame = (window.location != window.parent.location) ? true : false;
	if (isInIFrame == true) {
		jQuery('#targ').addClass('in-iframe');
		jQuery(document.body).addClass('in-iframe');
	};
	layoutResize();
	mediaQuery();
	
	
	jQuery('a.bwc-supermenu.anchor-link').click(function(e) {
		e.preventDefault;
		if ( jQuery(this).parents('li').hasClass('inactive-menu') ) {
			closeAllMenus(false);
			jQuery(this).parents('li').children('.box-wrap').slideDown(600);
			jQuery(this).parents('li.depth-1').removeClass('inactive-menu');
			jQuery(this).parents('li.depth-1').addClass('active-menu');
			jQuery('#menu-shroud').fadeIn(200);
		} else {
			closeAllMenus(true);
		}
		return false;
	}); //jQuery('.supermenu-parent').click(function()
	
	jQuery('#menu-shroud').click(function(e) {
		e.preventDefault;
		closeAllMenus(true);
		return false;
	}); //jQuery('#menu-shroud').click(function(e) {
	
	jQuery('.bwc-supermenu-close-icon').click(function() { closeAllMenus(true) });
	
	jQuery('.bwc-dashboard-selection').click(function() {
			if (jQuery(this).hasClass('activated')) {
				jQuery(this).removeClass('activated');
			} else {
				jQuery(this).addClass('activated');
			}
		}); //jQuery('.cgr-dashboard-selection').click(function() {
	
	//Highlight the map when the menu mouseovers.
	jQuery('.bwc-dashboard-select-overflow ul li').mouseover(function(){
		menuIndex = jQuery(this).index() + 1;
		switchMapSprites(menuIndex);
	});
		
 jQuery('.faq-list-subtab-list .quicktabs-views-group').live('click', function(){
 	if (jQuery(this).hasClass('active-question')) {
		jQuery('.quicktabs-views-group').removeClass('active-question');
		jQuery('.faq-list-answer').slideUp('fast');
 	} else { //if (jQuery(this).hasClass('active-question'))
	 	jQuery('.quicktabs-views-group').removeClass('active-question');
	 	jQuery(this).addClass('active-question');
	 	jQuery('.faq-list-answer').slideUp('fast');
	 	jQuery(this).find('.faq-list-answer').slideDown('fast');
	} //} else { //if (jQuery(this).hasClass('active-question'))
 }) //jQuery('.faq-expansion-row').click(function()
 
 /* Regional map code */
	/*
			Only one bubble should be open at a time.  Every time hover out
			happens, make sure ALL are closed.
	*/
	jQuery('.virtual-tour-item-wrapper .expand-section').each(function() {jQuery(this).css('height', jQuery(this).height()) });
	jQuery('.virtual-tour-item-wrapper .expand-section').hide();
	jQuery('.virtual-tour-item-wrapper').click(function() { mapBubble(this); });
	
	jQuery('.map-list-title-click').click(function() {
		mapBubble(jQuery(this).parent().find('.virtual-tour-item-wrapper'));
	}) //jQuery('map-list-title-click').click(function() {


	jQuery("#map-grid-overlay").click(function(e) {
  	offset =  jQuery(this).offset();
  	var xcoord = Math.round( e.pageX - (offset.left ));
  	var ycoord = Math.round( e.pageY - (offset.top ));
  	e.stopPropagation();
  	var coordstring = "<i>X:</i>" + String(xcoord) + " | <i>Y:</i>" + String(ycoord) + "";
  	jQuery("#map-grid-coords-digits").html( coordstring );
 	}); //.click	
/* End Regional map code */

	//Slider controls 
	jQuery('.bwc-slider').each(function() {
		var sizeIncrement = jQuery(this).find('.related-slider-row').outerWidth();
		var rawWidth = jQuery(this).width() -61; //61 = width of controls
		var newSize = Math.floor(rawWidth / sizeIncrement) * sizeIncrement + 61;
		var newSizeString = String(newSize) + 'px';
		jQuery(this).width(newSizeString);
	}) //jQuery('.bwc-slider').each(function()
	
	jQuery('.bwc-slider-control.right').click( function() {
		var scrollCount = jQuery(this).attr('scrollcount');
		var scrollIncrement = jQuery(this).closest('.bwc-slider').find('td').outerWidth() * scrollCount;
		var maxScroll = jQuery(this).closest('.bwc-slider').find('table').outerWidth() - scrollIncrement;
		var scrollTarget = Math.abs(jQuery(this).closest('.bwc-slider').find('.slider-table-wrap').css('marginLeft')) + scrollIncrement;
		if (scrollTarget <= maxScroll) {
			var scrollString =  '-' + String(scrollTarget) + 'px';
		} else {
			var scrollString =  '-' + String(maxScroll) + 'px';
		}
		jQuery(this).closest('.bwc-slider').find('.slider-table-wrap').animate({'marginLeft' : scrollString}, 1000);
	}); 
	
		jQuery('.bwc-slider-control.left').click( function() {
		var scrollCount = jQuery(this).attr('scrollcount');
		var scrollIncrement = jQuery(this).closest('.bwc-slider').find('td').outerWidth() * 3;
		var maxScroll = 0
		var scrollTarget = Math.abs(jQuery(this).closest('.bwc-slider').find('.slider-table-wrap').css('marginLeft')) + scrollIncrement;
		if (scrollTarget <= maxScroll) {
			var scrollString =  '-' + String(scrollTarget) + 'px';
		} else {
			var scrollString =  String(maxScroll) + 'px';
		}
		jQuery(this).closest('.bwc-slider').find('.slider-table-wrap').animate({'marginLeft' : scrollString}, 1000);
	}); 
 
	
}); //jQuery(document).ready(function()

function closeAllMenus(removeShroud) {
	jQuery('.box-wrap').slideUp('fast');
	jQuery('.bwc-supermenu-block li.depth-1').addClass('inactive-menu');
	jQuery('.bwc-supermenu-block li.depth-1').removeClass('active-menu');
	if ( true == removeShroud ) jQuery('#menu-shroud').fadeOut(200);
}

jQuery(window).resize(function() {
	layoutResize();
	mediaQuery();
});

/* The stylesheet is responsible for setting the content property of 
	 #screen-format to match the major break point.  This function simply
	 adds that property as a css class. 
	 
	 This SHOULD NOT be used as the main controller for breakpoints.  Use
	 CSS Media queries for page layout.
*/

function layoutResize() {
	jQuery('#targ').css('min-height', jQuery(window).height());
};

function mediaQuery() {
	if (formFactor != undefined) jQuery('#targ').removeClass(formFactor);
	formFactor = jQuery('#screen-format').css('width');
	if (formFactor != undefined) {
		formFactor = formFactor.replace(/\"/g, '');	
		formFactor = 'form-factor-' + formFactor;
		jQuery('#targ').addClass(formFactor);
	} //if (formFactor != undefined)
} //function mediaQuery()

//Global map sprites
function switchMapSprites(spriteNumber) {
	mapHeight = 735;
	spriteOffset = mapHeight * spriteNumber
	spriteOffset = "left -" + String(spriteOffset) + "px";
	jQuery('.distro-map-sprites').css("background-position", spriteOffset);
}  //function switchMapSprites(spriteNumber)

	jQuery("#map-grid-overlay").click(function(e) {
  	offset =  jQuery(this).offset();
  	var xcoord = Math.round( e.pageX - (offset.left + jQuery(this).width()) );
  	var ycoord = Math.round( e.pageY - (offset.top + jQuery(this).height()) );
  	e.stopPropagation();
  	var coordstring = "<i>X:</i>" + String(xcoord) + " - <i>Y:</i>" + String(ycoord) + "";
  	jQuery("#map-grid-coords-digits").html( coordstring );
 	}); //.click	
 	
 	function closeAllTourItems() {
	jQuery('.virtual-tour-item-wrapper.inactive').children('.expand-section').slideUp('fast');
	}
	
	function deactivateSpot() {
		jQuery('.closing-now').removeClass('active');
		jQuery('.closing-now').addClass('inactive');
		jQuery('.virtual-tour-item-wrapper').removeClass('.closing-now');
	}
	
	function mapBubble(bubble) {
		jQuery('.map-list-expansion-section').slideUp('fast');
		jQuery('.map-list-expansion-section').removeClass('active');
		if (jQuery(bubble).hasClass('inactive')) {
			jQuery(bubble).closest('.views-row').find('.map-list-expansion-section').slideDown('medium');
			jQuery(bubble).closest('.views-row').find('.map-list-expansion-section').addClass('active');
			jQuery('.virtual-tour-item-wrapper').addClass('inactive');
			jQuery('.virtual-tour-item-wrapper').removeClass('active');
			jQuery(bubble).removeClass('inactive');
			jQuery(bubble).addClass('active');
			closeAllTourItems();
			jQuery(bubble).children('.expand-section').slideDown('medium');
		} else {
			jQuery(bubble).addClass('closing-now');
			jQuery(bubble).children('.expand-section').slideUp('fast', deactivateSpot );
		} //if (jQuery(bubble).hasClass('inactive')) {
	}; //function mapBubble(bubble) 
	
	function showgrid() {
		if ( jQuery('.distributor-map-region').hasClass('grid-active') ) {
			jQuery('.distributor-map-region').removeClass('grid-active');
			jQuery('#map-grid').removeClass('grid-active');
		} else {
			jQuery('.distributor-map-region').addClass('grid-active');
			jQuery('#map-grid').addClass('grid-active');
		}
	} //function showgrid()


	
/* End regional map code */