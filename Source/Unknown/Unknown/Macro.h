#pragma once

#define DEFAULT_CONSTRUCTOR(CLASS)					\
	public:											\
		CLASS() = default;							

#define ABSTRACT_OBJ(CLASS)							\
	DEFAULT_CONSTRUCTOR(CLASS)						\
	protected:										\
		virtual ~CLASS() = default;					\
	public:											\
		virtual void Init(void) = 0;					

#define OVERRIDE_OBJ(CLASS)							\
	DEFAULT_CONSTRUCTOR(CLASS)						\
	protected:										\
		virtual ~CLASS() override;					\
	public:											\
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
	private:										\
		static unique_ptr<CLASS> instance;			\
		static once_flag onceFlag;					\
													\
	public:											\
		static CLASS& GetInstance(void);									

#define IMPLEMENT_SINGLETON(CLASS)					\
	unique_ptr<CLASS> CLASS::instance;				\
	once_flag CLASS::onceFlag;						\
													\
	CLASS& CLASS::GetInstance(void)					\
	{												\
		call_once(CLASS::onceFlag, []()				\
		{											\
			instance.reset(new CLASS);				\
		});											\
													\
		return *(instance.get());					\
	}												

#define GET_INSTANCE(CLASS) CLASS::GetInstance()	