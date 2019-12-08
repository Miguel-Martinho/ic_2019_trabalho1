# Relatório do Mini-projeto de computação
----
## Miguel Martinho 21901530 (Pandora: random)

## Descrição da solução
A primeira coisa que fiz foi escrever a lógica do código e cheguei á conclusão de que iria fazer o código da seguinte forma: Criar um ciclo para iterar o jogo, neste caso o while, estabelecer as opções do menu (***s*** ***q*** e ***m***) e definir o que iria acontecer se o jogador colocasse a letra ***p***. 

Dentro do ***if*** da letra ***p*** teria criar um ***array*** com os números randomizados utilizando a função ***rand***, pedir números ao utilizador e compará-los com os números randomizados para ver se podia verificar se a ordem estava correta ou não. *(Apenas após acabar o código percebi que podia simplesmente utilizar o array randomizado e reorganizá-lo em vez de criar uma cópia, mas foi mais simples para mim na altura.)* A seguir a ter esta estrutura básica feita apenas teria de definir quando adicionar valores ás variáveis ***plays*** ***points*** e ***level*** e no fim fazer as verificações para ver se o nível terminou. No repositório github coloquei um ficheiro txt no qual estão algumas das minha soluções para alguns dos problemas como organizar as listas compará-las e fazer algumas das funções que usei, mas da maneira mais "hardcoded" sem ciclos.

----
## Estrutura do Software
        - começamos com um while e verificamos quais os inputs do menu que o utilizador coloca, sendo o último o p, depois dentro da instrução *else if* do *p*  utilizo uma função *minmax_gen* que vai buscar o intervalo dos números para a função *rand_number* baseado no nível em que estamos, após gerarmos estes números fiz um *do while* para que o programa apenas verifique se os números estão bem ordenados após ter acerteza que os números que o utilizador deu estão de acordo com o *array randomizado*
        - dentro deste *do while* peço input ao utilizador sobre os números, crio uma lista e organizo-a (agora reparo também que podia ter feito a criação e organização da lista após o do while já que a verificação da ordem também só ocorre após o do while) faço a comparação dos números dados pelo utilizador e dos números randomizados para ver os números estão corretos.
        - A seguir a este do while, verifico se o utilizador ordenou bem os números ou não e mexo nas variaveis de acordo com a resposta, saio do *else if* do *p* temos o *else* do input do menu caso a opção dada esteja errada e faço a verficação se o jogo acabou ou não. 

-----
## Conclusões e matéria aprendida

Programar pode ser chato

É bastante melhor trabalhar em equipa porque os erros que eu posso não estar a ver os meus colegas reparam.

Escrever o relatório deve ser feito mais cedo e antes de entregar o código porque me permite, tal como descrito acima, ver que havia partes do código que podiam ser melhoradas facilmente.

Aprendi no geral a programar melhor, melhorei a maneira como penso em iterar as coisas.
A utilizar a função seed +/- ainda fiquei um pouco confuso porque pedi ajuda a um amigo(não da lusófona) e a função sscanf confudiu me um pouco mas percebi a geração da seed apartir do tempo atual e que o argc é o número de argumentos dados ao programa, neste caso 2 nome e seed e argv é o que eles são essencialmente. E nesse if verifica se existem menos de dois argumentos dados ao programa ou seja, se há seed ou não, e se não houver ele cria uma baseada no tempo.

-----
## Referências, trocas de ideias, bibiotecas e código reutilizado
utilizei a parte do código deste site para ordenar o ***array organized_list***.

https://en.wikiversity.org/wiki/C_Source_Code/Sorting_array_in_ascending_and_descending_order

Utilizei este site para perceber o erro dado ao submeter o código na Pandora, com a função level graças aos ***if's***.

https://cs50.stackexchange.com/questions/2448/how-to-solve-control-may-reach-end-of-non-void-function-error 

Utilizei este site para perceber o erro dado ao submeter o código na Pandora, porque me esqueci de um = no while e como não podia igualar dois valores na condição do while e programa sabe disso, ele assumiu que era == na mesma, mas graças a uma das verificações tive de ser "mais específico" e colocar o outro =.

https://stackoverflow.com/questions/5476759/compiler-warning-suggest-parentheses-around-assignment-used-as-truth-value

Utilizei esse site, pois tal como referido acima estava á procura de uma forma de retornar um array, sendo os ponteiros a melhor que encontrei.

https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm

Discuti ideias com 
Pedro Coutinho 21905323
E com o grupo do Fransisco Salgado, João Fonseca e João Gonçalves

bibliotecas usadas:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>