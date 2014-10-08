#ifndef ClientClassesUnit1H
#define ClientClassesUnit1H

#include "DBXCommon.hpp"
#include "Classes.hpp"
#include "SysUtils.hpp"
#include "DB.hpp"
#include "SqlExpr.hpp"
#include "DBXDBReaders.hpp"

  class TServerMethods1Client : public TObject
  {
  private:
    TDBXConnection *FDBXConnection;
    bool FInstanceOwner;
    TDBXCommand *FConnectTo1CCommand;
    TDBXCommand *FInitCommand;
    TDBXCommand *FDestroyCommand;
    TDBXCommand *FFindOrdersCommand;
    TDBXCommand *FFindGoodsCommand;
    TDBXCommand *FFindUsersCommand;
    TDBXCommand *FSaveOrderCommand;
    TDBXCommand *FSaveNewOrderCommand;
    TDBXCommand *FSaveNewOrder3Command;
    TDBXCommand *FSaveRemakeOrderCommand;
    TDBXCommand *FFindAgentsCommand;
    TDBXCommand *FFindCommand;
  public:
    __fastcall TServerMethods1Client::TServerMethods1Client(TDBXConnection *ADBXConnection);
    __fastcall TServerMethods1Client::TServerMethods1Client(TDBXConnection *ADBXConnection, bool AInstanceOwner);
    __fastcall TServerMethods1Client::~TServerMethods1Client();
    System::UnicodeString __fastcall ConnectTo1C(System::UnicodeString login, System::UnicodeString pass);
    int __fastcall Init();
    int __fastcall Destroy();
    System::UnicodeString __fastcall FindOrders(System::UnicodeString beginDate, System::UnicodeString endDate, System::UnicodeString filter);
    System::UnicodeString __fastcall FindGoods(System::UnicodeString n, System::UnicodeString d1, System::UnicodeString d2);
    System::UnicodeString __fastcall FindUsers();
    System::UnicodeString __fastcall SaveOrder(System::UnicodeString order, System::UnicodeString goods);
    System::UnicodeString __fastcall SaveNewOrder(System::UnicodeString order, System::UnicodeString goods);
    System::UnicodeString __fastcall SaveNewOrder3(System::UnicodeString order, System::UnicodeString goods);
    System::UnicodeString __fastcall SaveRemakeOrder(System::UnicodeString order, System::UnicodeString goods);
    System::UnicodeString __fastcall FindAgents(System::UnicodeString filter);
    System::UnicodeString __fastcall Find(System::UnicodeString query, System::UnicodeString send_params, System::UnicodeString get_params);
  };

#endif

