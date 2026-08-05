// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004930b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004930b0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004930b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "sky_box.geo". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "sky_box.geo"
//   - "sky_box.anm"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×9, return×4.
//  - Notable callees: FUN_0048ea00×2, FUN_00989e00×2, FUN_0040d4f0, FUN_00490c60, FUN_004930b0, FUN_0074d420, FUN_0074d750, FUN_0074e6c0.
//  - Strings: "sky_box.geo"; "sky_box.anm".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_004930b0(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  float10 fVar4;

  void *pvVar5;

  uint8_t local_18 [4];

  void *pvStack_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0b71;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0048ea00();

  local_10 = operator_new(0x14c);

  local_4 = 0;

  if (local_10 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00764030();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = uVar2;

  local_4 = 0xffffffff;

  FUN_00989e00(local_18,"sky_box.geo");

  iVar3 = (**(code **)(**(int **)(param_1 + 0x94) + 0x5c))(local_18);

  if (iVar3 < 0) {

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x94) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x94))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

    ExceptionList = local_10;

    return;

  }

  FUN_00490c60();

  pvStack_14 = operator_new(0x78);

  puStack_8 = (uint8_t *)0x1;

  if (pvStack_14 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0074ed90();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = uVar2;

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_00989e00(local_18,"sky_box.anm");

  iVar3 = FUN_0074ee40(local_18);

  if (iVar3 < 0) {

    pvVar5 = *(void **)(param_1 + 0x180);

    if (pvVar5 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar5);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

    ExceptionList = local_10;

    return;

  }

  fVar4 = (float10)FUN_0079a110();

  FUN_0074e910(0,(float)fVar4);

  FUN_0074e6c0(0x3911a2b4);

  pvStack_14 = operator_new(0x5c);

  puStack_8 = (uint8_t *)0x2;

  if (pvStack_14 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0074d750();

  }

  puStack_8 = (uint8_t *)0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = uVar2;

  pvStack_14 = operator_new(0x14);

  puStack_8 = (uint8_t *)0x3;

  if (pvStack_14 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0040d4f0();

  }

  puStack_8 = (uint8_t *)0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = uVar2;

  FUN_0074d420(*(uint32_t /* width from decompiler */ *)(param_1 + 0x94));

  pvVar5 = (void *)0x0;

  (**(code **)(**(int **)(param_1 + 0x188) + 4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x184));

  (**(code **)(**(int **)(param_1 + 0x188) + 0xc))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x180));

  cVar1 = (**(code **)(**(int **)(param_1 + 0x188) + 0x18))

                    (*(uint32_t /* width from decompiler */ *)(param_1 + 0x180),0,0x3f800000);

  if (cVar1 == '\0') {

    FUN_0048ea00();

  }

  ExceptionList = pvVar5;

  return;

}
