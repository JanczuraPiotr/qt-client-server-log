
Record::Record(QSqlRecord &rec)
    : rec(rec)
{
}

QSqlRecord &Record::generic() {
    return rec;
}

}