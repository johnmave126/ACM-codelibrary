# ~/.vimrc
set ts=4
set sts=4
set sw=4
set smartindent
set nu
set ruler
map <F9> :w<Enter>:!g++ -g -Wall -Wno-unused-variable -Wno-unused-result /*other switches*/ -o %:r %<Enter>
map <F5> :!./%:r<Enter>
map <F10> :!gdb %:r<Enter>