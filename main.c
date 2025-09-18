#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 40
#define PART_COUNT 3
#define COUNT_OF(x) (sizeof(x) / sizeof((x)[0]))
#define USER_RESPONSE_NUM 2
#define TRUE 1
#define FALSE 0

char USERPART[LINE_SIZE];
const char MESSAGE_WELCOME[] = "Welcome to my spare part inventory\n";
const char WHAT_DO_U_WANT[] = "What to you need?\n"
                              "Enter the part: ";
const char KNOWN_PARTS[PART_COUNT][LINE_SIZE] = {
    "PLC module",
    "servo motor",
    "hydraulic pump",
};
const char MESSAGE_POSITIVE[] = "✅ I have that!.";
const char MESSAGE_NEGATIVE[] = "❌ I don't have it.";
const char *USER_RESPONSE[USER_RESPONSE_NUM] = {"What do you have?",
                                                "Do you have anything at all?"};

int main(void) {
  printf("%s", MESSAGE_WELCOME); // prints welcome to the shop

  int found = 0; // making a variable for the while loop.

  while (!found) {                // loop while found is false
    printf("%s", WHAT_DO_U_WANT); // this will be printed in a loop until the
                                  // correct response is made.

    if (fgets(USERPART, COUNT_OF(USERPART),
              stdin)) { // Basically scanf but u can do multiple words.
      USERPART[strcspn(USERPART, "\n")] =
          0; // removes the newline from your word
    }

    int l = FALSE;

    for (int j = 0; j < USER_RESPONSE_NUM; j++) {
      if (strcmp(USERPART, USER_RESPONSE[j]) == 0)
        l = TRUE;
    }

    if (l) {
      printf("This is what i got my man:\n");
      for (int k = 0; k < PART_COUNT; k++) {
        printf("-%s\n", KNOWN_PARTS[k]);
      }
      continue;
    }

    int i = 0;

    while (i < PART_COUNT && strcmp(USERPART, KNOWN_PARTS[i]) != 0) {
      i++; // scans KNOWN_PARTS to see if the USERPART is equal to any.
    }
    if (i < PART_COUNT) {
      found = 1; // if USERPART is equal to any => found becomes true => the
                 // loop ends.
    } else {
      puts(MESSAGE_NEGATIVE); // if USERPART doesn't match KNOWN_PARTS puts the
                              // "too bad" message.
    }
  }
  puts(MESSAGE_POSITIVE); // congratz! you've done the job.
  return EXIT_SUCCESS;    // ends program
}
