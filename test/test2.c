#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char emails[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int emailCount;
} Account;

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    Account accounts[MAX_ACCOUNTS] = {
        {"Gabe", {"Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"}, 3},
        {"Kevin", {"Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"}, 3},
        {"Ethan", {"Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"}, 3},
        {"Hanzo", {"Hanzo3@m.co", "Hanzo0@m.co", "Hanzo1@m.co"}, 3},
        {"Fern", {"Fern5@m.co", "Fern0@m.co", "Fern1@m.co"}, 3}
    };
    int accountCount = 5;

    int parent[MAX_EMAILS];
    int rank[MAX_EMAILS] = {0};
    char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int emailIndex = 0;

    for (int i = 0; i < accountCount; i++) {
        for (int j = 0; j < accounts[i].emailCount; j++) {
            strcpy(emailList[emailIndex], accounts[i].emails[j]);
            parent[emailIndex] = emailIndex;
            emailIndex++;
        }
    }

    for (int i = 0; i < accountCount; i++) {
        int firstEmailIndex = -1;
        for (int j = 0; j < emailIndex; j++) {
            if (strcmp(emailList[j], accounts[i].emails[0]) == 0) {
                firstEmailIndex = j;
                break;
            }
        }
        for (int j = 1; j < accounts[i].emailCount; j++) {
            int currentEmailIndex = -1;
            for (int k = 0; k < emailIndex; k++) {
                if (strcmp(emailList[k], accounts[i].emails[j]) == 0) {
                    currentEmailIndex = k;
                    break;
                }
            }
            unionSets(parent, rank, firstEmailIndex, currentEmailIndex);
        }
    }

    for (int i = 0; i < emailIndex; i++) {
        int root = find(parent, i);
        printf("%s -> %s\n", emailList[i], emailList[root]);
    }

    return 0;
}