#include "KeyPlayback.h"
#include "RumEngine.h"

KeyPlayback::KeyPlayback()
{
	infilename = "KeyOutput";
	inputFile = fopen(infilename, "rb");
//	fseek(inputFile, 0, SEEK_END);
//	int size = ftell(inputFile);
//	fclose(inputFile);

	inputFile = fopen(infilename, "rb");
	FileHeader* temp1 = new FileHeader;
	fread(temp1, sizeof(FileHeader), 1, inputFile);
	int max = (int)temp1->numberOfEntries;
	int i = 0;
	//int t = size - sizeof(KeyTracker);
	while (i<max)
	{
		linecount++;
		KeyTracker* temp = new KeyTracker();
		fread(temp, sizeof(KeyTracker), 1, inputFile);
		Keylist.push_back(temp);
		DebugMsg::out("%d: Frame is %d, key is %d\n", linecount, temp->Cycle, temp->Key);
		//i += sizeof(KeyTracker);
		i++;
	}

	fclose(inputFile);
	DebugMsg::out("Input size of key list %d\n", Keylist.size());
	ListIterator = Keylist.begin();
}

KeyPlayback::~KeyPlayback()
{
	auto itr1 = Keylist.begin();
	auto itr2 = itr1;
	while (itr1 != Keylist.end())
	{
		itr2 = itr1;
		itr1++;
		delete (*itr2);
	}
}

void KeyPlayback::Update()
{
	//if (ListIterator == Keylist.end())
	//{
	//	return;
	//}
	FrameList.clear();
	
	//DebugMsg::out("Next input key Cycle %d\n", (*ListIterator)->Cycle);
	while (ListIterator != Keylist.end() && (*ListIterator)->Cycle <= Frame)
	{
		DebugMsg::out("Current Cycle %d\n", Frame);
		FrameList.push_back((*ListIterator));
		ListIterator++;
	}
	DebugMsg::out("There were %d key inputs\n", Keylist.size());
	Frame++;
}

bool KeyPlayback::GetKeyState(AZUL_KEY key)
{
	auto itr = FrameList.begin();
	while (itr != FrameList.end())
	{
		if ((int)(*itr)->Key == key)
		{
			itr++;
			return true;
		}
		itr++;
	}
	return false;
}

void KeyPlayback::clear()
{
}
