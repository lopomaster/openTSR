NOM = memoria
DOC = $(NOM).tex

PDF = pdflatex
BIB = bibtex
LATEX = latex
DVI = dvipdf

EPSTOPDF = epstopdf
DOT = dot

DIRIMAGENES = imagenes imagenes/dot imagenes/tex

ARCHIVOSDOT		:=	$(foreach dir,$(DIRIMAGENES),$(wildcard $(dir)/*.dot))
ARCHIVOSEPS		:=	$(foreach dir,$(DIRIMAGENES),$(wildcard $(dir)/*.eps))
ARCHIVOSTEXAUX := $(foreach dir,$(DIRIMAGENES),$(wildcard $(dir)/*.tex))

# Por defecto: compila usando BibTeX para las referencias bibliográficas.
# Antes que nada genera los gráficos en .pdf a partir de los .dot y
# los .eps y los .tex auxiliares
pdf-bib: $(ARCHIVOSDOT:.dot=.pdf) $(ARCHIVOSEPS:.eps=.pdf) $(ARCHIVOSTEXAUX:.tex=.pdf)
	$(PDF) $(DOC) && $(BIB) $(NOM) | make pdf

# No tendremos en cuenta las referencias bibliográficas. Seguramente de error
pdf: $(DOTFILES:.dot=.pdf) $(EPSFILES:.eps=.pdf) $(ARCHIVOSTEXAUX:.tex=.pdf)
	$(PDF) $(DOC) && $(PDF) $(DOC)

latex-bib:
	$(LATEX) $(DOC) && $(BIB) $(NOM) | make latex

latex:
	$(LATEX) $(DOC) && $(LATEX) $(DOC)

# Pasa de .dvi a .pdf
dvi-pdf:
	$(DVI) $(NOM).tex

clean:
	$(RM) *.aux *.toc *.log \
	*.lof *.lot *.out *.bbl \
	*.blg *~ *\#
	$(RM) -r auto


clean-all:
	make clean
	$(RM) $(ARCHIVOSDOT:.dot=.pdf) \
	$(ARCHIVOSEPS:.eps=.pdf) \
	$(ARCHIVOSTEXAUX:.tex=.pdf) \
	$(NOM).pdf $(NOM).dvi

%.eps: %.dot
	$(DOT) -Tps $< > $@

%.pdf: %.eps
	$(EPSTOPDF) $< > $@

%.pdf: %.tex
	$(PDF)  $<
	mv $(notdir $@) $(dir $@)
