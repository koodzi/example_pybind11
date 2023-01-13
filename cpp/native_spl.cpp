#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace pybind11::literals;

int add(int i, int j) {
    return i + j;
}

int sub(int i, int j) {
    return i - j;
}

int blah(int i = 1, int j = 2) {
    return i - j;
}

struct Pet {
public:
    Pet(const std::string &name) : name(name) { }

    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    void setColor(const std::string &color_) { color = color_; }
    const std::string &getColor() const { return color; }

    std::string name;
    int age;

private:
    std::string color;
};

PYBIND11_MODULE(native_spl, m) {
    m.doc() = "pybind11 native_spl plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers", py::arg("i"), py::arg("j"));
    m.def("sub", &sub, "A function that subtracts two numbers", "i"_a, "j"_a);
    m.def("blah", &blah, "A function that blah two numbers", "i"_a = 1, "j"_a = 2);

    m.attr("the_answer") = 42;

    py::object world = py::cast("World");
    m.attr("hello") = world;

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def_readwrite("age", &Pet::age) // public fields
        //.def_readwrite("color", &Pet::getColor, &Pet::setColor) // private filed behind setters

    ;
}

