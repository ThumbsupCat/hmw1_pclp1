Task 1:

-dimen = variabila ce retine rezultatul functiei dim, dimensiunea operandului
-findn - prelucrarea numarului de instructiuni
-operatii = formeaza vectorul "semne" pentru a retine instructiunile ordinea aflarii lor

Task 2:

-nroper si nroper1 au ca rezultat formula pentru cate numere trebuie citite
M-am folosit de masti pentru a extrage fiecare numar de dimensiune dim, masca finala "mask" are "dimen" biti setati.
In for, am citit ((N+1)*Dimen)/16 numere si m-am folosit de 2 variabile operand si copie.
	-operand este numarul simplu, ce nu trebuie modificat in urma prelucrarii
	-copie are rolul de a extrage cei mai semnificativi "dimem" biti aftel incat sa ramana in final un numar format din "dimen" biti, iar apoi operandul
	 este retinut in vectorul v.
