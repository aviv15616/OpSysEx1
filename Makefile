.PHONY: all clean 

SUBDIRS = Assignment1 Assignment2 Assignment3 Assignment4 Assignment5 Assignment6 Assignment7

all:
	@echo "🔨 Building all assignments..."
	@for dir in $(SUBDIRS); do \
		echo ">> Building in $$dir"; \
		$(MAKE) -C $$dir; \
	done

clean:
	@echo "🧹 Cleaning all assignments..."
	@for dir in $(SUBDIRS); do \
		echo ">> Cleaning in $$dir"; \
		$(MAKE) -C $$dir clean; \
	done
