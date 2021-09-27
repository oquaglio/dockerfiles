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
# note: sed replaces
RUN \
  apt-get update && apt-get install -y \
  build-essential  \
  software-properties-common \
  byobu \
  curl \
  git \
  htop \
  man \
  vim \
  wget \
  --no-install-recommends \
  && rm -rf /var/lib/apt/lists/*

RUN rm -rf /var/lib/apt/lists/*

# Install pip3 and npm
RUN \
  apt update && apt install -y \
  python3-pip \
  npm \
  --no-install-recommends

# Set environment variables.
ENV HOME /root

# Add files
ADD root/.bashrc /root/.bashrc
#ADD root/.gitconfig /root/.gitconfig
ADD root/.scripts /root/.scripts

# Install Ultimate VIM
RUN git clone --depth=1 --branch master https://github.com/amix/vimrc.git $HOME/.vim_runtime
RUN chmod + x $HOME/.vim_runtime/install_awesome_vimrc.sh
RUN $HOME/.vim_runtime/install_awesome_vimrc.sh

# Define working directory.
WORKDIR $HOME

# Dotfiles
RUN git clone --depth 1 --branch master https://github.com/oquaglio/dotfiles.git /root/.dotfiles
RUN chmod +x /root/.dotfiles/create_symlinks.sh
RUN /root/.dotfiles/create_symlinks.sh

# Install Oh My Zsh
# https://github.com/deluan/zsh-in-docker
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.1/zsh-in-docker.sh)"

# Define default command.
CMD ["zsh"]