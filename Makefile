VENV=.venv
PYTHON=$(VENV)/bin/python
PDF=codebook.pdf
SRC=codebook.tex
TEMP_FILES=*.aux *.log *.out *.toc *.lof *.lot *.fls *.fdb_latexmk *.synctex.gz _minted-codebook/

all: $(PDF)

$(PDF): generated_content.tex $(SRC)
	xelatex -shell-escape $(SRC) > /dev/null
	xelatex -shell-escape $(SRC) > /dev/null
	@echo "Cleaning temp files..."
	@rm -rf $(TEMP_FILES)

generated_content.tex: generate_codebook.py
	. $(VENV)/bin/activate && $(PYTHON) generate_codebook.py

clean:
	rm -rf $(PDF) $(TEMP_FILES) generated_content.tex

clean_without_pdf:
	rm -rf $(TEMP_FILES) generated_content.tex
