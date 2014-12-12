object ClientModule1: TClientModule1
  OldCreateOrder = False
  Height = 271
  Width = 415
  object SQLConnection1: TSQLConnection
    DriverName = 'Datasnap'
    LoginPrompt = False
    Params.Strings = (
      'DriverUnit=DBXDataSnap'
      'HostName=192.168.137.60'
      'Port=211'
      'CommunicationProtocol=tcp/ip'
      'DatasnapContext=datasnap/'
      
        'DriverAssemblyLoader=Borland.Data.TDBXClientDriverLoader,Borland' +
        '.Data.DbxClientDriver,Version=15.0.0.0,Culture=neutral,PublicKey' +
        'Token=91d62ebb5b0d1b1b'
      'Filters={}')
    Left = 48
    Top = 40
    UniqueId = '{8E29B8E9-FE78-4258-A2B9-5BA30A48F2A7}'
  end
end
