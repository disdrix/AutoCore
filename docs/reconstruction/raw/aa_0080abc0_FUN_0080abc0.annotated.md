# Annotated low-level: FUN_0080abc0

| Field | Value |
|---|---|
| Stable ID | `aa_0080abc0` |
| VA | `0x0080abc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080abc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0080abc0(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  void *pvVar4;
  char *pcVar5;
  int unaff_EBX;
  undefined4 unaff_EDI;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char local_114 [20];
  char acStack_100 [256];
  
  FUN_007a69d0();
  if (*(char *)(unaff_EBX + 0x10) == '\0') {
    switch(*(undefined4 *)(unaff_EBX + 0x14)) {
    case 2:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: You cannot invite yourself!",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 3:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: Your convoy is already full.",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 4:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: Player already in a convoy.",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    default:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request was rejected.",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 6:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: You cannot invite an enemy!",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 7:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: Player already has a convoy pending.",
                           0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 8:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: You are currently waiting on a convoy.",
                           0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 9:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Invitation request declined: Player is currently busy.",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    case 10:
      uVar8 = 0;
      uVar7 = 1;
      uVar6 = 0xffffffff;
      uVar2 = FUN_007a6de0("Only the leader of the convoy can invite other members.",0xffffffff);
      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);
      return;
    }
  }
  if (*(char *)(unaff_EBX + 0x11) == '\0') {
    pcVar3 = (char *)FUN_007a6de0("Player",0xffffffff);
    pcVar5 = local_114;
    do {
      cVar1 = *pcVar3;
      *pcVar5 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pvVar4 = Client_LookupObjectByTfid_Inferred
                       (1,*(uint *)(unaff_EBX + 8),*(uint *)(unaff_EBX + 0xc));
    if (pvVar4 != (void *)0x0) {
      pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar4 + 4) + 4) + 4 +
                                            (int)pvVar4) + 0x160))();
      pcVar5 = local_114;
      do {
        cVar1 = *pcVar3;
        *pcVar5 = cVar1;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    }
    if (*(int *)(unaff_EBX + 0x14) == 9) {
      uVar2 = FUN_007a6de0("is currently busy",0xffffffff);
      pcVar5 = local_114;
      uVar6 = FUN_007a6de0("Invitation request declined",0xffffffff);
      sprintf(acStack_100,"%s: %s %s.",uVar6,pcVar5,uVar2);
    }
    else {
      uVar2 = FUN_007a6de0("has declined your convoy invitation",0xffffffff);
      sprintf(acStack_100,"%s %s.",local_114,uVar2);
    }
    FUN_007fdfb0(unaff_EDI,acStack_100,0xffffffff,1,0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
