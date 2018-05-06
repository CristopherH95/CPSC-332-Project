#pragma once
#include <map>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <iomanip>

//TODO: Fix ordering on semantic actions. Alter exec_semantics for symbol table checks

struct symbol {
    std::string ident;
    unsigned int loc;
    std::string type;
};

struct instr {
    unsigned int addr;
    std::string oper;
    std::string oprnd;
};

class semantic {
    public:
        semantic();
        ~semantic();
        bool exists_symbol(const std::string& sym_to_check);
        bool add_symbol(const std::string& sym_to_add, const std::string& sym_type);
        void exec_semantics(const std::list<std::string>& semant);
        void gen_instr(const std::string& oper, const std::string& op_arg);
        void back_patch(const std::string& jmp_addr);
        void print_table(std::ostream& output_dest, bool err_out = true);
        void print_instructions(std::ostream& output_dest, bool err_out = true);
        void print_table();

    private:
        unsigned int pop_jmp_stack();

        std::map<std::string, symbol> sym_table;
        unsigned int memory_counter;
        std::stack<std::string> jmp_stack;
        unsigned int last_instr_loc;
        std::vector<instr> instructions;
};