#pragma once
//------------------------------------------------------------------------------
/**
    @class Shared::CameraSettings
    
    Helper class for handling camera projection and related settings
    
    @copyright
    (C) 2009 Radon Labs GmbH
    (C) 2013-2020 Individual contributors, see AUTHORS file
*/
#include "math/mat4.h"
#include "math/vec2.h"
#include "math/frustum.h"

//------------------------------------------------------------------------------
namespace Graphics
{
class CameraSettings
{
public:
    /// default constructor
    CameraSettings();

    /// setup a perspective view volume
    void SetupPerspectiveFov(float fov, float aspect, float zNear, float zFar);
    /// setup an orthogonal projection transform
    void SetupOrthogonal(float w, float h, float zNear, float zFar);

    /// get projection matrix
    const Math::mat4& GetProjTransform() const;
    /// get the inverse projection matrix
    const Math::mat4& GetInvProjTransform() const;
    /// get focal length (computed from fov and aspect ratio)
    const Math::vec2& GetFocalLength() const;

    /// return true if this is a perspective projection
    bool IsPerspective() const;
    /// return true if this is an orthogonal transform
    bool IsOrthogonal() const;
    /// get near plane distance
    float GetZNear() const;
    /// get far plane distance
    float GetZFar() const;
    /// get field-of-view (only if perspective)
    float GetFov() const;
    /// get aspect ration (only if perspective)
    float GetAspect() const;
    /// get width of near plane
    float GetNearWidth() const;
    /// get height of near plane
    float GetNearHeight() const;
    /// get width of far plane
    float GetFarWidth() const;
    /// get height of far plane
    float GetFarHeight() const;
    
private:

    Math::mat4 projMatrix;
    Math::mat4 invProjMatrix;

    bool isPersp;
    float zNear;
    float zFar;
    float fov;
    float aspect;
    float nearWidth;
    float nearHeight;
    float farWidth;
    float farHeight;
    Math::vec2 focalLength;
};

//------------------------------------------------------------------------------
/**
*/
inline const Math::mat4&
CameraSettings::GetProjTransform() const
{
    return this->projMatrix;
}

//------------------------------------------------------------------------------
/**
*/
inline const Math::mat4&
CameraSettings::GetInvProjTransform() const
{
    return this->invProjMatrix;
}

//------------------------------------------------------------------------------
/**
*/
inline bool
CameraSettings::IsPerspective() const
{
    return this->isPersp;
}

//------------------------------------------------------------------------------
/**
*/
inline bool
CameraSettings::IsOrthogonal() const
{
    return !this->isPersp;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetZNear() const
{
    return this->zNear;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetZFar() const
{
    return this->zFar;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetFov() const
{
    return this->fov;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetAspect() const
{
    return this->aspect;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetNearWidth() const
{
    return this->nearWidth;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetNearHeight() const
{
    return this->nearHeight;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetFarWidth() const
{
    return this->farWidth;
}

//------------------------------------------------------------------------------
/**
*/
inline float
CameraSettings::GetFarHeight() const
{
    return this->farHeight;
}

//------------------------------------------------------------------------------
/**
*/
inline const Math::vec2&
CameraSettings::GetFocalLength() const
{
    return this->focalLength;
}

} // namespace Graphics
//------------------------------------------------------------------------------
    