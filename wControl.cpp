#include "wControl.h"
#include <QFile>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QStandardItemModel>

WControl::WControl() {
    watcher = new QFileSystemWatcher(this);
    connect(watcher, &QFileSystemWatcher::directoryChanged, this, &WControl::onDirectoryChanged);
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &WControl::onDirectoryChanged);
}

WControl::~WControl() {

    delete watcher;
}

void WControl::openFileButton() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Все файлы (*.*);;Файлы 1sp (*.s1p)");
    if(fileName.isEmpty()) return;
    else openFile(fileName);
}

void WControl::openFolderButton(void) {
    QString dirName = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dirName.isEmpty()) return;
    QDir directory(dirName);
    QStringList files = directory.entryList((QStringList)"*.s1p", QDir::Files);

    currentDirectory = dirName;
    watcher->addPath(dirName);

    for (auto &x : files) x = dirName + '/' + x;
    uint32_t counter = files.count();
    emit listFiles(files, counter);
}

void WControl::openFile(QString fileName) {
    QFile file(fileName);
    QString suffix = QFileInfo(fileName).suffix().toLower();

    if (suffix != "s1p") messageBoxHandler("Ошибка", "Неправильный формат: Пожалуйста, выберите файл формата:\".s1p\"");
    else if(!file.open(QIODevice::ReadOnly)) messageBoxHandler("Ошибка", "Файл не удалось открыть!");
    else
    {
        QList<double> xpos; QList<double> ypos;
        uint32_t counter = 0;
        QTextStream containData(&file);
        uint32_t lineNumber = 0;
        bool data_ok = true;
        while (!containData.atEnd()) {
            QString line = containData.readLine();
            lineNumber++;
            if (line.startsWith('!') || line.startsWith('#') || line.trimmed().isEmpty() || line.isEmpty()) {
                continue;
            }

            QStringList values = line.split(" ", Qt::SkipEmptyParts);

            if (values.size() < 3)
            {
                messageBoxHandler("Ошибка!", QString("Строка %1:").arg(lineNumber) + " недостаточно значений.");
                data_ok = false;
                break;
            }

            bool ok0, ok1, ok2;
            xpos.append(values[0].toDouble(&ok0));
            ypos.append(20.0 * std::log10(sqrt(pow(values[1].toDouble(&ok1), 2) + pow(values[2].toDouble(&ok2), 2)))); // Convet to "LogMag"

            if (!ok0 || !ok1 || !ok2) {
                messageBoxHandler("Ошибка!", QString("Строка %1:").arg(lineNumber) + " содержит нечисловые значения.");
                data_ok = false;
                break;
            }

            counter++;
        }
        if (data_ok)
        {
            emit dataPos(xpos, ypos, counter);
            file.close();
            xpos.clear(); ypos.clear();
        }
        else
        {
            file.close();
            xpos.clear(); ypos.clear();
        }

    }
    return;
}

void WControl::onDirectoryChanged(const QString &path) {
    if (path == currentDirectory) updateFileList();
}

void WControl::updateFileList() {
    QDir directory(currentDirectory);
    QStringList files = directory.entryList(QStringList() << "*.s1p", QDir::Files);

    for (auto &x : files) x = currentDirectory + '/' + x;
    uint32_t counter = files.count();
    emit listFiles(files, counter);
}

void WControl::messageBoxHandler(const QString &title, const QString &text) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}















