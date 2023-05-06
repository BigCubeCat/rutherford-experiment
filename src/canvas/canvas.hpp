#include "../simulation/simulation.hpp"
#include "../utils/utils.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Canvas;
}
QT_END_NAMESPACE

class Canvas : public QWidget {
    Q_OBJECT

  public:
    explicit Canvas(QWidget *parent = nullptr);
    TScene scene;
    ~Canvas();
    void SpawnParticle();
  public slots:
    void tick();

  private:
    void InitScene();

    QPixmap pixmap;
    QTimer *timer;

  protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *e) override;
  signals:
    void updateData();
};
