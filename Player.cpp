#include "Player.h"
#include<cassert>
#include "Function.h"
#include <ImguiManager.h>
void Player::Initialize(Model* model, uint32_t textureHandle) 
{
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	this -> model_ = model;
	this -> textureHandle_ = textureHandle;

	// ワールド変数の初期化
	worldTransform_.Initialize();

	//シングルトンインスタンスを取得
	input_ = Input::GetInstance();

}
void Player::Update() 
{
	////行列を定数バッファに転送する
	worldTransform_.TransferMatrix();

	////移動ベクトルの設定
	////基本斜め移動

	////キャラクターの移動ベクトル
	Vector3 move = {0.0f, 0.0f, 0.0f};

	////キャラクターの移動速度
	const float kCharacterSpeed = 0.2f;

	////押した方向で移動ベクトルを変更（左右）
	if (input_->PushKey(DIK_LEFT)) 
	{
		move.x -= kCharacterSpeed;
	}
	else if (input_->PushKey(DIK_RIGHT)) 
	{
		move.x += kCharacterSpeed;
	}
	else if(input_->PushKey(DIK_DOWN)) 
	{
		move.y -= kCharacterSpeed; 
	}
	else if (input_->PushKey(DIK_UP))
	{
		move.y += kCharacterSpeed;
	}
	else {
		move.x = 0.0f;
		move.y = 0.0f;
	}


	 
	//回転速さ[ラジアン/frame]
	const float kRotSpeed = 0.02f;
	//押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_A))
	{
		worldTransform_.rotation_.y -= kRotSpeed;
	}
	if (input_->PushKey(DIK_D))
	{
		worldTransform_.rotation_.y += kRotSpeed;
	}
	//キャラクターの攻撃処理
	Attack();
	if (bullet_)
	{
		bullet_->Update();
	}
	
	// 移動の限界
	const float MOVE_LIMITX = 30.0f;
	const float MOVE_LIMITY = 18.0f;

	
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -MOVE_LIMITX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, MOVE_LIMITX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -MOVE_LIMITY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, MOVE_LIMITY);
	// 座標移動（ベクトルの加算）
	worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	////平行移動行列

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
	//画面に座標を出す
	ImGui::Begin("Player");

	ImGui::InputFloat3("PlayerPosition", &worldTransform_.translation_.x);
	ImGui::SliderFloat3("PlayerSlide", &worldTransform_.translation_.x, -20.0f, 30.0f);

	ImGui::End();
}

void Player::Attack() 
{
	// SPACEキーで発射
	if (input_->TriggerKey(DIK_SPACE)) 
	{

		// 弾を生成し、初期化
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initalize(model_, worldTransform_.translation_);

		// 弾を登録する
		
		bullet_ = (newBullet);
	}
}

void Player::Draw(ViewProjection viewProjection_) 
{ 
	model_->Draw(worldTransform_, viewProjection_,textureHandle_);
	//弾描画
	if (bullet_)
	{
		bullet_->Draw(viewProjection_);
	}
}