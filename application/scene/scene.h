#ifndef SCENE_H_
#define SCENE_H_

#include <QColor>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

#include "model_settings.h"

namespace Tvix57 {

enum class ProjectionType { kOrtho = 0, kPerspective };
enum class DrawSceneType { kNo = 0, kDraw };

struct SceneTransformMatrix {
 private:
  QMatrix4x4 matrix;
  TranslateSetting translate{0.0f, 0.0f, 0.0f};
  RotateSetting rotate{0.0f, 0.0f, 0.0f};

 public:
  QMatrix4x4 GetMatrix();
  void SetTranslateX(float shift);
  void SetTranslateY(float shift);
  void SetTranslateZ(float shift);

  void SetRotateX(float rotate);
  void SetRotateY(float rotate);
  void SetRotateZ(float rotate);

  TranslateSetting GetTranslateSetting();
  RotateSetting GetRotateSetting();

 private:
  void TransformMatrix();
};

class Scene {
 private:
  QOpenGLVertexArrayObject VAO;
  QOpenGLBuffer VBO, EBO;

  QMatrix4x4 m_model;
  SceneTransformMatrix scene_transform;

  QMatrix4x4 m_projection;
  ProjectionType m_projection_type;
  float m_view_angle = 45.0f;
  float m_view_ratio = 1.0f;

  QOpenGLShaderProgram *m_program;

  float vertices[6] = {
      100.0f, 0.0f, 0.0f, -100.0f, 0.0f, 0.0f,
  };

  QColor x_axis_color;
  QColor y_axis_color;
  QColor z_axis_color;

  QColor grid_color;

  QColor m_background_color;
  DrawSceneType m_draw_type = DrawSceneType::kDraw;

 public:
  explicit Scene(QOpenGLShaderProgram *shader);
  ~Scene();

  void DrawAxis();
  void DrawGrid();

  QMatrix4x4 GetProjectionMat();
  QMatrix4x4 GetTransformMat();
  const QColor GetBackgroundColor() const;
  DrawSceneType GetDrawType() const;

  void SetProjectionType(ProjectionType type);
  void SetProjectionViewAngle(float angle);
  void SetProjectionViewRatio(float ratio);
  void SetBackgroundColor(QColor color);
  void SetDrawType(DrawSceneType type);

 private:
  void SetupMesh();
  void UpdateProjection();
};

}  // namespace Tvix57

#endif  // SCENE_H_
