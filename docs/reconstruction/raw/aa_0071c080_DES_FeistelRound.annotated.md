# Annotated low-level: DES_FeistelRound

| Field | Value |
|---|---|
| Stable ID | `aa_0071c080` |
| VA | `0x0071c080` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071c080`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void DES_FeistelRound(void)

{
  byte *unaff_EBX;
  byte *unaff_EDI;
  undefined4 local_4;
  
  DES_RoundFunctionF(&local_4);
  *unaff_EBX = unaff_EDI[4];
  unaff_EBX[1] = unaff_EDI[5];
  unaff_EBX[2] = unaff_EDI[6];
  unaff_EBX[3] = unaff_EDI[7];
  unaff_EBX[4] = *unaff_EDI ^ (byte)local_4;
  unaff_EBX[5] = unaff_EDI[1] ^ (byte)((uint)local_4 >> 8);
  unaff_EBX[6] = unaff_EDI[2] ^ (byte)((uint)local_4 >> 0x10);
  unaff_EBX[7] = unaff_EDI[3] ^ (byte)((uint)local_4 >> 0x18);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
