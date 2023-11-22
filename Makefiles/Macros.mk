define copy_file
$(out_dir)/$1: $1
	@echo "Copying $1..."
	@cp $1 $(out_dir)/$1
	@echo "Done!"
endef

define compile
$1: $(patsubst %.c, $(out_dir)/%, $(wildcard $1/$2*.c)) $3
endef