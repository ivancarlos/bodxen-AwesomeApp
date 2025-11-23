#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <bdn/Json.h>

#include "MainViewController.h"

using namespace bdn;
using namespace bdn::ui;

// Card simples, sem sombra/cor (para evitar bug de estilo)
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

        "size" : {
            "width"  : 320.0
        },

        "spacing" : 8.0
    });
}

MainViewController::MainViewController()
{
    // --- Janela principal ---
    _window           = std::make_shared<Window>();
    _window->title    = "Multi-Telas";
    _window->geometry = Rect{0, 0, 400, 300};
    _window->setLayout(std::make_shared<yoga::Layout>());

    // ============================================================
    // TELA 1 – SOMA
    // ============================================================
    _sumRoot = std::make_shared<ContainerView>();
    _sumRoot->stylesheet = FlexJsonStringify({
        "direction"      : "Column",
        "flexGrow"       : 1.0,
        "alignItems"     : "Center",
        "justifyContent" : "Center",
        "padding"        : { "all" : 16.0 }
    });

    _sumCard = std::make_shared<ContainerView>();
    _sumCard->stylesheet = makeCardStyle();

    _sumTitle       = std::make_shared<Label>();
    _sumTitle->text = "Somador";
    _sumTitle->stylesheet = FlexJsonStringify({
        "margin"    : { "bottom" : 12.0 },
        "textAlign" : "Center"
    });

    _labelA       = std::make_shared<Label>();
    _labelA->text = "Valor A";
    _labelA->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _aField = std::make_shared<TextField>();
    _aField->placeholder = "Digite o valor A";
    _aField->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 8.0 }
    });

    _labelB       = std::make_shared<Label>();
    _labelB->text = "Valor B";
    _labelB->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _bField = std::make_shared<TextField>();
    _bField->placeholder = "Digite o valor B";
    _bField->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _sumButton       = std::make_shared<Button>();
    _sumButton->label = "Somar";
    _sumButton->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "top" : 4.0, "bottom" : 12.0 }
    });

    _sumResultLabel       = std::make_shared<Label>();
    _sumResultLabel->text = "Resultado: ";
    _sumResultLabel->stylesheet = FlexJsonStringify({
        "margin" : { "top" : 4.0, "bottom" : 8.0 }
    });

    _sumPrevButton       = std::make_shared<Button>();
    _sumPrevButton->label = "Prev";

    _sumNextButton       = std::make_shared<Button>();
    _sumNextButton->label = "Next";

    auto navRow1 = std::make_shared<ContainerView>();
    navRow1->stylesheet = FlexJsonStringify({
        "direction" : "Row",
        "spacing"   : 8.0,
        "margin"    : { "top" : 8.0 }
    });
    navRow1->addChildView(_sumPrevButton);
    navRow1->addChildView(_sumNextButton);

    _sumCard->addChildView(_sumTitle);
    _sumCard->addChildView(_labelA);
    _sumCard->addChildView(_aField);
    _sumCard->addChildView(_labelB);
    _sumCard->addChildView(_bField);
    _sumCard->addChildView(_sumButton);
    _sumCard->addChildView(_sumResultLabel);
    _sumCard->addChildView(navRow1);

    _sumRoot->addChildView(_sumCard);

    // ============================================================
    // TELA 2 – X2
    // ============================================================
    _doubleRoot = std::make_shared<ContainerView>();
    _doubleRoot->stylesheet = _sumRoot->stylesheet;

    _doubleCard = std::make_shared<ContainerView>();
    _doubleCard->stylesheet = makeCardStyle();

    _doubleTitle       = std::make_shared<Label>();
    _doubleTitle->text = "Vezes 2";
    _doubleTitle->stylesheet = FlexJsonStringify({
        "margin"    : { "bottom" : 12.0 },
        "textAlign" : "Center"
    });

    _labelX       = std::make_shared<Label>();
    _labelX->text = "Valor X";
    _labelX->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _xField = std::make_shared<TextField>();
    _xField->placeholder = "Digite o valor";
    _xField->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _doubleButton       = std::make_shared<Button>();
    _doubleButton->label = "x2";
    _doubleButton->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _doubleResultLabel       = std::make_shared<Label>();
    _doubleResultLabel->text = "Resultado: ";
    _doubleResultLabel->stylesheet = FlexJsonStringify({
        "margin" : { "top" : 4.0, "bottom" : 8.0 }
    });

    _doublePrevButton       = std::make_shared<Button>();
    _doublePrevButton->label = "Prev";

    _doubleNextButton       = std::make_shared<Button>();
    _doubleNextButton->label = "Next";

    auto navRow2 = std::make_shared<ContainerView>();
    navRow2->stylesheet = FlexJsonStringify({
        "direction" : "Row",
        "spacing"   : 8.0,
        "margin"    : { "top" : 8.0 }
    });
    navRow2->addChildView(_doublePrevButton);
    navRow2->addChildView(_doubleNextButton);

    _doubleCard->addChildView(_doubleTitle);
    _doubleCard->addChildView(_labelX);
    _doubleCard->addChildView(_xField);
    _doubleCard->addChildView(_doubleButton);
    _doubleCard->addChildView(_doubleResultLabel);
    _doubleCard->addChildView(navRow2);

    _doubleRoot->addChildView(_doubleCard);

    // ============================================================
    // TELA 3 – MAIÚSCULO
    // ============================================================
    _upperRoot = std::make_shared<ContainerView>();
    _upperRoot->stylesheet = _sumRoot->stylesheet;

    _upperCard = std::make_shared<ContainerView>();
    _upperCard->stylesheet = makeCardStyle();

    _upperTitle       = std::make_shared<Label>();
    _upperTitle->text = "Maiúsculo";
    _upperTitle->stylesheet = FlexJsonStringify({
        "margin"    : { "bottom" : 12.0 },
        "textAlign" : "Center"
    });

    _labelText       = std::make_shared<Label>();
    _labelText->text = "Texto";
    _labelText->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _textField = std::make_shared<TextField>();
    _textField->placeholder = "Digite o texto";
    _textField->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _upperButton       = std::make_shared<Button>();
    _upperButton->label = "Maiuscular";
    _upperButton->stylesheet = FlexJsonStringify({
        "size"   : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _upperResultLabel       = std::make_shared<Label>();
    _upperResultLabel->text = "Resultado: ";
    _upperResultLabel->stylesheet = FlexJsonStringify({
        "margin" : { "top" : 4.0, "bottom" : 8.0 }
    });

    _upperPrevButton       = std::make_shared<Button>();
    _upperPrevButton->label = "Prev";

    _upperNextButton       = std::make_shared<Button>();
    _upperNextButton->label = "Next";

    auto navRow3 = std::make_shared<ContainerView>();
    navRow3->stylesheet = FlexJsonStringify({
        "direction" : "Row",
        "spacing"   : 8.0,
        "margin"    : { "top" : 8.0 }
    });
    navRow3->addChildView(_upperPrevButton);
    navRow3->addChildView(_upperNextButton);

    _upperCard->addChildView(_upperTitle);
    _upperCard->addChildView(_labelText);
    _upperCard->addChildView(_textField);
    _upperCard->addChildView(_upperButton);
    _upperCard->addChildView(_upperResultLabel);
    _upperCard->addChildView(navRow3);

    _upperRoot->addChildView(_upperCard);

    // ============================================================
    // LÓGICA
    // ============================================================

    // Soma
    _sumButton->onClick() += [this](auto) {
        try {
            double a = std::stod(_aField->text.get());
            double b = std::stod(_bField->text.get());
            _sumResultLabel->text = "Resultado: " + std::to_string(a + b);
        } catch (...) {
            _sumResultLabel->text = "Valor inválido";
        }
    };

    // x2
    _doubleButton->onClick() += [this](auto) {
        try {
            double x = std::stod(_xField->text.get());
            _doubleResultLabel->text = "Resultado: " + std::to_string(2.0 * x);
        } catch (...) {
            _doubleResultLabel->text = "Valor inválido";
        }
    };

    // Maiúsculo
    _upperButton->onClick() += [this](auto) {
        std::string txt = _textField->text.get();
        for (auto &ch : txt)
            ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
        _upperResultLabel->text = "Resultado: " + txt;
    };

    // Navegação (cíclica)
    _sumNextButton->onClick()    += [this](auto) { showPage(1); };
    _sumPrevButton->onClick()    += [this](auto) { showPage(2); };

    _doubleNextButton->onClick() += [this](auto) { showPage(2); };
    _doublePrevButton->onClick() += [this](auto) { showPage(0); };

    _upperNextButton->onClick()  += [this](auto) { showPage(0); };
    _upperPrevButton->onClick()  += [this](auto) { showPage(1); };

    // Começa na tela 0
    showPage(0);

    // Torna a janela visível
    _window->visible = true;
}

void MainViewController::showPage(int index)
{
    _currentPage = (index + 3) % 3;

    switch (_currentPage)
    {
        case 0:
            _window->contentView = _sumRoot;
            break;
        case 1:
            _window->contentView = _doubleRoot;
            break;
        case 2:
            _window->contentView = _upperRoot;
            break;
    }
}

