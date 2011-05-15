objs = weicaozuo.o d2b.o encryption.o exchange.o muiti.o
weicaozuo: $(objs)
	$(CC) $^ -o $@
sources = weicaozuo.c d2b.c encryption.c exchange.c muiti.c
include $(sources:.c=.d)
%d:%c
	set -e; rm -f $@;\
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$;\
	sed 's,\($*\)\o[ :]*,\1.o $@ : ,g' < $@.$$$$ >$@;\
	rm -f $@.$$$$
clean:
	@echo "cleanning project"
	-rm weicaozuo *.o
	@echo "cleanning completed"
.PHONY:clean
