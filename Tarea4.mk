# Tarea4.mk


all:PuntoNemo.pdf

PuntoNemo.pdf: Plots.py
	python $<

Plots.py: mapa.csv 
	python $@

mapa.csv: GeographicPoint.x
	./$< >> respuesta.csv

GeographicPoint.x: GeographicPoint.c
	cc $< -lm -o $@
