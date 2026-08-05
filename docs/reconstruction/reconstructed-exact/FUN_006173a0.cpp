// =============================================================================
// FUN_006173a0  (scaffold alias → Map_ConstructIntKeyNode_0x18)
// -----------------------------------------------------------------------------
// Stable ID: aa_006173a0
// Address:   0x006173a0–0x006173de  (autoassault.exe, image base 0x400000)
// System:    std map/set node construction (int-key 0x18 family)
// Generated: 2026-07-23 scaffold; dual A/B sealed 2026-07-29 W18-L
// Prefer:    Map_ConstructIntKeyNode_0x18.cpp (named clean; EAX return)
// Dual:      accept-with-gaps
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006173a0 @ 0x006173a0
// Stable ID: aa_006173a0
// Node ctor: operator_new(0x18); left/parent/right; key/mapped; color; isnil=0.
// ABI: RET 0x14; returns node* in EAX (decompiler void is wrong).

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: operator_new.
//  - Return sites: 1 (EAX).

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory body seal 2026-07-29.
 * - Shared by Map_InsertNodeAndRebalance_IntKey and 13 other insert sites.
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

extern "C" void *operator_new(std::uint32_t size);

// Returns node* in EAX (not reflected in historical decompiler void sig).
extern "C" std::uint32_t /* node* */ FUN_006173a0(
    std::uint32_t param_1,   // left*
    std::uint32_t param_2,   // parent*
    std::uint32_t param_3,   // right*
    std::uint32_t *param_4,  // IntPair* {key, mapped}
    std::uint8_t param_5)    // color
{
  std::uint32_t *puVar1;

  puVar1 = (std::uint32_t *)operator_new(0x18);
  if (puVar1 != (std::uint32_t *)0x0) {
    *puVar1 = param_1;
    puVar1[2] = param_3;
    puVar1[1] = param_2;
    puVar1[3] = *param_4;
    puVar1[4] = param_4[1];
    *(std::uint8_t *)(puVar1 + 5) = param_5;
    *(std::uint8_t *)((int)puVar1 + 0x15) = 0;
  }
  return (std::uint32_t)puVar1;
}
