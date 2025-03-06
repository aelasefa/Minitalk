# Minitalk

## **Overview**
Minitalk is a 42/1337 project that requires implementing a simple client-server communication program using UNIX signals (`SIGUSR1` and `SIGUSR2`). The client sends a message to the server, which then prints it character by character.

## **Features**
- Server that prints messages sent by the client.
- Client that sends messages using UNIX signals.
- Bitwise transmission of characters.
- Error handling for invalid input and incorrect signals.
- Bonus: Unicode support, message acknowledgment, and signal queueing.

## **How It Works**
1. The **server** prints its Process ID (PID) and waits for messages.
2. The **client** takes the server's PID and a message as arguments.
3. The client **converts each character to binary** and sends it bit by bit using `SIGUSR1` (for 0) and `SIGUSR2` (for 1).
4. The server **reconstructs the message** from the received bits and prints it.

## **Project Structure**
```
minitalk/
├── src/          # Source code files
├── include/      # Header files
├── libft/        # Custom libft (if needed)
├── Makefile      # Compilation script
├── client.c      # Client program
├── server.c      # Server program
├── minitalk.h    # Header file
├── README.md     # Documentation
```

## **Installation & Compilation**
Clone the repository and compile the project using Makefile:
```bash
git clone https://github.com/yourusername/minitalk.git
cd minitalk
make
```

## **Usage**
### 1. Start the server
```bash
./server
```
This will print the server's PID. Keep it running.

### 2. Send a message from the client
```bash
./client <SERVER_PID> "Hello, World!"
```
Replace `<SERVER_PID>` with the actual PID printed by the server.

## **Error Handling**
- Invalid arguments are handled gracefully.
- The client checks if the server's PID is valid before sending signals.
- The server ensures signals are processed correctly to prevent crashes.

## **Bonus Features**
- **Unicode Support**: Handles wide characters.
- **Acknowledgment**: Server sends a signal back after receiving a full message.
- **Signal Queueing**: Handles multiple clients efficiently.

## **Testing**
Run multiple clients to send messages simultaneously and check how the server handles them:
```bash
./client <SERVER_PID> "First message"
./client <SERVER_PID> "Second message"
```

## **Cleanup**
To remove compiled files:
```bash
make clean
```
To remove all binaries:
```bash
make fclean
```

## **Contributing**
Feel free to fork and improve the project. Pull requests are welcome!

## **License**
This project is licensed under the MIT License.

## **Acknowledgments**
- 42/1337 School for the challenge.
- UNIX programming and signals documentation.


