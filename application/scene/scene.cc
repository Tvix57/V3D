#include "scene.h"

namespace Tvix57 {

Scene::Scene(QOpenGLShaderProgram *shader)
    : VBO(QOpenGLBuffer::VertexBuffer),
      m_projection_type{ProjectionType::kPerspective},
      m_program{shader} {
  SetupMesh();
  x_axis_color = QColor(255, 0, 0);
  y_axis_color = QColor(0, 255, 0);
  z_axis_color = QColor(0, 0, 255);
  grid_color = QColor(125, 125, 125);
  m_background_color = QColor(255, 255, 255);
}

Scene::~Scene() {
  VAO.destroy();
  VBO.destroy();
}

void Scene::DrawAxis() {
  VAO.bind();
  m_model.setToIdentity();

  m_program->setUniformValue("PointColor", x_axis_color);
  m_program->setUniformValue("model", m_model);
  glDrawArrays(GL_LINES, 0, 6);

  m_model.rotate(90.0f, 0.0f, 1.0f, 0.0f);
  m_program->setUniformValue("PointColor", y_axis_color);
  m_program->setUniformValue("model", m_model);
  glDrawArrays(GL_LINES, 0, 6);

  m_model.rotate(90.0f, 0.0f, 0.0f, 1.0f);
  m_program->setUniformValue("PointColor", z_axis_color);
  m_program->setUniformValue("model", m_model);
  glDrawArrays(GL_LINES, 0, 6);
}

void Scene::DrawGrid() {
  VAO.bind();
  m_program->setUniformValue("PointColor", grid_color);

  m_model.setToIdentity();
  m_model.translate(0.0f, 0.0f, -100.0f);
  for (int i = 0; i <= 200; ++i) {
    m_program->setUniformValue("model", m_model);
    glDrawArrays(GL_LINES, 0, 6);
    m_model.translate(0.0f, 0.0f, 1.0f);
  }

  m_model.setToIdentity();
  m_model.rotate(90.0, 0.0, 1.0, 0.0);
  m_model.translate(0.0f, 0.0f, -100.0f);

  for (int i = 0; i <= 200; ++i) {
    m_program->setUniformValue("model", m_model);
    glDrawArrays(GL_LINES, 0, 6);
    m_model.translate(0.0f, 0.0f, 1.0f);
  }
}

QMatrix4x4 Scene::GetProjectionMat() {
  UpdateProjection();
  return m_projection;
}

QMatrix4x4 Scene::GetTransformMat() { return scene_transform.GetMatrix(); }

const QColor Scene::GetBackgroundColor() const { return m_background_color; }

DrawSceneType Scene::GetDrawType() const { return m_draw_type; }

void Scene::SetProjectionType(ProjectionType type) { m_projection_type = type; }

void Scene::SetProjectionViewAngle(float angle) { m_view_angle = angle; }

void Scene::SetProjectionViewRatio(float ratio) { m_view_ratio = ratio; }

void Scene::SetBackgroundColor(QColor color) { m_background_color = color; }

void Scene::SetDrawType(DrawSceneType type) { m_draw_type = type; }

void Scene::UpdateProjection() {
  m_projection.setToIdentity();

  if (m_projection_type == ProjectionType::kPerspective) {
    m_projection.perspective(m_view_angle, m_view_ratio, 0.01f, 500.0f);
  } else if (m_projection_type == ProjectionType::kOrtho) {
    m_projection.ortho(-m_view_ratio, m_view_ratio, -1.0, 1.0, 0.01f, 500.0f);
  }
}

void Scene::SetupMesh() {
  VAO.create();
  VAO.bind();

  VBO.create();
  VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

  VBO.bind();
  VBO.allocate(vertices, sizeof(vertices));

  m_program->enableAttributeArray(0);
  m_program->setAttributeBuffer(0, GL_FLOAT, 0, 3, 3 * sizeof(float));

  VAO.release();
}

QMatrix4x4 SceneTransformMatrix::GetMatrix() {
  TransformMatrix();
  return matrix;
}

void SceneTransformMatrix::SetTranslateX(float shift) { translate.Tx = shift; }

void SceneTransformMatrix::SetTranslateY(float shift) { translate.Ty = shift; }

void SceneTransformMatrix::SetTranslateZ(float shift) { translate.Tz = shift; }

void SceneTransformMatrix::SetRotateX(float rotate) {
  this->rotate.Rx = rotate;
}

void SceneTransformMatrix::SetRotateY(float rotate) {
  this->rotate.Ry = rotate;
}

void SceneTransformMatrix::SetRotateZ(float rotate) {
  this->rotate.Rz = rotate;
}

TranslateSetting SceneTransformMatrix::GetTranslateSetting() {
  return translate;
}

RotateSetting SceneTransformMatrix::GetRotateSetting() { return rotate; }

void SceneTransformMatrix::TransformMatrix() {
  matrix.setToIdentity();

  matrix.translate(translate.Tx, translate.Ty, translate.Tz);

  matrix.rotate(rotate.Rx, 1.0f, 0.0f, 0.0f);
  matrix.rotate(rotate.Ry, 0.0f, 1.0f, 0.0f);
  matrix.rotate(rotate.Rz, 0.0f, 0.0f, 1.0f);
}

}  // namespace Tvix57
