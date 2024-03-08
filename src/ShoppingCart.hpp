/**
 * @file    ShoppingCart.hpp
 * @brief   Class declaration for a Shopping Cart containing Product objects
 *          from a given Catalog.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include <iostream>
    using std::cerr;
#include <string>
    using std::string;
#include <map>
    using std::map;
#include <vector>
    using std::vector;

#include "Product.hpp"
#include "Catalog.hpp"

class ShoppingCart
{
    public:
        ShoppingCart  (string catalog_file);
        ~ShoppingCart ();

        /** Accessors **/

        double getTotalPrice   ();
        int    getProductCount ();

        /**
         * @brief       Adds a Product from the Catalog to the Shopping Cart.
         *
         * @details     This method has to be implemented in the class
         *              declaration due to the use of the variadic template for
         *              accepting any number of arguments, which are assumed to
         *              be strings for the product codes to be added.
         *
         *              Any codes that are not in the Catalog will be ignored
         *              and not added.
         *
         * @param   args    Unique product codes (strings) to be added.
         */
        template <typename... Codes>
        void addProducts (const Codes&... args)
        {
            /* Unpack the argument list. */
            vector<string> codes {args...};
            for (string code : codes)
            {
                /* Check if the Product is not already in the cart. */
                map<string, Product>::iterator search_it = _cart.find(code);

                try
                {
                    if (search_it == _cart.end())
                    {
                        /* If not in the cart, add it. */
                        _cart.insert({code, _catalog -> getProduct(code)});
                    }
                    else
                    {
                        /* If in the cart, simply increase the quantity. */
                        (search_it -> second).increaseQuantity();
                    }
                }
                catch(const std::out_of_range&)
                {
                    /* Write to error stream the non-valid code. */
                    cerr << "Ignoring non-valid code "
                         << code << endl;
                }
            }
        }

    private:
        Catalog* _catalog = nullptr;
        map<string, Product> _cart;
};

#endif
