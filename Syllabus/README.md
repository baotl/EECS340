# Course Description
This course provides an introduction to fundamental concepts in the design and implementation of computer communication networks, their protocols, and applications. Topics to be covered include: overview of network architectures, applications (HTTP, FTP), network programming interfaces (e.g., sockets), transport (TCP, UDP), flow control, congestion control, IP, routing , IPv6, multicast, data link protocols, error-detection/correction, multiple access, LAN, Ethernet, wireless networks, and network security. Examples will be drawn primarily from the Internet (e.g., TCP, UDP, and IP) protocol suite. Over the course of the quarter, students program in C++ on UNIX systems to build web clients and servers, and a fully compatible TCP/IP stack that can run them.

# Prerequisites
* Required: EECS 311 or equivalent data structures course
* Required: Knowledge of C and C++
* Required: EECS 213 or equivalent computer systems course
* Highly recommended: EECS 343 or equivalent operating systems course
* Highly recommended: Unix development experience (gcc, gdb, make, etc)

# Grading
There will be a midterm and a final exam. Exams will be in-class, closed-book, and will cover materials from lectures, required readings and projects. The final exam will not be cumulative.
* Homeworks 10%
* Projects 50%
* Midterm 20%
* Final 20%
 
# Homework
There will be two kinds of homework assignments: reading assignments and textbook-style questions. You should have finished the assigned reading before coming to lecture. In addition, there will be about four sets of written homeworks.

# Projects
Over the course of the quarter, you will implement a user-level TCP/IP stack and a small web server that runs on top of it. Your code will not implement the full functionality of HTTP or TCP/IP, but it will implement enough of it to be able to interoperate with other, complete implementations. In keeping with the top-down approach of Kurose and Ross, you will build this from the web server down instead of from the network card up. I will initially provide you with the whole stack (as object code) and you will implement the web server. Next, I will peal away the layers of the stack, leaving you to implement your own versions. Each layer will have well-defined interfaces that you will fill out. Here are the layers, as well as each one?s percentage of the project grade. Note that the layers in italics will be supplied to you and are included only for completeness.

* Project 1 (Sockets) 20%
* Project 2 (TCP) 50%
* Project 3 (routing) 30%

The implementation language will be C++ and the platform will be Red Hat Linux 9.0. We hope that you will use g++2.9.6 as your compiler, make as your build tool, and CVS as your version control system. You may also find that the C++ standard template library will make your life easier. You?ll be using the PCs in the TLAB, which will be specially configured for this class. You are welcome to use other machines, but we must be able to compile and run your code on our machines. Note that the Ethernet layer of the code requires that your kernel supports the Berkeley packet filter interface and that you can run your Ethernet card in promiscuous mode to extract and inject raw packets of such test cases. To evaluate your project, we will spot-check your source code, compile it, and run randomized testcases on it. When appropriate, we will supply you with examples. All the projects are to be done by teams of two students. Each team should work cooperatively on the design, implementation, and testing of their solutions. And the work should be shared in a fair manner. The submissions need to include a simple specification of work undertaken by each party.

# Late Policy
Unless otherwise indicated, homeworks and projects are due by the end of lecture on their due date. If you hand in an assignment late, we will take off 10% for each day (or portion thereof) it is late.

# Cheating Policy
It's OK to ask someone about the concepts, algorithms, or approaches needed to do the project assignments, I encourage you to do so; both giving and taking advice will help you to learn. However, what you turn in must be your own, or for projects, your group's own work; copying other people's code, solution sets, or from any other sources is strictly prohibited. We will punish transgressors severely.

# Schedule
| Date | Lecture Topics | Reading | Assignment |
| --- | --- | --- | --- |
| Wed 1/6 | Class overview, Computer Networks and the Internet (Internet architecture, protocols, circuit- and packet-switching) | Ch. 1.1-1.3, 1.7; Handout for project 1 | Project 1 out. Find partner (groups of up to 2). |
| Fri 1/8 | Computer Networks and the Internet (access networks, physical media, delay and loss, layered architecture, attacks) | Ch. 1.4 - 1.6 | Homework 1 out. |
| Wed 1/13 | Application Layer (Web, HTTP, FTP) | Ch. 2.1 - 2.3 | |
