#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct file {
    int fileID;
    int fileSize;
};


void swap(file* a, file* b) {
    file temp = *a;
    *a = *b;
    *b = temp;
}


void quickSortFiles(file* array, int start, int end) {
    if (start < end) {
        int pivot = array[end].fileSize;
        int i = start - 1; // smaller element index

        for (int j = start; j < end; j++) {
            // If current element is smaller than or
            // equal to pivot
            if (array[j].fileSize <= pivot) {
                i++;    // increment index of smaller element
                swap(&array[i], &array[j]);

            }

        }
        swap(&array[i + 1], &array[end]);

        int partIndex = i + 1;
        // separately sort elements before
        // partition and after partition
        quickSortFiles(array, start, partIndex - 1);
        quickSortFiles(array, partIndex + 1, end);

    }
}


void quickSortOutput(file* array, int start, int end) {
    if (start < end) {
        int pivot = array[end].fileID;
        int i = start - 1; // smaller element index

        for (int j = start; j < end; j++) {
            // If current element is greater than or
            // equal to pivot
            if (array[j].fileID >= pivot) {
                i++;    // increment index of smaller element
                swap(&array[i], &array[j]);

            }

        }
        swap(&array[i + 1], &array[end]);

        int partIndex = i + 1;
        // separately sort elements before
        // partition and after partition
        quickSortOutput(array, start, partIndex - 1);
        quickSortOutput(array, partIndex + 1, end);

    }
}


bool copyNextFile(file* pendrive, file file, int pendrSize) {
    if (file.fileSize <= pendrSize) {
        *pendrive = file;
        return true;

    }
    else
        return false;
}


void writeIDs(file* pendrive, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", pendrive[i].fileID);

    }
    printf("\n");
}


int main() {
    int filesN, pendrSize1, pendrSize2;
    scanf("%d %d", &filesN, &pendrSize1);
    pendrSize2 = pendrSize1;

    file* fileArr = new file[filesN];

    for (int i = 0; i < filesN; i++) {
        scanf("%d %d", &fileArr[i].fileID, &fileArr[i].fileSize);

    }

    quickSortFiles(fileArr, 0, filesN - 1);

    file* pendrive1 = new file[filesN / 2 + 1];
    file* pendrive2 = new file[filesN / 2];

    int n1 = 0, n2 = 0; // number of files written on pendrives 1 and 2

    for (int i = 0; i < filesN - 1; i += 2) {
        if (copyNextFile(&pendrive1[n1], fileArr[i], pendrSize1)) {
            n1++;
            pendrSize1 -= fileArr[i].fileSize;

        }

        if (copyNextFile(&pendrive2[n2], fileArr[i + 1], pendrSize2)) {
            n2++;
            pendrSize2 -= fileArr[i + 1].fileSize;

        }
        else { // maybe there's free space on pendr1, we've copied smaller files there
            if (copyNextFile(&pendrive1[n1], fileArr[i + 1], pendrSize1)) {
                n1++;
                pendrSize1 -= fileArr[i + 1].fileSize;

            }

        }

    }

    quickSortOutput(pendrive1, 0, n1 - 1);
    quickSortOutput(pendrive2, 0, n2 - 1);

    printf("%d\n", n1 + n2);
    printf("1: ");
    writeIDs(pendrive1, n1);
    printf("2: ");
    writeIDs(pendrive2, n2);

    delete[] fileArr;
    delete[] pendrive1;
    delete[] pendrive2;
    return 0;
}