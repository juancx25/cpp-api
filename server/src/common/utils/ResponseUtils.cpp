#include <crow.h>
#include <nlohmann/json.hpp>
#include <list>

namespace response {
    template <class responseObject>

    crow::response toJson(responseObject* data){
        if (data){
            crow::response r;
            r.add_header("Access-Control-Allow-Origin", "*");
            r.add_header("Content-Type", "application/json");
            r.write(nlohmann::json(*data).dump());
            delete data;
            return r;
        } else {
            return crow::response(404);
        }
    }
    template <class listResponseObject>
    crow::response listToJson(std::list<listResponseObject*> data){
        crow::response r;
        r.add_header("Access-Control-Allow-Origin", "*");
        r.add_header("Content-Type", "application/json");
        auto arr = nlohmann::json::array();
        for(auto it = data.begin(); it != data.end(); ++it){
            arr.push_back(**it);
            free(*it);
        }
        r.write(arr.dump());
        return r;
    }
}