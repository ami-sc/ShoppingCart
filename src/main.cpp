/**
 * @file    main.cpp
 * @brief   Testing suite for the Shopping Cart.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#include <iostream>
    using std::cout;
    using std::endl;
#include <iomanip>
    using std::left;
    using std::setw;
#include <cmath>

#include "ShoppingCart.hpp"
#include "Catalog.hpp"
#include "Product.hpp"

void check_int    (int expected, int result);
void check_double (double expected, double result);
void check_string (string expected, string result);

const double EPSILON = 0.0000001;

int main ()
{
    /** Testing Suite for Product Class **/

    cout << endl << "[ > ] Begin tests for Product"
         << endl << endl;

    cout << left << setw(8) << "Result"
         << left << "Test Description" << endl;

    for (int i = 0; i <= 50; i++)
    {
        cout << '-';
    }

    cout << endl;

    Product test_product = {"Red Flower", 32.95};
    check_double(32.95, test_product.getPrice());
    cout << "[01] Test Product getPrice() method." << endl;

    check_string("Red Flower", test_product.getName());
    cout << "[02] Test Product getName() method." << endl;

    test_product.increaseQuantity();
    test_product.increaseQuantity();
    check_int(3, test_product.getQuantity());
    cout << "[03] Test Product increaseQuantity() method." << endl;

    /** Testing Suite for Catalog Class **/

    cout << endl << "[ > ] Begin tests for Catalog"
         << endl << endl;

    cout << left << setw(8) << "Result"
         << left << "Test Description" << endl;

    for (int i = 0; i <= 50; i++)
    {
        cout << '-';
    }

    cout << endl;

    Catalog test_catalog {"product_catalog.csv"};

    check_int(3, test_catalog.getProductCount());
    cout << "[01] Test correct initialization." << endl;

    check_string("Blue Flower", test_catalog.getProduct("BF1").getName());
    cout << "[02] Test getProduct() method." << endl;

    check_string("Green Flower", test_catalog.getProduct("GF1").getName());
    cout << "[03] Test getProduct() method." << endl;

    try
    {
        test_catalog.getProduct("ZZ").getName();
        cout << left << setw(8) << "FAILED";
    }
    catch(const std::out_of_range&)
    {
        cout << left << setw(8) << "PASSED";
    }

    cout << "[04] Test getProduct() with product not in Catalog." << endl;

    ShoppingCart test_cart01 {"product_catalog.csv"};

    /** Testing Suite for ShoppingCart Class **/

    cout << endl << "[ > ] Begin tests for ShoppingCart"
         << endl << endl;

    cout << left << setw(8) << "Result"
         << left << "Test Description" << endl;

    for (int i = 0; i <= 50; i++)
    {
        cout << '-';
    }

    cout << endl;

    test_cart01.addProducts("BF1");
    check_int(1, test_cart01.getProductCount());
    cout << "[01] Test adding a Product." << endl;

    test_cart01.addProducts("RF1");
    check_int(2, test_cart01.getProductCount());
    cout << "[02] Test adding a different Product." << endl;

    test_cart01.addProducts("RF1");
    check_int(3, test_cart01.getProductCount());
    cout << "[03] Test adding a Product already in the cart." << endl;

    ShoppingCart test_cart02 {"product_catalog.csv"};

    test_cart02.addProducts("BF1", "GF1");
    check_int(2, test_cart02.getProductCount());
    cout << "[04] Test adding multiple Products at a time." << endl;

    check_double(37.85, test_cart02.getTotalPrice());
    cout << "[05] Test shipping for orders less than $50." << endl;

    ShoppingCart test_cart03 {"product_catalog.csv"};

    test_cart03.addProducts("RF1", "GF1");
    check_double(60.85, test_cart03.getTotalPrice());
    cout << "[06] Test shipping for orders higher than $50 but less than 90$."
         << endl;

    ShoppingCart test_cart04 {"product_catalog.csv"};

    test_cart04.addProducts("BF1", "BF1", "RF1", "RF1", "RF1");
    check_double(98.275, test_cart04.getTotalPrice());
    cout << "[07] Test shipping for orders higher than $90."
         << endl;

    ShoppingCart test_cart05 {"product_catalog.csv"};

    test_cart05.addProducts("RF1", "RF1");
    check_double(54.375, test_cart05.getTotalPrice());
    cout << "[08] Test special offer for Red Flowers."
         << endl;

    test_cart05.addProducts("ZZ");
    check_int(2, test_cart05.getProductCount());
    cout << "[09] Test adding Product not in catalog."
         << endl;

    return 0;
}

/**
 * @brief   Check the result of a function returning an integer.
 *
 * @param   expected    Expected integer result of tested function.
 * @param   result      Produced integer result of tested function.
 */
void check_int (int expected, int result)
{
    if (expected == result)
    {
        cout << left << setw(8) << "PASSED";
    }
    else
    {
        cout << left << setw(8) << "FAILED";
    }
}

/**
 * @brief   Check the result of a function returning a double.
 *
 * @param   expected    Expected double result of tested function.
 * @param   result      Produced double result of tested function.
 */
void check_double (double expected, double result)
{
    if ((fabs(expected - result) < EPSILON))
    {
        cout << left << setw(8) << "PASSED";
    }
    else
    {
        cout << left << setw(8) << "FAILED";
    }
}

/**
 * @brief   Check the result of a function returning a string.
 *
 * @param   expected    Expected string result of tested function.
 * @param   result      Produced string result of tested function.
 */
void check_string (string expected, string result)
{
    if (expected == result)
    {
        cout << left << setw(8) << "PASSED";
    }
    else
    {
        cout << left << setw(8) << "FAILED";
    }
}
