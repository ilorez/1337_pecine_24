#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype of the ft_split function
char **ft_split(char *str, char *charset);

// Utility function to compare arrays of strings
int compare_string_arrays(char **arr1, char **arr2) {
    if (arr1 == NULL && arr2 == NULL) {
        return 1;
    }
    if (arr1 == NULL || arr2 == NULL) {
        return 0;
    }
    int i = 0;
    while (arr1[i] && arr2[i]) {
        if (strcmp(arr1[i], arr2[i]) != 0) {
            return 0;
        }
        i++;
    }
    // Both arrays should have ended at the same point
    if (arr1[i] == NULL && arr2[i] == NULL) {
        return 1;
    }
    return 0;
}

// Utility function to free memory allocated for string arrays
void free_string_array(char **arr) {
    if (arr) {
        int i = 0;
        while (arr[i]) {
            free(arr[i]);
            i++;
        }
        free(arr);
    }
}

// Tester function to test the ft_split function
void test_ft_split(char *str, char *charset, char **expected) {
    char **result = ft_split(str, charset);
    if (compare_string_arrays(result, expected)) {
        printf("Test passed for input \"%s\" with charset \"%s\"\n", str, charset);
    } else {
        printf("Test failed for input \"%s\" with charset \"%s\"\n", str, charset);
    }
    // Free memory allocated for result
    free_string_array(result);
}

int main() {
    // Test cases with expected values
    char *str1 = "abc:def,ghi";
    char *charset1 = ":,";
    char *expected1[] = {"abc", "def", "ghi", NULL};
    test_ft_split(str1, charset1, expected1);

    char *str2 = "::,,:::";
    char *charset2 = ":,";
    char *expected2[] = {NULL};
    test_ft_split(str2, charset2, expected2);

    char *str3 = ",abc,def,ghi,";
    char *charset3 = ",";
    char *expected3[] = {"abc", "def", "ghi", NULL};
    test_ft_split(str3, charset3, expected3);

    char *str4 = "abc,,def,,ghi";
    char *charset4 = ",";
    char *expected4[] = {"abc", "def", "ghi", NULL};
    test_ft_split(str4, charset4, expected4);

    char *str5 = "abcdefghi";
    char *charset5 = ",";
    char *expected5[] = {"abcdefghi", NULL};
    test_ft_split(str5, charset5, expected5);

    char *str6 = "";
    char *charset6 = ":,";
    char *expected6[] = {NULL};
    test_ft_split(str6, charset6, expected6);

    return 0;
}
