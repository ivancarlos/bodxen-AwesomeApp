#include "SumView.h"

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

SumView::SumView()
{
    // Este ContainerView já É a view (herda de ContainerView)
    this->stylesheet = makeCardStyle();

    _title       = std::make_shared<Label>();
    _title->text = "Somador";
    _title->stylesheet = FlexJsonStringify({
        "margin"    : { "bottom" : 12.0 },
        "textAlign" : "Center"
    });

    _labelA       = std::make_shared<Label>();
    _labelA->text = "Valor A";
    _labelA->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _fieldA = std::make_shared<TextField>();
    _fieldA->placeholder = "Digite o valor A";
    _fieldA->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 8.0 }
    });

    _labelB       = std::make_shared<Label>();
    _labelB->text = "Valor B";
    _labelB->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _fieldB = std::make_shared<TextField>();
    _fieldB->placeholder = "Digite o valor B";
    _fieldB->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _sumButton       = std::make_shared<Button>();
    _sumButton->label = "Somar";
    _sumButton->stylesheet = FlexJsonStringify({
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

    // Monta a hierarquia
    this->addChildView(_title);
    this->addChildView(_labelA);
    this->addChildView(_fieldA);
    this->addChildView(_labelB);
    this->addChildView(_fieldB);
    this->addChildView(_sumButton);
    this->addChildView(_resultLabel);
    this->addChildView(navRow);

    // Lógica da soma
    _sumButton->onClick() += [this](auto) {
        try {
            double a = std::stod(_fieldA->text.get());
            double b = std::stod(_fieldB->text.get());
            _resultLabel->text = "Resultado: " + std::to_string(a + b);
        } catch (...) {
            _resultLabel->text = "Valor inválido";
        }
    };
}

