#include "DJ.h"
#include "music.h"
#include "Recording.h"
extern Music music;

int main(void) {

	game_init();//게임 초기설정

	game_status status = game_status::Init; // 寃뚯엫 ?곹깭 ?쒖떆
	string filename = "music";	// filename ?�??
	thread thread_recording(Record, &status, &filename); // ?뱀쓬???곕젅??
	
	srand((unsigned int)time(0) * (unsigned int)GetCurrentThreadId());

	game_init();//寃뚯엫 珥덇린?ㅼ젙
	
        // music thread
	thread music_thread(&Music::music_start, &music);
	
	system("cls");
		
	
	while (1) {
		status = game_status::Start;

		if (!menu_function())
			break;

		status = game_status::GameOver;
	} //게임오버 당할때까지
	
	status = game_status::End;

	thread_recording.join(); // ?곕젅??醫낅즺源뚯? ?�湲?


	return 0;
}
