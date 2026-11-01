# VEIL-19

**Personal Encoding System — v1.0**

VEIL-19 is a lightweight terminal-based text encoding program written in C.

It uses a repeating-key substitution algorithm inspired by the Vigenère cipher to encode and decode text.

## Features

- Text encryption and decryption.
- Repeating alphabetic secret key.
- Supports uppercase and lowercase English letters.
- Preserves spaces, numbers, and special characters.
- Key validation (English letters only).
- Simple terminal interface.
- No external libraries required.

## How It Works

VEIL-19 uses a repeating key to transform alphabetic characters.

Each letter is converted into a numerical value:

- A = 0
- B = 1
- ...
- Z = 25

**Encryption:**

`E = (P + K) mod 26`

**Decryption:**

`D = (C - K + 26) mod 26`

Where:

- P = Plaintext letter
- K = Key letter
- C = Ciphertext letter
- E = Encrypted letter
- D = Decrypted letter

Non-alphabetic characters remain unchanged and do not advance the key.

## Requirements

- GCC compiler
- Linux, Windows, or another system with a C compiler

## Compilation

```bash
gcc veil19.c -o veil19
```

## Usage

Run the program:

```bash
./veil19
```

Choose an operation:

```text
[1] Encrypt
[2] Decrypt
[0] Exit
```

Enter your text and secret key when prompted.

## Project Structure

```text
VEIL-19/
├── veil19.c
├── README.md
└── LICENSE
```

## Security Notice

VEIL-19 is an educational encoding project, not a secure encryption system.

It is based on a repeating-key substitution algorithm and should not be used to protect sensitive information.

## Version

**VEIL-19 v1.0**

## Author

Created as a personal programming project.

## License

See the LICENSE file for licensing information.
