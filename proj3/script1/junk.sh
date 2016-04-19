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
 
argcount=0;
#echo $1; echo $2; echo $3
if [ "$1" = "--help" ] || [ "$2" = "--help" ] || [ "$3" = "--help" ]
    then
    echo "help requested"
    # set the flag for -l option
    optl=1
    # increment number of arguments (used for shifting)
    ((argcount+=1))
else
    while getopts ":ln" opt; do
      case $opt in
        l)
          echo "-l was triggered!" >&2
          let argcount=argcount+1
          ;;
        n)
          echo "-n was triggered!" >&2
          let argcount=argcount+1
          ;; 
        \?)
          echo "Invalid option: -$OPTARG" >&2
          ;;
      esac
    done
    echo "argcount = $argcount"
    echo "# = $#"
    echo "at 1 = $1"
    echo "at 2 = $2"
    echo "at 3 = $3"
    shift $argcount
    echo "at 1 = $1"
    echo "at 2 = $2"
    echo "at 3 = $3"
    
    let totalcount=$#-$argcount
    echo "totalcount = $totalcount"
    #if [ $totalcount = "0" ] ; then
    if [ $# = "0" ] ; then
        echo "Not enough arguments. Please specify a file"
    fi

    # for all files specified, move them to ~/.junk/ directory
    for filename in $*
    do
        echo "Moving $filename"
        # if .junk subdirectory doesn't exist, create it
        if [ ! -d "~/.junk/" ]; then
            mkdir "~/.junk/"
        fi
        # move the files to the .junk subdirectory
        mv $filename "~/.junk/$filename"
        ls $filename
        ls "~/.junk/" 
    done
fi

