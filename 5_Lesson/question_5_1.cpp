#include "question_5_1.h"
#include "ui_question_5_1.h"
#include <QVector>

question_5_1::question_5_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::question_5_1)
{
    ui->setupUi(this);
    QVBoxLayout *box = new QVBoxLayout();

    //box->addStretch();
    //box->addSpacing(40);
    //box->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    //box->setSizeConstraint(box->SetFixedSize);

    ui->CentralWidget->setLayout(box);

    QVector<CardCreator*> Cards;
    CardCreator* buf = new CardCreator("Dima","Melnichenko","+79145553535","Yeap@mail/ru","www.Da.net","Line 5 Already done");
    Cards.push_back(buf);
    buf = new CardCreator("Valera","Kyrtigin","+79146667788","Nope@mail/ru","www.Maybe.net","Line 6 Already sad");
    Cards.push_back(buf);

    //box->addWidget(CreateQMLFromCard(Cards[0]),0);
    box->addWidget(CreateQMLFromCard(Cards[1]),0);
}

question_5_1::~question_5_1()
{
    delete ui;
}

QQuickWidget* question_5_1::CreateQMLFromCard(CardCreator *Card){
    QQuickWidget *NewCard = new QQuickWidget();
    NewCard->setFixedHeight(400);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("card_info", Card);

    QQmlComponent component(&engine);
    component.loadUrl(QUrl("qrc:/5_Lesson/Card.qml"));
    component.create(context);

    NewCard->setContent(component.url(),&component,component.create());
    return NewCard;
}
