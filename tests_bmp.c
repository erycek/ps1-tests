#include "../bmp.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

const char vigenere_long_key[30][5000] = {};

const char vigenere_long_text[30][5000] = {};

const char vigenere_long_text_output[30][5000] = {
};

const char vigenere_short_key[50][5000] = {
};

const char vigenere_short_text[50][5000] = {
};

const char vigenere_short_text_output[50][5000] = {
};

//const char vigenere_long_key[30][5000] = {};
//
//const char vigenere_long_text[30][5000] = {};
//
//const char vigenere_long_text_output[30][5000] = {
//};
//
//const char vigenere_short_key[50][5000] = {
//};
//
//const char vigenere_short_text[50][5000] = {
//};
//
//const char vigenere_short_text_output[50][5000] = {
//};
//
//const char vigenere_long_key[30][5000] = {};
//
//const char vigenere_long_text[30][5000] = {};
//
//const char vigenere_long_text_output[30][5000] = {
//};
//
//const char vigenere_short_key[50][5000] = {
//};
//
//const char vigenere_short_text[50][5000] = {
//};
//
//const char vigenere_short_text_output[50][5000] = {
//};
//
//const char vigenere_long_key[30][5000] = {};
//
//const char vigenere_long_text[30][5000] = {};
//
//const char vigenere_long_text_output[30][5000] = {
//};
//
//const char vigenere_short_key[50][5000] = {
//};
//
//const char vigenere_short_text[50][5000] = {
//};
//
//const char vigenere_short_text_output[50][5000] = {
//};

extern char* vigenere_encrypt(const char* key, const char* text);
extern char* vigenere_decrypt(const char* key, const char* text);

extern char* reverse(const char* text);

extern unsigned char* bit_encrypt(const char* text);
extern char* bit_decrypt(const unsigned char* text);

extern unsigned char* bmp_encrypt(const char* key, const char* text);
extern char* bmp_decrypt(const char* key, const unsigned char* text);

void vigenere_encrypt_dry_run()
{
    printf("Tests vigenere_encrypt_dry_run:\n");

    assert(vigenere_encrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void vigenere_decrypt_dry_run()
{
    printf("Tests vigenere_decrypt_dry_run:\n");

    assert(vigenere_decrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void vigenere_encrypt_key_isalpha()
{
    printf("Tests vigenere_encrypt_key_isalpha:\n");

    assert(vigenere_encrypt("#$%&'()*", "abc") == NULL);

    printf("Tests passed.\n");
}

void vigenere_decrypt_key_isalpha()
{
    printf("Tests vigenere_decrypt_key_isalpha:\n");

    assert(vigenere_decrypt("#$%&'()*", "abc") == NULL);


    printf("Tests passed.\n");
}


void vigenere_encrypt_vignere_short_text()
{
    printf("Tests vigenere_encrypt_vignere_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        assert(vigenere_encrypt(vignere_short_key[i], vignere_short_text[i]) == vignere_output[i]);
    }

    printf("Tests passed.\n");
}

void vigenere_decrypt_vignere_short_text()
{
    printf("Tests vigenere_decrypt_vignere_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        assert(vigenere_decrypt(vignere_short_key[i], vignere_short_text[i]) == vignere_output[i]);
    }

    printf("Tests passed.\n");
}

void vigenere_encrypt_long_text()
{
    printf("Tests vigenere_encrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        assert(vigenere_encrypt(vignere_long_key[i], vignere_vignere_long_text[i]) == vignere_output[i]);
    }

    printf("Tests passed.\n");
}

void vigenere_decrypt_long_text()
{
    printf("Tests vigenere_decrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        assert(vigenere_decrypt(vignere_long_key[i], vignere_long_text[i]) == vignere_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_encrypt_dry_run()
{
    printf("Tests playfair_encrypt_dry_run:\n");

    assert(playfair_encrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_decrypt_dry_run()
{
    printf("Tests playfair_decrypt_dry_run:\n");

    assert(playfair_encrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_encrypt_key_isalpha()
{
    printf("Tests playfair_encrypt_key_isalpha:\n");

    assert(playfair_encrypt("#$%&'()*", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_decrypt_key_isalpha()
{
    printf("Tests playfair_decrypt_key_isalpha:\n");

    assert(playfair_decrypt("#$%&'()*", "abc") == NULL);


    printf("Tests passed.\n");
}


void playfair_encrypt_short_text()
{
    printf("Tests playfair_encrypt_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        assert(playfair_encrypt(short_key[i], short_text[i]) == short_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_decrypt_short_text()
{
    printf("Tests playfair_decrypt_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        assert(playfair_decrypt(short_key[i], short_text[i]) == short_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_encrypt_long_text()
{
    printf("Tests playfair_encrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        assert(playfair_encrypt(long_key[i], long_text[i]) == long_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_decrypt_long_text()
{
    printf("Tests playfair_decrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        assert(playfair_decrypt(long_key[i], long_text[i]) == long_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_encrypt_dry_run()
{
    printf("Tests playfair_encrypt_dry_run:\n");

    assert(playfair_encrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_decrypt_dry_run()
{
    printf("Tests playfair_decrypt_dry_run:\n");

    assert(playfair_encrypt(" ", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_encrypt_key_isalpha()
{
    printf("Tests playfair_encrypt_key_isalpha:\n");

    assert(playfair_encrypt("#$%&'()*", "abc") == NULL);

    printf("Tests passed.\n");
}

void playfair_decrypt_key_isalpha()
{
    printf("Tests playfair_decrypt_key_isalpha:\n");

    assert(playfair_decrypt("#$%&'()*", "abc") == NULL);


    printf("Tests passed.\n");
}


void playfair_encrypt_short_text()
{
    printf("Tests playfair_encrypt_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        assert(playfair_encrypt(short_key[i], short_text[i]) == short_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_decrypt_short_text()
{
    printf("Tests playfair_decrypt_short_text:\n");

    for(int i = 0; i < 40; i++)
    {
        assert(playfair_decrypt(short_key[i], short_text[i]) == short_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_encrypt_long_text()
{
    printf("Tests playfair_encrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        assert(playfair_encrypt(long_key[i], long_text[i]) == long_text_output[i]);
    }

    printf("Tests passed.\n");
}

void playfair_decrypt_long_text()
{
    printf("Tests playfair_decrypt_long_text:\n");

    for(int i = 0; i < 24; i++)
    {
        assert(playfair_decrypt(long_key[i], long_text[i]) == long_text_output[i]);
    }

    printf("Tests passed.\n");
}

int main()
{
    printf("Tests for playfair.c:\n");
//    TODO: Implement memory leak check
//    printf("Memory check:\n");

    printf("Tests for encrypt:\n");
    playfair_encrypt_dry_run();
    playfair_encrypt_key_isalpha();
    playfair_encrypt_short_text();
    playfair_encrypt_long_text();

    printf("Tests for decrypt:\n");
    playfair_decrypt_dry_run();
    playfair_decrypt_key_isalpha();
    playfair_decrypt_short_text();
    playfair_decrypt_long_text();

    printf("Tests passed.\n");
    return 0;
}
