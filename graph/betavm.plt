#!/usr/bin/gnuplot

set xlabel "{/:Italic β}"
set ylabel "〈|{/:Italic M}|^2⟩"

set format y '%.0f'

set term svg fname 'sans-serif' fsize 12
set termoption enhanced
set output "graph.svg"

unset key

plot "part2.dat" w l lc 3, "part2.2.dat" w l lc 6

#5, 3
#3, 6

#pause -1

