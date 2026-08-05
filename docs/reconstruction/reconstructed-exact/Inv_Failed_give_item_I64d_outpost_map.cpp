// =============================================================================
// Inv_Failed_give_item_I64d_outpost_map
// -----------------------------------------------------------------------------
// Stable ID: aa_00607a00
// Address:   0x00607a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_Failed_give_item_I64d_outpost_map @ 0x00607a00
// Stable ID: aa_00607a00
// Embedded strings (evidence for future rename):
//   - "Failed to give item %d to %I64d, outpost %s on map(%d)%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00607610×2, FUN_005310a0, Inv_Failed_give_item_I64d_outpost_map, FUN_007a4480, map.
//  - Strings: "Failed to give item %d to %I64d, outpost %s on map(%d)%s".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Failed to give item %d to %I64d, outpost %s on map(%d)%s"
 * Domain alias of FUN_00607a00 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_Failed_give_item_I64d_outpost_map(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  iVar4 = FUN_00607610();

  if (0 < iVar4) {

    uVar5 = FUN_00607610();

    cVar3 = FUN_005310a0(0x21a3,uVar5);

    if (cVar3 == '\0') {

      iVar4 = *(int *)(*(int *)(param_2 + 4) + 4);

      iVar1 = *(int *)(iVar4 + 0xa8 + param_2);

      iVar4 = iVar4 + param_2;

      uVar5 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168);

      uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x160))

                        (*(uint32_t /* width from decompiler */ *)(iVar1 + 0xfc),iVar1 + 0xb4);

      FUN_007a4480(1,"Failed to give item %d to %I64d, outpost %s on map(%d)%s",0x21a3,uVar5,uVar2,

                   uVar6);

    }

  }

  return;

}
