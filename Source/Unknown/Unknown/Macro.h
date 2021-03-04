#pragma once

#define DEFAULT_CONSTRUCTOR(CLASS)					\
	public:											\
		CLASS() = default;							

#define ABSTRACT_OBJ(CLASS)							\
	DEFAULT_CONSTRUCTOR(CLASS)						\
	public:											\
		virtual ~CLASS() = default;					\
													\
	private:										\
		virtual void Init(void) = 0;					

#define OVERRIDE_OBJ(CLASS)							\
	public:											\
		CLASS();									\
		virtual ~CLASS() override;					\
													\
	private:										\
		virtual void Init(void) override;			

#define NO_COPY(CLASS)								\
	private:										\
		CLASS()				= default;				\
		CLASS(const CLASS&) = delete;				\
		CLASS(const CLASS&&) = delete;				\
		CLASS& operator = (const CLASS&) = delete;	\
		CLASS& operator = (const CLASS&&) = delete;		

#define DECLARE_SINGLETON(CLASS)					\
	NO_COPY(CLASS)									\
													\
	public:											\
		static CLASS& GetInstance(void);			\
													\
	private:										\
		void Init(void);							\
													\
	private:										\
		static unique_ptr<CLASS> instance;			\
		static once_flag onceFlag;					

#define IMPLEMENT_SINGLETON(CLASS)					\
	unique_ptr<CLASS> CLASS::instance;				\
	once_flag CLASS::onceFlag;						\
													\
	CLASS& CLASS::GetInstance(void)					\
	{												\
		call_once(CLASS::onceFlag, []()				\
		{											\
			instance.reset(new CLASS);				\
			(*(instance.get())).Init();				\
		});											\
													\
		return *(instance.get());					\
	}												

#define GET_INSTANCE(CLASS) CLASS::GetInstance()	

#define GET_INT_NAME "int"
#define GET_SIZE_T_NAME "size_t"
#define GET_STRING_NAME "string"

#define SIZE_OF_INT sizeof(int)
#define SIZE_OF_SIZE_T sizeof(size_t)
#define SIZE_OF_STRING sizeof(string)

#define CHAR_P_TO_INT_REF *(int*)
#define CHAR_P_TO_SIZE_T_REF *(size_t*)
#define CHAR_P_TO_STRING_REF *(string*)