#pragma once
//------------------------------------------------------------------------------
/**
    Fiber implementation header

    @copyright
    (C) 2020 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
namespace Fibers
{

class Fiber
{
public:

    /// constructor
    Fiber();
    /// construct from nullpointer
    Fiber(std::nullptr_t);
    /// constructor
    Fiber(void(*Function)(void*), void* context);
    /// copy constructor
    Fiber(const Fiber& rhs);
    /// destructor
    ~Fiber();
    /// assignment operator
    void operator=(const Fiber& rhs);

    /// convert thread to fiber
    static void ThreadToFiber(Fiber& fiber);
    /// convert fiber back to thread
    static void FiberToThread(Fiber& fiber);

    /// switch to this fiber
    void SwitchToFiber(Fiber& CurrentFiber);
private:
    void* handle;
    void* context;

};

} // namespace Fibers
