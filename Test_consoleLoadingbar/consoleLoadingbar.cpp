#include "consoleLoadingbar.h"
#include "killhandler.h" // KILLHANDLER ONLY WORKS ON LINUX

int main()
{
#ifdef linux
	linuxSysHandler();
#endif
	std::cout << "LOADING SOMETHING" << std::endl;
	CloadingBarConsole l;
	for (int x = 0; x <= 100; x++) {
		if (x <= 40)
			l.setColorCode(//SET COLOR CODE
				x < 20 ?
				colorcode::CANCEL : x == 40 ?
				colorcode::OK : colorcode::SUSPEND
			);
		l.setPercent(x);//SET PERCENT VALUE
		l.render();
		std::this_thread::sleep_for(std::chrono::milliseconds(x < 40 ? 1500 : 900));
	}
}
