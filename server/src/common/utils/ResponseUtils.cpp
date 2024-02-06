#include <crow.h>
#include <nlohmann/json.hpp>
#include <list>

namespace response {
    template <class responseObject>

    crow::response toJson(responseObject data){
        crow::response r;
        r.add_header("Access-Control-Allow-Origin", "*");
        r.add_header("Content-Type", "application/json");
        r.write(nlohmann::json(data).dump());
        return r;
    }
    template <class T>
    crow::response listToJson(std::list<T*> data){
        crow::response r;
        r.add_header("Access-Control-Allow-Origin", "*");
        r.add_header("Content-Type", "application/json");
        auto arr = nlohmann::json::array();
        for(auto it = data.begin(); it != data.end(); ++it){
            arr.push_back(**it);
        }
        r.write(arr.dump());
        return r;
    }
}