<?php
/**
 * @file
 * dev_portal_base_fields.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function dev_portal_base_fields_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'ddws-new-handshake-get-token',
    'description' => 'Gets a valid Access Token using the new handshake method.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '00227fac-afa6-4f08-8cec-602a85b900b9',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-new-handshake-get-token',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'pet',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '07e9248a-e41f-41e7-a9bf-a4c3e16d45ac',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'petstore_example',
    'description' => 'Manage inventory and users through an example REST API patterned after the classic pet store demo.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '1278f3ae-a5d4-490f-b722-c7c256c3a64f',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Pet Store Example API',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OPTIONS',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '16ef0d5d-2f79-45fe-8d55-10af6f2122db',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'pet',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '17b7deb8-59c0-4010-9b14-435e33b5c69b',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'Get Weather',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '17bf6b09-ee4b-4cf4-8bc9-fdaadef023c3',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'store',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '21fa4130-176c-4ef9-906d-2306566b454c',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'POST',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '29fc8fb5-afe2-40aa-b3bb-299345289fa5',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'CONNECT',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2ac70e79-c5aa-4304-b2c9-e6355d08b584',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'CONNECT',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '2fab2b0e-8650-4d9b-af10-d9a445cd502a',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'TRACE',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '3969a147-148d-4702-8858-114ceedc151e',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'ddws-new-handshake-orders',
    'description' => 'Get Order Details and Get Orders List',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '3fa96dae-753f-474f-9a87-1ec26b43420e',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-new-handshake-orders',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'weather_example',
    'description' => 'Get weather reports for any location using the Yahoo Weather API.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '469606ee-2767-4555-8b2b-3c94ff01a94c',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Weather Example API',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'null',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4cf0d428-aca2-4a4a-a6b1-93ef52edcddf',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'ddws-get-orderdetailsandlist-',
    'description' => '<p>This service will provide Partners with detailed order information, including contract numbers, serial numbers, and product information.</p> ',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '5076b404-1533-40bc-aa56-383f9afee7a5',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-get-orderDetailsAndList',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'store',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5c876e1b-ff9e-4d3e-8342-9f5f47af970c',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'InvoicesList',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5c946152-b9b6-422e-9e23-06422a1d1ed2',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'user',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '5f492bbd-649a-4c3b-80c5-eb7b443de7a4',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'user',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '6ad99557-be25-4036-8460-516c1c00440d',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'ddws-new-handshake-get-license',
    'description' => '<p>This service will retrieve information for a given serial number or for a combination of product line code and serial numbers.</p>',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '7376b8f0-c46c-4ec6-b2f9-7f91bea22394',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-new-handshake-get-license',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'DDS Program Service Layer API',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '816e7a24-c1ad-48ef-99f3-8168f8515c1a',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'HEAD',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '819542bf-e1f2-4b04-9fbe-41df00d1acc9',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'GET',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '8505abe0-2394-4deb-92e4-cfd974b9f987',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'HEAD',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '869448ec-95b4-47ce-982c-f1d664354519',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'ddws-get-token',
    'description' => '<p>Get a valid access token using the <strong>OLD </strong>handshake algorithm</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '8947756c-e423-48d7-b176-8b338b1ffca6',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-get-token',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Token',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '93587378-3cfd-49c6-98cf-847ec9b8fd6e',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'PUT',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9c7089b4-ab27-4e4b-a615-702813276272',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'ddws',
    'description' => 'ddws',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '9ec15fb3-ce57-4b3e-aecb-7fe6b6587522',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'Digital Distribution Web Services',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Get Weather',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'a2c6b5ab-6c78-4f54-962a-d712fb9869b6',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'OrderDetails',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'ade4cd30-e5af-4759-945c-93092ad5c4fd',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'GET',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'b5accfae-90f6-4f20-8ef3-aa23ffa5955f',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'PUT',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'bc7697da-85f3-4cd7-91ee-e98447486959',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'POST',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c11b92a0-ae5c-4484-8f67-ed46029708df',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'Invoices',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'c51aafc3-f10e-4d7d-9004-26309f4b796b',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'ddws-get-license',
    'description' => '<p>This service will retrieve information for a given serial number or for a combination of product line code and serial numbers.</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c5fbe973-70cc-4e07-b70c-c45b3091d836',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-get-license',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OPTIONS',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c8330b77-3b3f-45fb-bb61-e7d2a0b6a7c5',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'license',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'cb172604-7c08-4017-8fb2-a928e8726562',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'ddws-get-invoice',
    'description' => '<p>Gets Invoice details and list using the old handshake method.</p>

<p>This service will get the invoices corresponding to a particular period, and the invoice details for a particular Invoice Number, Purchase Order Number, Sales Order Number</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'cb6d54e4-c3fb-4406-986c-14db61716ee9',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-get-invoice',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'InvoiceDetails',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd0a39d53-1682-418c-bb83-c22b4eb299e3',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'OrderList',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd4dd2670-cfdc-4de4-905d-19aa6e765a1a',
    'vocabulary_machine_name' => 'smartdocs_tags',
  );
  $terms[] = array(
    'name' => 'TRACE',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'd566f89c-a77b-4a6b-b4fd-a577d1d5bff7',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'DELETE',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'dd0431f9-aff4-48b5-896e-4df79a4ce672',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  $terms[] = array(
    'name' => 'ddws-new-handshake-get-invoice',
    'description' => '<p>This service will get the invoices corresponding to a particular period, and the invoice details for a particular Invoice Number, Purchase Order Number, Sales Order Number</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'eaa97fb1-3038-40f8-b478-b31eb447a9a9',
    'vocabulary_machine_name' => 'smartdocs_models',
    'field_model_display_name' => array(
      'und' => array(
        0 => array(
          'value' => 'ddws-new-handshake-get-invoice',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'DELETE',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'f8980d2a-524a-4925-997a-305057f3b95a',
    'vocabulary_machine_name' => 'smartdocs_verbs',
  );
  return $terms;
}
