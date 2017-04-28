#include <iostream>
#include <memory>
#include <string>

class Shap {
public:
    virtual void draw() = 0;
};

class Circle: public Shap {
public:
    void draw() {
        std::cout << "draw a circle\n";
    }
};

class Rectangle: public Shap {
public:
    void draw() {
        std::cout << "draw a Rectangle\n";
    }
};

class Factory {
public:
    Factory() {}

    std::shared_ptr<Shap> produce(std::string type) {
        if (type == "Cir") {
            return std::make_shared<Circle>();
        } else if (type == "Rec") {
            return std::make_shared<Rectangle>();
        } else {
            return nullptr;
        }
    }

private:

};

int main(int argc, char const *argv[]) {
    Factory fct;
    auto shap = fct.produce("Cir");
    if (shap != nullptr) {
        shap->draw();
    }

    auto shap1 = fct.produce("Rec");
    if (shap1 != nullptr) {
        shap1->draw();
    }
    return 0;
}
