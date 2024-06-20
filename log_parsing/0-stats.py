#!/usr/bin/python3
"""
Module to parse logs and report statistics on HTTP status
codes and total file size.

This module reads from stdin, processes each log entry to compute
the total file size and count of different HTTP status codes.
It prints the statistics every 10 lines and handles interruptions
gracefully.
"""

import sys
"""Import sys"""


def parse_logs():
    """
    Function to parse logs from stdin and print statistics.

    It reads each line from stdin, extracts the HTTP status code and file size,
    updates the total file size and counts of different status codes. Every 10
    lines, it prints the current statistics. It handles KeyboardInterrupt to
    print the final statistics before exiting.

    The expected log line format:
    <other data> <status_code> <file_size>

    Example:
    127.0.0.1 - - [2023-06-20 13:55:36] "GET /index.html HTTP/1.1" 200 1024
    """
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        """Read from stdin"""
        for line in sys.stdin:
            parts = line.split()
            if len(parts) < 2:
                continue

            try:
                """Compute metrics"""
                status_code = int(parts[-2])
                file_size = int(parts[-1])
            except ValueError:
                """Skip lines with invalid data"""
                continue

            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1
            line_count += 1

            if line_count % 10 == 0:
                print("Total file size:", total_size)
                for code in sorted(status_codes.keys()):
                    if status_codes[code] > 0:
                        print(f"{code}: {status_codes[code]}")

    except KeyboardInterrupt:
        """Handle Keyboard interruption and print final statistics"""
        print("\nInterrupted")

    finally:
        """Print final statistics"""
        print("Total file size:", total_size)
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print(f"{code}: {status_codes[code]}")


if __name__ == "__main__":
    parse_logs()
