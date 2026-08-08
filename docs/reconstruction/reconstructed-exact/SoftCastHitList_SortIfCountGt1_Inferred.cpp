// =============================================================================
// SoftCastHitList_SortIfCountGt1_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a060
// Address:   0x0048a060 – 0x0048a082 inclusive (35 B / 0x23)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-116 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0048a060
// =============================================================================
//
// PURPOSE
//   Gate: if soft-cast hit-list count > 1, full-range quicksort the hit array
//   via FUN_00489f20 (elem size 0x30, ascending float key @ elem+0x14).
//   Sole caller: Client_InteractWorldClickHub (0x00925820) after soft-cast
//   fill (FUN_0055e1e0 → FUN_006ca890). Enables nearest-first walk / pick.
//
// ABI (sealed)
//   thiscall: ECX = SoftCastHitList*
//   void return; bare RET (C3)
//   Stack local: this with low byte forced 0, passed as 4th arg to sort
//                (recursive pass-through only; not used in compare).
//
// LAYOUT (this)
//   +0x10  void*  array_base
//   +0x14  int    count
//
// ODD BEHAVIOR PRESERVED
//   - 4th arg = (uint32_t)this & 0xFFFFFF00 (low-byte clear of this pointer).
//   - No-op when count is 0 or 1 (includes empty list).
//
// READABILITY
//   - Decompiler showed __fastcall(uint); assembly seals ECX=this.
//   - Callee name remains FUN_00489f20 until MEGA-115 dual promotes it.
// =============================================================================

#include <cstdint>

// Forward: hit-list qsort core @ 0x00489f20 (MEGA-115 OWN residual).
// cdecl: (base, lo, hi, unused_cookie); elem stride 0x30; key float @ +0x14.
extern "C" void __cdecl FUN_00489f20(void *array_base, int lo, int hi,
                                     uint32_t sort_cookie);

struct SoftCastHitList {
  void *vtbl;            // +0x00
  uint32_t _pad_04[3];   // +0x04 .. +0x0C (not read here)
  void *array_base;      // +0x10
  int count;             // +0x14
  // inline hit storage follows in ctor FUN_0040c410 (not accessed here)
};

// ECX = this; void; bare RET
void __thiscall SoftCastHitList_SortIfCountGt1_Inferred(SoftCastHitList *self)
{
  // PUSH ECX; MOV byte ptr [ESP], 0  →  self & 0xFFFFFF00
  uint32_t sort_cookie =
      static_cast<uint32_t>(reinterpret_cast<uintptr_t>(self)) & 0xFFFFFF00u;

  int count = self->count; // [ECX+0x14]

  if (count > 1) {
    // PUSH cookie; PUSH count-1; PUSH 0; PUSH array_base; CALL FUN_00489f20
    FUN_00489f20(self->array_base, /*lo=*/0, /*hi=*/count - 1, sort_cookie);
  }
  // POP ECX; RET
}
