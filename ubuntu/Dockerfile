#
# Ubuntu Dockerfile
#
# https://github.com/dockerfile/ubuntu
#

# Pull base image.
#FROM ubuntu:14.04
FROM ubuntu:latest
LABEL maintainer "Otto Quaglio <otto.q@gmx.com>"

# to prevent hanging when waiting for TZ input, configure the TZ as pre-step
ENV TZ=Australia/Perth
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

  # Install Ubuntu updates and tools
RUN \
  apt-get update && apt-get install -y --no-install-recommends \
  #apt-transport-https \
  build-essential  \
  software-properties-common \
  ca-certificates ssh-client \
  man \
  sudo passwd \
  # Utils
  openssh-client openssh-server \
  skopeo \
  # procps \
  iputils-ping \
  #git-all \
  git \
  curl less wget jq tree htop \
  vim nano \
  # Build tools
  npm \
  openjdk-8-jdk \
  libssl-dev \
  python3-pip \
  python3 \
  cmake \
  nodejs \
  # Apps
  awscli \
  && rm -rf /var/lib/apt/lists/*

# for kubectl package
RUN curl -fsSLo /usr/share/keyrings/kubernetes-archive-keyring.gpg https://packages.cloud.google.com/apt/doc/apt-key.gpg
RUN echo "deb [signed-by=/usr/share/keyrings/kubernetes-archive-keyring.gpg] https://apt.kubernetes.io/ kubernetes-xenial main" | tee /etc/apt/sources.list.d/kubernetes.list

RUN \
  apt-get update && apt-get install -y --no-install-recommends \
  kubectl \
  && rm -rf /var/lib/apt/lists/*

# Set environment variables
ENV HOME /root

# Define working directory
WORKDIR $HOME

# TODO get this from source repos
# Add config files
#ADD root/.bashrc /root/.bashrc
#ADD root/.gitconfig /root/.gitconfig
#ADD root/.scripts /root/.scripts

# Install Ultimate VIM
RUN git clone --depth=1 --branch master https://github.com/amix/vimrc.git $HOME/.vim_runtime
RUN chmod +x $HOME/.vim_runtime/install_awesome_vimrc.sh
RUN $HOME/.vim_runtime/install_awesome_vimrc.sh

# Dotfiles
RUN git clone --depth 1 --branch master https://github.com/oquaglio/dotfiles.git /root/.dotfiles
# TODO: Append sources for all .dotfiles to config files
RUN chmod +x /root/.dotfiles/create_symlinks.sh
# RUN /root/.dotfiles/create_symlinks.sh
# Create symlinks (overwrite existing)
RUN ln -sf ~/.dotfiles/.gitconfig ~/.gitconfig
RUN ln -sf ~/.dotfiles/.gitmessage ~/.gitmessage
RUN ln -sf ~/.dotfiles/.gitignore ~/.gitignore
RUN ln -sf ~/.dotfiles/.nanorc ~/.nanorc
RUN ln -sf ~/.dotfiles/.vimrc ~/.vimrc

RUN git config --global core.excludesfile ~/.gitignore

# Scripts
RUN git clone --depth=1 --branch master https://github.com/rupa/z.git $HOME/.scripts/z
#RUN sh -c "$(wget -P $HOME/.scripts/ https://raw.githubusercontent.com/git/git/master/contrib/completion/git-completion.zsh)"

# Install Oh My Zsh (includes zsh)
# https://github.com/deluan/zsh-in-docker
# This will replace any existing .zshrc file
RUN yes | sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.2/zsh-in-docker.sh)" -- \
-p git -p aws

# Append to .zshrc
RUN { \
		echo ''; \
    echo '# Source files from .scripts dir'; \
		#echo 'source $HOME/.scripts/git-completion.zsh'; \
    echo 'source $HOME/.scripts/z/z.sh'; \
    echo ''; \
    echo '# Source files from .dotfiles repo'; \
    #echo 'source $HOME/.dotfiles/.zshrc'; \
    echo 'source $HOME/.dotfiles/.aliases'; \
    echo 'source $HOME/.dotfiles/.env'; \
	} >> $HOME/.zshrc

RUN chsh -s $(which zsh)

# Define default command.
CMD ["zsh"]