#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_SIZE 1000
#define MAX_WORDS 500
#define MAX_WORD_LENGTH 50

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char paragraph[MAX_PARAGRAPH_SIZE];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Remove newline if present
    size_t len = strlen(paragraph);
    if (len > 0 && paragraph[len - 1] == '\n') {
        paragraph[len - 1] = '\0';
    }

    // Tokenize paragraph into words using space and punctuation as delimiters
    const char *delimiters = " ,.-!?\t\n;:\"()[]{}";
    char *token = strtok(paragraph, delimiters);

    while (token != NULL) {
        toLowerCase(token);

        // Check if word already exists in words array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // If word not found, add it to the array
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], token);
            freq[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, delimiters);
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
