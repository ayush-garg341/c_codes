- There is a c code exec_suid.c which we will compile as binary and set SUID bit on it. SUID bit on binaries is not removed by linux.
    - Compile: gcc exec_suid.c -o exec_suid
    - chown root:root exec_suid ( This will set the owner and group to root )
    - chmod u+s exec_suid ( Set the SUID bit on the binary )
    - Now try to execute ./exec_suid without any arguments passed to it and you will see error of its usage.

- Create another python script, script.py
    - Print the real UID, effective UID, real GID and effective GID in the script with the help of OS module.
    - Make it executable: chmod +x script.py
    - Set SUID bit on it: chmod +s script.py
    - Now run it, ./script.py ( remove exec_suid from the very first shebang line ) and you will see your own user, group ID. Because even after SUID bit set, that will be dropped by the Linux.
    - Now run it again, but this time keep exec_suid shebang on top and you will see root user effective UID. Because now python script executes via our custom suid_exec binary on which we already set SUID bit.
        - kernel reads shebang -> invokes exec_suid
    - Now run it again but like: python3 ./script.py: you will see this time even after having proper shebang (including exec_suid), it's being run via your own user ID and group ID and not root's. Why so? the main reason is:
        - You're explicitly invoking the interpreter yourself.
        - The kernel never looks at the shebang line at all.
        - Python just reads the file as source code, shebang line is treated as a comment (starts with #).

