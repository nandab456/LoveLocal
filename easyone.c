#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;//to find the index of the last letter

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Calculate the length of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char input_from_user[105];
    //taking input from user
    scanf("%[^\n]%*c",input_from_user);
    printf("%d\n", lengthOfLastWord(input_from_user));  

    return 0;
}
