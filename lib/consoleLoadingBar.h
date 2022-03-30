enum colorcode {
	OK,
	SUSPEND,
	CANCEL
};

class CloadingBarConsole {
private:
	void* hConsole;
	int* pcent;
	colorcode cc = colorcode::OK;
public:
	CloadingBarConsole(void);
	void render();
	void setPercent(int p);
	~CloadingBarConsole();
	void setColorCode(colorcode colorcode = colorcode::OK);
	void resetColor();
};
