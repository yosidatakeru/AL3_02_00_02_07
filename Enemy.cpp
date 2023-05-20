#include"Enemy.h"
#include <cassert>
#include "Function.h"

void Enemy::Initialize(Model* model, const Vector3& position, const Vector3& velocity) { 
	// NULLチェック
	assert(model);

	model_ = model;
	// 敵
	textureHandle_ = TextureManager::Load("monhan.png");
	// ワールド変数の初期化
	worldTransform_.Initialize();
	// 引数で受け取った初期座標をセット
	worldTransform_.translation_ = position;
	velocity_ = velocity;
}
//	// NULLポインタチェック
//	assert(model);
//
//	enemymodel_ = model;
//	textureHandle_ = TextureManager::Load("monhan.png");
//	// ワールド変数の初期化
//	worldTransform_.Initialize();
//
//	// 因数で受け取った初期座標をセット
//	worldTransform_.translation_ = position;
//	// 引数で受けっとた速度
//	//velociy_ = velocity;
//}
//
void Enemy::Update()
{
	//Vector3 enemyPosition_;
	// ワールドトランスの更新
	worldTransform_.UpdeateMatrix();
	// 座標を移動させる（1フレーム分の移動量を足しこむ）
	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);
	
}
//
	void Enemy::Draw(ViewProjection viewProjection_) 
	{
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
	}
