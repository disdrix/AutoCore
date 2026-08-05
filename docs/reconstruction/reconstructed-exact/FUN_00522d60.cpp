// =============================================================================
// FUN_00522d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00522d60
// Address:   0x00522d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522d60 @ 0x00522d60
// Stable ID: aa_00522d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_00512670×2, FUN_004294f0, FUN_004f3590, FUN_004f7f80, FUN_00522d60, FUN_005706d0, LeaveCriticalSection.
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

void __fastcall FUN_00522d60(int param_1)



{

  int iVar1;

  int iVar2;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x634) = 0xffffffff;

  if (*(int *)(param_1 + 0x250) != 0) {

    FUN_004f3590();

  }

  FUN_00512670();

  if (*(int *)(param_1 + 0xcbc) != 0) {

    local_4 = 0;

    local_8 = 0;

    FUN_005706d0();

    iVar1 = *(int *)(param_1 + 0xcbc);

    FUN_004294f0();

    iVar2 = FUN_004022a0(&local_4,&local_8);

    while (iVar2 == 0) {

      if (local_8 != 0) {

        FUN_00512670();

      }

      iVar2 = FUN_004022a0(&local_4,&local_8);

    }

    if (*(char *)(iVar1 + 0x54) != '\0') {

      *(uint8_t *)(iVar1 + 0x54) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x30));

    }

  }

  if (*(int *)(param_1 + 0x250) != 0) {

    FUN_004f7f80();

  }

  return;

}
