#include "UpperView.h"

#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <bdn/Json.h>

#include <cctype>

using namespace bdn;
using namespace bdn::ui;

static std::string makeCardStyle()
{
    return FlexJsonStringify({
        "direction"      : "Column",
        "alignItems"     : "Stretch",
        "justifyContent" : "FlexStart",
        "padding" : {
            "top"    : 20.0,
            "bottom" : 20.0,
            "left"   : 16.0,
            "right"  : 16.0
        },
        "size" : { "width" : 320.0 },
        "spacing" : 8.0
    });
}

UpperView::UpperView()
{
    this->stylesheet = makeCardStyle();

    _title       = std::make_shared<Label>();
    _title->text = "Maiúsculo";
    _title->stylesheet = FlexJsonStringify({
        "margin"    : { "bottom" : 12.0 },
        "textAlign" : "Center"
    });

    _labelText       = std::make_shared<Label>();
    _labelText->text = "Texto";
    _labelText->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _fieldText = std::make_shared<TextField>();
    _fieldText->placeholder = "Digite o texto";
    _fieldText->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _upperButton       = std::make_shared<Button>();
    _upperButton->label = "Maiuscular";
    _upperButton->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _resultLabel       = std::make_shared<Label>();
    _resultLabel->text = "Resultado: ";
    _resultLabel->stylesheet = FlexJsonStringify({
        "margin" : { "top" : 4.0, "bottom" : 8.0 }
    });

    _prevButton       = std::make_shared<Button>();
    _prevButton->label = "Prev";

    _nextButton       = std::make_shared<Button>();
    _nextButton->label = "Next";

    auto navRow = std::make_shared<ContainerView>();
    navRow->stylesheet = FlexJsonStringify({
        "direction" : "Row",
        "spacing"   : 8.0,
        "margin"    : { "top" : 8.0 }
    });
    navRow->addChildView(_prevButton);
    navRow->addChildView(_nextButton);

    this->addChildView(_title);
    this->addChildView(_labelText);
    this->addChildView(_fieldText);
    this->addChildView(_upperButton);
    this->addChildView(_resultLabel);
    this->addChildView(navRow);

    _upperButton->onClick() += [this](auto) {
        std::string txt = _fieldText->text.get();
        for (auto &ch : txt)
            ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
        _resultLabel->text = "Resultado: " + txt;
    };
}

