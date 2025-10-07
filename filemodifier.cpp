#include "filemodifier.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QByteArray>

FileModifier::FileModifier(QObject *parent) : QObject(parent), m_overwrite(false)
{
}

void FileModifier::setParameters(const QStringList &files, const QByteArray &xorKey,
                                 const QString &outputDir, bool overwrite, bool deleteFiles)
{
    m_files = files;
    m_xorKey = xorKey;
    m_outputDir = outputDir;
    m_overwrite = overwrite;
    m_deleteFiles = deleteFiles;
}

void FileModifier::startProcessing()
{
    int totalFiles = m_files.size();
    for (int i = 0; i < totalFiles; ++i) {
        QFile inputFile(m_files[i]);
        if (!inputFile.open(QIODevice::ReadOnly)) {
            emit statusMessage("Не удалось открыть файл: " + m_files[i]);
            continue;
        }

        QByteArray fileData = inputFile.readAll();
        inputFile.close();

        for (int j = 0; j < fileData.size(); ++j) {
            fileData[j] ^= m_xorKey[j % m_xorKey.size()];
        }

        QString outputFileName = m_files[i];
        QFileInfo fileInfo(m_files[i]);
        QString outputPath = m_outputDir + "/" + fileInfo.fileName();

        if (QFile::exists(outputPath) && !m_overwrite) {
            int counter = 1;
            while (QFile::exists(outputPath)) {
                outputPath = m_outputDir + "/" + fileInfo.completeBaseName() + QString("-%1").arg(counter++) + "." + fileInfo.suffix();
            }
        }

        QFile outputFile(outputPath);
        if (outputFile.open(QIODevice::WriteOnly)) {
            outputFile.write(fileData);
            outputFile.close();

            if (m_deleteFiles) {
                QFile inputFile(m_files[i]);
                if (inputFile.remove()) {
                    emit statusMessage(QString("Файл удален: %1").arg(m_files[i]));
                } else {
                    emit statusMessage(QString("Не удалось удалить файл: %1").arg(m_files[i]));
                }
            }
        }
        emit progressUpdated(static_cast<int>((i + 1) * 100.0 / totalFiles));
        emit statusMessage(QString("Обработан файл: %1").arg(m_files[i]));
    }

    emit processingFinished();
}
