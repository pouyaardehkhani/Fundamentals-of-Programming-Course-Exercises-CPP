# question
Prime numbers are numbers that have only two counters. Some of the prime numbers: 3, 19, 101 In the sequence of prime numbers, sometimes a pair of consecutive prime numbers have a distance of 2, such as 3, 5 or 17 and 19. This pair of prime numbers are called golden pairs.

In the world of cyber security, prime numbers are very useful. The security team of Tehran School of Chemistry has noticed a security problem in their systems. For this purpose, it needs a series of new prime numbers to increase its security. You are asked to find the last golden pair between the numbers 2 and n and display it.

If n and n-2 were prime, count the answers.

In other words, show between all the golden directions (x, x + 2) the pair whose sum of two numbers is greater than the other pairs.

(**Note: You must use the function to solve the question, even if the code without your function gets a full score after reviewing your score will decrease**)
# input
The input contains only one line containing a natural number n.
# output
The output of your program should contain 2 numbers that are in a line. They are x and x + 2, which is the last golden pair between 2 and n. (First print a smaller number.)

If you do not find any gold pairs, print -1 -1.
# example:

## Sample input 1:
```
29
```
## Sample output 1:
```
17 19
```
## Sample input 2:
```
4
```
## Sample output 2:
```
-1 -1
```