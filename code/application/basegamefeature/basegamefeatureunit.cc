//------------------------------------------------------------------------------
//  game/basegamefeature.cc
//  (C) 2007 Radon Labs GmbH
//  (C) 2013-2020 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------

#include "basegamefeature/basegamefeatureunit.h"
#include "appgame/gameapplication.h"
#include "core/factory.h"
#include "game/gameserver.h"
#include "io/ioserver.h"
#include "io/console.h"
#include "managers/blueprintmanager.h"
#include "managers/timemanager.h"
#include "imgui.h"
#include "basegamefeature/components/basegamefeature.h"
#include "components/position.h"
#include "components/orientation.h"
#include "components/scale.h"
#include "components/velocity.h"

namespace BaseGameFeature
{
__ImplementClass(BaseGameFeature::BaseGameFeatureUnit, 'GAGF', Game::FeatureUnit);
__ImplementSingleton(BaseGameFeatureUnit);

using namespace App;
using namespace Game;

//------------------------------------------------------------------------------
/**
*/
BaseGameFeatureUnit::BaseGameFeatureUnit()
{
    __ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
BaseGameFeatureUnit::~BaseGameFeatureUnit()
{
    __DestructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
void
BaseGameFeatureUnit::OnAttach()
{
    this->RegisterComponentType<Game::Entity>();
    this->RegisterComponentType<Game::Position>();
    this->RegisterComponentType<Game::Orientation>();
    this->RegisterComponentType<Game::Scale>();
    this->RegisterComponentType<Game::IsActive>();
    this->RegisterComponentType<Game::Static>();
    this->RegisterComponentType<Game::Velocity>();
    this->RegisterComponentType<Game::AngularVelocity>();
}

//------------------------------------------------------------------------------
/**
*/
void
BaseGameFeatureUnit::OnActivate()
{
    FeatureUnit::OnActivate();

    this->blueprintManager = BlueprintManager::Create();
    this->timeManager = TimeManager::Create();

    this->AttachManager(this->blueprintManager);
    this->AttachManager(this->timeManager);

    this->cl_debug_worlds = Core::CVarCreate(Core::CVar_Int, "cl_debug_worlds", "1", "Enable world debugging");
}

//------------------------------------------------------------------------------
/**
*/
void
BaseGameFeatureUnit::OnDeactivate()
{
    this->RemoveManager(this->blueprintManager);
    this->RemoveManager(this->timeManager);

    this->blueprintManager = nullptr;
    this->timeManager = nullptr;

    FeatureUnit::OnDeactivate();
}

//------------------------------------------------------------------------------
/**
*/
void
BaseGameFeatureUnit::OnRenderDebug()
{
    //for (uint worldIndex = 0; worldIndex < numWorlds; worldIndex++)
    //    Game::World* world = Game::GameServer::Instance()->state.worlds[worldIndex];

    if (Core::CVarReadInt(this->cl_debug_worlds) == 0)
        return;
        
    ImGui::Begin("World inspector");
    {
        static int selectedWorld = 0;

		ImGui::InputInt("World index", &selectedWorld);

		selectedWorld = Math::clamp(selectedWorld, 0, 31);

		Game::World* world = Game::GameServer::Instance()->state.worlds[selectedWorld];

		if (world != nullptr)
        {
            world->RenderDebug();
        }
        else
        {
            ImGui::TextDisabled("Invalid world index");
        }
    }
    ImGui::End();

    FeatureUnit::OnRenderDebug();
}

//------------------------------------------------------------------------------
/**
*/
void
BaseGameFeatureUnit::OnEndFrame()
{
    FeatureUnit::OnEndFrame();
}

//------------------------------------------------------------------------------
/**
*/
void
BaseGameFeatureUnit::OnFrame()
{
    FeatureUnit::OnFrame();
}

} // namespace Game
