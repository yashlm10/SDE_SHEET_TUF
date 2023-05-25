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
## problem 7 rotate matrix clockwise
### given a matrix rotate it by 90 deg cloclwise
#### solution == mysol tc =n*n sc=1.
1. naive approach would have been making another array and printing directly the last row to first column and so on.
2. optimised approach is basically taking transpose of the matrix and reversing each row == taking mirrir image of matrix.
3. to transpose, for every j>i swap i|j with j|i, remember not to swap for all j.
4. reverse each row in the next loop to get the required matrix.
---
## problem 8 merge overlapping intervals
### given an array of mixed intervals, merge the overlapping intervals to return an array with minimum number of intervals.
#### solution tc = nlogn + n, sc = n;
1. firstly sort the given array to group the closer intervals together (nlogn time).
2. create another 2d array ans.
3. run a loop for number of intervals in the given array.
4. now if the ans array is empty or the pointer intervals first element is greater than second element of ans array last element.
5. this means there is no overlapping so push the interval in the ans array.
6. otherwise if there is overlapping, modify the 2nd element of last interval of answer array to be the maximum of (intervals[i][1]/ans.back()[1]).
7. come out of the loop and return the ans array.
---
## problem 9 merge sorted arrays
### given two sorted arrays merge them and return two arrays such that sorted merged array is printed as those two arrays.
#### naive approach with extra space n+m. tc = (n+m)*2, sc = n+m.
1. traverse both arrays simultaneously starting from first element each.
2. compare corresponding elements and add the smaller one to another array and shift that arrays pointer to the next element.
3. after smaller array ends, add rest elements to third array.
4. divide 3rd array in two arrays and return.
#### optimal sol 1 tc = min(n,m) + nlogn + mlogm, sc = 1.
1. make two pointers left = last element of first arr and right = first element of 2nd arr.
2. for every iteration till one of the arrs end, compare the two elements.
3. if left is greater, swap it. if left is smaller or equal, stop the iterations.
4. now we will have all small and larger elements stored in respective arrays.
5. sort both arrays and return.
#### optimal sol 2, gap method using shell sorting. tc = (n+m)log(n+m), sc = 1.
1. calculate the gap by the formula ceil(length/2), length = n+m.
2. now initialise two pointers left = 0 and right = gap + left.
3. think of a hypothetical third array made by merging two arrays given.
4. now iterate through this array with pointers, and compare the two elements, if left is > right then swap them.
5. in each iteration increase both pointers by one and keep iterating till right = length.
6. then edit gap to be ceil(gap/2) and repeat the process till gap = 0 and then return two arrays.
7. while implementing code, we will have 3 situations, both pointers in diff arrays, in first array, in second array.
8. carefully edit value of pointers to make sure you are operating in the correct array.
---
## problem 10 find the duplicate element 
### find the duplicate element in a given array of n+1 size where all elements are from 1 to n range.
#### naive sol tc= nlogn+n sc=1
1. sort the array and iterate through the loop to find duplicate.
#### solution using hasing/frequency array tc = n, sc = n (extra space)
1. create a frequency array of same size and initialize all elements to zero.
2. run a loop iterating through the given array, every element of the given array points to an index in the freq array.
3. change the value of the pointed index to 1 for every iteration on the given array.
4. if at any iteration, the pointed index in frquency array is already edited to 1, then retuen that index as the duplicate element.
#### using hare and tortoise method / circular linked list method. tc = n, sc= 1.
1. we create a path starting from the first index(0) and the next element being the value at the index pointed to by the value of the current index
2. so on we create a path and since there exists a duplicate element, a cycle would be formed at some point.
3. now usinf the hare tortoise method, we initialise a slow and a fast pointer at the 0th index.
4. now the slow pointer will move one step while the fast pointer moves two steps.
5. since at every point distance travelled by slow is half of that travelled by fast, they are bound to meet on the cycle.
6. once they meet at the first time, edit fast to be the first element on the path and move both pointers one step.
7. the pointers will meet at the duplicate element.
8. once they meet for the first time, fast is sent to start, so fast will cover that distance slow covered before entering the loop.
9. while slow travels the same distance in the loop, so they are bound to meet at the duplicate element where the loop starts.
10. to prove, let distance from first element to first collision point be a, distance till duplicate element be x.
11. so distance inside loop fro dup element to first collision point is a-x, so distance from first collision to dup to the other side of loop is x
12. while implementing code, initialise slow and fast pointers to be value of first element.
13. now move slow by one step by slow = arr[slow], and fast by two steps by fast = arr[arr[fast]].
---
# problem 11 find repeating and missing digit
## in an array of n intergers from 1 to n, find the repeating and missing digit.
#### hashing method tc =2n sc = n(extra space)
1. make a frequency array and store freq of each element.
2. iterate freq array and return the indices with freq 2 and 0.
#### using mathematical equations tc = n, sc = 1.
1. make 2 eq 2 variables and solve them to obtain the values.
2. eq 1 => repeat - missing = sum of array elements - sum of elements till n
3. eq 2 => repeat^2 - missing^2 = sum of squares of elements of given array - sum of squares of numbers till n.
#### there is a third approach using XOR with similar tc and constant sc.
1. go through https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
---
## problem 12 count inversions
### given an array, count number of inversion pairs--> for i<j arr[i] > arr[j].
#### bruteforce run 2  loops and check n^2 tc.
#### using merge sort with tc = n*logn.
1. while doing merge sort count number of inversions while merging the divided pieces of array.
2. to divide use recursion by editing mid to left+right/2 and (left to mid)/ mid+1 to right.
3. while merging, compare left and right elements if there is a need to swap increase inv_count by mid-left.
4. basically pls practise merge sort code.
---
## problem 13 search in 2D matrix
### given a 2D matrix and a target element, find if it is present in the matrix or not.
#### linear search n+m complexity
1. iterate through first column, to find the element which is less than taregt and next element greater than target.
2. iterate through the found row or return false if no such row exists.
3. linear search in the row to find/ not find the target.
#### binary search log(n*m) complexity
1. we will treat the matrix as a single array sorted in non-dec fashion and create a low=0 and a high=n*m-1 pointer.
2. return false for the case in which matrix is empty.
3. create a loop to run while low <= high and in every iteration initialise pointer mid = (low+high)/2;
4. to access the element pointed by mid, row = mid/m, column = mid%m where m is number of columns.
5. now if mid element is == target return true, if less than target low = mid + 1, if greater high = mid-1.
6. if we make it out of the loop that means left>right so we return false.
---
## problem 14 find power of double 
## given a double x and long long n find x raised to the power n. 
#### cant solve by brute force as n is very large.
#### solve using BINARY EXPONENTATION tc = logn.
1. in binary expo. we keep dividing the power by 2 till power is 0, so log n times we compute x*x.
2. create a long long variable initialised to n and a double initialised to x.
3. for negative n convert it to positive.
4. for power = odd, subtract power by 1 and multiply answer by x. note for atleast once power would be odd.
5. if power is even, edit x to x*x(raising to power 2) and divide power by 2.
6. for the case in which power is negative, divide answer by 1: ans = (double)(1.0)/(double)(ans); return answer.
---
## problem 15 find element > n/2
### given an array find the element which occurs more than n/2 times.
#### n^2 complexity naive solution to run loop for every element.
#### solution using hash map. tc = nlogn + n, sc = n.
1. create a map and for iteration i 0 to n, do map[v[i]]++.
2. this assign the key to be v[i] and every time it occurs, the value increases by 1, hence creating a hashmap.
3. again for auto it: map iterate through the map and for it.second > n/2, return that it.second  
4. if in the question it is not mentioned that there is necessarily a majority element, the run another loop to check.
5. inserting in map requires logn time, since n insertions nlogn. if we have to check existence then another n time added.
#### MOORE'S VOTING ALGORITHM
1. we initialise a count variable = 1, element = v[0].
2. now we iterate through the array, if the current element == element the increase count.
3. if not equal, then check if count is zero, if not then decrese count and move to next itertion.
4. if count is 0 for curr_ele != element then edit element = v[i], and increase count by 1.
5. the intution is, the non majority element cancle out their count, and the count for majo element persists.
6. ie count at the end would be the no of times majo element is more than non majo elements.
---
## problem 16 find element occuring > n/3.
### given an array, find elemmts occuring more than n/3 times,return empty array if not.
#### observation.
1. the max no. of elements can be 2, more than that is not possible. proof by contradiction.
#### sol by hash map tc = nlogn, sc = n.
1. same like last problem just push the checked element in an array and return it.
#### Extended Boyer Moore's Voting Algorith
1. same logic of cancellation as before, this time we use two counters and independently move them.
2. init two counters to 0 and elements1 and 2 to int_min.
3. iterate through the given array, if counter is zero and another counter element is not equal to curr_ele
   then increase counter and assign counter's element to current element.
4. if curr_ele is equal to any of the elements, then increase its counter.
5. for all other cases, decrease BOTH counters by one.
6. now, for the two obtained elements, run a loop to check its frequency.
7. push the checked element in an array and return.
---
## problem 17 unique grid paths.
### given number of rows and columns of a grid find number of uniques paths from top left to bottom right if you can only move down or right
#### exponential time complexity and space compleity recursion solution.
1. using recursion we will travel all paths and check for each of them.
2. for any [i][j] position if we exceed number of rows/columns we return zero.
3. if we reach bottom right we return 1 or else run program again with i+1,j and i,j+1 till we hit base cases.
4. for i=0,j=0 we will run the recursive function and return our answer.
#### dynamic programming solution, tc = m*n, sc = m*n.
1. priciple of dp is we wont resolve the sub problems we already have visited, rather just return its answer on checking.
2. we will create a matrix with m+1 row ans n+1 columns and initialise all values to -1.
3. now keeping everything else same as previous solution, we will check if matrix cell value is alrady -1.
4. if not then we will take rhe result strored in that cell.
5. if it is -1 this means it hasnt been visited so we compute a recursive function for it last solution when we returned this value.
6. now we return dp[0][0], if m==n==1, we return the value on computing nd not dp[0][0] bcuz it is an edge case.
#### most optimal solution is using combinatorics tc = n-1 or m-1 sc =1.
1. if we observe everytime we need only m+n-2 number of steps to reach the target.
2. so we choose any n-1 rows or m-1 columns (both being same).
3. so we compute m+n-2Cn-1 by the method used in pascals triangle problem.
---
## problem 18 Reverse pairs count
### given an array find the number of reverse pais such that for i<j arr[i] > 2*arr[j].
#### brute force solution n*n tc sc = 1.
1. run 2 nested loops to check.
#### using merge sort tc  = nlogn + n + n. sc = n.
1. write merge sort codes it is just add the following function.
2. in this function before merging we check if arr[i] > 2*arr[j] and increase counter.
3. consider two sorted arrays left and right.
4. if in the right first element forms a reverse pair with an element of left then in the next iteration we need not check this right element for next element of left as it would naturally form a reverse pair since both arrays are sorted. using this logic we write the code.
5. we run a loop for i= low to i = mid, and initialise a pointer j = mid+1.
6. now for every i we check if j<=high and arr[i]>2*arr[j] if yes we increase j by one and keep checking.
7. if j comes out of the loop we add to the counter j-(mid+1) since we initialised j to mid+1.
8. notice we are not initialising j again and again as using logic 4 we need not check smaller checked elements again. 
9. practise merge sort algo again.
10. keep in mind the use of long long since there might be an over flow, the syntax used to convert int to long long in this case is 
arr[i] > 2*(long long)arr[j] **remember use of spaces errorifies the syntax**
---