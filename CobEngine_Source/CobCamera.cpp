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
		// ���� Ÿ���� ������ Ÿ������ lookPosition�� ����
		if (mViewTarget)
		{
			const Transform* transform = mViewTarget->GetComponent<Transform>();
			mLookPosition = transform->GetPosition();
		}
		// Ÿ���� ������ �ڱ� �ڽ��� ��ġ�� ����
		else
		{
			const Transform* cameraTransform = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTransform->GetPosition();
		}

		// Ÿ�꿡�� ȭ�� �߾��� �� ������ ���� (ī�޶󿡼� Ÿ���� ���ϴ� ����)
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
