#include "ClientChanges.h"
#include <QJsonObject>

namespace {
const QString projectKey{QStringLiteral("project")};
const QString fileLocationKey{QStringLiteral("fileLocation")};
const QString patchesKey{QStringLiteral("patches")};
const QString clientIdKey{QStringLiteral("clientId")};
} //namespace


namespace collaborativeEditing {
namespace common {
ClientChanges::ClientChanges(const QString &projectName, const QString &filePath, const std::string &pathesText)
    : mProjectName(projectName),
      mFilePath(filePath),
      mPatchesText(pathesText) {
}

ClientChanges ClientChanges::fromByteArray(const QByteArray &data) {
    auto document = QJsonDocument::fromJson(data);
    if(document.isNull() || ! document.isObject()) {
        return {};
    }
    auto object= document.object();
    ClientChanges result;
    result.setClientId(object.value(clientIdKey).toString());
    result.setFilePath(object.value(fileLocationKey).toString());
    result.setProjectName(object.value(projectKey).toString());
    result.setPatchesText(object.value(patchesKey).toString().toStdString());
    return result;
}

ClientChanges::ClientChanges(const QByteArray &data) {
    parserData(data);
}

void ClientChanges::setProjectName(const QString &projectName) {
    mProjectName = projectName;
}

void ClientChanges::setFilePath(const QString &value) {
    mFilePath = value;
}

void ClientChanges::setPatchesText(const std::string &patchesText) {
    mPatchesText = patchesText;
}

QJsonDocument ClientChanges::toJson() const {
    QJsonDocument document;
    QJsonObject object;
    object.insert(projectKey, mProjectName);
    object.insert(fileLocationKey, mFilePath);
    object.insert(patchesKey, QString::fromStdString(mPatchesText));
    object.insert(clientIdKey, mClientId);
    document.setObject(object);
    return document;
}

QByteArray ClientChanges::toByteArray() const {
    return toJson().toJson();
}

QString ClientChanges::projectName() const {
    return mProjectName;
}

QString ClientChanges::filePath() const {
    return mFilePath;
}

std::string ClientChanges::patchesText() const {
    return mPatchesText;
}

bool ClientChanges::isValid() const {
    return !mProjectName.isEmpty() && !mFilePath.isEmpty()
            && !mPatchesText.empty();
}

void ClientChanges::parserData(const QByteArray &data) {
    if(data.isEmpty()) {
        return;
    }
    auto document = QJsonDocument::fromJson(data);
    if(document.isNull() || document.isEmpty() || !document.isObject()) {
        return;
    }
    auto object = document.object();
    if(object.isEmpty()) {
        return;
    }
    mProjectName = object.value(projectKey).toString();
    mFilePath = object.value(fileLocationKey).toString();
    mPatchesText = object.value(patchesKey).toString().toStdString();
    mClientId = object.value(clientIdKey).toString();
}

QString ClientChanges::clientId() const {
    return mClientId;
}

void ClientChanges::setClientId(const QString &clientId) {
    mClientId = clientId;
}
} //namespace common
} //namespace collaborativeEditing
