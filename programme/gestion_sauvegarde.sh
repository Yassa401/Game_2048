#!/usr/bin/env bash



cd parties_sauvegardees
n=$(ls -t | wc -l )


if (( $n >= 10 ));
then
    for i in $(ls -t | tail -n $(( $n - 10 )) ); do
        rm $i
        
    done
fi;

( ls -rt | cut -d "." -f 1 ; echo " ") > ../parties.txt

exit 0