# push_swap



REGRAS DE MOVIMENTAÇÃO DE SORTING;
argc = numero de elemtos a serem sortados;
n = argc - 1;

usando memoização, testa cada elemento para achar a maior sequencia possivel - isso quer dizer que não necessariamente a sequencia será iniciada pelo menor numero inputado;
entao: dado o array {5, 2, 4, 8, 6, 3, 1}
a maior sequencia seria
1248 ou 1246 -> usa o menor ultimo elemento possível: isso faz com que um swap POSSA resolver o problema;

usa um sort qualquer para ordernar em um array diferente, logo: {1, 2, 3, 4, 5, 6, 8};

checa se o primeiro elemento de cada lista entrará na ordem caso haja um swap: se 5 ficar entre 4 e 6, dá um swap a; caso houvessem elementos na stack b, lembrando que a stack b tem os seus elementos ordernados em ordem reversa, e seu elemento do topo for entrar em ordem decrescente, dá swap s;
Caso nao haja swaps, push B
Checa se o elemento do topo de B entra em ordem se der push A, caso sim, push B;

8 5 2 4 9 7 1
1 2 4 5 7 8 9

2 4 9 7 1 //1 2 4 7
8 5

pb
pb
//como saber se posso (rr) para poder insirir 5 no lugar certo?