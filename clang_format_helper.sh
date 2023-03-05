#!/bin/bash

BASEDIR=$(dirname $(readlink -f "$0"))

CLANGFORMATCOMMAND=clang-format

if [ -n "$2" ]; then
   CLANGFORMATCOMMAND="$2"
fi

case "$1" in
    "--check")
	find ${BASEDIR}/ -regex '.*\.\(cpp\|hpp\|h\|cc\|cxx\)' -exec ${CLANGFORMATCOMMAND} -style=file --dry-run --Werror {} +;;
    "--format")
	find ${BASEDIR}/ -regex '.*\.\(cpp\|hpp\|h\|cc\|cxx\)' -exec ${CLANGFORMATCOMMAND} -style=file -i {} +;;
esac
