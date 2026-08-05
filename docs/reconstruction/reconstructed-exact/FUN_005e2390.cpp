// =============================================================================
// FUN_005e2390
// -----------------------------------------------------------------------------
// Stable ID: aa_005e2390
// Address:   0x005e2390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e2390 @ 0x005e2390
// Stable ID: aa_005e2390
// Embedded strings (evidence for future rename):
//   - "ed_riverhandle.geo"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004cd220, FUN_005e2390, FUN_00764030, FUN_00989e00.
//  - Strings: "ed_riverhandle.geo".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_005e2390(int param_1)



{

  int *piVar1;

  int iVar2;

  uint8_t *puVar3;

  uint32_t /* width from decompiler */ unaff_EDI;

  float10 fVar4;

  void *local_1c;

  uint32_t /* width from decompiler */ local_18;

  void *local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a750b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  fVar4 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)(param_1 + 0x140),*(uint32_t /* width from decompiler */ *)(param_1 + 0x148));

  *(float *)(param_1 + 0x144) = (float)fVar4;

  local_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x140);

  local_10 = *(void **)(param_1 + 0x148);

  local_14 = (void *)(*(float *)(param_1 + 0x170) + *(float *)(param_1 + 0x144));

  if (**(int **)(param_1 + 0x154) == 0) {

    local_1c = operator_new(0x14c);

    local_4 = 0;

    if (local_1c == (void *)0x0) {

      piVar1 = (int *)0x0;

    }

    else {

      piVar1 = (int *)FUN_00764030();

    }

    local_4 = 0xffffffff;

    FUN_00989e00(&local_1c,"ed_riverhandle.geo");

    (**(code **)(*piVar1 + 0x5c))(&local_1c);

    iVar2 = (**(code **)(*piVar1 + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc) = 0xffffffff;

    *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90) = unaff_EDI;

    *(void **)(iVar2 + 0x94) = local_1c;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98) = local_18;

    puVar3 = operator_new(0xc);

    *(int *)(puVar3 + 4) = param_1;

    *puVar3 = 3;

    *(uint32_t /* width from decompiler */ *)(puVar3 + 8) = 0;

    piVar1[0x1e] = (int)puVar3;

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x154) = piVar1;

    ExceptionList = local_14;

    return;

  }

  iVar2 = (**(code **)(*(int *)**(int **)(param_1 + 0x154) + 0x10))(3);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc) = 0xffffffff;

  *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;

  *(void **)(iVar2 + 0x90) = local_1c;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x94) = local_18;

  *(void **)(iVar2 + 0x98) = local_14;

  ExceptionList = local_10;

  return;

}
