/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"


// Game-related State data
SpriteRenderer  *Renderer;

//通过一个width和height(对应于你玩游戏时的设备分辨率)来初始化一个游戏实例
Game::Game(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
	delete Renderer;
}

//使用Init函数来加载着色器、纹理以及初始化游戏状态。
void Game::Init() //初始化函数
{
	// Load shaders
	//ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");
	ResourceManager::LoadShader("triangle.vertex", "triangle.frag", nullptr, "sprite");
	
	// Configure shaders
	//定义如下的矩阵来把世界坐标指定为屏幕坐标：
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	// Load textures
	//ResourceManager::LoadTexture("textures/awesomeface.png", GL_TRUE, "face");
	ResourceManager::LoadTexture("awesomeface.png", GL_TRUE, "face");
	
	// Set render-specific controls
	Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
}

//在Update函数里面更新游戏设置状态(比如玩家/球的移动)
void Game::Update(GLfloat dt) //更新函数
{

}

//通过调用ProcessInput函数来使用存储在Keys数组里的数据来处理输入
void Game::ProcessInput(GLfloat dt) //处理输入函数
{

}

//在Render函数里面渲染游戏。注意，我们在渲染逻辑里面分离出了运动逻辑。
void Game::Render() //渲染函数
{
	Renderer->DrawSprite(ResourceManager::GetTexture("face"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}