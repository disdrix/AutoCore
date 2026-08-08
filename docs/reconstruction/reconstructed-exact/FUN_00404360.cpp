// =============================================================================
// FUN_00404360  (scaffold twin of StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404360
// Address:   0x00404360–0x0040438C exclusive (44 B / 0x2C); epilogue RET 0xC
// System:    MSVC std::_Tree node construct — Val32 payload, isnil@+0x31
// Generated: 2026-08-05 R10-021 dual seal (scaffold 2026-07-23 refreshed)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred
// =============================================================================

#include <cstdint>

// Forward-declare same layout as named unit.
struct NodeIsnil31_Val32 {
  NodeIsnil31_Val32* left;
  NodeIsnil31_Val32* parent;
  NodeIsnil31_Val32* right;
  std::uint32_t val[8];
  std::uint8_t color;
  std::uint8_t isnil;
};

extern "C" void StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
    NodeIsnil31_Val32* node,
    NodeIsnil31_Val32* left,
    NodeIsnil31_Val32* parent,
    NodeIsnil31_Val32* right,
    const std::uint32_t* value8,
    std::uint8_t color);

// Ghidra symbol alias — same body as named unit.
extern "C" void FUN_00404360(
    NodeIsnil31_Val32* node,          // EAX (Ghidra: in_EAX)
    NodeIsnil31_Val32* left,          // ECX (param_1)
    NodeIsnil31_Val32* parent,        // EDX (param_2)
    NodeIsnil31_Val32* right,         // stack (param_3)
    const std::uint32_t* value8,      // stack (param_4)
    std::uint8_t color)               // stack (param_5)
{
  StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred(
      node, left, parent, right, value8, color);
}
