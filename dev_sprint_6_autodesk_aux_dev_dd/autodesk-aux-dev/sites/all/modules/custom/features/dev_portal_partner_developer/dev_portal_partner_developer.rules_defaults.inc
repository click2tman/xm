<?php
/**
 * @file
 * dev_portal_partner_developer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dev_portal_partner_developer_default_rules_configuration() {
  $items = array();
  $items['rules_create_developer_user_cloned_'] = entity_import('rules_config', '{ "rules_create_developer_user_cloned_" : {
      "LABEL" : "Create Developer User",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "eck" ],
      "ON" : { "partner_developers_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "partner-developers" ],
            "type" : "partner_developers",
            "bundle" : { "value" : { "developers" : "developers" } }
          }
        },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "11" : "11", "3" : "3" } },
            "operation" : "OR"
          }
        },
        { "entity_has_field" : { "entity" : [ "site:current-user" ], "field" : "field_ref_company_name" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_field_first_name" : "[partner-developers:field-first-name]",
              "param_field_last_name" : "[partner-developers:field-last-name]",
              "param_field_company_csn_no" : [ "site:current-user:field-ref-company-name:field-company-csn-no" ],
              "param_field_company_partner_type" : [ "site:current-user:field-ref-company-name:field-company-partner-type" ],
              "param_field_ref_company_name" : [ "site:current-user:field-ref-company-name" ],
              "param_field_sales_org_no" : [ "site:current-user:field-ref-company-name:field-sales-org-no" ],
              "param_field_user_account_types" : "Partner Developer",
              "param_name" : "[partner-developers:field-first-name].[partner-developers:field-last-name][partner-developers:id]",
              "param_mail" : "[partner-developers:field-email]"
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-created:status" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "name",
              "value" : [ "entity-created:name" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "username_fetched" : "Fetched user name" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "uid",
              "value" : [ "entity-created:uid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "partner-developers:field-developer-uiid" ],
            "value" : [ "entity-created:uid" ]
          }
        },
        { "data_set" : {
            "data" : [ "partner-developers:field-related-developer-user-acc" ],
            "value" : [ "username-fetched:0" ]
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : {
                  "data" : [ "site:current-user:field-ref-company-name:field-company-partner-type" ],
                  "value" : "Direct"
                }
              },
              "DO" : [
                { "user_add_role" : {
                    "account" : [ "entity-created" ],
                    "roles" : { "value" : { "8" : "8" } }
                  }
                }
              ]
            },
            { "ELSE" : [
                { "user_add_role" : {
                    "account" : [ "entity-created" ],
                    "roles" : { "value" : { "9" : "9" } }
                  }
                }
              ]
            }
          ]
        },
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "mail",
              "value" : [ "partner-developers:field-email" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "account_fetched" : "Fetched Account" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "account-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "user_send_account_email" : {
                  "account" : [ "list-item" ],
                  "email_type" : "register_no_approval_required"
                }
              },
              { "data_set" : {
                  "data" : [ "partner-developers:field-developer-uiid" ],
                  "value" : [ "list-item:uid" ]
                }
              }
            ]
          }
        },
        { "redirect" : { "url" : "[site:url]\\/admin\\/workbench\\/my-developers" } }
      ]
    }
  }');
  $items['rules_link_condition_disable_developer_account'] = entity_import('rules_config', '{ "rules_link_condition_disable_developer_account" : {
      "LABEL" : "Rules link: Disable Developer Account condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "partner_developers" : { "label" : "partner_developers", "type" : "partner_developers" } },
      "AND" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "11" : "11", "5" : "5", "3" : "3" } },
            "operation" : "OR"
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "partner-developers" ],
            "type" : "partner_developers",
            "bundle" : { "value" : { "developers" : "developers" } }
          }
        },
        { "data_is" : { "data" : [ "partner-developers:field-account-status" ], "value" : "1" } }
      ]
    }
  }');
  $items['rules_link_condition_enable_developer_account'] = entity_import('rules_config', '{ "rules_link_condition_enable_developer_account" : {
      "LABEL" : "Rules link: Enable Developer Account condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "partner_developers" : { "label" : "partner_developers", "type" : "partner_developers" } },
      "AND" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "11" : "11", "5" : "5", "3" : "3" } },
            "operation" : "OR"
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "partner-developers" ],
            "type" : "partner_developers",
            "bundle" : { "value" : { "developers" : "developers" } }
          }
        },
        { "data_is" : { "data" : [ "partner-developers:field-account-status" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_link_set_disable_developer_account'] = entity_import('rules_config', '{ "rules_link_set_disable_developer_account" : {
      "LABEL" : "Rules link: Disable Developer Account rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "partner_developers" : { "label" : "partner_developers", "type" : "partner_developers" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "partner-developers" ],
                  "type" : "partner_developers",
                  "bundle" : { "value" : { "developers" : "developers" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "partner-developers:field-account-status" ], "value" : "0" } },
              { "data_set" : {
                  "data" : [ "partner-developers:field-related-developer-user-acc:status" ],
                  "value" : "0"
                }
              },
              { "redirect" : { "url" : "\\/admin\\/workbench\\/my-developers" } }
            ],
            "LABEL" : "Disable Developer Account"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_enable_developer_account'] = entity_import('rules_config', '{ "rules_link_set_enable_developer_account" : {
      "LABEL" : "Rules link: Enable Developer Account rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "partner_developers" : { "type" : "partner_developers", "label" : "partner_developers" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "partner-developers" ],
                  "type" : "partner_developers",
                  "bundle" : { "value" : { "developers" : "developers" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "partner-developers:field-account-status" ], "value" : "1" } },
              { "data_set" : {
                  "data" : [ "partner-developers:field-related-developer-user-acc:status" ],
                  "value" : "1"
                }
              },
              { "redirect" : { "url" : "\\/admin\\/workbench\\/my-developers" } }
            ],
            "LABEL" : "Enable Developer Account"
          }
        }
      ]
    }
  }');
  return $items;
}
