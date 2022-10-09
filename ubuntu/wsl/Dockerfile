FROM ottoq/ubuntu:latest
LABEL maintainer="Otto Quaglio <otto.q@gmx.com>"

ARG user

#RUN groupadd -r mysql && useradd -r -g mysql mysql
#RUN useradd otto && echo "otto:otto" | chpasswd
#RUN useradd -m otto && echo "$user:$user" | chpasswd && adduser $user sudo
#RUN chsh --shell /bin/zsh $user
#RUN mkdir -p /home/$user && chown -R $user:$user /home/$user




RUN \
    #Install the HashiCorp GPG key.
    wget -O- https://apt.releases.hashicorp.com/gpg | \
    gpg --dearmor | \
    sudo tee /usr/share/keyrings/hashicorp-archive-keyring.gpg \
    #Verify the key's fingerprint.
    && gpg --no-default-keyring \
    --keyring /usr/share/keyrings/hashicorp-archive-keyring.gpg \
    --fingerprint \
    #Set???
    && echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] \
    https://apt.releases.hashicorp.com $(lsb_release -cs) main" | \
    tee /etc/apt/sources.list.d/hashicorp.list \
    # Install
    && apt update && apt-get install terraform


#RUN chsh -s $(which zsh)
#RUN PATH="$PATH:/usr/bin/zsh"
#CMD [“echo”,”Image created”]
#CMD ["zsh"]