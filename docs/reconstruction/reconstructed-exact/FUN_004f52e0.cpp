// =============================================================================
// FUN_004f52e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f52e0
// Address:   0x004f52e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f52e0 @ 0x004f52e0
// Stable ID: aa_004f52e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004f52e0, Weapon_CanFireHeatCheck.
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

uint32_t /* width from decompiler */ __fastcall FUN_004f52e0(int param_1)



{

  int *pWeapon;

  char cVar1;

  bool bVar2;

  int iVar3;

  

  iVar3 = 0;

  do {

    pWeapon = *(int **)(iVar3 + *(int *)(param_1 + 0x260));

    if (pWeapon != (int *)0x0) {

      cVar1 = (**(code **)(*pWeapon + 0x3c))();

      if (cVar1 != '\0') {

        bVar2 = Weapon_CanFireHeatCheck(pWeapon);

        if (!bVar2) {

          return 0;

        }

      }

    }

    iVar3 = iVar3 + 4;

  } while (iVar3 < 0xc);

  return 1;

}
