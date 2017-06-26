#pragma once
#include "Renderer.hpp"
#include <vulkan/vulkan.h>

class VKBasicRenderer :
	public Renderer
{
public:
	VKBasicRenderer();
	virtual ~VKBasicRenderer();

	virtual bool Init();
	virtual void Update() {};
	virtual void Draw() {};
	virtual void Finish() {};

	const VkInstance& getInstance() const;
	const VkPhysicalDevice& getPhysicalDevice() const;
private:
	VkInstance m_instance;
	VkPhysicalDevice m_physDevice;

	void createInstance();
	void findPhysicalDevice();
};

