#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

class GameObject {

  // Setters
  void _update_position(Vector2);
  void _update_position(float, float);
  void _update_velocity(Vector2);
  void _update_velocity(float, float);

  // Getters
  Vector2 _get_position();
  Vector2 _get_velocity();

  // Cleaning up
  void _destroy();

  // Class Variables
  Vector2 position;
  Vector2 velocity;

  public:
    // Constructors
    GameObject() {}
    GameObject(Vector2 position) : position(position) {}
    GameObject(int x, int y) {
      _update_position(x, y);
    }
    GameObject(Vector2 position, Vector2 velocity) : position(position), velocity(velocity) {}
    GameObject(int x, int y, int xv, int yv) {
      _update_position(x, y);
      _update_velocity(xv, yv);
    }

    void update_position(Vector2);
    void update_position(float, float);
    void update_velocity(Vector2);
    void update_velocity(float, float);
    Vector2 get_position();
    Vector2 get_velocity();
  
    // Deconstructor
    ~GameObject() {
      _destroy();
    }
};

#endif
