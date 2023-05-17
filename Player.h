#pragma once
#include "Model.h"
#include "WorldTransform.h"
class Player
{
	/// <summary>
	/// 自キャラ
	/// </summary>
public:
	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model,uint32_t textureHandle);

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
	 Player* player_ = nullptr;
	//
	
};







