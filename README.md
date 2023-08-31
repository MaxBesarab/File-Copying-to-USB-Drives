# File Copying to USB Drives
This project consists of a C++ program that solves the problem of copying files onto two USB drives. The program selects files and distributes them between the two drives in order to maximize the number of copied files.
Problem Description

The task is as follows:

    Given files with their sizes and two USB drives with fixed capacities.
    The goal is to choose files and distribute them between the two drives in order to maximize the number of copied files.
    Files cannot be divided, and each file fits entirely onto a drive.
    Program should output lists of files copied onto each drive.

Solution Overview

The program utilizes a sorting algorithm to arrange files in descending order based on their sizes. It then selects and distributes files onto the drives while considering the size constraints. The program is implemented in C++ and follows these steps:

    Read input data: the number of files, drive capacities, and information about each file.
    Sort files by size.
    Choose and distribute files onto the drives, taking size constraints into account.

Note

This project is created for educational purposes and demonstrates a solution to a specific problem. If you have any suggestions for improving the code or functionality, feel free to submit a pull request.
