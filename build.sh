#!/usr/bin/env bash
echo "Building Program..."
if gcc source/*.c -o myprogram; then
  echo "Program Built and Running..."
  echo "============================"
  ./myprogram
else
  echo "XXXXXXXXXX Error Building Program XXXXXXXXXX"
fi
