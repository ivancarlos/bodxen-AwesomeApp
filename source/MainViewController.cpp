#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <bdn/Json.h>

#include "MainViewController.h"

using namespace bdn;
using namespace bdn::ui;

MainViewController::MainViewController()
{
    // Janela principal
    _window           = std::make_shared<Window>();
    _window->title    = "Somador";
    _window->geometry = Rect{0, 0, 400, 300};
    _window->setLayout(std::make_shared<yoga::Layout>());

    //
    // ROOT: centraliza o card vertical e horizontalmente
    //
    _root = std::make_shared<ContainerView>();
    _root->stylesheet = FlexJsonStringify({
        "direction"      : "Column",
        "flexGrow"       : 1.0,
        "alignItems"     : "Center",      // centra horizontal
        "justifyContent" : "Center",      // centra vertical
        "padding"        : { "all" : 16.0 }
    });

    //
    // CARD: “caixinha” com padding interno
    //
    _card = std::make_shared<ContainerView>();
    _card->stylesheet = FlexJsonStringify({
        "direction"      : "Column",
        "alignItems"     : "Stretch",
        "justifyContent" : "FlexStart",

        "padding" : {
            "top"    : 20.0,
            "bottom" : 20.0,
            "left"   : 16.0,
            "right"  : 16.0
        },

        // largura confortável
        "size" : {
            "width"  : 320.0
        },

        // só pra dar cara de card (se o tema suportar)
        "backgroundColor" : "#FFFFFF",
        "cornerRadius"    : 8.0,
        "shadow" : {
            "radius" : 4.0,
            "opacity": 0.25,
            "offset" : { "width" : 0.0, "height" : 2.0 }
        },

        // espaço vertical entre os filhos do card
        "spacing" : 8.0
    });

    //
    // TÍTULO
    //
    _titleLabel       = std::make_shared<Label>();
    _titleLabel->text = "Somador";
    _titleLabel->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 12.0 },
        "font"   : { "size" : 20.0, "weight" : "Bold" },
        "textAlign" : "Center"
    });

    //
    // LABEL + CAMPO A
    //
    _labelA       = std::make_shared<Label>();
    _labelA->text = "Valor A";
    _labelA->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _aField = std::make_shared<TextField>();
    _aField->placeholder = "Digite o valor A";
    _aField->stylesheet = FlexJsonStringify({
        "size" : { "height" : 44.0 },
        "margin" : { "bottom" : 8.0 }
    });

    //
    // LABEL + CAMPO B
    //
    _labelB       = std::make_shared<Label>();
    _labelB->text = "Valor B";
    _labelB->stylesheet = FlexJsonStringify({
        "margin" : { "bottom" : 4.0 }
    });

    _bField = std::make_shared<TextField>();
    _bField->placeholder = "Digite o valor B";
    _bField->stylesheet = FlexJsonStringify({
        "size" : { "height" : 44.0 },
        "margin" : { "bottom" : 12.0 }
    });

    //
    // BOTÃO
    //
    _sumButton       = std::make_shared<Button>();
    _sumButton->label = "Somar";
    _sumButton->stylesheet = FlexJsonStringify({
        "size" : { "height" : 44.0 },
        "margin" : { "top" : 4.0, "bottom" : 12.0 }
    });

    //
    // RESULTADO
    //
    _resultLabel       = std::make_shared<Label>();
    _resultLabel->text = "Resultado: ";
    _resultLabel->stylesheet = FlexJsonStringify({
        "margin" : { "top" : 4.0 }
    });

    //
    // Monta a hierarquia:
    // root → card → (título, A, campo A, B, campo B, botão, resultado)
    //
    _card->addChildView(_titleLabel);

    _card->addChildView(_labelA);
    _card->addChildView(_aField);

    _card->addChildView(_labelB);
    _card->addChildView(_bField);

    _card->addChildView(_sumButton);
    _card->addChildView(_resultLabel);

    _root->addChildView(_card);

    _window->contentView = _root;
    _window->visible     = true;

    //
    // Lógica do botão "Somar"
    //
    _sumButton->onClick() += [this](auto /*event*/) {
        try {
            double a = std::stod(_aField->text.get());
            double b = std::stod(_bField->text.get());
            double s = a + b;

            _resultLabel->text = "Resultado: " + std::to_string(s);
        }
        catch (...) {
            _resultLabel->text = "Valor inválido";
        }
    };
}

