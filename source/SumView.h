#pragma once

#include <memory>
#include <bdn/ui/ContainerView.h>
#include <bdn/ui/Label.h>
#include <bdn/ui/TextField.h>
#include <bdn/ui/Button.h>

class SumView : public bdn::ui::ContainerView
{
  public:
    SumView();
    virtual ~SumView() = default;

    // Para o controller conectar navegação
    std::shared_ptr<bdn::ui::Button> prevButton() const { return _prevButton; }
    std::shared_ptr<bdn::ui::Button> nextButton() const { return _nextButton; }

  private:
    std::shared_ptr<bdn::ui::Label>     _title;
    std::shared_ptr<bdn::ui::Label>     _labelA;
    std::shared_ptr<bdn::ui::Label>     _labelB;
    std::shared_ptr<bdn::ui::TextField> _fieldA;
    std::shared_ptr<bdn::ui::TextField> _fieldB;
    std::shared_ptr<bdn::ui::Button>    _sumButton;
    std::shared_ptr<bdn::ui::Label>     _resultLabel;
    std::shared_ptr<bdn::ui::Button>    _prevButton;
    std::shared_ptr<bdn::ui::Button>    _nextButton;
};

