# question
You are given an array like a of size n whose members are arithmetic numbers.

An array is acceptable in our view if the following relation holds for all members of the array such as a[i]:

```i mod 2 = a[i] mod 2```

That is, each a[i] with its corresponding index, ie i, has the same remainder on 2.

For example, the array [0,5,2,1] is an acceptable array but the array [2,4,6,7] is not acceptable, because we have for i = 1:

```1 mod 2! = 4 mod 2```

Now you have an array and you have to accept it. At each step you can remove both members of the array and swap them.

The goal is to get the minimum number of shifts to make the array acceptable.
# input
The first line contains the natural number n, which is the size of the array.

In the second line comes the members of the array. (a[i])
# output
The output is only one number, if possible, print at least the number of shifts in the output; otherwise, print -1 in the output.
# example:

## Sample input 1:
```
4
3 2 7 6
```
## Sample output 1:
```
2
```