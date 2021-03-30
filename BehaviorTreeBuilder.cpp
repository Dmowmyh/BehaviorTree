#include "BehaviorTreeBuilder.h"
#include "BehaviorTree.h"

//BehaviorTreeBuilder::BehaviorTreeBuilder():
    //behaviorTree(new BehaviorTree)
//{

//}

BehaviorTree* BehaviorTreeBuilder::build()
{
    return new BehaviorTree(this);
}

BehaviorTreeBuilder* BehaviorTreeBuilder::selector()
{
    //if (!behaviorTree->m_pRoot)
    //{
        //behaviorTree->m_pRoot = new Selector;
    //}
    //else
    //{
        //behaviorTree->m_pRoot->AddChild(new Selector);
    //}
    return this;
}

BehaviorTreeBuilder* BehaviorTreeBuilder::sequence()
{
    //behaviorTree->m_pRoot = new Sequence;
    return this;
}
