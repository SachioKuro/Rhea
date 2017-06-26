#pragma once

class Renderer
{
public:
	virtual ~Renderer() {};

	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finish() = 0;
};

