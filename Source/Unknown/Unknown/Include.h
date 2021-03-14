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
#include <direct.h>
#include <optional>

using namespace std;

#include "Macro.h"
#include "ObjInclude.h"
#include "InterfaceInclude.h"
#include "LoadInclude.h"
#include "LogInclude.h"
#include "TimeManager.h"
#include "DummyManager.h"
#include "StringManager.h"
#include "DataTypeManager.h"
#include "HashManager.h"
#include "ItemInclude.h"