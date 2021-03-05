#pragma once

class CSVLoader : public Loader
{
	OVERRIDE_OBJ(CSVLoader)

private:
	virtual void Load(char* out) override;

public:
	virtual void Load(string_view filePath, char* out) override;

private:
	fstream fileStream;
};