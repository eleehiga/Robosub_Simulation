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
COPY environment.yml /setup/environment.yml
RUN conda env create -f /setup/environment.yml
SHELL ["conda", "run", "-n", "RoboSubML-2020-Tensorflow", "/bin/bash", "-c"]
RUN apt install gnupg gnupg2 gnupg1 -y
# installing Gazebo takes a VERY long time
RUN curl -sSL http://get.gazebosim.org | sh
#RUN sed -i 's/# deb/deb/g' /etc/apt/sources.list
#RUN apt-get update && apt-get install -y lsb-release && apt-get clean all
#RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
#RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
#RUN curl -sSL 'http://keyserver.ubuntu.com/pks/lookup?op=get&search=0xC1CF6E31E6BADE8868B172B4F42ED6FBAB17C654' | apt-key add -
#RUN rm  /etc/apt/sources.list.d/ros-latest.list
#RUN apt update
#RUN apt install ros-noetic-desktop-full
#RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
#RUN /bin/bash -c "source ~/.bashrc"
#SHELL ["conda", "run", "-n", "RoboSubML-2020-Tensorflow", "/bin/bash", "-c"]
#RUN apt install ros-noetic-gazebo-ros-pkgs
