CC=$(CROSS_COMPILE)gcc


writer: writer.o
	$(CC) -o writer writer.o


.PHONY: clean

clean:
	rm -f writer *.o
