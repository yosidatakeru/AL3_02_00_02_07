#pragma once

#include "Model.h"
#include "WorldTransform.h"
class Enemy
{
public:

	//行動フェーズ
	enum class Phase
	{
		Approach,//接近する
		Leave,//離脱する
	};
	//フェーズ
	Phase phase_ = Phase::Approach; // 初期フェーズ

	
    
	Vector3 velocity_;
	//	//Vector3 velociy_;
//	/// <summary>
//	/// 初期化
//	/// </summary>
	void Initialize(Model* model, const Vector3& position, const Vector3& velocity);
	//
//	/// <summary>
//	/// 更新
//	/// </summary>
	void Update();
//
//	/// <summary>
//	/// 描画
//	/// </summary>
	void Draw(ViewProjection viewProjection_);

private:
	//ワールドトランスホーム:
	WorldTransform worldTransform_;
	//モデルポインター
	Model* model_ = nullptr;
	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;
		//Enemy* enemy_ = nullptr;
};