// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080e1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e1e0
// Callee of Client_PacketDispatch
// Address:   0x0080e1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "point in". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "point in"
//   - "You have improved"
//   - "[System]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007a6de0×3, FUN_00403450, FUN_0052ae30, FUN_0052b040, FUN_007a69d0, FUN_0080e1e0, FUN_008a05a0, FUN_008f8200.
//  - Strings: "point in"; "You have improved"; "%s %d %s %s"; "[System]".
//  - Return sites: 1.

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

/* WARNING: Removing unreachable block (ram,0x0080e315) */



void Named_CalleeOf_Client_PacketDispatch_0080e1e0(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_EBX;

  uint8_t auStack_388 [128];

  char acStack_308 [256];

  uint8_t auStack_208 [42];

  uint8_t auStack_1de [466];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b8088;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007a69d0();

  if (*(char *)(unaff_EBX + 0xc) != '\0') {

    FUN_0052ae30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8));

    if ((*(int *)(param_1 + 0x10b0) != 0) &&

       (cVar1 = (**(code **)(**(int **)(param_1 + 0x10b0) + 0x3d8))(), cVar1 != '\0')) {

      FUN_008a05a0();

    }

    cVar1 = (**(code **)(**(int **)(param_1 + 0x1030) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x1030) + 0x448))();

    }

    cVar1 = FUN_0052b040(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),auStack_208);

    if (cVar1 != '\0') {

      uVar2 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(auStack_1de,uVar2);

      uStack_4 = 0;

      uVar3 = FUN_007a6de0(auStack_388,0xffffffff);

      uVar4 = FUN_007a6de0("point in",0xffffffff);

      uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8);

      uVar5 = FUN_007a6de0("You have improved",0xffffffff);

      sprintf(acStack_308,"%s %d %s %s",uVar5,uVar2,uVar4,uVar3);

      uStack_4 = 0xffffffff;

      FUN_008f8200(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),6,"[System]",acStack_308,0);

    }

  }

  ExceptionList = local_c;

  return;

}
