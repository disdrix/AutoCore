// =============================================================================
// FUN_005eb680
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb680
// Address:   0x005eb680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eb680 @ 0x005eb680
// Stable ID: aa_005eb680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00580b60×2, FUN_005eb680.
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

void __thiscall FUN_005eb680(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  if (*param_2 != 0) {

    iVar2 = *(int *)(param_1 + 0xc4) + -1;

    if (-1 < iVar2) {

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc0) + iVar2 * 4);

      do {

        if ((int *)*puVar1 == param_2) {

          FUN_00580b60(param_2,1);

          *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc0) + iVar2 * 4) =

               *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc0) + *(int *)(param_1 + 0xc4) * 4);

          return;

        }

        iVar2 = iVar2 + -1;

        puVar1 = puVar1 + -1;

      } while (-1 < iVar2);

    }

    FUN_00580b60(param_2,(uint)param_2 & 0xffffff00);

  }

  return;

}
