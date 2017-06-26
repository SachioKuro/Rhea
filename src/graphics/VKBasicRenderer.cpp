#include "VKBasicRenderer.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>

#define CHECK(param)\
	if (param != VK_SUCCESS)\
		throw new std::runtime_error("Internal VK Error");

VKBasicRenderer::VKBasicRenderer() {
}


VKBasicRenderer::~VKBasicRenderer() {
	vkDestroyInstance(m_instance, nullptr);
}

const VkInstance& VKBasicRenderer::getInstance() const {
	return m_instance;
}

const VkPhysicalDevice& VKBasicRenderer::getPhysicalDevice() const {
	return m_physDevice;
}

bool VKBasicRenderer::Init() {
	createInstance();
	findPhysicalDevice();

	return true;
}

void VKBasicRenderer::createInstance() {
	VkApplicationInfo appInfo {};
	appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName   = "Rhea";
	appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
	appInfo.pEngineName        = "Rhea";
	appInfo.engineVersion      = VK_MAKE_VERSION(0, 0, 1);
	appInfo.apiVersion         = VK_API_VERSION_1_0;

	VkInstanceCreateInfo instanceCreateInfo {};
	instanceCreateInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pApplicationInfo        = &appInfo;
	instanceCreateInfo.enabledLayerCount       = 0;
	instanceCreateInfo.ppEnabledLayerNames     = VK_NULL_HANDLE;
	instanceCreateInfo.enabledExtensionCount   = 0;
	instanceCreateInfo.ppEnabledExtensionNames = VK_NULL_HANDLE;

	CHECK(vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance));
}

void VKBasicRenderer::findPhysicalDevice() {
	uint32_t nrPhysicalDevices = 0;
	vkEnumeratePhysicalDevices(m_instance, &nrPhysicalDevices, nullptr);
	std::vector<VkPhysicalDevice> physDevices(nrPhysicalDevices);
	vkEnumeratePhysicalDevices(m_instance, &nrPhysicalDevices, physDevices.data());

	VkPhysicalDeviceProperties physDeviceProperties;
	vkGetPhysicalDeviceProperties(physDevices[0], &physDeviceProperties);

	std::cout << physDeviceProperties.deviceName << std::endl;
}