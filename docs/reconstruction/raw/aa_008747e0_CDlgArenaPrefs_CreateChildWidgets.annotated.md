# Annotated low-level: CDlgArenaPrefs_CreateChildWidgets

| Field | Value |
|---|---|
| Stable ID | `aa_008747e0` |
| VA | `0x008747e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008747e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Arena prefs host UI: construct/load child widgets from i_d_arena/i_d_arena_prefs_*.xml (match
   type, fees, ranks, factions, victory). thiscall on arena prefs window. Vtable DATA xref
   0x00a5aef0. */

void __fastcall CDlgArenaPrefs_CreateChildWidgets(void *this)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 *puVar6;
  char *pcStack_758;
  char *pcStack_74c;
  char *pcStack_318;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b52e7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined1 *)((int)this + 0x518) = 0;
  *(undefined1 *)((int)this + 0xc5) = 0;
  *(undefined4 *)((int)this + 0x4fc) = 0xf;
  (**(code **)(*(int *)this + 0x114))();
  (**(code **)(*(int *)this + 0x130))();
  *(undefined1 *)((int)this + 0x510) = 0;
  FUN_00792600();
  pvVar2 = operator_new(0x488);
  pvStack_c = (void *)0x0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  pvStack_c = (void *)0xffffffff;
  *(undefined4 *)((int)this + 0x534) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x534) + 0x28))();
  pvVar2 = operator_new(0x4bc);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00864f20();
  }
  *(undefined4 *)((int)this + 0x538) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x538) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x53c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x53c) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x540) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x540) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x540) + 0x74))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x544) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x544) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x544) + 0x74))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x548) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x548) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x548) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x548) + 0xd4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x54c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x54c) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x54c) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x54c) + 0xd4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x550) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x550) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x550) + 0x74))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x554) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x554) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x554) + 0x74))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x558) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x558) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x55c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x55c) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x560) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x560) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x558) + 0x1d8))();
  (**(code **)(**(int **)((int)this + 0x55c) + 0x1d8))();
  (**(code **)(**(int **)((int)this + 0x560) + 0x1d8))();
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x564) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x564) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x564) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x564) + 0x3ac))();
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x568) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x568) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x568) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x568) + 0x3ac))();
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x56c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x56c) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x56c) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x56c) + 0x3ac))();
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x570) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x570) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x570) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x570) + 0x3ac))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x574) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x574) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x578) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x578) + 0x28))();
  pcStack_318 = (char *)0x874f60;
  pcStack_318 = operator_new(0x488);
  if (pcStack_318 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x57c) = uVar3;
  pcStack_318 = (char *)0x874f9a;
  (**(code **)(*(int *)this + 0xa8))();
  pcStack_318 = "i_d_arena/i_d_arena_prefs_wnd_label_rank_minimum.xml";
  (**(code **)(**(int **)((int)this + 0x57c) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x580) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x580) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x588) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x588) + 0x28))();
  pcStack_318 = operator_new(0x4a4);
  uVar3 = 0;
  if (pcStack_318 != (char *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x58c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x58c) + 0x28))();
  if (DAT_00d1b6d8 == 0) {
    pcStack_318 = DAT_00a5c1b8;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x160))();
    sprintf((char *)&pcStack_318,"%s\'s Arena");
  }
  (**(code **)(**(int **)((int)this + 0x58c) + 0x3ac))();
  piVar1 = *(int **)((int)this + 0x58c);
  *(undefined1 *)((int)piVar1 + 0x489) = 1;
  piVar4 = (int *)(**(code **)(*piVar1 + 0x170))();
  piVar1[0x8b] = *piVar4;
  piVar4 = (int *)__RTDynamicCast();
  if ((piVar4 != (int *)0x0) && ((int *)piVar4[0x12f] == piVar1)) {
    (**(code **)(*piVar4 + 0x1c8))();
    (**(code **)(*piVar4 + 0x3c0))();
  }
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x590) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x590) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x590) + 0x3ac))();
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x594) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x594) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x594) + 0x3ac))();
  (**(code **)(**(int **)((int)this + 0x594) + 0x1d0))();
  *(undefined1 *)(*(int *)((int)this + 0x594) + 0x48c) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x598) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x598) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x59c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x59c) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5a0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5a0) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5a4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5a4) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5a8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5a8) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5a8) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5a8) + 0x3b4))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5ac) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5ac) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5b0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5b0) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5b0) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5b0) + 0x3b4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5b4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5b4) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5b4) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5b4) + 0x3b4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5b8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5b8) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5b8) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5b8) + 0x3b4))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5bc) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5bc) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5c0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5c0) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5c4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5c4) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5c8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5c8) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5c8) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5c8) + 0x3b4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5cc) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5cc) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5cc) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5cc) + 0x3b4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5d0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5d0) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5d0) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5d0) + 0x3b4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5d4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5d4) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5d4) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5d4) + 0x3b4))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5d8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5d8) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5dc) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5dc) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5e0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5e0) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5e4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5e4) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5e8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5e8) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5a8) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5b0) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5b4) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5b8) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5c8) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5cc) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5d0) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5d4) + 0x3c8))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5ec) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5ec) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5ec) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5ec) + 0x3b4))();
  (**(code **)(**(int **)((int)this + 0x5ec) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5ec) + 0xd4))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x5f0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5f0) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x5f0) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x5f0) + 0x3b4))();
  (**(code **)(**(int **)((int)this + 0x5f0) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x5f0) + 0xd4))();
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x5f4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5f4) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x5f4) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x5f4) + 0x3ac))();
  piVar1 = *(int **)((int)this + 0x5f4);
  *(undefined1 *)((int)piVar1 + 0x489) = 1;
  piVar4 = (int *)(**(code **)(*piVar1 + 0x170))();
  piVar1[0x8b] = *piVar4;
  piVar4 = (int *)__RTDynamicCast();
  if ((piVar4 != (int *)0x0) && ((int *)piVar4[0x12f] == piVar1)) {
    (**(code **)(*piVar4 + 0x1c8))();
    (**(code **)(*piVar4 + 0x3c0))();
  }
  pvVar2 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x5f8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5f8) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x5f8) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x5f8) + 0x3ac))();
  piVar1 = *(int **)((int)this + 0x5f8);
  *(undefined1 *)((int)piVar1 + 0x489) = 1;
  piVar4 = (int *)(**(code **)(*piVar1 + 0x170))();
  piVar1[0x8b] = *piVar4;
  piVar4 = (int *)__RTDynamicCast();
  if ((piVar4 != (int *)0x0) && ((int *)piVar4[0x12f] == piVar1)) {
    (**(code **)(*piVar4 + 0x1c8))();
    (**(code **)(*piVar4 + 0x3c0))();
  }
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x5fc) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x5fc) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x600) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x600) + 0x28))();
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x604) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x604) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x608) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x608) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x608) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x608) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x608) + 0x498) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x620) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x620) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x60c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x60c) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x60c) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x60c) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x60c) + 0x498) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x624) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x624) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x610) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x610) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x610) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x610) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x610) + 0x498) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x628) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x628) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x614) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x614) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x614) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x614) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x614) + 0x498) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x62c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x62c) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x618) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x618) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x618) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x618) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x618) + 0x498) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x630) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x630) + 0x28))();
  pvVar2 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar2 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x61c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x61c) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x61c) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x61c) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x61c) + 0x498) = 1;
  pvVar2 = operator_new(0x488);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = (void *)FUN_007b5dd0();
  }
  *(void **)((int)this + 0x634) = pvVar2;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x634) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x638) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x638) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x63c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x63c) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x63c) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x63c) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x63c) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x660) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x660) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x640) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x640) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x640) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x640) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x640) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x664) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x664) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x644) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x644) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x644) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x644) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x644) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x668) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x668) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x648) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x648) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x648) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x648) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x648) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x66c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x66c) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x64c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x64c) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x64c) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x64c) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x64c) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x670) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x670) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x650) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x650) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x650) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x650) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x650) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x674) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x674) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x654) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x654) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x654) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x654) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x654) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x678) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x678) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x658) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x658) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x658) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x658) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x658) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x67c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x67c) + 0x28))();
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x65c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x65c) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x65c) + 0x74))();
  (**(code **)(**(int **)((int)this + 0x65c) + 0x3b4))();
  *(undefined4 *)(*(int *)((int)this + 0x65c) + 0x498) = 0;
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x680) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x680) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x684) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x684) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x688) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x688) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x640) + 0x3c8))();
  (**(code **)(**(int **)((int)this + 0x614) + 0x3c8))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x68c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x68c) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x690) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x690) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x694) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x694) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x698) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x698) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x69c) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x69c) + 0x28))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6a0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6a0) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6a0) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6a0) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6a0) + 0x3ac))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6a4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6a4) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6a4) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6a4) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6a4) + 0x3ac))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6a8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6a8) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6a8) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6a8) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6a8) + 0x3ac))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6ac) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6ac) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6ac) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6ac) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6ac) + 0x3ac))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x6b0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6b0) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x6b4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6b4) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x6b8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6b8) + 0x28))();
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x6bc) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6bc) + 0x28))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6c0) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6c0) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6c0) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6c0) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6c0) + 0x3ac))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6c4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6c4) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6c4) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6c4) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6c4) + 0x3ac))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6c8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6c8) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6c8) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6c8) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6c8) + 0x3ac))();
  pvVar5 = operator_new(0x4a4);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_00795f20();
  }
  *(undefined4 *)((int)this + 0x6cc) = uVar3;
  (**(code **)(*(int *)this + 0xa8))();
  (**(code **)(**(int **)((int)this + 0x6cc) + 0x28))();
  *(undefined1 *)(*(int *)((int)this + 0x6cc) + 0x48b) = 1;
  (**(code **)(**(int **)((int)this + 0x6cc) + 0x1d0))();
  (**(code **)(**(int **)((int)this + 0x6cc) + 0x3ac))();
  pcStack_74c = (char *)0x8772cf;
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x504) = uVar3;
  pcStack_74c = (char *)0x877306;
  (**(code **)(*(int *)this + 0xa8))();
  pcStack_74c = "i_d_arena/i_d_arena_prefs_btn_close.xml";
  (**(code **)(**(int **)((int)this + 0x504) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x504) + 0x74))();
  pcStack_758 = (char *)0x877330;
  pcStack_758 = operator_new(0x488);
  if (pcStack_758 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0();
  }
  *(undefined4 *)((int)this + 0x6d0) = uVar3;
  pcStack_758 = (char *)0x877369;
  (**(code **)(*(int *)this + 0xa8))();
  pcStack_758 = "i_d_arena/i_d_arena_prefs_mini_wnd_bg_texture.xml";
  (**(code **)(**(int **)((int)this + 0x6d0) + 0x28))();
  (**(code **)(**(int **)((int)this + 0x6d0) + 0xcc))(0);
  *(undefined1 *)(*(int *)((int)this + 0x6d0) + 0xc4) = 1;
  puVar6 = (undefined4 *)(**(code **)(**(int **)((int)this + 0x6d0) + 0x120))(&pcStack_74c,1,0);
  *(undefined4 *)((int)this + 0x524) = *puVar6;
  *(undefined4 *)((int)this + 0x528) = puVar6[1];
  pcStack_758 = (char *)0x0;
  (**(code **)(**(int **)((int)this + 0x6d0) + 0x110))(&pcStack_758);
  pvVar5 = operator_new(0x488);
  if (pvVar5 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007b5dd0(pvVar5,0);
  }
  *(undefined4 *)((int)this + 0x6d4) = uVar3;
  (**(code **)(*(int *)this + 0xa8))(uVar3);
  (**(code **)(**(int **)((int)this + 0x6d4) + 0x28))
            ("i_d_arena/i_d_arena_prefs_mini_wnd_label_status.xml");
  (**(code **)(**(int **)((int)this + 0x6d4) + 0xcc))(0);
  *(undefined1 *)(*(int *)((int)this + 0x6d4) + 0xc4) = 1;
  pvVar5 = operator_new(0x4cc);
  uVar3 = 0;
  if (pvVar5 != (void *)0x0) {
    uVar3 = FUN_0079c860();
  }
  *(undefined4 *)((int)this + 0x6d8) = uVar3;
  (**(code **)(*(int *)this + 0xa8))(uVar3);
  (**(code **)(**(int **)((int)this + 0x6d8) + 0x28))
            ("i_d_arena/i_d_arena_prefs_mini_btn_cancel.xml");
  (**(code **)(**(int **)((int)this + 0x6d8) + 0x74))(0x9c61);
  (**(code **)(**(int **)((int)this + 0x6d8) + 0xcc))(0);
  (**(code **)(**(int **)((int)this + 0x56c) + 0xcc))(0);
  (**(code **)(**(int **)((int)this + 0x564) + 0xcc))(0);
  (**(code **)(*(int *)this + 0x448))();
  (**(code **)(*(int *)this + 0x34c))();
  ExceptionList = pvVar2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
