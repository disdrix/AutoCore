// =============================================================================
// Object_CacheAIProfileFields_TypeMask_Inferred  (Ghidra: FUN_004c9120)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c9120
// Address:   0x004c9120  (autoassault.exe, image base 0x400000)
// System:    Host AI profile / object cache (HBAI-related)
// Sealed:    2026-07-29 W27-H (live decompile + read_memory + analyze_function_complete)
// Dual:      A/B accept W27-H — profile field cache + map type-bit sealed
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Mid-object thiscall method (entered via MI adjustor thunks) that:
//     1) Calls FUN_005c8eb0 with this-0x3F0 (related subobject init/cache).
//     2) Resolves a profile/def block via MI/vbtable chain ending at +0x3c.
//     3) Copies a fixed set of profile fields into negative offsets from this.
//     4) Looks up key *(profile+0x4dc) in Host_AIProfileMap (FUN_00540890 +
//        Map_LowerBoundFindByIntKey_Isnil65 / FUN_004cbd50).
//     5) On hit: stores type bitmask 1<<(node+0x10 & 0x1f) at this-0x300.
//
// ABI (sealed):
//   __fastcall/thiscall; ECX = this (mid-object); void; frame SUB ESP,8; plain RET.
//   Prologue: 83 EC 08 56 8B F1 ...
//   Epilogue: 5E 83 C4 08 C3  (POP ESI; ADD ESP,8; RET)
//   Body: 0x004c9120–0x004c92e3 (452 B inclusive RET; pad CC after)
//
// Entry thunks (DATA vtable slots → adjustor JMP, not direct CALL):
//   0x004ccec0: 2B 49 FC E9 ... → JMP 0x004c9120  (vbtable adjust [ecx-4])
//   0x0053baa0: 2B 49 FC; SUB ECX,0x8A0; JMP 0x004c9120
//   Vtable DATA: 0x009cbb80, 0x009cfaa0
//
// Callees:
//   FUN_005c8eb0
//   Host_AIProfileMap_GetOrReset (FUN_00540890) x2
//   Map_LowerBoundFindByIntKey_Isnil65 (FUN_004cbd50)
//
// Sibling: FUN_004c9430 also uses +0x4dc key + same map pair; that unit creates
//   CVOGHB* drivers by type. This unit only caches fields + type mask bit.
//
// Gaps:
//   Product English for each profile field; full MI class layout; runtime open.
// =============================================================================

#include <stdint.h>

// External callees (Ghidra names). thiscall ECX surfaces may be elided in decompiler.
extern void FUN_005c8eb0(void);
extern int FUN_00540890(char forceReset);
extern void FUN_004cbd50(int *pOutIt, uint32_t *pKey);

void __fastcall FUN_004c9120(int param_1)
{
  int iVar1;
  int *piVar2;
  uint32_t *puVar3;
  uint32_t local_8;
  int local_4;

  /* Bytes: LEA ECX,[ESI-0x3F0]; CALL FUN_005c8eb0 — decompiler omits ECX rebuild. */
  FUN_005c8eb0();

  *(uint32_t *)(param_1 + -0x310) =
      *(uint32_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4c0);
  *(uint32_t *)(param_1 + -0x308) =
      *(uint32_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4d0);
  *(int *)(param_1 + -0x3b0) =
      (int)*(int16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 +
                                         param_1) +
                                0x3c) +
                        0x4ee);
  *(uint32_t *)(param_1 + -0x3e0) =
      *(uint32_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4d8);
  *(uint16_t *)(param_1 + -0x3c2) =
      *(uint16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4f0);
  *(uint16_t *)(param_1 + -0x3c4) =
      *(uint16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4f2);
  *(uint16_t *)(param_1 + -0x3c0) =
      *(uint16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4f4);
  *(uint16_t *)(param_1 + -0x3be) =
      *(uint16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4f6);
  *(float *)(param_1 + -0x2a4) =
      (float)(int)*(int16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 +
                                               param_1) +
                                       0x3c) +
                               0x512);
  *(float *)(param_1 + -0x2a0) =
      (float)(int)*(int16_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 +
                                               param_1) +
                                       0x3c) +
                               0x510);
  local_8 =
      *(uint32_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) +
                            0x3c) +
                    0x4dc);
  puVar3 = &local_8;
  piVar2 = &local_4;
  /* Host_AIProfileMap_GetOrReset(0) — ECX = host (callers: DAT_00b041fc family). */
  FUN_00540890(0);
  /* Map_LowerBoundFindByIntKey_Isnil65 — ECX = map from prior get. */
  FUN_004cbd50(piVar2, puVar3);
  iVar1 = FUN_00540890(0);
  if (local_4 != *(int *)(iVar1 + 4)) {
    *(int *)(param_1 + -0x300) = 1 << (*(uint8_t *)(local_4 + 0x10) & 0x1f);
  }
  return;
}
