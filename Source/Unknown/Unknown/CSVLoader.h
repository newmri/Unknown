#pragma once

class CSVLoader : public Loader
{
	OVERRIDE_OBJ(CSVLoader)

private:
	virtual void Load(void) override;

public:
	virtual LOAD_DATA Load(string_view filePath) override;

private:
	fstream fileStream;
	stringstream stringStream;
};