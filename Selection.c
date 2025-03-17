#include <stdio.h>
#include <time.h>
#include <stdlib.h>  /* To recognize exit function when compiling with gcc */

// Function to perform Selection Sort
void selsort(int n, int a[]);

int main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while(1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for(i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                selsort(n, a);  // Call Selection Sort
                end = clock();
                printf("\nSorted array is: ");
                for(i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;

            case 2:
                n = 500;
                while(n <= 14500) {
                    for(i = 0; i < n; i++) {
                        a[i] = n - i;  // Generate a descending array (worst-case for Selection Sort)
                    }
                    start = clock();
                    selsort(n, a);  // Call Selection Sort

                    // Dummy loop to create delay
                    for(j = 0; j < 500000; j++) {
                        temp = 38 / 600;  // This line doesn't do anything, just creates a delay
                    }

                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n = n + 1000;
                }
                break;

            case 3:
                exit(0);  // Exit the program
        }

        // Remove unnecessary getchar() as it might cause unwanted behavior
    }

    return 0;  // Return 0 to indicate successful program execution
}

// Selection Sort function
void selsort(int n, int a[]) {
    int i, j, t, small, pos;
    for(i = 0; i < n - 1; i++) {
        pos = i;
        small = a[i];
        for(j = i + 1; j < n; j++) {
            if(a[j] < small) {
                small = a[j];
                pos = j;
            }
        }
        t = a[i];
        a[i] = a[pos];
        a[pos] = t;
    }
}
