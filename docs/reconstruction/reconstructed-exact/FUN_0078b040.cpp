// =============================================================================
// FUN_0078b040
// -----------------------------------------------------------------------------
// Stable ID: aa_0078b040
// Address:   0x0078b040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078b040 @ 0x0078b040
// Stable ID: aa_0078b040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, while×1, return×1.
//  - Notable callees: block×4, FUN_00423f40×2, FUN_00423fe0, FUN_004294f0, FUN_00789430, FUN_00789eb0, FUN_0078b040, LeaveCriticalSection.
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

/* WARNING: Removing unreachable block (ram,0x0078b0f4) */

/* WARNING: Removing unreachable block (ram,0x0078b10c) */

/* WARNING: Removing unreachable block (ram,0x0078b110) */

/* WARNING: Removing unreachable block (ram,0x0078b11e) */



void __thiscall FUN_0078b040(int *param_1,int param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *local_8;

  int local_4;

  

  local_4 = FUN_00789eb0(param_2,param_3);

  if (local_4 != 0) {

    if ((param_1[0x266] == param_2) && (param_1[0x267] == param_3)) {

      param_1[0x266] = -1;

      param_1[0x267] = -1;

    }

    if (*(int *)(local_4 + 0x1c) != 0) {

      FUN_004294f0();

      iVar1 = FUN_00423f40(&local_8);

      while (iVar1 == 0) {

        if (local_8 == *(uint32_t /* width from decompiler */ **)(local_4 + 0x1c)) {

          *local_8 = 0xffffffff;

          local_8[1] = 0xffffffff;

          if (local_8[2] != 0) {

            FUN_00789430();

          }

          break;

        }

        iVar1 = FUN_00423f40(&local_8);

      }

      if ((char)param_1[0x158] != '\0') {

        *(uint8_t *)(param_1 + 0x158) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14f));

      }

      FUN_00423fe0(local_4);

      (**(code **)(*param_1 + 0x34c))();

    }

  }

  return;

}
