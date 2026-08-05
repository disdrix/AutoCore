// =============================================================================
// QuickBar_BuildItemButtonWidgets
// -----------------------------------------------------------------------------
// Stable ID: aa_00825e00
// Address:   0x00825e00  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* QuickBar_BuildItemButtonWidgets(pButton)
   
   Builds item quickbar button: bg, icon, keynum, cooldown gauge, click hitbox. */

void __fastcall QuickBar_BuildItemButtonWidgets(void *pButton)

{
  int iVar1;
  void *this;
  void *pvVar2;
  uint32_t /* width from decompiler */ uVar3;
  char *pcVar4;
  uint32_t /* width from decompiler */ uVar5;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
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
