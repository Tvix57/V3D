#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "point_light.h"

namespace Tvix57 {
class SpotLight : public PointLight {
 public:
  SpotLight() : PointLight(), m_inner_cone_{12.5f}, m_outer_cone_{15.0f} {
    m_type_ = "spotLight";
    lightData.insert(".cutOff", QVariant::fromValue(&m_inner_cone_));
    lightData.insert(".outerCutOff", QVariant::fromValue(&m_outer_cone_));
  }

 private:
  float m_inner_cone_;
  float m_outer_cone_;
};
}  // namespace Tvix57
Q_DECLARE_METATYPE(Tvix57::SpotLight);
#endif  // SPOT_LIGHT_H
