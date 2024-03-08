#include <stdio.h>

#define PAGE_TABLE_SIZE 3

void printPageTable(int pageTable[], int size) {
	int i;
    printf("Page Table: ");
    for (i = 0; i < size; ++i) {
        if (pageTable[i] == -1) {
            printf("[ ] ");
        } else {
            printf("[%d] ", pageTable[i]);
        }
    }
    printf("\n");
}

int isPageInTable(int pageTable[], int size, int page) {
	int i;
    for ( i = 0; i < size; ++i) {
        if (pageTable[i] == page) {
            return 1; // Page found in the table
        }
    }
    return 0; // Page not found in the table
}

void fifoPageReplacement(int pageRequests[], int numRequests) {
    int pageTable[PAGE_TABLE_SIZE];
    int pageTableIndex = 0;
    int i;
    // Initialize page table with -1 (indicating an empty slot)
    for (i = 0; i < PAGE_TABLE_SIZE; ++i) {
        pageTable[i] = -1;
    }
    for (i = 0; i < numRequests; ++i) {
        int currentPage = pageRequests[i];

        // Check if the page is already in the page table
        if (!isPageInTable(pageTable, PAGE_TABLE_SIZE, currentPage)) {
            // Page fault: replace the oldest page in the page table
            printf("Page %d caused a page fault.\n", currentPage);
            printf("Replacing page %d.\n", pageTable[pageTableIndex]);

            // Replace the oldest page with the current page
            pageTable[pageTableIndex] = currentPage;

            // Move the page table index to the next slot (circular)
            pageTableIndex = (pageTableIndex + 1) % PAGE_TABLE_SIZE;

            // Print the updated page table
            printPageTable(pageTable, PAGE_TABLE_SIZE);
        } else {
            // Page hit: page is already in the page table
            printf("Page %d is already in the page table. No page fault.\n", currentPage);
            printPageTable(pageTable, PAGE_TABLE_SIZE);
        }
    }
}

int main() {
    // Example sequence of page requests
    int pageRequests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    int numRequests = sizeof(pageRequests) / sizeof(pageRequests[0]);

    // Simulate FIFO page replacement algorithm
    fifoPageReplacement(pageRequests, numRequests);

    return 0;
}

