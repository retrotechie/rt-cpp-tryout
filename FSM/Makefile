OBJS = main.o state_manager.o state.o menu.o about.o
CC = g++

FSM: $(OBJS)
	g++ -o FSM $(OBJS)
	rm -f $(OBJS)	# Remove *.o files

main.o:	
	$(CC) -c ./main.cpp	# -> main.o  

state_manager.o:
	$(CC) -c ./src/state_manager.cpp	# -> state_manager.o

state.o:
	$(CC) -c ./src/state.cpp	# -> state.o

menu.o:
	$(CC) -c ./src/menu.cpp	# -> menu.o

about.o:
	$(CC) -c ./src/about.cpp	# -> about.o

clean:	
	rm -f core FSM $(OBJS)	# -------------- Clean -------------- #

run:
	./FSM	# -------------- Run -------------- # 

rebuild:
	make clean; make	# -------------- Rebuild -------------- #
