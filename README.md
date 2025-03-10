# C-Professional-Examples

 A collection of well-structured, professional C programming examples with detailed explanations. Each .c file includes a corresponding explanation in the README.md to enhance understanding.<br><br><br>



# Overview

This repository contains a collection of professional C programming examples. Each example is designed to follow best coding practices and includes a detailed explanation in the README file.<br><br><br>



# License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/muhammedceberli/C-Professional-Examples/blob/main/LICENSE) file for details.<br><br><br>



## 🛠 Example_1 - Detab: Ensuring Consistent Text Alignment with Tab Expansion

The detab program replaces tab characters (\t) with spaces to align text at defined tab stops, ensuring consistent formatting.<br><br>


### 🛠 Features

✔ Reads and processes user input efficiently.<br>
✔ Converts tab characters into spaces according to TAB_SIZE.<br>
✔ Maintains correct text alignment.<br>
✔ Handles various input edge cases, including long input lines.<br><br>


### 📌 How It Works

1. **User Input**: The program reads a line of text from standard input.
2. **Tab Expansion**: Tabs are replaced with the appropriate number of spaces, preserving alignment.
3. **Output Display**: The processed text is printed with consistent spacing.<br><br>


### 📂 Code Structure
The program consists of three key functions:<br>

🔹 **readUserInput()**
- Reads a line of input while ensuring it does not exceed the buffer limit (INPUT_SIZE).
- Handles EOF detection and empty input cases.
- Trims excess characters beyond the buffer size.

🔹 **expandTabs()**
- Scans the input string and replaces tab characters with spaces.
- Ensures proper alignment based on TAB_SIZE.
- Handles cursor position tracking to maintain text structure.

🔹 **main()**
- Manages program execution, calling readUserInput() and expandTabs().
- Handles user interaction and displays results.
- Ensures smooth termination upon EOF.<br><br>


### Usage

1️⃣ Clone the repository:
<pre>git clone https://github.com/muhammedceberli/C-Professional-Examples</pre>

2️⃣ Compile the program:
<pre>gcc detab.c -o detab.exe</pre>

3️⃣ Run the program:
<pre>detab.exe</pre>

4️⃣ Enter input and observe the detabbed output.<br><br>


### 🎯 Example Execution
<pre>Enter the input...
Hello(\t)world!  This(\t)is(\t)an(\t)example.

The output :
Hello   world!  This    is      an      example.</pre><br><br>



## 🛠 Example_2 - Entab: Efficient Array Usage in Text Processing

The entab program improves memory efficiency by replacing sequences of spaces with tab characters (\t) where possible. Instead of storing redundant spaces, it optimizes how text is represented in the character array while preserving alignment.<br><br>


### 🛠 Features

✔ Reads and processes user input efficiently.<br>
✔ Replaces consecutive spaces with tab characters when aligned with tab stops.<br>
✔ Ensures that the final text remains properly formatted.<br>
✔ Uses the array more effectively by reducing unnecessary space characters.<br><br>


### 📌 How It Works

1. **User Input**: The program reads a line of text into a fixed-size character array.
2. **Space Detection**: It scans for consecutive spaces and tracks tab stop positions.
3. **Tab Replacement**: When enough spaces reach a tab stop, they are replaced with a tab (\t), shifting the remaining text accordingly.
4. **Optimized Storage**: The updated string takes up less space in the array while maintaining structure.
5. **Output Display**: The processed text is printed for verification.<br><br>


### 📂 Code Structure
The program consists of three key functions:<br>

🔹 **getString()**
- Reads a line of input while ensuring it stays within the array size limit (ARRAY_SIZE).
- Handles newline characters, EOF conditions, and empty input cases.

🔹 **entab()**
- Scans the array to detect spaces and tab stop positions.
- Replaces spaces with tab characters where possible.
- Shifts the remaining text efficiently to maintain correctness.

🔹 **main()**
- Controls the execution flow, calling getString() and entab().
- Manages user interaction and displays results.<br><br>

  
### 🚀 Usage

1️⃣ Clone the repository:
<pre>git clone https://github.com/muhammedceberli/C-Professional-Examples</pre>

2️⃣ Compile the program:
<pre>gcc entab.c -o entab.exe</pre>

3️⃣ Run the program:
<pre>entab.exe</pre>

4️⃣ Enter input and observe the detabbed output.<br><br>


### 🎯 Example Execution
<pre>Enter the input...
Hello      world!  This    is   an     example.

Original :
Hello      world!  This    is   an     example.
Length before entab: 47

Entabbed:
Hello(\t)   world!  This(\t)   is(\t)an     example.
Length after entab: 43</pre><br><br>


## 🛠 Example_3 - 




