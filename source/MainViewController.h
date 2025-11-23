#pragma once

#include <memory>
#include <bdn/ui/Window.h>
#include <bdn/ui/TextField.h>
#include <bdn/ui/Button.h>
#include <bdn/ui/Label.h>
#include <bdn/ui/ContainerView.h>

class MainViewController
{
  public:
    MainViewController();
    virtual ~MainViewController() = default;

  private:
    std::shared_ptr<bdn::ui::Window>        _window;

    std::shared_ptr<bdn::ui::ContainerView> _root;
    std::shared_ptr<bdn::ui::ContainerView> _card;

    std::shared_ptr<bdn::ui::Label>         _titleLabel;
    std::shared_ptr<bdn::ui::Label>         _labelA;
    std::shared_ptr<bdn::ui::Label>         _labelB;

    std::shared_ptr<bdn::ui::TextField>     _aField;
    std::shared_ptr<bdn::ui::TextField>     _bField;
    std::shared_ptr<bdn::ui::Button>        _sumButton;
    std::shared_ptr<bdn::ui::Label>         _resultLabel;
};

