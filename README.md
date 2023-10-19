<h1>Sorting algorithms & Big O</h1>
<img src="https://cdn-media-1.freecodecamp.org/images/1*KfZYFUT2OKfjekJlCeYvuQ.jpeg" alt="Big O notation" width="100%" height="auto">

## Description

- <strong>Sorting Algorithm:</strong> In computer science, a sorting algorithm is an algorithm that puts elements of a list into an order. The most frequently used orders are numerical order and lexicographical order, and either ascending or descending.
- <strong>Big O Notation:</strong> Big O Notation in Data Structure is used to express algorithmic complexity using algebraic terms. It describes the upper bound of an algorithm's runtime and calculates the time and amount of memory needed to execute the algorithm for aninput value.

## Learning Objectives

At the end of this project, you are expected to be able to [explain to anyone](https://alx-intranet.hbtn.io/rltoken/b-QhraVUoSGmQ1C4QfNoFw "explain to anyone"), **without the help of Google**:

### General

-   At least four different sorting algorithms
-   What is the Big O notation, and how to evaluate the time complexity of an algorithm
-   How to select the best sorting algorithm for a given input
-   What is a stable sorting algorithm


## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on `Ubuntu 20.04` LTS using `gcc`, using the options `-Wall` `-Werror` `-Wextra` `-pedantic` `-std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- You are not allowed to use global variables
- No more than 5 functions per file
- Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like `printf`, `puts`, … is totally forbidden.
- The prototypes of all your functions should be included in your header file called `sort.h`
	_Don’t forget to push your header file_
- All your header files should be include guarded
- A list/array does not need to be sorted if its size is less than 2.
- The following format is expected for big O notation:
  * `O(1)`
  * `O(n)`
  * `O(n!)`
  * n squared -> `O(n^2)`
  * log(n) -> `O(log(n))`
  * n * log(n) -> `O(nlog(n))`
  * n + k -> `O(n+k)`

Please use the "short" notation (don't use constants). Example: `O(nk)` or `O(wn)` should be written `O(n)`. If an answer is required within a file, all your answers files must have a newline at the end.

## Tasks :page_with_curl:

* **0. Bubble sort**
  * [0-bubble_sort.c](./0-bubble_sort.c): C function that sorts an array of integers in ascending order using the Bubble Sort algorithm.
  * Prints the array after each swap.
  * [0-O](./0-O): Text file containing the best, average, and worst case time complexities of the Bubble Sort algorithm, one per line.

* **1. Insertion sort**
  * [1-insertion_sort_list.c](./1-insertion_sort_list.c): C function that sorts a `listint_t` doubly-linked list of integers in ascending order using the
  Insertion Sort algorithm.
  * Prints the list after each swap.
  * [1-O](./1-O): Text file containing the best, average, and worst case time complexities of the Insertion Sort algorithm, one per line.

* **2. Selection sort**
  * [2-selection_sort.c](./2-selection_sort.c): C function that sorts an array of integers in ascending order using the Selection Sort algorithm.
  * Prints the array after each swap.
  * [2-O](./2-O): Text file containing the best, average, and worst case time complexities of the Selection Sort algorithm, one per line.

* **3. Quick sort**
  * [3-quick_sort.c](./3-quick_sort.c): C function that sorts an array of integers in ascending order using the Quick Sort algorithm.
  * Implements the Lomuto partition scheme.
  * Always uses the last element of the partition being sorted as the pivot.
  * Prints the array after each swap.
  * [3-O](./3-O): Text file containing the best, average, and worst case time complexities of the Quick Sort Lomuto Partition scheme algorithm, one per line.

* **4. Shell sort - Knuth Sequence**
  * [100-shell_sort.c](./100-shell_sort.c): C function that sorts an array of integers in ascending order using the Shell sort algorithm.
  * Implements the Knuth interval sequence.
  * Prints the array each time the interval is decreased.

* **5. Cocktail shaker sort**
  * [101-cocktail_sort_list.c](./101-cocktail_sort_list.c): C function that sorts
  a `listint_t` doubly-linked list of integers in ascending order using the Cocktail Shaker Sort algorithm.
  * Prints the list after each swap.
  * [101-O](./101-O): Text file containing the best, average, and worst case time complexities of the Cocktail Shaker Sort algorithm, one per line.

* **6. Counting sort**
  * [102-counting_sort.c](./102-counting_sort.c): C function that sorts an array of integers in ascending order using the Counting Sort algorithm.
  * Assumes that the array will only contain numbers `>= 0`.
  * Prints the counting array after it has been initialized.
  * [102-O](./102-O): Text file containing the best, average, and worst case time complexities of the Counting Sort algorithm, one per line.

* **7. Merge sort**
  * [103-merge_sort.c](./103-merge_sort.c): C function that sorts an array of integers in ascending order using the Merge Sort algorithm.
  * Implements the `top-down` Merge Sort algorithm.
    * When an array is divided, the size of the left subarray is always less than or equal to the size of the right subarray.
    * Always sorts the left subarray before the right one.
  * Prints subarrays each time they are merged.
  * [103-O](./103-O): Text file containing the best, average, and worst case time complexities of the Merge Sort algorithm, one per line.

* **8. Heap sort**
  * [104-heap_sort.c](./104-heap_sort.c): C function that sorts an array of integers in ascending order using the Heap Sort algorithm.
  * Implements the `sift-down` Heap Sort algorithm.
  * Prints the array after each swap.
  * [104-O](./104-O): Text file containing the best, average, and worst case time complexiites of the Heap Sort algorithm, one per line.

* **9. Radix sort**
  * [105-radix_sort.c](./105-radix_sort.c): C function that sorts an array of integers in ascending order using the Radix Sort algorithm.
  * Implements the Least-Significant-Digit (LSD) Radix Sort algorithm.
  * Assumes that the array will only contain numbers `>= 0`.
  * Prints the array for each significant digit increase.
  * [105-O](./105-O): Text file containing the best, average, and worst case time complexities of the Radix Sort algorithm, one per line.

* **10. Bitonic sort**
  * [106-bitonic_sort.c](./106-bitonic_sort.c): C function that sorts an array of integers in ascending order using the Bitonic Sort algorithm.
  * Assumes that `size` is a power of 2 (ie. `size` can be expressed as `2^k` where `k >= 0`).
  * Prints subarrays each time they are merged.
  * [106-O](./106-O): Text file containing the best, average, and worst case time complexities of the Bitonic Sort algorithm, one per line.

* **11. Quick Sort - Hoare Partition scheme**
  * [107-quick_sort_hoare.c](./107-quick_sort_hoare.c): C function that sorts an array of integers in ascending order using the Quick Sort algorithm.
  * Implements the Hoare partition scheme.
  * Always uses the last elemement of the partition being sorted as the pivot.
  * Prints the array after each swap.
  * [107-O](./107-O): Text file containing the best, average, and worst case time complexities of the Quick Sort Hoare Partition cheme algorithm, one per line.

* **12. Dealer**
  * [1000-sort_deck.c](./1000-sort_deck.c): C function that sorts a `deck_node_t` doubly-linked list deck of cards.
  * Assumes that there are exactly `52` elements in the doubly-linked list.
  * Orders the deck from spades to diamonds and from aces to kings.
