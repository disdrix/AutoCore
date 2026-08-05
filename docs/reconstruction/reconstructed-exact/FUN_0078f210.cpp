// =============================================================================
// FUN_0078f210
// -----------------------------------------------------------------------------
// Stable ID: aa_0078f210
// Address:   0x0078f210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078f210 @ 0x0078f210
// Stable ID: aa_0078f210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0078f210, FUN_007906a0.
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

void __thiscall FUN_0078f210(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (((param_1[0x252] != 0) && (param_1[0x251] != 0)) && (*(char *)(param_1[0x251] + 0xd3) != '\0')

     ) {

    if (param_1[0xac] != 0) {

      cVar2 = (**(code **)(*(int *)param_1[0x252] + 0x3c4))();

      if (cVar2 != '\0') {

        iVar1 = *(int *)param_1[0xac];

        uVar3 = (**(code **)(*param_1 + 0x78))();

        (**(code **)(iVar1 + 0x338))(100,uVar3);

      }

    }

    (**(code **)(*(int *)param_1[0x252] + 0x3d0))(0);

    (**(code **)(*(int *)param_1[0x252] + 0x34c))();

  }

  FUN_007906a0(param_2,param_3);

  return;

}
