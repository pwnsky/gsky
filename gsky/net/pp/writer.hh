#pragma once
#include <map>
#include <string>

#include <gsky/gsky.hh>
#include <gsky/util/vessel.hh>
#include <gsky/util/json.hh>

namespace gsky {
namespace net {
namespace pp {

class writer {
    using json = gsky::util::json;
public:
    explicit writer(); // uid for deal with offline
    ~writer();
    void set_send_data_handler(std::function<void(const std::string &)> h);
    void set_push_data_handler(std::function<void(const std::string &)> h);
    void set_route_handler(std::function<void(unsigned char [])> h);
    bool send_data(const std::string &content); // 同步发送数据, 一次请求只能发送一次
    bool push_data(const std::string &content); // 异步发送数据, 一次请求可以发送多次
    bool send_json(gsky::util::json &json_obj);
    bool push_json(gsky::util::json &json_obj);
    void clean_handler();
    void set_route(unsigned char route []);

private:
    std::string json_to_string(json &json_obj);
    std::function<void(const std::string &)> send_data_handler_ = nullptr;
    std::function<void(const std::string &)> push_data_handler_ = nullptr;
    std::function<void(unsigned char [])> set_route_handler_ = nullptr;
};

}
}
}
