#!/bin/bash

CPPLINT_OPTION="--filter=-legal/copyright,-build/include,-build/include_what_you_use,-readability/streams"

function Check {
    SUFFIX=$1
    SUFFIX_PASS=$1"_pass"
    EXECUTABLE_FILE=$SUFFIX.out
    if [ ! -d $SUFFIX ] ; then
        echo "Can't find GTest Directory"
        return -1
    fi

    for file in *_$SUFFIX.cpp; do
        if [ -f ${file} ] ; then
            result="$file.result"
            cp $file $SUFFIX/$SUFFIX.cpp
            id=`echo $file | cut -d'_' -f 1`
            cp $id"_"$SUFFIX".h" $SUFFIX/$SUFFIX.h 
            echo "=== " ${file} " === " >> $result
            echo "--------- Cpplint Check ---------" >> $result
            python ./cpplint.py $CPPLINT_OPTION ${file} 1>>$result 2>&1
            echo >> $result

            echo "--------- Compile Result ---------" >> $result
            make -C $SUFFIX 1>>$result 2>&1
            if [ $? == 0 ]; then
              echo $file | cut -d'_' -f 1
            fi

            echo "--------- Google Test ---------" >> $result
            timeout 5 ./$SUFFIX/a.out 1>> $result 2>&1

            if [ $? == 0 ]; then
              echo -n "Test Done: "
              echo $file | cut -d'_' -f 1
            fi
         
            make -C $SUFFIX clean > /dev/null 2>&1
            rm $SUFFIX/$SUFFIX.cpp
            rm $SUFFIX/$SUFFIX.h
        fi
    done
}

rm *.result 1> /dev/null 2>&1
Check file_interface_impl
