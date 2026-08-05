# Annotated low-level: DES_RoundFunctionF

| Field | Value |
|---|---|
| Stable ID | `aa_0071bf70` |
| VA | `0x0071bf70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071bf70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void DES_RoundFunctionF(void)

{
  int iVar1;
  int in_EAX;
  byte local_10;
  byte local_f;
  undefined4 local_e;
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  
  iVar1 = in_EAX * 6;
  DES_CalculateExpansion();
  local_8 = (&DAT_00d16e90)[iVar1] ^ local_10;
  local_7 = (&DAT_00d16e91)[iVar1] ^ local_f;
  local_6 = (&DAT_00d16e92)[iVar1] ^ (byte)local_e;
  local_5 = (&DAT_00d16e93)[iVar1] ^ (byte)((uint)local_e >> 8);
  local_4 = *(byte *)((int)&DAT_00d16e94 + iVar1) ^ (byte)((uint)local_e >> 0x10);
  local_3 = *(byte *)((int)&DAT_00d16e94 + iVar1 + 1) ^ (byte)((uint)local_e >> 0x18);
  DES_CalculateSBoxSubstitution(&local_10);
  DES_CalculatePermutationP(&local_10);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
