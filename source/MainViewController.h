#pragma once

#include <memory>
#include <bdn/ui/Window.h>
#include <bdn/ui/TextField.h>
#include <bdn/ui/Label.h>
#include <bdn/ui/Button.h>

class MainViewController
{
  public:
    MainViewController();
    virtual ~MainViewController() = default;

  private:
    std::shared_ptr<bdn::ui::Window>    _window;
    std::shared_ptr<bdn::ui::TextField> _aField;
    std::shared_ptr<bdn::ui::TextField> _bField;
    std::shared_ptr<bdn::ui::Label>     _resultLabel;
    std::shared_ptr<bdn::ui::Button>    _sumButton;
};

