FROM ubuntu:latest
RUN apt-get update
RUN apt install wget -y
RUN apt install curl -y
#From instructions
RUN apt install libgl1-mesa-glx libegl1-mesa libxrandr2 libxrandr2 libxss1 libxcursor1 libxcomposite1 libasound2 libxi6 libxtst6 -y
RUN wget -P /tmp https://repo.anaconda.com/archive/Anaconda3-2020.02-Linux-x86_64.sh
RUN sha256sum /tmp/Anaconda3-2020.02-Linux-x86_64.sh
RUN bash /tmp/Anaconda3-2020.02-Linux-x86_64.sh -b -p
RUN ln -s ~/anaconda3/bin/conda /usr/bin/conda
#RUN conda create --name RoboSubML-2020-Tensorflow tensorflow-gpu python=3.7 
#RUN conda init bash
COPY environment.yml /setup/environment.yml
RUN conda env create -f /setup/environment.yml
RUN conda run -n RoboSubML-2020-Tensorflow python -V
#RUN conda activate RoboSubML-2020-Tensorflow
RUN curl -sSL http://get.gazebosim.org | sh 
