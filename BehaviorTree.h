#ifndef BEHAVIORTREE_H_
#define BEHAVIORTREE_H_
#include <bits/stdc++.h>
#include "BehaviorTreeBuilder.h"

enum Status
{
    eInvalid,
    eRunning,
    eSuccess,
    eFailure
};

class Task
{
    public:
        virtual void Start() {};
        virtual Status Update() = 0;
        virtual void End() {};
        //virtual void UpdateDraw() {};
        //

        //virtual void Init() {};
    private:
        Status m_eStatus;
    public:
        Task(): m_eStatus(eInvalid) {}
        virtual ~Task() {}
        Status Tick()
        {
            if (m_eStatus != eRunning)
            {
                Start();
            }
            m_eStatus = Update();
            if (m_eStatus != eRunning)
            {
                End();
            }
            return m_eStatus;
        }
};

//class Decorator: public Task
//{
    //protected:
        //Task* m_pChild;
    //public:
        //Decorator(Task* child) : m_pChild(child) {}
//};

class Composite: public Task
{
    public:
        void AddChild(Task* child);
        void RemoveChild(Task* child);
        void ClearChildren();
    protected:
        using Tasks = std::vector<Task*>;
        Tasks m_Children;
};

class Sequence: public Composite
{
    protected:
        Tasks::iterator m_CurrentChild;
        virtual void Start() override
        {
            m_CurrentChild = m_Children.begin();
        }
        virtual Status Update() override
        {
            while (true)
            {
                Status s = (*m_CurrentChild)->Tick();
                if (s != eSuccess)
                {
                    return s;
                }
                if (++m_CurrentChild == m_Children.end())
                {
                    return eSuccess;
                }
            }
            return eInvalid;
        }
};

class Selector: public Composite
{
    public:
        Selector(SelectorTreeBuilder builder) : m_Children(builder.m_Children) {}
        static SelectorTreeBuilder* newBuilder()
        {
            return new SelectorTreeBuilder;
        }
    protected:
        Tasks::iterator m_CurrentChild;
        virtual void Start() override
        {
            m_CurrentChild = m_Children.begin();
        }
        virtual Status Update() override
        {
            while (true)
            {
                Status s = (*m_CurrentChild)->Tick();
                if (s != eFailure)
                {
                    return s;
                }
                if (++m_CurrentChild == m_Children.end())
                {
                    return eFailure;
                }
            }
            return eInvalid;
        }
};

class Filter: public Sequence
{
    public:
        void AddCondition(Task* condition)
        {
            //TODO thats inneficient
            m_Children.insert(m_Children.begin(), condition);
        }
        void AddAction(Task* action)
        {
            m_Children.push_back(action);
        }
};

class BehaviorTree
{
    //TODO
//protected:
    //Task* m_pRoot;
public:
    BehaviorTree(BehaviorTreeBuilder builder)
    Composite* m_pRoot;
    void Update()
    {
        m_pRoot->Tick();
    }
};

#endif
