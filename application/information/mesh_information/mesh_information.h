#ifndef MESH_INFORMATION_H_
#define MESH_INFORMATION_H_

#include <QString>

namespace Tvix57 {

struct MeshInfo {
  QString name;

  unsigned int vertices_count;
  unsigned int face_count;
};

}  // namespace Tvix57

#endif  // MESH_INFORMATION_H_
