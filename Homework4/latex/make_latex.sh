for D in $(find .. -type d)
do
   cp $D/homework*.c ../latex
   sed -i '/#include/d' ./homework*.c
   sed -i '/#define/d' ./homework*.c
   cp $D/notes* ../latex
   cp $D/out* ../latex
done

cat ramble > homework4.tex

for i in 1 2 3 4 5 6 
do
	echo  "\section{Question $i}" >> homework4.tex
	echo  "\subsection{Explanation}" >> homework4.tex
	cat notes$i.txt >> homework4.tex
	echo  "\subsection{Code:}" >> homework4.tex
	head -c -1 -q verb >> homework4.tex
	echo  "homework$i.c}" >> homework4.tex
	echo  "\subsection{Output:}" >> homework4.tex
	head -c -1 -q verb >> homework4.tex
	echo "out$i.txt}" >> homework4.tex
	cat outnotes$i.txt >> homework4.tex
done

#sed -e  's/verbatiminput/^\(\verbatiminput)/g' homework4.tex
echo "\subsection{PERLF.c}" >> homework4.tex
head -c -1 -q verb >> homework4.tex
echo "PERFL.c}" >> homework4.tex
echo "\end{document}" >> homework4.tex

pdflatex homework4.tex
evince homework4.pdf
