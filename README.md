# push_swap

INT MIN		-2147483648
INT MAX		2147483647
Range: de INT MIN à INT MAX

REGRAS DE MOVIMENTAÇÃO DE SORTING;
argc = numero de elemtos a serem sortados;
n = argc - 1;

se n=2, ou está em ordem, ou qualquer movimento sem ser o push na STACK A resolve;
	1 2 -> ok;
	2 1 -> SWAP || RR || RA || RRR || RRA -> 1 2;
desta forma temos nossas priemiras regras:
	* se n=2 e n1 < n2
	* se n=2 e n1 > n2, SWAP

se n=3 existem 9 possibilidades, ou seja, n! (n fatorial):
1 2 3 -> ok;
1 3 2 -> SWAP -> 312 -> RA;
2 1 3 -> SWAP;
2 3 1 -> RRA;
3 1 2 -> RA;
3 2 1 -> SWAP -> 231 -> RRA;
ainda dá pra fazer hardcoded em no maximo 2 ops sem muita dor de cabeça;
Com 4 elementos, as possibilidades aumentam para 24. 5 elementos: 120. 6: 720. E aí matemáticas...

Para fins de estudo e procrastinação, vou colocar aqui os 24 casos e tentar pensar na menor quantidade possivel de movimentos para cada:
1 2 3 4 -> ok;
1 2 4 3 -> RA -> 2431 -> RA -> 4312 -> SA -> 3412 -> RA -> 4123 -> RA -> ok;
1 3 2 4 -> RA -> 3241 -> SA -> 2341 -> RRA -> ok;
1 3 4 2 -> RRA -> 2134 -> SA -> ok;
1 4 2 3 -> SA -> 4123 -> RA -> ok;
1 4 3 2 -> SA -> 4132 -> RA -> 1324 -> RA -> 3241 -> SA -> 2341 -> RRA -> ok;				// PB -> 432/1 -> RRA -> 243/1 -> SA -> 423/1 -> RA -> 234/1 -> PA -> ok
2 1 3 4 -> SA -> ok;
2 1 4 3 -> RA -> 1432 SA -> 4132 -> RA -> 1324 -> RA -> 3241 -> SA -> 2341 -> RRA -> ok;	//SA -> 1243 -> PB -> 243/1 -> SA -> 423/1 -> RA -> 234/1 -> PA -> ok
2 3 1 4 -> RA -> 3142 -> SA -> 1342 -> RRA -> 2134 -> SA -> ok;								//RRA  -> 4231 -> PB -> 231/4 -> RRA -> 123/4 -> PA -> 4123 -> RA -> ok;
2 3 4 1 -> RRA -> ok;
2 4 1 3 -> RRA -> 3241-> SA -> 2341 -> RRA -> ok;
2 4 3 1 -> RA -> 4312 -> SA -> 3412 -> RA -> 4123 -> RA -> ok;
3 1 2 4 -> RRA -> 4312 -> SA -> 3412 -> RA -> 4123 -> RA -> ok;
3 1 4 2 -> SA -> 1342 -> RRA -> 2134 -> SA -> ok;
3 2 1 4 -> RA -> 2314 -> RA -> 3142 -> SA -> 1342 -> RRA -> 2134 -> SA -> ok;
3 2 4 1 -> SA -> 2341 -> RRA -> ok;
3 4 1 2 -> RA -> 4123 -> RA -> ok;
3 4 2 1 -> RA -> 4213 -> RA -> 2134 -> SA -> ok;
4 1 2 3 -> RA -> ok;
4 1 3 2 -> RA -> 1324 -> RA -> 3241 -> SA -> 2341 -> RRA -> ok;
4 2 1 3 -> RA -> 2134 -> SA -> ok;
4 2 3 1 -> SA -> 2431 -> RA -> 4312 -> SA -> 3412 -> RA -> 4123 -> RA -> ok;
4 3 1 2 -> SA -> 3412 -> RA -> 4123 -> RA -> ok;
4 3 2 1 -> SA -> 3421 -> RA -> 4213 -> RA -> 2134 -> SA -> ok;
Ao usar uma IDE (ou com um mínimo de atenção e/ou lógica), dá pra ver que sempre chegaremos a um estado onde dá para copiar o resto da solução. A merda é quais estados são os mais curtos para se solucionar. Por sorte, eu sou otário e já fiz isso por você.
Agora pense o seguinte: Ainda vale a pena introduzir um montão de regras que podem ou não funcionar, ou vale mais a pena só tascar uma tabelona de prints? Eu vou optar pela LUT mesmo porque já fiz na mão mesmo e não quero testar AINDA mais.
Note que não foi utilziado o push em nenhum momento, e que os movimentos mais complicados são variações do mesmo input mas com offsets: 4321, 3214, 2143, 1432. Nestes casos seria tão ou mais eficiente usar o push em conjunto do swap. Mas o que vale talvez realmente contar aqui são as quantidades de elementos que já estão em ordem, ou seja: no máximo 2.

Para 5 elementos, diz-se poder fazer em no máximo 11 movimentos (pelo menos é o que a régua diz). Se a gente aprendeu algo nos passados, é que a grandessíssima bosta está quando a coisa vem sortada, mas ao contrário, entao: 5 4 3 2 1 . Se isso se mantém verdade aqui, não sei, vamos testar:
5 4 3 2 1 -> PB -> 4321/5 -> PB -> 321/45 -> SA -> 231/45 -> RA -> 312/45 -> RR -> 123/54 -> PB -> 5123/4 -> PB -> 45123 -> RA -> 51234 -> RA -> ok;
9/11. Tá dentro da linha, tá bom o suficiente.
Mas isso foi no olho e na fé. Vamos pensar.

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
	0 1 2 3 5 7 9			// segunda iteração da memoização
	0 1 2 3 5 6 7 8			// terceira iteração da memoização
então temos que testar todos os elementos maiores que o elemento atual da comparação para podermos achar a sequencia braba. Isso num algoritmo de sorting normal seria uma grande merda de eficiência computacional em questão de tempo e memória, mas já que nosso benchmark é o número de movimentos printados, podemos tacar o foda-se com vontade.

Se levarmos em conta que toda quantidade de elementos terão 4 casos de resolução simples (um pronto, e outros 3 que podem ser resolvidos apenas com 1 movimento), dá pra fazer uma implementação simples para todos eles;
são eles:
0 1 2 3 ... n -> ok
1 0 2 3 ... n -> swap -> ok;
n 0 1 2 3... (n-1) -> RA || RR -> ok;
1 2 3 ... n 0 -> RRA || RRR -> ok;
então conseguimos criar nosso terceiro set de regras que é em verdade o segundo mas mais chic (gastando o francês aqui ó)
	*itera pela lista e conta em (i), se i+1=n quer dizer que veio na ordem correta. Beijo no ombro e me liga. Não faz nada e sai do programa.
	*caso 2, deixa pra pensar mais tarde
<!-- # COMPLETAR OS CASOS -->

Agora, vamos reutilizar o caso do primeiro exemplo de 5 elementos (5 4 3 2 1) pra já criar as regras pro caso mais bosta possivel e ver se funciona, pelo menos em pequena escala.
5 4 3 2 1 -> PB -> 4321/5 -> PB -> 321/45 -> SA -> 231/45 -> RA -> 312/45 -> RR -> 123/54 -> PB -> 5123/4 -> PB -> 45123 -> RA -> 51234 -> RA -> ok;
Saca só que já dei um migué e tinha implementado umas regrinhas básicas pra resolver esse BO:
primeiro acha a maior sequencia de numeros crescentes. Como eles estão em ordem reversa, temos apenas 2: 4 5 ou 3 4/5 ou 2 3/4/5 ou 1 2/3/4/5. Como decidir qual pegar? NÂO SEI. Vai ter que se na base do teste mesmo.
Mas bora criar uma regrinhas pra gente ir testando e depois vamos arrumando... Mas é claro, vamos sair de uns pressupostos meio que chutados:
1- usar comandos que mexam nas duas stacks ao mesmo tempo é bão que tu ganha 1 de lambuja: SA+SB==SR RA+RB==RR RRA+RRB==RRR;
2- PUSH B -> RA -> PUSH A == SWAP A -> RA; Então esse combo é ineficiente e se estiver no teu algorítmo vai tomar um cróque pra aprender;
3- Elementos ordenados não valem a pena de ser mexidos especialmente os que estão adjacentes, então se uma sequencia 345 aparece no seu STACK A, mantenha-a-aa-aaa-aà-á.
4- Qualquer coisa que não seja push não tem efeito se o STACK tiver apenas 1 elemento.
5- RRR/RR > SS > PUSH em VÁRIOS casos. Não se limite a 5 elementos e pense no pq. Se tiver uma STACK com 400 e outra com 100, fica mais fácil de visualizar na mente. Gosto de engrenagens.
Testa TOP_A e TOP_B: se TOP_A entrar em ordem crescente com um SWAP A e TOP_B entrar em ordem crescente com um SWAP B,


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


