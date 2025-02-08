#pragma once
#include <vector>

//==================================================
// Direct Input Cursor
//==================================================

#define DIC_LEFT			0x00
#define DIC_RIGHT			0x01
#define DIC_CENTER			0x02
#define DIC_EX1				0x03
#define DIC_EX2				0x04
#define DIC_EX3				0x05
#define DIC_EX4				0x06
#define DIC_EX5				0x07

//==================================================
// Direct Input Xbox Controller
//==================================================

#define DIXC_UP				0x00
#define DIXC_DOWN			0x01
#define DIXC_LEFT			0x02
#define DIXC_RIGHT			0x03
#define DIXC_MENU			0x04
#define DIXC_VIEW			0x05
#define DIXC_LEFTSTICK		0x06
#define DIXC_RIGHTSTICK		0x07
#define DIXC_LEFTBUTTON		0x08
#define DIXC_RIGHTBUTTON	0x09
#define DIXC_LB				DIXC_LEFTBUTTON
#define DIXC_RB				DIXC_RIGHTBUTTON
#define DIXC_A				0x0A
#define DIXC_B				0x0B
#define DIXC_X				0x0C
#define DIXC_Y				0x0D
#define DIXC_LEFTTRIGGER	DIXC_A
#define DIXC_RIGHTTRIGGER	DIXC_B
#define DIXC_LT				DIXC_LEFTTRIGGER
#define DIXC_RT				DIXC_RIGHTTRIGGER

enum InputType {
    KEYBOARD,
    MOUSE,
    JOYSTICK
};

class GetInput {
    GetInput() = default;
    ~GetInput() = default;

	char keys_[256] = { 0 };
    char preKeys_[256] = { 0 };

	int mouseX_ = 0;
	int mouseY_ = 0;
	int mousePreX_ = 0;
	int mousePreY_ = 0;
    char mousePushButton_[8] = { 0 };
    char mousePrePushButton_[8] = { 0 };
	bool isMouseMove_ = false;

	int joysticksNum_ = -1;
    std::vector<int> joystickAnalogLeftX_ = {};
    std::vector<int> joystickAnalogLeftY_ = {};
    std::vector<int> joystickAnalogLeftPreX_ = {};
    std::vector<int> joystickAnalogLeftPreY_ = {};
	std::vector<int> joystickAnalogRightX_ = {};
	std::vector<int> joystickAnalogRightY_ = {};
	std::vector<int> joystickAnalogRightPreX_ = {};
	std::vector<int> joystickAnalogRightPreY_ = {};
	std::vector<char> joystickPushButton_[20] = {};
	std::vector<char> joystickPrePushButton_[20] = {};

	InputType nowInputType_ = KEYBOARD;

public:
    GetInput(const GetInput &) = delete;
    GetInput &operator=(const GetInput &) = delete;
    GetInput(GetInput &&) = delete;
    GetInput &operator=(GetInput &&) = delete;

    static GetInput *GetInstance() {
        static GetInput instance;
        return &instance;
    }

	void UpdateKeys();
	void UpdateMouse();
	void UpdateJoystick();
    void UpdateInputType();

	bool Keys(int keyID);
	bool PreKeys(int keyID);
	bool TriggerKeys(int keyID);
	bool ReleaseKeys(int keyID);
	bool Keys(std::vector<int> keyID);
	bool PreKeys(std::vector<int> keyID);
	bool TriggerKeys(std::vector<int> keyID);
	bool ReleaseKeys(std::vector<int> keyID);

	int MouseX();
	int MouseY();
	int MousePreX();
	int MousePreY();
	bool MousePushButton(int buttonID);
	bool MousePrePushButton(int buttonID);
	bool MouseTriggerButton(int buttonID);
	bool MouseReleaseButton(int buttonID);
	bool MousePushButton(std::vector<int> buttonID);
	bool MousePrePushButton(std::vector<int> buttonID);
	bool MouseTriggerButton(std::vector<int> buttonID);
	bool MouseReleaseButton(std::vector<int> buttonID);
	bool IsMouseMove();

	int JoysticksNum();
	int JoystickAnalogLeftX(int stickNo);
	int JoystickAnalogLeftY(int stickNo);
	int JoystickAnalogLeftPreX(int stickNo);
	int JoystickAnalogLeftPreY(int stickNo);
	int JoystickAnalogRightX(int stickNo);
	int JoystickAnalogRightY(int stickNo);
	int JoystickAnalogRightPreX(int stickNo);
	int JoystickAnalogRightPreY(int stickNo);
	bool JoystickPushButton(int stickNo, int buttonID);
	bool JoystickPrePushButton(int stickNo, int buttonID);
	bool JoystickTriggerButton(int stickNo, int buttonID);
	bool JoystickReleaseButton(int stickNo, int buttonID);
	bool JoystickPushButton(int stickNo, std::vector<int> buttonID);
	bool JoystickPrePushButton(int stickNo, std::vector<int> buttonID);
	bool JoystickTriggerButton(int stickNo, std::vector<int> buttonID);
	bool JoystickReleaseButton(int stickNo, std::vector<int> buttonID);

    bool IsInputType(InputType inputType);
    bool IsInputType(InputType inputType1, InputType inputType2);
    InputType NowInputType();
};