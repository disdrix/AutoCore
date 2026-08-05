// =============================================================================
// FUN_00610e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00610e60
// Address:   0x00610e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00610e60 @ 0x00610e60
// Stable ID: aa_00610e60
// Embedded strings (evidence for future rename):
//   - "Failed to give item %d to %I64d, objective %d mission %S(%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004de760, FUN_005310a0, FUN_00610e60, FUN_007a4480, S.
//  - Strings: "Failed to give item %d to %I64d, objective %d mission %S(%d)".
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

void __thiscall FUN_00610e60(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char cVar3;

  

  if ((*(char *)(param_1 + 0x20) != '\0') &&

     (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) != '\0')) {

    cVar3 = FUN_005310a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    if (cVar3 == '\0') {

      puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0x14c);

      iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

      FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission %S(%d)",

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_2),

                   *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_2),

                   *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);

    }

  }

  FUN_004de760(param_2,0);

  return;

}
