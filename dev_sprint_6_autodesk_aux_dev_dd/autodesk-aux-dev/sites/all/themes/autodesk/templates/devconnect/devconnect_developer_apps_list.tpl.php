<?php
/**
 * @file
 * Apigee Responsive theme implementation to display list of developer apps.
 *
 * Available variables inherited from devconnect_developer_apps:
 * $add_app - link to add an app if user has permission, otherwise FALSE.
 * $application_count - number of applications registered to the user
 * $applications - array of arrays, each of which has the following keys:
 *  - app_name
 *  - callback_url
 *  - credential (each member has apiproduct, status, displayName keys)
 *  - delete_url
 *  - created (Unix timestamp)
 *  - new_status (TRUE if app created in last 24 hrs, FALSE otherwise)
 *  - noproducts (TRUE if there are no API Products for this app, else FALSE)
 *  - id (unique JS identifier used in generating modals & links to modals)
 * $user - fully-populated user object (stdClass)
 * $show_status - bool indicating whether APIProduct status should be shown.
 * $show_analytics - bool indicating whether analytics link should be shown.
 * $singular - label for an app. Usually App or API. First letter is uppercase.
 * $singular_downcase - label for an app, with first letter lowercased unless
 *                      it is an acronym.
 * $plural - label for more than one app. First letter uppercase.
 * $plural_downcase - label for more than one app, downcased as above.
 *
 * Additional variables added via preprocess hook in template.php:
 *
 */

$i = 0;

?>


<?php if ($application_count): ?>
  <div class="row">
    <div class="col-sm-12">
		<div class="row page-header">
			<div class="col-sm-6">
				<!-- Title -->
				<h1><?php print t("$plural_downcase"); ?></h1>
			</div>
			<?php if ($add_app): ?>
			<div class="col-sm-6">
				<div class="add-app-button pull-right">
					<?php print $add_app; ?>
			  	</div>
			</div>
			<?php endif; ?>
	  	</div>	
    </div>
  </div>
  <div class="row">
  <div class="col-sm-12">
  <?php // more than one application ?>
  <?php foreach ($applications as $app): ?>
    <?php $status = autodesk_app_status($app); ?>
    <div class="panel-group my-apps-accordion">
      <div class="panel panel-default">
        <div class="panel-heading">
          <h4 class="panel-title">
            <div class="truncate">
              <!--DONT WANT THIS<?php if ((bool) $app['new_status']) : ?><span class="badge">new</span>&nbsp;&nbsp;<?php endif; ?>-->
             	<a data-toggle="collapse" data-parent="#my-apps-accordion" class="collapsed" href="#my-apps-collapse<?php print $i; ?>">
					<div class="col-md-6">
						<?php print $app['app_name']; ?>
					</div>
					<div class="col-md-6 text-right">
						Created <?php print format_date($app['credential']['issued']); ?>
					</div>
					<div class="app-desc col-lg-12">
						<?php print $app['credential']['dev_portal_app_description']; ?> This text will be replaced with text entered in the description field
					</div>
				</a>
				
            </div>
          </h4>
        </div>
        <div id="my-apps-collapse<?php print $i; ?>" class="my-apps-panels panel-collapse collapse">
          <div class="panel-body">
            <!--AUTODESK DONT WANT THIS /**<ul class="nav nav-pills">
              <li class="active"><a data-toggle="tab" href="#keys<?php print $i; ?>"><?php print t('Keys'); ?></a></li>
    <?php if (!$app['noproducts']) : ?>
              <li><a data-toggle="tab" href="#profile<?php print $i; ?>"><?php print t('Products'); ?></a></li>
      <?php if (isset($app['smartdocs'])) : ?>
              <li><a data-toggle="tab" href="#docs<?php print $i; ?>"><?php print t('Docs'); ?></a></li>
      <?php endif; ?>
    <?php endif; ?>
              <li><a data-toggle="tab" href="#details<?php print $i; ?>"><?php print t('Details'); ?></a></li>
    <?php if ($show_analytics): ?>
              <li><?php print l(t('Analytics'), $app['detail_url']); ?></li>
    <?php endif; ?>
    <?php if (user_access("edit developer apps")): ?>
              <li class="hidden-xs apigee-modal-link-edit"><a href="<?php print base_path() . $app['edit_url']; ?>" data-toggle="modal" data-target="#edit-<?php print $app['id']; ?>"><?php print t('Edit "%n"', array('%n' => $app['app_name'])); ?></a></li>
              <li class="visible-xs apigee-modal-link-edit"><a href="<?php print base_path() . $app['edit_url']; ?>" data-toggle="modal" data-target="#edit-<?php print $app['id']; ?>"><?php print t('Edit'); ?></a></li>
    <?php endif; // edit developer apps ?>
    <?php if (user_access("delete developer apps")): ?>
              <li class="hidden-xs apigee-modal-link-delete"><a href="<?php print base_path() . $app['delete_url']; ?>" data-toggle="modal" data-target="#delete-<?php print $app['id']; ?>"><?php print t('Delete "%n"', array('%n' => $app['app_name'])); ?></a></li>
              <li class="visible-xs apigee-modal-link-delete"><a href="<?php print base_path() . $app['delete_url']; ?>" data-toggle="modal" data-target="#delete-<?php print $app['id']; ?>"><?php print t('Delete'); ?></a></li>
    <?php endif; // delete developer apps ?>
            </ul>AUTODESK DONT WANT THIS-->
             
    <?php if (user_access('edit developer apps')): ?>
    <!-- Edit Modal -->
            <div class="modal fade" id="edit-<?php print $app['id']; ?>" tabindex="-1">
              <div class="modal-dialog">
                <div class="modal-content">
                  <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                    <h4 class="modal-title" id="edit-<?php print $app['id']; ?>-title"><?php print t('Edit @name', array('@name' => $app['app_name'])); ?></h4>
                  </div>
                  <div class="modal-body"></div>
                  <div class="modal-footer">
                    <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                  </div>
                </div>
              </div>
            </div>
    <?php endif; ?>
    <!-- Delete Modal -->
    <?php if (user_access('delete developer apps')): ?>
            <div class="modal fade" id="delete-<?php print $app['id']; ?>" tabindex="-1">
              <div class="modal-dialog">
                <div class="modal-content">
                  <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                    <h4 class="modal-title" id="delete-<?php print $app['id']; ?>-title"><?php print t('Delete @name', array('@name' => $app['app_name'])); ?></h4>
                  </div>
                  <div class="modal-body"></div>
                  <div class="modal-footer"></div>
                </div>
              </div>
            </div>
    <?php endif; ?>
            <div class="tab-content">
				<div class="row">
					<div class="col-lg-6">
						<div class="app-data">
							<div>
								<?php print t('Consumer Key'); ?>:
							</div>
							<div>
								<?php print $app['credential']['consumerKey']; ?>
							</div>
						</div>
						<div class="app-data">
							<div>
								<?php print t('Consumer Secret'); ?>:
							</div>
							<div>
								<?php print $app['credential']['consumerSecret']; ?>
							</div>
						</div>
						<div class="app-data">
							<div>
								<?php print t('Key Expiration'); ?>:
							</div>
							<div>
								<?php $exp = $app['credential']['expires'];
									if ($exp == -1) {
									  print t('Never');
									}
									else {
									  print format_date($exp);
									}
                            	?>
							</div>
						</div>
					</div>
					<div class="col-lg-6">
						<div class="app-data">
							<div>
								<?php print t('API Products'); ?>:
							</div>
							<div>
								<ul style="margin:0;padding:0;">
                                	<?php foreach ($app['credential']['apiProducts'] as $product): ?>
                                  	<li style="margin:0;padding:0;list-style-type:none;">
									  <?php print $product['displayName']; ?>
									</li>
                                	<?php endforeach; ?>
								</ul>
							</div>
						</div>
					</div>
				</div>
				<div class="row">
					<div class="col-lg-12 actions-links">
						<?php if (user_access("edit developer apps")): ?>
						<a href="<?php print base_path() . $app['edit_url']; ?>"><?php print t('Edit'); ?></a>
						<?php endif; // edit developer apps ?>
    					<?php if (user_access("delete developer apps")): ?>
              			<a href="<?php print base_path() . $app['delete_url']; ?>"><?php print t('Delete'); ?></a>
    					<?php endif; // delete developer apps ?>
					</div>
				</div>
			</div>
		 </div>
		</div>
	   </div>
	</div>
    <?php $i++; endforeach; // applications ?>
  </div>
</div>
  
<?php else : ?>
  <?php // only one application ?>
  <div class="row">
    <div class="col-sm-12">
		<div class="row page-header">
			<div class="col-sm-6">
				<!-- Title -->
				<h1><?php print t("$plural_downcase"); ?></h1>
			</div>
			<?php if ($add_app): ?>	
			<div class="col-sm-6">
				<div class="add-app-button pull-right">
					<?php print $add_app; ?>
			  	</div>
			</div>
			<?php endif; ?>
	  	</div>	
    </div>
  </div>
<?php endif; // application_count ?>