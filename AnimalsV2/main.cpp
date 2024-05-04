#include <iostream>
#include <string>
using namespace std;

class Herbivore {
    protected:
        int weight;
    public:
        Herbivore(): weight(100) {}
        virtual ~Herbivore() {}
        virtual void eatGrass() = 0;
        int getWeight() const { return weight; }
        void increaseWeight(int amount) { weight += amount; }
};

class Carnivore {
    protected:
        int power;
    public:
        Carnivore(): power(120) {}
        virtual ~Carnivore() {}
        virtual void eat(Herbivore* herbivore) = 0;
        int getPower() const { return power; }
        void increasePower(int amount) { power += amount; }
        void decreasePower(int amount) { power -= amount; }
};

class Wildebeest: public Herbivore {
    public:
        void eatGrass() override {
            cout << "Wildebeest is eating grass." << endl;
            increaseWeight(10);
        }
};

class Bison: public Herbivore {
    public:
        void eatGrass() override {
            cout << "Bison is eating grass." << endl;
            increaseWeight(10);
        }
};

class Lion: public Carnivore {
    public:
        void eat(Herbivore* herbivore) override {
            cout << "Lion is eating a herbivore." << endl;
            if (getPower() > herbivore->getWeight()) {
                increasePower(10);
                cout << "Lion gained 10 power points." << endl;
            }
            else {
                decreasePower(10);
                cout << "Lion lost 10 power points." << endl;
            }
        }
};

class Wolf: public Carnivore {
    public:
        void eat(Herbivore* herbivore) override {
            cout << "Wolf is eating a herbivore." << endl;
            if (getPower() > herbivore->getWeight()) {
                increasePower(10);
                cout << "Wolf gained 10 power points." << endl;
            }
            else {
                decreasePower(10);
                cout << "Wolf lost 10 power points." << endl;
            }
        }
};

class Elk: public Herbivore {
    public:
        void eatGrass() override {
            cout << "Elk is eating grass." << endl;
            increaseWeight(10);
        }
};

class Tiger: public Carnivore {
    public:
        void eat(Herbivore* herbivore) override {
            cout << "Tiger is eating a herbivore." << endl;
            if (getPower() > herbivore->getWeight()) {
                increasePower(10);
                cout << "Tiger gained 10 power points." << endl;
            }
            else {
                decreasePower(10);
                cout << "Tiger lost 10 power points." << endl;
            }
        }
};

class Continent {
    public:
        virtual Herbivore* createHerbivore() = 0;
        virtual Carnivore* createCarnivore() = 0;
        virtual ~Continent() {}
};

class Africa : public Continent {
    public:
        Herbivore* createHerbivore() override {
            Wildebeest* wildebeest = new Wildebeest();
            wildebeest->increaseWeight(20);
            return wildebeest;
        }

        Carnivore* createCarnivore() override {
            Lion* lion = new Lion();
            lion->increasePower(10);
            return lion;
        }

    ~Africa() {}
};

class NorthAmerica : public Continent {
    public:
        Herbivore* createHerbivore() override {
            Bison* bison = new Bison();
            bison->increaseWeight(30);
            return bison;
        }

        Carnivore* createCarnivore() override {
            Wolf* wolf = new Wolf();
            wolf->increasePower(5);
            return wolf;
        }

    ~NorthAmerica() {}
};

class Eurasia : public Continent {
    public:
        Herbivore* createHerbivore() override {
            return new Elk();
        }

        Carnivore* createCarnivore() override {
            return new Tiger();
        }

    ~Eurasia() {}
    };

class AnimalWorld {
    public:
        void herbivoresFeeding(Herbivore* herbivore) {
            cout << "Herbivore's weight before eating: " << herbivore->getWeight() << endl;
            herbivore->eatGrass();
            cout << "Herbivore's weight after eating: " << herbivore->getWeight() << endl;
        }
        void carnivoresHunting(Carnivore* carnivore, Herbivore* herbivore) {
            cout << "Carnivore's power before eating: " << carnivore->getPower() << endl;
            carnivore->eat(herbivore);
            cout << "Carnivore's power after eating: " << carnivore->getPower() << endl;
        }
};

int main() {
    AnimalWorld world;

    Continent* africa = new Africa();
    Herbivore* herbivoreAfrica = africa->createHerbivore();
    Carnivore* carnivoreAfrica = africa->createCarnivore();

    Continent* northAmerica = new NorthAmerica();
    Herbivore* herbivoreNorthAmerica = northAmerica->createHerbivore();
    Carnivore* carnivoreNorthAmerica = northAmerica->createCarnivore();

    Continent* eurasia = new Eurasia();
    Herbivore* herbivoreEurasia = eurasia->createHerbivore();
    Carnivore* carnivoreEurasia = eurasia->createCarnivore();

    cout << "Africa:" << endl;
    world.herbivoresFeeding(herbivoreAfrica);
    world.carnivoresHunting(carnivoreAfrica, herbivoreAfrica);

    cout << endl << "North America:" << endl;
    world.herbivoresFeeding(herbivoreNorthAmerica);
    world.carnivoresHunting(carnivoreNorthAmerica, herbivoreNorthAmerica);

    cout << endl << "Eurasia:" << endl;
    world.herbivoresFeeding(herbivoreEurasia);
    world.carnivoresHunting(carnivoreEurasia, herbivoreEurasia);

    return 0;
}
