#include "../source/mutavol"
#include <iostream>


int coin_test(const int argc, char *argv[]) {
    const auto result = mtv::Args::process_args(argc, argv);
    if (!result.args_processed) return -1;
    if (result.should_exit) return 0;
    mtv::Scanner::init_scanner(result.input);
    while(true) {
        const auto [lexem, type, pos] = mtv::Scanner::get();
        if(lexem.empty())break;
        std::wcout << lexem << " - " << type_str(type)<< L'\n';
    }
    return 0;
}

int test_parser(const int argc, char *argv[]) {
    const auto result = mtv::Args::process_args(argc, argv);
    if (!result.args_processed) return -1;
    if (result.should_exit) return 0;
    mtv::Scanner::init_scanner(result.input);

    mtv::Parser::init_parser().parse();

    return 0;
}