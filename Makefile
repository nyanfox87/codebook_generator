VENV=.venv
PYTHON=$(VENV)/bin/python
PDF=codebook.pdf
SRC=codebook.tex
TEMP_FILES=*.aux *.log *.out *.toc *.lof *.lot *.fls *.fdb_latexmk *.synctex.gz

all: $(PDF)

$(PDF): generated_content.tex $(SRC)
	. $(VENV)/bin/activate && xelatex  $(SRC) > /dev/null
	@echo "Cleaning temp files..."
	@rm -f $(TEMP_FILES)

generated_content.tex: generate_codebook.py
	. $(VENV)/bin/activate && $(PYTHON) generate_codebook.py

clean:
	rm -f $(PDF) $(TEMP_FILES) generated_content.tex
