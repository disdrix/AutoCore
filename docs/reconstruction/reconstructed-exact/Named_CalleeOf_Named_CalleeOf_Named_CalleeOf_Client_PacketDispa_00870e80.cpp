// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_00870e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00870e80
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x00870e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, return×1.
//  - Notable callees: FUN_004113b0×6, FUN_004294f0, FUN_007fd970, FUN_00870e80, LeaveCriticalSection, sprintf.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_00870e80(void)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *unaff_EDI;

  int *local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  int local_104;

  char acStack_100 [256];

  

  local_10c = 0;

  local_110 = (int *)0x0;

  if (unaff_EDI[0x193] != 0) {

    piVar1 = unaff_EDI + 0x18a;

    FUN_004294f0();

    iVar4 = FUN_004113b0(piVar1,&local_110);

    while (iVar4 == 0) {

      local_108 = 0;

      local_104 = 0;

      iVar4 = 1;

      iVar5 = FUN_004113b0(piVar1,&local_104);

      piVar2 = local_110;

      while (iVar5 == 0) {

        if (*(ushort *)((int)piVar2 + 0x16) < *(ushort *)(local_104 + 0x16)) {

          iVar4 = iVar4 + 1;

        }

        iVar5 = FUN_004113b0(piVar1,&local_104);

      }

      piVar2[0xe] = iVar4;

      if (*piVar2 != 0) {

        *(short *)(*piVar2 + 0x61c) = (short)iVar4;

      }

      iVar4 = FUN_004113b0(piVar1,&local_110);

    }

    local_10c = 0;

    cVar3 = (**(code **)(*unaff_EDI + 0x3d8))();

    if ((cVar3 != '\0') && (unaff_EDI[0x17a] != 0)) {

      iVar4 = FUN_004113b0(piVar1,&local_110);

      piVar2 = local_110;

      while (local_110 = piVar2, iVar4 == 0) {

        sprintf(acStack_100,"%d",piVar2[0xe]);

        (**(code **)(*(int *)unaff_EDI[0x17a] + 0x45c))(acStack_100,piVar2[2],piVar2[3],1);

        (**(code **)(*(int *)unaff_EDI[0x17a] + 0x460))(piVar2[2],piVar2[3],0,piVar2[0xe]);

        uVar6 = FUN_007fd970();

        (**(code **)(*(int *)unaff_EDI[0x17a] + 0x464))(piVar2[2],piVar2[3],1,uVar6);

        (**(code **)(*(int *)unaff_EDI[0x17a] + 0x34c))();

        iVar4 = FUN_004113b0(piVar1,&local_110);

        piVar2 = local_110;

      }

    }

    if ((char)unaff_EDI[0x194] != '\0') {

      *(uint8_t *)(unaff_EDI + 0x194) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x18b));

    }

  }

  return;

}
