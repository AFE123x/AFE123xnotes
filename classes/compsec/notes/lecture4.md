# Lecture 4 - Public-key Cryptography (asymetric cryptography)

## public key vs. private key

- The public key is shared to the public
- the private key is kept to each user.

## Public key, private key basic steps

- Each user will have a private and public key.

1. alice obtains bob's public key (PK_Bob)
2. alice encrypts: C = E(>K_Bob, M)
3. Alice sends C to Bob
4. Bob decrypts: M = D(SK_Bob, C)

## advantage of public key cryptography

- advantages:
    - scalable: only need 2n keys for n users.
    - enable digital signatures
    - easier key management.
- disadvantage:
    - performance: slower
    - longer keys (2048+ bits)
    - mathmatically complex
    - Vulnerable to math breakthroughs

## one way & trapdoor

- It's easy to compute forward, hard to reverse
    - we multiply primes $(p \times q = n)$, which is easy
    - factoring $n \rightarrow (p, q)$, which is hard

- analogy: breaking a plate into pieces is hard, putting it back together is easy.
- It'll be easy for the key holders.

## RSA Algorithm

- Rivest, Shamir, Adleman algorithm
    - these three invented the algorithm

- what does the algo look like?

1. choose two large primes: p, q (both prime, typically 1024 bits each)
2. compute modulus: $n = p \times q$ (n is the modulus).
3. computer Euler's totient: $\varphi(n) = (p - 1)(q - 1)$
4. choose e
5. compute private exponent: $d = e^{-1} \mod \varphi (n)$, where $9d \cdot e = 1 \mod \varphi(n)$
6. public key(n,e), private key(n,d)


- this is the most commonly used for encryption.

## RSA - Encryption approach

- given: message m, public key (n, e)

1. compute cipher: $c = m^e \mod n$
2. decrypt: private key(n, d), $m = c^d \mod n$

- why this works: $(m^e)^d = m (\mod n)$


## hybrid encryption (RSA + AES)

- RSA is 1000x slowed than AES

- the proposed solution is to use both.
    - generate random symmetric key (AES-256).
    - encrypt data with symmetric key (fast).
    - encrypt symmetric key with RSA (small, one-time).
    - send: RSA-encrypted key + AES-encrypted data.

- here, we don't need to encrypt the entire plain text, instead encrypting the AES-256.


## master key problem

- essentially, if a hacker gets access to the private key, they'll be compromised.
- the disposable key is a solution, where you create keys on the fly.

## diffie-hellman protocol

- public parameters: p (largo prime (2048+ bits)), g (generator (primitive root modulo p))

- alice will
    - choose a secret key (random 1 < a < p)
    - compute $A = g^a \mod p$
    - send A to bob
- bob will choose b (secret) (random 1 < b < p)
- compute $B = g^b \mod p$
- send B to alice

- shared secret computation

ALice: $s = B^a \mod p = (g^b)^a mod p = g^{(ab)} \mod p$
Bob: $s = A^b mod p = (g^a)^b mod p = g^{(ab)} \mod p$

both will have the same shared secret.

**read up on this**

## man-in-the-middle attack

- the attack is basically

1. eve intercepts Alice's A, sends her own E1 to Bob.
2. Eve interepts Bob's B, sends her own E2 to alice
3. Alice thinks she shares key with bob (actually eve)
4. bob thinks he shares key with Alice (actually Eve)

## trust problem
- scenario:
    - alice wants bob's public key
    - bob publishes public key online
    - how does alice know it's really bob's key, not an attacker's

- anyone can generate a key pair and claims it belongs to someone else.

## digital certificates

- Digitally signed statement binding public key to identity.

- certificate content (X.509):
    - subject: owner's identity (name, organization, etc.)
    - subject public key: owner's public key
    - issuer: who signed this certificate (certificate authority)
    - validity period: not before / not after dates
    - serial number: unique identifier.

- how it works:
    - bob generates key pair
    - bob sends public key + identity proof to certificate authority
    - CA verifies Bob's identity (out-of-band)
    - CA signs certificate with CA's private key
    - Anyone can verify certificates using CA's public key

## certificate authorities (CAs)

- role:
    - trusted third parties
    - verify identities
    - issue + sign certificates
    - maintain certificate revocation lists (CRLs)

- trust model:
    - your browser/OS has list of trusted root CA certificates
    - these CAs can issue certificates for any domain
    - you trust CA to properly verify identities

steps:
    - server sends certificate to browser
    - browser verifies:
        - signature valid.
        - domain matches
        - not expired
        - not revoked
    - browser extracts server's public key from certificate
    - browser and server perform **diffie-hellman** with authentication.

## PKI
- PKI: Public Key Infrastructure

## what's a hash function

- A hash function takes an input of arbitrary length, and produces fixed length output
    - `h = H(M)`
- examples include SHA-256

## hash properties

- deterministic: same input -> same output
- fast to compute: efficient calculation
- pre image resistance: can't reverse (one-way)
    - for example, given a hash value, you cannot deduct what the hash is.
- the hash should always provide unique results (no collisions).
    - and you should always get the same result given the same hash

## hash function - applications

- data integrity: file verification, check integrity of file.
- password storage: store as a hash, not a plaintext
- digital signatures: as a signed hash, not entire doc
- blockchain: uses double SHA-256, each block contains hash of previous block.

## hash algorithms

- md5, sha-1, sha-2, sha-3

## Hash algorithms: MD5 and SHA-1

- provides 128 bit output for MD5, 160 bit output for SHA-1
- these are deprecated

## Hash Algorithms: SHA-2 family

- These are secure, much more bits.

## issues with hash's 

- it helps with data integrity, but not authentication.
- Anyone can intercept a message, and rehash another message.
    - the recipient is oblivious to who sent the message
## MACs

- Message Authentication Codecs

- MAC is a checksum, which uses a secret key.
    - it detects accidential vs. intentional modification.

$MAC = MAC(K,M) ;; K = $ secret key (shared between alice and bob) M = message, MAC = authentication tag


## HMAC

- this is Hash based MAC
- Here, you use a cryptographic hash function (like SHA-256), and a secret key to produce a MAC

$HMAC(K, M) = H((K \oplus opad) || H((K \oplus ipad) || M))$


## digital signatures

