// =============================================================================
// FUN_008032f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008032f0
// Address:   0x008032f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008032f0 @ 0x008032f0
// Stable ID: aa_008032f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_008032f0, GetObjectA, strncpy.
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

void __thiscall FUN_008032f0(int *param_1,char *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ local_3c [7];

  char local_20 [32];

  

  if (param_2 != (char *)0x0) {

    puVar2 = local_3c;

    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

    }

    GetObjectA((HANDLE)param_1[0x4d],0x3c,local_3c);

    strncpy(local_20,param_2,0x20);

    (**(code **)(*param_1 + 0x6c))(local_3c);

  }

  return;

}
