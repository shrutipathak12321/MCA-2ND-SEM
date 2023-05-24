#!/bin/bash
if [ $# -eq 0 ]; then
  echo "No argument given"
  exit 1
fi
for dir in "$@"; do
  if [ -d "$dir" ]; then
    echo "$dir"
    echo "Disk space usage in bytes:"
    du -b "$dir"
    echo "Disk space usage in kilobytes or megabytes:"
    du -h "$dir"
  else
    echo "$dir is not a valid directory"
  fi
  echo "Total size of the directory is "
  echo "$(du -sh "$dir")\n"
done
