#include <tgbot/tgbot.h>

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593
void showMessageAndInfo(TgBot::Message::Ptr);
void showMessage(TgBot::Message::Ptr);
bool isPhoto(TgBot::Message::Ptr);

<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593
int main() {
    TgBot::Bot bot("TOKEN");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!\nI'm echo-bot written on C++\nAnd soon the Creator will kill me");
    });
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        if(isPhoto(message))
        {
            bot.getApi().sendMessage(message->chat->id, "Your message is photo. Replying...");
            bot.getApi().forwardMessage(message->chat->id,message->from->id, message->messageId,false);
            showMessageAndInfo(message);
            return;
        }
        showMessageAndInfo(message);

<<<<<<< HEAD
=======
=======
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        std::cout << "User wrote: " << message->text.c_str() << std::endl;

        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593
}

void showMessageAndInfo(TgBot::Message::Ptr message){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;
    std::cout << "ID: " <<message->from->id << "\nUsername: " << message->from->username  << "\nFirst name: "
    << message->from->firstName << "\nSecond name: " << message->from->lastName << std::endl;
    if(!isPhoto(message))
        showMessage(message);
    else
        std::cout << "Photo ? Size: " <<message->photo.size() << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;
}

void showMessage(TgBot::Message::Ptr message){
    std::cout << "Message: " << message->text.c_str() << std::endl;
}

bool isPhoto(TgBot::Message::Ptr message) {
    return message->photo.size()!=0;
}
<<<<<<< HEAD
=======
}
>>>>>>> master
=======
}
>>>>>>> 69c6902a81897189c1072cd11e1b9f86bc6bb593
