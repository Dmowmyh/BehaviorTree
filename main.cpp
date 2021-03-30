#include "BehaviorTree.h"
#include "BehaviorTreeBuilder.h"
#include <chrono>

class Player
{
    public:
        void Init(const std::string& animName, unsigned int FPS, unsigned int nFrames)
        {
            m_AnimName = animName;
            m_FPS = FPS;
            m_nFrames = nFrames;
        }
        void Draw()
        {
            std::cout << "Draw" << m_AnimName << ":" << m_nCurrentFrame++;
            if (m_nCurrentFrame == m_nFrames)
            {
                m_nCurrentFrame = 0;
            }
        }
        void Start()
        {
            m_nCurrentFrame = 0;
        }
        bool IsStopped()
        {
            if (m_nCurrentFrame == 60)
                return true;
            else
                return false;
        }
    private:
        std::string m_AnimName = "";
        unsigned int m_FPS = 0;
        std::size_t m_nCurrentFrame = 0;
        std::size_t m_nFrames = 0;
};

class IntroSplash: public Task
{
    public:
    void Init()
    {
        anim.Init("INTRO_SPLASH", 30, 60);
    }
    void Start()
    {
        anim.Start();
    }
    Status Update()
    {
        if (anim.IsStopped())
            return eSuccess;
        else
            return eRunning;
    }
    private:
        Player anim;
};

int main()
{
    BehaviorTree* tree = BehaviorTreeBuilder().selector()->sequence()->build();
    while (true)
    {
    }
    //tree.OnButton();
}
