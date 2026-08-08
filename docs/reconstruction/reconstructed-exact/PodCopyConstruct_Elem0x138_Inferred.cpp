// =============================================================================
// PodCopyConstruct_Elem0x138_Inferred  (FUN_00408880)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408880
// Address:   0x00408880–0x004088ef inclusive (112 B / 0x70); next fn @ 0x004088f0
// System:    util / POD construct — element width 0x138 (Logic-UI event queue)
// Generated: 2026-08-04 WQ9H-I dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   POD-copy construct one 0x138-byte element: dest ← src.
//   Used by LogicUiEventQueue_InsertN (stack value buffer) and placement
//   wrapper FUN_0040a6e0.
//
// ABI: __thiscall; ECX = dest; stack const void* src; void; RET 4.
// Leaf: no callees.
//
// Dual: reviews/A|B_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md

#include <cstdint>
#include <cstring>

static constexpr std::uint32_t kElemBytes = 0x138u;

// __thiscall RET 4
extern "C" void __thiscall PodCopyConstruct_Elem0x138_Inferred(
    void* dest,          // ECX
    const void* src)     // Stack[0x4]
{
  // Retail shape: 14 unrolled dword stores (0x00..0x37) then
  //   lea esi,[src+0x38]; lea edi,[dest+0x38]; mov ecx,0x40; rep movsd
  // Equivalent single transfer of 0x138 bytes:
  std::memcpy(dest, src, kElemBytes);
}

// Scaffold alias
extern "C" void __thiscall FUN_00408880(void* dest, const void* src)
{
  PodCopyConstruct_Elem0x138_Inferred(dest, src);
}
