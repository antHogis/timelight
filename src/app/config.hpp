#ifndef TIMELIGHT_CONFIG_HPP
#define TIMELIGHT_CONFIG_HPP

#include "toml.hpp"
#include <optional>
#include <ostream>
#include <string>

namespace App
{
	typedef toml::basic_value<toml::type_config> RawConfig;

	struct LightMatrixConfig {
		int rows = 1;
		int cols = 10;
	};

	class Config
	{
	public:
		Config();
		std::string to_string() const;
		const LightMatrixConfig light_matrix() const;

	private:
		LightMatrixConfig light_matrix_;

		std::optional<RawConfig> get_raw_config();
		void set_opt_int(const RawConfig& data, const std::string& key, int* val);
	};

	std::ostream& operator<<(std::ostream& strm, const Config& config);

} // namespace App

#endif
