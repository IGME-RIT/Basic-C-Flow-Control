/*
Flow Control
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// In the functions example, we shows how to define and use functions to run code in different places.
// This example will more thoroughly the idea of flow control in a program, and how to use it.
// If you've programmed in another language before, you can probably skip most of this, but you may see something you haven't seen before.


// Include iostream for output during the program.
#include <iostream>
// Use std to avoid writing std:: everywhere.
using namespace std;


// Start of main function
int main() 
{
    // The first thing we've encountered with flow control is our braces { }
    // These change the scope of a program, and while they technically aren't part of the flow control.
    // They are used everywhere, and it's useful to know that they can exit on their own too.
    {
        cout << "{ Braces control the scope of variables }" << endl;
    }
    cin.get();



    // Then there is the obvious if else statement:
    // If you put a true or false statement into the parenthesis the code inside the braces will execute.
    // If statements are pretty self explanatory, so I won't go too in-depth on them.

    cout << "if-else statements" << endl;
    if (10 < 5)
    {
        cout << "Math has failed us." << endl;
    }
    else if (10 < 10)                           // It is useful to note that else if, and else are not required.
    {                                           // You can have if-else if, or if-else do different things.
        cout << "No." << endl;                  // if-if is not the same as if-else if either.
    }
    else
    {
        cout << "The world is safe. 10 is not less than 10." << endl;
    }
    cin.get();



    // If the code inside the braces is only one line, you can exclude the braces:
    int x = 0;
    if (x == 0)
        x = 5;
    else
        x = 3;

    // You can also put it on the same line in this situation:
    if (x == 0) x = 5;
    else x = 3;

    // Also, if elses can be chained forever:
    if (false) x = 0;
    else if (false) x = 1;
    else if (false) x = 2;
    else if (false) x = 3;
    else if (false) x = 4;



    // When comparing one variable to a bunch of possible things in an if chain, don't.
    // Instead, use a switch statement. It looks like this:

    int y = 4;

    cout << "switch statement" << endl;
    switch (y) // the value inside of the parenthesis is the thing we are checking against
    {
        case 0:                         // case: 0 is similar to if(y = 0)
            cout << "y is 0" << endl;
            break;                      // if you hit a line with break, you will immediately leave the scope you are in.
        case 1:                         // break is what changes our switch statment from a bunch of ifs, to a bunch of if-elses.
            cout << "y is 1" << endl;   // break is also useful for some other things that will be explained later.
            break;
        case 2:
            cout << "y is 2" << endl;
            break;
        case 3:
            cout << "y is 3" << endl;
            break;
        default:                        // There's also a special case called default. This case will always happen if the switch statement gets here.
            cout << "y is not 0, 1, 2, or 3" << endl;   // It can be useful to catch incorrect inputs or ones that don't fall into a special case.
    }
    cin.get();


    // There's also a thing called goto, which we won't cover, because bad programmers use it.
    // You don't want to be a bad programmer. Do you?


    // while loop execute the same code over and over so long as a condition is met.
    int countDown = 5;

    cout << "Counting down: with while" << endl;
    while (countDown > 0)   // If this is true, execute the code inside the braces.
    {
        cout << countDown << endl;  // Print out the number
        countDown--;                // Decrement countdown by one.
    }
    cin.get();


    // If you want to make sure that the code inside the loop runs at least once, use a do-while loop
    // do while loops execute the code first, and then check the condition.
    cout << "Counting up: with do-while" << endl;
    do
    {
        cout << countDown << endl;  // Print countdown.
        countDown++;                // Increment countdown.
    }
    while (countDown < 5);          // Here we do the check, if it passes, go back to the top.
    cin.get();



    // for loops are a more complex way to do while loops:
    cout << "counting up with for loop" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }
    // The syntax for a for loop is a little weird. The parens contain 3 different things, and the braces contain the 'looped code'
    
    // Breaking it down:
    /*

    int i = 0;  // The first line of code that executes as part of the for loop. Conveniently, i now only exists inside the loop unlike our while loop above.

    i < 5;      // If this line is true, the loop will loop. (This is checked first similar to the while loop)

    i++;        // This line runs at the end of each loop iteration. In this case it increments i.

    */
    

    // Written as a while loop, the above for loop looks like this:
    cout << "for loop as a while loop:" << endl;
    {
        int i = 0;  // i is created inside of the braces, meaning it won't exist after the loop.

        while (i < 5)   // The second part of the for loop goes inside this parens
        {
            // Code inside the loop goes here:
            cout << i << endl;

            // The third part of the for loop goes at the end like this:
            i++;
        }
    }

    // You can do some really goofy stuff inside the for loop paramters, but usually it just looks like the first one I did above.


    cin.get();


    // break and continue are used primarily with loops (all 3 kinds).
    // yes, you can also use break with switch, but it's slightly different here.
    cout << "break and continue" << endl;

    int a = 2;
    while (true)    // I can have a while loop that never ends like this.
    {
        a = a * a;
        if (a > 100)
            break;      // A break statement will immediately end the loop, regardless of the condition, and stop executing any later code.

        // Anything down here won't happen once break happens.
        // This is useful when you need to loop until you find what you are looking for.
        // Once you find it, there's no reason to keep looping, so you can end early.
    }

    // Continue has a similar usage:
    int b = 0;
    int numbersDivisibleBy9 = 0;
    int numbersDivisibleBy3 = 0;

    while (b < 100)
    {
        b += 1; // Increment b by 1.

        if (b % 9 == 0) // % is the modulus operator, (it gets the remainder of x when divided by the second number)
        {               // In this case, it is 0 if the number is divisible by 3.
            numbersDivisibleBy9++;
            numbersDivisibleBy3++;
            continue;   // continue will immediately end this iteration of the loop, but doesn't end the loop entirely like break does.
        }               // This is useful if want to go through the whole loop, but don't want to do the thing afterwards.

        // In this case, we already know a number is divisible by 3 if it's divisible by 9, so we can skip this step.
        if (b % 3 == 0)
        {
            numbersDivisibleBy3++;
        }
    }
    cout << "numbers betwen 0 and 100 divisible by 9: " << numbersDivisibleBy9 << endl;
    cout << "numbers betwen 0 and 100 divisible by 3: " << numbersDivisibleBy3 << endl;
    


    // That's all for this example. Thanks for reading!


    cin.get();
    return 0;   // End Program.
}