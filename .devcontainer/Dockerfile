FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive

# Core build + developer utilities
RUN apt-get update && apt-get install -y --no-install-recommends \
    bash-completion \
    build-essential \
    ca-certificates \
    ccache \
    clang \
    cmake \
    curl \
    device-tree-compiler \
    file \
    flex \
    g++ \
    gawk \
    gcc \
    gdb \
    gfortran \
    gperf \
    git \
    graphviz \
    jq \
    libboost-all-dev \
    libbz2-dev \
    libc6-dev \
    libcurl4-openssl-dev \
    libeigen3-dev \
    libexpat1-dev \
    libffi-dev \
    libfl-dev \
    libfontconfig1-dev \
    libfreetype6-dev \
    libftdi1-dev \
    libgflags-dev \
    libglib2.0-dev \
    libgoogle-glog-dev \
    libgmp-dev \
    libgomp1 \
    libgtk-3-dev \
    libharfbuzz-dev \
    libhwloc-dev \
    libjpeg-dev \
    libjsoncpp-dev \
    liblapack-dev \
    liblzma-dev \
    libmpc-dev \
    libmpfr-dev \
    libncurses5-dev \
    libncursesw5-dev \
    libopenmpi-dev \
    libpixman-1-dev \
    libpython3-dev \
    libreadline-dev \
    librsvg2-dev \
    libsqlite3-dev \
    libssl-dev \
    libtbb-dev \
    libtool \
    libunwind-dev \
    libx11-dev \
    libxaw7-dev \
    libxft-dev \
    libxml2-dev \
    libxmu-dev \
    libxpm-dev \
    libxrender-dev \
    libxt-dev \
    llvm \
    make \
    ninja-build \
    openjdk-17-jdk \
    openssh-client \
    pkg-config \
    python3 \
    python3-dev \
    python3-pip \
    python3-setuptools \
    python3-venv \
    rsync \
    sudo \
    swig \
    tcl \
    tcl-dev \
    tcsh \
    texinfo \
    time \
    tk \
    tk-dev \
    unzip \
    uuid-dev \
    wget \
    xz-utils \
    zlib1g-dev \
    && rm -rf /var/lib/apt/lists/*

# Python tools commonly required by OpenROAD/OpenLane-style flows and scripts
RUN python3 -m pip install --no-cache-dir \
    click \
    jinja2 \
    klayout \
    matplotlib \
    numpy \
    pandas \
    pyyaml \
    scipy

# Helpful defaults for non-interactive CI/EDA usage
ENV LANG=C.UTF-8 \
    LC_ALL=C.UTF-8 \
    MAKEFLAGS=-j$(nproc)

WORKDIR /workspace
