# Annotated low-level: FUN_004fcb50

| Field | Value |
|---|---|
| Stable ID | `aa_004fcb50` |
| VA | `0x004fcb50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fcb50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint FUN_004fcb50(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char local_130 [31];
  char cStack_111;
  char local_110 [2];
  undefined4 uStack_10e;
  
  uVar5 = 0;
  local_110[0] = '\0';
  local_110[1] = '\0';
  puVar7 = &uStack_10e;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  while( true ) {
    FUN_004fc4c0(local_110);
    if (uVar5 + 1 < 10) {
      pcVar8 = "_0%i_t";
    }
    else {
      pcVar8 = "_%i_t";
    }
    sprintf(local_130,pcVar8,uVar5 + 1);
    pcVar8 = local_130;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar2 = (int)pcVar8 - (int)local_130;
    pcVar8 = &cStack_111;
    do {
      pcVar6 = pcVar8 + 1;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar6 != '\0');
    pcVar6 = local_130;
    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar8 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar8 = &cStack_111;
    do {
      pcVar6 = pcVar8;
      pcVar8 = pcVar6 + 1;
    } while (pcVar6[1] != '\0');
    pcVar8 = local_110;
    *(undefined4 *)(pcVar6 + 1) = DAT_00a2c53c;
    pcVar6[5] = DAT_00a2c540;
    FUN_007b6a20(pcVar8);
    cVar1 = FUN_007b6770(pcVar8);
    if (cVar1 == '\0') break;
    uVar5 = (uint)(byte)((char)uVar5 + 1);
  }
  return uVar5;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
