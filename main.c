#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 40
#define PART_COUNT 3
#define COUNT_OF(x) (sizeof(x) / sizeof((x)[0]))
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
const char MESSAGE_POSITIVE[] = ":DDD I have";
const char MESSAGE_NEGATIVE[] = ":OO I don't have";
const char *USER_RESPONSE[2] = {"What do you have?",
                                "Do you have anything at all?"};

int main(void) {
  printf("%s", MESSAGE_WELCOME); // prints welcome to the shop

  int found = FALSE; // making a variable for the while loop.

  while (!found) {                // loop while found is false
    printf("%s", WHAT_DO_U_WANT); // this will be printed in a loop until the
                                  // correct response is made.

    if (fgets(USERPART, COUNT_OF(USERPART),
              stdin)) { // Basically scanf but u can do multiple words.
      USERPART[strcspn(USERPART, "\n")] =
          0; // removes the newline from your word
    }

    int l = FALSE;

    for (int j = 0; j < 2; j++) { // loops, to check if USER_RESPONSE is 1 of
                                  // the 2 possible responses.
      if (strcmp(USERPART, USER_RESPONSE[j]) == 0)
        l = TRUE;
    }

    if (l) {
      printf("This is what i got my man:\n"); // if USER_RESPONSE is 1 of the 2
                                              // possible responses, prints list
                                              // of KNOWN_PARTS.
      for (int k = 0; k < PART_COUNT; k++) {
        printf("-%s\n", KNOWN_PARTS[k]);
      }
      continue; // if printed, skips the next steps and go back to loop start.
    }

    int i = FALSE;

    while (i < PART_COUNT && strcmp(USERPART, KNOWN_PARTS[i]) != 0) {
      i++; // scans KNOWN_PARTS to see if the USERPART is equal to any.
    }
    if (i < PART_COUNT) {
      found = TRUE; // if USERPART is equal to any => found becomes true => the
                    // loop ends.
    } else {
      printf("%s %s!\n", MESSAGE_NEGATIVE,
             USERPART); // if USERPART doesn't match KNOWN_PARTS prints the
                        // "too bad" message.
    }
  }
  printf("%s %s!\n", MESSAGE_POSITIVE,
         USERPART);    // congratz! you've done the job.
  return EXIT_SUCCESS; // ends program
}
