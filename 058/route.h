#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <functional>

class Node
{
    using Node_ptr = Node *;

private:
    std::string m_name;
    std::vector<std::pair<Node_ptr, size_t>> m_dest;

public:
    Node(/* args */){};
    Node(std::string const &_name)
        : m_name(_name){};
    Node(std::string const &_name, std::vector<std::pair<Node_ptr, size_t>> _dest)
        : m_name(_name), m_dest(_dest){};
    ~Node(){};

    std::string name() { return m_name; }
    std::vector<Node_ptr> dest()
    {
        std::vector<Node_ptr> res;
        for (auto &&dest : m_dest)
            res.push_back(dest.first);

        return res;
    }

    std::size_t weight;
};

class Route
{
    using Node_ptr = Node *;

    std::map<Node_ptr, std::vector<std::pair<Node_ptr, size_t>>> adjacent_nodes;

    std::vector<Node_ptr> nodes;

    void clear_nodes()
    {
        for (auto &&node : nodes)
        {
            node->weight = std::numeric_limits<std::size_t>::max();
        }
    }

public:
    ~Route()
    {
        for (auto &&node : nodes)
        {
            delete node;
        }
    }
    void add_node(std::string const &src, std::string const &dest, size_t const weight) // "A", "B", 7
    {
        if (std::find_if(nodes.begin(), nodes.end(), [&](Node_ptr node)
                         { return node->name() == src; }) == nodes.end())
            nodes.push_back(new Node(src));

        if (std::find_if(nodes.begin(), nodes.end(), [&](Node_ptr node)
                         { return node->name() == dest; }) == nodes.end())
            nodes.push_back(new Node(dest));

        auto src_itr = std::find_if(nodes.begin(), nodes.end(), [&](Node_ptr node)
                                    { return node->name() == src; });

        auto dest_itr = std::find_if(nodes.begin(), nodes.end(), [&](Node_ptr node)
                                     { return node->name() == dest; });

        adjacent_nodes[*src_itr].push_back(std::make_pair(*dest_itr, weight));
        adjacent_nodes[*dest_itr].push_back(std::make_pair(*src_itr, weight));
    }

    void dijkstra(std::string const &start)
    {
        //0. ?????????
        clear_nodes();

        // 1. ?????????????????????
        std::vector<Node_ptr> start_set;

        // 1.5. ?????????weight???0
        auto start_itr = std::find_if(nodes.begin(), nodes.end(), [&](Node_ptr node)
                                      { 
                                          if(node->name() == start) 
                                          {
                                              node->weight = 0;
                                              return true;
                                          }
                                          return false; });

        start_set.push_back(*start_itr);

        // 4. ???????????? == ????????????????????????????????????2??????????????????
        while (start_set.size() != nodes.size())
        {
            std::priority_queue<Node_ptr,
                                std::vector<Node_ptr>,
                                std::function<bool(const Node_ptr, const Node_ptr)>>
            que([&](const Node_ptr node1, const Node_ptr node2) -> bool
                { return node1->weight > node2->weight; });

            // 2. ?????????????????????????????????????????????????????????????????????????????????????????????????????????
            // ???????????????????????????????????????????????????
            // source -> target???Map??????target -> source???Map????????????
            for (auto &&start_node : start_set)
            {

                for (auto &&target : adjacent_nodes[start_node])
                {
                    // ???????????????????????????????????????????????????????????????????????????
                    if (std::find(start_set.begin(), start_set.end(), target.first) != start_set.end())
                        continue;

                    // ???????????????????????????????????????????????????????????????
                    if (target.first->weight > (target.second + start_node->weight))
                        target.first->weight = target.second + start_node->weight;

                    que.push(target.first);
                }
            }

            // 3. 3????????????????????????????????????????????????
            start_set.push_back(que.top());
        }
    }

    std::vector<Node_ptr> shortest_path(std::string const &start, std::string const &goal)
    {
        this->dijkstra(start);

        // 5. ?????????????????????????????????????????????????????????return
        std::vector<Node_ptr> res;
        Node_ptr on_path = *std::find_if(nodes.begin(), nodes.end(), [&](Node_ptr node)
                                         { return node->name() == goal; });

        res.insert(res.begin(), on_path);
        while (on_path->name() != start)
        {
            on_path = (*std::find_if(adjacent_nodes[on_path].begin(), adjacent_nodes[on_path].end(), [&](auto target_pair)
                                     {
                auto target = target_pair.first;
                auto cost = target_pair.second;
                return (target->weight + cost) == on_path->weight; }))
                          .first;

            res.insert(res.begin(), on_path);
        }

        return res;
    }
};
