#include "webui.hpp"

int main() {
  webui::window m_win;
  // m_win.show("index.html");
  m_win.show_browser("index.html", Edge);
  webui::wait();
  return 0;
}

#ifdef _WIN32
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                    _In_ LPWSTR lpCmdLine, _In_ int nShowCmd) {
  return main();
}
#endif