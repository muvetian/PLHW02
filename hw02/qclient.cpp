/*
 * CSC 322 Programming Languages (Mossinghoff)
 * P2 The World Turned Upside Down
 * Client Code: Incomplete posted version.
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
//#include "quaternion.h"

using namespace std;

int menu();
int generalTest();
void commutTest();
void assocTest();
void distrTestA();
void distrTestB();
void normTest();
void rotation();
void quit();

// Main: allow user to select any of six different tests of the Quaternion
// class, and repeat until the quit command is received.
int main() {
    cout.precision(7); // Number of decimal places to display when printing.
    int choice;
    do {
        choice = menu();
        try {
            switch (choice) {
            case 1: generalTest();break;
//                case 1: commutTest(); break;
//                case 2: assocTest(); break;
//                case 3: distrTestA(); break;
//                case 4: distrTestB(); break;
//                case 5: normTest(); break;
//                case 6: rotation(); break;
//                case 7: quit(); break;
                default: cout << "Invalid command." << endl; break;
            }
        } catch (domain_error& e) {
            cout << "domain_error exception: " << e.what() << endl;
        } catch (out_of_range& e) {
            cout << "out_of_range exception: " << e.what() << endl;
        } catch (exception& e) {
            cout << "generic exception: " << e.what() << endl;
        }
    } while (choice != 7);
    return 0;
}

// Simple routine to print the menu of options, and request a choice.
// Return the choice number to the caller.
int generalTest(){
	return 0;
}
int menu() {
    int ans = 0;
    cout << "\nPlease pick a number, any number.\n"
	 << "  1. Commutativity test.\n"
	 << "  2. Associativity test.\n"
	 << "  3. Distributive test A.\n"
	 << "  4. Distributive test B.\n"
	 << "  5. Norm test.\n"
	 << "  6. Rotations in 3D.\n"
	 << "  7. Quit.\n"
	 << "Enter choice: ";
    cin >> ans;
    #ifdef echo
        cout << ans << endl;
    #endif
    return ans;
}

//// Commutative check.
//// Tests: four-argument constructor, binary *, ==, <, >=.
//void commutTest() {
//    double a, b, c, d;
//    cout << "Enter four doubles for q: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion q(a, b, c, d);
//    cout << "Enter four doubles for r: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endi
//    Quaternion r(a, b, c, d);
//    Quaternion ans1 = q * r;
//    Quaternion ans2 = r * q;
//    cout << "q*r = " << ans1 << ";\nr*q = " << ans2 << ";\n";
//    if (ans1 == ans2) {
//        cout << "Equal!" << endl;
//    } else if (ans1 < ans2) {
//        cout << "q*r is smaller." << endl;
//    } else if (ans1 >= ans2) { // Logically extraneous but tests >=
//        cout << "q*r is larger." << endl;
//    }
//}
//
//// Associative check.
//// Tests: binary *, ==
//void assocTest() {
//    double a, b, c, d;
//    cout << "Enter four doubles for q: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion q(a, b, c, d);
//    cout << "Enter four doubles for r: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion r(a, b, c, d);
//    cout << "Enter four doubles for s: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion s(a, b, c, d);
//    Quaternion ans1 = (q * r) * s;
//    Quaternion ans2 = q * (r * s);
//    cout << "(q*r)*s = " << ans1 << ";\nq*(r*s) = " << ans2 << ";\n";
//    if (ans1 == ans2) cout << "Equal!" << endl;
//    else cout << "Not equal!" << endl;
//}
//
//// Distributive check A.
//// Tests: copy constructor, +, *, +=, *=, !=
//void distrTestA() {
//    double a, b, c, d;
//    cout << "Enter four doubles for q: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion q(a, b, c, d);
//    cout << "Enter four doubles for r: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion r(a, b, c, d);
//    cout << "Enter four doubles for s: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion s(a, b, c, d);
//    Quaternion ans1 = (q + r) * s;
//    Quaternion ans2 = q;
//    ans2 *= s;
//    ans2 += r*s;
//    cout << "(q+r)*s = " << ans1 << ";\nq*s + r*s = " << ans2 << ";\n";
//    if (ans1 != ans2) cout << "Not equal!" << endl;
//    else cout << "Equal!" << endl;
//}
//
//// Distributive check B.
//// Tests: binary -, /, -=, /=, assignment operator, default constructor, ==.
//void distrTestB() {
//    double a, b, c, d;
//    cout << "Enter four doubles for q: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion q(a, b, c, d);
//    cout << "Enter four doubles for r: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion r(a, b, c, d);
//    cout << "Enter four doubles for s: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion s(a, b, c, d);
//    Quaternion ans1; // will get (q-r)/s but we do this on several lines to test more operators.
//    ans1 = q;
//    ans1 -= r;
//    ans1 /= s;
//    Quaternion ans2 = q/s - r/s;
//    cout << "(q-r)/s = " << ans1 << ";\nq/s - r/s = " << ans2 << ";\n";
//    if (ans1 == ans2) cout << "Equal!" << endl;
//    else cout << "Not equal!" << endl;
//}
//
//// Norm check.
//// Tests: default constructor, brackets as lvalue, norm, ==.
//void normTest() {
//    double a, b, c, d;
//    cout << "Enter four doubles for q: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion q(a, b, c, d);
//    cout << "Enter four doubles for r: ";
//    cin >> a >> b >> c >> d;
//    #ifdef echo
//        cout << a << " " << b << " " << c << " " << d << endl;
//    #endif
//    Quaternion r;
//    r[0] = a;
//    r[1] = b;
//    r[2] = c;
//    r[3] = d;
//    double nq = q.norm();
//    double nr = r.norm();
//    double nqr = (q*r).norm();
//    cout << "N(q) = " << nq << ";\n"
//         << "N(r) = " << nr << ";\n"
//         << "N(q*r) = " << nqr << ";\n"
//         << "N(q)*N(r) = " << nq*nr << ";\n";
//    if (nqr == nq*nr) cout << "Equal!" << endl;
//    else cout << "Not equal!" << endl;
//}
//
//// Rotation (unfinished).
//// Tests: brackets as rvalue, conjugate, * or *=.
//void rotation() {
//    double nx, ny, nz, rx, ry, rz, theta;
//    cout << " Enter coordinates for axis of rotation: ";
//    cin >> nx >> ny >> nz;
//    #ifdef echo
//        cout << nx << " " << ny << " " << nz << endl;
//    #endif
//    cout << " Enter coordinates for object you are rotating: ";
//    cin >> rx >> ry >> rz;
//    #ifdef echo
//        cout << rx << " " << ry << " " << rz << endl;
//    #endif
//    cout << " Enter angle of rotation in degrees: ";
//    cin >> theta;
//    #ifdef echo
//        cout << theta << endl;
//    #endif
//
//    const double pi = 3.141592653589793;
//
//    // Add code to compute the unit normal, throw a domain_error if this
//    // is impossible, and then compute a quaternion named ans whose imaginary
//    // parts have the rotated coordinates.
//
//    // CODE REMOVED
//
//    cout << "\n Rotated position is (" << ans[1] << ", " << ans[2]
//         << ", " << ans[3] << ")" << endl;
//}

// Simple routine to call when the quit command is received.
void quit() {
    cout << "Thank you for playing!" << endl;
}
