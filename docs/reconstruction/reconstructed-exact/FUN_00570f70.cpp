// =============================================================================
// FUN_00570f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00570f70
// Address:   0x00570f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00570f70 @ 0x00570f70
// Stable ID: aa_00570f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_004bc580, FUN_004d4790, FUN_00570f70, InventoryGrid_AllocateCellArray_Inferred, LeaveCriticalSection.
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

void __fastcall FUN_00570f70(void *param_1)



{

  int *piVar1;

  int iVar2;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar2 = FUN_004022a0(&local_4,&local_8);

  piVar1 = local_8;

  while (local_8 = piVar1, iVar2 == 0) {

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x158))(0);

      if (piVar1[0x29] == 0) {

        (**(code **)*piVar1)(1);

        local_8 = (int *)0x0;

      }

      else {

        FUN_004d4790(piVar1);

      }

    }

    iVar2 = FUN_004022a0(&local_4,&local_8);

    piVar1 = local_8;

  }

  if (*(char *)((int)param_1 + 0x54) != '\0') {

    *(uint8_t *)((int)param_1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x30));

  }

  FUN_004bc580();

  InventoryGrid_AllocateCellArray_Inferred(param_1);

  return;

}
