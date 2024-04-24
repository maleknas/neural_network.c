#define NUM_EPOCHS 100
#define MAX_ROWS 100
#define MAX_COLS 3  
int read_csv(const char *filename, float data[MAX_ROWS][MAX_COLS], int *num_rows) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char line[1024];
    *num_rows = 0;
    while (fgets(line, 1024, file)) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            data[*num_rows][col++] = atof(token);
            token = strtok(NULL, ",");
        }
        (*num_rows)++;
    }

    fclose(file);
    return 0;
}
