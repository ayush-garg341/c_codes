FROM ubuntu:jammy

LABEL maintainer="Ayush Garg"

COPY container-setup-arm64.sh /usr/local/bin/container-setup-arm64
COPY container-setup-common.sh /usr/local/bin/container-setup-common

# copy new sources.list
COPY --chown=root:root sources.list /etc/apt/sources.list

# set default locale
ENV LANG en_US.UTF-8

RUN /usr/local/bin/container-setup-arm64

# git build arguments
ARG USER=elliott
ARG EMAIL=gargayush341@example.com

# configure your environment
USER elliott

WORKDIR /home/elliott
CMD ["/bin/bash", "-l"]


