# Sales Management System

This is a simple console-based application for managing product sales. The application allows you to add products, calculate their sales value, and display the list of products.

## Features

- **Add Product Details:** Enter the name, code, price, and stock quantity of a product.
- **Calculate Sales Value:** Automatically calculate the sales value of a product based on its price and stock quantity.
- **Display Products:** Display the list of all products with their details.

## Files

- `sales.c`: The main source code file containing the implementation of the sales management system.

## Prerequisites

- GCC (GNU Compiler Collection) or any C compiler installed on your system.

## How to Compile and Run

1. **Compile the program:**

   Open a terminal or command prompt and navigate to the directory containing `sales.c`. Run the following command to compile the program:

   ```sh
   gcc sales.c -o sales
   ```

2. **Run the program:**

   After compiling, run the executable:

   ```sh
   ./sales
   ```

   On Windows, you may need to use:

   ```sh
   sales.exe
   ```

## Usage

1. **Adding Products:**

   When you run the program, you will be prompted to enter the number of products. For each product, you will be prompted to enter the name, code, price, and stock quantity. The sales value will be calculated automatically.

   Example:
   ```
   Enter the number of products: 2
   Enter the name of the product: Product A
   Enter the code of the product: 101
   Enter the price of the product: 10.5
   Enter the quantity in stock for this product (0-50): 20
   Enter the name of the product: Product B
   Enter the code of the product: 102
   Enter the price of the product: 15.0
   Enter the quantity in stock for this product (0-50): 30
   ```

2. **Displaying Products:**

   After entering the product details, the list of all products will be displayed with their details.

   Example:
   ```
   Name        code    price   stock   salesValue
   Product A   101     10.5    20      210.00
   Product B   102     15.0    30      450.00
   ```

## Function Descriptions

- **clearBuffer:** Clears the input buffer to avoid any unwanted characters.
- **inputSalesData:** Prompts the user to enter product details and saves them to the `records.txt` file.
- **calculateSalesValue:** Calculates the sales value of a product based on its price and stock quantity.
- **recursiveAdjustStock:** Recursively adjusts the stock quantity to ensure it does not exceed the maximum limit.
- **displayProducts:** Displays the list of all products with their details.
- **loadSalesData:** Loads product data from the `records.txt` file into the `product` array.

## Notes

- The product details are stored in a file named `records.txt`.
- The maximum stock quantity for a product is limited to 50.

## License

This project is licensed under the MIT License.