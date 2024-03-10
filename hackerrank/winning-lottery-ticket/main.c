#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'winningLotteryTicket' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING_ARRAY tickets as parameter.
 */

#define BITMASK_MAX 1024
#define ALL_BITS_SET ((BITMASK_MAX) - 1)

long winningLotteryTicket(int tickets_count, char** tickets) {
    int *bitmask_cnt = calloc(BITMASK_MAX, sizeof(int));
    int len;
    int bitmask;
    long cnt = 0;

    for (int i = 0; i < tickets_count; ++i)
    {
        bitmask = 0;

        for (int j = 0, len = strlen(tickets[i]); j < len; ++j)
            bitmask |= 1 << (tickets[i][j] - '0'); // set n-th bit to 1
        
        ++bitmask_cnt[bitmask]; // group same bitmask tickets
    }

    // ignore bitmask[1023], as tickets with those bitmasks is compatible with any ticket
    for (int i = 0; i < BITMASK_MAX - 1; ++i)
        for (int j = i + 1; j < BITMASK_MAX - 1; ++j)
            if ((i | j) == ALL_BITS_SET)
                cnt += (long)bitmask_cnt[i] * bitmask_cnt[j];  // all combinations of these groups

    /* 
    * each bitmask_cnt[ALL_BITS_SET] is compatible with all of the rest of the tickets
    * and as we need to ignore duplicate tuples:
    * The first "all-included" ticket will have (tickets_cnt - 1) combinations
    * second will have (tickets_cnt - 2) combinations
    * third will have (tickets_cnt - 3) combinations and so on.
    * so, we have arithmetic progression from [tickets_cnt - bitmask_cnt[ALL_BITS_SET], ticket_cnt - 1]
    * sum = n * (a1 + an) / 2 =>  
    * bitmask_cnt[ALL_BITS_SET] * (tickets_cnt - bitmask_cnt[ALL_BITS_SET] + (tickets_cnt - 1)) / 2
    * so, total = bitmask_cnt[ALL_BITS_SET] * (2 * tickets_count - bitmask_cnt[ALL_BITS_SET] - 1)) / 2
    */
    return cnt + (((long)bitmask_cnt[ALL_BITS_SET] * (2 * tickets_count - bitmask_cnt[ALL_BITS_SET] - 1)) / 2);
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** tickets = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* tickets_item = readline();

        *(tickets + i) = tickets_item;
    }

    long result = winningLotteryTicket(n, tickets);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
