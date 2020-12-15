#ifndef TESTENTIRETYDATA_H
#define TESTENTIRETYDATA_H
#include <QString>
#include <vector>
class TestEntiretyData
{
public:
    TestEntiretyData();
    void TestAvalible(QString Data);
    void TestJson(QString Data);
    void TestBad(QString Data);
    QString ShowResTest();
private:
    int success_test=0;
    int all_test=0;
    QString TestAvalibleData="{\"OpType\":\"0\", \"Accept\":\"1\", \"Users\":[\"Goose\",\"JoJo\"], \"Programs\":[\"Skype\",\"Zoom\",\"DarkSouls\",\"Fifa\",\"Sekiro\"]}";
    QString TestJsonData="{\"OpType\":\"1\",\"Users\":[{\"name\":\"Goose\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Zoom\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"DarkSouls\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]},{\"name\":\"Yuki\", \"ID\":\"11\", \"Programs\":[{\"name\":\"Skype\",\"ID\":\"121\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Wakanim\",\"ID\":\"122\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]},{\"name\":\"Sekiro\",\"ID\":\"123\",\"HourWork\":[{\"creationDate\":\"Nov 17, 2020, 8:54:32 PM\",\"workTime\":\"5\",\"activeWindowTime\":\"2\",\"threadAmount\":\"2\",\"cpuUsage\":\"1.941\",\"ramUsage\":\"1231\"},{\"creationDate\":\"Nov 18, 2020, 8:54:32 PM\",\"workTime\":\"2\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"4.912\",\"ramUsage\":\"2131\"},{\"creationDate\":\"Nov 19, 2020, 8:54:32 PM\",\"workTime\":\"7\",\"activeWindowTime\":\"1\",\"threadAmount\":\"2\",\"cpuUsage\":\"8.271\",\"ramUsage\":\"3131\"}]}]}]}";
    QString TestBadLog="{\"OpType\":\"0\",\"Accept\":\"0\"}";
    std::vector <QString> AllTests;
};

#endif // TESTENTIRETYDATA_H
