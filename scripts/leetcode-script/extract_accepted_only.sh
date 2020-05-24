#!/bin/sh

if ! [ -x "$(command -v jq)" ] 
then
    echo "jq is not installed"
    exit 1
fi

if [ -f "result.json" ]
then
    rm result.json
fi

for f in download/*.json ; do
    if [ $f != "result.json" ] 
    then
        cat $f | jq '[.submissions_dump[] |
            select(.status_display=="Accepted") |
            {
                "lang" : .lang,
                "timestamp" : .timestamp | strftime("%Y-%m-%d"),
                "title" : .title,
                "runtime" : .runtime,
                "memory" : .memory,
                "code" : (
                     if .lang == "cpp" then ("\\*\nAuthor: allannozomu" + "\nRuntime: " + .runtime + "\nMemory: " + .memory + "*\\\n\n" + .code) 
                     else ("# Author: allannozomu" + "\n# Runtime: " + .runtime + "\n# Memory: " + .memory + "\n\n" + .code) end)
             }]' >> result.json 
    fi
done

if [ -f "result.json" ]
then
    perl -i -p0e 's/\[\]//sg' result.json
    perl -i -p0e 's/\]\s*\[/,/sg' result.json 
    cat result.json | jq . > temp.json && mv temp.json result.json
fi
