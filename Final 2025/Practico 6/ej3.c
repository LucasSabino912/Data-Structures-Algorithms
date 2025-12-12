/* Implementar el TAD Cola utilizando la siguiente representación, dónde N es una constante de tipo nat

ímplement Queue of T where

type Queue of T = tuple
					elems: array[0..N-1] of T
					size: nat
				  end tuple */

fun empty_queue() ret q: Queue of T
	q.zize:= 0
end fun

proc enqueue(in/out q: Queue of T, in e: T)
	q.size:= q.size + 1
	q.elems[q.size+1]:= e
end proc

fun is_empty(q: Queue of T) ret b: bool
	b:= q.size = 0
end fun

fun first(q: Queue of T) ret e: T
	e:= q.elems[0]
end fun

proc dequeue(in/out q: Queue of T)
	for i:= 1 to N-1 do
		q.elems[i-1]:= 1.elems[i]
	od
	q.size(N-1)-1
end proc