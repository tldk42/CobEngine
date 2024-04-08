#include "CobCamera.h"

#include "CobApplication.h"

extern Cob::Application application;

namespace Cob
{
	Camera::Camera()
		: Component(EComponentType::Camera),
		  mViewTarget(nullptr),
		  mDistance(Vector2::ZERO),
		  mResolution(Vector2::ZERO),
		  mLookPosition(Vector2::ZERO)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Initialize()
	{
		mResolution.X = application.GetWidth();
		mResolution.Y = application.GetHeight();
	}

	void Camera::Update()
	{
		// 지정 타깃이 있으면 타깃으로 lookPosition을 변경
		if (mViewTarget)
		{
			const Transform* transform = mViewTarget->GetComponent<Transform>();
			mLookPosition = transform->GetPosition();
		}
		// 타깃이 없으면 자기 자신의 위치로 설정
		else
		{
			const Transform* cameraTransform = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTransform->GetPosition();
		}

		// 타깃에서 화면 중앙을 뺀 값으로 설정 (카메라에서 타깃을 향하는 방향)
		mDistance = mLookPosition - (mResolution / 2.f);
	}

	void Camera::LateUpdate()
	{
		Component::LateUpdate();
	}

	void Camera::Render(HDC Hdc)
	{
		Component::Render(Hdc);
	}
}
