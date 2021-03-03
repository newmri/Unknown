#pragma once

class CSVLoader : public Loader
{
	OVERRIDE_OBJ(CSVLoader)

private:
	virtual void Load(void) override;

public:
	virtual void Load(string_view filePath) override;

private:
	fstream fileStream;
};