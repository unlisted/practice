#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog {
public:
  void Woof() {
      cout << _size << endl;
      cout << _color << endl;
    //cout << "I am a size " << _size << " dog with " << _color << " fur." << endl;
  }
  void SetSize(int s) { _size = s; }
  void SetColor(string c) { _color = c; }

private:
  int _size = 0;
  string _color = "";
};

// abstract builder class holds constructed object in unique_ptr
// returns bare pointer to caller
class DogBuilder {
public:
    virtual ~DogBuilder() {};
    void CreateNewDog() {
        cout << "creating new dog." << endl;
        _dog = make_unique<Dog>();
    };
    Dog *GetDog() { _dog.release(); }
    virtual void BuildDogSize() = 0;
    virtual void BuildDogColor() = 0;
protected:
    unique_ptr<Dog> _dog;
};    

class SchnauzerDogBuilder : public DogBuilder {
public:
    virtual void BuildDogSize() final { _dog->SetSize(10); }
    virtual void BuildDogColor() final { _dog->SetColor("RED"); }
};

class DogMaker {
public:
    DogMaker(DogBuilder *b) : _builder(b) {}
    void MakeDog() {
        _builder->CreateNewDog();
        _builder->BuildDogSize();
        _builder->BuildDogColor();
    }

    // pointer is release, so _dog should be nullptr. not good.
    void Speak() {
        Dog *dog = _builder->GetDog();
        if (dog)
            dog->Woof();
        else {
            MakeDog();
            Dog *dog = _builder->GetDog();
            dog->Woof();
        }
    }

private:
    DogBuilder * _builder;
};
int main(int argc, char *argv[]) { 
    SchnauzerDogBuilder builder;
    DogMaker maker {&builder};
    maker.MakeDog();
    maker.Speak();
    maker.Speak();
    return 0; 
}
