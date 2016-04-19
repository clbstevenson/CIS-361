#!/bin/bash
# Syntax: junk [options] targetFileList
# Options: -l       list the current contents of the .junk directory
#          -n       shows the number of files in the .junk directory
#                       and the amount of memory space they consume
#          --help   display a brief descrition about this script
# Script 'junk' is replacement for the 'rm' commmand.
# Argument targetFileList is a list of filenames.
# Rather than removing the target files, 'junk' moves them
#   into the subdirectory .junk in the user's home directory.
# If the .junk subdirectory does not exist, it is automatically created.
# If a file with the same name as the file to be moved already
#   exists in .junk directory, keep the newer version of 
#   that file in the subdirectory.

#set $*
#!/bin/bash
 
while getopts ":l:n:help" opt; do
  case $opt in
    l)
      echo "-l was triggered!" >&2
      ;;
    n)
      echo "-n was triggered!" >&2
      ;; 
    help)
      echo "--help was triggered" >&2
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done
#    case $option in
#        l  )    echo "option long";;
#        n  )    echo "option num";;
#        help  ) echo "help!";;
#        \? )    if (( (err & ERROPTS) != ERROPTS ))
#                then
#                    error $NOEXIT $ERROPTS "Unknown option."
#                fi;;
#    esac
#done
#echo $1; echo $2; echo $3
#argcount=0
#if [ "$1" = "-l" ] || [ "$2" = "-l" ] || [ "$3" = "-l" ]
#    then
#    echo "long"
#    # set the flag for -l option
#    optl=1
#    # increment number of arguments (used for shifting)
#    ((argcount+=1))
#fi
#if [ "$1" = "-n" ] || [ "$2" = "-n" ] || [ "$3" = "-n" ]
#    then
#    echo "num"
#    # set the flag for -l option
#    optn=1
#    # increment number of arguments (used for shifting)
#    ((argcount+=1))
#fi
#if test "$optl" = 1
#    then echo "-l  $optl"
#fi
#if test "$optn" = 1
#    then echo "-n  $optn"
#fi
#echo "argc  $argcount"
