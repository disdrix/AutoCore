// =============================================================================
// FUN_005e5780
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5780
// Address:   0x005e5780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5780 @ 0x005e5780
// Stable ID: aa_005e5780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_005e5780.
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

void __thiscall FUN_005e5780(int *param_1,int *param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint8_t local_c [8];

  uint32_t /* width from decompiler */ *puStack_4;

  

  if (param_3 != 0) {

    iVar4 = 0;

    while( true ) {

      if (param_1[5] == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = param_1[6] - param_1[5] >> 2;

      }

      if (iVar2 <= iVar4) break;

      if (*(int *)(param_1[5] + iVar4 * 4) == param_3) {

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x44))(local_c,iVar4);

        uVar1 = puVar3[2];

        *puStack_4 = *puVar3;

        puStack_4[1] = uVar1;

        return;

      }

      iVar4 = iVar4 + 1;

    }

  }

  *param_2 = param_1[0x50];

  param_2[1] = param_1[0x52];

  return;

}
