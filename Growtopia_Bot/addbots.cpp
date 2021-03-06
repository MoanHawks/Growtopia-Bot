
//    Grotopia Bot
//    Copyright (C) 2018  Growtopia Noobs
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "addbots.h"
#include "ui_addbots.h"

AddBots::AddBots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBots)
{
    ui->setupUi(this);
}

AddBots::~AddBots()
{
    delete ui;
}

void AddBots::on_buttonBox_accepted()
{
    this->setResult(QDialog::Accepted);
    BotSettings settings;

    settings.username = ui->username->text().toStdString();
    settings.password = ui->password->text().toStdString();
    settings.bot = new GrowtopiaBot(settings.username,settings.password);
    settings.bot->worldName = choosenWorld;
    settings.bot->publicOwnership = publicOwner;
    settings.bot->backwardWalk=backwardWalk;
    settings.bot->gameVersion=gameVersion;
    if(botsSettings.size()!=0)
        settings.bot->isFollowing = botsSettings.at(0).bot->isFollowing;
    settings.bot->userInit();
    botsSettings.push_back(settings);
    refreshBotList();
}
