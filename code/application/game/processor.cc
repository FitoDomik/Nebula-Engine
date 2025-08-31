//------------------------------------------------------------------------------
//  @file processor.cc
//  @copyright (C) 2022 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------

#include "processor.h"
#include "gameserver.h"
#include "basegamefeature/components/basegamefeature.h"

namespace Game
{

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder::ProcessorBuilder(World* world, Util::StringAtom processorName)
    : world(world),
      name(processorName),
      onEvent("OnBeginFrame")
{
    this->filterBuilder = FilterBuilder();
}

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder&
ProcessorBuilder::Excluding(std::initializer_list<ComponentId> components)
{
    this->filterBuilder.Excluding(components);
    return *this;
}

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder&
ProcessorBuilder::On(Util::StringAtom eventName)
{
    this->onEvent = eventName;

    if (eventName == "OnActivate"_atm)
    {
        this->filterBuilder.Excluding<Game::IsActive>();
    }

    return *this;
}

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder&
ProcessorBuilder::Async()
{
    this->async = true;
    return *this;
}

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder&
ProcessorBuilder::OnlyModified()
{
    this->onlyModified = true;
    return *this;
}

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder&
ProcessorBuilder::Order(int order)
{
    this->order = order;
    return *this;
}

//------------------------------------------------------------------------------
/**
*/
ProcessorBuilder&
ProcessorBuilder::RunInEditor()
{
#ifdef WITH_NEBULA_EDITOR
    this->runInEditor = true;
#endif
    return *this;
}

//------------------------------------------------------------------------------
/**
*/
Processor*
ProcessorBuilder::Build()
{
    Processor* processor = new Processor();
    processor->name = this->name.AsString();
    processor->async = this->async;
    processor->order = this->order;
    processor->filter = this->filterBuilder.Build();

#ifdef WITH_NEBULA_EDITOR
    processor->runInEditor = this->runInEditor;
#endif

    if (this->onlyModified)
        processor->callback = this->funcModified;
    else
        processor->callback = this->func;

    FrameEvent* frameEvent = world->GetFramePipeline().GetFrameEvent(this->onEvent);
    n_assert(frameEvent != nullptr);
    frameEvent->AddProcessor(processor);
    return processor;
}

} // namespace Game

