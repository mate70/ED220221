all: clear pointers list dlist hash  genlist bst

pointers:
	@echo -e "\nCompilando ponteiros"
	gcc pointers.c -o pointers
	gcc pointers2.c -o pointers2
	@echo -e "\nHabilitando execução"
	chmod +x pointers
	chmod +x pointers2

list:
	@echo -e "\nCompilando Listas Dinâmicas"
	gcc LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	@echo -e "\nHabilitando execução"
	chmod +x linkedlist

dlist:
	@echo -e "\nCompilando Listas Duplas Dinâmicas"
	gcc DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o doublylinkedlist
	@echo -e "\nHabilitando execução"
	chmod +x doublylinkedlist

hash:
	@echo -e "\nCompilando Hash"
	gcc log.h log.c DoublyLinkedList.h DoublyLinkedList.c Hash.h Hash.c HashTest.c -std=c99 -o hash
	@echo -e "\nHabilitando execução"
	chmod +x hash

blockchain:
	@echo -e "\nCompilando Blockchain"
	gcc log.h log.c sha-256.h sha-256.c Blockchain.h Blockchain.c BlockchainTest.c -std=c99 -o blockchain
	@echo -e "\nHabilitando execução"
	chmod +x blockchain

genlist:
	@echo -e "\nCompilando Lista Generalizada"
	gcc log.h log.c GeneralizedList.h GeneralizedList.c -std=c99 -o genlist
	@echo -e "\nHabilitando execução"
	chmod +x genlist

bst:
	@echo -e "\nCompilando Árvore de Busca Binária"
	gcc BinarySearchTree.h BinarySearchTree.c BinarySearchTreeTest.c -std=c99 -o bst
	@echo -e "\nHabilitando execução"
	chmod +x bst

clear:
	@echo -e "\nRemovendo arquivos objeto"
	rm -f pointers pointers2 linkedlist doublylinkedlist hash blockchain genlist bst
