// =============================================================================
// FUN_004c4560
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4560
// Address:   0x004c4560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c4560 @ 0x004c4560
// Stable ID: aa_004c4560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004c4560, FUN_0053d9b0, FUN_005d4440.
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

void __fastcall FUN_004c4560(int param_1)



{

  int iVar1;

  bool bVar2;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  FUN_0053d9b0();

  if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x4e0) == 1) {

    FUN_005d4440(7);

  }

  iVar1 = *(int *)(param_1 + 8);

  if (iVar1 != 0) {

    if ((*(char *)(iVar1 + 0x40) == '\0') || (*(int *)(iVar1 + 8) == 0)) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    if (bVar2) {

      local_34 = 0;

      local_38 = 0;

      local_3c = 0;

      local_40 = 0;

      local_24 = 0;

      local_28 = 0;

      local_2c = 0;

      local_30 = 0;

      local_14 = 0;

      local_18 = 0;

      local_1c = 0;

      local_20 = 0;

      (**(code **)(**(int **)(iVar1 + 0x3c) + 0x30))(&local_40);

    }

  }

  return;

}
