#pragma once

class g_modeldata
{
public:
	const char* GetModelName(const model_t* model);
	studiohdr_t* GetStudioModel(const model_t* mod);
};
