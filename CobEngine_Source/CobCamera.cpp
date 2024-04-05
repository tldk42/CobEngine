#include "CobCamera.h"

#include "CobApplication.h"

extern Cob::Application application;

namespace Cob
{
	Camera::Camera()
		: Component(EComponentType::Camera),
		  mViewTarget(nullptr),
		  mDistance(Math::Vector2::ZERO),
		  mResolution(Math::Vector2::ZERO),
		  mLookPosition(Math::Vector2::ZERO)
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
		if (mViewTarget)
		{
			const Transform* transform = mViewTarget->GetComponent<Transform>();
			mLookPosition = transform->GetPosition();
		}
		else
		{
			const Transform* cameraTransform = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTransform->GetPosition();
		}

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
