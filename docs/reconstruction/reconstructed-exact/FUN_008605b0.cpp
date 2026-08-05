// =============================================================================
// FUN_008605b0  →  Client_UI_InventorySheet_AddItemWidget
// -----------------------------------------------------------------------------
// Stable ID: aa_008605b0
// Address:   0x008605b0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B plate 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Preferred clean: Client_UI_InventorySheet_AddItemWidget.cpp
// Dual: reviews/A_aa_008605b0_… / B_aa_008605b0_… (accept-with-gaps)
// =============================================================================
//
// PURPOSE: UI sheet add — new inventory item widget, COID hash insert, attach,
// page-local cell stamp, pixel place, refresh. Not a packet path.
//
// ABI: EDI=window, EBX=item (register). Gate: *(window+0x56c) && item.
// Ctor string (callee FUN_0085e590): i_g_2d_wnd_inventory_item_template.xml
//
// DECOMPILER ARTIFACT: success ExceptionList=(void*)bVar1 is FALSE (SEH stack restore).
//

void FUN_008605b0(void)



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
