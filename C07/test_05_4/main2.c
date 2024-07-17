#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ft_split(char *str, char *charset);

void run_test(char *str, char *charset, char **expected)
{
    char **result;
    int i = 0;

    printf("Test case:\n");
    printf("Input string: \"%s\"\n", str);
    printf("Charset: \"%s\"\n", charset);

    result = ft_split(str, charset);

    printf("Expected output:\n");
    for (i = 0; expected[i] != NULL; i++)
    {
        printf("  [%d]: \"%s\"\n", i, expected[i]);
    }

    printf("Actual output:\n");
    if (result == NULL)
    {
        printf("  ft_split returned NULL\n");
    }
    else
    {
        for (i = 0; result[i] != NULL; i++)
        {
            printf("  [%d]: \"%s\"\n", i, result[i]);
        }
    }

    // Free the allocated memory
    if (result != NULL)
    {
        for (i = 0; result[i] != NULL; i++)
        {
            free(result[i]);
        }
        free(result);
    }

    printf("\n");
}

int main()
{
    // Test case 1: Basic splitting
    char *test1 = "Hello,world!How are:you;today?";
    char *charset1 = ",!:;?";
    char *expected1[] = {"Hello", "world", "How are", "you", "today", NULL};
    run_test(test1, charset1, expected1);

    char *test6 = "apple,banana;cherry:date grape";
    char *charset6 = ",;: ";
    char *expected6[] = {"apple", "banana", "cherry", "date", "grape", NULL};
    run_test(test6, charset6, expected6);

    // Test case 2: Empty string
    char *test2 = "";
    char *charset2 = ",";
    char *expected2[] = {NULL};
    run_test(test2, charset2, expected2);

    // Test case 3: No delimiters in string
    char *test3 = "Hello world";
    char *charset3 = ",";
    char *expected3[] = {"Hello world", NULL};
    run_test(test3, charset3, expected3);

    // Test case 4: String is only delimiters
    char *test4 = ",,,,";
    char *charset4 = ",";
    char *expected4[] = {NULL};
    run_test(test4, charset4, expected4);

    // Test case 5: Multiple consecutive delimiters
    char *test5 = "One,,Two,,,Three";
    char *charset5 = ",";
    char *expected5[] = {"One", "Two", "Three", NULL};
    run_test(test5, charset5, expected5);

    // Test case 6: Different types of delimiters

    return 0;
}
