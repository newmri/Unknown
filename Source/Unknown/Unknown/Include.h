#pragma once

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

using namespace std;

#include "Macro.h"
#include "Obj.h"
#include "Loader.h"
#include "CSVLoader.h"
#include "ScriptLoadManager.h"
#include "Logger.h"
#include "ConsoleLogger.h"
#include "LogManager.h"
#include "TimeManager.h"
#include "DummyManager.h"
#include "StringManager.h"
#include "DataTypeManager.h"
#include "HashManager.h"