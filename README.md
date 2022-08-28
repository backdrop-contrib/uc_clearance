Ubercart Clearance
==================

Ubercart Clearance applies some special behaviors that apply to clearance products, products that when sold out, will not be reordered: 

* Modify forms for clearance items to display the available quantity and remove
the "add to cart" button if we're out of stock.

* When an order is placed, check to see if any products were Clearance and
had their stock levels decremented to zero. When we've sold the last product,
unpublish it from the catalog. Implemented via a Rule.

* When orders are at the final submission stage, we check to make sure that
for any Clearance products, the order size does not exceed available stock.
Implemented via hook_order().

Clearance products are identified by being assigned the Clearance catalog term, which is configurable.


Installation
------------

Install this module using [the official Backdrop CMS instructions](https://backdropcms.org/guide/modules).

Visit the configuration page under Administration > Store > Configuration >
Clearance (admin/store/settings/clearance) and select the vocabulary term that
should be applied to Clearance products. Apply this term to any products that
you want the clearance behavior to apply to.

You can use the Views interface to create a listing of all Clearance products,
  if desired.

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
