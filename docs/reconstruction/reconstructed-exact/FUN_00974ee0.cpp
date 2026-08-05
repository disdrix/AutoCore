// =============================================================================
// FUN_00974ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00974ee0
// Address:   0x00974ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974ee0 @ 0x00974ee0
// Stable ID: aa_00974ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: BitStream_readBits, CONCAT31, FUN_00426ae0, FUN_00431f70, FUN_00974ee0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall FUN_00974ee0(int *param_1,uint32_t /* width from decompiler */ param_2,uint param_3)



{

  float fVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  

  uVar2 = FUN_00426ae0(param_2,param_3);

  if ((char)uVar2 != '\0') {

    BitStream_readBits(0x20,&param_3);

    iVar3 = (**(code **)(*param_1 + 0x50))();

    if (param_3 < *(uint *)(&DAT_00d1ea20 + iVar3 * 0x24)) {

      param_1[0x7e] = param_3;

      (**(code **)(*param_1 + 0x50))();

      uVar2 = FUN_00431f70();

      if ((char)uVar2 == '\0') goto LAB_00974fae;

    }

    else {

      param_1[0x7e] = *(uint *)(&DAT_00d1ea20 + iVar3 * 0x24);

    }

    iVar3 = param_1[0x7e];

    iVar4 = (**(code **)(*param_1 + 0x50))();

    fVar1 = (float)param_1[0x7e];

    uVar2 = param_1[0x7e];

    param_1[0x80] =

         *(int *)(*(int *)(*(int *)(&DAT_00d1ea28 + iVar4 * 0x24) + (iVar3 + -1) * 4) + 8);

    if ((int)uVar2 < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    param_1[0x7f] = (((uVar2 - 1 & uVar2) != 0) - 0x7f) + ((uint)fVar1 >> 0x17);

    return CONCAT31((uint3)((uint)fVar1 >> 0x1f),1);

  }

LAB_00974fae:

  return uVar2 & 0xffffff00;

}
