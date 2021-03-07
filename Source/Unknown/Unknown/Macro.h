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

#define SAFE_DELETE(NUM, PTR)												\
	if(PTR) { if(1 < NUM) delete[] PTR; else delete PTR; PTR = nullptr; }

#define SAFE_DELETE_DTOR(NUM, PTR, CLASS_PTR, CLASS)						\
	if(PTR)																	\
	{																		\
		if(1 < NUM)															\
		{																	\
			for (size_t i = 0; i < NUM; ++i)								\
				CLASS_PTR[i].~CLASS();										\
																			\
			delete[] PTR;													\
		}																	\
		else																\
		{																	\
			CLASS_PTR->~CLASS();											\
			delete PTR;														\
		}																	\
		PTR = nullptr;														\
	}