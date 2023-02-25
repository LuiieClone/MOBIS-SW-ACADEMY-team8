OBJS = stack.o main.o

main : $(OBJS)
	g++ -o $@ $(OBJS)
.cpp.o:
	g++ -c $<

clean:
	rm main $(OBJS)