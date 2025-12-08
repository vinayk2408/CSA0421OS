#include <stdio.h>
#include <string.h>

int main() {
    char files[20][20];
    int n = 0, choice;
    char name[20];

    while (1) {
        printf("\n1.Create  2.Delete  3.Search  4.List  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name to create: ");
            scanf("%s", name);
            int exists = 0;
            for (int i = 0; i < n; i++)
                if (strcmp(files[i], name) == 0)
                    exists = 1;
            if (exists)
                printf("File already exists.\n");
            else {
                strcpy(files[n++], name);
                printf("File created.\n");
            }
            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", name);
            exists = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(files[i], name) == 0) {
                    exists = 1;
                    for (int j = i; j < n-1; j++)
                        strcpy(files[j], files[j+1]);
                    n--;
                    printf("File deleted.\n");
                    break;
                }
            }
            if (!exists) printf("File not found.\n");
            break;

        case 3:
            printf("Enter file name to search: ");
            scanf("%s", name);
            exists = 0;
            for (int i = 0; i < n; i++)
                if (strcmp(files[i], name) == 0)
                    exists = 1;
            if (exists) printf("File found.\n");
            else       printf("File not found.\n");
            break;

        case 4:
            printf("Files in directory:\n");
            for (int i = 0; i < n; i++)
                printf("%s\n", files[i]);
            if (n == 0) printf("(empty)\n");
            break;

        case 5:
            return 0;
        }
    }
}
