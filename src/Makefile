IN=tests/in/$(CTG)/test$(TEST).in
OUT=tests/out/$(CTG)/test$(TEST).out
AUX=tests/aux/$(CTG)/test$(TEST).aux

build:
	gcc kClique.c -o kClique

run_backtracking:
	./kClique $(IN) > $(OUT)

run_reduction:
	python3 kCliqueReduction.py $(IN) > $(AUX)

clean:
	rm -rf kClique
