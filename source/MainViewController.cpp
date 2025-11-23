#include "MainViewController.h"

#include <bdn/ui.h>
#include <bdn/ui/yoga.h>
#include <bdn/Json.h>

using namespace bdn;
using namespace bdn::ui;

MainViewController::MainViewController()
{
    // Janela principal
    _window           = std::make_shared<Window>();
    _window->title    = "Multi-Telas MVC";
    _window->geometry = Rect{0, 0, 400, 300};
    _window->setLayout(std::make_shared<yoga::Layout>());

    // Root único
    _root = std::make_shared<ContainerView>();
    _root->stylesheet = FlexJsonStringify({
        "direction"      : "Column",
        "flexGrow"       : 1.0,
        "alignItems"     : "Center",
        "justifyContent" : "Center",
        "padding"        : { "all" : 16.0 }
    });

    // Cria as 3 views
    _sumView    = std::make_shared<SumView>();
    _doubleView = std::make_shared<DoubleView>();
    _upperView  = std::make_shared<UpperView>();

    // Adiciona ao root (stack)
    _root->addChildView(_sumView);
    _root->addChildView(_doubleView);
    _root->addChildView(_upperView);

    _window->contentView = _root;

    // Navegação: 0 -> 1 -> 2 -> 0 (cíclica)
    _sumView->nextButton()->onClick()    += [this](auto) { showPage(1); };
    _sumView->prevButton()->onClick()    += [this](auto) { showPage(2); };

    _doubleView->nextButton()->onClick() += [this](auto) { showPage(2); };
    _doubleView->prevButton()->onClick() += [this](auto) { showPage(0); };

    _upperView->nextButton()->onClick()  += [this](auto) { showPage(0); };
    _upperView->prevButton()->onClick()  += [this](auto) { showPage(1); };

    // Começa na primeira tela
    showPage(0);
    _window->visible = true;
}

void MainViewController::showPage(int index)
{
    _currentPage = (index + 3) % 3;

    _sumView->visible    = (_currentPage == 0);
    _doubleView->visible = (_currentPage == 1);
    _upperView->visible  = (_currentPage == 2);
}

