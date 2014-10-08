//
// Created by the DataSnap proxy generator.
// 22.01.2013 20:41:38
//

#include "ClientClassesUnit1.h"

System::UnicodeString __fastcall TServerMethods1Client::ConnectTo1C(System::UnicodeString login, System::UnicodeString pass)
{
  if (FConnectTo1CCommand == NULL)
  {
    FConnectTo1CCommand = FDBXConnection->CreateCommand();
    FConnectTo1CCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FConnectTo1CCommand->Text = "TServerMethods1.ConnectTo1C";
    FConnectTo1CCommand->Prepare();
  }
  FConnectTo1CCommand->Parameters->Parameter[0]->Value->SetWideString(login);
  FConnectTo1CCommand->Parameters->Parameter[1]->Value->SetWideString(pass);
  FConnectTo1CCommand->ExecuteUpdate();
  System::UnicodeString result = FConnectTo1CCommand->Parameters->Parameter[2]->Value->GetWideString();
  return result;
}

int __fastcall TServerMethods1Client::Init()
{
  if (FInitCommand == NULL)
  {
    FInitCommand = FDBXConnection->CreateCommand();
    FInitCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FInitCommand->Text = "TServerMethods1.Init";
    FInitCommand->Prepare();
  }
  FInitCommand->ExecuteUpdate();
  int result = FInitCommand->Parameters->Parameter[0]->Value->GetInt32();
  return result;
}

int __fastcall TServerMethods1Client::Destroy()
{
  if (FDestroyCommand == NULL)
  {
    FDestroyCommand = FDBXConnection->CreateCommand();
    FDestroyCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FDestroyCommand->Text = "TServerMethods1.Destroy";
    FDestroyCommand->Prepare();
  }
  FDestroyCommand->ExecuteUpdate();
  int result = FDestroyCommand->Parameters->Parameter[0]->Value->GetInt32();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::FindOrders(System::UnicodeString beginDate, System::UnicodeString endDate, System::UnicodeString filter)
{
  if (FFindOrdersCommand == NULL)
  {
    FFindOrdersCommand = FDBXConnection->CreateCommand();
    FFindOrdersCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FFindOrdersCommand->Text = "TServerMethods1.FindOrders";
    FFindOrdersCommand->Prepare();
  }
  FFindOrdersCommand->Parameters->Parameter[0]->Value->SetWideString(beginDate);
  FFindOrdersCommand->Parameters->Parameter[1]->Value->SetWideString(endDate);
  FFindOrdersCommand->Parameters->Parameter[2]->Value->SetWideString(filter);
  FFindOrdersCommand->ExecuteUpdate();
  System::UnicodeString result = FFindOrdersCommand->Parameters->Parameter[3]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::FindGoods(System::UnicodeString n, System::UnicodeString d1, System::UnicodeString d2)
{
  if (FFindGoodsCommand == NULL)
  {
    FFindGoodsCommand = FDBXConnection->CreateCommand();
    FFindGoodsCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FFindGoodsCommand->Text = "TServerMethods1.FindGoods";
    FFindGoodsCommand->Prepare();
  }
  FFindGoodsCommand->Parameters->Parameter[0]->Value->SetWideString(n);
  FFindGoodsCommand->Parameters->Parameter[1]->Value->SetWideString(d1);
  FFindGoodsCommand->Parameters->Parameter[2]->Value->SetWideString(d2);
  FFindGoodsCommand->ExecuteUpdate();
  System::UnicodeString result = FFindGoodsCommand->Parameters->Parameter[3]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::FindUsers()
{
  if (FFindUsersCommand == NULL)
  {
    FFindUsersCommand = FDBXConnection->CreateCommand();
    FFindUsersCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FFindUsersCommand->Text = "TServerMethods1.FindUsers";
    FFindUsersCommand->Prepare();
  }
  FFindUsersCommand->ExecuteUpdate();
  System::UnicodeString result = FFindUsersCommand->Parameters->Parameter[0]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::SaveOrder(System::UnicodeString order, System::UnicodeString goods)
{
  if (FSaveOrderCommand == NULL)
  {
    FSaveOrderCommand = FDBXConnection->CreateCommand();
    FSaveOrderCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FSaveOrderCommand->Text = "TServerMethods1.SaveOrder";
    FSaveOrderCommand->Prepare();
  }
  FSaveOrderCommand->Parameters->Parameter[0]->Value->SetWideString(order);
  FSaveOrderCommand->Parameters->Parameter[1]->Value->SetWideString(goods);
  FSaveOrderCommand->ExecuteUpdate();
  System::UnicodeString result = FSaveOrderCommand->Parameters->Parameter[2]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::SaveNewOrder(System::UnicodeString order, System::UnicodeString goods)
{
  if (FSaveNewOrderCommand == NULL)
  {
    FSaveNewOrderCommand = FDBXConnection->CreateCommand();
    FSaveNewOrderCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FSaveNewOrderCommand->Text = "TServerMethods1.SaveNewOrder";
    FSaveNewOrderCommand->Prepare();
  }
  FSaveNewOrderCommand->Parameters->Parameter[0]->Value->SetWideString(order);
  FSaveNewOrderCommand->Parameters->Parameter[1]->Value->SetWideString(goods);
  FSaveNewOrderCommand->ExecuteUpdate();
  System::UnicodeString result = FSaveNewOrderCommand->Parameters->Parameter[2]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::SaveNewOrder3(System::UnicodeString order, System::UnicodeString goods)
{
  if (FSaveNewOrder3Command == NULL)
  {
    FSaveNewOrder3Command = FDBXConnection->CreateCommand();
    FSaveNewOrder3Command->CommandType = TDBXCommandTypes_DSServerMethod;
    FSaveNewOrder3Command->Text = "TServerMethods1.SaveNewOrder3";
    FSaveNewOrder3Command->Prepare();
  }
  FSaveNewOrder3Command->Parameters->Parameter[0]->Value->SetWideString(order);
  FSaveNewOrder3Command->Parameters->Parameter[1]->Value->SetWideString(goods);
  FSaveNewOrder3Command->ExecuteUpdate();
  System::UnicodeString result = FSaveNewOrder3Command->Parameters->Parameter[2]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::SaveRemakeOrder(System::UnicodeString order, System::UnicodeString goods)
{
  if (FSaveRemakeOrderCommand == NULL)
  {
    FSaveRemakeOrderCommand = FDBXConnection->CreateCommand();
    FSaveRemakeOrderCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FSaveRemakeOrderCommand->Text = "TServerMethods1.SaveRemakeOrder";
    FSaveRemakeOrderCommand->Prepare();
  }
  FSaveRemakeOrderCommand->Parameters->Parameter[0]->Value->SetWideString(order);
  FSaveRemakeOrderCommand->Parameters->Parameter[1]->Value->SetWideString(goods);
  FSaveRemakeOrderCommand->ExecuteUpdate();
  System::UnicodeString result = FSaveRemakeOrderCommand->Parameters->Parameter[2]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::FindAgents(System::UnicodeString filter)
{
  if (FFindAgentsCommand == NULL)
  {
    FFindAgentsCommand = FDBXConnection->CreateCommand();
    FFindAgentsCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FFindAgentsCommand->Text = "TServerMethods1.FindAgents";
    FFindAgentsCommand->Prepare();
  }
  FFindAgentsCommand->Parameters->Parameter[0]->Value->SetWideString(filter);
  FFindAgentsCommand->ExecuteUpdate();
  System::UnicodeString result = FFindAgentsCommand->Parameters->Parameter[1]->Value->GetWideString();
  return result;
}

System::UnicodeString __fastcall TServerMethods1Client::Find(System::UnicodeString query, System::UnicodeString send_params, System::UnicodeString get_params)
{
  if (FFindCommand == NULL)
  {
    FFindCommand = FDBXConnection->CreateCommand();
    FFindCommand->CommandType = TDBXCommandTypes_DSServerMethod;
    FFindCommand->Text = "TServerMethods1.Find";
    FFindCommand->Prepare();
  }
  FFindCommand->Parameters->Parameter[0]->Value->SetWideString(query);
  FFindCommand->Parameters->Parameter[1]->Value->SetWideString(send_params);
  FFindCommand->Parameters->Parameter[2]->Value->SetWideString(get_params);
  FFindCommand->ExecuteUpdate();
  System::UnicodeString result = FFindCommand->Parameters->Parameter[3]->Value->GetWideString();
  return result;
}


__fastcall  TServerMethods1Client::TServerMethods1Client(TDBXConnection *ADBXConnection)
{
  if (ADBXConnection == NULL)
    throw EInvalidOperation("Connection cannot be nil.  Make sure the connection has been opened.");
  FDBXConnection = ADBXConnection;
  FInstanceOwner = True;
}


__fastcall  TServerMethods1Client::TServerMethods1Client(TDBXConnection *ADBXConnection, bool AInstanceOwner)
{
  if (ADBXConnection == NULL)
    throw EInvalidOperation("Connection cannot be nil.  Make sure the connection has been opened.");
  FDBXConnection = ADBXConnection;
  FInstanceOwner = AInstanceOwner;
  Init();
}


__fastcall  TServerMethods1Client::~TServerMethods1Client()
{
  Destroy();
  delete FConnectTo1CCommand;
  delete FInitCommand;
  delete FDestroyCommand;
  delete FFindOrdersCommand;
  delete FFindGoodsCommand;
  delete FFindUsersCommand;
  delete FSaveOrderCommand;
  delete FSaveNewOrderCommand;
  delete FSaveNewOrder3Command;
  delete FSaveRemakeOrderCommand;
  delete FFindAgentsCommand;
  delete FFindCommand;
}


