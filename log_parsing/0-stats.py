#!/usr/bin/python3
"""
A script that reads stdin line by line and computes metrics:
- Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
<status code> <file size>
- After every 10 lines and/or a keyboard interruption (CTRL + C),
prints statistics:
  * Total file size: File size: <total size>
  * Number of lines by status code in ascending order
Possible status codes: 200, 301, 400, 401, 403, 404, 405, and 500
If the format is not as expected, the line is skipped.
"""

import sys


def print_stats(total_size, status_counts):
    """
    Prints the total file size and the number of lines for each status code.
    """
    print(f"File size: {total_size}")
    for status_code in sorted(status_counts.keys()):
        if status_counts[status_code] > 0:
            print(f"{status_code}: {status_counts[status_code]}")


def parse_line(line):
    """
    Parses a line of the log and returns the status code and file size if valid
    """
    parts = line.split()
    if len(parts) < 9:
        return None, None

    try:
        status_code = int(parts[-2])
        file_size = int(parts[-1])
    except (ValueError, IndexError):
        return None, None

    return status_code, file_size


def main():
    """Main function to read stdin and compute the required metrics."""
    total_size = 0
    status_counts = {200: 0, 301: 0, 400: 0, 401: 0,
                     403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            status_code, file_size = parse_line(line)
            if status_code is None or file_size is None:
                continue

            total_size += file_size
            if status_code in status_counts:
                status_counts[status_code] += 1

            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise

    print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
