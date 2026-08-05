// =============================================================================
// FUN_004236f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004236f0
// Address:   0x004236f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004236f0 @ 0x004236f0
// Stable ID: aa_004236f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×2.
//  - Notable callees: FUN_004048e0, FUN_004236f0, FUN_00423780.
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

void FUN_004236f0(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  iVar2 = *param_1;

  uVar3 = *(uint *)(iVar2 + -0xc);

  iVar1 = param_2 + uVar3;

  uVar4 = (int)in_EAX - iVar2 >> 1;

  if ((int)(1U - *(int *)(iVar2 + -4) | *(int *)(iVar2 + -8) - iVar1) < 0) {

    FUN_00423780();

  }

  if (uVar4 <= uVar3) {

    in_EAX = (uint32_t /* width from decompiler */ *)(*param_1 + uVar4 * 2);

  }

  puVar5 = (uint32_t /* width from decompiler */ *)(*param_1 + uVar3 * 2);

  for (uVar4 = (uint)(param_2 * 2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar5 = *in_EAX;

    in_EAX = in_EAX + 1;

    puVar5 = puVar5 + 1;

  }

  for (uVar3 = param_2 * 2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar5 = *(uint8_t *)in_EAX;

    in_EAX = (uint32_t /* width from decompiler */ *)((int)in_EAX + 1);

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  if (-1 < iVar1) {

    if (iVar1 <= *(int *)(*param_1 + -8)) {

      *(int *)(*param_1 + -0xc) = iVar1;

      *(uint16_t *)(*param_1 + iVar1 * 2) = 0;

      return;

    }

  }

                    /* WARNING: Subroutine does not return */

  FUN_004048e0(0x80070057);

}
