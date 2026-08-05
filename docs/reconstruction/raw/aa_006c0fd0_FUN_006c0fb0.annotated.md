# Annotated low-level: FUN_006c0fb0

| Field | Value |
|---|---|
| Stable ID | `aa_006c0fd0` |
| VA | `0x006c0fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c0fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_006c0fb0(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  
  if (DAT_009cbf60 != 0) {
    iVar3 = FUN_006c0d20(PTR_s_NetDevilVOG_00af0c50);
    if (DAT_009cbf60 != iVar3) {
      iVar3 = FUN_005e03a0(
                          "Havok client keycode is invalid.\nPlease check that you have entered it correctly in keycode.cpp\nIf this problem persists please contact Havok.com for assistance.\nNo simulation possible."
                          );
      return iVar3;
    }
    DAT_00d09210 = 1;
    return iVar3;
  }
  iVar3 = FUN_00718340();
  cVar2 = *PTR_s_NetDevilVOG_00af0c50;
  puVar4 = PTR_s_NetDevilVOG_00af0c50;
  while (cVar2 != '-') {
    if (cVar2 == '\0') {
      iVar3 = FUN_005e03a0(
                          "Havok evaluation key has expired or is invalid.\nPlease contact Havok.com for an extension.\nNo simulation possible."
                          );
      return iVar3;
    }
    pcVar7 = puVar4 + 1;
    puVar4 = puVar4 + 1;
    cVar2 = *pcVar7;
  }
  pcVar7 = puVar4 + 1;
  cVar2 = puVar4[1];
  pcVar5 = pcVar7;
  while (cVar2 != '-') {
    if (cVar2 == '\0') {
      iVar3 = FUN_005e03a0(
                          "Havok evaluation key has expired or is invalid.\nPlease contact Havok.com for an extension.\nNo simulation possible."
                          );
      return iVar3;
    }
    pcVar1 = pcVar5 + 1;
    pcVar5 = pcVar5 + 1;
    cVar2 = *pcVar1;
  }
  if (pcVar7 != pcVar5) {
    iVar8 = (int)&DAT_00a0d19c - (int)pcVar7;
    do {
      if (((*pcVar7 == '\0') || (pcVar7[iVar8] == '\0')) || (*pcVar7 != pcVar7[iVar8]))
      goto LAB_006c110c;
      pcVar7 = pcVar7 + 1;
    } while (pcVar7 != pcVar5);
  }
  uVar6 = ((pcVar5[4] + -0x41) * 0x1000 | (pcVar5[3] + -0x41) * 0x100 |
           (pcVar5[7] + -0x41) * 0x1000000 | (pcVar5[2] + -0x41) * 0x10 |
           (pcVar5[6] + -0x41) * 0x100000 | (pcVar5[5] + -0x41) * 0x10000 |
           pcVar5[8] * 0x10000000 + 0xf0000000U | (int)pcVar5[1] - 0x41U) ^ DAT_00a0d198;
  iVar8 = uVar6 - (int)uVar6 % 0x15180;
  if ((iVar3 < iVar8) && (iVar8 - iVar3 < 0xed4e00)) {
    DAT_00d09210 = 1;
    return (int)uVar6 / 0x15180;
  }
LAB_006c110c:
  iVar3 = FUN_005e03a0(
                      "Havok evaluation key has expired or is invalid.\nPlease contact Havok.com for an extension.\nNo simulation possible."
                      );
  return iVar3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
