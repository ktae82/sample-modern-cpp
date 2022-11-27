#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Command {
public:
  virtual void execute(void) = 0;
  virtual ~Command(void){};
};

class CommandAAA : public Command {
public:
  CommandAAA(std::string msg) : mMsg(msg) {}

  void execute(void) {
    std::cout << "CommandAAA::" << __FUNCTION__ << "() mMSG:" << mMsg
              << std::endl;
  }

private:
  std::string mMsg;
};

class CommandBBB : public Command {
public:
  CommandBBB(std::string msg) : mMsg(msg) {}

  void execute(void) {
    std::cout << "CommandBBB::" << __FUNCTION__ << "() mMSG:" << mMsg
              << std::endl;
  }

private:
  std::string mMsg;
};

class CommandStack {
public:
  void addCommand(std::shared_ptr<Command> cmd) {
    std::cout << "CommandStack::" << __FUNCTION__ << "()" << std::endl;

    commands.push_back(cmd);
  }

  void executeCommands(void) {
    std::cout << "CommandStack::" << __FUNCTION__ << "()" << std::endl;

    for (const auto &spCommand : commands) {
      spCommand->execute();
    }
  }

  void undoCommand(void) {
    std::cout << "CommandStack::" << __FUNCTION__ << "()" << std::endl;

    if (commands.size() >= 1) {
      commands.pop_back();
    }
  }

private:
  std::vector<std::shared_ptr<Command>> commands;
};

int main(void) {
  CommandStack comandStack;

  // create command
  auto firstCmd = std::make_shared<CommandAAA>("1 CommandAAA");
  auto secondCmd = std::make_shared<CommandBBB>("2 CommandBBB");
  auto thirdCmd = std::make_shared<CommandAAA>("3 CommandAAA");
  auto fourthCmd = std::make_shared<CommandAAA>("4 CommandAAA");
  auto fifthCmd = std::make_shared<CommandBBB>("5 CommandBBB");

  // add/undo command
  comandStack.addCommand(firstCmd);
  comandStack.addCommand(secondCmd);
  comandStack.undoCommand();
  comandStack.addCommand(thirdCmd);
  comandStack.undoCommand();
  comandStack.addCommand(fourthCmd);
  comandStack.addCommand(fifthCmd);
  comandStack.executeCommands();
  return 0;
}