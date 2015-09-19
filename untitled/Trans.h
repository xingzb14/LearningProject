/*
    这部分代码参考网上完成，链接见报告
*/

#ifndef __JasonQt_Translation_h__
#define __JasonQt_Translation_h__

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "Net.h"

namespace Qt_Translation
{

class BaiduTranslation: public QObject
{
    Q_OBJECT
private:
    QString m_apiKey;
    Qt_Net::HTTP m_http;
public:
    BaiduTranslation(const QString &apiKey);
public slots:
    std::pair<bool, QString> translation(const QString &string, const QString &from = "auto", const QString &to = "auto");
};

}

#endif  //__JasonQt_Translation_h__
