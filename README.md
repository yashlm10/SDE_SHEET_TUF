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