#pragma once

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <mutex>
#include <thread>
#include <string>
#include <string_view>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <map>
#include <typeinfo>
#include <unordered_map>

using namespace std;

#include "Macro.h"
#include "Obj.h"
#include "Loader.h"
#include "CSVLoader.h"
#include "ScriptLoadManager.h"
#include "Logger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "LogManager.h"
#include "TimeManager.h"
#include "DummyManager.h"
#include "StringManager.h"
#include "DataTypeManager.h"
#include "HashManager.h"
#include "ItemManager.h"