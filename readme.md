# README – OS Assignments Submission

This submission contains 7 completed assignments, each in its own directory:

```
Assignment1/
Assignment2/
Assignment3/
Assignment4/
Assignment5/
Assignment6/
Assignment7/
```

A top-level recursive Makefile automates building and cleaning all assignments:

## Top-Level Makefile (in root folder)

- `make` – builds all assignments
- `make clean` – cleans all assignments
- **Each assignment section includes its own run instructions.**



---

## Assignment1 – Signal Errors

### Files:
- `div_by_zero.c`
- `ndef_mem_acc.c`
- `stack_overflow.c`

### How to build:
```bash
make
```

### How to run:
```bash
./div_by_zero     # triggers SIGFPE
./ndef_mem_acc    # triggers segmentation fault
./stack_overflow  # triggers stack overflow
```

### Notes:
- Debug flags enabled (`-ggdb`) to allow GDB analysis
- Use core dumps to debug: see `cores/` directory 
- Each program crashes with a specific signal – suitable for `gdb` / `ddd` demo

---

## Assignment2 – Mandelbrot Number Test

### Files:
- `mandelbrot.c`

### How to build:
```bash
make
```

### How to run:
```bash
./mandelbrot <real> <image> <N(optional)>
```

### Notes:
- Reads complex number input in form: `real imag`
- Checks if the number belongs to Mandelbrot set
- result is printed based on iteration threshold(optional N input defaults to 1000)
- M = 2, is chosen as the constant( for cabs(complex num)> M, validation) based on convention.
 
---

## Assignment3 – Shared Library: Mandelbrot

### Files:
- `main.c`, `mandelbrot.c`, `mandelbrot.h`
- Builds shared object: `libmandelbrot.so`

### How to build:
```bash
make
```

### How to run:
```bash
make run
```

### Notes:
- Builds a shared library with `-fPIC` and `-shared`
- Main links dynamically with `-lmandelbrot`
- despite N being an argument of the "is_in_mandelbrot" function, it is defaulted to 1000, and not requested from the user, based on the assignment's requirements.
- Demonstrates use of dynamic libraries and linking
- Screenshot of successful usage included

---

## Assignment4 – Dijkstra + Code Coverage

### Files:
- `Dijkstra.cpp`, `GraphApp.cpp`, `GraphBuilder.cpp`

### How to build:
```bash
make
```

### How to run:
```bash
make run
```

### How to check code coverage:
```bash
1.use "make run" to run the program and test all edge cases you please (flags are set to check coverage).
2. afterwards use "make coverage-summary" that will print coverage precentage for each cpp file.
```

### Notes:
- Flags: `-fprofile-arcs -ftest-coverage -g`
- Interactive program (with stdin)
- Handles edge cases: self-loops, invalid input, fewer/more fields than expected
- if you want to view our coverage's summary from the terminal, use "make clean", copy our coverage's gcov's output files to "Assignment 4" folder, and run "make coverage-summary".
- `pause()`-based input validation ensures program is resilient

---

## Assignment5 – Profiling with gprof

### Files:
- `main.c`, `max_sub_arr.c`, `max_sub_arr.h`

### How to build:
```bash
make
```

### How to profile:
```bash
./prog <rand seed> <array size>
```
This creates `gmon.out`. Then run:
```bash
gprof prog gmon.out > profile.txt
```

### Notes:
- Compiled with `-pg` for profiling
- Finds max subarray sum – classic benchmark for time complexity

---

## Assignment6 – Signal Communication

### Files:
- `signal_sender.c`, `signal_receiver.c`

### How to build:
```bash
make
```

### How to run:
1. Open two terminals:
2. In terminal 1:
```bash
./signal_receiver
```
3. In terminal 2:
```bash
./signal_sender
Enter receiver PID: [PID from terminal 1]
Enter message: <number from 0 to 255>
```

### Notes:
- Demonstrates signal-based IPC
- Uses `usleep` between bits to avoid signal loss
- Uses `sigaction` and `sa_mask` to block nested signals (per instructions)
- Shows use of `pause()` to wait for signal
- Demonstrates robustness against quick signal burst

---

## Assignment7 – Phonebook Lookup with Process Pipeline and Logging

### Files:
- `add2PB.c` – Adds a record to `phonebook.txt` in CSV format  
- `findPhone.c` – Searches for a name using a pipeline of Unix commands (`cat`, `grep`, `sed`, `awk`)  
- `logger.c`, `logger.h` – Implements detailed logging to `findPhone.log`

### How to build:
```bash
make
```

### How to run:

**To add a new contact:**
```bash
./add2PB "John Doe" 0541234567
```

**To search for a contact:**
```bash
./findPhone "John Doe"
```

### Notes:
- `findPhone` creates 5 child processes connected via pipes:
  1. `cat phonebook.txt`
  2. `grep` the search term
  3. `sed 's/ /#/'` – replaces spaces with `#`
  4. `sed 's/,/ /'` – replaces commas with spaces
  5. `awk '{print $2}'` – extracts the phone number
- Each stage is **logged** with timestamps and process IDs in `findPhone.log`
- If `execve` fails, the failure is logged and printed to `stderr`
- `logger.c` handles all logging: stage starts, exec failures, child exits, parent waits

### Example:
```bash
./add2PB "Alice Wonderland" 0501112233
./findPhone "Alice"
```

**Expected Output:**
```
0501112233
```

The file `findPhone.log` will contain detailed logs of all process stages involved in the pipeline.


---

## General Notes
- Each assignment folder is self-contained with its own `Makefile`
- Screenshots and coverage reports are included where required
- All crash-generating programs tested under GDB with core dump enabled
- Submission follows OS course instructions precisely (POSIX-only, no Windows/mac)

---

