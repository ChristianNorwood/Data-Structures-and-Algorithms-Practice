template<typename T> 
class SortingAlgorithms {
    public:

        // Time Complexity - O(n^2)
        // Space Complexity - O(1)
        void bubbleSort(auto&& n) {
            for (size_t i = std::size(n); i > 0; i--) {
                for (size_t j = 1; j < i; j++) {
                    if (n[j] < n[j-1]) {
                        int tmp = n[j-1];
                        n[j-1] = n[j]
                        n[j] = tmp
                    }
                }
            }
        }

        // Time Complexity - O(n^2)
        // Space Complexity - O(1)
        void selectionSort(auto&& n) {
            for (size_t i = 0; i < std::size(n); i++) {
                auto minIdx = i
                for (size_t j = i; j < std::size(n); j++) {
                    if (n[j] < n[minIdx]){
                       minIdx = j;
                    }
                }
                auto tmp = n[i];
                n[i] = n[minIdx];
                n[minIdx] = n[tmp];
            }
        }

        // Time Complexity - O(n^2)
        // Space Complexity - O(1)
        void insertionSort(auto&& n) {
            for (size_t i = 1, i < std::size(n); i++) {  // This starts at 1, because if the array is 1 element long, its already sorted, so we start at element 2
                auto elementToInsert = n[i];    // Selecting the element that we want to insert
                int scanningIdx = i - 1;        // This is the scanning element. We want to compare this against our element to insert. Needs to be int 
                                                // because when it hits a negative number, thats how we know we hit the end of our search

                // Two conditions. 1. Scanning Index hasnt gone past its search area, and 2. the search stop when we reach a number that is less than the insertion element
                while (scanningIdx >= 0 && n[scanningIdx] > elementToInsert) { 
                    n[scanningIdx + 1] = n[scanningIdx];    // shifts the scanning element to the right, if it is greater than the insertion element
                    scanningIdx--;                  // moves the scanner to the left to check the next value
                }
                // Once we either reach the end of the array, or we find an element that is less than our insertion element, we insert that element to the right of our scanner and start over
                n[scanningIdx+1] = elementToInsert;

            }
        }






        // Merge Sorting
////////////////////////////////////////////////////////////////////////////////////////
        void merge(auto& n, int left, int mid, int right){
            std::vector<int> tmp;           // temp buff to put the sorted elements into
            int i = left, j = mid+1;        // two halves of teh 'sub-array'

            while(i <= mid && j <= right) { // continues as long as the left pointer hasnt reached the second element, and the right pointer hasnt gone off the deep end
                if (n[i] <= n[j]) {
                    tmp.push_back(n[i++]);  // a bit confusing, but basically this is looking and saying, "if left is less than right, put it in the temp array, and move the pointer to the right element after"
                } else {                    // which if the left pointer has been moved to the right, that would disatisfy one of the while requirements, kicking us out
                    tmp.push_back(n[j++]);  // Kind of the same concept as above, moves the pointer out of bounds which would kick us out
                }
            }

            // So, the first while loop up there, is doing the heavy lifting between the sorting. its easy to think of how it works with the two element merges, but
            // lets imagine you have two 'sub-arrays' that you are working on that arent even: [1,3,5,6,7,8] and [2,4]. the function above will sort: [1,2,3,4] 
            // but then you have an array with [5,6,7,8] left over. This handles that where it just tosses them on the end.
            while(i <= mid) {
                tmp.push_back(n[i++]);
            }

            while (j <= right) {
                tmp.push_back(n[j++]);
            }

            for (int k = 0; k < tmp.size(); k++) {
                n[left + k] = tmp[k];               // For loop takes all the values of the tmp, and just tosses them back onto the array
            }

        }
        // 




        // Time Complexity - O(n log(n))
        void mergeSort(auto& n, int left, int right) {
            if (left >= right) {return;}                // So, this line right here basically just looks at right and left. If left index is 0, and right index is 0, that means only one element
            int mid = left + (right-left)/2;        // this finds the mid, but is safe against possible overflows if both numbers are huge. 

            mergeSort(n, left, mid);            // sorting left half (which will recursively sort the left half again until it hits 1 elements)
            mergeSort(n, mid+1, right);         // same for right half, using mid+1 cuz yeah
            merge(n, left, mid, right);
        }
        // general idea of how to look at this: when it hits that first mergeSort, it is going to continuously recursively call until it hits a single element 
        // (which is where that if statement above comes in). Then it will pass to the next mergeSort, which returns the second element of the two element 'sub-array'
        // Remember, all of those previous mergeSort calls are still up on the callstack (including when the array was whole), we are just currently going to operate 
        // on those first two elements. Now that we have those two elements, and we have passed the two mergesorts, we go to merge.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////





        // Quick Sort
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        int partition(auto& n, int left, int right) {
            int pivot = n[right];
            int i = left-1;

            for (int j = left; j < right; j++) {
                if (n[j] <= pivot) {
                    i++;
                    std::swap(n[i], n[j]);
                }
            }

            std::swap(n[n+1], n[right]);
            return i+1;
        }

        void quickSort(auto& n, int left, int right) {
            if (left >= right) return;
            int pivotIdx = partition(n, left, right);
            quickSort(n, left, pivotIdx-1);
            quickSort(n, pivotIdx+1, right);
        }
};



// Answer the following questions by which sorting algorithm to use:


// 1. Sort 10 schools around your house by distance: 
// A: Insertion Sort
// Correct Answer: Insertion Sort

// 2. eBay sorts listings by the current Bid amount: 
// A: IDK
// Correct Answer: Radix / Counting (because strictly fixed length numbers/integers)


// 3. Sport scores on ESPN: 
// A: IDK
// Correct Answer: Quick Sort (Because there is a worry about in memory storing, quick sort has better space complexity than merge sort)


// 4. Massive database (can't fit all into memory) needs to sort through past year's user data: 
// A: Merge Sort
// Correct Answer: Merge Sort


// 5. Almost sorted Udemy review data needs to update and add 2 new reviews: 
// A: IDK
// Correct Answer: Insertion Sort


// 6. Temperature records for the past 50 years: 
// A: IDK
// Correct Answer: If no decimal places: Radix/Counting, if decimal places: Quick Sort



// 7. Large user name database needs to be sorted. Data is very random: 
// A: IDK
// Correct Answer: Merge Sort or Quick Sort depending on memory size


// 8. You want to teach sorting for the first time: 
// A: Bubble Sort
// Correct Answer: Bubble Sort/Selection Sort