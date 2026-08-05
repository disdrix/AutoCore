// =============================================================================
// FUN_00748ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00748ab0
// Address:   0x00748ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748ab0 @ 0x00748ab0
// Stable ID: aa_00748ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00414a50×2, FUN_0074ba50×2, FUN_00746520, FUN_00748ab0, FUN_0074b510.
//  - Return sites: 3.

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

void __fastcall FUN_00748ab0(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffe;

  if ((*(int *)(param_1 + 0x14) == 0) ||

     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + 0x10) + 4) & 2) != 0)) {

    return;

  }

  FUN_0074b510();

  iVar2 = *(int *)(param_1 + 0x14);

  if (*(int *)(iVar2 + 0x10) != 0) {

    iVar2 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x18),4);

    if (iVar2 != 0) {

      if (*(int *)(param_1 + 0x14) == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 0x18);

      }

      if ((*(int *)(param_1 + 0x14) != 0) &&

         (iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x10), iVar1 != 0)) {

        FUN_0074ba50(iVar2,*(uint32_t /* width from decompiler */ *)(iVar1 + 8),uVar3);

        FUN_00414a50();

        return;

      }

      FUN_0074ba50(iVar2,0,uVar3);

    }

  }

  FUN_00414a50();

  return;

}
