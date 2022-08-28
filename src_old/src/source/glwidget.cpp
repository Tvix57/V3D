#include "../include/glwidget.h"

#include <math.h>

#include <QTimer>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
    line_type = false;
    viey_type = false;
    dot_type = 0;
    objModel = nullptr;
    sl_x = 0;
    sl_y = 0;
    sl_z = 0;
    step_x = 0;
    step_y = 0;
    step_z = 0;
}

GLWidget::~GLWidget() {
    clearModel(objModel);
    cleanup();
}

void GLWidget::cleanup() {
    makeCurrent();
    doneCurrent();
}

void GLWidget::initializeGL() {
    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this,
            &GLWidget::cleanup);
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL() {
    set_camera();
    drow();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GLWidget::get_setting(QSettings current_set) {
    QVariant line_color_v =
        current_set.value("settings/line_color", QColor(Qt::blue));
    line_color = line_color_v.value<QColor>();

    QVariant dot_color_v =
        current_set.value("settings/dot_color", QColor(Qt::green));
    dot_color = dot_color_v.value<QColor>();

    QVariant background_v =
        current_set.value("settings/background_color", QColor(Qt::black));
    background_color = background_v.value<QColor>();

    line_size = current_set.value("settings/line_size", 2).toInt();
    dot_size = current_set.value("settings/dot_size", 2).toInt();

    line_type = current_set.value("settings/type_dot_line", false).toBool();

    viey_type = current_set.value("settings/center_parallel", false).toBool();

    if (current_set.value("settings/view_type_qadro", false).toBool()) {
        dot_type = 2;
    } else if (current_set.value("settings/view_type_circle", false).toBool()) {
        dot_type = 1;
    } else {
        dot_type = 0;
    }
    update();
}

void GLWidget::scale_chaged(int value) {
    this->scale = value / 10.0;
    update();
}

void GLWidget::set_camera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLdouble ratio = (GLdouble)this->width() / (GLdouble)this->height();
    if (viey_type) {
        glFrustum(-0.1 * ratio, 0.1 * ratio, -0.1, 0.1, 0.1, 50.0);
    } else {
        glOrtho(-1.0 * ratio, 1.0 * ratio, -1.2, 1.2, 1, 20);
    }
}

void GLWidget::drow_dots() {
    if (dot_type != 0) {
        glVertexPointer(3, GL_DOUBLE, 0, objModel->vertexes);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColor3f(dot_color.redF(), dot_color.greenF(), dot_color.blueF());
        glPointSize((GLfloat)dot_size);
        if (dot_type == 1) {
            glEnable(GL_POINT_SMOOTH);
        } else {
            glDisable(GL_POINT_SMOOTH);
        }
        glDrawArrays(GL_POINTS, 0, objModel->vertex_count);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
}

void GLWidget::drow_lines() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, objModel->vertexes);
    glColor3d(line_color.redF(), line_color.greenF(), line_color.blueF());
    glLineWidth((GLfloat)line_size);
    if (line_type) {
        glLineStipple(1, 0x3333);
        glEnable(GL_LINE_STIPPLE);
    } else {
        glDisable(GL_LINE_STIPPLE);
        glEnable(GL_LINE);
    }
    glDrawElements(GL_TRIANGLES, objModel->face_count, GL_UNSIGNED_INT, objModel->faces);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::set_new_model(char *filename) {
    objModel = getModel(filename);
    update();
}

void GLWidget::change_position(QString name_btn) {
    GLdouble step = 1.01;
    if (name_btn == "Up") {
        step_y += step;
    } else if (name_btn == "Down") {
        step_y -= step;
    } else if (name_btn == "Right") {
        step_x += step;
    } else if (name_btn == "Left") {
        step_x -= step;
    } else if (name_btn == "Forward") {
        step_z += step;
    } else if (name_btn == "Back") {
        step_z -= step;
    }
    update();
}

void GLWidget::drow() {
    glClearColor(background_color.redF(), background_color.greenF(),
                 background_color.blueF(), 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (objModel != nullptr) {
        glScaled(scale, scale, scale);
        glScalef(0.5, 0.5, 0.5);
        glTranslated(step_x, step_y, step_z);
        glRotated(sl_x, 1, 0, 0);
        glRotated(sl_y, 0, 1, 0);
        glRotated(sl_z, 0, 0, 1);
        drow_dots();
        drow_lines();
    }
}

unsigned int GLWidget::get_vertex_count() {
    return objModel->vertex_count;
}

unsigned int GLWidget::get_face_count() {
    return objModel->face_count;
}

void GLWidget::set_sl_x_val(int x) {
    this->sl_x = x;
    update();
}

void GLWidget::set_sl_y_val(int y) {
    this->sl_y = y;
    update();
}

void GLWidget::set_sl_z_val(int z) {
    this->sl_z = z;
    update();
}
