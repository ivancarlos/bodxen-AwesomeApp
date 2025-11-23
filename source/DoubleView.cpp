#include "DoubleView.h"

#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <bdn/Json.h>

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

DoubleView::DoubleView()
{
    this->stylesheet = makeCardStyle();

    _title       = std::make_shared<Label>();
    _title->text = "Vezes 2";
    _title->stylesheet = FlexJsonStringify({
        "margin"    : { "bottom" : 12.0 },
        "textAlign" : "Center"
    });

    _labelX       = std::make_shared<Label>();
    _labelX->text = "Valor X";
    _labelX->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _fieldX = std::make_shared<TextField>();
    _fieldX->placeholder = "Digite o valor";
    _fieldX->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _doubleButton       = std::make_shared<Button>();
    _doubleButton->label = "x2";
    _doubleButton->stylesheet = FlexJsonStringify({
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
    this->addChildView(_labelX);
    this->addChildView(_fieldX);
    this->addChildView(_doubleButton);
    this->addChildView(_resultLabel);
    this->addChildView(navRow);

    _doubleButton->onClick() += [this](auto) {
        try {
            double x = std::stod(_fieldX->text.get());
            _resultLabel->text = "Resultado: " + std::to_string(2.0 * x);
        } catch (...) {
            _resultLabel->text = "Valor inválido";
        }
    };
}

