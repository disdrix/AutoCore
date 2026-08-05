// =============================================================================
// FUN_00563890
// -----------------------------------------------------------------------------
// Stable ID: aa_00563890
// Address:   0x00563890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00563890 @ 0x00563890
// Stable ID: aa_00563890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004bb1f0, FUN_00563890.
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

void __thiscall FUN_00563890(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar1 = param_2;

  if ((param_2 != 0) && (*(int *)(param_1 + 0x184) != *(int *)(param_1 + 0x188))) {

    puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x160);

    param_2 = *(int *)(param_1 + 0x184);

    do {

      piVar2 = (int *)FUN_004bb1f0(puVar3);

      if (piVar2 == (int *)0x0) {

        return;

      }

      (**(code **)(*piVar2 + 0x74))

                (*puVar3,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x168),

                 *(uint32_t /* width from decompiler */ *)(iVar1 + 0x16c));

      param_2 = param_2 + 8;

    } while (param_2 != *(int *)(param_1 + 0x188));

  }

  return;

}
