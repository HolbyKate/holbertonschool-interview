# RAIN

## Requirements
### General
- Allowed editors: `vi, vim, emacs`
- All your files will be interpreted/compiled on `Ubuntu 14.04 LTS using python3 (version 3.4.3)`
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8 style (version 1.7.x)`
- You are not allowed to import any module
- All modules and functions must be documented
- All your files must be executable

````
cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))

jesse@ubuntu:~/$ ./0_main.py
6
6
```
Visual representation of the walls [0, 1, 0, 2, 0, 3, 0, 4]
[Image1]


Visual representation of the walls [2, 0, 0, 4, 0, 0, 1, 0]
[Image2]
