#include "ClientChanges.h"
#include <QJsonDocument>
#include <QJsonObject>

namespace {
const QString projectKey{QStringLiteral("project")};
const QString fileLocationKey{QStringLiteral("fileLocation")};
const QString patchesKey{QStringLiteral("patches")};
} //namespace


namespace collaborativeEditing {
namespace common {
ClientChanges::ClientChanges(const QString &projectName, const QString &filePath, const std::string &pathesText)
    : mProjectName(projectName),
      mFilePath(filePath),
      mPatchesText(pathesText) {
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

QByteArray ClientChanges::toByteArray() const {
    QJsonDocument document;
    QJsonObject object;
    object.insert(projectKey, mProjectName);
    object.insert(fileLocationKey, mFilePath);
    object.insert(patchesKey, QString::fromStdString(mPatchesText));
    document.setObject(object);
    return document.toJson();
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
    return !mProjectName.isEmpty() && !mFilePath.isEmpty() && !mPatchesText.empty();
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
}
} //namespace common
} //namespace collaborativeEditing
