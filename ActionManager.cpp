#include "ActionManager.h"
#include "CLIController.h"

ActionManager::ActionManager()
{
    return;
}

ActionManager::~ActionManager()
{

}

void ActionManager::addAction(Action* action)
{
    this->redoStack = stack<Action*>();
    this->undoStack.push(action);
}

ActionAdd::ActionAdd(pair<Item*,int> item) : Action()
{
    this->addedItem = item;
}

ActionAdd::~ActionAdd()
{
    delete this->addedItem.first;
}

void ActionAdd::executeUndo(CLIController* controller)
{
    controller->removeElem(this->addedItem.first->getId());
}

void ActionAdd::executeRedo(CLIController* controller)
{
    controller->addElem(this->addedItem.first, this->addedItem.second);
}

ActionRemove::ActionRemove(pair<Item*, int> item)
{
    this->removedItem = item;
}

ActionRemove::~ActionRemove()
{
    delete this->removedItem.first;
}

void ActionRemove::executeUndo(CLIController* controller)
{
    controller->addElem(this->removedItem.first, this->removedItem.second);
}

void ActionRemove::executeRedo(CLIController* controller)
{
    controller->removeElem(this->removedItem.first->getId());
}

ActionModify::ActionModify(pair<Item*,int> prevState, pair<Item*,int> currentState)
{
    this->prevState = prevState;
    this->currentState = currentState;
}

ActionModify::~ActionModify()
{
    delete this->prevState.first;
    delete this->currentState.first;
}

void ActionModify::executeUndo(CLIController* controller)
{
    controller->modify(prevState,currentState.first->getId());
}

void ActionModify::executeRedo(CLIController* controller)
{
    controller->modify(currentState,prevState.first->getId());
}

void ActionManager::undo(CLIController* controller)
{
    if (this->undoStack.size() > 0)
    {
        this->undoStack.top()->executeUndo(controller);
        this->redoStack.push(this->undoStack.top());
        this->undoStack.pop();
    }
    else
        throw(8);
}


void ActionManager::redo(CLIController* controller)
{
    if (this->redoStack.size() > 0)
    {
        this->redoStack.top()->executeRedo(controller);
        this->undoStack.push(this->redoStack.top());
        this->redoStack.pop();
    }
    else
        throw(9);
}
