// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_008605b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008605b0
// Callee of Named_CalleeOf_Client_RecvInventoryEquip (+1 other named callers)
// Address:   0x008605b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RecvInventoryEquip (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00413920, FUN_0085e590, FUN_0085f150, FUN_008605b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvInventoryEquip (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_008605b0(void)



{

  byte bVar1;

  void *pvVar2;

  int *piVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int *unaff_EBX;

  int *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b375a;

  local_c = ExceptionList;

  if ((unaff_EDI[0x15b] != 0) && (unaff_EBX != (int *)0x0)) {

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x514);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_0085e590(pvVar2);

    }

    local_4 = 0xffffffff;

    iVar4 = FUN_00413920(unaff_EDI[0x15c],unaff_EBX[0x58],unaff_EBX[0x59],piVar3,0);

    if (-1 < iVar4) {

      piVar3[0x125] = *(int *)(unaff_EDI[0x15b] + 4);

      (**(code **)(*unaff_EDI + 0xa8))(piVar3);

      bVar1 = *(byte *)(unaff_EDI + 0x159);

      unaff_EDI[0x140] = unaff_EDI[0x140] + 1;

      if (unaff_EDI[0x15b] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(unaff_EDI[0x15b] + 0x1c);

      }

      uVar5 = (**(code **)(*unaff_EBX + 0x254))();

      uVar6 = (**(code **)(*unaff_EBX + 0x250))();

      piVar3[0x126] = uVar6 & 0xff;

      piVar3[0x127] = (uVar5 & 0xff) - iVar4 * (int)(uint)bVar1;

      (**(code **)(*piVar3 + 0x3b0))();

      FUN_0085f150();

      (**(code **)(*piVar3 + 0x34c))();

      ExceptionList = (void *)(uint)bVar1;

      return;

    }

    if (piVar3 != (int *)0x0) {

      (**(code **)*piVar3)(1);

    }

  }

  ExceptionList = local_c;

  return;

}
