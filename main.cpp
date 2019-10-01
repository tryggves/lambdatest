/**
 * Thi program is for self training on c++ lambda test.
 *
 * See article in Dr.Dobbs:
 * http://www.drdobbs.com/cpp/lambdas-in-c11/240168241
 */

#include <iostream>
#include <algorithm>    // Functions to be used on range of elements (STL)
#include <vector>       // Vector container class (STL)
using namespace std;

// ====================================================================================
// Lambda expression syntax:
// Here are all parts of a lambda expression: Return type declared as void
// [] captures the variables (in scope) available to lambda function
// () captures parameters to the function
// -> declares the return type
// {} captures the statements
//
// Example (with return type declared as -> void
// auto lambda4 = [](void) -> void { cout << "Code within lambda4 expression " << endl; };


//=======================================================================
// Example 3 help function - this is replaced with lambda expression
//=======================================================================
bool is_greater_than_5 (int value) {
    return (value > 5);
}

int main() {
    cout << "===============================================================================" << endl;
    cout << "=== Testing and training lambda expressions.                                ===" << endl;
    cout << "===============================================================================" << endl;

    // ========  EXAMPLE 1 ====================================================
    // This version is without the return type
    auto lambda1 = []() { cout << "Code within lambda1 expression " << endl; };

    // This version is without the optional parameters list
    auto lambda2 = [] { cout << "Code within lambda2 expression " << endl; };

    // Parameters list with void keyword
    auto lambda3 = [](void) { cout << "Code within lambda3 expression " << endl; };

    // This shows the lambda expression with all parts: Return type declared as void
    // [] captures the variables (in scope) available to lambda function
    // () captures parameters to the function
    // -> declares the return type
    // {} captures the statements
    auto lambda4 = [](void) -> void { cout << "Code within lambda4 expression " << endl; };

    lambda1();
    lambda2();
    lambda3();
    lambda4();

    // ========  EXAMPLE 2 ====================================================
    // lamda expression that takes two parameters x and y and sums them
    auto sum = [](int x, int y) -> int { return x + y; };
    cout << "sum of 1 and 2 is: " << sum(1,2) << endl;

    // ========  EXAMPLE 3 ====================================================
    vector<int> numbers { 1,2,3,4,5,6,7,8,9,10,15,20,25,35,45,50 };

    // This calls the helper bool function as the predicate (making the assertion on the parameter)
    auto greater_than_5_count1 = count_if(numbers.begin(), numbers.end(), is_greater_than_5);
    cout << "Number of elements greater than 5 is: " << greater_than_5_count1 << endl;

    // This shows a lambda expression that does the same
    auto greater_than_5_count2 = count_if(numbers.begin(), numbers.end(), [](int x) -> bool { return x > 5; });
    cout << "Number of elements greater than 5 is: " << greater_than_5_count2 << endl;

    // Can include the whole expression in the cout statement - notice we can skip the return type
    cout << "Number of elements greater than 5 is: " <<
        count_if(numbers.begin(), numbers.end(), [](int x) {return x>5;}) << endl;


    // ========= EXAMPLE 4 =======================================================
    // This shows the use of how values from the enclosing scope can be captured
    // either by value or by reference into the Lambda expression.
    //
    // This is done in the first [] part of the lambda expression by inserting either
    // '=' or '&' between the brackets.
    int x = 1;
    // Capture x by value
    auto valueLambda = [=]() -> void { cout << "Capture x by value: x=" << x << endl; };
    // Capture x by reference
    auto refLamda = [&]() -> void { cout << "Capture x by reference: x=" << x << endl; };

    // Assign a new value to x
    x = 13;
    // Call the lambda expressions
    valueLambda();  // This prints x value at time of declaring the lambda expression
    refLamda();     // This prints x value at time of running the lambda expression.


    return 0;
}