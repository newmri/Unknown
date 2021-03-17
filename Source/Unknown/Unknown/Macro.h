#pragma once

#define DEFAULT_CONSTRUCTOR(CLASS)											\
	public:																	\
		CLASS() = default;													

#define ABSTRACT_OBJ(CLASS)													\
	DEFAULT_CONSTRUCTOR(CLASS)												\
	public:																	\
		virtual ~CLASS() = default;											\
																			\
	private:																\
		virtual void Init(void) = 0;											

#define OVERRIDE_OBJ(CLASS)													\
	public:																	\
		CLASS();															\
		virtual ~CLASS() override;											\
																			\
	private:																\
		virtual void Init(void) override;									

#define OVERRIDE_OBJ_DELETE_DEFAULT_CONSTRUCTOR(CLASS)						\
	public:																	\
		CLASS() = delete;													\
		virtual ~CLASS() override;											\
																			\
	private:																\
		virtual void Init(void) override;									

#define NO_COPY(CLASS)														\
	private:																\
		CLASS()				= default;										\
		CLASS(const CLASS&) = delete;										\
		CLASS(const CLASS&&) = delete;										\
		CLASS& operator = (const CLASS&) = delete;							\
		CLASS& operator = (const CLASS&&) = delete;		

#define DECLARE_SINGLETON(CLASS)											\
	NO_COPY(CLASS)															\
																			\
	public:																	\
		static CLASS& GetInstance(void);									\
																			\
		friend unique_ptr<CLASS> std::make_unique<CLASS>();					\
		friend unique_ptr<CLASS>::deleter_type;								\
																			\
																			\
	private:																\
		void Init(void);													\
																			\
	private:																\
		static unique_ptr<CLASS> instance;									\
		static once_flag onceFlag;					
														

#define IMPLEMENT_SINGLETON(CLASS)											\
	unique_ptr<CLASS> CLASS::instance;										\
	once_flag CLASS::onceFlag;												\
																			\
	CLASS& CLASS::GetInstance(void)											\
	{																		\
		call_once(CLASS::onceFlag, []()										\
		{																	\
			instance = make_unique<CLASS>();								\
			(*(instance.get())).Init();										\
		});																	\
																			\
		return *(instance.get());											\
	}												

#define GET_INSTANCE(CLASS) CLASS::GetInstance()	

#define SAFE_DELETE(ROWS, PTR)												\
	if(PTR) { if(1 < ROWS) delete[] PTR; else delete PTR; PTR = nullptr; }

#define SAFE_DELETE_DTOR(ROWS, RAW_PTR, DATA_TYPE, DATA_PTR)				\
	if(RAW_PTR)																\
	{																		\
		if(1 < ROWS)														\
		{																	\
			for (size_t i = 0; i < ROWS; ++i)								\
				DATA_PTR[i].~DATA_TYPE();									\
																			\
			delete[] RAW_PTR;												\
		}																	\
		else																\
		{																	\
			DATA_PTR->~DATA_TYPE();											\
			delete RAW_PTR;													\
		}																	\
		RAW_PTR = nullptr;													\
		DATA_PTR = nullptr;													\
	}

#define RAW_DATA_TO_HASH_MAP(ROWS, RAW_PTR, IN_TYPE, OUT, KEY)				\
	IN_TYPE* data = reinterpret_cast<IN_TYPE*>(RAW_PTR);					\
																			\
	for (size_t i = 0; i < ROWS; ++i)										\
	{																		\
		IN_TYPE info = data[i];												\
		OUT[data[i].KEY] = make_shared<IN_TYPE>(info);						\
	}																		\
	SAFE_DELETE_DTOR(ROWS, RAW_PTR, IN_TYPE, data);

#define CSV_LOAD_AND_TO_HAS_MAP(FILE_PATH, IN_TYPE, OUT, KEY)				\
	{																		\
		char* table = nullptr;												\
		size_t rows = CSV_LOAD.Load(FILE_PATH, table);						\
		RAW_DATA_TO_HASH_MAP(rows, table, IN_TYPE, OUT, KEY);				\
	}