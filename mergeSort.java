
// for all best avg and worst->o(nlogn)
import java.util.Scanner;

class MergeSort {

  // Merge the two halves: [start..mid] and [mid+1..end]
  void merge(int[] array, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int[] leftArray = new int[leftSize];
    int[] rightArray = new int[rightSize];

    // Copy the left half: from start to mid
    for (int i = 0; i < leftSize; i++)
      leftArray[i] = array[start + i];

    // Copy the right half: from mid+1 to end
    for (int j = 0; j < rightSize; j++)
      rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = start;

    // Merge the two halves into the main array
    while (i < leftSize && j < rightSize) {
      if (leftArray[i] <= rightArray[j]) {
        array[k++] = leftArray[i++];
      } else {
        array[k++] = rightArray[j++];
      }
    }

    // Copy remaining elements of leftArray
    while (i < leftSize) {
      array[k++] = leftArray[i++];
    }

    // Copy remaining elements of rightArray
    while (j < rightSize) {
      array[k++] = rightArray[j++];
    }
  }

  // Divide the array into halves and sort each part
  void divide(int[] array, int start, int end) {
    if (start < end) {
      int mid = (start + end) / 2;

      // Sort the first half: from start to mid
      divide(array, start, mid); // left

      // Sort the second half: from mid+1 to end
      divide(array, mid + 1, end);// right

      // Merge the sorted halves
      merge(array, start, mid, end);// call merge
    }
  }

  static void printArray(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter the number of elements: ");
    int size = scanner.nextInt();

    int[] array = new int[size];
    System.out.println("Enter the elements:");
    for (int i = 0; i < size; i++) {
      array[i] = scanner.nextInt();
    }

    MergeSort sorter = new MergeSort();
    sorter.divide(array, 0, array.length - 1);// question is that why merge not call
    // because in divide function we already call merge f

    System.out.println("Sorted array:");
    printArray(array);

    scanner.close();
  }
}

