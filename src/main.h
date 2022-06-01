//
// Created by mulh8377 on 5/31/22.
//

#ifndef CMAKE_EXAMPLE_HAND_H
#define CMAKE_EXAMPLE_HAND_H

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

#include "linkedlist.h"
#include "map.h"
#include "tree.h"

PYBIND11_MAKE_OPAQUE(std::vector<int>);

namespace container {

    namespace py = pybind11;

    void bind_linkedlist(py::module_ &m) {
        detail::container::bind_list<std::vector<int>>(m, "LinkedList");
    }
    void bind_tree(py::module_& m) {
        bind_class_tree(m);

    }

    void bind_map(py::module_& m) {

    }

}
#endif //CMAKE_EXAMPLE_HAND_H
