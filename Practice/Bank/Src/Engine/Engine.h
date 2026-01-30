#pragma once
#include <functional>

namespace Wanted
{
	// Main game engine class
	class Engine
	{
		//데이터.
		//Down/Up/Key
		struct KeyState
		{
			//현재 키 눌림 여부
			bool isKeyDown = false;

			//이전에 키 눌림 여부
			bool wasKeyDown = false;
		};

	public:
		Engine();
		~Engine();

		// Engine Loop(Game Loop)(Unity Update)
		void Run();

		// Engine Quit
		void QuitEngine();

		// Tick Callback
		using TickCallback = std::function<void(float)>;
		void SetTickCallback(TickCallback cb);

		using ShutDownCallback = std::function<void()>;
		void SetShutDownCallback(ShutDownCallback cb);

		// 입력 확인 함수
		// 이전에 입력이 안됐는데, 현재 입력이 됐으면 1번 호출
		bool GetKeyDown(int keyCode);
		// 이전에 입력이 됐는데, 현재 입력이 취소됐으면 1번 호출
		bool GetKeyUp(int keyCode);
		// 현재 눌려 있으면 반복 호출
		bool GetKey(int keyCode);

	private :
		//입력 처리 함수
		void ProcessInput();

		//업데이트 함수
		void Tick(float deltaTime);

		//그리기 함수
		void Draw();

		//종료 시점 호출 함수
		void ShutDown();

	private :
		//엔진 종료 Flag
		bool isQuit = false;

		TickCallback m_tick;

		ShutDownCallback m_shutDown;

		// 키 상태 저장용 배열 255개면 모든 키를 받을수 있다고함...(게임패드, 키보드, 마우스 etc...)
		KeyState keyStates[255] = {};
	};
}
