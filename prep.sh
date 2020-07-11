# example usage: `prep.sh abc/abc173/`

path=$1
if [ -e $path ]; then
    echo "path ${path} already exists!"
else
    mkdir $path
    cp template.cpp "${1}/a.cpp"
    cp template.cpp "${1}/b.cpp"
    cp template.cpp "${1}/c.cpp"
    cp template.cpp "${1}/d.cpp"
    cp template.cpp "${1}/e.cpp"
    cp template.cpp "${1}/f.cpp"
    cd $path
fi
