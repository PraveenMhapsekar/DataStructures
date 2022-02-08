Given an array of lowercase letters sorted in ascending order, find the smallest letter in the given array greater than a given ‘key’.


The problem follows the Binary Search pattern. Since Binary Search helps us find an element in a sorted array efficiently, we can use a modified version of it to find the next letter.

We can use a similar approach as discussed in Ceiling of a Number. There are a couple of differences though:

The array is considered circular, which means if the ‘key’ is bigger than the last letter of the array or if it is smaller than the first letter of the array, the key’s next letter will be the first letter of the array.
The other difference is that we have to find the next biggest letter which can’t be equal to the ‘key’. This means that we will ignore the case where key == arr[middle]. To handle this case, we can update our start range to start = middle +1.

