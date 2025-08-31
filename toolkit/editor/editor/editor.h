#pragma once
//------------------------------------------------------------------------------
/**
    @class  Editor::Editor

    Front end for the Nebula editor

    (C) 2020 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "util/string.h"
#include "util/guid.h"
#include "game/category.h"
#include "game/gameserver.h"

namespace Editor
{

constexpr uint32_t WORLD_EDITOR = uint32_t('EWLD');
constexpr uint32_t TIMESOURCE_EDITOR = uint32_t('TsEd');

typedef Game::Entity Entity;

struct Editable
{
    /// guid
    Util::Guid guid;
    /// name
    Util::String name;
    /// template, if any
    Game::TemplateId templateId;
    /// which game entity in the game database the editable is associated with
    Game::Entity gameEntity = Game::Entity::Invalid();
    /// version of editable. Bump if something has changed about the entity.
    uint64_t version = 0;

};

struct State
{
    /// contains the world state for the editor
    Game::World* editorWorld;
    /// maps from editor entity index to editable
    Util::Array<Editable> editables;
};

/// Create the editor
void Create();

/// Start the editor
void Start();

/// Destroy the editor
void Destroy();

/// Start playing the game.
void PlayGame();

/// Pause the game.
void PauseGame();

/// Stop the game
void StopGame();

/// global editor state
extern State state;

} // namespace Editor
