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
		const auto& opt_raw_config = get_raw_config();
		if (!opt_raw_config.has_value())
		{
			return;
		}
		const auto& data = opt_raw_config.value();

		if (data.contains("light-matrix") && data.at("light-matrix").is_table())
		{
			auto& light_matrix = data.at("light-matrix").as_table();

			set_opt_int(light_matrix, "rows", &light_matrix_.rows);
			set_opt_int(light_matrix, "cols", &light_matrix_.cols);
		}
	}

	const LightMatrixConfig Config::light_matrix() const
	{
		return light_matrix_;
	}

	std::string Config::to_string() const
	{
		std::stringstream ss;
		ss << "{ ";
		ss << "light_matrix: { rows: " << light_matrix_.rows
		   << ", cols: " << light_matrix_.cols << " }";
		ss << " }";
		return ss.str();
	}

	std::optional<RawConfig> Config::get_raw_config()
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

	void Config::set_opt_int(const RawConfig& data, const std::string& key, int* val)
	{
		if (data.contains(key) && data.at(key).is_integer())
		{
			*val = data.at(key).as_integer();
		}
	}

	std::ostream& operator<<(std::ostream& strm, const Config& config)
	{
		return strm << config.to_string();
	}

} // namespace App
