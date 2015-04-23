#include "actualpicker.h"
#include "ui_actualpicker.h"

#include <unistd.h>
#include <QDebug>
#include <QMouseEvent>
#include <QClipboard>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QThread>
#include <KEmoticons>
#include <kemoticons.h>

ActualPicker::ActualPicker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActualPicker)
{
    ui->setupUi(this);
    setWindowTitle("Emote Picker");
    loadEmotes();
}

ActualPicker::~ActualPicker()
{
    delete ui;
}

void ActualPicker::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        qApp->closeAllWindows();
    }
}

void ActualPicker::clickedEmote()
{
    QObject *buttonClicked = sender();
    QString emoteText = buttonClicked->property("emoteText").toString();

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(emoteText);
}

void ActualPicker::loadEmotes()
{
    KEmoticons ke;
    KEmoticonsTheme et = ke.theme();

    QHash<QString, QStringList> emotes = et.emoticonsMap();
    QMap<QString, QString> emotesMap = QMap<QString, QString>();

    QHashIterator<QString, QStringList> i(emotes);
    while(i.hasNext())
    {
        i.next();
        QString emotePath = i.key();
        QString emoteText = i.value()[0];

        emotesMap.insert(emotePath, emoteText);
    }

    int current = 0;
    static int perRow = 13;

    QMapIterator<QString, QString> im(emotesMap);
    while (im.hasNext())
    {
        im.next();
        QString emotePath = im.key();
        QString emoteText = im.value();

        QPixmap emoteImage = QPixmap(emotePath);
        QPushButton *currentEmoteButton = new QPushButton(emoteImage, "", this);
        currentEmoteButton->setIconSize(QSize(50, 50));
        currentEmoteButton->setProperty("emoteText", emoteText);
        currentEmoteButton->setToolTip(emoteText);

        ui->gridLayout->addWidget(currentEmoteButton, current / perRow, current % perRow);
        connect(currentEmoteButton, SIGNAL(clicked()), this, SLOT(clickedEmote()));

        current++;
    }
}
