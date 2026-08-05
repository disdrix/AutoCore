// =============================================================================
// FUN_006fafb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006fafb0
// Address:   0x006fafb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fafb0 @ 0x006fafb0
// Stable ID: aa_006fafb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_006f8160, FUN_006f8200, FUN_006f88a0, FUN_006f8f00, FUN_006f91d0, FUN_006fa360, FUN_006fa550, FUN_006fa7d0.
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

void FUN_006fafb0(int param_1)



{

  char *pcVar1;

  int iVar2;

  uint8_t local_5d;

  char local_5c [4];

  uint32_t /* width from decompiler */ local_58;

  uint16_t local_54;

  uint8_t local_50 [76];

  

  FUN_006f8f00();

  FUN_006fa360(param_1);

  FUN_006f8200(local_5c,param_1);

  if ((*(char *)(param_1 + 0x58) == '\0') || (local_5c[0] != '\0')) {

    pcVar1 = (char *)FUN_006f91d0(&local_5d);

    if (*pcVar1 != '\0') {

      local_54 = 0;

      iVar2 = FUN_006fabe0(param_1,&local_58,local_50);

      if ((local_5c[0] != '\0') && (iVar2 != 0)) {

        FUN_006f8160(param_1,&local_58,local_50,iVar2 == 2);

        if (*(char *)(param_1 + 0x59) != '\0') {

          FUN_006fa550(param_1);

        }

      }

      if (iVar2 == 2) {

        FUN_006f88a0(param_1,local_50,&local_58);

        FUN_006fa7d0(param_1,local_58,local_54);

      }

    }

  }

  return;

}
