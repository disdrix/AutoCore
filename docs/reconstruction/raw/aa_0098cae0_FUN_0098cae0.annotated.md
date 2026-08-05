# Annotated low-level: FUN_0098cae0

| Field | Value |
|---|---|
| Stable ID | `aa_0098cae0` |
| VA | `0x0098cae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0098cae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0098cae0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_EBX;
  byte *pbVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  undefined4 uVar8;
  undefined4 local_108 [65];
  
  *(undefined2 *)(unaff_EBX + 0x77e) = 0;
  iVar2 = FUN_00796d40();
  puVar6 = local_108;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  if (*(int *)(iVar2 + 0x70) == 0) {
    local_108[0] = 0;
    local_108[1] = 0;
    local_108[2] = 0;
    local_108[3] = 0;
    local_108[4] = 0;
    if (*(int *)(iVar2 + 0x74) == 0) {
      puVar6 = local_108;
      for (iVar3 = 0x44; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      if (*(int *)(iVar2 + 0x78) == 0) {
        return 0;
      }
      piVar4 = *(int **)(iVar2 + 0x78);
      iVar2 = *piVar4;
      uVar8 = 0x110;
    }
    else {
      piVar4 = *(int **)(iVar2 + 0x74);
      iVar2 = *piVar4;
      uVar8 = 0x14;
    }
    (**(code **)(iVar2 + 0x24))(piVar4,uVar8,local_108);
  }
  else {
    (**(code **)(**(int **)(iVar2 + 0x70) + 0x24))(*(int **)(iVar2 + 0x70),0x100,local_108);
  }
  iVar2 = 0;
  pbVar7 = &stack0xfffffeec;
  pbVar5 = (byte *)(unaff_EBX + 0x558);
  do {
    sVar1 = (short)iVar2;
    if ((sVar1 == 0x2a) || (sVar1 == 0x36)) {
      if ((*pbVar7 & 0x80) != 0) {
        *(short *)(unaff_EBX + 0x77e) = sVar1;
      }
    }
    else if (*pbVar7 == *pbVar5) {
      if ((byte *)(uint)*(ushort *)(unaff_EBX + 0x77c) == pbVar5 + (-0x558 - unaff_EBX)) {
        *(undefined1 *)(unaff_EBX + 0x780) = 1;
      }
    }
    else if ((char)*pbVar5 < '\0') {
      *pbVar5 = *pbVar7;
    }
    else {
      *(short *)(unaff_EBX + 0x77c) = sVar1;
    }
    iVar2 = iVar2 + 1;
    pbVar5 = pbVar5 + 1;
    pbVar7 = pbVar7 + 1;
  } while ((ushort)iVar2 < 0xf0);
  return CONCAT31((int3)((uint)iVar2 >> 8),*(char *)(unaff_EBX + 0x780) != '\0');
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
