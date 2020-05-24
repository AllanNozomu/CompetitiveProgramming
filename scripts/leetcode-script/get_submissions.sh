#/bin/sh 
COOKIE=""

if [ -z $COOKIE ]
then
    echo "Please set the Cookie"
    exit 1
fi

if ! [ -x "$(command -v jq)" ]
then
    echo "jq is not installed"
    exit 1
fi

if ! [ -x "$(command -v curl)" ]
then
    echo "curl is not installed"
    exit 1
fi

if ! [ -e download ]
then
    mkdir download
fi

echo "Downloading page number 1"
curl --cookie "LEETCODE_SESSION=${COOKIE}" "https://leetcode.com/api/submissions/?offset=0&limit=20&lastkey=" -o download/1.json
has_next=$(cat download/1.json | jq .has_next)
page_num=1
while [[ $has_next == "true" ]]
do
    last_key=$(cat download/$page_num.json | jq .last_key -r)
    page_num=$((page_num+1))

    echo "Downloading page number $page_num"
    curl --cookie "LEETCODE_SESSION=${COOKIE}" "https://leetcode.com/api/submissions/?offset=0&limit=20&lastkey=$last_key" -o "donwload/$page_num.json"
    
    has_next=$(cat download/$page_num.json | jq .has_next)
    echo $has_next
    sleep 5
done
