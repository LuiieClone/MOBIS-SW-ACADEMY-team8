OBJS = test1.o test2.o test3.o
SRCS = $(OBJS:.o=.c)
CFLAGES = -c -g

test:  $(OBJS)
	gcc -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGES) $<

clean:
	rm $(OBJS) test
