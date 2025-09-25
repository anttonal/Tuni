#include <QtTest>
#include "../gameboard.hh"

class path_test : public QObject
{
    Q_OBJECT

public:
    path_test();
    ~path_test();

private slots:
    void test_FailedMove();
    void test_SuccessfulMove();
    // Define test data: from, to, expected result
    void test_DataDrivenMove_data();
    // Run test using the data above
    void test_DataDrivenMove();
};

path_test::path_test() {}
path_test::~path_test() {}

void path_test::test_FailedMove()
{
    GameBoard board;
    board.initialFill();

    Location from{1, 5}; // Red button
    Location to{1, 1};   // Empty top row

    QVERIFY(!board.move(from, to)); // Should fail succesfully
}

void path_test::test_SuccessfulMove()
{
    GameBoard board;
    board.initialFill();

    Location from{2, 1}; // Green button
    Location to{3, 3};   // Empty path to {3, 3} cell

    QVERIFY(board.move(from, to)); // Should succeed
}

void path_test::test_DataDrivenMove_data()
{
    QTest::addColumn<Location>("from");
    QTest::addColumn<Location>("to");
    QTest::addColumn<bool>("expected");

    QTest::newRow("valid move") << Location{2, 1} << Location{3, 3} << true;
    QTest::newRow("invalid move") << Location{1, 5} << Location{1, 6} << false;
    QTest::newRow("blocked move") << Location{2, 1} << Location{1, 1} << false;
}

void path_test::test_DataDrivenMove()
{
    QFETCH(Location, from);
    QFETCH(Location, to);
    QFETCH(bool, expected);

    GameBoard board;
    board.initialFill();
    QCOMPARE(board.move(from, to), expected);
}

QTEST_APPLESS_MAIN(path_test)
#include "tst_path_test.moc"
