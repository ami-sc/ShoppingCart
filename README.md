# Shopping Cart

An implementation of a simple shopping cart using C++.

## Explanation

The `ShoppingCart` class is implemented on top of an `std::map`, which maps product codes to a `Product` object.

The `Product` is a simple object consisting of a name, a price, and a quantity (used only in the cart).

To function properly, a `Catalog` object is needed, which is implemented similarly to the shopping cart. It is initialized using a `.csv` file containing the catalog specification.

Whenever an item is added to the cart, the ShoppingCart checks if it is present in the catalog and requests the item to add, simply by giving a valid product code.

The current implementation assumes the following:
 - Each product code is unique.
 - The `.csv` file follows the format `product,code,price`.
 - Product codes are represented as `std::string` objects.
 - The `product_catalog.csv` file is present in the source code directory.

For deeper details, each function is individually documented in the corresponding source files.

## Compiling

To compile the source code:

```sh
cd ./src
g++ -Wall -Wextra -pedantic -std=c++17 *.cpp
```

## Testing

The `main.cpp` file contains an automated testing suite that can be executed by:

```sh
./a.out
```
