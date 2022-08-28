<?php
/**
 * @file
 * Administration pages for the Ubercart Clearance module.
 */

/**
 * Admin settings form.
 */
function uc_clearance_settings_form() {
  $form['#config'] = 'uc_clearance.settings';

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

  $form['uc_clearance_tid'] = array(
    '#title' => t('Clearance catalog term'),
    '#type' => 'select',
    '#description' => t('Select the catalog term that applies to Clearance products.'),
    '#options' => $options,
    '#default_value' => config_get('uc_clearance.settings', 'uc_clearance_tid'),
  );

  return system_settings_form($form);

}
