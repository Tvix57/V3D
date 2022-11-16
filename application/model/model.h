#ifndef MODEL_H
#define MODEL_H

#include <QDir>
#include <QVector3D>

#include "mesh.h"
#include "model_information.h"
#include "model_settings.h"

namespace s21 {

class Model {
 public:
  void DrawTexture(QOpenGLShaderProgram &shader);
  void DrawMaterial(QOpenGLShaderProgram &shader);
  void DrawEdge(QOpenGLShaderProgram &shader);
  void DrawVertex(QOpenGLShaderProgram &shader);

  void ChangeTexture(QImage img, QString &path);
  void DelTexture();
  void MirrorTexture();
  void SetDefaultMaterial();

  void ChangeAmbient(QColor color);
  void ChangeDiffuse(QColor color);
  void ChangeSpecular(QColor color);
  void ChangeShine(double shine);
  void ChangeOpacity(double opacity);
  void ChangeReflection(double reflect);
  void ChangeRoughness(double roughness);

  const QMatrix4x4 GetModelMatrix() const;
  ModelSettings &GetSettings();
  ModelInfo GetInfo();

  static Model *createModel(QString path);
  void Destroy();

 private:
  Model(QString path);
  ~Model();

  ModelSettings m_settings_;

  ModelInfo *info_;

  void TransformMatrix();

  void ProcessNode(aiNode *node, const aiScene *scene);
  Mesh *ProcessMesh(aiMesh *mesh, const aiScene *scene);
  void LoadVertexData(aiMesh *mesh, QVector<Vertex> &vertices);
  void LoadIndicesData(aiMesh *mesh, QVector<unsigned int> &indices);
  void LoadTextureData(const aiScene *scene, aiMesh *mesh,
                       QVector<Texture *> &textures);
  void LoadMaterial(const aiScene *scene, aiMesh *mesh, Material &material);
  QVector<Texture *> LoadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                          QString typeName);
};

}  // namespace s21

#endif  // MODEL_H
