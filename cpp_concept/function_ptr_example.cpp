// functionPtrExp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
#include <functional>

/*
Example of getting a function ptr from an API
std::function<bool(cacheline_tracker_entry&)> l2_module::get_process_state(cacheline_tracker_entry& entry)
{
    if (entry.is_read_flow_type())
    {
        return [this](cacheline_tracker_entry& entry) { return this->process_read_state(entry); };
    }
    else if (entry.is_write_flow_type())
    {
        return [this](cacheline_tracker_entry& entry) { return this->process_write_state(entry); };
    }
    else
    {
        CB_CHECK(false) << "Unsupported flow type";
    }

    return nullptr;
}

std::function<bool(cacheline_tracker_entry&)> process_state = get_process_state(entry);
*/

#define USE_LIST

class parent
{
public:
    parent() {}
    parent(uint64_t id): uid(id) {}

    void notification_from_child(bool val, uint32_t pos)
    {
        flag.at(pos) = val;
    }

    std::vector<bool> flag{ false, false };
    uint64_t uid{ UINT64_MAX };
};

class child
{
public:
    child() {}
    child(std::function<void(bool, uint32_t)> cb): notify_parent_command_entry_cb(std::move(cb)) {}

    std::function<void(bool, uint32_t)> notify_parent_command_entry_cb{};
    uint64_t pid{ UINT64_MAX };
};

int main()
{
    using namespace std::placeholders;
#ifdef USE_LIST
    std::list<parent> m_parent;
#else
    std::vector<parent> m_parent;
#endif // USE_LIST

    std::list<child> m_child_list;

    parent p1(5), p2(8);

    m_parent.push_back(p1);
    
    child c1_p1{ std::bind(&parent::notification_from_child, &m_parent.back(), _1, _2) };
    m_child_list.push_back(c1_p1);

    m_parent.push_back(p2);

    auto* val_back = &(m_parent.back());
    child c1_p2{ [val_back](bool val, uint32_t pos) { val_back->notification_from_child(val, pos); } };
    m_child_list.push_back(c1_p2);

    child c2_p2{ [val_back](bool val, uint32_t pos) { val_back->notification_from_child(val, pos); } };
    m_child_list.push_back(c2_p2);

    uint32_t i = 0;
    for (auto& child_entry : m_child_list)
    {
        if (i == 2)
            child_entry.notify_parent_command_entry_cb(true, 1);
        else
            child_entry.notify_parent_command_entry_cb(true, 0);
        i++;
    }

    i = 0;
    for (auto& parent_entry : m_parent)
    {
        if (i == 1)
        {
            std::cout << "parent_entry flag : " << parent_entry.flag.at(0) << "\n";
            std::cout << "parent_entry flag : " << parent_entry.flag.at(1) << "\n";
        }
        else
            std::cout << "parent_entry flag : " << parent_entry.flag.at(0) << "\n";
        i++;
    }
}

