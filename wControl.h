#ifndef WCONTROL_H
#define WCONTROL_H

#include <QMessageBox>
#include <QFileDialog>
#include <QObject>
#include <QFileSystemWatcher>

class WControl : public QObject {
    Q_OBJECT
public:

    WControl();
    ~WControl();

    Q_INVOKABLE void openFileButton();              // The button to open the file
    Q_INVOKABLE void openFolderButton();            // The button to open the folder
    Q_INVOKABLE void openFile(QString fileName);    // The function to open the file

signals:
    void dataPos(const QList<double> &xpos, const QList<double> &ypos, uint32_t count); // Signal of current graph points
    void listFiles(const QList<QString> &xpos, uint32_t count);                         // Signal list of files

private:
    QFileSystemWatcher *watcher = nullptr;
    QString currentDirectory;                                               // Current directory
    void updateFileList();                                                  // Function upadate list
    void messageBoxHandler(const QString &title, const QString &text);      // MessageBox handler

private slots:
    void onDirectoryChanged(const QString &path);                           // File change handler
};

#endif // WCONTROL_H
