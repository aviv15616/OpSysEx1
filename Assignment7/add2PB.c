/**
 * @file add2PB.c
 * @brief Adds a new record to the phonebook.txt file.
 *
 * This program receives a full name and phone number as command-line arguments
 * and appends them to the phonebook in the format:
 *     Full Name,PhoneNumber
 *
 * Example usage:
 *     ./add2PB "John Doe" 0541234567
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 int main(int argc, char *argv[]) {
     // Check that the user provided both a name and a phone number
     if (argc < 3) {
         fprintf(stderr, "Usage: %s \"Full Name\" phone-number\n", argv[0]);
         exit(1);
     }
 
     // Open the phonebook file in append mode
     FILE *f = fopen("phonebook.txt", "a");
     if (!f) {
         perror("fopen");
         exit(1);
     }
 
     // Write the new record to the file in CSV format
     fprintf(f, "%s,%s\n", argv[1], argv[2]);
 
     // Close the file and exit
     fclose(f);
     return 0;
 }
 