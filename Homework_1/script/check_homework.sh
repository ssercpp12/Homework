#!/bin/bash

CPPLINT_OPTION="--filter=-legal/copyright,-build/include"

function Check {
    SUFFIX=$1
    EXECUTABLE_FILE=$SUFFIX.out
    if [ ! -d $SUFFIX ] ; then
        echo "Can't find GTest Directory"
        return -1
    fi
 
    for file in *_$SUFFIX.cpp; do
        if [ -f ${file} ] ; then
            result="$file.result"
            cp $file $SUFFIX/$SUFFIX.cpp
            echo "=== " ${file} " === " >> $result
            echo "--------- Compile Result ---------" >> $result
            make -C $SUFFIX 1>>$result 2>&1
            if [ $? != 0 ]; then
              echo $file | cut -d'_' -f 1
            fi
            echo "--------- Google Test ---------" >> $result
            timeout 5 ./$SUFFIX/a.out 1>> $result 2>&1 && rm ./$SUFFIX/a.out
          
            make -C $SUFFIX clean > /dev/null 2>&1
            rm $SUFFIX/$SUFFIX.cpp

            echo >> $result
            echo "--------- Cpplint Check ---------" >> $result
            python ./cpplint.py $CPPLINT_OPTION ${file} 1>>$result 2>&1
        fi
    done
}

rm *.result 1> /dev/null 2>&1
Check series_comp
Check version
