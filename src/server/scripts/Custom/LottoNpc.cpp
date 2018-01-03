//
// Created by adizbek on 1/3/18.
//

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "WorldSession.h"
#include "Chat.h"

struct GambleAI : public CreatureAI {
    GambleAI(Creature *creature) : CreatureAI(creature) {

    }

    void UpdateAI(uint32 diff) override {

    }

    virtual bool GossipHello(Player *player) override {
        player->PlayerTalkClass->ClearMenus();
        if (player->GetMoney() > 5000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_01:30|t Gamble 50 silver",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 20);

        if (player->GetMoney() > 10000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 1 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 10);


        if (player->GetMoney() > 50000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 5 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 11);


        if (player->GetMoney() > 150000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 15 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 12);

        if (player->GetMoney() > 250000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 25 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 13);

        if (player->GetMoney() > 500000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 50 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 14);


        if (player->GetMoney() > 1000000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 100 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 6);

        if (player->GetMoney() > 2500000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 250 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 7);


        if (player->GetMoney() > 5000000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 500 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 8);

        if (player->GetMoney() > 10000000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 1000 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 9);

        if (player->GetMoney() > 50000000)
            AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, "|TInterface\\Icons\\INV_Ingot_03:30|t Gamble 5000 gold",
                             GOSSIP_SENDER_MAIN,
                             GOSSIP_ACTION_INFO_DEF + 15);


        else if (player->GetMoney() <= 4999) // if player has less than or equal to 49s 99c
        {
            ChatHandler(player->GetSession()).PSendSysMessage("You don't have the required coins to play.");
            player->PlayerTalkClass->SendCloseGossip();
            return true;
        }

        SendGossipMenuFor(player, 999062, me);
        return true;
    }

    virtual bool GossipSelect(Player *player, uint32 Sender, uint32 action) override {
        uint32 number = urand(1, 3); //Return a random number between the range (uint32 min, uint32 max)

        player->PlayerTalkClass->ClearMenus();
        if (Sender == GOSSIP_SENDER_MAIN)
            switch (action) {
                case GOSSIP_ACTION_INFO_DEF + 6:
                    if (number == 3) {
                        player->ModifyMoney(2000000); // 200g 00s 00c

                        // green = |cff00ff00
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 200 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-1000000); // -100g 00s 00c

                        // red = |cffff0000
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 100 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 7:
                    if (number == 3) {
                        player->ModifyMoney(5000000); // 500g 00s 00c
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 500 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-2500000); // -250g 00s 00c
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 250 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 8:
                    if (number == 3) {
                        player->ModifyMoney(10000000); // 1000g 00s 00c
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 1000 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-5000000); // -500g 00s 00c
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 500 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 9:
                    if (number == 2) {
                        player->ModifyMoney(20000000);
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 2000 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-10000000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 1000 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 10:
                    if (number == 2) {
                        player->ModifyMoney(20000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cff00ff00Congratulations, you won 2 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-10000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 1 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 11:
                    if (number == 2) {
                        player->ModifyMoney(100000);
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 10 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-50000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 5 gold.");
                        player->PlayerTalkClass->SendCloseGossip();

                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 12:
                    if (number == 2) {
                        player->ModifyMoney(300000); // 30 gold
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 30 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-150000); // 15 gold
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 15 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 13:
                    if (number == 2) {
                        player->ModifyMoney(500000);
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 50 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-250000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 25 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 14:
                    if (number == 2) {
                        player->ModifyMoney(1000000);
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 100 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-500000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 50 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 15:
                    if (number == 2) {
                        player->ModifyMoney(100000000);
                        ChatHandler(player->GetSession()).PSendSysMessage(
                                "|cff00ff00Congratulations, you won 10.000 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-50000000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 5000 gold.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

                case GOSSIP_ACTION_INFO_DEF + 20:
                    if (number == 2) {
                        player->ModifyMoney(10000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cff00ff00Congratulations, you won 1 gold!");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;

                    } else {
                        player->ModifyMoney(-5000);
                        ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000You lost 50 silver.");
                        player->PlayerTalkClass->SendCloseGossip();
                        return true;
                    }
                    break;

            }
        return true;
    }

};

class Gamble_npc : public CreatureScript {
public:
    Gamble_npc() : CreatureScript("Gambler") {}

    CreatureAI *GetAI(Creature *creature) const override {
        return new GambleAI(creature);
    }
};


void AddSC_Gamble_npc() {
    new Gamble_npc();
}