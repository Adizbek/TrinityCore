/*
+#Patch: Announce Arena Points
+#By: r0m1ntik
+#Tested: Yes
+#Work: Yes
+*/
#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "DatabaseEnv.h"


struct BroadcastData {
    uint32 time;
};

struct BroadcastData Broadcasts[] =
        {
                {300000}, // 5 минут (в мили секундах)
        };

#define BROADCAST_COUNT  sizeof Broadcasts/sizeof(*Broadcasts)

class AnnounceArenaPoints : public WorldScript {
public:
    AnnounceArenaPoints() : WorldScript("AnnounceArenaPoints") {}

    void OnStartup() {
        for (uint32 i = 0; i < BROADCAST_COUNT; i++)
            events.ScheduleEvent(i + 1, Broadcasts[i].time);
    }

    void OnUpdate(uint32 diff) {
        events.Update(diff);
        while (uint32 id = events.ExecuteEvent()) {
            if (id <= BROADCAST_COUNT) {
                QueryResult result1 = CharacterDatabase.PQuery("SELECT value FROM worldstates WHERE entry = 20001");
                if (result1) {
                    Field *fields = NULL;
                    fields = result1->Fetch();
                    uint32 value = fields[0].GetUInt32();

                    time_t autoDisTime = value;
                    double waitTime = difftime(autoDisTime, time(NULL));

                    int32 dWait = int(int(waitTime / 60) / 60) / 24;
                    waitTime -= dWait * 60 * 60 * 24;
                    int32 hWait = int(waitTime / 60) / 60;
                    waitTime -= hWait * 60 * 60;
                    int32 mWait = waitTime / 60;
                    waitTime -= mWait * 60;
                    int32 sWait = waitTime;

                    std::ostringstream ss;
                    ss
                            << "|cffff6060[|cff00e600Арена Пойнт|cffff6060]:|cff00e600 Начесление Арена Пойнт будет через: |cffff0000"
                            << dWait << "|r Дней |cffff0000" << hWait << "|r часов |cffff0000" << mWait
                            << "|r минут |cffff0000" << sWait << "|r секунд.";
                    sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                    events.ScheduleEvent(id, Broadcasts[id - 1].time);

                }
            }
        }
    }

private:
    EventMap events;
};

void AddSC_AnnounceArenaPoints() {
    new AnnounceArenaPoints();
}