#include <string>
#include <iostream>
#include <fmt/core.h>
#include <range/v3/view/chunk_by.hpp>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/range/primitives.hpp>

namespace vw = ranges::view;

int main()
{
    // utf8字节流
    std::u8string str = u8"我是瓜王mel1，没瓜吃就喷人";
    std::cout<<"字节数: "<<str.length()<<"\n";
    for(auto c: str) {
        std::cout<< fmt::format("{0:08b}", char(c)) << " ";
    }
    std::cout<<"\n\n";

    // 切分成字符流
    auto fun = [](auto c1, auto c2) { return (0b11000000 & char(c2)) == 0b10000000; };
    auto v = str | vw::chunk_by(fun); // 切分完毕

    // 统计字符数
    std::cout<<"字符数："<<ranges::distance(v)<<"\n";
    for(auto vv: v) {
        for(auto c: vv) {
            std::cout<<fmt::format("{0:08b} ", char(c));
        }
        std::cout<<"\n";
    }
    std::cout<<"\n\n";

    // 获取第N个字符
    std::cout<<"第三个字符的字节串：";
    {
        auto c3 = v | vw::drop(2) | vw::take(1);
        for(auto c: c3) {
            for(auto cc: c) {
                std::cout << fmt::format("{0:08b}", char(cc)) << " ";
            }
        }
    }
    std::cout<<"\n";
    std::cout<<"第三个字符的字符串：";
    {
        auto c3 = v | vw::drop(2) | vw::take(1);
        for(auto c: c3) {
            std::string s;
            for(auto cc: c) {
                s.push_back(cc);
            }
            std::cout<<s;
        }
    }
    std::cout<<"\n";
}