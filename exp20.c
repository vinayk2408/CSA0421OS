#include <stdio.h>
#include <string.h>

struct UserDir {
    char user[20];
    char files[20][20];
    int fileCount;
};

int main() {
    struct UserDir dirs[10];
    int userCount = 0, choice;
    char uname[20], fname[20];

    while (1) {
        printf("\n1.Create User  2.Create File  3.List Files");
        printf("  4.Search File  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter user name: ");
            scanf("%s", uname);
            int exists = 0;
            for (int i = 0; i < userCount; i++)
                if (strcmp(dirs[i].user, uname) == 0)
                    exists = 1;
            if (exists)
                printf("User already exists.\n");
            else {
                strcpy(dirs[userCount].user, uname);
                dirs[userCount].fileCount = 0;
                userCount++;
                printf("User directory created.\n");
            }
        }

        else if (choice == 2) {
            printf("Enter user name: ");
            scanf("%s", uname);
            int u = -1;
            for (int i = 0; i < userCount; i++)
                if (strcmp(dirs[i].user, uname) == 0)
                    u = i;
            if (u == -1) {
                printf("User not found.\n");
                continue;
            }
            printf("Enter file name to create: ");
            scanf("%s", fname);
            strcpy(dirs[u].files[dirs[u].fileCount++], fname);
            printf("File created under user %s.\n", uname);
        }

        else if (choice == 3) {
            printf("Enter user name: ");
            scanf("%s", uname);
            int u = -1;
            for (int i = 0; i < userCount; i++)
                if (strcmp(dirs[i].user, uname) == 0)
                    u = i;
            if (u == -1) {
                printf("User not found.\n");
                continue;
            }
            printf("Files of user %s:\n", dirs[u].user);
            for (int i = 0; i < dirs[u].fileCount; i++)
                printf("%s\n", dirs[u].files[i]);
            if (dirs[u].fileCount == 0) printf("(no files)\n");
        }

        else if (choice == 4) {
            printf("Enter user name: ");
            scanf("%s", uname);
            printf("Enter file name to search: ");
            scanf("%s", fname);

            int u = -1, found = 0;
            for (int i = 0; i < userCount; i++)
                if (strcmp(dirs[i].user, uname) == 0)
                    u = i;

            if (u == -1) {
                printf("User not found.\n");
                continue;
            }

            for (int i = 0; i < dirs[u].fileCount; i++)
                if (strcmp(dirs[u].files[i], fname) == 0)
                    found = 1;

            if (found) printf("File found in user %s.\n", uname);
            else       printf("File not found.\n");
        }

        else if (choice == 5) {
            return 0;
        }
    }
}
