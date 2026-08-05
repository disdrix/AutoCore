// =============================================================================
// GameUtils_ParseRagDollBoneCount_Inferred  (Ghidra: FUN_005f4380)
// -----------------------------------------------------------------------------
// Stable ID: aa_005f4380
// Address:   0x005f4380  (autoassault.exe, image base 0x400000)
// System:    GameUtils / ragdoll buffer parse
// Sealed:    2026-07-29 W27-H (live decompile + read_memory + analyze_function_complete)
// Dual:      A/B accept W27-H — sole caller GameUtils_createRagDoll; returns bone/slot count
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   SEH-framed wrapper that builds two short-lived parse/container objects from the
//   ragdoll buffer inputs, runs FUN_005f4230 to walk typed tokens and produce a count,
//   tears down the containers, and returns that count (EAX).
//
//   Sole live caller: GameUtils_createRagDoll @ 0x005f44c0 (call 0x005f45af), which
//   uses the return as expected bone/slot count (limit-checked < 0x21).
//
// ABI (sealed from bytes + decompile):
//   cdecl; 5 stack formals; EAX = count (uint32_t); plain RET after SEH teardown.
//   Prologue: PUSH -1; PUSH LAB_009a79e0; FS ExceptionList install; SUB ESP,0x1C; ...
//   Epilogue: POP ESI; POP EBX; restore ExceptionList; ADD ESP,0x28; RET
//   Body: 0x005f4380–0x005f441a (155 B inclusive RET; pad CC after)
//
// Callees:
//   FUN_005f3120  — construct/ref container from param_1/param_2 (fastcall ECX out-object)
//   FUN_00646d90  — construct second container from *(param_3+8)
//   FUN_005f4230  — token walk; returns count used by createRagDoll
//   FUN_00646dd0  — destroy second container
//   FUN_005f3160  — destroy first container
//
// Gaps:
//   Nested helper duals not OWN; product field English for containers; runtime open.
//   createRagDoll decompiler surface may show only 2 formals at call site — machine
//   pushes 5 (read_memory @ 0x005f4590..0x005f45b4); this unit's 5-formal decompile wins.
// =============================================================================

#include <stdint.h>

extern "C" {
  void FUN_005f3120(uint32_t a, uint32_t b);
  void FUN_005f3160(void);
  uint32_t FUN_005f4230(uint8_t *local_buf, uint32_t a, uint32_t b);
  void FUN_00646d90(uint32_t local_obj, uint32_t from_field);
  void FUN_00646dd0(void);
  void *ExceptionList;
  void LAB_009a79e0(void);
}

uint32_t FUN_005f4380(
    uint32_t param_1,
    uint32_t param_2,
    int param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  uint32_t uVar1;
  uint32_t local_20;
  uint8_t local_1c[16];
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;

  local_4 = (int)0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009a79e0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_005f3120(param_1, param_2);
  local_4 = 0;
  FUN_00646d90(local_20, *(uint32_t *)(param_3 + 8));
  /* SEH state byte = 1 */
  local_4 = (local_4 & ~0xff) | 1;
  uVar1 = FUN_005f4230(local_1c, param_4, param_5);
  local_4 = (int)(((uint32_t)local_4 >> 8) << 8);
  FUN_00646dd0();
  local_4 = (int)0xffffffff;
  FUN_005f3160();
  ExceptionList = pvStack_c;
  return uVar1;
}

// Named alias (no plate on this VA; inferred from sole caller GameUtils::createRagDoll)
uint32_t GameUtils_ParseRagDollBoneCount_Inferred(
    uint32_t param_1,
    uint32_t param_2,
    int param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  return FUN_005f4380(param_1, param_2, param_3, param_4, param_5);
}
