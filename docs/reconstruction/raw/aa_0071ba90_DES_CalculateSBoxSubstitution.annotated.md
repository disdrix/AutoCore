# Annotated low-level: DES_CalculateSBoxSubstitution

| Field | Value |
|---|---|
| Stable ID | `aa_0071ba90` |
| VA | `0x0071ba90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071ba90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void DES_CalculateSBoxSubstitution(undefined1 *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte *in_EAX;
  
  bVar1 = in_EAX[2];
  bVar2 = in_EAX[1];
  bVar3 = in_EAX[3];
  bVar4 = in_EAX[4];
  bVar5 = in_EAX[5];
  *param_1 = (&DAT_00d12e90)[(int)(char)bVar2 >> 4 & 0xfU | (uint)*in_EAX << 4];
  param_1[1] = (&DAT_00d13e90)[(int)CONCAT11(bVar2,bVar1) & 0xfff];
  param_1[2] = (&DAT_00d14e90)[(int)(char)bVar4 >> 4 & 0xfU | (uint)bVar3 << 4];
  param_1[3] = (&DAT_00d15e90)[(int)CONCAT11(bVar4,bVar5) & 0xfff];
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
