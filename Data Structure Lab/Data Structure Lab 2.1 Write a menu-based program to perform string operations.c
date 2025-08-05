
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

int myStrcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}


void myStrcat(char *dest, char *src)
{
    int i = 0, j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
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


void substring(char *orig, char *substr, int index, int length)
{
    int i = 0;
    while (i < length && orig[index + i] != '\0')
    {
        substr[i] = orig[index + i];
        i++;
    }
    substr[i] = '\0';
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
    char Str1[100], Str2[100], Str3[100], part_num[100];
    int choice, st, nofc, index;

    while (1)
    {
        printf("1. Input a String\n");
        printf("2. Length of the String\n");
        printf("3. Sub-string of the String\n");
        printf("4. Compare Two Strings\n");
        printf("5. Concatenation of Two Strings\n");
        printf("6. Indexing\n");
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
            printf("The length of the string is: %d\n", Strlen(Str1));
            break;

        case 3:
            printf("Enter start index: ");
            scanf("%d", &st);
            printf("Enter number of characters: ");
            scanf("%d", &nofc);
            substring(Str1, part_num, st, nofc);
            printf("Sub-string: %s\n", part_num);
            break;

        case 4:
            printf("Enter second string: ");
            readString(Str2, sizeof(Str2));
            if (myStrcmp(Str1, Str2) == 0)
                printf("The two strings are the same.\n");
            else
                printf("The two strings are different.\n");
            break;

        case 5:
            printf("Enter a string to add: ");
            readString(Str2, sizeof(Str2));
            myStrcat(Str1, Str2);
            printf("Concatenated String: %s\n", Str1);
            break;

        case 6:
            printf("Enter substring to find: ");
            readString(Str3, sizeof(Str3));
            index = isSubstring(Str1, Str3);
            if (index != -1)
                printf("Substring found at index: %d\n", index);
            else
                printf("Substring not found.\n");
            break;

        case 0:
            exit(0);
        }
    }
    return 0;
}
