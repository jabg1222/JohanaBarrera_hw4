# Tarea4.mk


all: mapa.png

mapa.png: Plots.py
	python $<

Plots.py: mapa.csv
	python $@

mapa.csv: GeographicPoint.x
	./$< >> $@

GeographicPoint.x: GeographicPoint.c
	cc $< -lm -o $@
