#!/bin/bash


echo "Files before delete :"
ls -p | grep -v /


find . -name "*~" -type f -delete
echo "Deleted files ending with ~"

echo "Files after delete :"
ls -p | grep -v /
