#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define ENG_ALPHA_COUNT 26

typedef struct _trie_node {
    struct _trie_node *node[ENG_ALPHA_COUNT];
    bool is_word;
} trie_node;

int8_t get_index(const char c);
void put_word(trie_node *tn, char *word);
bool has_word(trie_node *tn, char *word);
char **get_word_completions(trie_node *tn, char *prefix);
trie_node *create();
void destroy(trie_node *tn);

int main(int argc, char **argv) {
    trie_node *tn = create();

    put_word(tn, "purple");
    put_word(tn, "red");
    put_word(tn, "Blue");
    put_word(tn, "yellow");
    put_word(tn, "CYAN");
    put_word(tn, "zzzzzZZzzZZz");
    put_word(tn, "zzzzzZZz");

    printf("%d\n", has_word(tn, "purple"));
    printf("%d\n", has_word(tn, "magenta"));
    printf("%d\n", has_word(tn, "cyan"));
    printf("%d\n", has_word(tn, "red"));
    printf("%d\n", has_word(tn, "orange"));
    printf("%d\n", has_word(tn, "green"));
    printf("%d\n", has_word(tn, "z"));
    printf("%d\n", has_word(tn, "Z"));
    printf("%d\n", has_word(tn, "zzzzzZZ"));
    printf("%d\n", has_word(tn, "zzzzzZZzzZZz"));
    printf("%d\n", has_word(tn, "zzzzzZZz"));

    destroy(tn);
}

int8_t get_index(const char c) {
    return tolower(c) - 97;
}

void put_word(trie_node *tn, char *word) {
    if (*word == '\0') {
        tn -> is_word = true;
        return;
    }

    int8_t index = get_index(*word);
    if (tn -> node[index] == NULL)
        tn -> node[index] = create();
    put_word(tn -> node[index], word + 1);
}

bool has_word(trie_node *tn, char *word) {
    if (*word == '\0' && tn -> is_word)
        return true;

    int8_t index = get_index(*word);
    if (tn -> node[index] == NULL)
        return false;
    return has_word(tn -> node[index], word + 1);
}

trie_node *create() {
    trie_node *tn = malloc(sizeof(*tn));
    for (int i = 0; i < ENG_ALPHA_COUNT; i++) {
        tn -> node[i] = NULL;
    }
    tn -> is_word = false;
    return tn;
}

void destroy(trie_node *tn) {
    for (int i = 0; i < ENG_ALPHA_COUNT; i++) {
        if (tn -> node[i] != NULL) {
            destroy(tn -> node[i]);
            tn -> node[i] = NULL;
        }
    }
    tn -> is_word = false;
    free(tn);
}

