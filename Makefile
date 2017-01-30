MAKE = make

all:
	$(MAKE) all -C ch*/

sharedlib: 
	$(MAKE) all -C lib/

libclean:
	$(MAKE) clean -C lib/

clean:
	$(MAKE) clean -C ch*/

# DO NOT DELETE THIS LINE
