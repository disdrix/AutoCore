// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_007fc360
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc360
// Callee of Client_PacketDispatch (+4 other named callers)
// Address:   0x007fc360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_PacketDispatch (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_007fc360, FUN_008073b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch (+4 other named callers)
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

void Named_CalleeOf_Client_PacketDispatch_007fc360(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ auStack_18 [4];

  uint8_t uStack_7;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((*(int **)(in_EAX + 0x1118) != (int *)0x0) && (*(int *)(in_EAX + 0xf40) != 0)) {

    cVar2 = (**(code **)(**(int **)(in_EAX + 0x1118) + 0x3d8))();

    if (cVar2 != '\0') {

      if (**(int **)(in_EAX + 0xf40) != 0) {

        (**(code **)(*(int *)**(int **)(in_EAX + 0xf40) + 0xb0))(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1118));

      }

      (**(code **)(**(int **)(in_EAX + 0x1118) + 0x440))();

      if (*(char *)(in_EAX + 0x30f4) != '\0') {

        *(uint8_t *)(in_EAX + 0x30f4) = 0;

        auStack_18[0] = 0x8006;

        uStack_4 = 9;

        uStack_7 = 0;

        FUN_008073b0(0x18,auStack_18);

      }

      if (**(int **)(in_EAX + 0xf40) != 0) {

        iVar4 = **(int **)(in_EAX + 0xf40);

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x498) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x514);

        *(uint32_t /* width from decompiler */ *)(**(int **)(in_EAX + 0xf40) + 0x49c) =

             *(uint32_t /* width from decompiler */ *)(**(int **)(in_EAX + 0xf40) + 0x518);

      }

      if (*(int *)(in_EAX + 0xf38) != 0) {

        iVar4 = 0;

        piVar3 = (int *)(in_EAX + 0x1030);

        do {

          if ((((iVar4 != 0x16) && (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) &&

              (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) && (piVar1[0x140] == 1))

          goto LAB_007fc476;

          iVar4 = iVar4 + 1;

          piVar3 = piVar3 + 1;

        } while (iVar4 < 0x3a);

        (**(code **)(**(int **)(in_EAX + 0xf38) + 0x3c4))(*(uint8_t *)(in_EAX + 0x31d8));

      }

    }

LAB_007fc476:

    *(uint8_t *)(*(int *)(in_EAX + 0x1118) + 0x4fd) = 0;

  }

  return;

}
