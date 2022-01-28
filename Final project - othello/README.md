first, you can play othello in [here](https://www.eothello.com/) to understand the logics of the games.

The playing field is 8 * 8, we show the white bead with W and the black bead with B! At the beginning of the game, two white pieces and two black pieces are crossed in the middle of the screen! Sample image of the table:

![board](Fundamentals-of-Programming-Course-Exercises-CPP/End of the semester project - othello/saved_image.png)

First it is the black player's turn!

Places that each player can choose must meet these two conditions:

There should be a bead of the same color as the row, column or diameter
The distance between these two beads should be filled only by the opposite beads
If no such house is found, it is the turn of the next player

By placing this bead, all the opposing cells between these two beads become the same color as these two beads

The end of the game is when there is no house left to choose from

Score section

Ability to save and load the game

Save the game statement with the name key and retrieve the game load name statement with the name key
Implement artificial intelligence to play with the computer