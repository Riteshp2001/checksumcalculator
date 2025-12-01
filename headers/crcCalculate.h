#ifndef CRCCALCULATE_H
#define CRCCALCULATE_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QStyle>
#include <QPushButton>
#include <QClipboard>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QToolTip>
#include <QComboBox>
#include <QCryptographicHash>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class crcCalculate; }
QT_END_NAMESPACE

// Class to calculate CRC checksum
class crcCalculate : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    crcCalculate(QWidget *parent = nullptr);
    // Destructor
    ~crcCalculate();

    // Calculates checksum for a file
    QString CalculateChecksum(const QString &filePath);
    // Computes CRC value
    unsigned short computeCrc(unsigned char *message, qint64 blk_len);

    enum ChecksumType {
        CRC16,
        CRC32,
        MD5,
        SHA1,
        SHA256
    };

protected:
    // Handles drag enter event
    void dragEnterEvent(QDragEnterEvent *event) override;
    // Handles drop event
    void dropEvent(QDropEvent *event) override;

private slots:
    // Slot for add files button click
    void on_btnAddFiles_clicked();
    // Slot for clear button click
    void on_btnClear_clicked();
    // Slot for table item click
    void onTableItemClicked(int row, int column);
    // Slot for checksum type change
    void onChecksumTypeChanged(int index);

private:
    // UI pointer
    Ui::crcCalculate *ui;
    // Current checksum type
    ChecksumType currentType;

    // Sets up the table widget
    void setupTable();
    // Finds row index by file path
    int findRowByPath(const QString &fullFilePath);
    // Processes a file to calculate checksum
    void processFile(const QString &filePath);
    // Updates checksums for all files
    void updateChecksums();
    // Computes CRC32
    unsigned int computeCrc32(const QByteArray &data);
};
#endif // CRCCALCULATE_H
