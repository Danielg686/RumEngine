#include "LiveKeyInput.h"
#include "RumEngine.h"
#include <fstream>
#include <iostream>

LiveKeyInput::LiveKeyInput()
{
	remove("KeyOutput");
}

LiveKeyInput::~LiveKeyInput()
{
	//ofilename = "KeyOutput";

	//outputFile = fopen(ofilename, "w+");
	//auto itr1 = Keylist.begin();
	//auto itr2 = itr1;
	//DebugMsg::out("Size of logged key list %d\n", Keylist.size());
	//while (itr1 != Keylist.end())
	//{
	//	itr2 = itr1;
	//	itr1++;
	//	fwrite((*itr2), sizeof(KeyTracker), 1, outputFile);
	//	DebugMsg::out("Output frame %d, output key %d\n", (*itr2)->Cycle, (*itr2)->Key);
	//	delete (*itr2);
	//}
	//fclose(outputFile);
//
//	ofilename = "KeyOutput";
//
//	outputFile = fopen(ofilename, "w+");
//	auto itr1 = Keylist.begin();
//	auto itr2 = itr1;
//
//	int numInList = Keylist.size();
//
//	FileHeader* tempHeader = new FileHeader;
//	tempHeader->numberOfEntries = numInList;
//
//	//char* buffer = new char[(sizeof(KeyTracker)*numInList) + sizeof(FileHeader)];
//	char* buffer = (char*)malloc(((sizeof(KeyTracker)*numInList) + sizeof(FileHeader)));
////	int sizeOfBuffer = ((sizeof(KeyTracker)*numInList) + sizeof(FileHeader));
//	char* bufferStart = buffer;
//	memcpy(buffer, tempHeader, sizeof(FileHeader));
//	buffer += sizeof(FileHeader);
//	while (itr1 != Keylist.end())
//	{
//		memcpy(buffer, (*itr1), sizeof(KeyTracker));
//		buffer += sizeof(KeyTracker);
//		itr2 = itr1;
//		itr1++;
//		delete (*itr2);
//	}
//	fwrite(bufferStart, ((sizeof(KeyTracker)*numInList) + sizeof(FileHeader)), 1, outputFile);
//	fclose(outputFile);
//	
//	delete tempHeader;

	ofilename = "KeyOutput";

	std::ofstream myfile;
	myfile.open(ofilename, std::ios::out | std::ios::app | std::ios::binary);
	
	FileHeader* tempHeader = new FileHeader;
	tempHeader->numberOfEntries = Keylist.size();

	auto itr1 = Keylist.begin();
	auto itr2 = itr1;

	//char* buffer = new char[(sizeof(KeyTracker)*numInList) + sizeof(FileHeader)];
	char* buffer = (char*)malloc(((sizeof(KeyTracker)*Keylist.size()) + sizeof(FileHeader)));
//	int sizeOfBuffer = ((sizeof(KeyTracker)*numInList) + sizeof(FileHeader));
	char* bufferStart = buffer;
	memcpy(buffer, tempHeader, sizeof(FileHeader));
	buffer += sizeof(FileHeader);
	while (itr1 != Keylist.end())
	{
		memcpy(buffer, (*itr1), sizeof(KeyTracker));
		buffer += sizeof(KeyTracker);
		itr2 = itr1;
		itr1++;
		delete (*itr2);
	}
	//fwrite(bufferStart, ((sizeof(KeyTracker)*Keylist.size()) + sizeof(FileHeader)), 1, outputFile);
	myfile.write(bufferStart, ((sizeof(KeyTracker)*Keylist.size()) + sizeof(FileHeader)));
	//fclose(outputFile);
	myfile.close();
	delete tempHeader;
	
}

void LiveKeyInput::Update()
{
	Frame++;
}

bool LiveKeyInput::GetKeyState(AZUL_KEY key)
{
	bool KeyPressed = Keyboard::GetKeyState(key);
	//DebugMsg::out("Current frame %d\n", Frame);
	if (KeyPressed)
	{
		KeyTracker* temp = new KeyTracker;
		temp->Cycle = Frame;
		//DebugMsg::out("Current Frame %d\n", Frame);
		temp->Key = (int)key;
		Keylist.push_back(temp);
		//fwrite(temp, sizeof(KeyTracker), 1, outputFile);
		//DebugMsg::out("Input key stored\n");
	}
	return KeyPressed;
}

void LiveKeyInput::clear()
{

}
