#include <nanogui/nanogui.h>
#include <nanogui/layout.h>
#include <nanogui/window.h>
using namespace nanogui;

int main(int /* argc */, char ** /* argv */) {
    nanogui::init();
    Screen *screen = new Screen({500, 400}, "NanoGUI Test");
    //Window *w = new Window(screen, "demo btn" ); 
    //BoxLayout* b_lay = new BoxLayout(Orientation::Horizontal,Alignment::Maximum,0,6); 
    //w->setLayout(b_lay);
    Button *b = new Button(screen, "Hello world!");
    b->setCallback([] { std::cout << "Button pressed." << std::endl; });

    screen->setVisible(true);
    screen->performLayout();
    nanogui::mainloop();
    nanogui::shutdown();
}

