// =============================================================================
// PodCopyBlock_0x40_Thiscall_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb040
// Address:   0x005eb040  (autoassault.exe, image base 0x400000)
// Range:     0x005eb040–0x005eb0a6 inclusive (103 B / 0x67); pad CC after
// System:    interaction-activation (shared 0x40 POD block copy)
// Generated: 2026-08-05 R12-036 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Leaf thiscall POD copy of exactly 16 dwords (0x40 bytes):
//     dest[i] = src[i] for i in 0..15
//   No null check, no overlap handling, no callees.
//
// ABI (sealed)
//   thiscall: ECX = dest*, stack = src*, RET 4
//   EAX = dest on return (prolog MOV EAX,ECX; preserved)
//   Decompiler may show void — incorrect; EAX is dest at RET.
//
// CALL SITES (sample; 29 UNCONDITIONAL_CALL total)
//   FUN_005eb210 (VOGPhysics_QueryObject_BaseCtor_Inferred) @ 0x005eb2a1
//     dest = self+0x80, src = params+0x20
//   FUN_005eb0b0 @ 0x005eb0c8; FUN_005eb0e0 @ 0x005eb0f7
//   FUN_005f0210 (multi), FUN_005f1ec0, FUN_00662510, FUN_00668d30, …
//
// DISTINCT FROM
//   FUN_005eb210              — query-object base ctor (caller of this)
//   StdVector PodCopy 0x10/…  — register-ABI single-element leaves
//   memcpy / REP MOVSD helpers — variable-length / string copies
//
// RETIRED SCAFFOLD
//   Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005eb040
// =============================================================================

#include <cstdint>

// Ghidra-faithful thiscall body (ECX = dest).
uint32_t * __thiscall PodCopyBlock_0x40_Thiscall_Inferred(
    uint32_t *dest /* ECX */,
    const uint32_t *src /* stack */)
{
  // Assembly: MOV EAX,ECX; MOV ECX,[ESP+4] then 16 dword pairs.
  // Decompiler lists dest as param_1 / this; src as param_2.
  dest[0]  = src[0];
  dest[1]  = src[1];
  dest[2]  = src[2];
  dest[3]  = src[3];
  dest[4]  = src[4];
  dest[5]  = src[5];
  dest[6]  = src[6];
  dest[7]  = src[7];
  dest[8]  = src[8];
  dest[9]  = src[9];
  dest[10] = src[10];
  dest[11] = src[11];
  dest[12] = src[12];
  dest[13] = src[13];
  dest[14] = src[14];
  dest[15] = src[15];  // +0x3C
  return dest;         // EAX; RET 4
}

// Ghidra twin name
uint32_t * __thiscall FUN_005eb040(uint32_t *dest /* ECX */,
                                   const uint32_t *src /* stack */)
{
  return PodCopyBlock_0x40_Thiscall_Inferred(dest, src);
}
