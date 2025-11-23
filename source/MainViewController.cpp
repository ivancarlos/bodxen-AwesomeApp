#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <bdn/Json.h>

#include "MainViewController.h"

using namespace bdn;
using namespace bdn::ui;

MainViewController::MainViewController()
{
    _window           = std::make_shared<Window>();
    _window->title    = "AwesomeApp";
    _window->geometry = Rect{0, 0, 400, 300};
    _window->setLayout(std::make_shared<yoga::Layout>());

    auto root = std::make_shared<ContainerView>();

    //
    // 🟦 LAYOUT PRINCIPAL (com padding maior no topo)
    //
    root->stylesheet = FlexJsonStringify({
        "direction"      : "Column",
        "flexGrow"       : 1.0,
        "alignItems"     : "Stretch",
        "justifyContent" : "FlexStart",

        // mais espaço no topo
        "padding" : { 
            "top"    : 32.0,
            "left"   : 16.0,
            "right"  : 16.0,
            "bottom" : 16.0
        },

        "spacing" : 12.0      // espaçamento automático entre filhos
    });

    //
    // 🟦 CAMPOS DE TEXTO
    //
    _aField = std::make_shared<TextField>();
    _aField->placeholder = "Digite o valor A";
    _aField->stylesheet = FlexJsonStringify({
        "size" : { "height" : 48.0 },
        "margin" : { "bottom" : 12.0 }
    });

    _bField = std::make_shared<TextField>();
    _bField->placeholder = "Digite o valor B";
    _bField->stylesheet = FlexJsonStringify({
        "size" : { "height" : 48.0 },
        "margin" : { "bottom" : 12.0 }
    });

    //
    // 🟦 BOTÃO
    //
    _sumButton = std::make_shared<Button>();
    _sumButton->label = "Somar";
    _sumButton->stylesheet = FlexJsonStringify({
        "size" : { "height" : 48.0 },
        "margin" : { "bottom" : 16.0 }
    });

    //
    // 🟦 LABEL DO RESULTADO (mais espaçado)
    //
    _resultLabel = std::make_shared<Label>();
    _resultLabel->text = "Resultado: ";
    _resultLabel->stylesheet = FlexJsonStringify({
        "margin" : { "top" : 12.0 }
    });

    //
    // 🟦 Monta layout
    //
    root->addChildView(_aField);
    root->addChildView(_bField);
    root->addChildView(_sumButton);
    root->addChildView(_resultLabel);

    _window->contentView = root;
    _window->visible = true;

    //
    // 🟦 Lógica
    //
    _sumButton->onClick() += [this](auto){
        try {
            double a = std::stod(_aField->text.get());
            double b = std::stod(_bField->text.get());
            _resultLabel->text = "Resultado: " + std::to_string(a + b);
        }
        catch (...) {
            _resultLabel->text = "Valor inválido";
        }
    };
}

