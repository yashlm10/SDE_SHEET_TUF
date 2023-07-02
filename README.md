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
## problem 19 two sum pairs
### given an array and a target, find indces of two numbers whose sum is equal to the target, if not return -1, indicea cant be same
#### brute force approach tc = n*n.
1. run two loops(nested) to search for such pairs
#### hashing using unordered map 
1. we add numbers in a map as key and its value as index.
2. before adding the number we check if its complement(target - num), exists in the map using .find() function.
3. if yes then we return the two indices else return -1,-1 if we come out of the loop.
4. time c = n, since searching,insertion and deletion in unordered map is constant complexity, sc =n.
5. in rare worst cases we get n*n tc as map takes n time to search, so we use map and tc = n*logn as in map search = logn.
#### using two-pointers
1. we first sort the array and then initialse left =0 and right =n-1 pointers.
2. now we compute sum of elements pointed by pointers.
3. if sum is == target we have our required indices, search for these indices in the original array before sorting.
4. if sum is < target, increase left pointer by 1 other wise decrease right pointer by 1.
5. keep checking till the base case condition left > right.
6. return the answer or -1 accordingly.
7. tc = n + logn*n sorting + searching (except the loop where we searched original indices)
8. it is reccomended to use previous method if we have to return the two indices as tc(&sc) will increase.
---
## problem 20 Four sum quadrets.
### given an array find all quadrets which sum up to be equal to a given target.
#### use 4 loops n^4 tc solution.
#### using hashing (n^3)*(logm) sc = 2*number of quads + n(use of set) *tc is high*
1. we fix two indices and use hasing to find other two as in the previous sol.
2. we run two loops to fix first two indices and like last we use hashset to find and store values.
3. while calc. sum we initialise sum = first two fixed numbers sum, then in next step we add next elements value so that in every loop we can add a diff value. as in prev. sol we then insert the checked element to the hashset and continue checking (unlike last sol).
4. we add our quadret to a temporary array then sort it and insert it into the answer set.
#### using two pointer method tc = n^3 sc = no of quads === const.
1. we fix first two indices and then use two pointer method as prev. sol.
2. *first of all dont forget to sort the given array which is a common mistake*
3. Now run first loop for first index and check for duplicates if it is not first element and equal to prev element,increment it to next element.
4. similarly run another loop for 2nd index and check for duplicates.
5. now we use 2-ptr method, by initilizing left = j+1 and right =n-1.
6. run loop while left < right, initialise sum = arr[i] and add the other 3 indices separately so that in every iteration we can add diff values.
7. now if sum< target increment left else decrement right, if equal then make a temp vector with values being the 4 quads and push in answer vector
8. now we have to check for duplicates, after pushing in the answer,intialise two pointers equal to left and right,run two separate while loops and check for left < right if arr[left]==arr[temp1] (same with right), increment or decrement accordingly if true.
9. on coming out of the loops, return the answer vector.
---
## problem 21 Longest consecutive sequence 
### given an unsorted array find the longest possible sequence of numbers in the array
#### basic approach n*logn = tc constant sc.
1. before starting we check for n=0 casse then first we sort the array and then run a loop to check for max sequence.
2. run two counters answer=1 and currentsequence=1, at the end of every iteration checking, edit answer  = max of answer/currentsequence
#### using hashing tc = n and sc =n.
1. first we add all numbers of the array in a hashset by using for(int num: nums) loop and .insert() function of set.
2. now we again run the loop and check if the pointed current element is the first in the sequence (i.e its -1 not present in hset).
3. if yes then we make our counter =1 and current element equal to the iterated element.
4. then we keep checking till +1 of current element is present and keep increasing counter and current element.
5. on coming out of the loop we edit value of answer counter = max of answer and currentcounter.
6. return the answer.
---
## problem 22 longest subarray with zero sum.
### given an array of integers find the longest subarray(subarray is always of consecutive elements) whose sum is zero.
#### brute force tc = n^2, sc =1.
1. run two nested loops and check sum for each sub array.
2. return the longest length of subarray if sum is zero.
#### using unordered map tc = n, sc =n.
1. we will check prefix sum of every element, the logic is, if sum of subarray is zero, the prefeix sum would be same for boundary elements of the subarray.
2. so we use unordered map to use numbers as key and their indices as value.
3. if PS =0, then max is max of prev value and i+1, else we will check in the map for the same PS.
4. if we find one, we edit max to be max of prev value and i - map[sum]. note that we dont add this to map as we need max length.
5. if we dont find the PS in map we add it to the map with its index as value.
6. worst case sc =n if we have to add all elements to the map.
---
## problem 23 count subarrays with XOR k.
### given an array count number of subarrays with XOR equal to the given target.
#### naive approach tc = n^2 sc =1.
1. run two loops to check every sub array.
2. in every iteration xor with previous value and check if equal to target.
3. if yes then increment the counter and after coming out of the loops return counter.
#### using unordered map tc = n = sc.
1. the logic is in using prefix xor and the fact that number of PXOR^k present in the map == number of req. sub arrays upto the current element.
2. lets assume a sub array upto current element with xor =k, and the PXOR = xr, and the rest of the subarray before required subarray =x.
3. so we have x^k=xr, if we xor by k on both sids we get x = xr^k. hence proved. so number of xr^k present before current element has to be equal to number of required subarrays before current element.
4. so in every iterartion we take the prefix XOR and increase the counter by number of xr^k present in map then add current PXOR to the map.
5. *IMPORTANT* in maps if value is not specified, it is by default set to 0 for any key.
6. before the loop we first set value of 0 to 1 (map[0]++). this is because, if suppose first element is a and a is required xor, so x = a^a = 0,
now if we dont set map[0] to one, the counter wont increase for this single element subarray which should not be the case. *important*
7. in every iteration we xor to the PXOR and initialise x and increase counter by map[x] if x is not present map[x] would be zero by default else the required frequency would be added.
8. at the end of iteration we increment the PXOR map value by 1, if it hase been added first time its value will become 1 and so on.
---
## problem 24 longest substring nonrepeating characters.
### given a string, find maximum substring in which no character is repeated.
#### using two loops and hash set tc = n^2,sc = n.
1. we use two loops to check in every substring and before entering any substring we declare a new hash set.
2. check for a duplicate character and if present edit length and break out of loop.
3. if j is last element of the arr, i.e there is no duplicate element then again edit the length.
4. also dont forget to return 0 for empty array.
#### using two pointers and hash set tc = 2n sc = n;
1. we use an unordered set and a left pointer = 0, first we return 0 for empty array.
2. we check for every iteration of right pointer from 0 t0 n , and keep adding right pointer element to the hset and edit length value to be max of prev value or right-length+1.
3. if there is a duplicate element, we keep erasing the left pointer and incrementing the left pointer till we dont find a duplicate element.
4. we edit length again and insert right, as we come out of the loop return the value of length.
#### using mapping and two pointers tc = n, sc =n
1. we create a vector and ititialise it with 256 -1 's since there can be 256 characters in a string.
2. we intialise two pointers left and right both 0.
3. now we run a loop for right pointer to go 0 to n, and in every iteration we check if in the vector the index position is -1 if not, this means it is a duplicate element.
4. in that case shift left pointer to be either vector[s[r]]+1 (one ahead of last seen of duplicate element) or if last seen of duplicate element is out of l-r range then dont shift left.
5. irrespective of the checking, modify value of s[right] i.e vector[s[r]] = r
6. now edit length to be max of prev value or r-l+1, then increment right by one and after coming out of loop return length.
---
## problem 25 reverse linked list using iterative and recursive method.
### given a linked list and reference to its head, reverse it using iterative and recurrsive method and return the new head.
#### using 3 pointers. tc = n, sc = 1.
1. we use next to save the next node.
2. then we swap current next to be previous and previous tobe current node and then shift the curr to be the next node for the next iteration.
3. we will have aour successive iterations till we reach the last node and then return previous as it would be our new head.
#### using one pointer and one dummy node.
1. we create a null node first and then run a loop for till head is not null.
2. in every iteration we edit head->next to be dummy and then shift dummy and head one node ahead by making dummy=head and head to the next node.
3. as head reaches null we return dummy which is our new head.
#### using recursion.
1. firstly for the vase when head is null we return null.
2. 2nd base case is when head->next is null that is we reached the last node.
3. we recursively move to the last node and make it head.
4. then we travel backwards doing 5 4 3 2->1->null ny the commands head->next->next = head and head->next = null.
5. in the end we return new head.
---
## problem 26 find middle of linked list
### given a linked list and reference to its head, return the middle element of the list.
#### brute force approach n+n/2 tc.
1. iterate throught the list to the end and increase counter to find number of nodes.
2. divide count by 2 and iterate till midlle node and return it.
#### using hare tortoise method. tc = n.
1. logic is if hare reaches end, the tortoise will travel half that is to the middle element.
2. create 2 pointers and increment to next and next next repectively till the latter becomes null or last node.
3. return the slower pointer as the middle element.
---
## problem 27 merge two sorted linked lists.
### given two sorted non decreasing linked lists and references to their head, merge them and return head of resultant LL.
#### using extra linkedlist tc = n+m, sc = n+m(extra).
1. create a dummy null node and another temporary node initilaised to dummy node, we create dummy so that we can return dummy next as answer.
2. now while both lists are not null, check for the smaller node and set temp next to be that node temp->next = list1/list2 and move that list to the next node.
3. after every check move temp to the next element, that is the next in sequence. by temp = temp-next.
4. after either of the lists reach null, set next of temp to be the other list.
5. return dummy-next as your answer as it would be the head of the resultant list.
#### using inplace method without use of extra space tc = n+m, sc =1.
1. firstly check if either of the lists is empty, if yes then return the other list.
2. check if first list head is greater than second lists head, if yes then swap it so that we can create a new node answer to store head of the resultant list.
3. now run a loop till both lists are not null. and in every iteration we create a null node temp.
4. now run loop as long as list1 is not null and list1 value is lesser than list2 value and in every iteration edit temp to be list1 and move list1 ahead.
5. if we come out of loop, it means list1 value became greater, so make temp next to be list2 and then swap list1 and 2 to keep list 1 pointed at smaller element. 
6. so again in next iteartion we will create temp null and follow same steps.
7. return the answer node as head of resultant list.
---
## problem 28 remove nth element from end
### given a linked list and a reference to its head, and a position n from end, return head of the linked list after removing nth element from the end.
#### bt traversing the linked list twice.
1. traverse the linked list and maintain a counter to count total nodes.
2. now traverse again to the element before the element to be removed, and change temp-next to temp-next-next.
3. take care of the cases separately when head is null or n is total size of list
#### using two pointers.
1. create a null node start and initialise two pointers to be start. and let start-next be the head.
2. mow take the fast pointer to nth node, and then run a loop till fast is the last element of the list.
3. so logically at this point slow would be pointing to the element before the node to be removed.
4. edit slow-next to be slow-next-next and return start->next. dont return head as it is set to be the first element but the first element can itself be removed.
---
## problem 29 add two numbers represented as linked lists
### given two numbers represented as linked lists with digits in reverse order, return their sum stored in a linked list in a similar way.
#### using a carry and normally adding tc = max(n,m) sc = max(n,m).
1. initialise a carry to be zero and create a dummy null node as head of answer linked list.
2. run a loop till either of lists is non zero or carry in non-zero.
3. in every iteration, create a sum variable and store the sum in it adding elements from both lists and the carry.
4. edit carry to be sum%10 and add sum/10 to a new formed node.
5. add this node to our new linked list and carry on with the iterations.
6. return the head of answer array = dummy-next.
---
## problem 30 delete a given node from a linked list in tc=1.
### given a linked list and reference to the node to be deleted (delete it and return the list),head reference not given.
#### my sol not recommended
1. copy all elements to the previous one till the last node and then remove last node.
#### optimal O(1) solution.
1. copy value of next node to the intended node and then move pointer of current node to the node after the next node.
---
## problem 31 find intersection of two linked lists.
### given head reference of two linked lists return their intersecting node or return null if they dont intersect.
#### brute force method tc = n*m sc=1.
1. for every node of list 1 iterate over list 2 to check for intersection.
2. so we use nested loops and check for each node pair.
3. return null if we come out of loops.
#### using hashing  tc = n+m sc =n;
1. we create an unordered hash set and store first list nodes in it.
2. now iterate over 2nd list and check for intersecting node, if not present return null.
#### using difference in length of lists tc = 2*n + n-m + m, sc = 1.
1. iterate over both lists to find length of both,then for the longer list move to the next node diff number of times.
2. now iterate over both loops simultaneously and check for intersection, if not present return null.
#### optimal solution using two pointers tc = n+m sc=1.
1. for both pointers to match on intersecting node, they travel same distance n+m.
2. initialise both pointers to be heads of respective lists and simultaneously move them ahead.
3. once a pointer reaches null, move to head of other list and keep moving to the next node till both pointers reach common node.
4. if any pointer becomes null more than once, it means there is no intersection, return NULL. use a bool variable to check that.
---
## problem 32 detect cycle in linked list.
### given head reference to a linked list detect if there is a cycle present in it else return false.
### we have to write a cretae cycle function to actually form a cycle in the input end.
1. traverse to the intersecting and last element and point last element to intersection element.
#### my sol tc = n sc = 1. in this sol we are editing the listas well.
1. start iterating over the list and for every node check if itsvalye is INT_MIN id/not then edit its value to be INT_MIN.
2. if its value is already int_min then return true, if we reach end of the list, return false.
#### using hashing tc = n sc = n.
1. use unordered set to store nodes and check if already present for every node.
2. if found in hashset, return true else if we reach end return false.
#### hare tortoise method usinf slow and fast pointers tc = n, sc =1;
1. create slow and fast pointers to be head and run a loop till fast->next and fast->next->next are both not null.
2. this condition for loop is so that we dont iterate to a node that does not exist i.e after null.
3. in every iteration of loop we move slow by one step and fast by 2 steps.
4. if a cycle exists, slow and fast are bound to meet as proved earlier as well.
5. return false if we come out of the loops
---
## problem 33 reverse subgroups of linked list
### given head reference of a linked list and a number certainly less than or equal to its length, reverse the subgroups and return the ll.
#### solution using dummy node and three pointers tc = n sc = 1.
1. we first create a null node adummy, and point it to the head, then deternine the length of the linked list.
2. now we create three pointers prev initilaised to dummy mode and other two pointers cuu and nxt.
3. we will run a loop till length is greater thwn or equal to k and inside the loop we will iterate k-1 times in every iteration.
4. in the beginning or iteration we will set curr to be prev-next and next to be curr-next.
5. in the nested loop that runs k-1 times, we set curr-next= nxt-next , nxt-next = prev-next, prev-next=nxt and nxt = curr-next.
6. as we come out of this loop we will have our one supgroup reversed, we not edit prev = curr and at the start of next iteration we will have set curr to be prev-next and next to be curr-next.
7. after every iteration on one subgroup, decrease length by k.
8. return dummy-next as the head of modified linked list.
---
## problem 34 check if a linked list is palindrome or not
### given head reference of a liked list, check if it is palindrome or not.
#### uding extra space
1. create a vector and store all values of ll in the vector.
2. now check if the vector is palindrome or not and return answer.
3. check for cases when ll is null or contains one element.
#### optimal solution without using extra space
1. idea is to access the middle element of the list and reverse the part of the list after it, then iterate and check if it is a palindrome or not.
2. use slow and fast pointer method(slow by one step and fats by two step,return slow as fast reaches end) and now slow is the middle element.
3. now to reverse, create 3 pointers, prev = slow, curr = slow-next and nxt = curr-next.
4. now iterate till nxt becomes null and in every iteration do curr-next=nxt-next,nxt-next=prev-next,prev-next=nxt & nxt=curr-nxt.
5. once reversed, taverse one step from head and middle simultaneously, check if values are same return false if not.
6. dont forget to check for case when head is null and head next is null.
---
## problem 35 find the node in ll where loop starts.
### given head reference of a linked list find the node at which the loop starts, return -1 if no loop exists.
#### using hash set tc=n=sc.
1. create a set and iterate over list, if node not present add it,if present return it.
#### using hare-tortoise method tc=n,sc=1.
1. use the same hare tortoise method as already explained in prob 10 and check for cases when head is null or head next is null.
---
## problem 36 Flatten a linked list with next and bottom pointers.
### given root reference of a ll in which elements have either next or bottom or both pointers, return a flattened ll with only bottom ptrs.
#### using recursion and merge of merge sort algorithm tc = n sc = 1.
1. first up since there are two possible pointers a node can point at, the input taking process becomes interesting.
2. we have to first take number of elements in ever bottom list and store it in an array for easier individual access.
3. now we first create the horizontol list and then by iterating over it and using the array we take input for vertical lists.
4. now that we have input the linked list we call the flatten function to create a one sorted vertical list.
5. in the flatten function, the idea is to start from the last vertical list and merge it with second last and the resutant to the list beofore it and so on till we have one vertical sorted list.
6. to get access to the last list, we recursively traverse to the second last list by the nase case that returns head if it is null or last node.
7. we then pass the current list and the list after to the merge function which returns one list, which we pass again to the flatten function(recursive) which then merges it with the list before it.
8. the merge function is the one we use in merge function of merge sort algorithm.
7. keep adding the smaller pointed node to a new formed ll (by pointing it to the smaller node) and move to the next node of that list and so on.
8. finally return the merged list and pass it to the recursive flatten function.
---
## problem 37 rotate linked list by a given no of times to right.
### given head reference of a ll and a number k, rotate ll to right by k no of times, rotate right means shifting all digits one place right and last to first.
#### brute force no recommended, for all k run a loop and keep shifting last element to first tc=n*k
#### optimal sol === my sol, tc = n + n-(k%n).
1. for every n length ll, every n right shift returns the same linked list, so we have to shift only k%n times.
2. for that, iterate to the node before the node to be made head, make next node head and then point it to null, to make it the tail node.
3. also before that point last node to the original head node.
4, dont forget to add the case when head is empty or the last element.
---
## problem 38 clone a ll with next and a random pointer.
### given head reference of a linked list, clone it and form a different identical ll, if every node has a next and a random pointer pointing to any other node of the list.
#### using hashmap tc= n+n, sc=n.
1. create a hashmap and while traversing the given linked list, create another new linked list with same nodes pointing to same new nodes and in the map store for original ll node as key and corresponding node of new ll as its value.
2. now iterate again and for every node newtemp-random = map[temp-random] as map values are nodes of new ll they random will point to the intended node in the intended ll.
3. for the case when head is null return head.
#### optimal solution using multiple pointers tc = n+n sc=1.
1. traverse the original ll and point ever node to its corresponding new list node and point new list node to next node of original list.
2. this basically inserts new list nodes in between original list nodes.
3. now to set random pointers, since every original node is pointing to its corresponding new list node, simply set temp-next-random = temp-random-next. where temo next will give the new list corresponding node of the temp node then continue the iteration.
4. now we have the random pointers set so we have to seperate the two lists now, for that we use three pointers temp,itr and fast.
5. fast is to store original list next node, itr is to iterate over original list and temp is to iterate over bew list.
6. we first vreate a dummy node and set temp to be dummy and itr to be head.
7. now we start iterating and set fast to be itr-next-next, temp-next to be itr-next to set the next of new list node to the next new list node(in first iteration to point dummy to first new list node).
8. then we move itr-next to be fast to point original list node to next original list node.
9. move temp to temp next to move to next new list node (in the first iteration we go from dummty to first new list node) and then set itr to fast again to get set for next iteration.
10. finally we return dummy->next.
---
## problem 39 three sum 0 target
### given an array find triplets in the array taht sum up to be the target value i.e zero.
#### brute force using three loops to check all possible triplets.
#### using two pointer method as used in four sum problem tc = n^2, sc=3*no. of triplets.
1. first of all to use two pointer approach we need to sort the given array.
2. now we run a loop from first to 3rd last element in the array.
3. if current element is either 0th index or is not the duplicate of prev element we operate else continue with next iteration.
4. in every operation, we set low to be element just after iterating element and high to be last element and sum = target - iterating element.
5. now we run a loop while lo < hi and check if lo plus high is equal to sum , we push the triplet in our answer and as long as there are no duplicates we increment and decrement lo and high.
6. after that we incrememnt and dectrement lo and high, and if lo plus high is less than sum we increment lo if more than sum we decrement hi.
7. to check for duplicates is most important in this problem. return answer once out of loops.
---
## problem 40 trapping rainwater 
### given an array of positve integers represents the ground level values, determine the amount of water trapped in the ground.
### the prime logic of thi problem is to figure out that the amount of water trapped is basically for all elements min of leftmax and rightmax minus height at current index.
#### brute force calculating max on either side for both elements tc = n^2,sc=1. will give TLE not recommended.
1. create var leftmax and rightmax.
2. for every element traverse to left to find left max and traverse to right to find right max and return min of it - height at that element.
#### using prefix and suffix arrays to store left and right max for every element tc = 3*n, sc=2n.
1. apart from leftmax and rightmax variables, create two arrays of size n prefix and suffix.
2. for both arrays set first element to be the first and the last element repectively.
3. traverse right to store prefix values max(prefix[i-1],height[i]) and to left to store suffix values max(suffix[i+1], height[i]).
4. now traverse the array and for every element add to the answer min of prefix,suffix - height.
#### using two pointers tc = n, sc=1.
1. create two pointers left and right apart from leftmax and rightmax.
2. while left pointer is less than right we make our conditional iterations.
3. if left height is lesser than right we check if it is less than leftmax, if not then make leftmax to be that value else add leftmax - left pointed height to the answer and then move left pointer ahead.
4. do the smae in case right height is lesser, just that we mov in reverse direction.
5. we simultaneously keep editing leftmax and rightmax values in this approach and approax the max most height from both sides.
---
## problem 41 remove duplicates in place
### given a non-decreasing array, return k number of unique elements and edit those values to be first k elememts of array given.
#### using hashset tc = nlogn + n sincr set takes logn time for insertion, sc = n.
1. since a set data structure STORES UNIQUE VALUES ONLY, we create a set and add all elements to it.
2. we then copy all elements to our array and return size of set.
#### using two pointers tc = n, sc = 1.
1. we start with first pointer at 0 and second pointer one ahead of it.
2. we then check if both elements are same, if yes then we move second pointer forward.
3. if not then we move first pointer one step and copy value of second pointer to it.
4. these iterations go on till second pointer reaches end, after than we return index of first pointer+1.
---
## problem 42 count consecutive ones.
### given an array with only ones and zeroes find max number of consecutive ones.
#### using max and temp counters == my sol tc = n, sc=1.
1. create two counters max and temp and then iterate over the array.
2. if it is one increment temp else make temp 0 and edit max to be max of temp and max
3. return max.
---
## problem 43 number of meetings in one room.
### given 2 arrays with start and end times of n meetings, if there can be one one meeting at a time in the room find max number of meetings possible.
#### GREEDY ALGORITHM tc = n+ nlogn+n, sc= n.
1. in this problem, we use the logic that to accomodate maximum meetings we hav to choose meetings that end early first.
2. so we use a data structure to store 3 things, start time end time and meeting number(1-indexing) we use struct and give it three props, later in the fuction we initialise an array with this struct.
3. we first assign values to all the properties using the given arrays and then sort them in ascending order of end time using a comparator function.
4. the comparator function is of static bool type ( we use static because the sort fuction does not take non-static member), in the fuction we return true if end time of a meeting is less than the other and we return trues for the one with lesser pos in case end time is same.
5. after sorting, we now assign limit = our first meeting end time = meet[0] , and in answer vector we push the position.
6. now for all meetings starting from 2 we check if start time is > limit, if yes we edit limit to be that start time and push that position in our answer vector.
7. we return size of our answer vector as answer.
---
## problem 44 minimum platforms required for trains.
### given two arrays with arrival and departure time of n trains, find minimum number of platforms required for yhe arriving trains.
#### naive approach using nested loops to find ma overlapping intervals.
1. the idea is for every train the maximum overlapping intervals of other trains would be the min platforms required.
2. we run two loops and for every train check for all trains after it in the array.
3. for every iteration we maintain a count, if this condition is met arr[i]<=arr[j] && arr[j]<=dep[i] || arr[i]>=arr[j] && dep[j]>=arr[i], that means it is an overlapping interval so we increment the count.
4. after every iteration of inner loop we make ans = max of ans and current count. return ans counter for max overlaps.
#### optimal using sorting.
1. the idea is to sort both arrival times and dep times and then for every time check difference in arrived and not departed trains.
2. to check, we make two pointers i on arrival times and j on departure times and run a loop till i and j are less than n.
3. if arrival i is less than or equal to departure j, that means one more platform needed,so we increase counter,and move i to next arrival time.
4. else one platform can be removed, so we move j to next and decrease counter by one.
5. after every iteration we make ans = max of ans and counter, ie max platforms needed at any instance.
---
## problem 45 job sequencing 
### given the job id(job number),deadline and profit of n jobs, find max profits that can be gained if every job takes one unit time.
#### greedy algorithm using extra space. m = max deadline, tc = nlogn + n*m, sc = m.
1. we use struct data structure to store id,deadline and profit properties of every job.
2. we first sort the array in decreasing order of profits and then find the max deadline possible.
3. the idea is to try to do a job on the last day available of its deadline.
4. so we create an array of size = max deadline and set all values to -1.
5. now we run a loop across the array and in every iteration we check if in the new formed array that deadline number day is -1(available), if yes then we push that job in our answer vector else keep going one day back untill we find an available day or we reach the first day, then we movet to the next job in sequence and finally return the answer vector;
---
## problem 46 Fractional knapsack problem.
### given weight and value of n bags and total weight required, calculate maximum value that can be obtained.
#### greedy algorithm == mysol tc = nlogn + n, sc = 1;
1. idea is to pick those bags first which offer more value per unit weight.
2. so we sort the array in decreasing terms of value per unit weight.
3. now iterate through the array and keep adding bags untill a bag cannot be added in full quantity.
4. then calculate the fraction of the bag that can be added and that fraction of value to our answer, then BREAK OUT of the loop and return answer.
5. remember to convert int to doubl whereever necessary using (double in front of them.)
---
## problem 47 subset sums 
### given array and it's size, return an array of sums of all possible subsets.
#### using recursion tc = sc = 2^n.
1. the idea is to traverse the array and at every index make two choices, to take that index value or ignore, doing this we get all possible combinations of some indices ignored while others picked and those we will get the sum of a subset at every dead end(bas case).
2. thus to implemnt this logic we will use recursion, we first form a function and create an answer array and then pass a few parameters to another recursive function that does the major job for us here.
3. in the recursive function, we first put the base case to be when the index is equal to n, i.e we have already considered last element and the array has ended, so we add the sum to our array, note that this is the point where every subset ends be its sum 0 (when no element added) or maximum(when all eleents added)
4. in the function we call the recursive function twice(once when we add the current index, oncebwhen we dont).
5. the only difference is in the parameters of the function, in the case we pic the element, we add it to the sum in the parameter else we dont add anything to sum in the parameter.
6. in the end when the recursive function returns with answer array modified, we sort it and return the answer array.
---
## problem 48 unique subsets
### given an array print all possible unique subsets.
#### using recursion and a set data structure to store unique subsets.tc = 2^n * klogx sc = 2^n*k, klogx for insertion in set. k = avg length.
1. the logic is to use the "pick or do not pick algorithm", i.e for every element we either pick it or dont and make all possible combinations, and then store them all in a set after sorting.
2. since set stores only unique elements, duplicates would be automatically removed, then we copy the set to aur answer and return.
3. To implement the logic, we create vector of vectors answer array, an auxiliary ds vector, a set and pass these along with the original array and 0 index value to our recursive function, and once the function returns with the set filled, we copy from set to our required vector and return it.
4. in the recursive function, our base case would be when index is equal to n (size of array), in that case we sort our auxiliary vector ans insert it to our set ans return the void function.
5. in every recursive call we push curr index element to auxiliary vector and the again call the function with ind=ind+1, then pop back from the vector and again call the fuction with ind+ind+1.
6. in these 4 lines we basically first pick all, then as we start returning and coming back we keep getting all combinations in every back iteration(going above the tree once reached bottom), then again we go down once we come back to 1st recursive call.
#### without using set, so we save time of insertion and copying, tc = 2^n*k,sc=2^n*k k=avg length of subsets.(backtarcking)
1. backtracking is when we make all possible combinations and at every step check for the required condition and stop the calll whenever necessary.
2. so the logic is, we dont pick duplicates (except the first element after current index),to avoid getting duplicate subsets.
3. to implement, we first make answer vector and auxiliary vector ds and then sort original array to group all duplicates together.
4. then we call our recursive function by passing both our answer vector and ds and index 0.
5. in the recursive function, we first pushback ds in answer so that we keep inserting all unique subsets in start of every new call.
6. now we run a for loop from i=index to i < n, and inside the function we put the case of duplicates, if i!=ind(except the first element) && arr[i] != arr[i-1] if duplicate present we continue in the loop iteration thus avoiding the duplicates.
7. then we pushback arr[i] in ds and all the recursive function with ind = i+1 and then popback from ds.
8. the fuction first picks all elements till max subset is inserted, then comes up the tree and then the for loop comes into action and we get our different combinations.
9. in this way we coming up the tree, and by popping back we come to 1st recursive call and then from 2nd index again go down in the tree ans insert required unique subsets.
10. once the recursive function returns to the main function, return the answer vector.
---
## problem 49 combination sum 1
### given an array and a target number, find combinations from that array that sum up to equal the target, if every element can be used multiple times.
#### my sol, using for loop and recursion tc = 2^n*k = sc k = aveerage size of combinations.
1. we basically use the same pick not-pick algorithm.
2. in the main function we initialise our vectors and then in the recirsive function we put our base case and a for loop.
3. use the base case when target = 0 , push ds in answer vector and reset target to be original value ad return.
4. else if target is less than 0, simply return.
5. in for loop from i=inex to n, we push in ds then recall the function with target =target - arr[i] and then pop back.
6. these three lines along with for loop will form our combinantions.
#### sol without for loop same tc and sc.
1. same logic and same main fuction with different implementation of recursive function.
2. in the recursive function put base case when ind = size of array, in that check if target is = if yes then push in answer array, and return.
3. now we will pic element, for that if arr[ind] is less than target, use the three lines, push recall pop for our combinations with target =target-arr[ind].
4. lastly recall the function with ind=ind+1 to iterate over the array to pick elements.
---
## problem 50 unique combination sum
### same as previous problem but this time one element can be used once and unique combinations required.
1. same approach as previous problem and same implementation, this time we make two crucial changes.
2. in the for loop put the condition if i!=ind(to pick duplicate if it is first element) && num[i] == num[i-1] i.e there is duplicate lement we continue the iteration thus avoiding the duplicate element.
3. second change is, since we cant use an element more than once, in the for loop recall function we also do ind=ind+1 so that we move to the next element in array.
---
## problem 51 palindrome partitioning.
### given a string, return substrings such that each of them are palindromes.
#### using pick not pick and string.substr() function, tc = 2^n*k*n/2 sc = k*x.
1. the idea is to make partitions using pick not pick method and use a bool function to check for palindromes, and insert in ds if it is a palindrome.
2. firstly in the main function we initialize the vectors and then pass those to recursive function along with the string.
3. in the recursive function, first write the base case when index==size of string then push ds in answer vector.
4. in the bool function we pass 3 parameters, string start and end index, and we run a while loop till start<=end, if not palindrome we return false and increment and decrement start and end respectively in while loop.
5. in the recursive function we run our for loop for i=index to size of string, in the loop we first check if current substring is palindrome by passing s index=start and i=end to the bool function
6. if yes then, write the 3 lines push recall pop, we push substring using s.substr(), it takes two parameters, start position and length, so we pass ind and i-ind+1 as length.
7. we then recall the function with ind = ind +1.
---
## problem 52 Kth permutation sequence
### given n and k find kth permutation of sequence 1,2,3...n.
#### using recursion (brute force) tc = n!*n + n!logn! n! permutations and rest for sorting. sc = n.
1. create main function and initialise vectors and string and store from 1 to n in the string using for loop and i + '0' (It's a requirement of the language that any character set used to write C++ source has the digit characters 0 through 9 appear sequentially. So i + '0' converts the integer held in i into the character value that represents that number, as long as it's in the range 0 to 9. 1 becomes whatever value '1' is and so on.) and then call the fuction that returns all possible permutations in a vector of strings and sort it, then print the kth permutation by accessing k-1th element from vector.begin().
2. in the auxiliary function, we have passes the vector and the string along with indx =0, write base case of index=n, which pushes ds in answer and returns.
3. run for loop from i=index to n , in the loop swap s[i] and s[index] then recall function with ind =ind+1 then again swap s[i] and s[ind] these three lines wil give us all posible permutations of the sequence.
#### optimal approach without recursion tc = n^2 sc = n.
1. the idea is, to place the the correct digit on the current position starting from the first position, in first iteration we can have n possible digits, n-1 in next iteration n-2 in next and so on till all digits are placed.
2. if the permutation sequence is observed, every element is placed equal no of times on a position, so if we have n=4, we have from 0-5 1, 6-11 2 and so on.
3. so for implementation, we first compute n!/n i.e (n-1)! and add numbers from 1 to n in a vector of ints.
4. since we are using 0 based indexing we reduce k ny one, now we create an empty string.
5. now run a while loop that runs forever (ofc if not broken out), and to the string the stringified version of nums[k/fact] (by to_string function) and then erase that from nums using nums.erase(nums.begin() + k/fact).
6. if nums is empty break out of loop else edit k to be k%fact and fact to be fact/nums.size().
7. return the string as answer once out of loop.
---
## problem 53 print all permutations
### given an array or string simply print all possible permutations in any order.
#### using extra data structure and recursion tc = n!* n sc = n extra space.
1. every thing same as next solution but we create extra frequency array and initialise all elemnts to zero, in the helper function for loop then we push thenchange freq to 1 then recall function the change freq to 0 and pop this will give all cobinations provided loop runs under the condition freq or current index is 0.
#### using back tracking no extra space required.
1. exactly same as last problem.
2. in the recursive function put the base case ad in the for loop swap recall and swap, this would give required permutations.
---
## problem 54 placing n queens
### given n sized chessboard, find different ways of placing n queens on the board such that no queen can attack the other.
#### using backtracking and additional boolean function to check for safe positions tc = expo/ n!*n sc =n^2.
1. the idea is to check all possible places using backtracking and a boolean function to check if the to-be placed sopt is safe or not.
2. in the main function we create our answer vector and board vector and initialise it using loop as n strings of n dots each and pass it to recursive function with col set to 0.
3. in recursive function first write base case when col = n, push board in answer and return.
4. then run for loop for row =0 to row < n and inside loop first check if position is safe, if yes then edit that cell to be Q then recall the function with col++ and then reset the cell to be '.' .
5. these three lines will give us all possible combinations, by first traversing the whole row then by loop the whole column then the 2nd column and while backtarcking it resets the cell if changed.
6. now in the boolean safety check function we pass the row col board and n parameters, idea is to check for q in left side of same row, left side lower and upper diagonal(not needed to check right side as we know no q is placed there).
7. to do the same we run while loops with necessary conditions and in every iteration we check for q and increment decrecrement row/col as required.
#### same approach just optimising the safety check function tc same sc = n.
1. in the main function we initialise 3 additional vectors leftrow size n, lowerdiagonal size 2*n-1 and upperdiagonal size 2*n-1 the size is because there can be 2*n-1 different diagonals for any cell on a board.
2. the lower diagonal is marked by simply row+col and on every lower diagonal cell same number would be present so marking a lower diagonal means ther is one q present there, similarly in case of upper diagonal its n-1+col-row to fom upper diagonls and it works same as lowerdiagonal.
3. in the for loop instead of bool function we check if leftrow[row], lowerdiagonal[row+col],upperdiagonal[n-1+col-row] are all zero then and only then we move into the loop iteration.
4. now when we add q we edit all three vectors respective cells to 1 and when we remove we edit it to 0, rest backtracking process is same as previous approach.
---
## problem 55 solving sudoku 
### given an incomplete sudoku board completely solve with 3 traditional sudoku rules satisfied.
#### using matrix and backtracking tc = 9^(n^2) constant sc.
1. the logic is, for every blank space we try filling all 9 numbers and check its validity, if valid we move ahead and at any future juncture we find a position impossible we backtrack and try another number till we fill all blank spaces.
2. our main function is a boolean function with board paased as parameter, boolean to check if it is solvable further or not.
3. in this function we first run 2 nested loops to acces every cell and find the cell marked '.', then we run a for loop for char's from '1' to '9' and check for its validity in that position using if valid function.
4. if it is valid, we edit that cell value to be that char and then in if statement recall function as condition, if true we return true else we revert back the value to '.', the function on recall returning false means we have reached an impossible point so we revert the char value and try another.
5. after coimg out of the for loop of 9 characters we return false, we will reach this point if none of the 9 characters are valid, i.e an unsolvable position, at the end of the function we return true i.e we have placed all at right pos.
6. now in the isValid boolean function we pass the current row and column and the character, then we crun a loop and check in row and column, to check in the submatrix, we use board[3*(row/3) + i/3][3*(col/3) + i%3] in row, we reach the sub matrix by first term then iterate through first row by changing columns then move to next row, since it row we have i/3 it move 3x slower than col i%3 so that we can traverse through whole submatrix.
7. return true once checked.
---
## problem 56 rat in a maze.
### given n*n size maze with few blocked blocked by 0 and rest oopen by 1, find all paths a rat can take to reach right bottom from top left if it can move in all 4 directions.
#### using backtrcking and additional data structure for hashing writing different code for all 4 directions tc = 4^mn sc = mn.
1. in the main function we initialise our answer array and a visited vector to track visited cells and initilise it identical to maze with all cells 0 and then pass these along with row=0,col=0 and an empty string to the recursive function.
2. in the recursive function we write the base case when rat reached last cell then push the string in our answer vector.
3. now we check for all 4 directions whichever cell we are in, first we check if the cell we are movin into is not out of bounds then we check if it is visited, then we check if that cell value is 1 or not, if these conditions satisfy for a direction we move in it and mark the current cell visited and then recall the function with row/col edited and add the direction to the string, and after that again mark the cell not visited for when we backtrack.
#### same solution just instead of writing all 4 directions separately, we run a loop and write it all once.
1. in the main function we create two additional arrays for row 1,0,0-1 and for col 0,-1,1,0 these are if commands are in order DLRU, 
in the recursive function, insted of writing 4 times, we run a loop of 4 iterations and add di[z] to row and dj[z] to col and add that index of string DLRU to our string in every recall.
---
## problem 57 nth root of a number
### given n and m find nth root of m, variant is find upto 6 decimal places.
#### using binary search n*log(m + 10^d), d = no. of decimal places.
1. we basically use binary search with doubles, and along with hi and lo we initialise eps variable 1e-6, so that we can find upto 6 decimal places.
2. we run loop while hi-lo is > eps and keep changing hi/lo to mid if power function is hi/lo , at last we return low as we cannot find accurately over 6 deci places, also <= case is low =mid.
---
## problem 58 matrix median
### given a 2d matrix with r*c odd, and every row is sorted in ascending order, find median of elements of that matrix.
#### using binary search.
1. theres another approach where we store all elements in a data structure and then sort them to get required element but that will take extra space.
2. so we find minimum and maximum of the matrix and make middle, then count no of elements less than or equal to the middle element, if less, we edit mini to be mid +1 else max = mid, we run loop while mini< maxi, return mini as we come out of the loop.
---
## problem 59 search single
### given a sorted array with all elements occuring twice except one, find the element.
#### in tc = n, by traversing whole array.
1. one approach is to make two consecutive pointers,initially pointing to first two elements and increment by in every iterartion, if at any point both point at differernt values then return lo, else if we come out of loop that runs till faster pointer reaches 2nd last element, return last element.
2. another approach is using XOR, since p^0 = p and p^p = 0, calculate xor over entire array and return eventual value as answer.
#### optimal approach using binary search.
1. set lo and hi pointer to first and last element, and run loop while lo < hi, set mid to be lo+hi/2, now we will have to operate differently for when mid is even and when mid is odd.
2. idea is to check if single element is before mid or after, in case of mid = even, this means if single element is not before mid then due to the pattern mid element = mid+1 element so we set lo = mid, else mid element = mid-1 element, so we set hi = mid, else if both are not the case then we have our abswer as mid element, similarly for the case when mid is odd.
---
## problem 60 search an element in a rotated sorted array
### given a soerted array after rotating it about a pivot, find if the target element is present, if yes then which position.
#### binary search tc = logn
1. basically we consider it as two separate sorted arrays, first we initialise lo=0 and hi=n-1 pointers, then run a loop while lo is less than or equal to hi.
2. now we initialise mid and heck if it is the target, return mid if yes.
3. now we check if low element is less than or equal to mid element, if yea then it means we are in same sorted array, so now er check if the target is present in this range of lo-mid, if yes then we set hi to mid else it would be present in another sorted array so we edit lo = mid+1.
4. if lo is greater than mid then definitely mid is in different sorted array, so we check if element is present in mid to hi, if yes then set lo to mid else we set hi to mid -1.
5. oncewe come out of loop, it means element is not present so we return -1.
---
## pr0blem 61 median of two sorted arrays.
### given two sorted arrays, find the median, if two medians return their average.
#### ineff approaches.
1. one idea is to put both into one array and sort it and find median.
2. else take two pointers and insert smaller one in a third array and return once reached median value.
#### efficient approach tc = log(min(n,m)), sc =1 using binary search.
1. the idea is to divide both arrays into two parts such that the left of both parts are the elments to the left of median.
2. we will apply binary search in the smaller array, so take n to be smaller than m, if m< n, then recall function with both arrays reversed.
3. now we calculate median by n+m+1/2 and set lo and hi.
4. now run loop while lo<=hi , in the loop calculate first cut by lo+hi/2 and other cut by simply median - cut1.
5. now we initialise 4 numbers 1 on either side of each of the two cuts. and if cuts are last or first element we set them to be intmax,intmin accordingly.
6. now we check if l1 is less than equal to r2 and l2 is less than r2 where l are element left of cut and r are to right of cut, if this satisfies we return max(l1,l2) else max(l1,l2)+min(r1,r2)/2.0 but if l1 > r2 we have to shift cut to left, so we set hi = cut-1 else we have to shift cut to right so we do l0 = cut+!.
7. we we come out of while loop we have no solution so return 0.0.
---
## problem 62 kth elemnt in two sorted arrays
### given two sorted arrays find the kth elemnt if two arrays were a single sorted array.
#### using two pointers tc = n+m sc=1.
1. in this we initialise two pointers pointing to first elements of both arrays, and create a counter=0 ans a current element holder.
2. now we run a loop while none of the array ends, in every iteration we will check which element pointed to is smaller, we store that element as currrent and increase counter.
3. if couter is k i.e we got our element so we return curr.
4. if we come out of loop, that means one array ended, we check which one, and in the other we return arr[a + k - counter -1];
5. return1 is no answer, only happens when k>m+n so dw.
#### using binary search tc= log(min(m+n)) sc=1.
1. same as we did partitioning in last problem, but in this case out cuts may go well out of bounds of the two arrays, so we set lo to max(0,k-m), if k is more than m then surely we will have atleast k-m elements from first array, and set hi to min(n,k) if k is less than n then surely we wont take elements after k in first array.
2. restricting these bounds prevents our cuts from running out of bound, so the rest of the problem can be solved easily in the same way as before.
---
## problem 63 allocate pages to students.
### given an array of number of pages in different books and number of students to be distributed to, find minimum of max number of pages to a student, if every student gets atleast one, one book can be given to only one student and books to be distributed in contiguous manner.
#### using binary search by first creating a search space. tc = nlogn sc=1.
1. the idea is to create a search space by determining the minimum and the maximum possible answer, for that we can say that minimum answer would be the minimum element in a case when all elemnts are same and b = size of array; and maximum answer possible is sum of all elements when b = 1.
2. so we first traverse the array and find sum and minimum element and then set low to be the minimum element and hi = sum.
3. run a loop till lo <= hi and set mid = lo+hi/2, now we start allocating pages and move on to the next student if allocation exceeds mid value move on to next student and so on, in case any element exceeds mid value, stop the loop and edit lo to mid+1 to increase mid value.
4. else if students is less than B (less than b because we initialise students to 0 and so dont count first student),then inrease lo to be mid+1 else hi to be mid-1.
5. once we come out of loop return lo.
---
## problem 64 aggressive cows
### given n number of stalls and c no. of cows, and position of n stalls, find the largest minimum distance between two cows possible. That means is there are 4 cows and distance between them is a,b,c we have to maximise min(a,b,c).
#### using brute force proving it is a monotonic function tc = nm, sc = 1.
1. in this approach we start by placing all cows consecutively so that initial minimum distance is 1, and the maximum minimum distance possible would be last - first(in case when 2 cows present), so we run a loop from d=1 to max distance.
2. for every minimum distance we place other cows and check if placing them is possible.
3. for that we run a loop from i=1 to n, we initialise k by placing one cow on first stall, then check if the next position in loop - k is >= minimum distance, if yes then we cows--, edit k to be the current stall, till we exhaust cows , in that case we return true, else return false.
4. we return max of all possible minimum distances.
#### using binary search tc = nlogm sc = 1.
1. in this approach we first establish our search space to be from 1 to last element - first, we can say for sure the answer will lie between thee two values.
2. now run a loop while lo<=hi , set mid and then check if mid is a possible minimum distance by the same function we used in previous approach.
3. if yes, then it means our answer will be greater than this mid element as we need max answer, so we move lo = mid+1, else we move hi = mid-1.
4. eventually when lo > hi , return hi as it would be the max minimum distance possible.
---
## problem 65 min heap implementation 
### heap is a complete tree ( all levels complete except the last one and last level has all keys as left as possible)
### min heap(max heap) is a heap in which every node is lesser(greater) than its children nodes, least(max) being the root node.
### binary heap is the one in wich every node has two children nodes.
### given n commands to either insert element in heap or remove the least element and return it.
#### using priority queue data structure to implement heap.
1. by default priority queue stores elements as per max heap but to initialise it as min heap p_q<int, vector<int>, greater<int>>.
2. now according to the command, p_q.push(i), else in answer vector push p_q.top(), i.e the minimum element, and then pop it using p_q.pop().
#### implementing min heap using array 
1. to access left child return 2*i +1, to access right return 2*i +2 to access parent return (i-1)/2.
2. void insert function set heap[size] = value(we are not pushing back because when we initilaise heap we allocate n size already).
3. then we heapify using swap (by strting from bottom and swapping parent if it is grester) and also increase size by one.
4. int extractMin fuction to remove the root (smallest) element and return its value, if size is one simplt decrease size by one and return heap[0]
5. else store the value, then decrease size then edit root to be the last element of heap and then heapify, return stored value.
6. void minheapify funtion initialize left and right and smallest = current element, now if left < size(so that ir dosent go out of bounds) and element at left is smaller, then edit smallest to be left, now if right is less than size and element at right is smaller than the smallet element, edit smallest to be right.
7. now if smallest is not i, we have to swap heap[i] and heap[smallest] and again call recursively heapify function with i = smallest.
8. in the main min_heap function, initialise vector heap with pre allocated memory n and an answer vector, if command says insert, simply call insert function, else push extractmin function to the answer array(this will remove the element as well), return answer vector.
---
## PROBLEM 66 kTH LARGEST/SMALLEST ELEMENT
### given a vector and an interger k, fing kth largest/smallest element.
#### using priority queue to implement heap tc = k+ (n-k)logk, sc = k.
1. use priority queue to store elements from the vector (max if largest, min heap if smallest)
2. then pop k-1 elements and return the top element after.
#### using quickselect algorithm tc = O(n) avg case, sc = 1.
1. the idea is to implement quick sort and then if the pivot is smaller we find in right half else left half.
2. initialise left = 0 and right =n-1.
3. run infinite loop and initialise index = partition function passing the vector and left and right to it.
4. the check if index = k-1, return element at index, else if index  < k-1, left = idx+1, else right = idx -1.
5. in the partition function , set pivot is left indexed elemnt, initilaise l = left+1 and r = right.
6. while l<=r if element at l is less then pivot and at right is greater, swap l and r elements and l++ r-- 
7. now if element at l is greater than pivot, move l ahead and if r is lesser, move r back a step and continue loop.
8. then once out of loop, swap pivot and r and then return r, this function in every loop iteration basically segregates all greater to the left of pivot and all smaller to right of pivot, similar function can be writtem if kth smallest has to be found.
---
## problem 67 k max sum combinations 
### given two arrays of size n, find first k largest sums possible from elements of both arrays.
#### brute force tc = n^2 + nlogn sc =n
1. run nested loops amd calculate all possible combinations possible and store in an array.
2. sort the array and push required sums to answer array
#### using priority queue to implement heap and set for uniqueness tc = nlogn sc = n.
1. the idea is to use set to check if combinations are repeated, and store tuples in max heap sum,(indices) and pair of indices in set.
2. firstly we sort both arrays, then create a max heap and push largest sum and largest indices into the max heap, and create set and push max indices into the set, we use pair to store values so remember to use {} around every pair.
3. now run loop while k>0, and in every iteration reduce k by one, in every iteration store top of maxheap and push the sum in answer array, now we check if x-1,y and x,y-1 indices are present in set if not we add them with their elements sum to the set and max heap and the continue iteration.
4. finally once we are out of loop, return answer array. be careful with use of pair and remenber to sort array.
---
## problem 68 find median of a running data stream.
### given an array to be input as running data stream print median at each input point if there are n entries.
#### using sorting  tc = n^2.logn sc = 1
1. at every element, sort the array and find middle element.
2. an optimised version of this approachis, at every new entry since it is previously sorted, using nested loop find element just greater than current element and insert it there using vector insert(position, val), then determine middle element.tc = n^2 sc = n.
#### using minheap and maxheap tc = nlogn sc = n.
1. the idea is to divide inputs in two halves lower(using max heap) and upper half using (min heap) and at every point try to maintain equal elements in both halves.
2. first create max and min heap, then check if max heap is not empty and element is less than max heap top then insert in max heap, now if max heap size is more than min heap + 1 then add top of max heap to min heap and pop it from max heap.
3. else insert in min heap and again check size, if more in min heap add to max heap, now check if size is odd if yes then median is top of half which has more size else it is avg of top of both halves.
4. print median, remember after initialising both halves run a loop for size =1 to n, remeber both heaps coincide at median point with their tops pointing to median point, so lower half is max heap and upper half min heap.
---
## problem 69 merge k sorted arrays
### given k sorted arrays, merge them into a single sorted array.
#### brute force tc = nklognk sc = nk.
1. push all elements into a single vector and sort it.
#### using divide and conquer recursion method. tc = nklogk sc = nklogk.
1. idea is to keep dividing vectorsmin two parts until we have two or one vector and then merge them using two pointer method.
2. first call helper function and pass given vectors and 0 as start and k-1 as end.
3. in helper function, write base cases, start=end return [start] pointed vector, if start+1 == end i.e two vectors, return their merge
4. else we recursively call the same function twice for either halves, start to mid for one and mid+1 to end for second.
5. in the end return the merge of these two call results.
6. merge function is same as we have been using with help of two pointers.
#### using minimum heap. tc = nklogk, sc = nk.
1. idea is to add first elements of all arrays and then returning top of min beap(min element) now if that array isnt empty we add another next element of that array to heap.
2. create min heap that can store tuple, pair of a value and a pair so that we can store indices as well.
3. now iterate over all arrays and push first element of each into the heap, theb run loop while heap is not empty.
4. we push heap top to answer array and pop heap top and if that array we picked heap top from is not empty, ie j+1< size  we will add next element of that array to heap.
---
## problem 70 k most frequent elements
#### using quickselect algorithm n^2=tc, sc =n.
1. similar to how we found kth smallest element, but in this instead in partition function we use our map key,value pairs and shift all less frequncy left words.
2. using map and vector, we assign all unique numbers to a vector and perform the quick select algo on it.
3. we use pivot = left + rand()%(right-left) to select a random pivot.
4. use map in partition function to segregate low freq and gi freq elements.
#### using heap nlogn = tc, sc =n.
1. use map/vector to store values and their frequencies in pairs.
2. then add them pairs to a heap, and one by one extract k max freq elements.
3. add them to a vector, sort it and return.
#### using bucket sort algo tc = n, sc = n.
1. important point *vector<int> xyx[n]* creates an ARRAY of n VECTORS .
2. store all elements in a map with their frequencies and then create an array of vectors and of size = max of frequencies i.e n.
3. then add elements to thier respective frequency bucket(vector) and then traversing from max value pick k elements that would give us the answer.
---
## problem 71 Binary Tree Inorder Traversal.
### given a binary tree, print node values trversing the tree inorder manner.
### inorder traversal means, left subtree then parent node then right subtree.
#### iterative method using stack data struture tc=sc= n.
1. idea is to keep moving from root to the left most leaf node while pushing all the nodes on the way to a stack.
2. once we reach null, print top of the stack value and pop it then move to the right child node and do the same till we reach null.
3. as we get null we will keep printing top values of stack and this thus give us the inorder traversal list of nodes.
#### using recursion tc = sc = n.
1. idea is to travel to the left most leaf node recursively then push the value into answer vector and then move to right recursively.
2. since we are using recursion, it will back track to parent node print it and move right then again back track to previous levels and so on we will get the required traversed list.
---
## problem 72 Binary tree Preorder traversal.
### given a binary tree, print node values traversing the tree preorder manner.
### preorder traversal means, root then left subtree then right subtreee.
#### iterative method using stack data struture tc=sc= n.
1. the idea is to push the root into the stack and then to the answer vector, then push the right child to the stack first then the left chil so that the left child can be accessed first.
2. we initialise our vector and stack and for the case when root == NULL, we return empty vector.
3. push root to the stack, then run a loop while s is not empty, then make a node to carry top element of stack, pop the top element and push its value to the vector.
4. then if right child is not null add it to stack first then check if left child is not null, push it to the stack, then in the next iteeration of loop we will print top element and again check for left and right and so on we will get our preorder traversal of nodes.
#### using recursion tc = sc = n.
1. first put the base case, when root = null return the void function.
2. since in preorder, we first print root then left then right, first push root value to the answer vector then make two recursive calls, first for root's left child then for roots right child.
3. these calls would backtrack and give the required preorder traversal.
---
## problem 73 Binary tree Postorder traversal.
### given a binary tree, print node values traversing the tree postorder manner.
### postorder traversal means, left subtree then right subtreee and then the parent node of them.
#### recursion tc=sc=n.
1. first put the base case, when root = null return the void function.
2. now we call the function recursively twice, first passing root->left then root->right, and then we push root value to answer vector.
3. these calls would backtrack and give the required postorder traversal.
#### iterative method using two stacks tc = n, sc = 2n.
1. idea is to push values in one stack in preorder manner and then push them to another stack.
2. then we push these values to answer vector to get required traversal.
3. we initialise vector and two stacks, and push root in one stack.
4. then we run loop while the first stack is not empty, and push the top node to second stack, and pop it from the first.
5. then we check if left child is null, if not then push it to first stack, then the right child.
6. this way in the next iteration we will first push the right child to another stack and then the left, so that when we pop elements from second stack we first get the left thrn right then parent.
7. in the last step, simply push top of stack 2 to ansswer vector and pop the top in every iteration till its empty.
#### using one stack only tc = sc = n.
1. we first initialise vector and stack and check for the case when root is null.
2. run a loop while root is not null or stack is not empty, check is root is not null, then push into stack and move root to root->left, else(i.e root is null) so we create a temp node and initialise its value to be s.top()->right that right chil of parent node whose left is null, now if this temp is also null, this means we have reached a leaf node, so we push this to our answer vector and pop out of stack.
3. no we check the case if the node we just pushed is the right child, if yes then the next node to be printed is the parent node which is at the top of our stack so we push it to our vector and pop it out of stack.
4. the else case in which the right child is not null, we move root to be this right child so that we can print this subtree.
5. return answer vector.
---
## problem 74 and 75 Morris inorder/preorder traversal.
### given a binary tree, print inorder and preorder traversal of nodes using noextra space by morris method.
### in morris traversal, we basically use threaded binary trees, which means, the right most node of a left subtree points to the parent of that subtree. we make use of this to traverse the binary tree.
#### morris threaded binary tree traversal using no extra space and tc = n.
1. we run a loop while root is not null, and check if left sub tree exists, if not we push the current node to our vector and move to right child
2. if it does exist, we traverse to the right most node of this sub tree using while loop, now if it is pointing to null, in case of in order traversal, we simply point it to current node(parent of this subtree) and move current node to its left child and in case of preorder traversal,we point right most node to current node and push value of current node to answer vector then move current to left subchild.
3. if it is pointing to the current node already, this meanswe have traversed this subtree already, so in case of inorder traversal, we remove this link by pointing it to null and push back this node to answer vector and move current to right subchild whereas in case of preorder traversal, simply remove link and move to right child of current node.
---
## problem 76 LEFT/RIGHT VIEW of binary tree.
### given a binary tree reference to its root, print the left view and right view of the same.
#### using recursion tc = n, sc = height if tree.
1. the idea is to use concept of levels, if root is at level 0 and it keeps increasing for every child node.
2. we pass answer vector root and level 0 to recursive function.
3. in the function, base case is when root is null we simply return. now, the idea is, if the size of answer vector is equal to level, push it in answer vector.
4. for left view, if we push left most element and then recursively come to its right sibling, the level would be one less than size, so we dont push the right one.
5. basically at every level we push the left most and traverse every node recursively, since we have started from level 0, at every left most element, level = size of answer which is no. oflevels travelled till now.
5. for right view, we first recursively call root->right then left, contrary to left view, everthing else is same.
---
## problem 77 and 78 BOTTOM/TOP view of a binary tree.
### given a binary tree reference to its root, print the bottom/top view of the same.
#### using queue and map data structure tc = sc =n.
1. the idea is to use the concept of line wise traversal, root being at line 0 and each node to the left being -1 and to the right being +1.
2. we use a map with key as the line and its value as the node(value) which is on tha line, while we use a queue to store node and its line in pairs in it.
3. so we first create a queue and a map with necessary data types and push root node and its line 0 to the queue.
4. now we run a loop whie queue is not empty, in the loop we access the front element of the queue and store its first value to a temp node and its second value to a line int and pop it from the front of the queue.
5. now since in bottom view we need the last element on any line we simply assign map with key line a value of temp->val, if there alredy was a node on the same line it would get edited and we would get the last node.
6. for top view, we first need to check if this line has already been inserted in the map, if yes we dont have to edit it, cuz we want the first element on the line else we insert the current key value pair.
7. now we check if left child of temp node is not null, we push the child and line-1 to queue similarly we push/not-push the right child with line+1.
8. after coming out of the while loop, we push all the nodes from our map to out answer vector and return it.
---
## problem 79 all 3 types of traversals in one iteration 
### given root reference of a binary tree print all three traversals in one iteration
#### using stack and pair tc=sc=n.
1. the idea is, if a particular node is visited for the first time, it means it has to be added to pre order trv, if visited second time then inorder and if visited third time then post order.(this can be determined by observation and this is the base logic)
2. we initialise a stack that takes a pair with node and int data types and create 3 different arrays pre, in ,post.
3. firstly we push root,1 in the stack and then run a loop while stack is not empty.
4. now we store the top pair in the stack and pop it, no the second entry of pair is the number of times the node in first entry has been visited.
5. so if second value is 1, we push the first in pre vector, increment second value and again push the edited pair to the stack.
6. now we check if left child exists, we move our node to its left child and push into te stack with visited freq 1.
7. if second valueis in, we push first node to in vector, increment the second value and push the edited pair to the stack.
8. now we check if right child exists, if yes we move to the right child and push that node with visited freq 1 into the stack.
9. for all other values of second value (3 basically), we simply add the first node to the post vector, we dont have to push anything to the stack in this case, as after 3 visits it wont be visited and obc its childrensub trees must have been visited.
---
## problem 80 vertical order traversal of binary tree.
### given root reference of a binary tree, print vertical order traversal from leftmost to rightmost node printing elements from top to bottom on every line and in ascending order if same coordinates of two elements, duplicate nodes are present as well.
#### we will use a special data structure, map<map<multiset>> and queue tc = nlognlognlogn sc = n.
1. the idea is to traverse the tree and assign a vertical and a level value to every node, we store these 3 values in a special data structure.
2. first we need to travel from left most to right most, so we select a map as it stores in ascending order, now in every line we need to print from top to bottom, so second element of first map is also a map so that we can get ascending order of levels, now since duplicates are present in tree and we have to print elements having same verical and level in ascending order, we set second elelemt of second map as a multiset.
3. now we create a queue with pair entries, first bein a node and second being a pair of vertical and level values.
4. firstly we push root,{0,0} in the queue and then run a loop while queue is not empty.
5. now we access the front element of the queue and pop it, we store first element of queue in a temp node and set x = first of second element(vertical), and y = second or second element(level).
6. now we assign vetical key level key and multiset value to our data structure, nodes[x][y].insert(temp->val).
7. now if left(right) element exists, we push it into the queue with the respective node and {x-1,y+1} for left and {x+1,y+1} for right.
8. now we have assigned all coordinates to all nodes so we will now push our answers to the answer vector.
9. run loop for p in nodes and a nested loop for q in p.second, for every iteration in inner loop we create a col vector, and insert the whole multiset of that vertical,level to col vector and then push col vector to answer vector.
---
## problem 81 find root to node path
### given root reference of a binary tree and a target node, find a path from the root to that node.
#### using recursion tc=sc=n
1. the idea is to first check if the current node is the target node, if not then check left and right sub tree recursively.
2. in this recursive approach, the path would automatically get added to the array in every step and if target is found it would rreturn with the path.
3. we pass our root , answer vector and target to a bool recursive function and for root==null return false.
4. now we add the root(current) node to array and check if it is the target node, return true if yes
5. else we check if left or right subtree had the target, by calling recursively for left and right subtree and return true if yes.
6. if this condition is not true, it means target is not in the tree so we popback from array and return false.
---
## problem 82 find max width of a binary tree
### given root reference of a binary tree find the max width of the binary tree if empty nodes in between are to be counted as well.
#### using queue and pair DS and level order traversal tc=sc=n.
1. the idea is to travel level order wise nd on every level run a loop to traverse every node on that level and assign an index to it, left child being 2*i+1, right being 2*i+2.
2. we push node and value as pairs in the queue and firstly push root and 0 to the queue.
3. to avoid overflow, we set first element as curr_min and for every traversal in a level we make curr id = value of a node - curr_min.
4. idea is to push left and rigth child if they exist for every node, by creating a temporary node and poping out the top of the queue everytime.
5. we set leftmost and right most to be the curr_id for first and last node of the level, later we return answer as rightmost-leftmost+1(max).
---