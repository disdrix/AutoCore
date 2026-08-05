// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772050
// -----------------------------------------------------------------------------
// Stable ID: aa_00772050
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00772050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, do×1, while×1.
//  - Notable callees: FUN_007707d0×3, FUN_00770650×2, FUN_007701d0, FUN_00770280, FUN_00770440, FUN_00770540, FUN_00770820, FUN_00771b60.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772050(int param_1,int *param_2,int param_3)



{

  int iVar1;

  byte bVar2;

  uint uVar3;

  uint uVar4;

  uint *puVar5;

  

  if (param_1 < 1) {

    iVar1 = FUN_00770650();

    if (param_3 != 0) {

      FUN_007701d0();

    }

    return iVar1;

  }

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    if ((param_3 != 0) && (iVar1 = FUN_00771b60(param_1), iVar1 != 0)) {

      FUN_007707d0();

      return iVar1;

    }

    iVar1 = FUN_00770650();

    if (iVar1 != 0) {

      FUN_007707d0();

      return iVar1;

    }

    if (0x1b < param_1) {

      FUN_00770280();

    }

    iVar1 = param_1 % 0x1c;

    if (iVar1 != 0) {

      param_1 = *param_2;

      bVar2 = (byte)iVar1;

      uVar3 = 0;

      puVar5 = (uint *)(param_2[3] + -4 + param_1 * 4);

      if (-1 < param_1 + -1) {

        do {

          uVar4 = uVar3 << (0x1c - bVar2 & 0x1f);

          uVar3 = *puVar5 & (1 << (bVar2 & 0x1f)) - 1U;

          param_1 = param_1 + -1;

          *puVar5 = *puVar5 >> (bVar2 & 0x1f) | uVar4;

          puVar5 = puVar5 + -1;

        } while (param_1 != 0);

      }

    }

    FUN_00770820();

    if (param_3 != 0) {

      FUN_00770540();

    }

    FUN_007707d0();

    iVar1 = 0;

  }

  return iVar1;

}
