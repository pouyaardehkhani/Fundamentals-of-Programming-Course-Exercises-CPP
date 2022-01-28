# question
In the final of the xo college competitions, the judges of the competition asked you for help. They want to play several games to determine the champion of the tournament in the final due to the sensitivity of the game instead of just one game, and they ask you to determine the champion of the game by taking the tables.
# input
The input consists of a line containing the natural number n and then in 3n lines the competition tables.

Do not worry about empty spaces, they are filled with '' characters.
# output
The output of your program must consist of 2 lines, the first line of which is the number of X player wins, the number of draws and the number of O player wins in the format mentioned below. In the second line, the hero character is printed:
```
printf("X: %d - Ties: %d - O: %d\nChamp: %c", 
       score_X, Ties, score_O, champ);
```
In case of a tie, print N.
# example:

## Sample input 1:
```
1
X O
OX 
XOX
```
## Sample output 1:
```
X: 1 - Ties: 0 - O: 0
Champ: X
```
## Sample input 2:
```
2
O X
 OX
O X
OXO
OOX
XOX
```
## Sample output 2:
```
X: 1 - Ties: 1 - O: 0
Champ: X
```