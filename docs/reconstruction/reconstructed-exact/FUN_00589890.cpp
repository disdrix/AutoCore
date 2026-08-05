// =============================================================================
// FUN_00589890
// -----------------------------------------------------------------------------
// Stable ID: aa_00589890
// Address:   0x00589890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00589890 @ 0x00589890
// Stable ID: aa_00589890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004073a0, FUN_00589890, _aligned_malloc.
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

void __fastcall FUN_00589890(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *local_4;

  

  if (((int *)*param_1 == (int *)0x0) || (*(int *)*param_1 == 0)) {

    local_4 = param_1;

    piVar2 = _aligned_malloc(1000,0x10);

    iVar4 = param_1[2];

    if ((iVar4 == 0) || ((uint)(param_1[4] - iVar4 >> 2) <= (uint)(param_1[3] - iVar4 >> 2))) {

      local_4 = piVar2;

      FUN_004073a0(param_1[3],1,&local_4);

    }

    else {

      puVar1 = (uint32_t /* width from decompiler */ *)param_1[3];

      *puVar1 = piVar2;

      param_1[3] = (int)(puVar1 + 1);

    }

    *param_1 = (int)piVar2;

    iVar4 = 0x18;

    piVar3 = piVar2;

    do {

      iVar4 = iVar4 + -1;

      *piVar3 = (int)(piVar3 + 10);

      piVar3 = piVar3 + 10;

    } while (iVar4 != 0);

    piVar2[0xf0] = 0;

  }

  *param_1 = *(int *)*param_1;

  return;

}
