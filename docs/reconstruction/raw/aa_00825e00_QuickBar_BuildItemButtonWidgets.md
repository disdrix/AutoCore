# Raw capture: QuickBar_BuildItemButtonWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825e00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00825e00` |
| **Canonical name** | `QuickBar_BuildItemButtonWidgets` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* QuickBar_BuildItemButtonWidgets(pButton)
   
   Builds item quickbar button: bg, icon, keynum, cooldown gauge, click hitbox. */

void __fastcall QuickBar_BuildItemButtonWidgets(void *pButton)

{
  int iVar1;
  void *this;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b84e2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00792600();
  (**(code **)(*(int *)pButton + 0x404))
            ((int)pButton + 0x540,"i_d_qb_2d_btn_quickbar_bg.xml",0xffffffff);
  iVar1 = *(int *)((int)pButton + 0x68) + 1;
  *(int *)((int)pButton + 0x68) = iVar1;
  *(float *)((int)pButton + 0x74) = (float)-iVar1;
  if (*(int *)((int)pButton + 0x70) < iVar1) {
    *(int *)((int)pButton + 0x70) = iVar1;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  (**(code **)(*(int *)pButton + 0x404))
            ((int)pButton + 0x544,"i_d_qb_2d_btn_quickbar_icon.xml",0xffffffff);
  iVar1 = *(int *)((int)pButton + 0x68) + 1;
  *(int *)((int)pButton + 0x68) = iVar1;
  *(float *)((int)pButton + 0x74) = (float)-iVar1;
  if (*(int *)((int)pButton + 0x70) < iVar1) {
    *(int *)((int)pButton + 0x70) = iVar1;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  uVar5 = 0xffffffff;
  pcVar4 = "i_d_qb_2d_btn_quickbar_keynum.xml";
  (**(code **)(*(int *)pButton + 0x404))
            ((int)pButton + 0x548,"i_d_qb_2d_btn_quickbar_keynum.xml",0xffffffff);
  iVar1 = *(int *)((int)pButton + 0x68) + 1;
  *(int *)((int)pButton + 0x68) = iVar1;
  *(float *)((int)pButton + 0x74) = (float)-iVar1;
  if (*(int *)((int)pButton + 0x70) < iVar1) {
    *(int *)((int)pButton + 0x70) = iVar1;
  }
  uVar3 = 1;
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  this = operator_new(0x4bc);
  if (this == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = UI_CooldownGaugeWidget_ctor(this);
  }
  *(void **)((int)pButton + 0x550) = pvVar2;
  (**(code **)(*(int *)pButton + 0xa8))(pvVar2,uVar3,this,pcVar4,uVar5,0xffffffff);
  (**(code **)(**(int **)((int)pButton + 0x550) + 0x28))("i_d_qb_2d_btn_quickbar_cooldown.xml");
  (**(code **)(**(int **)((int)pButton + 0x550) + 0x24))(1);
  *(int *)((int)pButton + 0x68) = *(int *)((int)pButton + 0x68) + 1;
  iVar1 = *(int *)((int)pButton + 0x68);
  *(float *)((int)pButton + 0x74) = (float)-iVar1;
  if (*(int *)((int)pButton + 0x70) < iVar1) {
    *(int *)((int)pButton + 0x70) = iVar1;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  pcVar4 = "i_d_qb_2d_btn_quickbar_btn.xml";
  (**(code **)(*(int *)pButton + 0x408))
            ((int)pButton + 0x54c,"i_d_qb_2d_btn_quickbar_btn.xml",60000);
  *(int *)((int)pButton + 0x68) = *(int *)((int)pButton + 0x68) + 1;
  iVar1 = *(int *)((int)pButton + 0x68);
  *(float *)((int)pButton + 0x74) = (float)-iVar1;
  if (*(int *)((int)pButton + 0x70) < iVar1) {
    *(int *)((int)pButton + 0x70) = iVar1;
  }
  (**(code **)(*(int *)pButton + 0x3f4))(1);
  (**(code **)(*(int *)pButton + 0x34c))();
  ExceptionList = pcVar4;
  return;
}
```
