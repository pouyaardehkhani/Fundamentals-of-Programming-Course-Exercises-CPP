# question
**Sub-string** "Consecutive" characters from the string whose beginning and end can be anywhere in the string, and the order of the characters is exactly the same as the order in the main string. Write a program that first receives a word in the form of a string from the user, then receives the number n and receives a string in the number n, if in each of the string lines, the word is entered or vice versa from In terms of letter layout and uppercase, there was lowercase, line number and character start of the word to be printed. If "Substring not found" is not found in any line, print the phrase "Substring not found". For example, if the word CEut99 is entered, check the words CEut99, ceUT99, 99tuEC, and 99TUec.

**The priority of checking in each line is that, first the word itself (for example aB), then inverted in terms of uppercase (Ab) then inverted in order (Ba) then inverted in order and uppercase () bA) be printed**
# input
The first line of a string, which is then checked for its sub-string, the second line of the natural number n, which is received as the number of that string
And then n string lines
# output
The output of your program must contain n lines if the primary string or its inverted sub-string is one of the lines, and in each line number and character number that the primary string is under the string, otherwise "Substring not found".
# example:

## Sample input 1:
```
CEut99
3
fsdfceUT99fsdk99tuEC fdsf
mfsdias99TUecosd fksC
dceUT99dsmkCEut99
```
## Sample output 1:
```
1 5
1 15
2 8
3 12
3 2
```
