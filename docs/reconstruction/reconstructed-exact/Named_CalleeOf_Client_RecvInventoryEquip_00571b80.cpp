// =============================================================================
// Named_CalleeOf_Client_RecvInventoryEquip_00571b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00571b80
// Callee of Client_RecvInventoryEquip (+2 other named callers)
// Address:   0x00571b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvInventoryEquip: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvInventoryEquip (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, goto×2, do×2, while×2.
//  - Notable callees: FUN_00415c00, FUN_005085b0, FUN_00512670, FUN_00513e70, FUN_00571b80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvInventoryEquip (+2 other named callers)
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

int * __thiscall Named_CalleeOf_Client_RecvInventoryEquip_00571b80(int param_1,int *param_2,int param_3,char param_4)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  char cVar4;

  byte bVar5;

  byte bVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int iStack_10;

  uint uStack_c;

  uint uStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((param_2 == (int *)0x0) || (cVar4 = FUN_00415c00(param_2), cVar4 == '\0')) {

    return (int *)0x0;

  }

  local_4 = 1;

  cVar4 = FUN_00513e70();

  if (cVar4 != '\0') {

    local_4 = (**(code **)(*param_2 + 0x25c))();

    iVar7 = (**(code **)(*param_2 + 0x25c))();

    if ((iVar7 < 2) || (((uint)param_2[0x5f] >> 0xf & 1) != 0)) {

      if (((uint)param_2[0x5f] >> 0xf & 1) != 0) goto LAB_00571c19;

    }

    else {

      iVar7 = *param_2;

      iVar8 = (**(code **)(iVar7 + 0x25c))();

      (**(code **)(iVar7 + 0x260))(iVar8 - param_3);

      iVar7 = (**(code **)(*param_2 + 0x25c))();

      if (0 < iVar7) {

LAB_00571c19:

        piVar9 = (int *)0x0;

        if (param_4 == '\0') goto LAB_00571d08;

      }

    }

  }

  if (*(int *)(param_2[0x2a] + 0x38) != 4) {

    bVar5 = (**(code **)(*param_2 + 0x250))();

    bVar6 = (**(code **)(*param_2 + 0x254))();

    bVar1 = *(byte *)(*(int *)(param_2[0x2a] + 0x3c) + 0x406);

    bVar2 = *(byte *)(*(int *)(param_2[0x2a] + 0x3c) + 0x407);

    if (bVar1 != 0) {

      uStack_8 = (uint)bVar1;

      iStack_10 = 0;

      do {

        if (bVar2 != 0) {

          uStack_c = (uint)bVar2;

          iVar7 = 0;

          do {

            iVar8 = *(int *)(param_1 + 0xc) * ((uint)bVar5 + iStack_10) + iVar7 + (uint)bVar6;

            if ((iVar8 < *(int *)(param_1 + 0x10)) && (-1 < iVar8)) {

              iVar3 = *(int *)(param_1 + 0x28);

              *(uint32_t /* width from decompiler */ *)(iVar3 + iVar8 * 8) = 0xffffffff;

              *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar8 * 8) = 0xffffffff;

            }

            iVar7 = iVar7 + 1;

            uStack_c = uStack_c - 1;

          } while (uStack_c != 0);

        }

        iStack_10 = iStack_10 + 1;

        uStack_8 = uStack_8 - 1;

      } while (uStack_8 != 0);

    }

  }

  FUN_005085b0(param_2);

  (**(code **)(*param_2 + 0x260))(local_4);

  (**(code **)(*param_2 + 0x158))(0);

  piVar9 = param_2;

LAB_00571d08:

  if (*(int *)(param_1 + 0x24) != 0) {

    FUN_00512670();

  }

  *(uint8_t *)(param_1 + 0x21) = 1;

  return piVar9;

}
