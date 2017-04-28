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

class Color {
public:
	virtual void fill() = 0;
};

class Red: public Color {
public:
	void fill() {
		std::cout << "fill with red color\n";
	}
};

class Green: public Color {
public:
    void fill() {
        std::cout << "fill with green color\n";
    }
};

class AbstractFactory {
public:
    virtual std::shared_ptr<Shap> produceShap(std::string type) = 0;
    virtual std::shared_ptr<Color> produceColor(std::string type) = 0;
};

class ColorFactory: public AbstractFactory {
public:
    std::shared_ptr<Shap> produceShap(std::string type) {
        throw std::runtime_error("not produce shap.");
    }

    std::shared_ptr<Color> produceColor(std::string type) {
        if (type == "Red") {
            return std::make_shared<Red>();
        } else if (type == "Green") {
            return std::make_shared<Green>();
        } else {
            return nullptr;
        }
    }
};

class ShapFactory: public AbstractFactory {
public:
    std::shared_ptr<Shap> produceShap(std::string type) {
        if (type == "Cir") {
            return std::make_shared<Circle>();
        } else if (type == "Rec") {
            return std::make_shared<Rectangle>();
        } else {
            return nullptr;
        }
    }

    std::shared_ptr<Color> produceColor(std::string type) {
        throw std::runtime_error("not produce color.");
    }
};

class FactoryProducer {
public:
    std::shared_ptr<AbstractFactory> getFactory(std::string type) {
        if (type == "Shap") {
            return std::make_shared<ShapFactory>();
        } else if (type == "Color") {
            return std::make_shared<ColorFactory>();
        } else {
            throw std::runtime_error("no this type factory.");
        }

    }
};

int main(int argc, char const *argv[]) {
    FactoryProducer pro;
    try {
        auto sfct = pro.getFactory("Shap");
        auto cfct = pro.getFactory("Color");

        auto cshap = sfct->produceShap("Cir");
        auto rcolor = cfct->produceColor("Red");

        cshap->draw();
        rcolor->fill();

        auto rshap = sfct->produceShap("Rec");
        auto gcolor = cfct->produceColor("Green");

       rshap->draw();
       gcolor->fill();        
    } catch (...) {
    }
    return 0;
}
