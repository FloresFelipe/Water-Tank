<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="18008000">
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
		<Item Name="Shared" Type="Folder">
			<Item Name="Globals.vi" Type="VI" URL="../Simulation/State Machines/Shared/Globals.vi"/>
		</Item>
		<Item Name="Simulation" Type="Folder">
			<Property Name="NI.SortType" Type="Int">3</Property>
			<Item Name="State Machines" Type="Folder">
				<Item Name="Node 1 - Sensors + UDP" Type="Folder">
					<Item Name="Sensors + UDP.vi" Type="VI" URL="../Simulation/State Machines/Node 1 - Sensors + UDP/Sensors + UDP.vi"/>
					<Item Name="Node 1 - States.ctl" Type="VI" URL="../Simulation/State Machines/Node 1 - Sensors + UDP/Node 1 - States.ctl"/>
				</Item>
				<Item Name="Node 2- Senros + UDP" Type="Folder">
					<Item Name="Pump + UDP.vi" Type="VI" URL="../Simulation/State Machines/Node 2 - Pump + UDP/Pump + UDP.vi"/>
					<Item Name="Node 2 - States.ctl" Type="VI" URL="../Simulation/State Machines/Node 2 - Pump + UDP/Node 2 - States.ctl"/>
					<Item Name="Node 2 - Error Handler.vi" Type="VI" URL="../Simulation/State Machines/Node 2 - Pump + UDP/Node 2 - Error Handler.vi"/>
				</Item>
				<Item Name="Node 1 - Error Handler.vi" Type="VI" URL="../Simulation/State Machines/Node 1 - Sensors + UDP/Node 1 - Error Handler.vi"/>
			</Item>
			<Item Name="Object Oriented" Type="Folder">
				<Item Name="Pump Class" Type="Folder">
					<Item Name="Pump.lvclass" Type="LVClass" URL="../Simulation/Object Oriented/Pump Class/Pump.lvclass"/>
				</Item>
				<Item Name="Sensor Class" Type="Folder">
					<Item Name="Sensor.lvclass" Type="LVClass" URL="../Simulation/Object Oriented/Sensor Class/Sensor.lvclass"/>
				</Item>
				<Item Name="Tank Class" Type="Folder">
					<Item Name="Tank.lvclass" Type="LVClass" URL="../Simulation/Object Oriented/Tank Class/Tank.lvclass"/>
				</Item>
				<Item Name="Main.vi" Type="VI" URL="../Simulation/Object Oriented/Main.vi"/>
			</Item>
			<Item Name="Task Oriented" Type="Folder">
				<Item Name="Sensor Persistence State.vi" Type="VI" URL="../Simulation/Task Oriented/Sensor Persistence State.vi"/>
				<Item Name="Water box.vi" Type="VI" URL="../Simulation/Task Oriented/Water box.vi"/>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="FormatTime String.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/ElapsedTimeBlock.llb/FormatTime String.vi"/>
				<Item Name="Set Busy.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/cursorutil.llb/Set Busy.vi"/>
				<Item Name="Set Cursor (Cursor ID).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/cursorutil.llb/Set Cursor (Cursor ID).vi"/>
				<Item Name="Set Cursor (Icon Pict).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/cursorutil.llb/Set Cursor (Icon Pict).vi"/>
				<Item Name="Set Cursor.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/cursorutil.llb/Set Cursor.vi"/>
				<Item Name="subElapsedTime.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/ElapsedTimeBlock.llb/subElapsedTime.vi"/>
				<Item Name="subTimeDelay.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/TimeDelayBlock.llb/subTimeDelay.vi"/>
				<Item Name="Unset Busy.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/cursorutil.llb/Unset Busy.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
