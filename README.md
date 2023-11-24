# C tasks

[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

[![Open Source Love svg1](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![Run Super-Linter](https://github.com/JakubKorytko/c-tasks/actions/workflows/super-linter.yml/badge.svg?branch=0.1.0)](https://github.com/JakubKorytko/c-tasks/actions/workflows/super-linter.yml?branch=0.1.0)
[![Run make to check for errors](https://github.com/JakubKorytko/c-tasks/actions/workflows/make.yml/badge.svg?branch=0.1.0)](https://github.com/JakubKorytko/c-tasks/actions/workflows/make.yml?branch=0.1.0)

## Table of Contents

- [C tasks](#c-tasks)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Adding a new task](#adding-a-new-task)
  - [Contributing](#contributing)
  - [Contact](#contact)
  - [License](#license)

## Introduction

This repository contains my solutions to various tasks and projects in C (44 in total).

It is not only that,
but also a template that allows you to easily add new tasks and compile them
or even rebuild the whole project for your own tasks or projects.

The tasks are divided into folders by task number and a `Tasks_` prefix.
There is also a [Projects](./Projects/) folder which contains more complex tasks.

Each task folder has a corresponding `.pdf` file in the [docs](./docs/) directory
with the same name as the folder in which the task is stored.
This file contains the description of the task.

Tasks can be compiled with `make` (see [Installation](#installation))
all at once or one at a time.

Some of the tasks are elementary
(like calculating the difference between two numbers),
some are more complex
(such as comparing expected and actual values of the Taylor series of the cosine function).

## Prerequisites

Before you begin, make sure you have the following prerequisites installed on your system:

- [GNU Make 4.4.1 or later](https://www.gnu.org/software/make/)
- [GNU GCC 11.4 or later](https://gcc.gnu.org)

## Installation

1. Clone this repository to your local machine using Git,
or download the ZIP file and extract it to a directory of your choice:

    ```bash
    git clone https://github.com/JakubKorytko/c-tasks.git
    ```

1. Change to the project directory:

    ```bash
    cd c-tasks
    ```

1. Compile all tasks or just one:

    - To compile all tasks, run the following command:

        ```bash
        make
        ```

    - To compile a single task, run the following command:

        ```bash
        make <folder_name>
        ```

        where `<folder_name>` is the name of the task folder (e.g. `Tasks_1`).

    The compiled executables will be placed in the `out` directory,
    in the corresponding task folder.

## Usage

To run a task, go to the task folder and run the executable file:

```bash
cd <folder_name>
./<executable_name>
```

where:

- `<folder_name>` is the name of the task folder (e.g. `Tasks_1`),
- `<executable_name>` is the name of the executable file (e.g. `task_1` / `task_1.exe`).

The use of the program depends on the task.
The description of each task can be found in the `.pdf` file in the [docs](./docs/) directory
with the same name as the task folder.

## Adding a new task

*By design, a task (folder) consists of many subtasks (source files).
In this section, the term "task" refers to a folder containing many source files.
If you want to use a single source file, you will still need to create a folder for it.*

1. Create a new folder (any name will do) in the root directory. This will be the task folder.
2. Add source files to the new folder. They must follow the rules:
    - Each file must be a standalone C program (must contain a `main` function).
    - Each file must have a prefix of any type (e.g. `task_`).
3. Open `Makefile` in the root directory.
    1. Add the name of the new folder to the `tasks` variable.
    2. You can change the name of the output directory by changing the `out_dir` variable.
    (this applies to all tasks)
    3. If you need to copy some files (like input files) to the output directory,
    use the following syntax:

        ```makefile
        $(call copy_file,<FILE_TO_COPY>)
        ```

        where `<FILE_TO_COPY>` is the name of the file to copy.
        This creates a new rule that copies a **single** file to the output directory.

        Now you can use the name of the file as a dependency for other rules.
        If you need to use variable in the name of the file,
        you probably need to wrap the `call` in `eval`:

        ```makefile
        $(eval $(call copy_file,<FILE_TO_COPY>))
        ```

    4. To create a rule for the task, use the following syntax:

        ```makefile
        $(call task,<TASK_FOLDER_NAME>,<PREFIX><ADDITONAL_DEPENDENCY>)
        ```

        where:

        - `<TASK_FOLDER_NAME>` is the name of the task folder,
        - `<PREFIX>` is the source file prefix,
        - `<ADDITONAL_DEPENDENCY>` is an optional additional dependency.

        For example, you can add a copied file there.
        If you need more dependencies, you can create a new rule
        that includes them all and use it as `<ADDITONAL_DEPENDENCY>`.

        This will create a new rule that will compile all the source files in the task folder
        and place the executables in the output directory in the corresponding task folder.
4. You can now run `make` or `make <TASK_FOLDER_NAME>` from the root directory to compile the task.
5. If you want to add a description of the task,
create a `.pdf` file in the [docs](./docs/) directory with the same name as the task folder.

## Contributing

If you find issues or have suggestions for improvements,
feel free to open an issue or submit a pull request.
Contributions are welcome!

## Contact

If you have any questions, feel free to contact me at <jakub@korytko.me>.

## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for details.
