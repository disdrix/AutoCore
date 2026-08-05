# Annotated low-level: FUN_0047dcd0

| Field | Value |
|---|---|
| Stable ID | `aa_0047dcd0` |
| VA | `0x0047dcd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0047dcd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0047dcd0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  bool bVar8;
  
  iVar7 = *(int *)(in_EAX + 0x1448);
  iVar3 = *(int *)(in_EAX + 0xb54 + param_1 * 4);
  iVar6 = param_1 * 2;
  bVar8 = SBORROW4(iVar6,iVar7);
  iVar5 = iVar6 - iVar7;
  if (iVar7 < iVar6) {
    *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;
    return;
  }
  do {
    iVar7 = iVar6;
    if (bVar8 != iVar5 < 0) {
      iVar5 = *(int *)(in_EAX + 0xb58 + iVar6 * 4);
      iVar4 = *(int *)(in_EAX + 0xb54 + iVar6 * 4);
      uVar1 = *(ushort *)(unaff_EDI + iVar5 * 4);
      uVar2 = *(ushort *)(unaff_EDI + iVar4 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(iVar5 + 0x1450 + in_EAX) <= *(byte *)(in_EAX + 0x1450 + iVar4))))) {
        iVar7 = iVar6 + 1;
      }
    }
    iVar5 = *(int *)(in_EAX + 0xb54 + iVar7 * 4);
    uVar1 = *(ushort *)(unaff_EDI + iVar3 * 4);
    uVar2 = *(ushort *)(unaff_EDI + iVar5 * 4);
    if (uVar1 < uVar2) break;
    if ((uVar1 == uVar2) &&
       (*(byte *)(in_EAX + 0x1450 + iVar3) <= *(byte *)(iVar5 + 0x1450 + in_EAX))) {
      *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;
      return;
    }
    *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar5;
    iVar4 = *(int *)(in_EAX + 0x1448);
    iVar6 = iVar7 * 2;
    bVar8 = SBORROW4(iVar6,iVar4);
    iVar5 = iVar6 - iVar4;
    param_1 = iVar7;
  } while (iVar6 <= iVar4);
  *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
