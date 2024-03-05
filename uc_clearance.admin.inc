<?php
/**
 * @file
 * Administration page for the Ubercart Clearance module.
 */

/**
 * Admin settings form.
 */
function uc_clearance_settings_form() {
  $form['#config'] = 'uc_clearance.settings';
  $config = config('uc_clearance.settings');
  $form['method'] = array(
    '#type' => 'radios',
    '#title' => t('Method'),
    '#description' => t('Select which products should be treated as clearance products.'),
    '#options' => array(
      'tid' => t('Products with a particular catalog term'),
      'all' => t('All tracked products'),
    ),
    '#default_value' => $config->get('method'),
  );

  $vocabulary = config_get('uc_catalog.settings', 'uc_catalog_vocabulary');
  $tree = taxonomy_get_tree($vocabulary);
  $options = array(
    '' => t('<none>'),
  );
  foreach ($tree as $leaf) {
    $options[$leaf->tid] = '';
    for ($i = 0; $i < $leaf->depth; $i++) {
      $options[$leaf->tid] .= '-';
    }
    $options[$leaf->tid] .= $leaf->name;
  }
  $form['tid'] = array(
    '#title' => t('Clearance catalog term'),
    '#type' => 'select',
    '#description' => t('Select the catalog term that applies to clearance products.'),
    '#options' => $options,
    '#default_value' => $config->get('tid'),
    '#states' => array(
      'visible' => array(
        ':input[name="method"]' => array('value' => 'tid'),
      ),
    ),
  );

  $filter_formats = filter_formats();
  $clearance_text = $config->get('clearance_text');
  $form['clearance_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Clearance text'),
    '#description' => t('Enter the text to display on clearance products. You can use the token QTY_AVAILABLE to indicate the quantity available (for products with attributes, it will show quantities for all attributes). Leave blank to display nothing.'),
    '#default_value' => $clearance_text['value'],
    '#format' => isset($filter_formats[$clearance_text['format']]) ? $clearance_text['format'] : filter_fallback_format(),
  );

  $sold_out_text = $config->get('sold_out_text');
  $form['sold_out_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Sold-out text'),
    '#description' => t('Enter the text to display on sold-out products. Leave blank to display nothing.'),
    '#default_value' => $sold_out_text['value'],
    '#format' => isset($filter_formats[$sold_out_text['format']]) ? $sold_out_text['format'] : filter_fallback_format(),
  );

  $form['disable_unit_qty'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable quantity in cart when stock = 1'),
    '#description' => t('When checked, this will disable the quantity in the shopping cart for a clearance product that has only one unit in stock, since the only allowed values are 1 and zero (in which case the Remove button will remove it from the cart).'),
    '#default_value' => $config->get('disable_unit_qty'),
  );

  return system_settings_form($form);

}
