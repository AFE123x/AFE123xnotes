# AES & Block Cipher Modes

## What is AES

- Advanced Encryption Standard
- developed in 2001 by Rijndael

- Offered:
    - better security + performance.
    - efficient hardware and software usage.
    - elegant
    - flexible and scalable

## AES vs. DES

| stuff | DES | AES-128 | AES-256 |
| --- | --- | --- | --- |
| block size | 64 bits | 128 bits | 128 bits |
| key size | 56 bits | 128 bits | 256 bits |
| rounds | 16 | 10 | 14 |
| speed | slow | fast | fast |
| security | broken | secure | very secure |

## AES algorithm structure

- It uses Substitution-Permutation Network (SPN)

- it'll perform the following operations:
    - subbytes
    - shiftrows
    - mixcolumns
    - add round key

### where's the rows and columns coming from?

- we'll take the 128 bit block of data, and treat it as a 4 x 4 grid
    - hence each row will have 4 bytes

- column 1: bytes 0, 1, 2, 3
- column 2: bytes 4, 5, 6, 7
- ... and so on

## AES security

- AES-128 is secure for most uses.
- AES-256 is quantum resistant.

- Using brute force, it'd take billions of years.
    - It's used by banks.

## block cipher - modes of operations

- block ciphers encrypt fixed blocks.

- the problem is:
    - how do we handle messages longer than one block.
    - messages aren't block sized
    - patterns in similar plaintexts.

- to handle this, we use modes of operations.
    - how do we take care of one block vs. another?

## ECB mode (electronic codebook)

- we can encrypt each block individually:
    `C_i = E(K, P_i)`, so you enrypt each block individually.

- it's simple, random access, but it generates parelellism.
- blocks are identical, patterns will be visible.

## CBC Mode (Cipher Block Chaining)

- we perform XOR with previous cipher text with encrypting:
    - $C_i = E(K, P_i \oplus C_{i-1})$
    - $C_0 = IV (\text{initialization vector})$

- to decrypt:
    - $P_i = D(K, C_i) \oplus C_{i - 1}$

- it's secure, widely used, parellel decrypt.
- problem is sequential encryption, and requires padding.

## CTR mode (counter)

- here, we encrypt the counter value, XOR with plaintext
- $C_i = P_i \oplus E(K, \text{Nonce || Counte}r_i)$

- advantages
    - here, we can use parallel encryption/decryption
    - random access
    - no padding needed
    - can pre compute.
- requirement:
    - never reuse nonce.
    - must be unique.
    - can be sequential.

## GCM

- Galois + Counter mode

- encryption:
    - uses CTR mode.
    - authentication: GMAC (Palois MAC)
    - output: Ciphertext + Authentication Tag

- features:
    - CTR mode encryption + GMAC authentication.

- benefits:
    - maintains confidentiality, integrity, authentication.

## Stream Ciphers

- audio/video streams need low latency, no padding and simplicity.
- DES and AES are block based engines.
- stream ciphers are flow based engines.

- stream ciphers offer
    - low latency.
    - no padding
    - simplicity


### overview

- Keystream = Generate(Key, IV)
    - you should never reuse the key. each bit should have it's own encryption key.
- $\text{cipbertext } = \text{ Plaintext} \oplus \text{ Keystream}$

### options

- RC4: broken, don't use
- ChaCha20
    - take 256 bit key, very fast.
- AES-CTR:
    - technically a block cipher, but acts like a stream.


## types of random numbers

- True RNG (TRNG)
    - take hardware characteristics, and generate a random number from that.
    - it's truly random, but slow.
- pseudorandom (PRNG):
    - deterministic random (not cryptographically secure)
- Crypographically Secure PRNG (CSPRNG)
    - unpredictable, passes statistical tests
    - used for all cryptography.

## best cryptography practices

- use standard algorithms
- use authenticated encryption.
- use appropriate key sizes
- generate keys with CSPRNG
- random, unique IVs/nonces for each encryption.
- use established libraries (OpenSSL)

