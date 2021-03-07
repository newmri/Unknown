#pragma once

class CSVLoader : public Loader
{
	OVERRIDE_OBJ(CSVLoader)

private:
	virtual void PreLoad(string_view filePath, char*& out) override;
	virtual void Load(char*& out) override;

public:
	virtual size_t Load(string_view filePath, char*& out) override;
};