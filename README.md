# Polynomial Equation Solver

## Overview

This C++ program allows you to input a polynomial equation, process it to determine its degree and coefficients, and solve the polynomial equation based on its degree. It can handle linear and quadratic equations and can be extended to handle higher degrees.

## Features

- Parses and validates a polynomial equation entered by the user.
- Determines the degree of the polynomial.
- Extracts the coefficients of the polynomial.
- Solves the polynomial equation for degrees 1 (linear) and 2 (quadratic).
- Handles real and complex roots for quadratic equations.

## Usage

1. **Input the Polynomial**:
   - The program prompts the user to enter a polynomial equation.

2. **Validation**:
   - The polynomial equation is validated for correct format, including checking for valid exponents and proper placement of plus/minus signs.

3. **Degree Determination**:
   - The degree of the polynomial is calculated.

4. **Coefficient Extraction**:
   - The coefficients of the polynomial are extracted and processed.

5. **Equation Solving**:
   - The polynomial equation is solved based on its degree.
   - Linear equations (degree 1) are solved directly.
   - Quadratic equations (degree 2) are solved using the quadratic formula, and both real and complex roots are handled.

## Program Flow

1. **Input and Validation**:
   - The user is prompted to enter a polynomial equation.
   - The input polynomial is validated using various checks (e.g., valid exponents, no digits directly after 'x', etc.).

2. **Degree Calculation**:
   - The degree of the polynomial is determined by parsing the input string.

3. **Coefficient Processing**:
   - The polynomial string is processed to extract the coefficients for each term.

4. **Solving the Polynomial**:
   - Depending on the degree, the polynomial is solved:
     - **Degree 1**: Solved as a linear equation.
     - **Degree 2**: Solved using the quadratic formula, handling both real and complex roots.

## Code Structure

### Main Function

The main function handles user input, validation, degree calculation, coefficient extraction, and solving the polynomial.

### Validation Functions

- `int check_digit(char c)`: Checks if a character is a digit.
- `bool check_exponent(const string& poly)`: Validates the exponent format in the polynomial.
- `bool check_number_before_x(const string& poly)`: Ensures no digits directly follow 'x'.
- `bool check_plus_minus(const string& poly)`: Checks the correct placement of plus/minus signs.
- `bool check_all(const string& poly)`: Combines all validation checks.

