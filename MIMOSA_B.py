# -*- coding: utf-8 -*-


import sys,subprocess

input_file = sys.argv[1]


call('bwa mem -t 2 -k 15 -a -v 0  db/gbk1113.fna ' +input_file+' > '+input_file+'.sam', shell=True )
call('./mimosa -B '+ input_file+'.sam')
