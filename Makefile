tasks = Tasks_1 Tasks_2 Tasks_3 Tasks_4 Tasks_5 Tasks_6 Projects
out_dir = out

include Makefiles/Macros.mk
include Makefiles/Targets.mk

$(call copy_file,Tasks_5/task_3-5_DATA.txt)

$(call compile,Tasks_1,task_)
$(call compile,Tasks_2,task_)
$(call compile,Tasks_3,task_)
$(call compile,Tasks_4,task_)
$(call compile,Tasks_5,task_,Tasks_5/task_3-5_DATA.txt)
$(call compile,Tasks_6,task_)
$(call compile,Projects,project_)