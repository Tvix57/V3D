#ifndef V3D_LIGHT_H_
#define V3D_LIGHT_H_

#include <QColor>
#include <QMap>
#include <QMetaType>
#include <QString>
#include <QVariant>
#include <QVector3D>

namespace Tvix57 {
class Light {
 public:
  Light();
  const bool &isActive() { return m_active_; }
  void SetActive(const bool status) { m_active_ = status; }

  const QString &GetType() { return m_type_; }
  QMap<QString, QVariant> &GetInfo() { return lightData; }

 protected:
  QMap<QString, QVariant> lightData;

  bool m_active_;
  QString m_type_;
  QVector3D m_direction_;
  QVector3D m_ambient_;
  QVector3D m_diffuse_;
  QVector3D m_specular_;
};

}  // namespace Tvix57
Q_DECLARE_METATYPE(Tvix57::Light);
#endif  // V3D_LIGHT_H_
