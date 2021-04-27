# Inversion Pairs
## Description
In this homework, you are asked to count the number of inversion pairs in a sequence. 	Let A be a sequence of numbers. If i<j but A[i]>A[j], we call (i,j) an inversion pair.

```
For example, let A=[1 2 3 5 4]. Then (4,5) is an inversion pair; Similarly, suppose A= [5 4 3 2 1], we have 10 inversion pairs: (5,4), (5,3), (5,2), (5,1), (4,3), (4,2), (4,1), (3,2), (3,1), (2,1).
```


## Input
here are multiple test cases, and each test case begins with an integer n, indicating the number of elements in the sequence. After n, the next line includes the n distinct integers in the sequence. 
Please note: 

1. 1 <= n <= 1,000,000
2. The value of each number is within [1, 2^32-1]
3.  It is also possible that the number of inversion pairs exceeds 2^32-1 but an unsigned long long variable will work fine

## Output
For each input sequence, you need to output the number of inversion pairs.

## Example

### Input
```
5	
1 2 3 4 5
5
5 4 3 2 1

```

### Output
```
0
10

```