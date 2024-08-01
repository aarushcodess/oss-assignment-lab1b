#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

void to_lowercase(char *str) {
    for (; *str; str++) {
        *str = tolower(*str);
    }
}

int find_word(WordFreq words[], int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char paragraph[1000];
    WordFreq words[MAX_WORDS];
    int word_count = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " ,.-\n");
    while (token != NULL) {
        to_lowercase(token);
        int index = find_word(words, word_count, token);
        if (index >= 0) {
            words[index].count++;
        } else {
            strcpy(words[word_count].word, token);
            words[word_count].count = 1;
            word_count++;
        }
        token = strtok(NULL, " ,.-\n");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
