<?php
/**
 * @file
 * Contains the Rules hooks and functions necessary for special handling of
 * clearance stock.
 */

/**
 * Implements hook_rules_action_info().
 */
function uc_clearance_rules_action_info() {
  $actions['uc_clearance_check_clearance_stock'] = array(
    'label' => t('Check clearance product stock levels and unpublish if stock is zero'),
    'group' => t('Stock'),
    'base' => 'uc_clearance_action_check_clearance_stock',
    'parameter' => array(
      'order' => array(
        'type' => 'uc_order',
        'label' => t('Order'),
      ),
    ),
  );
  return $actions;
}

/**
 * Check all products for clearance stock levels
 */
function uc_clearance_action_check_clearance_stock($order, $settings) {
  if (is_array($order->products)) {
    array_walk($order->products, '_uc_clearance_check_clearance');
  }
}
