#include <tgbot/tgbot.h>

void showMessageAndInfo(TgBot::Message::Ptr);
void showMessage(TgBot::Message::Ptr);

int main() {
    TgBot::Bot bot("TOKEN");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!\nI'm echo-bot written on C++\nAnd soon the Creator will kill me");
    });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {

        showMessageAndInfo(message);

        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        std::cout << "Bot username: " << bot.getApi().getMe()->username.c_str() << std::endl;
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            std::cout << "Long poll..." << std::endl;
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cout << "Error: " << e.what();
    }
    return 0;
}

void showMessageAndInfo(TgBot::Message::Ptr message){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;
    std::cout << "ID: " <<message->from->id << "\nUsername: " << message->from->username  << "\nFirst name: " << message->from->firstName
              << "\nSecond name: " << message->from->lastName << std::endl;
    showMessage(message);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;
}

void showMessage(TgBot::Message::Ptr message){
    std::cout << "Message: " << message->text.c_str() << std::endl;
}