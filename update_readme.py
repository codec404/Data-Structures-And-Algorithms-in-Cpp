#!/usr/bin/env python3
"""Updates the Problem Tracker section in README.md based on git history."""

import subprocess
from collections import defaultdict
from datetime import datetime

DATE_PATTERN = __import__("re").compile(r"\d{2}-[A-Za-z]{3}-\d{2}")

def get_problems_per_date():
    result = subprocess.run(
        ["git", "log", "--name-status", "--pretty=format:MSG:%s"],
        capture_output=True, text=True
    )

    counts = defaultdict(int)
    current_date = None

    for line in result.stdout.splitlines():
        if line.startswith("MSG:"):
            msg = line[4:].strip()
            match = DATE_PATTERN.search(msg)
            if match:
                current_date = match.group(0).upper()
            else:
                current_date = None
        elif line.startswith("A\t") and line.endswith("PROBLEM.md"):
            if current_date:
                counts[current_date] += 1

    return counts

def build_tracker_table(counts):
    header = "| Date | Problems Solved |\n|------|----------------|"
    rows = [header]
    for date in sorted(counts, key=lambda d: datetime.strptime(d, "%d-%b-%y")):
        rows.append(f"| {date} | {counts[date]} |")
    return "\n".join(rows)

def update_readme(table):
    with open("README.md", "r") as f:
        content = f.read()

    tracker_header = "## Problem Tracker"
    if tracker_header in content:
        before = content[:content.index(tracker_header)]
        content = before + tracker_header + "\n\n" + table + "\n"
    else:
        content = content.rstrip() + "\n\n" + tracker_header + "\n\n" + table + "\n"

    with open("README.md", "w") as f:
        f.write(content)

if __name__ == "__main__":
    counts = get_problems_per_date()
    table = build_tracker_table(counts)
    update_readme(table)
    print("README.md updated.")
