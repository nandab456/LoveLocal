#include<stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str, int len) {
    int i = 0;
    int j = len - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    return 1; // Palindrome
}

// Function to find the shortest palindrome by adding characters in front of the string
char* shortestPalindrome(char *s) {
    int len = strlen(s);
    int i;

    // Find the longest palindrome substring starting from the beginning
    for (i = len; i >= 0; i--) {
        if (isPalindrome(s, i)) {
            break;
        }
    }

    char *result = (char *)malloc(sizeof(char) * (2 * len - i + 1));
   
    // Reverse the remaining part and append it to the beginning
    int k = 0;
    for (int j = len - 1; j >= i; j--) {
        result[k++] = s[j];
    }
    for (int j = 0; j < len; j++) {
        result[k++] = s[j];
    }
    result[k] = '\0';

    return result;
}

int main() {
    char input_from_user[100];
    scanf("%[^\n]%*c",input_from_user);

    printf("%s\n",shortestPalindrome(input_from_user));

    return 0;
}
