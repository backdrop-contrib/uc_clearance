<?php
/**
 * @file
 * Rules default configurations for uc_clearance.module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function uc_clearance_default_rules_configuration() {
  // After checkout, check the stock level on all products in the order and if
  // any of them were clearance and the stock level dropped to zero, unpublish
  // the product.
  $rule = rules_reaction_rule();
  $rule->label = t('Check clearance stock levels upon order submission');
  $rule->tags = array('uc_clearance');
  $rule->active = TRUE;
  $rule->weight = 1; // to fire *after* stock decrement
  $rule->event('uc_checkout_complete')
    ->action('uc_clearance_check_clearance_stock', array('order:select' => 'order'));
  $configs['uc_clearance_check_clearance_stock_on_order'] = $rule;

  return $configs;
}
