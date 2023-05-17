#include "Player.h"
#include<cassert>
void Player::Initialize(Model* model, uint32_t textureHandle) 
{
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	this -> model_ = model;
	this -> textureHandle_ = textureHandle;

	// ワールド変数の初期化
	worldTransform_.Initialize();
}
void Player::Update() 
{
	//行列を定数バッファに転送する
	worldTransform_.TransferMatrix();
}
void Player::Draw(ViewProjection viewProjection_) 
{ 
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}