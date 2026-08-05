// =============================================================================
// FUN_0076e100
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e100
// Address:   0x0076e100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076e100 @ 0x0076e100
// Stable ID: aa_0076e100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0076e100.
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

void FUN_0076e100(int param_1,int param_2)



{

  uint8_t **ppuVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int unaff_EDI;

  uint8_t local_48 [4];

  uint8_t local_44 [4];

  uint8_t local_40 [4];

  uint8_t local_3c [4];

  uint8_t local_38 [4];

  uint8_t local_34 [4];

  uint8_t local_30 [4];

  uint8_t local_2c [4];

  uint8_t local_28 [4];

  uint8_t *local_24;

  uint8_t *local_20;

  uint8_t *local_1c;

  uint8_t *local_18;

  uint8_t *local_14;

  uint8_t *local_10;

  uint8_t *local_c;

  uint8_t *local_8;

  uint8_t *local_4;

  

  local_24 = local_38;

  local_20 = local_2c;

  local_1c = local_28;

  local_18 = local_34;

  local_14 = local_44;

  local_10 = local_3c;

  local_c = local_30;

  local_8 = local_40;

  iVar4 = 0;

  local_4 = local_48;

  iVar2 = 0;

  ppuVar1 = &local_20;

  do {

    iVar3 = iVar2;

    if (param_2 <= iVar4) {

      iVar3 = iVar2 + 4;

    }

    *(uint32_t /* width from decompiler */ *)ppuVar1[-1] = *(uint32_t /* width from decompiler */ *)(param_1 + (iVar3 + (uint)(unaff_EDI < 1)) * 4);

    iVar3 = iVar2;

    if (param_2 <= iVar4) {

      iVar3 = iVar2 + 4;

    }

    *(uint32_t /* width from decompiler */ *)*ppuVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + (iVar3 + (unaff_EDI < 2) + 1) * 4);

    iVar3 = iVar2;

    if (param_2 <= iVar4) {

      iVar3 = iVar2 + 4;

    }

    iVar2 = iVar2 + 4;

    iVar4 = iVar4 + 1;

    *(uint32_t /* width from decompiler */ *)ppuVar1[1] = *(uint32_t /* width from decompiler */ *)(param_1 + (iVar3 + (unaff_EDI < 3) + 2) * 4);

    ppuVar1 = ppuVar1 + 3;

  } while (iVar2 < 0xc);

  return;

}
