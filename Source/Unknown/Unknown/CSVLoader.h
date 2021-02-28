#pragma once

class CSVLoader : public Loader
{
	OVERRIDE_OBJ(CSVLoader)

public:
	void Load(string_view filePath) override;
};