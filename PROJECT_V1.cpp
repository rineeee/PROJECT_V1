#include<bangtal.h>

#include<stdio.h>
#include<windows.h>

#include <stdlib.h>
#include <time.h>

SceneID scene1, scene3, scene4, scene5, scene6, scene7, scene8,scene2_14,scene9,scene10,scene11;
ObjectID left1, start, left2, left3, r1left, r1right, r2left, r2right, r3left, r3right, r4left, r4right, door, driver, screw, cut,cutblack,ballon,piano,shelf,table,box,safe1,knife,safe2,key1,key2,key,medicine,cake,safe3,memo,dooropen,restart;
bool closed1 = true, closed2 = true, closed3 = true, closed4= true, closed5 =true;
TimerID timer1;
const Second animationTime = 5.f;

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown)
{
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}

	return object;
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	defineCombination(key1, key2, key);

	if (object == start) {
		enterScene(scene2_14);

	}
	else if (object == left1) {
		enterScene(scene3);
		showMessage("토끼가 어디 가는 거지");
	}
	 else if (object == left2) {
		enterScene(scene4);
		showMessage("어..어..!");
	}
	else if (object == left3) {
		enterScene(scene5);
		showTimer(timer1);
		startTimer(timer1);
		showMessage("여기가 어디야.. 얼른 나가야겠어.");
	}
	else if (object == r1left) {
		enterScene(scene6);
	}
	else if (object == r2left) {
		enterScene(scene7);
	}
	else if (object == r3left) {
		enterScene(scene8);
	}
	else if (object == r4left) {
		enterScene(scene5);
	}
	else if (object == r1right) {
		enterScene(scene8);
	}
	else if (object == r2right) {
		enterScene(scene5);
	}
	else if (object == r3right) {
		enterScene(scene6);
	}
	else if (object == r4right) {
		enterScene(scene7);
	}
	else if (object == medicine) {
		enterScene(scene9);
		showMessage("키가 작아진것 같아 어떡해..");
	}
	else if (object == cake) {
		enterScene(scene7);
		showMessage("다시 커졌네.. 다행이다..");
	}
	else if (object == door) {
		if (closed1 == true) {
			if (getHandObject() == key) {
				hideObject(door);
				showObject(dooropen);
				closed1 = false;
			}
			else {
				showMessage("잠겨 있어");
			}
		}		
	}
	else if(object == dooropen) {
		enterScene(scene10);
		showMessage("밖이다!");
	}
	else if (object == key1) {
		pickObject(key1);
	}
	else if (object == knife) {
		pickObject(knife);
	}
	else if (object == key2) {
		pickObject(key2);
	}
	else if (object == driver) {
		pickObject(driver);
	}
	else if (object == safe1) {
		showKeypad("351", safe1);
	}
	else if (object == safe2) {
		showKeypad("GETOUT", safe2);
	}
	else if (object == safe3) {
		showKeypad("543126", safe3);
	}
	else if (object == restart) {
		enterScene(scene5);
		setTimer(timer1, 10.f);
		startTimer(timer1);
	}
	else if (object == box) {
		if (closed5 == true) {
			if (getHandObject() == knife) {
				setObjectImage(box, "열린 상자.png");
				closed1 = false;
				showObject(memo);
			}
			else {
				showMessage("안 뜯어져..");
			}
		}
	}
	else if (object == memo) {
		showImageViewer("쪽지 확대본.png");
	}
	else if (object == ballon) {
			if (getHandObject() == knife) {
				hideObject(ballon);
				showObject(driver);
			}
		}
	else if (object == piano) {
		showImageViewer("피아노 확대본.png");
	}
	else if (object == screw) {
	if (getHandObject() == driver) {
		showObject(cutblack);
		showObject(cut);
		showObject(safe2);
	}
		}
}

void timerCallback(TimerID timer)
{
	if (timer == timer1) {
		enterScene(scene11);
	}
}

void objectCallback(ObjectID object, EventID event)
{
	if (object == safe1) {
		if (event == EventID::EVENT_KEYPAD) {
			closed3 = false;
			showMessage("풀렸네");
			setObjectImage(safe1, "금고 열림.png");
			showObject(knife);
		}
	}
	if (object == safe2) {
		if (event == EventID::EVENT_KEYPAD) {
			closed2 = false;
			showMessage("풀렸네");
			setObjectImage(safe2, "함 열림.png");
			showObject(key1);
		}
	}
	if (object == safe3) {
		if (event == EventID::EVENT_KEYPAD) {
			closed4 = false;
			showMessage("풀렸네");
			setObjectImage(safe3, "함 열림1.png");
			showObject(key2);
		}
	}
}

int main() {
	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);
	setObjectCallback(objectCallback);

	defineCombination(key1, key2, key);
	

	scene1 = createScene("앨리스", "앨리스1.png");
	scene2_14 = createScene("앨리스", "앨리스1-14.png");
	scene3 = createScene("앨리스", "토끼.png");
	scene4 = createScene("앨리스", "검정.png");
	scene5 = createScene("1", "배경.jpg");
	scene6 = createScene("2", "배경.jpg");
	scene7 = createScene("3", "배경.jpg");
	scene8 = createScene("4", "배경.jpg");
	scene9 = createScene("??", "작아진나.png");
	scene10 = createScene("탈출","탈출.png");
	scene11 = createScene("gameover", "gameover.jpg");

	key = createObject("열쇠.png", scene5, 230, 20, false);
	start = createObject( "start.png", scene1, 570, 60, true);
	left1 = createObject("left.png", scene2_14, 1170, 60, true);
	left2 = createObject("left.png", scene3, 1170, 60, true);
	left3 = createObject( "left.png", scene4, 1170, 60, true);
	r1left = createObject( "left.png", scene5, 1170, 60, true);
	r2left = createObject( "left.png", scene6, 1170, 60, true);
	r3left = createObject( "left.png", scene7, 1170, 60, true);
	r4left = createObject( "left.png", scene8, 1170, 60, true);
	r1right = createObject( "right.png", scene5, 20, 60, true);
	r2right = createObject( "right.png", scene6, 20, 60, true);
	r3right = createObject( "right.png", scene7, 20, 60, true);
	r4right = createObject( "right.png", scene8, 20, 60, true);

	door = createObject( "문.png", scene5, 230, 95, true);
	scaleObject(door, 0.7f);


	dooropen = createObject("문열림.png", scene5, 210, 55, false);
	scaleObject(dooropen, 1.3f);

	driver = createObject("육각 드라이버.png", scene8, 200, 55, false);
	scaleObject(driver, 0.3f);

	screw = createObject("육각나사.png", scene5, 840, 255, true);
	scaleObject(screw, 0.5f);

	cut = createObject("잘림.png", scene5, 940, 25, false);
	scaleObject(cut, 1.1f);

	cutblack = createObject("잘림검.png", scene5, 828, 156, false);
	scaleObject(cutblack, 1.1f);

	ballon = createObject("풍선.png", scene8, 150, 195, true);

	piano = createObject("피아노.png", scene6, 210, 45, true);
	scaleObject(piano, 0.9f);

	shelf = createObject("장.png", scene8, 830, 65, true);
	scaleObject(shelf, 0.8f);

	table = createObject("테이블.png", scene7, 830, 45, true);

	restart = createObject("restart.png", scene11, 330, 45, true);

	box = createObject("상자.png", scene6, 870, 25, true);

	safe1 = createObject("금고.png", scene7, 280, 55, true);

	knife = createObject("칼.png", scene7, 420, 55, false);

	safe2 = createObject("함.png", scene5, 620, 55, false);

	key1 = createObject("잘린열쇠1.png", scene5, 620, 25, false);
	scaleObject(key1, 0.7f);

	key2 = createObject("잘린열쇠2.png", scene9, 320, 195, false);
	scaleObject(key2, 0.7f);

	cake = createObject("케이크.png", scene9, 720, 155, true);
	scaleObject(cake, 1.2f);

	medicine = createObject("medicine.png", scene7, 850, 255, true);

	safe3= createObject("함1.png", scene9, 220, 205, true);

	memo = createObject("쪽지.png", scene6, 770, 25, false);

	timer1 = createTimer(3.f);

	startGame(scene1);
}