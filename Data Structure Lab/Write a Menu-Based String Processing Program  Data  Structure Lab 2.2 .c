#include <stdio.h>
#include <stdlib.h>
int Strlen(char *str)
{
    int l = 0;
    while (str[l] != '\0')
    {
        l++;
    }
    return l;
}

int isSubstring(char *str, char *sub)
{
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; sub[j] != '\0'; j++)
        {
            if (str[i + j] != sub[j])
            {
                break;
            }
        }
        if (sub[j] == '\0')
        {
            return i;
        }
    }
    return -1;
}

void myStrcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


void insertSubstring(char *mainStr, char *subStr, int pos)
{
    char result[200];
    int i, j = 0, k = 0;

    for (i = 0; i < pos; i++)
    {
        result[i] = mainStr[i];
    }
    while (subStr[j] != '\0')
    {
        result[i++] = subStr[j++];
    }
    while (mainStr[pos + k] != '\0')
    {
        result[i++] = mainStr[pos + k++];
    }
    result[i] = '\0';

    myStrcpy(mainStr, result);
}


void deleteSubstring(char *mainStr, char *subStr)
{
    int index = isSubstring(mainStr, subStr);
    if (index == -1) return;

    int i;
    for (i = index; mainStr[i + Strlen(subStr)] != '\0'; i++)
    {
        mainStr[i] = mainStr[i + Strlen(subStr)];
    }
    mainStr[i] = '\0';
}

void replaceSubstring(char *mainStr, char *oldSub, char *newSub)
{
    char result[300];
    int i = 0, j = 0, index = isSubstring(mainStr, oldSub);

    if (index == -1)
    {
        return;
    }

    while (i < index)
    {

        result[i++] = mainStr[j++];
    }

    j += Strlen(oldSub);

    int k = 0;
    while (newSub[k] != '\0')
    {
        result[i++] = newSub[k++];
    }

    while (mainStr[j] != '\0')
    {
        result[i++] = mainStr[j++];
    }

    result[i] = '\0';

    myStrcpy(mainStr, result);
}

void readString(char *str, int size)
{
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < size - 1)
    {
        str[i++] = c;
    }
    str[i] = '\0';
}

int main()
{
    char Str1[100],  subStri[50], subStrd[50], oldSub[50], newSub[50];
    int choice, pos;

    while (1)
    {

        printf("1. Input a String\n");
        printf("2. Insert a Sub-string\n");
        printf("3. Delete a Sub-string\n");
        printf("4. Replace a Sub-string\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter a string: ");
            readString(Str1, sizeof(Str1));
            break;



        case 2:
            printf("Enter substring to insert: ");
            readString(subStri, sizeof(subStri));
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertSubstring(Str1, subStri, pos);
            printf("Updated String: %s\n", Str1);
            break;

        case 3:
            printf("Enter substring to delete: ");
            readString(subStrd, sizeof(subStrd));
            deleteSubstring(Str1, subStrd);
            printf("Updated String: %s\n", Str1);
            break;

        case 4:
            printf("Enter substring to replace: ");
            readString(oldSub, sizeof(oldSub));
            printf("Enter new substring: ");
            readString(newSub, sizeof(newSub));
            replaceSubstring(Str1, oldSub, newSub);
            printf("Updated String: %s\n", Str1);
            break;

        case 0:
            exit(0);
        }
    }
    return 0;
}
