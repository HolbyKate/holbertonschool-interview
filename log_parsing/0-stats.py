#!/usr/bin/python3
"""Module to parse logs and report statistics on HTTP status
codes and total file size."""

import sys


def parse_logs():
    """Function to parse logs from stdin and print statistics"""
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        """Read stdin"""
        for line in sys.stdin:
            parts = line.split()
            if len(parts) < 2:
                continue

            try:
                """Compute metrics"""
                status_code = int(parts[-2])
                file_size = int(parts[-1])
            except ValueError:
                """interruption"""
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
        """Keyboard interruption and print"""
        print("\nInterrupted")

    finally:
        """print"""
        print("Total file size:", total_size)
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print(f"{code}: {status_codes[code]}")


if __name__ == "__main__":
    parse_logs()
