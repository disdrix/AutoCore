# Annotated low-level: DES_PermuteBlock

| Field | Value |
|---|---|
| Stable ID | `aa_0071bd40` |
| VA | `0x0071bd40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071bd40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void DES_PermuteBlock(byte *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *in_EAX;
  int unaff_EBX;
  int iVar3;
  
  in_EAX[0] = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  iVar3 = 0;
  do {
    pbVar1 = (byte *)(unaff_EBX + ((uint)(*param_1 >> 4) + iVar3) * 8);
    pbVar2 = (byte *)(unaff_EBX + 0x80 + ((*param_1 & 0xf) + iVar3) * 8);
    iVar3 = iVar3 + 0x20;
    *in_EAX = *in_EAX | *pbVar2 | *pbVar1;
    param_1 = param_1 + 1;
    in_EAX[1] = in_EAX[1] | pbVar2[1] | pbVar1[1];
    in_EAX[2] = in_EAX[2] | pbVar2[2] | pbVar1[2];
    in_EAX[3] = in_EAX[3] | pbVar2[3] | pbVar1[3];
    in_EAX[4] = in_EAX[4] | pbVar2[4] | pbVar1[4];
    in_EAX[5] = in_EAX[5] | pbVar2[5] | pbVar1[5];
    in_EAX[6] = in_EAX[6] | pbVar2[6] | pbVar1[6];
    in_EAX[7] = in_EAX[7] | pbVar2[7] | pbVar1[7];
  } while (iVar3 < 0x100);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
