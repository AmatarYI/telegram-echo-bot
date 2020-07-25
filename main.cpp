#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("TOKEN");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!\nI'm echo-bot written on C++\nAnd soon the Creator will kill me");
    });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        std::cout << "User wrote: " << message->text.c_str() << std::endl;

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