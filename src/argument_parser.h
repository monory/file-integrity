// Copyright 2015 Nikita Chudinov
#ifndef SRC_ARGUMENT_PARSER_H_
#define SRC_ARGUMENT_PARSER_H_

#include <string>

class ArgumentParser {
public:
    enum Mode: int { UNKNOWN, CHECK, STORE, HELP, START, KILL };
    ArgumentParser(int argc, char *argv[]);
    void PrintHelpMessage() const;
    Mode GetMode() const;
    std::string GetConfig() const;
private:
    const char *HELP_MESSAGE;
    ArgumentParser::Mode mode = UNKNOWN;
    std::string config;
};

#endif  // SRC_ARGUMENT_PARSER_H_
