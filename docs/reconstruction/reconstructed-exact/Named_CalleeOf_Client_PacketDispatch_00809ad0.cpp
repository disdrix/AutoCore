// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00809ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00809ad0
// Callee of Client_PacketDispatch
// Address:   0x00809ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Processing load queue of %d". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Processing load queue of %d"
//   - "Responding to stage 3"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×10, do×1, while×1, return×1.
//  - Notable callees: FUN_007a4480×2, GetTickCount×2, FUN_0040cf90, FUN_004971e0, FUN_004bfb20, FUN_004bfe10, FUN_00809ad0.
//  - Strings: "Processing load queue of %d"; "Responding to stage 3".
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

void Named_CalleeOf_Client_PacketDispatch_00809ad0(void)



{

  int iVar1;

  char cVar2;

  DWORD DVar3;

  uint uVar4;

  DWORD DVar5;

  int unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();

    if (cVar2 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x10))();

    }

  }

  if (*(char *)(unaff_ESI + 0x113) == '\0') {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = 0;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x134);

  }

  DVar3 = GetTickCount();

  iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe04) + 0xe898);

  uStack_c = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10);

  uStack_8 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14);

  uStack_4 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x8c) = uStack_c;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = uStack_8;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = uStack_4;

  FUN_0040cf90(&uStack_c);

  FUN_004971e0();

  do {

    uVar4 = FUN_004bfb20(9);

    if (uVar4 != 0) {

      FUN_004bfe10(0x40400000);

    }

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      cVar2 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x10))();

      }

    }

    if (*(int *)(unaff_ESI + 0xc7c) != 0) {

      cVar2 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();

      if (cVar2 != '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x10))();

      }

    }

    FUN_007a4480(0xffffffff,"Processing load queue of %d",uVar4);

    if (uVar4 < 6) break;

    DVar5 = GetTickCount();

  } while (DVar5 - DVar3 < 45000);

  FUN_007a4480(0xffffffff,"Responding to stage 3");

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff);

  }

  return;

}
