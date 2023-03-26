FROM ubuntu:latest
LABEL maintainer="Otto Quaglio <otto.q@gmx.com>"

ARG USER=otto
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Australia/Perth

# Base installs
RUN \
    ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    build-essential software-properties-common ca-certificates ssh-client \
    #
    # Utils
    man \
    sudo passwd wget gnupg \
    openssh-client openssh-server \
    skopeo \
    iputils-ping curl less wget jq tree htop git vim nano \
    #
    # Build tools
    npm openjdk-8-jdk libssl-dev cmake nodejs \
    python3-pip python3 \
    #
    && pip3 install virtualenv \
    #
    # Tools    #
    # Install Terraform
    # Install the HashiCorp GPG key.
    && wget -O- https://apt.releases.hashicorp.com/gpg | \
    gpg --dearmor | \
    tee /usr/share/keyrings/hashicorp-archive-keyring.gpg \
    # Verify the key's fingerprint.
    && gpg --no-default-keyring \
    --keyring /usr/share/keyrings/hashicorp-archive-keyring.gpg \
    --fingerprint \
    # Set???
    && echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] \
    https://apt.releases.hashicorp.com $(lsb_release -cs) main" | \
    tee /etc/apt/sources.list.d/hashicorp.list \
    && apt-get update && apt-get install terraform

# More installs
RUN \
    apt-get install -y --no-install-recommends \
    #
    # For python virtual environments
    python3.10-venv

RUN \
    apt-get install awscli -y

# User setup
RUN \
    groupadd --gid $USER_GID $USER \
    # create account
    && useradd --uid $USER_UID --gid $USER_GID -m $USER \
    && echo "$USER:$USER" | chpasswd \
    #&& mkdir -p /home/$USER && chown -R $USER:$USER /home/$USER \
    # Add sudo support
    # Grant user ability to execute any command as root without password
    && echo $USER ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USER \
    && chmod 0440 /etc/sudoers.d/$USER \
    #&& adduser $USER sudo \
    #&& chsh --shell /bin/zsh $USER \
    #
    # change default login shell to bash (sets in /etc/passwd)
    && chsh -s $(which bash) $USER

# Set environment variables
ENV HOME /home/$USER

# Set PWD
WORKDIR $HOME

# More installs and customizations for user
RUN \
    #
    # Awsome VIMRC
    git clone --depth=1 --branch master https://github.com/amix/vimrc.git $HOME/.vim_runtime \
    && chmod +x $HOME/.vim_runtime/install_awesome_vimrc.sh \
    && $HOME/.vim_runtime/install_awesome_vimrc.sh \
    #
    # Dotfiles
    && git clone --depth 1 --branch master https://github.com/oquaglio/dotfiles.git /home/$USER/.dotfiles \
    # TODO: Append sources for all .dotfiles to config files
    && chmod +x /home/$USER/.dotfiles/create_symlinks.sh \
    # RUN /root/.dotfiles/create_symlinks.sh
    # Create symlinks (overwrite existing)
    && ln -sf ~/.dotfiles/.gitconfig ~/.gitconfig \
    && ln -sf ~/.dotfiles/.gitmessage ~/.gitmessage \
    && ln -sf ~/.dotfiles/.gitignore ~/.gitignore \
    && ln -sf ~/.dotfiles/.nanorc ~/.nanorc \
    && ln -sf ~/.dotfiles/.vimrc ~/.vimrc \
    #
    && git config --global core.excludesfile ~/.gitignore \
    #
    # Starship https://linuxconfig.org/how-to-install-and-configure-starship-on-linux
    # Installs to /usr/local/bin
    # -s allows you to pass options to the script and -- seperates ssh options from script options
    # https://stackoverflow.com/questions/74399476/how-to-pass-yes-to-sh-command-like-curl-url-sh-sh
    && curl -sS https://starship.rs/install.sh | sh -s -- -y

# Append to .bashrc
RUN { \
    echo ''; \
    echo '# Source files from .dotfiles repo'; \
    echo 'source $HOME/.dotfiles/.aliases'; \
    echo 'source $HOME/.dotfiles/.env'; \
    #
    # https://unix.stackexchange.com/questions/1288/preserve-bash-history-in-multiple-terminal-windows
    echo ''; \
    echo '# BASH History Config'; \
    echo 'export HISTCONTROL=ignoredups:erasedups  # no duplicate entries'; \
    echo 'export HISTFILE=$HOME/.history'; \
    echo 'export HISTFILESIZE=1000000000'; \
    echo 'export HISTSIZE=1000000000'; \
    echo 'shopt -s histappend                      # append to history, don''t overwrite it'; \
    echo 'export PROMPT_COMMAND="history -a; history -c; history -r; $PROMPT_COMMAND"  # export immediately'; \
    echo 'export HISTTIMEFORMAT="[%F %T] "'; \
    #
    # Add Starship
    echo ''; \
    echo '# Starship'; \
    echo 'eval "$(starship init bash)"'; \
} >> $HOME/.bashrc

RUN chown -R $USER:$USER $HOME

# Set default user
USER $USER

#RUN chsh -s $(which zsh)
#RUN PATH="$PATH:/usr/bin/zsh"
#CMD [“echo”,”Image created”]
#CMD ["zsh"]
CMD ["bash"]