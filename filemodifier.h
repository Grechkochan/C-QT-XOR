#ifndef FILEMODIFIER_H
#define FILEMODIFIER_H

#include <QObject>
#include <QStringList>
#include <QByteArray>

class FileModifier : public QObject
{
    Q_OBJECT

public:
    explicit FileModifier(QObject *parent = nullptr);

    void setParameters(const QStringList &files, const QByteArray &xorKey,
                       const QString &outputDir, bool overwrite, bool deleteFiles);

    void startProcessing();

signals:
    void progressUpdated(int percent);
    void statusMessage(const QString &msg);
    void processingFinished();

private:
    QStringList m_files;
    QByteArray m_xorKey;
    QString m_outputDir;
    bool m_overwrite;
    bool m_deleteFiles;
};

#endif // FILEMODIFIER_H
