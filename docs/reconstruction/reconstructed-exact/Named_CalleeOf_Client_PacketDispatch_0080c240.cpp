// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080c240
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c240
// Callee of Client_PacketDispatch
// Address:   0x0080c240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Error opening Refinery, either character or refinery don\'t exist.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Error opening Refinery, either character or refinery don\'t exist."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007fef20×2, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080c240, FUN_00889fb0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_PacketDispatch_0080c240(void)



{

  int iVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  FUN_007a69d0();

  if (*(char *)(unaff_EBX + 0x18) != '\0') {

    iVar1 = *(int *)(unaff_ESI + 0xe98);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    if ((*(int *)(unaff_EBX + 8) == *(int *)(iVar2 + 0x164 + iVar1)) &&

       (*(int *)(unaff_EBX + 0xc) == *(int *)(iVar2 + 0x168 + iVar1))) {

      FUN_007fef20(9,1,0);

      FUN_007fef20(4,1,0);

      cVar3 = (**(code **)(**(int **)(unaff_ESI + 0x1040) + 0x3d8))();

      if (cVar3 != '\0') {

        FUN_00889fb0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1040),0);

      }

      if (DAT_00d1b778 == (int *)0x0) {

        return;

      }

      (**(code **)(*DAT_00d1b778 + 0x3c4))(1);

      return;

    }

  }

  uVar7 = 0;

  uVar6 = 1;

  uVar5 = 0xffffffff;

  uVar4 = FUN_007a6de0("Error opening Refinery, either character or refinery don\'t exist.",

                       0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar4,uVar5,uVar6,uVar7);

  return;

}
