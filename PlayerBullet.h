#pragma once
//#include "Player.h"
#include "Model.h"
#include "WorldTransform.h"

/// <summary>
/// 自キャラの弾
/// </summary>
class PlayerBullet 
{

public:
	/// <summary>
	/// 初期化
	/// </summary>
	//<param name ="model">モデル</param>
	//<param name ="position">初期座標</param>
	void Initalize(Model* model, const Vector3& position);
	
	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection viewProjection_);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;
};



