// =============================================================================
// FUN_00760ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00760ed0
// Address:   0x00760ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00760ed0 @ 0x00760ed0
// Stable ID: aa_00760ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, for×1, while×1.
//  - Notable callees: FUN_00760830, FUN_00760ed0.
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

void __thiscall FUN_00760ed0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  float fVar2;

  uint in_EAX;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  

  iVar6 = *(int *)(param_1 + 0xc);

  if (in_EAX == 0xffffffff) {

    if (iVar6 == 0) {

      in_EAX = 0xffffffff;

    }

    else {

      in_EAX = (*(int *)(param_1 + 0x10) - iVar6) / 0x28 - 1;

    }

  }

  else if ((iVar6 == 0) || ((uint)((*(int *)(param_1 + 0x10) - iVar6) / 0x28) <= in_EAX)) {

    FUN_00760830(in_EAX + 1);

  }

  iVar6 = in_EAX * 0x28;

  iVar3 = *(int *)(param_1 + 0xc) + iVar6;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = param_2;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = param_3;

  iVar3 = iVar6;

  for (uVar5 = in_EAX; uVar5 != 0; uVar5 = uVar5 - 1) {

    fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 0x20 + iVar3);

    iVar4 = *(int *)(param_1 + 0xc) + iVar3;

    *(float *)(iVar4 + -4) = fVar1;

    if (*(float *)(iVar4 + -8) <= fVar1) break;

    iVar3 = iVar3 + -0x28;

    *(float *)(iVar4 + -8) = fVar1;

  }

  while( true ) {

    iVar3 = 0;

    if (*(int *)(param_1 + 0xc) != 0) {

      iVar3 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

    }

    if (iVar3 - 1U <= in_EAX) break;

    iVar3 = *(int *)(param_1 + 0xc);

    fVar1 = *(float *)(iVar3 + 0x24 + iVar6);

    fVar2 = *(float *)(iVar3 + 0x4c + iVar6);

    *(float *)(iVar3 + iVar6 + 0x48) = fVar1;

    if (fVar1 <= fVar2) {

      return;

    }

    in_EAX = in_EAX + 1;

    *(float *)(iVar3 + iVar6 + 0x4c) = fVar1;

    iVar6 = iVar6 + 0x28;

  }

  return;

}
