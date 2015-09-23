(function ($) {
    Drupal.behaviors.autodesk = {
        attach: function (context, settings) {
            $('div.modal ul.openid-links li.user-link').hide();
            $('div.modal a[href="#openid-login"]').click(function() {
                $('div.modal div.apigee-responsive-openidhide').show();
            });

            $('li.dropdown').mouseover(function() {
                $(this).addClass('open');
            });

            $('li.dropdown').mouseout(function() {
                $(this).removeClass('open');
            });

            $('.apigee-modal-link-delete a').click(function() {
                var hrefLocation = $(this).attr('href');
                var identifier = $(this).attr('data-target');
                $(identifier).modal();
                if (($(identifier + ' .modal-body #devconnect_developer_application_delete').length == 0)) {
                    $(identifier + ' .modal-body').html('<p class="load-indicator" style="display:none;">' +
                        '<span class="label label-success" style="padding:5px;">Loading...</span></p>');
                    apigeePulsateForever(identifier + ' .modal-body .load-indicator');
                }
                $(identifier + ' .modal-body').load(hrefLocation + ' #devconnect_developer_application_delete', function() {
                    if (!($(identifier + ' .modal-body #devconnect_developer_application_delete').length == 0)) {
                        $(this).remove('.load-indicator');
                    }
                });
                return false;
            });

            $('.apigee-modal-link-edit a').click(function() {
                var hrefLocation = $(this).attr('href');
                var identifier = $(this).attr('data-target');
                $(identifier).modal();
                if (($(identifier + ' .modal-body #devconnect-developer-apps-edit-form').length == 0)) {
                    $(identifier + ' .modal-body').html('<p class="load-indicator" style="display:none;">' +
                        '<span class="label label-success" style="padding:5px;">Loading...</span></p>');
                    apigeePulsateForever(identifier + ' .modal-body .load-indicator');
                    $(identifier + ' .modal-body').load(hrefLocation + ' #devconnect-developer-apps-edit-form', function() {
                        if (!($(identifier + ' .modal-body #devconnect_developer_application_delete').length == 0)) {
                            $(this).remove('.load-indicator');
                        }
                        if (Drupal.settings.devconnect_developer_apps.selectlist == 'true'){
                            var selectItem = identifier + ' .selectlist-item';
                            $(identifier + ' select#api_product').attr('title', 'Select an API Product');

                            var sl = $(identifier + ' select#api_product').selectList({
                                instance: true,
                                clickRemove: false,
                                onAdd: function (select, value, text) {
                                    $(selectItem + ':last').append('<span style="margin-top:5px;" ' +
                                        'class="btn btn-primary pull-right remove-product">Remove</span>');
                                }
                            });

                            $('.selectlist-list').on('click', '.remove-product', function(event) {
                                sl.remove($(this).parent().data('value'));
                            });

                            $(selectItem).append('<span style="margin-top:5px;" ' +
                                'class="btn btn-primary pull-right remove-product">Remove</span>');
                        }
                    });
                }
                return false;
            });

            function apigeePulsateForever(elem) {
                $(elem).fadeTo(500, 1.0);
                $(elem).fadeTo(500, 0.1, function() {
                    apigeePulsateForever(elem);
                });
            }
        }
    };
})(jQuery);



jQuery(document).ready(function($) {
	
	jQuery('#api_product input[type="radio"]:checked').next().addClass('checked');
    
		// Radio Checked
		jQuery('#api_product label').mousedown(function(){
			$(this).parent().parent().children('div').children('label').each(function(){
				$(this).removeClass('checked');
				jQuery('#api_product input[type="radio"]').attr('checked',false);
			});
			$(this).prev().attr('checked',true)
			$(this).addClass('checked');
		});

	  jQuery('#api_product > div').matchHeight({
		byRow: false,
		property: 'height',
		target: null,
		remove: false
	});
	
	 jQuery('.method_details > div').matchHeight({
		byRow: false,
		property: 'height',
		target: null,
		remove: false
	});
	jQuery('.view-display-id-modelindex .views-row').matchHeight({
		byRow: false,
		property: 'height',
		target: null,
		remove: false
	});
	
	jQuery('.add-app-button a').removeClass().addClass('btn btn-primary go').children('span').remove();
	
	jQuery('.view-display-id-modelindex .verb-auth span.icon_lock').each(function(){
		jQuery(this).prev().addClass('lock');
	});
		
	jQuery('#devconnect-developer-apps-edit-form #edit-submit').removeClass('btn-success').addClass('btn-primary');
  
  jQuery('.view-display-id-block_1 .col-lg-3 > a').matchHeight({
        byRow: false,
        property: 'height',
        target: null,
        remove: false
    });
  
});


// Function to control the navigation bar behavior of some pages; 
// it makes the NAV scroll along with the content

jQuery( document ).ready(function() {
    if(!jQuery("#sticky").hasClass("left-nav")) return; //This makes the function not execute if its in another page
    
function sticky_relocate() {
    var window_top = jQuery(window).scrollTop();
    var div_top = jQuery('#sticky-anchor').offset().top;
    if (window_top+50 > div_top) {
        jQuery('#sticky').addClass('stick');
    } else {
        jQuery('#sticky').removeClass('stick');
    }
}

    jQuery(function () {
        jQuery(window).scroll(sticky_relocate);
        sticky_relocate();
    });
});
   

jQuery( document ).ready(function() {
// Accordion behavior for pages, next-steps, overview, products.
    
if(!jQuery("#sticky").hasClass("left-nav")) return; //This makes the function not execute if its in another page 
var _this; 
jQuery( ".left-nav a" ).click(function() {
    _this = jQuery(this);
setTimeout(
  function() 
  {
    jQuery('.left-nav a').removeClass('waypoint-focus');
    _this.addClass('waypoint-focus');
    
    jQuery( ".left-nav .panel-heading a" ).each(function() {
      if(jQuery( this ).attr("aria-expanded") === "true") {
          jQuery( this ).addClass("waypoint-focus");
      }
    });
       
  }, 50);

});

    
jQuery('.waypoint-subsection').waypoint(function() {
      jQuery('.left-nav ol li a').removeClass('waypoint-focus');
      jQuery('[name="' + jQuery(this)[0].element.id + '"]').addClass("waypoint-focus");
},{ 
    continuous: false
  });

    
 jQuery('.waypoint-section').waypoint(function(direction) {
   var _this = jQuery(this)[0].element;
   var WPLink = jQuery('[name="' + _this.id + '"]'); 
   var WPPrev = jQuery('[name="' + _this.attributes["data-prev-waypoint"].nodeValue + '"]');
   jQuery('.left-nav .panel-title a').removeClass('waypoint-focus'); 
      
       if(direction === "down") {
         if(WPLink.attr("aria-expanded") === "false") {   
           WPLink.get(0).click();
           WPLink.addClass("waypoint-focus"); 
         }
       }
       else {
         if(WPPrev.attr("aria-expanded") === "false") {
           WPPrev.get(0).click();
           WPPrev.addClass("waypoint-focus");
         }
       }
    
    } , {
        continuous: false
  });

});


// Contact US validation

jQuery( document ).ready(function() { 
    if(!jQuery("#webform-client-form-6").hasClass("webform-client-form-6")) return;  
    jQuery('#webform-client-form-6').validate({
    
        // Specify the validation rules
        rules: {
            "submitted[contact_telephone]": { required: true, number: true },
            "submitted[contact_email_address]": {
                required: true,
                email: true
            },
        },
        errorPlacement: function(error, element) {
        } 
});
    
    
    
});

