XY
==
The [XY model](https://en.wikipedia.org/wiki/Classical_XY_model) is an O(2) model of spin statistics. 

In _d_ = 2 dimensions, the XY model exhibits an infinite-order topological phase change: the [Kosterlitz–Thouless transition](https://en.wikipedia.org/wiki/Kosterlitz%E2%80%93Thouless_transition).
 
This program simulates the XY model on a 2-dimensional lattice with periodic boundary conditions, which undergoes the Kosterlitz–Thouless transition at _β_ ≈ 0.5.

Build
-----
Clone and `make && make clean`. 

Run
---
`./xy`. Run with `--usage` or `--help` for help. It takes arguments for most parameters and will run with sane defaults if none are given.

<p align="center">
<img src="https://rawgithub.com/iamfionn/xy/master/graph/graph.svg" alt="[〈|_M_|^2〉 against _β_ for 10000 and 100000 iterations]" style="width: 480px;"/>
</p>

