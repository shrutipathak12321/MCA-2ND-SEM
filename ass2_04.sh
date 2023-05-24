
echo "Home directory : $HOME"

os=$(uname -o)
echo "Operating System type is - $os"

version=$(uname -v | cut -d ' ' -f 1 | cut -c 6-)
echo "Operating System version is - $version"

release=$(uname -v)
echo "Operating System release is - $release"

kernel=$(uname -r)
echo "kernel version - $kernel"










echo "Current path setting $PATH"
