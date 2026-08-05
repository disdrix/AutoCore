// =============================================================================
// FUN_00631270
// -----------------------------------------------------------------------------
// Stable ID: aa_00631270
// Address:   0x00631270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00631270 @ 0x00631270
// Stable ID: aa_00631270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00631270.
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

void __fastcall FUN_00631270(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  iVar3 = 0;

  *param_1 = &PTR_FUN_009e33f0;

  if (0 < (int)param_1[0x1c]) {

    iVar4 = 0;

    do {

      puVar5 = (uint32_t /* width from decompiler */ *)(iVar4 + 8 + param_1[0x1e]);

      iVar2 = puVar5[2];

      if (-1 < iVar2) {

        (**(code **)(*DAT_00b05060 + 0x14))(*puVar5,iVar2 * 4,0x12);

      }

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0x14;

    } while (iVar3 < (int)param_1[0x1c]);

  }

  (**(code **)(*DAT_00b05060 + 4))(param_1[0x1e]);

  puVar5 = param_1 + 0x1c;

  iVar3 = 3;

  do {

    piVar1 = puVar5 + -1;

    puVar5 = puVar5 + -3;

    if (-1 < *piVar1) {

      (**(code **)(*DAT_00b05060 + 0x14))(*puVar5,*piVar1 * 8,0x12);

    }

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  if (-1 < (int)param_1[0x12]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x10],(param_1[0x12] & 0x7fffffff) * 0x1c,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
