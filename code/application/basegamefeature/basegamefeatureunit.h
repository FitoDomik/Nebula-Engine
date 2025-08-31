#pragma once
//------------------------------------------------------------------------------
/**
    @class BaseGameFeature::BaseGameFeatureUnit
    
    The BaseGameFeatureUnit creates everything to allow load and run a game level.
    Therefore it creates managers to allow creation and handling of
    entities, components and processors. 

    @copyright
    (C) 2007 Radon Labs GmbH
    (C) 2013-2020 Individual contributors, see AUTHORS file
*/
#include "game/featureunit.h"
#include "core/cvar.h"

/**
 *  @defgroup BaseGameComponents Base Game Components
 *  Components that come as part of the base game feature.
 */

//------------------------------------------------------------------------------
namespace BaseGameFeature
{

class BaseGameFeatureUnit : public Game::FeatureUnit    
{
    __DeclareClass(BaseGameFeatureUnit)
    __DeclareSingleton(BaseGameFeatureUnit)

public:

    /// constructor
    BaseGameFeatureUnit();
    /// destructor
    virtual ~BaseGameFeatureUnit();

    /// called upon attaching the feature unit
    void OnAttach() override;

    /// Called upon activation of feature unit
    void OnActivate() override;
    /// Called upon deactivation of feature unit
    void OnDeactivate() override;
         
    /// called at the end of the feature trigger cycle
    void OnEndFrame() override;
    /// called when game debug visualization is on
    void OnRenderDebug() override;
    /// called at the beginning of a frame
    void OnFrame() override;
    
protected:
    Ptr<Game::Manager> blueprintManager;
    Ptr<Game::Manager> timeManager;
    Core::CVar* cl_debug_worlds;
};

} // namespace BaseGameFeature
//------------------------------------------------------------------------------
