# ubuntu-wsl

Expands on ubuntu to add customizations for using image as WSL Distro.

``` SH
docker build -t ottoq/ubuntu-wsl:0.1.0 -t ottoq/ubuntu-wsl:0.1 -t ottoq/ubuntu-wsl:hydrogen -t ottoq/ubuntu-wsl:latest . --progress=plain --build-arg user=otto
```

Test by spawning transient container:

``` SH
docker run --rm -it ottoq/ubuntu-wsl:latest
```

I've made user, shell etc work by default, but you can specify them using:

``` SH
docker run --rm -it --user otto ottoq/ubuntu-wsl:latest /bin/bash
```

Check what shell I am using:

``` SH
ps -p $$
```

Check what the user's default shell is:

``` SH
echo "$SHELL"
```

``` SH
cat /etc/passwd | grep otto
```

Refresh dotfiles:

``` SH
cd ~/.dotfiles/; git pull; cd ~; . .bashrc
```
