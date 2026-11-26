# minitalk

> A client and a server that exchange text using **only two UNIX signals**: `SIGUSR1` and `SIGUSR2`.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![UNIX](https://img.shields.io/badge/UNIX-signals-555555?style=flat&logo=linux&logoColor=white)

## About

The server prints its PID and waits. The client takes that PID and a message, and sends the message
one **bit** at a time: `SIGUSR1` for a 1, `SIGUSR2` for a 0. The server rebuilds each byte,
collects the characters, and prints the whole message once it is complete.

## Features

- every character is sent as 8 signals, least significant bit first
- the end of a message is marked with a special byte
- the server uses `sigaction` with `SA_SIGINFO` to learn the client's PID
- **acknowledgement**: after receiving a full message the server signals back, and the client prints `Message delivered.`
- the server keeps running and can receive many messages in a row
- Unicode text works, because it is just bytes

## Build & run

```bash
make
./server                         # prints: PID: 12345
./client 12345 "Hello, minitalk!"
```

---

<sub>Part of the <a href="https://www.codam.nl/">Codam</a> (42 network) curriculum.</sub>
