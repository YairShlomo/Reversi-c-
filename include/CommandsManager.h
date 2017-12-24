
#ifndef CommandsManager_H_
#define CommandsManager_H_
#include <map>
#include "Command.h"

class CommandsManager {
    public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command,
                        vector<string> args);
    private:
    map<string, Command *> commandsMap;
};

#endif /* CommandsManager_H_ */
