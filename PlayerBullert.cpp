#include"PlayerBullet.h"
#include<cassert>

void PlayerBullet::Initalize(Model* model, const Vector3& position)
{ 
	//NULLポインタチェック
	assert(model);

	model_ = model;
	//テクスチャ読み込む
	textureHandle_ = TextureManager::Load("tex1.png");
	// ワールド変数の初期化
	worldTransform_.Initialize();
	
	//position初期座標
	//因数で受け取った初期座標をセット
	worldTransform_.translation_ = position;
}

void PlayerBullet::Update() 
{
	//ワールドトランスの更新
	worldTransform_.UpdeateMatrix();
}



void PlayerBullet::Draw(ViewProjection viewProjection_) 
{
	//モデルの描画
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}