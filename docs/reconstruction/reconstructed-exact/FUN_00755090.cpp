// =============================================================================
// FUN_00755090
// -----------------------------------------------------------------------------
// Stable ID: aa_00755090
// Address:   0x00755090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755090 @ 0x00755090
// Stable ID: aa_00755090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, return×2, while×2.
//  - Notable callees: FUN_00754fb0, FUN_00755090.
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

void FUN_00755090(int param_1,uint *param_2)



{

  int in_EAX;

  int iVar1;

  uint uVar2;

  uint *puVar3;

  

  iVar1 = *(int *)(in_EAX + 0x94);

  if (iVar1 != *(int *)(in_EAX + 0x98)) {

    do {

      uVar2 = 0;

      if (*(uint *)(in_EAX + 0x40) != 0) {

        puVar3 = *(uint **)(iVar1 + 8);

        do {

          if (*puVar3 < (uint)(*(int *)(in_EAX + 0x38) - *(int *)(param_1 + 0x14))) {

            *param_2 = uVar2;

            return;

          }

          uVar2 = uVar2 + 1;

          puVar3 = puVar3 + 1;

        } while (uVar2 < *(uint *)(in_EAX + 0x40));

      }

      iVar1 = iVar1 + 0x14;

    } while (iVar1 != *(int *)(in_EAX + 0x98));

  }

  FUN_00754fb0();

  *param_2 = 0;

  return;

}
