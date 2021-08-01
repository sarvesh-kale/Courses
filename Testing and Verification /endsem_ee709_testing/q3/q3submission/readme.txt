execute the following on linux terminal 
if picosat is not installed (since ubuntu is most common linux flavor aptitude package manager apt-get is used )

the $ denotes the terminal .
make sure that the present working directory has these files 
q3lowernor.cnf and q3uppernand.cnf

$ sudo apt-get install picosat    // if picosat installed do not use this directly run next command 
$ picosat --all q3lowernor.cnf 

output will be displayed

$ picosat --all q3uppernand.cnf

output will be displayed

$ picosat --all q3uppernor.cnf >> output.txt 
 this is generate output file output.txt
