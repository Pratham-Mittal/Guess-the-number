/**
 * Encryption abstract class, for CE221 Assignment 2 (Exercise 2)
 */

#ifndef _ENCRYPTION_H
#define _ENCRYPTION_H

using namespace std;
#include <string>
#include <list>

class Encryption
{
        public:

                /**
                 * Constructor. Stores the key for encryption
                 */
                Encryption(int key)
                {
                }

                //pure virtual function for filter
                virtual bool isEncrypted(string enc_message)=0;

                /**
                 * encrypts a message
                 */
                void encrypt(string message);

                /**
                 * decrypts a message
                 */

                void decrypt(string message);

        private:
                int key; //key for the encryption of a message
    
 };

 #endif
