#!/bin/bash
set -e

VENV=".venv"
PYTHON="$VENV/bin/python"
PDF="codebook.pdf"
TEMP_FILES="*.aux *.log *.out *.toc *.lof *.lot *.fls *.fdb_latexmk *.synctex.gz"

echo "[1/5] Activating venv..."
source "$VENV/bin/activate"

echo "[2/5] Generating LaTeX content..."
$PYTHON generate_codebook.py

echo "[3/5] Removing old PDF..."
rm -f "$PDF"

echo "[4/5] Compiling LaTeX..."
xelatex  codebook.tex > /dev/null

echo "[5/5] Cleaning temp files..."
rm -f $TEMP_FILES

deactivate
echo "✅ Done! PDF generated: $PDF"
