// =============================================================================
// FUN_006ef5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ef5b0
// Address:   0x006ef5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ef5b0 @ 0x006ef5b0
// Stable ID: aa_006ef5b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006cde50, FUN_006ef5b0.
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

void __thiscall FUN_006ef5b0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  FUN_006cde50(param_2);

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0xc)) {

    puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    do {

      if (*(uint *)(param_2 + 8) == (*(uint *)(param_2 + 0xc) & 0x7fffffff)) {

        FUN_005b3370((int *)(param_2 + 4),0x10);

      }

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) * 0x10 + *(int *)(param_2 + 4));

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;

      *puVar1 = puVar3[-2];

      puVar1[1] = puVar3[-1];

      puVar1[2] = *puVar3;

      puVar1[3] = puVar3[1];

      iVar2 = iVar2 + 1;

      puVar3 = puVar3 + 4;

    } while (iVar2 < *(int *)(param_1 + 0xc));

  }

  return;

}
