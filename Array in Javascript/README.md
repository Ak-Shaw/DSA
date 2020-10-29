# INTRODUCTION 
Arrays are one of the most used data structures. You probably have used it a lot, but are you aware of the runtimes many array operations? In this microbyte, we are going deeper into the most common operations and their runtimes.

# PREREQUISITES:
* A machine with any JS compiler installed. Or any online compiler will work too
* Knowledge of Javascript syntex.
* Loads of enthusiasm!

## Array Basics
An array is a collection of things (strings, characters, numbers, objects, etc.).

### Fixed vs. Dynamic Size Arrays
Some programming languages have fixed-size arrays like Java and C++. Fixed-size arrays might be a hassle when your collection gets full, and you have to create a new one with a bigger size. Those programming languages also have built-in dynamic arrays: we have vector in C++ and ArrayList in Java. Dynamic programming languages like JavaScript, Ruby, and Python use dynamic arrays by default.

Arrays look like this

![this](img/array.png)

Figure 1. Array representation: each value is accessed through an index. index starts from 0

#### What are the diffrent operations on an array ?
* **Insertion**

* **Deletion**

* **Searching**


# ACTIVITIES:

### ACTIVITY 1:
## Insertion
Arrays are built-in in most languages. Inserting an element is simple; you can either add them at creation time or after initialization. Below you can find an example for both cases:

```
Inserting elements into an array
// (1) Add elements at the creation time:
const array = [2, 5, 1, 9, 6, 7];

// (2) initialize an empty array and add values later
const array2 = [];
array2[3] = 1;
array2[100] = 2;
```
The runtime for inserting elements using an index is always is constant: O(1).

### Insertion can be done in 3 ways

### Inserting at the beginning of the array

```
const array = [2, 5, 1, 9, 6, 7];
array.unshift(0); // 
// array: [0, 2, 5, 1, 9, 6, 7]
```
As you can see, 2 was at index 0, now was pushed to index 1, and everything else is on a different index. unshift takes O(n) since it affects all the elements in the array.

### Inserting at the middle of the array

```
const array = [2, 5, 1, 9, 6, 7];
array.splice(1, 0, 111); 
// array: [2, 111, 5, 1, 9, 6, 7]
```
At position 1, delete 0 elements and insert 111.
The Big O for this operation would be O(n) since, in the worst case, it would move most of the elements to the right.

### Inserting at the end of the array

```
const array = [2, 5, 1, 9, 6, 7];
array.push(4); 
// array: [2, 5, 1, 9, 6, 7, 4]
```
The 4 element would be pushed to the end of the array. Notice that push returns the new length of the array. Adding to the tail of the array doesn’t change other indexes. E.g., element 2 is still at index 0. So, this is a constant time operation O(1).
Full code can be found at [here](src/insertion.js)
### Micro-Challenge
Can you find A way to clone an array. 
Solution:
There are several ways to clone an array:
1. Using loops: Copying elements one by one into the new array. You should ideally be able to do this by yourself. In case you are unable to solve the solution is given below:

<details>
<summary>CLICK TO SEE SOLUTION</summary>

``` 
let arr1 = [2, 3, 6, 1];
let arr2 = [];
for(el of arr1) {
     arr2.push(el);
}
console.log(arr2);
// arr2: [2, 3, 6, 1]
```

</details>

2. Using array.map: It calls the function for each element of the array and returns the array of results. An array can be cloned by returning the element in our map call.
    First try yourself. Check the solution only if you get stuck.

<details>
<summary>CLICK TO SEE SOLUTION</summary>

```
let arr1 = [2, 3, 6, 1];
let arr2 = arr1.map((x) => x);
// arr2: [2, 3, 6, 1];
//(x) => x is called identity. It returns whatever parameter it's been given.
```

</details>

3. Using array.slice(): It returns a new array copying to it all items from index start to end. Do give it a try. You can see the solution in case you are unable to solve.

<details>
<summary>CLICK TO SEE SOLUTION</summary>
    
```
let arr1 = [2, 3, 6, 1];
let arr2 = arr1.slice();
// arr2: [2, 3, 6, 1];
```
    
</details>  
 
There several other ways of cloning an array. Find out one such way. (You can create a PR and add it here)

### ACTIVITY 2:
## Deletion
There are three possible deletion scenarios (similar to insertion): removing at the beginning, middle, or end.

### Deleting from the beginning of the array.

```
const array = [2, 111, 5, 1, 9, 6, 7];
// Deleting from the beginning of the array.
array.shift();  
// array: [111,5, 1, 9, 6, 7]
```
As expected, this will change every index, so this takes O(n).
### Deleting element from the middle
```
const array = [0, 1, 2, 3, 4];
// Deleting from the middle
array.splice(2, 1); // delete 1 element at position 2.
// array: [0, 1, 3, 4]
```
Deleting from the middle might cause most of the array elements to move up one position to fill in for the eliminated item. Thus, runtime: O(n).
### Deleting element from the end
```
const array = [2, 5, 1, 9, 111];
array.pop(); 
// array: [2, 5, 1, 9]
```
No other element has been shifted, so it’s an O(1) runtime.
Full code can be found at [here](src/deletion.js)
### Micro-Challenge
How to remove multiple elements from array in JavaScript ? 
Solution:
If we want to remove consecutive elements from an array(from a particular index) then we can use the "splice" method. Try googling about the "splice" method and solve this. 
In case you are stuck, you can look up the solution given below.

<details>
<summary>CLICK TO SEE SOLUTION</summary>

```
const arr = [1, 2, 3, 4, 5, 6, 7];
// we want to remove 3 elements starting from index 2
arr.splice(2, 3);
// arr: [1, 2, 6, 7]
```

</details>  

If we want to remove multiple elements from an array which aren't necessarily consecutive then we can remove it one by one by using a loop. Give it a try.(Hint: "splice" will be 
used here too)

<details>
<summary>CLICK TO SEE SOLUTION</summary>

```
const arr = [1, 2, 3, 4, 5, 6, 7];
// we want to remove 3 elements: elements at indices 1, 3 and 4
const removeElementAtIndex = [1, 3, 4];
for (let i = removeElementAtIndex.length - 1; i >= 0; i--) {
    arr.splice(removeElementAtIndex[i], 1);
}
// arr: [1, 3, 6, 7]
// We are traversing the "removeElementAtIndex" array in reverse order so that the indices of the elements yet to be removed are not messed up
```

</details>  

### ACTIVITY 3:
## Searching 
There are two possible searching.
* Searching by index
* Searching by value 


```
function searchByIndex(array, index) {
  return array[index];
}
```
Searching by index takes constant time - O(1) - to retrieve values out of the array.

```
function searchByValue(array, value) {
  for (let index = 0; index < array.length; index++) {
    const element = array[index];
    if (element === value) return index;
  }
  return -1;
}
```

We would have to loop through the whole array (worst case) or until we find it: O(n).
Full code can be found at [here](src/searching.js)
### Micro-Challenge
Can you find more efficient solution ? 
Solution:
A more efficient solution would be using binary search.
First try it yourself. If you are unable to solve look at the solution below:

<details>
<summary>CLICK TO SEE SOLUTION</summary>

```javascript
function binarySearch(arr, val, lo, hi) {
    while(lo <= hi) {
        let mid = lo + (hi - lo) / 2; 
        if(val == arr[mid]) {
          return mid;
        }
        else if(val > arr[mid]) {
          lo = mid + 1;
        }
        else {
          hi = mid - 1;
        }
    }
    return -1;
}
function searchByValue(arr, val) {
    return binarySearch(arr, val, 0, arr.length - 1);
}
```

Time complexity: O(log n) 

</details>

### ACTIVITY 4:
## Transform an array
Here are some very useful methods that transform and reorder an array:
### 1. sort()
array.sort() sorts the array in place, changing its element order. It also returns the sorted array but the returned array is usually as the array itself is modified. The default sort order is ascending, built upon converting the elements into strings, then comparing their sequences of UTF-16 code units values.

```
let arr = [3, 6, 5, 23, 11];
arr.sort();

```
Try printing `arr` in the console after writing the piece of code given above. Did you notice something strange? Well there is nothing wrong there. By default the numbers are
converted into strings and they are compared according to the lexicographical order. To sort the array in our desired order we need to supply a function as an argument of arr.sort().

So the template would be something like this: 
```
function compare(a, b) {
   // todo: complete this function
}
arr.sort(compare);
```
### Todo: 
Complete the function for two cases: ascending order and descending order

### 2. map()
array.map() calls the function for each element of the array and returns the array of results.

```
let arr1 = [4, 8, 2, 14, 6];
let arr2 = arr1.map(x => x/2); 
// an arrow function has been used here
// to know more about arrow functions check the reference section
// arr2: [2,4,1,7,3]
```
### Todo: 
Use the map method to transform each element of an array into its length. 
e.g. Input: ["cat", "wolf", "tiger"]
     Output: [3, 4, 5]
(The operation should be in-place - don't store results in a different array)

### Micro-Challenge
Write a function that gets an array of objects (containing "name" and "age" properties) and sorts them by age.

```
let sam = { name: "Sam", age: 29 }
let tom = { name: "Tom", age: 56 };
let rose = { name: "Rose", age: 22 };
let arr = [sam, tom, rose];

function sortByAge(arr) {
     // complete this function
}

// arr: [rose, sam, tom]
```

# Summary
We just learned most common operations of array and their runtimes. Amazing right? now we can go ahead, do further excercise.
Congo on completing this MicroByte!  Don't forget to add your solutions.

# References

- [MDN Web Docs: Array](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array)
- [MDN Web Docs: Splice](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/splice)
- [MDN Web Docs: Unshift](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/unshift)
- [MDN Web Docs: Shift](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/shift)
- [StackOverflow: Remove multiple elements from array](https://stackoverflow.com/questions/9425009/remove-multiple-elements-from-array-in-javascript-jquery)
- [MDN Web Docs: Slice](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/slice)
- [MDN Web Docs: Map](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
- [MDN Web Docs: Sort](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)
- [MDN Web Docs: Arrow Functions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions)
