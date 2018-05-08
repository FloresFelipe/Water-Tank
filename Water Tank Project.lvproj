<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="17008000">
	<Property Name="SMProvider.SMVersion" Type="Int">201310</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="IOScan.Faults" Type="Str"></Property>
		<Property Name="IOScan.NetVarPeriod" Type="UInt">100</Property>
		<Property Name="IOScan.NetWatchdogEnabled" Type="Bool">false</Property>
		<Property Name="IOScan.Period" Type="UInt">10000</Property>
		<Property Name="IOScan.PowerupMode" Type="UInt">0</Property>
		<Property Name="IOScan.Priority" Type="UInt">9</Property>
		<Property Name="IOScan.ReportModeConflict" Type="Bool">true</Property>
		<Property Name="IOScan.StartEngineOnDeploy" Type="Bool">false</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="ESP Target" Type="Folder">
			<Item Name="Pump_Node" Type="Folder">
				<Item Name="Pump_Node.ino" Type="Document" URL="../ESP Target/Pump_Node/Pump_Node.ino"/>
			</Item>
			<Item Name="State_Machine" Type="Folder">
				<Item Name="State_Machine.ino" Type="Document" URL="../ESP Target/State_Machine/State_Machine.ino"/>
			</Item>
		</Item>
		<Item Name="Object Oriented" Type="Folder">
			<Item Name="Main.vi" Type="VI" URL="../Object Oriented/Main.vi"/>
			<Item Name="Pump.lvclass" Type="LVClass" URL="../Object Oriented/Pump Class/Pump.lvclass"/>
			<Item Name="Sensor.lvclass" Type="LVClass" URL="../Object Oriented/Sensor Class/Sensor.lvclass"/>
			<Item Name="Tank.lvclass" Type="LVClass" URL="../Object Oriented/Tank Class/Tank.lvclass"/>
		</Item>
		<Item Name="Task Oriented" Type="Folder">
			<Item Name="Sensor Persistence State.vi" Type="VI" URL="../Task Oriented/Sensor Persistence State.vi"/>
			<Item Name="Water box.vi" Type="VI" URL="../Task Oriented/Water box.vi"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
