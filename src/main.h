//
// Created by mulh8377 on 5/31/22.
//

#ifndef CMAKE_EXAMPLE_HAND_H
#define CMAKE_EXAMPLE_HAND_H

#include <pybind11/pybind11.h>

#include "linkedlist.h"
#include "map.h"
#include "tree.h"

namespace container {

    namespace py = pybind11;

    void bind_linkedlist(py::module_ &m) {
        bind_class_LinkedList(m);
    }
    void bind_tree(py::module_& m) {
        bind_class_tree(m);

    }

    void bind_map(py::module_& m) {

    }

}
#endif //CMAKE_EXAMPLE_HAND_H
