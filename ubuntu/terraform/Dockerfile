FROM ottoq/ubuntu:latest
LABEL maintainer="Otto Quaglio <otto.q@gmx.com>"

RUN \
    apt-get update && sudo apt-get install -y \
    gnupg software-properties-common

#Install the HashiCorp GPG key.

RUN wget -O- https://apt.releases.hashicorp.com/gpg | \
    gpg --dearmor | \
    sudo tee /usr/share/keyrings/hashicorp-archive-keyring.gpg

#Verify the key's fingerprint.

RUN gpg --no-default-keyring \
    --keyring /usr/share/keyrings/hashicorp-archive-keyring.gpg \
    --fingerprint

RUN echo "deb [signed-by=/usr/share/keyrings/hashicorp-archive-keyring.gpg] \
    https://apt.releases.hashicorp.com $(lsb_release -cs) main" | \
    tee /etc/apt/sources.list.d/hashicorp.list


RUN apt update && apt-get install terraform


#CMD ["zsh"]