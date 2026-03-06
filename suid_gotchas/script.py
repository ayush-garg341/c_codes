#!/home/elliott/exec_suid  /usr/bin/python3
import os

print(f"Real UID:      {os.getuid()}")
print(f"Effective UID: {os.geteuid()}")
print(f"Real GID:      {os.getgid()}")
print(f"Effective GID: {os.getegid()}")
