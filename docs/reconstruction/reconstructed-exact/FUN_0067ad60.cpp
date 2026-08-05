// =============================================================================
// FUN_0067ad60
// -----------------------------------------------------------------------------
// Stable ID: aa_0067ad60
// Address:   0x0067ad60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067ad60 @ 0x0067ad60
// Stable ID: aa_0067ad60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006810a0×6, CONCAT31×2, FUN_0067ad60.
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

void __thiscall

FUN_0067ad60(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint param_6,int param_7)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint8_t local_4;

  undefined3 uStack_3;

  

  _local_4 = CONCAT31((int3)((uint)param_1 >> 8),0xf);

  FUN_006810a0(&local_4,1);

  uVar1 = param_3;

  FUN_006810a0(&param_3,1);

  param_3 = param_4;

  FUN_006810a0(&param_3,2);

  iVar2 = param_7;

  uVar3 = 0;

  if ((uVar1 & 0xff) != 0) {

    do {

      param_3 = CONCAT31(param_3._1_3_,*(uint8_t *)(*(int *)(iVar2 + 4) + uVar3));

      FUN_006810a0(&param_3,1);

      uVar3 = uVar3 + 1;

    } while (uVar3 != (uVar1 & 0xff));

  }

  uVar1 = param_6;

  param_3 = param_6;

  FUN_006810a0(&param_3,2);

  FUN_006810a0(param_5,uVar1 & 0xffff);

  return;

}
