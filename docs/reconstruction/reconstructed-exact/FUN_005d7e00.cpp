// =============================================================================
// FUN_005d7e00
// -----------------------------------------------------------------------------
// Stable ID: aa_005d7e00
// Address:   0x005d7e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d7e00 @ 0x005d7e00
// Stable ID: aa_005d7e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004e8a40, FUN_005d7e00, NPC_TryCastSkillFromSet.
//  - Return sites: 1.

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

void __fastcall FUN_005d7e00(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  float *pfVar3;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  NPC_TryCastSkillFromSet(param_1,2);

  if (*(int *)(param_1[6] + 0xa0) == 0) {

    (**(code **)(*param_1 + 0x1c))();

  }

  iVar1 = param_1[0x19];

  if (*(char *)(iVar1 + 0x305) == '\0') {

    if (*(int *)(iVar1 + 8) == 0) {

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x94 + iVar1);

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0x30);

    }

    uStack_20 = *puVar2;

    uStack_1c = puVar2[1];

    uStack_18 = puVar2[2];

    uStack_14 = puVar2[3];

    FUN_004e8a40(&uStack_20,&fStack_30);

    iVar1 = param_1[0x19];

    if (*(int *)(iVar1 + 8) == 0) {

      pfVar3 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);

    }

    else {

      pfVar3 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);

    }

    fStack_30 = *pfVar3 + fStack_30 * DAT_00aaa7ac;

    fStack_2c = pfVar3[1] + fStack_2c * DAT_00aaa7ac;

    fStack_28 = pfVar3[2] + fStack_28 * DAT_00aaa7ac;

    fStack_24 = pfVar3[3] + fStack_24 * DAT_00aaa7ac;

    (**(code **)(*param_1 + 0x4c))(&fStack_30,0);

  }

  return;

}
