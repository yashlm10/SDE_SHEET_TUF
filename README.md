# SDE_SHEET_TUF
SDE SHEET TUF  problem solution and concepts
---
## problem 1 set matrix zeros
### for any cell in the matrix marked 0, mark the entire corresponding row n column 0
#### first approach with 2*n*m tc and n space complexity
1. create two arrays and initilise all values to be 0
2. traverse the matrix and for all zero cells mark that index in th two arrays as 1.
3. traverse the matrix again and for all marked index either row or col array, if vale is not already zero mark it zero.
#### second optimal approach with same tc but constant space complexity
1. traverse the matrix and mark the row column to be zero if that row has a zero
2. similarly make a column arrow with a variable col0 initialised to 1 and mark it while traversing if m[i][j]==0 for j==0, col0=0 else m[0][j] = 0
3. traverse the matrix gain but from second row and second column, mark cell zero if either the row or column array is marked.
4. now first check m[0][0] if zero then make the first row all zero.
5. now check if col0=0 make the entire first column =0.
---
## problem 2 pascal's triangle
### given the row and column print the value at that position
1. notice all the values are combination of rows to columns(nCr).
2. rather than using factorial method to calculate nCr, we use the observation nCr = n*(n-1)..*(n-r-1)/1*2*3*...*r.
3. on further observation nCr *= (n-i/i+1){for i = 0 to i = r-1};
4. so bcuz of zero indexing reduce row and column by one and calculate nCr as above tc = n.
### given the row number print the row
1. either for each element caluclate nCr but tc = n*n, so better approach.
2. notice for each row every next element is multiplied by (n-i/i) till the last element.
3. so start by taking first element = 1 and run a loop from i=1 to i=row number-1 and keep pushing the elements into row vector.tc =n.
### given a number, print pascals triangle upto that number of rows
1. for every row, determine the row as mentioned in prev question and by running a loop for number of rows, keeppushing the rows in 2d vector
2. hence you get the vector in n*n tc.
#### my solution with similar time complexity
1. run nested loops for every row iteration create a row vector and push these elements for every column.
2. element is row[j] = v[i-1][j] + v[i-1][j-1]; i.e element is equal to sum of two elements above it. tc = n*n.
---
## problem 3 next permutation
### given an array of elements find lexicographically next arrangement; if it is the last permutation print first.
#### using c++ STL lib function.
1. pass the given vector to a function.
2. use STL next_permutation(v.begin,v.end) and return the vector.
#### implmenting the code
1. traverse the vector from the end to find the breakpoint.
2. breakpoint index is the one where the next index in reverse traversal is smaller than previous for the first time.
3. now again travere the vector from behind and swap the breakpoint index value with the first value greater than itself.
4. now reverse the vector starting from the element after breakpoint element to the end and returm it.
5. we reverse because it is equivalent to sorting the remaining array. tc = 3*n space complexity is contant.
6. initialise the breakpoint index as -1 and if after first reverse traversal it is still -1 then reverse the entire array and return it.
---
## problem 4 Kadane's algorithm
### given an array, return the largest possible sum of a contiguous subarray (print the subarray)
#### using my solution which is efficient but cannot print the subarray
1. traverse the array simultaneously from front and end but i = 0 to i<n/2.
2. if the element is +ve and its sum with the next element is positive, add it to the next element.
3. similar for reverse iteration do the same.
4. return v[n/2] will give the answer as it stores the max sum possible.
5. if v[n/2] is negative that means we have an empty array as answer so print 0.
#### using kadane's algorithm tc = n, sc = 1. we will print the subarray as well.
1. initialise a maxi variable set to int_min, sum = 0, start =-1, ansstart=-1 ans ansend = -1.
2. traverse the array and add each element to the sum.
3. if the sum is greater than maxi then edit value of maxi to be that of sum.
4. but is sum is -ve, theres no point in carrying it so we change it to zero.
5. return maxi to get the maximum sum.
6. at the beginning of every loop iteration check if sum =0 then start = i.
7. everytime maxi value edits to that of sum, we get ansstart = start(when sum was 0), ansend = i(when sum maxed).
8. use these two indices to print the maximum subarray.
9. if maxi is less than then our max array is empty array print 0.
---
## problem 5 sort array of 0 1 2.
### sort a given array of 0 , 1 and 2 as elements
#### simple solution
1. either use sorting algos like merge sort but will have high tc.
2. initialise counters for 0 1 and 2, and print accordingly, but tc = 2*n.
#### dutch national flag algorithm
1. consider 4 parts of the array.
2. all elemnts 0 from 0 to low-1
3. all elements 1 from low to mid-1.
4. all elements 2 from high+1 to n-1.
5. rest of the elements between mid to high unsorted.
6. for v[mid] = 0, swap v[mid] and v[low] and low++ mid++.
7. for v[mid] = 1, just mid++.
8. for v[mid] = 2, swap v[mid] and v[high] and high--.
9. stop the iteration when mid>high and return the array with tc = n.
---
## problem 6 stock buy sell
### given aray of prices of stock, determine max profit if brought on someday and sold on a later date.
#### my sol with tc = n.
1. initialise buy and sell variables to day 0, and profit = buy - sell.
2. iterate the array from i=1 to n-1.
3. if arr[i] >= buy , check if difference is greater than profit, if yes then update profit and update sell to be the current day.
4. if difference is not greater than zero check if we have arrived the last day if yes then there is no buy sell zero profit.
5. also if difference is not greater than zero update buy to be the current day that is the new min price.
6. return the profit.
---