// =============================================================================
// FUN_005e71d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e71d0
// Address:   0x005e71d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e71d0 @ 0x005e71d0
// Stable ID: aa_005e71d0
// Embedded strings (evidence for future rename):
//   - "ed_roadhandle.geo"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004cd220, FUN_005e71d0, FUN_00764030, FUN_00989e00.
//  - Strings: "ed_roadhandle.geo".
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

void __fastcall FUN_005e71d0(void *param_1)



{

  int iVar1;

  uint8_t *puVar2;

  void *unaff_EBX;

  int *piVar3;

  float10 fVar4;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a76cb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_10 = param_1;

  fVar4 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)((int)param_1 + 0x140),

                                *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x148));

  *(float *)((int)param_1 + 0x144) = (float)fVar4;

  piVar3 = (int *)0x0;

  if (**(int **)((int)param_1 + 0x154) == 0) {

    local_10 = operator_new(0x14c);

    local_4 = 0;

    if (local_10 != (void *)0x0) {

      piVar3 = (int *)FUN_00764030();

    }

    local_4 = 0xffffffff;

    FUN_00989e00(&local_10,"ed_roadhandle.geo");

    (**(code **)(*piVar3 + 0x5c))(&local_10);

    iVar1 = (**(code **)(*piVar3 + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x140);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x144);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x148);

    puVar2 = operator_new(0xc);

    *(void **)(puVar2 + 4) = param_1;

    *puVar2 = 2;

    *(uint32_t /* width from decompiler */ *)(puVar2 + 8) = 0;

    piVar3[0x1e] = (int)puVar2;

    **(uint32_t /* width from decompiler */ **)((int)param_1 + 0x154) = piVar3;

    ExceptionList = unaff_EBX;

    return;

  }

  iVar1 = (**(code **)(*(int *)**(int **)((int)param_1 + 0x154) + 0x10))(3);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

  *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x140);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x144);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x148);

  ExceptionList = local_10;

  return;

}
