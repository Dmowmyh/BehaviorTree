#ifndef BEHAVIORTREEBUILDER_H_
#define BEHAVIORTREEBUILDER_H_
#include <vector>

class BehaviorTree;
class Composite;
class Selector;
class Sequence;
class Task;

class BehaviorTreeBuilder
{
public:
    //BehaviorTreeBuilder();
    BehaviorTree* build();
    BehaviorTreeBuilder* selector();
    BehaviorTreeBuilder* sequence();

//private:
    //BehaviorTree* behaviorTree;
};

class SelectorTreeBuilder
{
public:
    using Tasks = std::vector<Task*>;
    Tasks m_Children;
};

#endif
