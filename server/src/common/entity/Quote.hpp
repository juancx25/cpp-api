#include "string"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace quote {
    class Quote{
        public:
            std::string id;
            std::string text;
            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Quote, id, text)
    };
}