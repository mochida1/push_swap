# push_swap



REGRAS DE MOVIMENTAÇÃO DE SORTING;
argc = numero de elemtos a serem sortados;
n = argc - 1;

se n=2, ou está em ordem, ou qualquer movimento sem ser o push na STACK A resolve;
	1 2 -> ok;
	2 1 -> SWAP || RR || RA || RRR || RRA -> 1 2;
se n=3 existem 9 possibilidades, ou seja, n! (n fatorial):
1 2 3 -> ok;
1 3 2 -> SWAP -> 312 -> RA;
2 1 3 -> SWAP;
2 3 1 -> RRA;
3 1 2 -> RA;
3 2 1 -> SWAP -> 231 -> RRA;
ainda dá pra fazer hardcoded em no maximo 2 ops sem muita dor de cabeça;
Com 4 elementos, as possibilidades aumentam para 24. 5 elementos: 120. 6: 720. E aí matemáticas...

Para minimizar a quantidade de movimentos, queremos mexer na menor quantidade de elementos possível. E fazer isso é uma dor de cabeça do caralho.
Se nós soubessemos de antemão qual a ordem esperada de todos elementos, conseguiríamos apenas mover os que são necessários.
Saber onde cada coisa vai é simples: usa-se um sort qualquer para ordernar em um array diferente, portanto:
	5 2 4 8 6 9 3 1 iria resultar em {1, 2, 3, 4, 5, 6, 8, 9};

Agora que temos uma indexação maneira para servir como referência, para não produzir movimentos desnecessários, podemos achar a maior sequência indexável e maomeno a 'travamos', desta forma não entramos na armadilha de entrar num ciclo de SWAPs e ROTATEs.
Fazer isso não é tão simples: usando um stack(que não tem picas a ver com o STACK A ou B), testa cada elemento para achar a maior sequencia possível - isso quer dizer que não necessariamente a sequencia será iniciada pelo menor numero inputado;
	entao: dados os argumentos 5 2 4 8 6 9 3 1
a maior sequencia seria (note o uso do stack de memoização para o caso da decisão)
	12489 ou 12469 -> usa o menor ultimo possível: isso faz com que um swap POSSA resolver o problema; Veja que neste caso em específico, um swap entre 8 e 6 já resolveria.
o uso de momoização se faz necessário pelo seguinte fator:
	5 9 4 6 7 8 0 1 2 3		//input
	rodamos a busca da maior sequencia possivel:
	0 1 2 3 9				// se fizessemos com uma regra simples de achar o proximo maior
	0 1 2 3 5 7 9			// primeira iteração da memoização
	0 1 2 3 5 6 7 8			// segunda iteração da memoização
então temos que testar todos os elementos maiores que o elemento atual da comparação para podermos achar a sequencia braba. Isso num algoritmo de sorting normal seria uma grande merda de eficiência computacional em questão de tempo e memória, mas já que nosso benchmark é o número de movimentos printados, podemos tacar o foda-se com vontade.



Se levarmos em conta que toda quantidade de elementos terão 4 casos de resolução simples (um pronto, e outros 3 que podem ser resolvidos apenas com 1 movimento), dá pra fazer uma implementação simples para todos eles;

checa se o primeiro elemento de cada lista entrará na ordem caso haja um swap: se 5 ficar entre 4 e 6, dá um swap a; caso haja elementos na stack b e seu elemento do topo for entrar em ordem, dá swap s;
Caso nao haja swaps, push B
Checa se o elemento do topo de B entra em ordem se der push A, caso sim, push B;


8 5 2 4 9 7 1
1 2 4 5 7 8 9

2 4 9 7 1 //1 2 4 7
* * 8 5

pb
pb
//como saber se posso (rr) para poder inserir 5 no lugar certo?
SE HOUVER elementos em B, olha para o proximo elemento de B que possa ser inserido em A; se numero de rotações para inserí-lo for maior que o numero de rotações para chegar em seu espaço, olha para o próximo;
caso seja menor, usa RR ao invés de RA;


