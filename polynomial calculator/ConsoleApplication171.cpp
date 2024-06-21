#include <iostream>
#include <string>
#include <cmath>  // For sqrt and cbrt functions

const double pi = 3.14;
const int IMAX = 800;

using namespace std;

int check_digit(char c);
bool check_exponent(const string& poly);
bool check_number_before_x(const string& poly);
bool check_plus_minus(const string& poly);
bool check_all(const string& poly);
int get_degree(const string& poly);

typedef char* charptr;

int main() {
    string poly;
    charptr p;
    int degrees;
    double coefficients[6];
    long max_size = 200;
    int x = -1;
    int degree = 0;

    p = new char[max_size];
    cout << "Enter a polynomial Equation\n";
    getline(cin, poly);

    // Printing error
    if (!check_all(poly)) {
        cout << "Error";
        return 0;
    }

    // Get degree of the polynomial
    degree = get_degree(poly);
    cout << "Equation degree: " << degree << endl;

    // Remove spaces from the polynomial string
    size_t spacePos = poly.find(' ');
    while (spacePos != string::npos) {
        poly.replace(spacePos, 1, "");
        spacePos = poly.find(' ');
    }

    // Processing polynomial to extract coefficients
    for (size_t i = 0; i < poly.length(); i++) {
        if (poly[i] == '&' || poly[i] == ' ') continue;

        if ((poly[i] >= '0' && poly[i] <= '9') || poly[i] == '-' || poly[i] == '.') {
            x++;
            p[x] = poly[i];
            if (i == poly.length() - 1) {
                x++;
                p[x] = '*';
                x++;
                p[x] = '0';
            }
        }

        if ((poly[i] == '+' || poly[i] == '-') && poly[i + 1] == 'x') {
            x++;
            p[x] = '1';
        }
        else if (poly[i] == 'x') {
            if (i == 0) {
                x++;
                p[x] = '1';
            }
            x++;
            p[x] = '*';
            if (poly[i + 1] != '^') {
                x++;
                p[x] = '1';
                x++;
                p[x] = '&';
            }
        }
        else if (poly[i] == '^') {
            x++;
            p[x] = poly[i + 1];
            x++;
            p[x] = '&';
            i++;
        }
    }

    // Print coefficients
    for (int i = 0; i < max_size; i++) {
        if ((p[i] == '5') && (p[i - 1] == '*')) {
            if (degree < 5) degree = 5;
            int x = i - 2;
            while ((x > 0) && (p[x] != '*') && (p[x] != '&')) x--;
            cout << "coefficient of 5th degree x: ";
            while ((p[x] != '*') && (p[x] != '&')) cout << p[x++];
            cout << endl;
        }
        // Similar code for other degrees (4, 3, 2, 1, 0)...
    }

    // Convert string dynamic array to double array
    double* s = new double[degree + 1];
    bool availableDegrees[] = { false,false,false,false,false,false };
    int currentDegree = degree;
    string currentCoefficient = "";

    for (int i = 0; i < x; i++) {
        if (p[i] == '&') {
            s[currentDegree] = stod(currentCoefficient);
            currentCoefficient = "";
        }
        else if (p[i] == '*') {
            currentDegree = (int)(p[i + 1] - 48);
            availableDegrees[currentDegree] = true;
            i += 1;
        }
        else {
            currentCoefficient += p[i];
        }
    }

    if (currentCoefficient != "") {
        s[currentDegree] = stod(currentCoefficient);
    }

    // Solve the polynomial equation based on its degree
    if (degree == 1) {
        double b = s[1];
        double c = s[0];
        cout << "x equal\t" << -c / b << endl;
    }
    else if (degree == 2) {
        double a = s[2], b = s[1], c = s[0];
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and different." << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (discriminant == 0) {
            double x1 = -b / (2 * a);
            cout << "Roots are real and same." << endl;
            cout << "x1 = x2 = " << x1 << endl;
        }
        else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Roots are complex and different." << endl;
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
    else if (degree == 3) {
        // Cubic equation solving logic here...
    }
    else if (degree == 4) {
        // Quartic equation solving logic here...
    }

    delete[] p;
    delete[] s;
    return 0;
}

int check_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool check_exponent(const string& poly) {
    for (size_t i = 0; i < poly.length(); ++i) {
        if (poly[i] == '^' && (!check_digit(poly[i + 1]) || poly[i - 1] != 'x')) {
            return false;
        }
    }
    return true;
}

bool check_number_before_x(const string& poly) {
    for (size_t i = 0; i < poly.length(); ++i) {
        if (poly[i] == 'x' && check_digit(poly[i + 1])) return false;
    }
    return true;
}

bool check_plus_minus(const string& poly) {
    return !(poly[0] == '+' || poly[poly.length() - 1] == '+' || poly[poly.length() - 1] == '-');
}

bool check_all(const string& poly) {
    return check_plus_minus(poly) && check_exponent(poly) && check_number_before_x(poly);
}

int get_degree(const string& poly) {
    int degree = 0;
    for (size_t i = 0; i < poly.length(); ++i) {
        if (poly[i] == '^') {
            int current_degree = poly[i + 1] - '0';
            if (current_degree > degree) degree = current_degree;
        }
    }
    return degree;
}
