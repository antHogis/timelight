#include "config.hpp"
#include "toml.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

namespace App
{
	Config::Config()
	{
		const auto& opt_raw_config = getRawConfig();
		if (!opt_raw_config.has_value())
		{
			return;
		}
		const auto& data = opt_raw_config.value();

		maybe_set_int(data, "foo", &foo);
	}

	std::string Config::toString() const
	{
		std::stringstream ss;
		ss << "{ foo: " << foo << " }";
		return ss.str();
	}

	std::optional<RawConfig> Config::getRawConfig()
	{
		try
		{
			return toml::parse("timelight.toml", toml::spec::v(1, 1, 0));
		}
		catch (const toml::file_io_error& e)
		{
			std::cout << "Could not find config file, using defaults." << std::endl;
			return std::nullopt;
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught standard exception when reading config: " << e.what()
					  << std::endl;
			throw e;
		}
		catch (...)
		{
			std::cout << "Caught non-standard exception when reading config: "
					  << std::endl;

			throw std::runtime_error("unknown failure");
		}
	}

	void Config::maybe_set_int(const RawConfig& data, const std::string& key, int* val)
	{
		if (data.contains(key) && data.at(key).is_integer())
		{
			*val = data.at(key).as_integer();
		}
	}

	std::ostream& operator<<(std::ostream& strm, const Config& config)
	{
		return strm << config.toString();
	}

} // namespace App
