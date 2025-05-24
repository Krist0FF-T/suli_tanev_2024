#include "SFML/Graphics.hpp"
#include <math.h>

// #include <chrono>
// #include <iostream>
// #include <sstream>

/*constexpr double G = 0.000000000066743;*/
constexpr float K = 9e9;

struct Body {
  float mass;
  float charge = 0;
  sf::Vector2f pos, vel, acc;
  bool isStatic = false;
};

std::string normalStr(float x) {
  std::ostringstream s;
  s << std::fixed << std::setprecision(2) << x;
  return s.str();
}

inline float getLength(sf::Vector2f v) { return sqrt(v.x * v.x + v.y * v.y); }

class App {
public:
  App(const sf::Vector2u &winSize, uint16_t sub_steps,
      const std::vector<sf::Keyboard::Key> &controls) {
    m_window_size = winSize;
    m_window.create(sf::VideoMode(winSize), "n-body problem", sf::Style::Close);
    m_window.setFramerateLimit(60);
    m_window.setVerticalSyncEnabled(true);
    m_controls = controls;
    m_is_running = true;
    m_substeps = sub_steps;
    /*this->font.loadFromFile("FFFFORWA.TTF");*/
    m_font.openFromFile("CaskaydiaCove.ttf");

    this->reset();
  };

  void reset() {
    // this->maxVel = 0;
    m_size_mult = 80.0;
    m_time_mult = 1.0;
    m_bodies.clear();
    m_spent_time = 0;
    m_udt = 0;
    m_sdt = 0;

    m_cam_pos = {0, 0};

    this->spawnBodies();
  }

  void run() {
    m_prev_time = std::chrono::steady_clock::now();
    while (m_is_running) {
      m_udt = std::chrono::duration_cast<std::chrono::nanoseconds>(
                  std::chrono::steady_clock::now() - m_prev_time)
                  .count() *
              0.000000001;
      m_sdt = m_time_mult * m_udt / (float)m_substeps;
      m_prev_time = std::chrono::steady_clock::now();
      update();
      draw();
    }

    m_window.close();
  }

  void spawnBodies() {
    if (0) {
      // setup 1
      float vel_x = 0;
      float a = 2.0;
      /*float vel_x = M_PI*2/10;*/
      m_bodies.push_back(Body{
          .mass = 1.0f,
          .pos = {1.0f, 0.0f},
          .vel = {vel_x, 1.0f / a},
      });

      m_bodies.push_back(Body{
          .mass = 1.0,
          .pos = {-1.0, 0.0},
          .vel = {vel_x, -1.0f / a},
      });
    } else if (0) {
      // setup 2
      m_bodies.push_back(Body{
          .mass = 1.0,
          .pos = {0, 0},
          .vel = {0, 0.333},
          .isStatic = false,
      });

      m_bodies.push_back(Body{
          .mass = 0.5,
          .pos = {-1, 0},
          /*.vel={0, 1}*/
          .vel = {0, -0.666},
      });

    } else {
      // setup 3
      float vel_x = 0;
      /*float vel_x = M_PI*2/10;*/
      m_bodies.push_back(Body{
          .mass = 1.0,
          .pos = {-2.0, 0.0},
          .vel = {0, 0.5},
      });

      m_bodies.push_back(Body{
          .mass = 1.0,
          .pos = {2.0, 0.0},
          .vel = {0, -0.5},
      });

      m_bodies.push_back(Body{
          .mass = 1.5,
          .pos = {0.0, 2.0},
          .vel = {0.5, 0},
      });
    }
  }

  void updateBodies() {
    std::vector<Body> oldBodies = m_bodies;

    for (uint16_t i = 0; i < m_bodies.size(); i++) {
      // Body *cb = &m_bodies[i];
      Body &cb = m_bodies[i];

      if (cb.isStatic)
        continue;

      cb.acc = {0, 0};
      for (size_t j = 0; j < oldBodies.size(); j++) {
        if (i == j)
          continue;

        Body &b1 = oldBodies[i];
        Body &b2 = oldBodies[j];

        sf::Vector2f diff = (b1.pos - b2.pos);
        float dist = getLength(diff);

        float force = -1 * (b1.mass * b2.mass) / (dist * dist);

        sf::Vector2f da = (diff / dist * force) / cb.mass;

        cb.acc += da;
      }

      cb.vel += cb.acc * m_sdt;
      cb.pos += cb.vel * m_sdt;
    }
  }

  void update() {
    m_spent_time += m_sdt * (double)m_substeps;

    const auto ev_close = [this](const sf::Event::Closed &) {
      m_is_running = false;
    };

    const auto ev_keypress = [this](const sf::Event::KeyPressed &key) {
      switch (key.scancode) {
      case sf::Keyboard::Scancode::Escape: {
        m_is_running = false;
        break;
      }
      case sf::Keyboard::Scancode::U: {
        this->reset();
        break;
      }
      default:
        break;
      }
    };

    m_window.handleEvents(ev_close, ev_keypress);

    std::vector<bool> keyPresses;

    for (uint16_t i = 0; i < m_controls.size(); i++) {
      keyPresses.push_back(sf::Keyboard::isKeyPressed(m_controls[i]));
    }

    m_size_mult += (keyPresses[6] - keyPresses[7]) * m_size_mult * m_udt;
    m_time_mult += (keyPresses[4] - keyPresses[5]) * m_time_mult * m_udt;

    // sf::Vector2f movement(keyPresses[0] - keyPresses[1],
    //                       keyPresses[2] - keyPresses[3]);

    sf::Vector2f movement(sf::Keyboard::isKeyPressed(m_controls[0]) -
                              sf::Keyboard::isKeyPressed(m_controls[1]),
                          sf::Keyboard::isKeyPressed(m_controls[2]) -
                              sf::Keyboard::isKeyPressed(m_controls[3]));

    if (movement.length()) {
      m_cam_pos += movement.normalized() * m_udt / m_size_mult * 300.0f;
    }

    // m_cam_pos.x +=
    //     (keyPresses[0] - keyPresses[1]) * m_udt / m_size_mult * 800.0f;
    //
    // m_cam_pos.y +=
    //     (keyPresses[2] - keyPresses[3]) * m_udt / m_size_mult * 800.0f;

    for (uint16_t i = 0; i < m_substeps; i++)
      this->updateBodies();
  };

  void drawBodies() {
    sf::CircleShape shp;
    shp.setFillColor(sf::Color::White);

    std::vector<sf::Color> colors = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color(0x2374ffff),
    };

    double s = m_size_mult;
    for (size_t i = 0; i < m_bodies.size(); i++) {
      Body &body = m_bodies[i];
      float r = body.mass * 0.1 * m_size_mult;

      shp.setFillColor(colors[i]);

      shp.setRadius(r);
      shp.setOrigin({r, r});
      // shp.setPosition();
      shp.setPosition(sf::Vector2f(
          body.pos.x * s + m_window_size.x * 0.5f + m_cam_pos.x * s,
          body.pos.y * s + m_window_size.y * 0.5f + m_cam_pos.y * s));

      m_window.draw(shp);
    }
  }

  void drawInfo() {
    std::vector<std::string> txts = {
        "sim. speed: " + normalStr(m_time_mult),
        "time elapsed: " + normalStr(m_spent_time),
    };

    for (uint32_t i = 0; i < m_bodies.size(); i++) {
      Body &b = m_bodies[i];
      txts.push_back("");
      txts.push_back("body " + std::to_string(i + 1) + ":");
      txts.push_back("Q = " + normalStr(b.charge));
      txts.push_back("p = (" + normalStr(b.pos.x) + "; " + normalStr(b.pos.y) +
                     ")");
      txts.push_back("v = (" + normalStr(b.vel.x) + "; " + normalStr(b.vel.y) +
                     ")");
      txts.push_back("a = (" + normalStr(b.acc.x) + "; " + normalStr(b.acc.y) +
                     ")");
    }

    uint32_t chs = 16; // character size
    float margin = 20;
    /*float gap = chs/2 + 3; // space between*/
    float gap = chs / 2.0f - 1; // space between

    sf::Text s(m_font);
    s.setLetterSpacing(1);
    s.setCharacterSize(chs);
    s.setFillColor(sf::Color::White);

    for (uint16_t i = 0; i < txts.size(); i++) {
      s.setPosition({(float)margin, margin + (chs + gap) * (float)i});
      s.setString((sf::String)txts[i]);

      m_window.draw(s);
    }
  }

  void draw() {
    m_window.clear(sf::Color::Black);

    this->drawBodies();
    this->drawInfo();

    m_window.display();
  };

  std::vector<sf::Keyboard::Key> m_controls;
  sf::RenderWindow m_window;
  sf::Vector2u m_window_size;
  std::vector<Body> m_bodies;
  bool m_is_running;
  float m_udt;
  float m_sdt;
  std::chrono::steady_clock::time_point m_prev_time;
  float m_size_mult;
  float m_time_mult;
  float m_spent_time;
  uint16_t m_substeps;
  sf::Vector2f m_cam_pos;
  sf::Font m_font;
};

int main() {
  std::vector<sf::Keyboard::Key> controls = {
      sf::Keyboard::Key::A,  sf::Keyboard::Key::D,     sf::Keyboard::Key::W,
      sf::Keyboard::Key::S,  sf::Keyboard::Key::Right, sf::Keyboard::Key::Left,
      sf::Keyboard::Key::Up, sf::Keyboard::Key::Down};

  App({1280, 720}, 100, controls).run();

  return 0;
} // 314 sor - NICE
