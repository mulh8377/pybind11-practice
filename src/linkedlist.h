//
// Created by mulh8377 on 5/31/22.
//

#ifndef CMAKE_EXAMPLE_LINKEDLIST_H
#define CMAKE_EXAMPLE_LINKEDLIST_H

#include <pybind11/pybind11.h>
#include <fplus/fplus.hpp>
#include <memory>

#include <sstream>
#include <algorithm>


namespace detail {

    namespace py = pybind11;
    namespace f = fplus;

    template<typename Vector, typename Class_>
    void list_modifiers(Class_ &c1) {

        c1.def("clear", [](Vector &v) { v.clear(); });
    }
    template<typename Vector, typename Class_>
    void list_accessors(Class_ &c1) {
        c1.def("get", [](Vector &v) { return fplus::numbers(1, 30); } );
    }


namespace container {

    template <typename Vector, typename holder_type = std::unique_ptr<Vector>, typename... Args>
    py::class_<Vector, holder_type> bind_list(pybind11::handle scope, std::string const &name, Args&&...args) {
        using Class_ = py::class_<Vector, holder_type>;

        using vtype = typename Vector::value_type;
        auto *vtype_info = pybind11::detail::get_type_info(typeid(vtype));
        bool local = !vtype_info || vtype_info->module_local;


        Class_ c1(scope, name.c_str(), pybind11::module_local(local), std::forward<Args>(args)...);

        c1.def(py::init<>());

        detail::list_modifiers<Vector, Class_>(c1);
        detail::list_accessors<Vector, Class_>(c1);

        c1.def("__len__", &Vector::size);
        c1.def("capacity", &Vector::capacity);
        c1.def("max_size",      &Vector::max_size,      "returns the maximum possible number of elements");

        //Class_ c1(name.c_str());



        return c1;

    }

    } // container
}
#endif //CMAKE_EXAMPLE_LINKEDLIST_H
