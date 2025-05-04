#include "json_utils.h"
#include <QJsonDocument>
#include <QDebug>

QJsonObject NeuralLayer::toJsonObject() const {//将NeuralLayer对象转化为QJsonObject对象
    QJsonObject obj;
    obj["layerType"] = layerType;
    obj["neurons"] = neurons;
    obj["activationFunction"] = activationFunction;
    return obj;
}

NeuralLayer::NeuralLayer() {
    layerType = "";
    neurons = 0;
    activationFunction = "";
}

NeuralLayer NeuralLayer::fromJsonObject(const QJsonObject& obj) {//将QJsonObject对象转化为NeuralLayer对象
    NeuralLayer layer;
    if (!obj.contains("layerType") ||!obj.contains("neurons") ||!obj.contains("activationFunction")) {
        qDebug() << "Error form fromJsonObject: Missing required fields in JSON object when converting to NeuralLayer.";
        return layer;
    }
    layer.layerType = obj["layerType"].toString();
    layer.neurons = obj["neurons"].toInt();
    layer.activationFunction = obj["activationFunction"].toString();
    return layer;
}
QJsonArray parseNetworkStructure(const QString& jsonStr) {//将JSON字符串解析为QJsonArray对象
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
    QJsonArray layersArray;
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if(!jsonStr.contains("layers")){
            qDebug()<<"Error from parseNetworkStructure:JSON object does not contain 'layers' field";
        }
        layersArray = obj["layers"].toArray();
    }
    return layersArray;
}
QString generateNetworkStructureJson(const QJsonArray& layersArray) {//将QJsonArray对象转化为JSON字符串
    QJsonObject rootObj;
    rootObj["layers"] = layersArray;
    QJsonDocument doc(rootObj);
    return QString::fromUtf8(doc.toJson());
}
