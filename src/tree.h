//
// Created by mulh8377 on 5/31/22.
//

#ifndef CMAKE_EXAMPLE_TREE_H
#define CMAKE_EXAMPLE_TREE_H

#include <memory>

namespace container {

    class Tree {
        struct Node {
            int data;
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;
        };
    private:
        std::unique_ptr<Node> root;
        uint64_t size;

    public:
        Tree() = default;
        ~Tree() = default;

        void append(const int data) {
            /*container = std::unique_ptr<Node>(new Node{data, std::move(container)});
            memory++;
            */
        }

        const int find(const int data) {
            /*const int p = container->data;
            container = std::move(container->next);
            memory--;
            return p;
            */
            return 1;
        }
        void remove(const int data) {

        }
    };

    namespace py = pybind11;

    static void bind_class_tree(py::module_ &m) {

        py::class_<Tree>(m, "Tree")
                .def(py::init<>())
                .def("append", &Tree::append)
                .def("find", &Tree::find)
                .def("remove", &Tree::remove);
    }
} // container

#endif //CMAKE_EXAMPLE_LINKEDLIST_H