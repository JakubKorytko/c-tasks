.PHONY: all clean $(tasks)
all: compile_all

compile_all: $(tasks)

$(out_dir)/%: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@gcc $< -lm -o $@
	@echo "Done!"

clean:
	@echo "Cleaning up..."
	@rm -rf $(out_dir)