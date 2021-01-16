#include "mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QMediaPlayer* music=new QMediaPlayer();
//    music->setMedia(QUrl::fromLocalFile("D:\\chrome\\111_WAV.wav"));
//    music->setVolume(40);
//    music->play();

    QMediaPlaylist *musicList = new QMediaPlaylist();  //添加音乐列表
    musicList->addMedia(QUrl::fromLocalFile("D:\\chrome\\111_WAV.wav")); //添加音乐列表
    QMediaPlayer *soundPlayer = new QMediaPlayer();  //创建音乐播放器
    soundPlayer->setPlaylist(musicList);  //设置音乐列表
    soundPlayer->setVolume(10);
    soundPlayer->play();
    //以上会使音乐顺序播放
    //如果只有一首音乐，同样添加到musicList中，再添加一条
    musicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);  //循环播放
    //这样就可以单首音乐循环播放

    return a.exec();

    return 0;
}
