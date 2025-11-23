#pragma once

#include <memory>
#include <bdn/ui/Window.h>
#include <bdn/ui/TextField.h>
#include <bdn/ui/Button.h>
#include <bdn/ui/Label.h>
#include <bdn/ui/ContainerView.h>

class MainViewController
{
  public:
    MainViewController();
    virtual ~MainViewController() = default;

  private:
    // Janela principal
    std::shared_ptr<bdn::ui::Window> _window;

    // Índice da tela atual: 0 = soma, 1 = x2, 2 = maiúsculo
    int _currentPage = 0;

    // Raízes das 3 telas (cada uma vira contentView da janela)
    std::shared_ptr<bdn::ui::ContainerView> _sumRoot;
    std::shared_ptr<bdn::ui::ContainerView> _doubleRoot;
    std::shared_ptr<bdn::ui::ContainerView> _upperRoot;

    // --- Tela 1: Soma ---
    std::shared_ptr<bdn::ui::ContainerView> _sumCard;
    std::shared_ptr<bdn::ui::Label>         _sumTitle;
    std::shared_ptr<bdn::ui::Label>         _labelA;
    std::shared_ptr<bdn::ui::Label>         _labelB;
    std::shared_ptr<bdn::ui::TextField>     _aField;
    std::shared_ptr<bdn::ui::TextField>     _bField;
    std::shared_ptr<bdn::ui::Button>        _sumButton;
    std::shared_ptr<bdn::ui::Label>         _sumResultLabel;
    std::shared_ptr<bdn::ui::Button>        _sumPrevButton;
    std::shared_ptr<bdn::ui::Button>        _sumNextButton;

    // --- Tela 2: x2 ---
    std::shared_ptr<bdn::ui::ContainerView> _doubleCard;
    std::shared_ptr<bdn::ui::Label>         _doubleTitle;
    std::shared_ptr<bdn::ui::Label>         _labelX;
    std::shared_ptr<bdn::ui::TextField>     _xField;
    std::shared_ptr<bdn::ui::Button>        _doubleButton;
    std::shared_ptr<bdn::ui::Label>         _doubleResultLabel;
    std::shared_ptr<bdn::ui::Button>        _doublePrevButton;
    std::shared_ptr<bdn::ui::Button>        _doubleNextButton;

    // --- Tela 3: Maiúsculo ---
    std::shared_ptr<bdn::ui::ContainerView> _upperCard;
    std::shared_ptr<bdn::ui::Label>         _upperTitle;
    std::shared_ptr<bdn::ui::Label>         _labelText;
    std::shared_ptr<bdn::ui::TextField>     _textField;
    std::shared_ptr<bdn::ui::Button>        _upperButton;
    std::shared_ptr<bdn::ui::Label>         _upperResultLabel;
    std::shared_ptr<bdn::ui::Button>        _upperPrevButton;
    std::shared_ptr<bdn::ui::Button>        _upperNextButton;

    // Troca de tela
    void showPage(int index);
};

