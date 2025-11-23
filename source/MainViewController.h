#pragma once

#include <memory>
#include <bdn/ui/Window.h>
#include <bdn/ui/ContainerView.h>

#include "SumView.h"
#include "DoubleView.h"
#include "UpperView.h"

class MainViewController
{
  public:
    MainViewController();
    virtual ~MainViewController() = default;

  private:
    std::shared_ptr<bdn::ui::Window>        _window;
    std::shared_ptr<bdn::ui::ContainerView> _root;

    int _currentPage = 0; // 0 = soma, 1 = x2, 2 = maiúsculo

    std::shared_ptr<SumView>    _sumView;
    std::shared_ptr<DoubleView> _doubleView;
    std::shared_ptr<UpperView>  _upperView;

    void showPage(int index);
};

