# Memory-Cpu-Hog-Finder

From standard input, this program reads input in the same format as produced by the ps program with the aux argument (ps aux) on linux

This proram takes a command-line argument specifying a username, and will print some information about one process owned by this user to standard output.

It accepts an optional command-line argument of -m or -c, which must come before the username. Only one of these arguments may be provided. If -c is provided, your program reports the user's process that has the highest value for CPU usage. If -m is provided, your program reports the user's process that has the highest memory usage instead. If neither argument is provided, it reports the process with the highest CPU usage.

The output of this program is one line containing the PID, usage value (either memory or CPU - whichever is being compared) with exactly one digit after the decimal, and command, separated by tabs ('\t').

If the input does not contain any processes owned by the specified user, it returns no input. This is not an error.

usernames and commands will be at most SIZE characters, currently set at 127.
