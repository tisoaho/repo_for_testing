#include <ctype.h>
#include <string.h>
#include <limits.h>
#include "eke.h"


// swaps the given chars using a temporary variable.
static void swap(char* a, char* b)
{
    char tmp;

    tmp = *a;

    *a = *b;
    *b = tmp;
}




static void bufToLowerCase(char* buffer, size_t len) {
    
    for (unsigned i = 0; i < len; i++) {
        buffer[i] = (char) tolower(buffer[i]);
    }
    
}

static int charsValue(char in)
{
    static const char order[] = "qwertyuiopåasdfghjklöäzxcvbnm";

    char* pos = strchr(order, in);

    if (pos == NULL) {
        return INT_MAX; // everything else than alphas pushed to end. 
    }
    else {
        return (int) (pos - order); // 0 is the first (=q) and so on....
    }
}


// this implements quick sort kind of algorithm for the sorting
static void do_sort(char* buffer, size_t len)
{
    if (len < 2)
        return; // DONE!
    
    int pivot = charsValue(buffer[len / 2]);
    size_t i, j;
    
    for (i = 0, j = len - 1; ; i++, j--) {
        while (charsValue(buffer[i]) < pivot) {
            i++;   
        }
        while (charsValue(buffer[j]) > pivot) {
            j--;
        }
        
        if (i >= j) {
            break;
        }
        swap(&buffer[i], &buffer[j]);
    }
 
  do_sort(buffer, i);
  do_sort(buffer + i, len - i);
    
}

void fix_ending(char* buffer, size_t len)
{
    while (!isalpha(buffer[len])) {
        buffer[len] = '\0';
        len--;
    }
}

// sorts the buffer by the specified criteria. everything is conveted to
// lower case. Non-alphabetic characters are swallowed.
int eke_sort(char* buffer)
{
    if (!buffer) {
        return -1; // bad input;
    }
    
    size_t len = strlen(buffer);

    bufToLowerCase(buffer, len);
    do_sort(buffer, len);
    fix_ending(buffer, len);
    
    return 0;
}
