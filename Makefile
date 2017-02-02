MAKE = make

CHAPTERS = $(shell find $(pwd) -type d -name "ch*")
clean_CHAPTERS = $(addprefix clean_,$(CHAPTERS))

all: $(CHAPTERS)
clean: $(clean_CHAPTERS)

.PHONY: force

$(CHAPTERS): force
	@$(MAKE) -C $@ all

$(clean_CHAPTERS): force
	@$(MAKE) -C $(patsubst clean_%,%,$@) clean 

sharedlib: 
	$(MAKE) all -C lib/

libclean:
	$(MAKE) clean -C lib/

# DO NOT DELETE THIS LINE
