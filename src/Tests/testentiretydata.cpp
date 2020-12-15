#include "testentiretydata.h"

TestEntiretyData::TestEntiretyData()
{
    AllTests.push_back("----Tests_start----\n");
}

void TestEntiretyData::TestAvalible(QString Data)
{
    all_test++;
    if(TestAvalibleData==Data)
    {
        AllTests.push_back("Test_Avalible_data_success\n");
        success_test++;
    }
    else
        AllTests.push_back("Test_Avalible_data_BAD\n");
}
void TestEntiretyData::TestJson(QString Data)
{
    all_test++;
    if(TestJsonData==Data)
    {
        AllTests.push_back("Test_Json_data_success\n");
        success_test++;
    }
    else
        AllTests.push_back("Test_Json_data_BAD\n");
}
void TestEntiretyData::TestBad(QString Data)
{
    all_test++;
    if(TestBadLog==Data)
    {
        AllTests.push_back("Test_Bad_Login_data_success\n");
        success_test++;
    }
    else
        AllTests.push_back("Test_Bad_Login_data_BAD\n");
}

QString TestEntiretyData::ShowResTest()
{
    QString TestData="";
    TestData+=AllTests[0]+"\n";
    for(int i = 1; i<AllTests.size();i++)
    {
        TestData+=QString::number(i)+") "+AllTests[i]+"\n";
    }
    TestData+="UNIT_TEST_RES:\nSuccessfully run: "+QString::number(success_test)+" from "+QString::number(all_test);
    return TestData;
}
