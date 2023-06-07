#include <QtTest>
#include <../../hallServer/client.h>
// add necessary includes here

class heapsort_testcase : public QObject
{
    Q_OBJECT

public:
    heapsort_testcase();
    ~heapsort_testcase();
    Client* c;
private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
    void test_case7();
    void test_case8();
    void test_case9();
    void test_case10();
};

heapsort_testcase::heapsort_testcase()
{
    c = new Client(nullptr);
}

heapsort_testcase::~heapsort_testcase()
{

}

void heapsort_testcase::test_case1()
{
    std::vector<QString> r = c->parser("sort&5&8 7 6 5 4");
    bool result = r[0] == "4 | 7 5 6 4 8 \r\n" &&
            r[1] == "3 | 6 5 4 7 8 \r\n" &&
            r[2] == "2 | 5 4 6 7 8 \r\n" &&
            r[3] == "1 | 4 5 6 7 8 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case2()
{
    std::vector<QString> r = c->parser("sort&3&8 7 6 5 4");
    bool result = r[0] == "2 | 7 6 8 5 4 \r\n" &&
            r[1] == "1 | 6 7 8 5 4 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case3()
{
    std::vector<QString> r = c->parser("sort&2&8 9 1");
    bool result = r[0] == "1 | 8 9 1 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case4()
{
    std::vector<QString> r = c->parser("sort&4&1 4 2 3");
    bool result = r[0] == "3 | 3 1 2 4 \r\n" &&
            r[1] == "2 | 2 1 3 4 \r\n" &&
            r[2] == "1 | 1 2 3 4 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case5()
{
    std::vector<QString> r = c->parser("sort&5&1 2 8 6 4 3");
    bool result = r[0] == "4 | 6 4 1 2 8 3 \r\n" &&
            r[1] == "3 | 4 2 1 6 8 3 \r\n" &&
            r[2] == "2 | 2 1 4 6 8 3 \r\n" &&
            r[3] == "1 | 1 2 4 6 8 3 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case6()
{
    std::vector<QString> r = c->parser("sort&3&12 24 11");
    bool result = r[0] == "2 | 12 11 24 \r\n" &&
            r[1] == "1 | 11 12 24 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case7()
{
    std::vector<QString> r = c->parser("sort&3&10 20 30");
    bool result = r[0] == "2 | 20 10 30 \r\n" &&
            r[1] == "1 | 10 20 30 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case8()
{
    std::vector<QString> r = c->parser("sort&2&1 2 3");
    bool result = r[0] == "1 | 1 2 3 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case9()
{
    std::vector<QString> r = c->parser("sort&3&10 50 40 30 20");
    bool result = r[0] == "2 | 40 10 50 30 20 \r\n" &&
            r[1] == "1 | 10 40 50 30 20 \r\n";
    QVERIFY(result);
}
void heapsort_testcase::test_case10()
{
    std::vector<QString> r = c->parser("sort&3&999 222 111");
    bool result = r[0] == "2 | 222 111 999 \r\n" &&
            r[1] == "1 | 111 222 999 \r\n";
    QVERIFY(result);
}


QTEST_APPLESS_MAIN(heapsort_testcase)

#include "tst_heapsort_testcase.moc"
