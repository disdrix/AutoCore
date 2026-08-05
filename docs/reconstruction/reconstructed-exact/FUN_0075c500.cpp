// =============================================================================
// FUN_0075c500
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c500
// Address:   0x0075c500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075c500 @ 0x0075c500
// Stable ID: aa_0075c500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0043f7e0, FUN_0075c500, FUN_0076f6e0, FUN_00972e50, FUN_00972f10.
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

void __fastcall FUN_0075c500(int param_1)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  int local_48;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  iVar1 = *(int *)(param_1 + 8);

  if (*(int *)(iVar1 + 0xb4) != *(int *)(param_1 + 0xd0)) {

    *(uint8_t *)(param_1 + 0xcc) = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb4);

  }

  if (*(char *)(param_1 + 0xcc) != '\0') {

    FUN_0043f7e0();

    iVar3 = param_1 + 0x60;

    local_48 = 6;

    do {

      FUN_00972f10(&local_c,iVar3 + -4);

      if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {

        FUN_00972e50();

      }

      FUN_0076f6e0();

      pfVar2 = (float *)((-0x60 - param_1) + iVar3 + *(int *)(param_1 + 0xc0));

      pfVar2[2] = local_4;

      *pfVar2 = local_c;

      pfVar2[1] = local_8;

      iVar3 = iVar3 + 0x10;

      local_48 = local_48 + -1;

      pfVar2[3] = 0.0 - (local_4 * local_10 + local_8 * local_14 + local_c * local_18);

    } while (local_48 != 0);

    *(uint8_t *)(param_1 + 0xcc) = 0;

  }

  return;

}
