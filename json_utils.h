#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <QJsonObject>
#include <QJsonArray>

class NeuralLayer
{
public:

    QString layerType;//层定义
    int neurons;//神经元数量
    QString activationFunction;//激活函数
    NeuralLayer();
    QJsonObject toJsonObject()const;//将NeuralLayer对象转化为QJsonObject，以后可拼接为QJsonArray
    static NeuralLayer fromJsonObject(const QJsonObject& obj);// 从QJsonObject构造NeuralLayer的静态函数声明
    //obj 应该包含"layerType" "neurons" "activationFunction"
};


QJsonArray parseNetworkStructure(const QString& jsonStr);// JSON解析接口声明，根据JSON数据类型解析为QJsonArray对象
//jsonStr 应该包含"layers"

QString generateNetworkStructureJson(const QJsonArray& layersArray);// JSON生成接口声明，将网络结构相关数据转换为JSON格式

// 其他与JSON数据结构相关的声明
// 比如表示完整网络结构的类等

#endif // JSON_UTILS_H
