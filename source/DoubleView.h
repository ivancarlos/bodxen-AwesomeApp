#pragma once

#include <memory>
#include <bdn/ui/ContainerView.h>
#include <bdn/ui/Label.h>
#include <bdn/ui/TextField.h>
#include <bdn/ui/Button.h>

class DoubleView : public bdn::ui::ContainerView
{
  public:
    DoubleView();
    virtual ~DoubleView() = default;

    std::shared_ptr<bdn::ui::Button> prevButton() const { return _prevButton; }
    std::shared_ptr<bdn::ui::Button> nextButton() const { return _nextButton; }

  private:
    std::shared_ptr<bdn::ui::Label>     _title;
    std::shared_ptr<bdn::ui::Label>     _labelX;
    std::shared_ptr<bdn::ui::TextField> _fieldX;
    std::shared_ptr<bdn::ui::Button>    _doubleButton;
    std::shared_ptr<bdn::ui::Label>     _resultLabel;
    std::shared_ptr<bdn::ui::Button>    _prevButton;
    std::shared_ptr<bdn::ui::Button>    _nextButton;
};

