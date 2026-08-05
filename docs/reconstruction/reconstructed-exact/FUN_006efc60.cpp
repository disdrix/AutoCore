// =============================================================================
// FUN_006efc60
// -----------------------------------------------------------------------------
// Stable ID: aa_006efc60
// Address:   0x006efc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006efc60 @ 0x006efc60
// Stable ID: aa_006efc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006efc60.
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

void __thiscall FUN_006efc60(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  char *pcVar5;

  float fStack_3c;

  float fStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ local_30 [5];

  uint32_t /* width from decompiler */ local_1c;

  

  local_1c = param_4[1];

  pcVar5 = (char *)(**(code **)(*param_1 + 0x20))((int)&uStack_34 + 3,param_2,local_30);

  if (*pcVar5 != '\0') {

    iVar1 = *(int *)(param_3 + 8);

    fVar4 = uStack_34 * *(float *)(iVar1 + 0x40);

    fVar3 = uStack_34 * *(float *)(iVar1 + 0x44);

    fVar2 = fStack_3c * *(float *)(iVar1 + 0x24);

    uStack_34 = fStack_3c * *(float *)(iVar1 + 0x28) +

                fStack_38 * *(float *)(iVar1 + 0x38) + uStack_34 * *(float *)(iVar1 + 0x48);

    local_30[0] = 0;

    fStack_3c = fStack_3c * *(float *)(iVar1 + 0x20) + fStack_38 * *(float *)(iVar1 + 0x30) + fVar4;

    fStack_38 = fVar2 + fStack_38 * *(float *)(iVar1 + 0x34) + fVar3;

    (**(code **)*param_4)(param_3,&fStack_3c);

  }

  return;

}
