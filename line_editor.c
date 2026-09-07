#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define INITIAL_CAPACITY 10

// Document Data Structure
typedef struct {
    char **lines;
    int count;
    int capacity;
} Document;

// ==========================================
// PART A: CORE OPERATIONS & MEMORY MANAGEMENT
// ==========================================

void init_doc(Document *doc) {
    doc->capacity = INITIAL_CAPACITY;
    doc->count = 0;
    doc->lines = malloc(doc->capacity * sizeof(char *));
}

void free_doc(Document *doc) {
    for (int i = 0; i < doc->count; i++) {
        free(doc->lines[i]);
    }
    free(doc->lines);
}

void display_doc(const Document *doc) {
    if (doc->count == 0) {
        printf("[Document is empty]\n");
        return;
    }
    for (int i = 0; i < doc->count; i++) {
        printf("%4d | %s\n", i + 1, doc->lines[i]);
    }
}

void insert_line(Document *doc, int line_num, const char *text) {
    if (line_num < 1 || line_num > doc->count + 1) {
        printf("Error: Invalid line number. Must be between 1 and %d\n", doc->count + 1);
        return;
    }

    if (doc->count >= doc->capacity) {
        doc->capacity *= 2;
        doc->lines = realloc(doc->lines, doc->capacity * sizeof(char *));
    }

    int idx = line_num - 1;
    for (int i = doc->count; i > idx; i--) {
        doc->lines[i] = doc->lines[i - 1];
    }

    doc->lines[idx] = malloc(strlen(text) + 1);
    strcpy(doc->lines[idx], text);
    doc->count++;
    printf("Line inserted at %d.\n", line_num);
}

void delete_line(Document *doc, int line_num) {
    if (line_num < 1 || line_num > doc->count) {
        printf("Error: Invalid line number. Must be between 1 and %d\n", doc->count);
        return;
    }

    int idx = line_num - 1;
    free(doc->lines[idx]);

    for (int i = idx; i < doc->count - 1; i++) {
        doc->lines[i] = doc->lines[i + 1];
    }

    doc->count--;
    printf("Line %d deleted.\n", line_num);
}

// ==========================================
// PART B: FILE I/O & COMMAND INTERFACE
// ==========================================

void save_file(const Document *doc, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < doc->count; i++) {
        fprintf(fp, "%s\n", doc->lines[i]);
    }
    fclose(fp);
    printf("Saved to %s successfully.\n", filename);
}

void load_file(Document *doc, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("No existing file found. Starting empty.\n");
        return;
    }
    char buffer[MAX_LINE_LEN];
    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\r\n")] = 0;
        insert_line(doc, doc->count + 1, buffer);
    }
    fclose(fp);
    printf("Loaded document from %s.\n", filename);
}

int main(int argc, char *argv[]) {
    Document doc;
    init_doc(&doc);

    // Load file on startup if passed as a command-line argument
    if (argc > 1) {
        load_file(&doc, argv[1]);
    }

    char command[16];
    char buffer[MAX_LINE_LEN];

    printf("--- C Line Editor ---\nType 'help' for commands.\n\n");

    while (1) {
        printf("> ");
        if (scanf("%15s", command) != 1) break;

        if (strcmp(command, "display") == 0 || strcmp(command, "p") == 0) {
            display_doc(&doc);
        } else if (strcmp(command, "insert") == 0 || strcmp(command, "i") == 0) {
            int line;
            if (scanf("%d", &line) != 1) {
                printf("Usage: insert <line_number>\n");
                while (getchar() != '\n');
                continue;
            }
            getchar(); // Consume remaining newline character
            printf("Enter text: ");
            if (fgets(buffer, sizeof(buffer), stdin)) {
                buffer[strcspn(buffer, "\r\n")] = 0;
                insert_line(&doc, line, buffer);
            }
        } else if (strcmp(command, "delete") == 0 || strcmp(command, "d") == 0) {
            int line;
            if (scanf("%d", &line) != 1) {
                printf("Usage: delete <line_number>\n");
                while (getchar() != '\n');
                continue;
            }
            delete_line(&doc, line);
        } else if (strcmp(command, "save") == 0 || strcmp(command, "s") == 0) {
            char filename[128];
            scanf("%127s", filename);
            save_file(&doc, filename);
        } else if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0) {
            printf("Commands: display (p), insert (i) <line>, delete (d) <line>, save (s) <file>, quit (q)\n");
        } else if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
            break;
        } else {
            printf("Unknown command. Type 'help' for options.\n");
            while (getchar() != '\n');
        }
    }

    free_doc(&doc);
    return 0;
}