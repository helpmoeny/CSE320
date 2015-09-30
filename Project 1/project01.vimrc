
" Initialization commands for vim
"
" Additional documentation is available at:
"   http://vimdoc.sourceforge.net

" Alternative terminal types
"
" set term=builtin_ansi
" set term=sun-color

set term=xterm-color


" Don't force vim to act like vi
"
set nocompatible


" Use 80 as the width of one line and wrap long lines
"
set textwidth=80
set wrap


" Show status info at the bottom of the screen
"
set showcmd
set ruler


" Enable syntax highlighting
"
syntax on


" Enable C/C++ indenting
"
set cindent


" Expand tabs into 2 spaces (except for makefiles)
"
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab
autocmd FileType  make      setlocal noexpandtab
autocmd FileType  makefile  setlocal noexpandtab

