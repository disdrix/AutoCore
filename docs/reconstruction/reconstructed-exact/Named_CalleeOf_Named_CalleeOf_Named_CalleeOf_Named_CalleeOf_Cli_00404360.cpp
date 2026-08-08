// =============================================================================
// RETIRED SCAFFOLD ALIAS — aa_00404360
// -----------------------------------------------------------------------------
// Former auto plate: Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404360
// Retired: 2026-08-05 R10-021 OWN-ONLY dual
// Reason: chain-of-caller Client/NotifyActiveMission plate only; unit is shared
//         MSVC _Tree node construct (no product mission semantics).
// Canonical: StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred
// Ghidra:    FUN_00404360 @ 0x00404360
// See:       StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.cpp
//            docs/agents/task-dual-ab-00404360-r10-report.md
// =============================================================================

#include <cstdint>

struct NodeIsnil31_Val32;

extern "C" void StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
    NodeIsnil31_Val32* node,
    NodeIsnil31_Val32* left,
    NodeIsnil31_Val32* parent,
    NodeIsnil31_Val32* right,
    const std::uint32_t* value8,
    std::uint8_t color);

// Keep old symbol linkable as thin redirect for any residual references.
extern "C" void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404360(
    NodeIsnil31_Val32* node,
    NodeIsnil31_Val32* left,
    NodeIsnil31_Val32* parent,
    NodeIsnil31_Val32* right,
    const std::uint32_t* value8,
    std::uint8_t color)
{
  StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
      node, left, parent, right, value8, color);
}
