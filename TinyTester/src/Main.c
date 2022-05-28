#include <Core/Logger.h>
#include <Core/Asserter.h>
#include <Platform/platform.h>

int main(void)
{
    TFATAL("A test message: %f", 3.14f);
    TERROR("A test message: %f", 3.14f);
    TWARN("A test message: %f", 3.14f);
    TINFO("A test message: %f", 3.14f);
    TDEBUG("A test message: %f", 3.14f);
    TTRACE("A test message: %f", 3.14f);

    
    platform_state state;
    if (platform_startup(&state, "TinyEngine Tester", 100, 100, 1200, 720))
    {
        while (TRUE)
        {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);
    return 0;
}