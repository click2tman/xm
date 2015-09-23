<?php
/**
 * @file
 * dev_portal_bean_blocks.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function dev_portal_bean_blocks_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'Building an App (Home)',
    'description' => NULL,
    'title' => '',
    'type' => 'home_page_callouts',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'building-an-app-home',
    'view_mode' => 'default',
    'created' => 1439573483,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'ea631fd6-b858-4964-968a-230ff0161851',
    'uuid' => '3014f4c1-08f7-4b97-99e6-700ae21079c5',
    'field_callout_description' => array(
      'und' => array(
        0 => array(
          'value' => '<div class="container">
<div>
<h3>Creating and building your Autodesk Partner App is easy</h3>
</div>

<div class="row">
<div class="col-md-4">
<div>
<div><img src="sites/all/themes/autodesk/images/icons/steps-icons/steps-icons-01.svg" /></div>
</div>

<h5>Learn</h5>

<div class="clearfix">
<div>1</div>

<div>Get acquainted with our services by reading our reference documentation</div>
</div>
</div>

<div class="col-md-4">
<div>
<div><img src="sites/all/themes/autodesk/images/icons/steps-icons/steps-icons-02.svg" /></div>
</div>

<h5>Build</h5>

<div class="clearfix">
<div>2</div>

<div>Begin building an app for all your selected service</div>
</div>
</div>

<div class="col-md-4">
<div>
<div><img src="sites/all/themes/autodesk/images/icons/steps-icons/steps-icons-03.svg" /></div>
</div>

<h5>Test</h5>

<div class="clearfix">
<div>3</div>

<div>Begin testing your app by going to the API Documentation or API console</div>
</div>
</div>
</div>

<div class="text-center"><a class="btn btn-default go" href="/user/me/apps">Start Creating Your App</a></div>
</div>
',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => '2af41d06-631e-4e99-bf24-623dff71eaea',
  );
  $beans[] = array(
    'label' => 'Footer',
    'description' => NULL,
    'title' => '',
    'type' => 'home_page_callouts',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'footer',
    'view_mode' => 'default',
    'created' => 1440106644,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => '43707475-aa4d-49fe-95e4-4f1b9b2b21cd',
    'uuid' => '59a9188f-020d-4d32-b9a9-440e9f8c3114',
    'field_callout_description' => array(
      'und' => array(
        0 => array(
          'value' => '<div class="container">
<ul class="footer-links nav">
	<li><a href="/node/9" title="Privacy Policy &amp; Cookies">Privacy Policy &amp; Cookies</a></li>
	<li><a href="/node/60" title="Terms &amp; Use">Terms &amp; Use</a></li>
	<li><a href="/node/61" title="Legals Notices &amp; Trademarks">Legals Notices &amp; Trademarks</a></li>
	<li><a href="/sitemap" title="Sitemap">Sitemap</a></li>
</ul>

<div class="copy">
<p>&copy; 2015 <a href="https://www.autodesk.com" target="_blank">Autodesk Inc.</a> All rights reserved.</p>
</div>
</div>
',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => 'a8a0c446-2466-4716-a15d-122e7e23c7d3',
  );
  $beans[] = array(
    'label' => 'dev homepage header',
    'description' => NULL,
    'title' => '',
    'type' => 'home_page_callouts',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'dev-homepage-header',
    'view_mode' => 'default',
    'created' => 1439573388,
    'log' => '',
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'dc514e31-7a9f-4305-83d0-b17d39ecae26',
    'uuid' => 'ebe93a01-25f9-4b13-80ad-6f58b493ccd5',
    'field_callout_description' => array(
      'und' => array(
        0 => array(
          'value' => '<div class="content">
<div class="container">
<div class="row">
<div class="col-md-7">
<h1>Make your own apps using Autodesk Partner web services</h1>

<p>Access Autodesk web services to make operating your business easier</p>
<a class="btn btn-primary go" href="/next-steps">Learn How</a></div>
</div>
</div>
</div>
',
          'format' => 'full_html',
        ),
      ),
    ),
    'user_uuid' => '2af41d06-631e-4e99-bf24-623dff71eaea',
  );
  return $beans;
}
