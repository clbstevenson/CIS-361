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
flag_l=0;
flag_n=0;
#echo $1; echo $2; echo $3

#if --help is specified, do not do any other options
if [ "$1" = "--help" ] || [ "$2" = "--help" ] || [ "$3" = "--help" ]
    then
    echo "Help Page for junk.sh"
    echo "Syntax: junk [options] [file1, file2, ...]"
    echo "Options: -l       list the current contents of the .junk directory"
    echo "         -n       shows the number of files in the .junk directory"
    echo "         --help   display this brief help description" 
    echo
    echo "Script 'junk' is a replacement for the 'rm' command.\n
        Rather than removing the listed files, 'junk' moves them\n
        into the subdirectory .junk in the user's home directory."
    echo "If the .junk subdirectory does note xist, it is utomatically created."
    echo "If a file with the same name as the file to be moved already\n
        exists in .junk directory, keep the newer version of that file."
    # print some help information to the user
    ((argcount+=1))
else
    while getopts ":ln" opt; do
      case $opt in
        l)
            #echo "-l was triggered!" >&2
            # increment number of arguments (used for shifting)
            let argcount=argcount+1
            flag_l=1;
            ;;
        n)
            #echo "-n was triggered!" >&2
            flag_n=1;
            # increment number of arguments (used for shifting)
            let argcount=argcount+1
            ;; 
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit
            ;;
      esac
    done
    #echo "argcount = $argcount"
    #echo "# = $#"
    # shift equal to number of arguments provided
    # this will "remove" the -l, -n options
    # and allow the files specified to be start at $1
    shift $argcount
    
    let totalcount=$#-$argcount
    echo "totalcount = $totalcount"
    #if [ $totalcount = "0" ] ; then
    if [ $# = "0" ] ; then
        echo "Not enough arguments. Please specify a file"
        exit
    fi

    # set the path to the .junk/ folder
    DIRECTORY="$HOME/.junk"
    # for all files specified, move them to ~/.junk/ directory
    for filename in $*
    do
        if [ ! -e "${filename}" ] ; then
            echo "Invalid parameter: file '$filename' does not exist"
            exit
        fi
        if [ -d "${filename}" ] ; then
            echo "Invalid parameter: file '$filename' is a directory"
            exit
        fi
        echo "Moving $filename"
        # create the .junk/ directory if it does not already exist
        # -p option will not create the directory if it already exists
        mkdir -p "$DIRECTORY" #$DIRECTORY
        # move the file to the .junk subdirectory
        mv $filename "$DIRECTORY/$filename"
    done

    # if the flag for -l is on, then list the contents of .junk/
    if [ $flag_l = "1" ] ; then
        echo
        echo $DIRECTORY
        ls $DIRECTORY
    fi

    # if the flag for -n is on, then count number of files and show memory usage
    if [ $flag_n = "1" ] ; then
        echo
        num_files="$(ls $DIRECTORY | wc -l)"
        echo "Number of files in $DIRECTORY: $num_files"
    fi
        
fi

