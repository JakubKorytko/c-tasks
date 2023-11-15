tasks = $(wildcard Tasks_*/task_*.c)
projects = $(wildcard Projects/project_*.c)
data_file = Tasks_5/task_3-5_DATA.txt

out_dir = out

.PHONY: all clean tasks_1 tasks_2 tasks_3 tasks_4 tasks_5 tasks_6 projects

all: compile_all

make_out_dirs:
	@mkdir -p $(out_dir)
	@mkdir -p $(out_dir)/Tasks_1
	@mkdir -p $(out_dir)/Tasks_2
	@mkdir -p $(out_dir)/Tasks_3
	@mkdir -p $(out_dir)/Tasks_4
	@mkdir -p $(out_dir)/Tasks_5
	@mkdir -p $(out_dir)/Tasks_6
	@mkdir -p $(out_dir)/Projects

$(out_dir)/%: %.c
	@echo "Compiling $<..."
	@gcc $< -lm -o $@
	@echo "Done!"

$(out_dir)/$(data_file): $(data_file)
	@echo "Copying data file..."
	@cp $(data_file) $@
	@echo "Done!"

compile_all: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(tasks)) $(out_dir)/$(data_file) $(patsubst %.c, $(out_dir)/%, $(projects))

tasks_1: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Tasks_1/task_*.c))
tasks_2: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Tasks_2/task_*.c))
tasks_3: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Tasks_3/task_*.c))
tasks_4: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Tasks_4/task_*.c))
tasks_5: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Tasks_5/task_*.c)) $(out_dir)/$(data_file)
tasks_6: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Tasks_6/task_*.c))

projects: make_out_dirs $(patsubst %.c, $(out_dir)/%, $(wildcard Projects/project_*.c))

clean:
	@echo "Cleaning up..."
	@rm -rf $(out_dir)
