# Annotated low-level: FUN_0047dfc0

| Field | Value |
|---|---|
| Stable ID | `aa_0047dfc0` |
| VA | `0x0047dfc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0047dfc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0047dfc0(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EBX;
  uint uVar7;
  int iVar8;
  int unaff_EDI;
  ushort auStack_20 [16];
  
  uVar4 = 0;
  iVar8 = 1;
  do {
    iVar2 = iVar8 + 1;
    uVar4 = (*(short *)(param_2 + iVar8 * 2 + -2) + uVar4) * 2;
    auStack_20[iVar8] = uVar4;
    iVar8 = iVar2;
  } while (iVar2 < 0x10);
  iVar8 = 0;
  if (-1 < unaff_EBX) {
    do {
      uVar6 = (uint)*(ushort *)(unaff_EDI + 2 + iVar8 * 4);
      if (uVar6 != 0) {
        uVar5 = (uint)auStack_20[uVar6];
        auStack_20[uVar6] = auStack_20[uVar6] + 1;
        uVar1 = 0;
        do {
          uVar3 = uVar1;
          uVar7 = uVar5 & 1;
          uVar6 = uVar6 - 1;
          uVar5 = uVar5 >> 1;
          uVar1 = (uVar3 | uVar7) * 2;
        } while (0 < (int)uVar6);
        *(ushort *)(unaff_EDI + iVar8 * 4) = (ushort)uVar3 | (ushort)uVar7;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 <= unaff_EBX);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
