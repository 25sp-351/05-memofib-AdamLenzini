Tests:
1. Error Checking: No arguments
./memofib
Expected Output: "Please enter an input"

2. Error Checking: Two or more arguments
./memofib 2 2
Expected Output: "Too many inputs. Please enter ONE input"

3. Error Checking: Negative int entered
./memofib -1
Expected Output: "Please enter a number between 0 and 92"

4. Error Checking: Int greater than 92 entered
./memofib 93
Expected Output: "Please enter a number between 0 and 92"

5. Testing values that do not require recursion. Input: 0
./memofib 0
Expected Output:
Fibonacci(0) = 0

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(0) = 0

6. Testing values that do not require recursion. Input: 1
./memofib 1
Expected Output:
Fibonacci(1) = 1

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(1) = 1

7. Testing small values that do require recursion. Input: 2
./memofib 2
Fibonacci(2) = 1

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(2) = 1

8. Testing small values that do require recursion. Input: 3
./memofib 3
Fibonacci(3) = 2

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(3) = 2

9. Testing small values that do require recursion. Input: 8
./memofib 8
Fibonacci(8) = 21

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(8) = 21

10. Testing medium size values. Input: 20
./memofib 20
Fibonacci(20) = 6765

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(20) = 6765

11. Testing medium size values. Input: 45
./memofib 45
Fibonacci(45) = 1134903170

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(45) = 1134903170

12. Testing large values. Input: 70
./memofib 70
Fibonacci(70) = 190392490709135

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(70) = 190392490709135

13. Testing max input value. Input: 92
./memofib 92
Fibonacci(92) = 7540113804746346429

Replaying the same Fibonacci sequence to test memoization
Press enter to continue

Fibonacci(92) = 7540113804746346429