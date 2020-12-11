# math-tools
Some helpful tools we have developed for a discrete mathematics course.

## Tools
* Bezout
* Multiplikasjonstabell
* N-times permuntation
* Permutation
* Redusibelt Polynom

## Usage
###### Bezout
```
./bezout <num1> <num2>
```

###### Multiplikasjonstabell
```
./multiplikasjonstabell <integer>
```

###### N-times permuntation
```
./permutation <permutation> <n-times>
```

###### Permuntation
```
./perm <matrix1> <matrix2> ... <matrixK>
./perm s3
./perm d6
./perm d8
./perm d10
```

###### Redusibelt Polynom
```
Edit the source file and change the default polynomial and prime.
```

## Examples
###### Bezout
```
./bezout 43 32
GCD:  1
Bezuouts Coefficients:  3, -4
```

###### Multiplikasjonstabell
```
./multiplikasjonstabell 6
Addisjonstabell:
*  |  0  1  2  3  4  5
----------------------
0  |  0  1  2  3  4  5
1  |  1  2  3  4  5  0
2  |  2  3  4  5  0  1
3  |  3  4  5  0  1  2
4  |  4  5  0  1  2  3
5  |  5  0  1  2  3  4



Multiplikasjonstabell:
*  |  0  1  2  3  4  5  
---------------------
0  |  0  0  0  0  0  0  
1  |  0  1  2  3  4  5  
2  |  0  2  4  0  2  4  
3  |  0  3  0  3  0  3  
4  |  0  4  2  0  4  2  
5  |  0  5  4  3  2  1  

Idealer: {Z/0, Z/2, Z/3, Z/4}
```

###### N-times permuntation
```
./permutation 1342 4
1: 1342
2: 1423
3: 1234
4: 1342
```

###### Permuntation
```
./perm 1234 4321
s0 (1,2,3,4)
s1 (4,3,2,1)

 * | s0 s1 
---------
s0 | s0 s1 
s1 | s1 s0 


(*,*,*,*) | (1,2,3,4) (4,3,2,1) 
------------------------
(1,2,3,4) | (1,2,3,4) (4,3,2,1) 
(4,3,2,1) | (4,3,2,1) (1,2,3,4) 

```
```
./perm s3
s0 (1,2,3)
s1 (1,3,2)
s2 (2,1,3)
s3 (2,3,1)
s4 (3,2,1)
s5 (3,1,2)

 * | s0 s1 s2 s3 s4 s5 
---------------------
s0 | s0 s1 s2 s3 s4 s5 
s1 | s1 s0 s5 s4 s3 s2 
s2 | s2 s3 s0 s1 s5 s4 
s3 | s3 s2 s4 s5 s1 s0 
s4 | s4 s5 s3 s2 s0 s1 
s5 | s5 s4 s1 s0 s2 s3 


(*,*,*) | (1,2,3) (1,3,2) (2,1,3) (2,3,1) (3,2,1) (3,1,2) 
--------------------------------------------------------
(1,2,3) | (1,2,3) (1,3,2) (2,1,3) (2,3,1) (3,2,1) (3,1,2) 
(1,3,2) | (1,3,2) (1,2,3) (3,1,2) (3,2,1) (2,3,1) (2,1,3) 
(2,1,3) | (2,1,3) (2,3,1) (1,2,3) (1,3,2) (3,1,2) (3,2,1) 
(2,3,1) | (2,3,1) (2,1,3) (3,2,1) (3,1,2) (1,3,2) (1,2,3) 
(3,2,1) | (3,2,1) (3,1,2) (2,3,1) (2,1,3) (1,2,3) (1,3,2) 
(3,1,2) | (3,1,2) (3,2,1) (1,3,2) (1,2,3) (2,1,3) (2,3,1) 

```
