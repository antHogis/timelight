#ifndef TIMELIGHT_CONFIG_HPP
#define TIMELIGHT_CONFIG_HPP

#include "toml.hpp"
#include <optional>
#include <ostream>
#include <string>

namespace App
{
	typedef toml::basic_value<toml::type_config> RawConfig;

	class Config
	{
	public:
		int foo = 30;

		Config();
		std::string to_string() const;

	private:
		std::optional<RawConfig> get_raw_config();
		void maybe_set_int(const RawConfig& data, const std::string& key, int* val);
	};

	std::ostream& operator<<(std::ostream& strm, const Config& config);

} // namespace App

#endif
