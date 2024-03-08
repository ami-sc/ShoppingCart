/**
 * @file    ShoppingCart.cpp
 * @brief   Implementation of methods defined in the ShoppingCart.hpp file.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#include "ShoppingCart.hpp"

/**
 * @brief       Constructs a new ShoppingCart object, given a .csv file
 *              containing the catalog specification.
 *
 * @param   catalog_file    Path to the catalog file to initialize the Catalog.
 */
ShoppingCart::ShoppingCart (string catalog_file)
{
    _catalog = new Catalog {catalog_file};
}

/**
 * @brief       De-allocates memory used by the Catalog of the Shopping Cart,
 *              following RAII specifications.
 */
ShoppingCart::~ShoppingCart ()
{
    delete _catalog;
}

/**
 * @brief       Calculates the total price of the items in the Shopping Cart,
 *              taking into account shipping costs and offers.
 *
 * @details     Offers are assumed to be applied before shipping costs.
 */
double ShoppingCart::getTotalPrice ()
{
    double running_total = 0;

    /* Find the quantities of the products and add the corresponding amounts. */
    map<string, Product>::iterator it;
    for (it = _cart.begin(); it != _cart.end(); it++)
    {
        running_total += (it -> second).getPrice() *
                         (it -> second).getQuantity();
    }

    /** Product Offers **/

    it = _cart.find("RF1");
    if (it != _cart.end())
    {
        /* Check how many red flowers are in cart. */
        int num_flow = (it -> second).getQuantity();

        /*
         * In case of an even number, half of the red flowers are half price.
         * In case of an odd number, the floor of the half will give the
         * amount of the flowers with half price.
         *
         * In any case, the int type of the num_flow will floor (drop) the
         * decimals, so it can be correctly implemented as num_flow / 2, which
         * covers any odd number case.
         */
        running_total -= (num_flow / 2) *
                         ((it -> second).getPrice() * 0.5);
    }

    /** Shipping Discounts **/

    if (running_total < 50)
    {
        running_total += 4.95;
    }
    else if (running_total > 50 && running_total < 90)
    {
        running_total += 2.95;
    }

    /* Any cart above $90 will not have any cost added. */

    return running_total;
}

/**
 * @brief       Gets the total number of items (considering quantities)
 *              currently in the cart.
 */
int ShoppingCart::getProductCount ()
{
    int total_count = 0;

    /* Find quantities of all items in the cart. */
    map<string, Product>::iterator it;
    for (it = _cart.begin(); it != _cart.end(); it++)
    {
        total_count += (it -> second).getQuantity();
    }

    return total_count;
}
