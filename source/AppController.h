#pragma once

#include <memory>
#include <bdn/ui/UIApplicationController.h>
#include "MainViewController.h"

class AppController : public bdn::ui::UIApplicationController
{
  public:
    void beginLaunch() override;

  private:
    std::shared_ptr<MainViewController> _mainViewController;
};

