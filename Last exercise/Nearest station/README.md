# question
In this exercise, we intend to write a program that will suggest the nearest metro station(s) according to the user's location.
# input
The program first takes the number of metro stations in the city from the user, then the names and coordinates of the stations are entered in one line, respectively (the city is assumed to be a 100 by 100 page, and the coordinates are all arranged in pairs (x, y) are that x and y are natural numbers).

Finally the user enters his location.
# output
The station(s) closest to the user are displayed in alphabetical order with the correct component of their distance(s) from the output.

Important Note: Be sure to use struct to get the full score in implementation.
# example:

## Sample input 1:
```
3
Motahari 20,10
Tajrish 50,50
Enghelab 100,0
0,0
```
## Sample output 1:
```
The nearest station(s) to you:
Motahari at (20, 10)
about 22 meters away from you
```
## Sample input 2:
```
4
Rah_Ahan 0,0
Ghods 60,60
Vali_Asr 30,30
Fath 100,10
30,0
```
## Sample output 2:
```
The nearest station(s) to you:
Rah_Ahan at (0, 0)
Vali_Asr at (30, 30)
about 30 meters away from you
```
