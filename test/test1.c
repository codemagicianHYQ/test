#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isInDictionary(char *str, char **dictionary, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(str, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int minExtraChar(char *s, char **dictionary, int dictSize) {
    int len = strlen(s);
    int dp[len + 1];
    dp[0] = 0;

    for (int i = 1; i <= len; i++) {
        dp[i] = dp[i - 1] + 1;

        for (int j = 0; j < i; j++) {
            if (isInDictionary(s + j, dictionary, dictSize)) {
                dp[i] = (dp[i] < dp[j]) ? dp[i] : dp[j];
            }
        }
    }

    return dp[len];
}

int main() {
    char *s1 = "leetscode";
    char *dictionary1[] = {"leet", "code", "leetcode"};
    int dictSize1 = 3;
    printf("%d\n", minExtraChar(s1, dictionary1, dictSize1));

    char *s2 = "sayhelloworld";
    char *dictionary2[] = {"hello", "world"};
    int dictSize2 = 2;
    printf("%d\n", minExtraChar(s2, dictionary2, dictSize2));

    return 0;
}
