#include "AccountKit.h"

//AccountKit::AccountKit() {

//}

QString AccountKit::encryUserInfo(const QString &uid, const QString &serial, const QString &name, const QString &email)  {
    QString merge = QString("%1\n%2\n%3\n%4").arg(uid).arg(serial).arg(name).arg(email);
    qDebug() << merge;
    return getXorEncryptDecrypt(merge, AIDE_ENCRY_KEY);
}


// =============
// 以下為裝腔作勢的加密算法, 只是為了
// 不直接記錄賬戶信息而已
// =============

QString AccountKit::getXorEncryptDecrypt(const QString &str, const char &key) {
  QString result;
  QByteArray bs = qstringToByte(str);

  for(int i=0; i<bs.size(); i++){
    bs[i] = bs[i] ^ key;
  }

  result = byteToQString(bs);
  return result;
}

QString AccountKit::byteToQString(const QByteArray &byte) {
  QString result;
  if(byte.size() > 0){
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    result = codec->toUnicode(byte);
  }

  return result;
}

QByteArray AccountKit::qstringToByte(const QString &strInfo) {
  QByteArray result;
  if(strInfo.length() > 0){
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    result = codec->fromUnicode(strInfo);
  }

  return result;
}
