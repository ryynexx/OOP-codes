#include <iostream>
using namespace std;

// Forward declaration of Region class so it can be used in Animal class
class Region;

// Base class for all organisms
class Organism 
{
protected:
    string name; // Name of the organism

public:
    Organism(const string& n) : name(n) {}

    // These are pure virtual functions, meaning all derived classes must define them
    virtual void live() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void move() = 0;
    virtual void type() = 0;

    // Get name of organism
    string getName() const 
    { 
        return name; 
    }

    virtual ~Organism() {} // Virtual destructor so derived objects are deleted correctly
};

// Derived class: Plant is a type of Organism
class Plant : public Organism {
public:
    Plant(const string& n) : Organism(n) {}

    // Implementing the virtual functions
    void live() 
    {
        cout << name << " is photosynthesizing.\n";
    }

    void eat() 
    {
        cout << name << " absorbs sunlight and nutrients.\n";
    }

    void sleep() 
    {
        cout << name << " is sleeping.\n";
    }

    void move() 
    {
        cout << name << " does not move.\n";
    }

    void type() 
    {
        cout << name << " is a Plant.\n";
    }
};

// Animal also inherits from Organism
class Animal : public Organism 
{
protected:
    Region* region; // Pointer to the region the animal belongs to

public:
    Animal(const string& n, Region* r) : Organism(n), region(r) {}

    void move() 
    {
        cout << name << " is moving.\n";
    }

    void sleep() 
    {
        cout << name << " is sleeping.\n";
    }
};

// Herbivore is a type of Animal
class Herbivore : public Animal 
{
public:
    Herbivore(const string& n, Region* r) : Animal(n, r) {}

    void live() 
    {
        cout << name << " is alive.\n";
    }

    void eat() 
    {
        cout << name << " is eating plants.\n";
    }

    void type() 
    {
        cout << name << " is a Herbivore.\n";
    }
};

// Carnivore is another type of Animal that hunts other animals
class Carnivore : public Animal 
{
private:
    Animal* prey; // This carnivore's target (association)

public:
    Carnivore(const string& n, Region* r) : Animal(n, r), prey(nullptr) {}

    void setPrey(Animal* p) 
    {
        prey = p;
    }

    void live() 
    {
        cout << name << " is hunting.\n";
        if (prey) 
        {
            cout << name << " is targeting " << prey->getName() <<endl;
        }
    }

    void eat() 
    {
        if (prey) 
        {
            cout << name << " eats " << prey->getName() <<endl;
        } 
        else 
        {
            cout << name << " finds no prey.\n";
        }
    }

    void type() 
    {
        cout << name << " is a Carnivore.\n";
    }
};

// A region is a collection of organisms (composition)
class Region 
{
private:
    string name;
    Organism* organisms[10]; // Stores up to 10 organisms
    int count; // Number of organisms added

public:
    Region(const string& n) : name(n), count(0) {}

    ~Region() 
    {
        // Delete all organisms when the region is destroyed
        for (int i = 0; i < count; i++) 
        {
            delete organisms[i];
        }
    }

    void addOrganism(Organism* org) 
    {
        if (count < 10) 
        {
            organisms[count++] = org;
        } 
        else 
        {
            cout << "Region is full, can't add more organisms.\n";
        }
    }

    void display() 
    {
        cout << "\n-- Region: " << name << " --\n\n";
        for (int i = 0; i < count; i++) 
        {
            organisms[i]->live(); // Calls appropriate function using polymorphism
        }
    }

    Organism* getDominantSpecies() 
    {
        Organism* dominant = nullptr;
        size_t maxLen = 0;

        for (int i = 0; i < count; i++) 
        {
            if (organisms[i]->getName().length() > maxLen) 
            {
                dominant = organisms[i];
                maxLen = organisms[i]->getName().length();
            }
        }

        return dominant;
    }
};

// World class that holds multiple regions (composition)
class World 
{
private:
    Region* regions[5]; // Max 5 regions
    int count;

public:
    World() : count(0) {}

    ~World() 
    {
        for (int i = 0; i < count; i++) 
        {
            delete regions[i];
        }
    }

    void addRegion(Region* r) 
    {
        if (count < 5) 
        {
            regions[count++] = r;
        } 
        else 
        {
            cout << "World is full, can't add more regions.\n";
        }
    }

    void display() 
    {
        for (int i = 0; i < count; i++) 
        {
            regions[i]->display();
        }
    }
};


int main() 
{
    World world;

    // Create a region
    Region* forest = new Region("Rain Forest");

    // Create some organisms
    Plant* p1 = new Plant("Fern");
    Herbivore* h1 = new Herbivore("Deer", forest);
    Carnivore* c1 = new Carnivore("Tiger", forest);

    // Set prey for the carnivore
    c1->setPrey(h1);

    // Add organisms to the region
    forest->addOrganism(p1);
    forest->addOrganism(h1);
    forest->addOrganism(c1);

    // Add the region to the world
    world.addRegion(forest);


        world.display();
    
    // Show the dominant species
    cout << "\nDominant species in forest: ";
    Organism* dom = forest->getDominantSpecies();
    if (dom) 
    {
        dom->type();
    }

    return 0;
}
