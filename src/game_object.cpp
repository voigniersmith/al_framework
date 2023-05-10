#include "main.hpp"


void GameObject::update_position(Vector2 pos) {
  this->_update_position(pos);
  return;
}

void GameObject::update_position(float x, float y) {
  this->_update_position(x, y);
  return;
}

void GameObject::update_velocity(Vector2 velocity) {
  this->_update_velocity(velocity);
  return;
}

void GameObject::update_velocity(float x, float y) {
  this->_update_velocity(x, y);
  return;
}

Vector2 GameObject::get_position() {
  return this->_get_position();
}

Vector2 GameObject::get_velocity() {
  return this->_get_velocity();
}

// Private Functions
void GameObject::_update_position(Vector2 pos) {
  this->position = pos;
  return;
}

void GameObject::_update_position(float x, float y) {
  this->position.x = x;
  this->position.y = y;
  return;
}

void GameObject::_update_velocity(Vector2 velocity) {
  this->velocity = velocity;
  return;
}

void GameObject::_update_velocity(float x, float y) {
  this->velocity.x = x;
  this->velocity.y = y;
  return;
}

Vector2 GameObject::_get_position() {
  return this->position;
}

Vector2 GameObject::_get_velocity() {
  return this->velocity;
}

void GameObject::_destroy() {
  return;
}
