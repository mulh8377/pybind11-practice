//
// Created by mulh8377 on 5/31/22.
//

#ifndef CMAKE_EXAMPLE_LINKEDLIST_H
#define CMAKE_EXAMPLE_LINKEDLIST_H

#include <memory>

namespace container {

    class LinkedList {
        struct Node {
            int data;
            std::unique_ptr<Node> next;
        };
    private:
        std::unique_ptr<Node> container;
        uint64_t memory;
    public:
        LinkedList() = default;
        ~LinkedList() = default;

        void push(const int data) {
            container = std::unique_ptr<Node>(new Node{data, std::move(container)});
            memory++;
        }

        const int pop() {
            const int p = container->data;
            container = std::move(container->next);
            memory--;
            return p;
        }
    };

    namespace py = pybind11;

    static void bind_class_LinkedList(py::module_ &m) {

        py::class_<LinkedList>(m, "LinkedList")
                .def(py::init<>())
                .def("push", &LinkedList::push)
                .def("pop", &LinkedList::pop);
    }

} // container

#endif //CMAKE_EXAMPLE_LINKEDLIST_H
