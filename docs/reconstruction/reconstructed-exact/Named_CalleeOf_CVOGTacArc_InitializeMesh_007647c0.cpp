// Named_CalleeOf_CVOGTacArc_InitializeMesh_007647c0 — REJECTED scaffold alias
// Canonical: Host_RegisterObjectAndAccumulateBounds (aa_007647c0)
// Multi-caller host helper; not TacArc-only. See Host_RegisterObjectAndAccumulateBounds.cpp

#include <cstdint>
extern "C" void Host_RegisterObjectAndAccumulateBounds(void* host, void* obj);
extern "C" void Named_CalleeOf_CVOGTacArc_InitializeMesh_007647c0(void* host, void* obj)
{
    Host_RegisterObjectAndAccumulateBounds(host, obj);
}
