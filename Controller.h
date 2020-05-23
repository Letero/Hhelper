#pragma once

#include <QObject>
#include "ButtonModel.h"
#include "JsonParser.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ButtonModel *buttonModel READ getButtonModel CONSTANT)

public:
    Controller(QObject *parent = nullptr);
    ButtonModel *getButtonModel() const;
//    Q_INVOKABLE QString getTargetWindow();
//    Q_INVOKABLE void setTargetWindow(QString name);
    Q_INVOKABLE void setSlotName(QString name);
    Q_INVOKABLE QString getSlotName();
    Q_INVOKABLE void setHost(const QString& host);
    Q_INVOKABLE QString getHost();
    Q_INVOKABLE void saveCurrentConfig();
//    Q_INVOKABLE bool isDevMode();
//    Q_INVOKABLE void changeDevMode(bool isDevMode);
    Q_INVOKABLE bool isDarkTheme();
    Q_INVOKABLE void changeTheme(bool isDarkTheme);
    Q_INVOKABLE QString validateSlotName(QString name);

private:
    QScopedPointer<ButtonModel> m_buttonModel;
    JsonParser m_jsonParser;
    QString configFile;
};

