#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 0  - 9  for digits
// 10 - 35 for english alphabets
// 36      for whitespace
#define MAX_TRIE_SUPPORTED_CHARS 37
#define OFFSET_ALPHAS 26
#define OFFSET_NUMS 10

#define ASCII_LC_A_OFFSET 97
#define ASCII_NUM_OFFSET 48
#define ASCII_WHITESPACE_OFFSET 32

#define MAX_WORD_LEN 64
#define MAX_WORD_COMPLETIONS 10

typedef enum {
    UT_UNDEFINED,
    UT_INT,
    UT_CHAR_P
} utype;

typedef struct _ll_node {
    utype type;
    union {
        int32_t i_data;
        char *s_data;
    } data;
    struct _ll_node *next;
    struct _ll_node *prev;
} ll_node;

ll_node *ll_node_create(utype type, uint32_t size);
void ll_node_destroy(ll_node *node);

typedef struct {
    uint32_t size;
    ll_node *first;
    ll_node *last;
} dll;

dll *dll_create();
void dll_destroy(dll *_dll);
void dll_add_last_i(dll *_dll, int32_t i_data);
void dll_add_last_s(dll *_dll, char *c_data, int32_t size);
void dll_remove_last(dll *_dll);
void dll_print(dll *_dll);

typedef struct _trie_node {
    struct _trie_node *node[MAX_TRIE_SUPPORTED_CHARS];
    char *prefix;
    uint32_t level;
    bool is_word;
} trie_node;

uint8_t get_index(const char c);
char get_char(const int32_t index);
void trie_put_word(trie_node *tn, char *word);
bool trie_has_word(trie_node *tn, char *word);
void trie_get_word_completions(trie_node *tn, char *prefix, dll *completions);
trie_node *trie_node_create(uint32_t level);
void trie_node_destroy(trie_node *tn);

void random_name_generator(char *str, uint32_t size);
void populate_trie(trie_node *tn, uint32_t size, uint32_t count);
void test_mode(uint32_t count_trie_entries, uint32_t size_prefix, uint32_t count_prefix_completions_search);

int main(int argc, char **argv) {
    if (argc > 3) {
        uint32_t count_trie_entries = atoi(argv[1]);
        uint32_t size_prefix = atoi(argv[2]);
        uint32_t count_prefix_completions_search = atoi(argv[3]);
        test_mode(count_trie_entries, size_prefix, count_prefix_completions_search);
        return EXIT_SUCCESS;
    }

    trie_node *tn = trie_node_create(0);
    trie_put_word(tn, "purple");
    trie_put_word(tn, "r");
    trie_put_word(tn, "rr");
    trie_put_word(tn, "rrr");
    trie_put_word(tn, "rrr1");
    trie_put_word(tn, "reds r");
    trie_put_word(tn, "reds r x y z");
    trie_put_word(tn, "red");
    trie_put_word(tn, "Blue");
    trie_put_word(tn, "yellow");
    trie_put_word(tn, "CYAN");
    trie_put_word(tn, "zzzzzZZzzZZz");
    trie_put_word(tn, "zzzzzZZz");
    trie_put_word(tn, "zzz zZZz zzzz");

    printf("%d\n", trie_has_word(tn, "purple"));
    printf("%d\n", trie_has_word(tn, "magenta"));
    printf("%d\n", trie_has_word(tn, "cyan"));
    printf("%d\n", trie_has_word(tn, "r"));
    printf("%d\n", trie_has_word(tn, "red"));
    printf("%d\n", trie_has_word(tn, "orange"));
    printf("%d\n", trie_has_word(tn, "green"));
    printf("%d\n", trie_has_word(tn, "z"));
    printf("%d\n", trie_has_word(tn, "Z"));
    printf("%d\n", trie_has_word(tn, "zzzzzZZ"));
    printf("%d\n", trie_has_word(tn, "zzzzzZZzzZZz"));
    printf("%d\n", trie_has_word(tn, "zzzzzZZz"));

    printf("Prefix completions limit: %d\n", MAX_WORD_COMPLETIONS);

    dll *completions = dll_create();
    trie_get_word_completions(tn, "r", completions);
    trie_get_word_completions(tn, "z", completions);
    dll_print(completions);
    printf("Prefix completions size: %d\n", completions -> size);
    dll_destroy(completions);

    trie_node_destroy(tn);
}

void test_mode(uint32_t count_trie_entries, uint32_t size_prefix, uint32_t count_prefix_completions_search) {
    trie_node *tn = trie_node_create(0);
    // Setup
    time_t tstart_load;
    time(&tstart_load);
    printf("Loading Trie start time: %ld\n", tstart_load);
    // NOTE: random populate
    populate_trie(tn, MAX_WORD_LEN, count_trie_entries);

    time_t tend_load;
    time(&tend_load);
    printf("Loading Trie end time: %ld\n", tend_load);
    printf("Trie loaded with %d entries in %lds\n\n",
            count_trie_entries, (tend_load - tstart_load));

    // Search prefix completions
    time_t tstart_completions;
    time(&tstart_completions);
    printf("Prefix completions start time: %ld\n", tstart_completions);
    
    uint32_t total_found = 0;

    for (int i = 0; i < count_prefix_completions_search; i++) {
        char *prefix = malloc(sizeof(*prefix) * (size_prefix + 1));
        random_name_generator(prefix, size_prefix + 1);

        dll *completions = dll_create();
        trie_get_word_completions(tn, prefix, completions);

        // uncomment to see all the completions
        // keep commented during stats check
        /*printf("Prefix completions size for '%s': %d\n", prefix, completions -> size);*/
        /*dll_print(completions);*/

        total_found += completions -> size;
        dll_destroy(completions);
        free(prefix);
    }

    time_t tend_completions;
    time(&tend_completions);
    printf("Prefix completions end time: %ld\n\n", tend_completions);
    printf("Trie entries: %d\n", count_trie_entries);
    printf("Prefix size: %d\n", size_prefix);
    printf("Prefix completions limit: %d\n", MAX_WORD_COMPLETIONS);
    printf("Prefix completions search attempts: %d\n", count_prefix_completions_search);
    printf("Prefix completions search found total: %d in %lds\n\n",
            total_found, (tend_completions - tstart_completions));

    // Tear Down
    time_t tstart_free;
    time(&tstart_free);

    printf("Destroying Trie start time: %ld\n", tstart_free);
    trie_node_destroy(tn);

    time_t tend_free;
    time(&tend_free);
    printf("Destroying Trie end time: %ld\n", tend_free);
    printf("Trie memory freed with %d entries in %lds\n",
            count_trie_entries, (tend_free - tstart_free));
    printf("\n\n------------------------------------------------------------\n");
}

void dll_print(dll *_dll) {
    ll_node *tmp = _dll -> first;
    while (tmp != NULL) {
        printf("%s\n", tmp -> data.s_data);
        tmp = tmp -> next;
    }
}

uint8_t get_index(const char c) {
    if (isdigit(c))
        return c - ASCII_NUM_OFFSET;
    else if (isalpha(c))
        return tolower(c) - ASCII_LC_A_OFFSET + OFFSET_NUMS;
    else if (isspace(c))
        return 36;
    exit(EXIT_FAILURE);
}

char get_char(const int32_t index) {
    if (index >= 0 && index <= 9)
        return index + ASCII_NUM_OFFSET;
    else if (index >= 10 && index <= 35)
        return index + ASCII_LC_A_OFFSET - OFFSET_NUMS;
    else if (index == 36) {// whitespace
        return 32;
    }
    exit(EXIT_FAILURE);
}

char *get_word_from_dll(dll *dll_prefix) {
    char *matched_prefix = malloc(sizeof(*matched_prefix) * (dll_prefix -> size + 1));
    ll_node *tmp = dll_prefix -> first;
    int i = 0;
    while (tmp != NULL) {
        matched_prefix[i] = get_char(tmp -> data.i_data);
        i += 1;
        tmp = tmp -> next;
    }
    matched_prefix[i] = 0;
    return matched_prefix;
}

void trie_put_word(trie_node *tn, char *word) {
    int size = strnlen(word, MAX_WORD_LEN);
    if (size == 0 || (size == MAX_WORD_LEN && word[size] != 0))
        return;

    dll *dll_prefix = dll_create();

    while (*word != 0) {
        int8_t index = get_index(*word);
        dll_add_last_i(dll_prefix, index);

        if (tn -> node[index] == NULL) {
            tn -> node[index] = trie_node_create(tn -> level + 1);
        }
        tn = tn -> node[index];
        tn -> prefix = get_word_from_dll(dll_prefix);
        word += 1;
    }
    tn -> prefix = get_word_from_dll(dll_prefix);
    tn -> is_word = true;

    dll_destroy(dll_prefix);
}

bool trie_has_word(trie_node *tn, char *word) {
    int size = strnlen(word, MAX_WORD_LEN);
    if (size == 0 || (size == MAX_WORD_LEN && word[size] != 0))
        return false;

    while (*word != 0) {
        int8_t index = get_index(*word);
        if (tn -> node[index] == NULL) {
            return false;
        }
        tn = tn -> node[index];
        word += 1;
    }
    return tn -> is_word;
}

void _traverse_all_paths(trie_node *tn, dll *completions) {
    if (completions -> size >= MAX_WORD_COMPLETIONS)
        return;
    if (tn -> is_word) {
        dll_add_last_s(completions, tn -> prefix, tn -> level);
    }
    for (int i = 0; i < MAX_TRIE_SUPPORTED_CHARS; i++) {
        if (tn -> node[i] != NULL) {
            _traverse_all_paths(tn -> node[i], completions);
        }
    }
}

void trie_get_word_completions(trie_node *tn, char *prefix, dll *completions) {   
    int size = strnlen(prefix, MAX_WORD_LEN);
    if (size == 0 || (size == MAX_WORD_LEN && prefix[size] != 0))
        return;

    while (*prefix) {
        int8_t index = get_index(*prefix);
        if (tn -> node[index] == NULL)
            return;
        tn = tn -> node[index];
        prefix += 1;
    }
    _traverse_all_paths(tn, completions);
}

trie_node *trie_node_create(uint32_t level) {
    trie_node *tn = malloc(sizeof(*tn));
    for (int i = 0; i < MAX_TRIE_SUPPORTED_CHARS; i++) {
        tn -> node[i] = NULL;
    }
    tn -> prefix = malloc(sizeof(char) * (level + 1));
    if (level == 0) {
        tn -> prefix = 0;
    }
    tn -> level = level;
    tn -> is_word = false;
    return tn;
}

void trie_node_destroy(trie_node *tn) {
    for (int i = 0; i < MAX_TRIE_SUPPORTED_CHARS; i++) {
        if (tn -> node[i] != NULL) {
            trie_node_destroy(tn -> node[i]);
            tn -> node[i] = NULL;
        }
    }
    free(tn -> prefix);
    tn -> prefix = NULL;
    tn -> level = 0;
    tn -> is_word = false;
    free(tn);
}

void _dll_node_add_last(dll *_dll, ll_node *node) {
    if (_dll -> first == NULL) {
        _dll -> first = _dll -> last = node;
    } else {
        node -> prev = _dll -> last;
        _dll -> last -> next = node;
        _dll -> last = node;
    }
    _dll -> size += 1;
}

void dll_remove_last(dll *_dll) {
    if (_dll -> last == NULL)
        return;

    if (_dll -> last == _dll -> first) {
        ll_node_destroy(_dll -> last);
        _dll -> first = _dll -> last = NULL;
    } else {
        ll_node *last_node = _dll -> last;
        last_node -> prev = NULL;
        _dll -> last = _dll -> last -> prev;
        _dll -> last -> next = NULL;
        ll_node_destroy(last_node);
    }
    _dll -> size -= 1;
}

void dll_add_last_i(dll *_dll, int32_t i_data) {
    ll_node *node = ll_node_create(UT_INT, 0);
    node -> data.i_data = i_data;
    _dll_node_add_last(_dll, node);
}

void dll_add_last_s(dll *_dll, char *c_data, int32_t size) {
    ll_node *node = ll_node_create(UT_CHAR_P, size);
    strncpy(node -> data.s_data, c_data, MAX_WORD_LEN);
    _dll_node_add_last(_dll, node);
}

dll *dll_create() {
    dll *_dll = malloc(sizeof(*_dll));
    _dll -> size = 0;
    _dll -> first = NULL;
    _dll -> last = NULL;
    return _dll;
}

void dll_destroy(dll *_dll) {
    ll_node *tmp = _dll -> first;
    while (tmp != NULL) {
        ll_node *next = tmp -> next;
        ll_node_destroy(tmp);
        tmp = next;
    }
    _dll -> size = 0;
    _dll -> first = NULL;
    _dll -> last = NULL;
    free(_dll);
    _dll = NULL;
}

ll_node *ll_node_create(utype type, uint32_t size) {
    ll_node *node = malloc(sizeof(*node));
    node -> type = type;
    node -> next = NULL;
    node -> prev = NULL;
    if (node -> type == UT_INT) {
        node -> data.i_data = 0;
    } else if (type == UT_CHAR_P) {
        node -> data.s_data = malloc(sizeof(char) * (size + 1));
    }
    return node;
}

void ll_node_destroy(ll_node *node) {
    if (node -> type == UT_INT) {
        node -> data.i_data = 0;
    } else if (node -> type == UT_CHAR_P && node -> data.s_data != NULL) {
        free(node -> data.s_data);
        node -> data.s_data = NULL;
    }
    node -> type = UT_UNDEFINED;
    node -> next = NULL;
    node -> prev = NULL;
    free(node);
    node = NULL;
}

void random_name_generator(char *str, uint32_t size) {
    if (size && str) {
        const char *charset = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ";
        const int8_t charset_size = strlen(charset);
        int8_t i = 0;
        for (i = 0; i < size - 1; i++) {
            int8_t index = rand() % charset_size;
            str[i] = charset[index];
        }
        str[i] = 0;
    }
}

void populate_trie(trie_node *tn, uint32_t size, uint32_t count) {
    srand(time(NULL));

    int i = 0;
    while (i < count) {
        char *r1 = malloc(sizeof(*r1) * size);
        random_name_generator(r1, size);
        trie_put_word(tn, r1);

        /*printf("%s\n", r1);*/
        free(r1);
        r1 = NULL;
        i += 1;
    }
}

