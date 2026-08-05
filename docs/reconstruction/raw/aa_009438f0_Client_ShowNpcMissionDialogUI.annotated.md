# Annotated low-level: Client_ShowNpcMissionDialogUI

| Field | Value |
|---|---|
| Stable ID | `aa_009438f0` |
| VA | `0x009438f0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009438f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Client_ShowNpcMissionDialogUI(int param_1,int param_2,char param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  uint in_EAX;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  void *pvVar8;
  void *this;
  int *unaff_EDI;
  undefined4 uVar9;
  
  if ((((*(int **)(param_1 + 0xf40) != (int *)0x0) &&
       (**(int **)(param_1 + 0xf40) == *(int *)(param_1 + 0xf38))) &&
      (iVar1 = *(int *)(param_1 + 0xe98), iVar1 != 0)) &&
     (piVar2 = *(int **)(param_1 + 0x1058), piVar2 != (int *)0x0)) {
    if ((param_3 == '\0') || (in_EAX != 0xffffffff)) {
      puVar5 = (undefined4 *)FUN_0053fff0();
    }
    else {
      if (1 < *(uint *)(iVar1 + 0x510)) {
        *(undefined1 *)(param_1 + 0x19) = 0;
        cVar4 = (**(code **)(*piVar2 + 0x3d8))();
        if (cVar4 == '\0') {
          FUN_007fef20(10,1,0);
        }
        FUN_008ab550();
        FUN_008aa4b0();
        Client_UpdateMissionJournal(this,unaff_EDI);
        FUN_0092f090();
        return;
      }
      piVar3 = (int *)**(int **)(iVar1 + 0x50c);
      if (piVar3 == *(int **)(iVar1 + 0x50c)) {
        return;
      }
      puVar5 = (undefined4 *)FUN_0053fff0();
      in_EAX = piVar3[4];
    }
    puVar6 = CNDHash_LookupByKey((void *)*puVar5,in_EAX);
    if ((puVar6 != (uint *)0x0) && ((char)puVar6[0x4c] != '\0')) {
      *(undefined1 *)(param_1 + 0x19) = 0;
      FUN_00547920(0);
      cVar4 = (**(code **)(*piVar2 + 0x3d8))();
      if (cVar4 == '\0') {
        FUN_007fef20(10,1,0);
      }
      else if (((uint *)piVar2[0x19c] == puVar6) && (piVar2[0x191] == param_2)) {
        FUN_007a4480(0,"NPC dialog already active!");
        return;
      }
      cVar4 = FUN_0052b420(puVar6,param_2);
      FUN_008aa490();
      Client_NpcDialog_PrepareResponseOpcode();
      FUN_008ab550();
      FUN_008aa4b0();
      uVar7 = FUN_0052dac0(*puVar6,0);
      if (cVar4 == '\0') {
        pvVar8 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xe98) + 0x540),*puVar6);
        if (pvVar8 == (void *)0x0) {
          FUN_008aaf60();
          piVar2[0x144] = 2;
          FUN_008ac110();
          FUN_008aa510(0xffffffff,0xffffffff);
          FUN_008aa510(0xffffffff,0xffffffff);
          uVar9 = 0;
        }
        else {
          FUN_008aaf60();
          piVar2[0x144] = 1;
          FUN_008ac110();
          FUN_008aa510(0xffffffff,0xffffffff);
          uVar9 = 0;
        }
      }
      else {
        FUN_008aaf60();
        piVar2[0x144] = 1;
        FUN_008ac110();
        FUN_008aa510(0xffffffff,0xffffffff);
        uVar9 = 1;
      }
      FUN_008aa760(uVar7,4,uVar9);
      FUN_0092f090();
    }
  }
  return;
}
```

## Open questions (updated 2026-07-29 dual residual strengthen)

- **EAX framing sealed (4/4 xrefs):** Recv `OR EAX,-1` mode=1; unmapped `0x00924608` same (`char+0x510≠EBX` gate); HandleButton state3 key at `dialog+0x518+idx*8` mode=0; list click `*(entry+0x500)` mode=0.
- **Field map sealed:** `int*[0x144]` → `dialog+0x510` (chrome 1/2); `[0x191]`→`+0x644` NPC; `[0x19c]`→`+0x670` def; `FUN_008aa760` first store `MOV [EDI+0x64c],AL` turn-in flag (also reward captions).
- **`FUN_0052dac0`:** returns mission-state `+0x18` reward region (CF High).
- Still open: who writes HandleButton router `+0x648`; chrome FUN_* product names; product function for `0x00924608` (framing sealed); runtime.
