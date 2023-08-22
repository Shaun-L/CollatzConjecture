# CollatzConjecture
This was a C++ Project in my System Programming class that explored the idea of recursion, operator overloading, and avoiding integer overload. 

The Collatz conjecture is one of the most famous unsolved problems in mathematics. The conjecture asks whether repeating two simple arithmetic operations will eventually transform every positive integer into 1. It concerns sequences of integers in which each term is obtained from the previous term as follows: if the previous term is even, the next term is one half of the previous term. If the previous term is odd, the next term is 3 times the previous term plus 1. The conjecture is that these sequences always reach 1, no matter which positive integer is chosen to start the sequence.

What is so special about this conjecture is that it will always eventually go down to 1, and there is no obvious patterns in how this happens. 

In this project, we represented the problem in C++ using recursion while observing the number of steps, number of even numbers, number of odd numbers, and the highest reached number. 

The special part about this project would be the use of the BigInt class which is what would be used to replace normal integers. The problem with only using integer values is that the integers would get capped at 2147483647. Using the BigInt class with an array of characters, we are able to store any number no matter how large the number is. This paired with operator overloading can enable us to measure what happens when the number gets higher than 2147483647.

