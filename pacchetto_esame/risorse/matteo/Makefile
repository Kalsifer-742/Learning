ODIR=target/obj/
UODIR=$(ODIR)utils/
UTILS_OBJS=$(UODIR)in.o $(UODIR)list.o $(UODIR)sort.o  $(UODIR)binary_search.o $(UODIR)stack.o $(UODIR)priority_queue.o $(UODIR)queue.o $(UODIR)tree.o 
FLAGS=-Wall -ggdb3 #-fsanitize=address

target/%.x: target/obj/%.o $(UTILS_OBJS) 
	g++ $(FLAGS) $< $(UODIR)*.o -o $@

target/obj/%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@

clean:
	rm target/*.x $(ODIR)*.o $(UODIR)*.o -f


#non elimina i file oggetto
.PRECIOUS: $(ODIR)%.o
