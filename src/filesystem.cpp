#include "filesystem.hpp"

#include <iostream>

using namespace cs251;

filesystem::filesystem(const size_t sizeLimit)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::create_file(const size_t fileSize, const std::string& fileName)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::create_directory(const std::string& directoryName)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::create_link(const handle targetHandle, const std::string& linkName)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

bool filesystem::remove(const handle targetHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::create_file(const size_t fileSize, const std::string& fileName, const handle parentHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::create_directory(const std::string& directoryName, const handle parentHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::create_link(const handle targetHandle, const std::string& linkName, const handle parentHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

std::string filesystem::get_absolute_path(const handle targetHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

std::string filesystem::get_name(const handle targetHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

void filesystem::rename(const handle targetHandle, const std::string& newName)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

bool filesystem::exist(const handle targetHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::get_handle(const std::string& absolutePath)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::follow(const handle targetHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

handle filesystem::get_largest_file_handle() const
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

size_t filesystem::get_available_size() const
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

size_t filesystem::get_file_size(const handle targetHandle)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

size_t filesystem::get_file_size(const std::string& absolutePath)
{
	//TODO: Remove following line and add your implementation here.
  throw std::logic_error("filesystem::" + std::string(__FUNCTION__) + " not implemented");
}

std::string filesystem::print_layout()
{
	std::stringstream ss{};
	const auto& node = m_fileSystemNodes.ref_node(0);
	for (const auto& childHandle : node.peek_children_handles()) {
		print_traverse(0, ss, childHandle);
	}
	return ss.str();
}

void filesystem::print_traverse(const size_t level, std::stringstream& ss, const handle targetHandle)
{
	auto& node = m_fileSystemNodes.ref_node(targetHandle);
	std::stringstream indentation{};
	for (auto i = level; i > 0; i--)
	{
		indentation << "\t";
	}
	std::string type{};
	switch (node.ref_data().m_type)
	{
	case node_type::Directory: type = "[D]"; break;
	case node_type::Link: type = "[L]"; break;
	case node_type::File: type = "[F]"; break;
	}
	ss << indentation.str() << type << node.ref_data().m_name;
	if (node.ref_data().m_type == node_type::Link)
	{
		try {
			const auto path = get_absolute_path(follow(node.get_handle()));
			ss << " [->" << path << "]";
		}
		catch (const std::exception& e)
		{
			ss << " [invalid]";
		}
	}
	else if (node.ref_data().m_type == node_type::File)
	{
		ss << " (size = " << std::to_string(node.ref_data().m_fileSize) << ")";
	}
	ss << std::endl;
	for (const auto& childHandle : node.peek_children_handles())
	{
		print_traverse(level + 1, ss, childHandle);
	}
}
