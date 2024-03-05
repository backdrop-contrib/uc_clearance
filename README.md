Ubercart Clearance
==================

Ubercart Clearance applies some special behaviors that apply to _clearance_ products, i.e., products that when sold out, will not be reordered.

* On the product page for clearance items,
    * display the available quantity
    * for products with selectable attributes, only show in-stock attributes
    * remove the "add to cart" button if we're out of stock.
* On the cart page, check quantities against stock levels before going on to checkout.
* On the checkout page, again check quantities against stock levels before "review order".
* When an order is placed, check to see if any products were Clearance and
had their stock levels decremented to zero. When we've sold the last product, optionally
unpublish it from the catalog (which is done via a Rule that can be disabled).

There are two ways to identify clearance products:

* When only a subset of products are on clearance, clearance products are identified by being assigned the Clearance catalog term, which is configurable.
* Alternatively, you can make all products in the catalog have clearance behavior if, for example, one is selling only one-of-a-kind items.


Installation
------------

Install this module using [the official Backdrop CMS instructions](https://backdropcms.org/guide/modules).

Visit the configuration page under Administration > Store > Configuration >
Clearance (admin/store/settings/clearance) and select the vocabulary term that
should be applied to Clearance products. Apply this term to any products that
you want the clearance behavior to apply to. Alternatively, you can choose to make all tracked products Clearance products.

You can use the Views interface to create a listing of all Clearance products
  if desired.

The default behavior is to unpublish a clearance product when its stock (across all options) goes to zero. If you would like to disable this behavior, visit the Rules interface at admin/config/workflow/rules and look for the rule with the `uc_clearance` tag.

Issues
------

Bugs and feature requests should be reported in [the issue queue](https://github.com/backdrop-contrib/uc_clearance/issues).

Current Maintainers
-------------------

- [Robert J. Lang](https://github.com/bugfolder)

Credits
-------

- Ported to Backdrop CMS by [Robert J. Lang](https://github.com/bugfolder).
- Originally written for Drupal by [Robert J. Lang](https://github.com/bugfolder) for OrigamiUSA.

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
