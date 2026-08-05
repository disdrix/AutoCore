# Annotated low-level: FUN_004b1cb0

| Field | Value |
|---|---|
| Stable ID | `aa_004b1cb0` |
| VA | `0x004b1cb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004b1cb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004b1cb0(int *param_1)

{
  byte bVar1;
  int iVar2;
  int local_44;
  int local_40;
  int local_3c;
  undefined1 local_34 [16];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  local_44 = param_1[0x5e];
  local_40 = param_1[0x5f];
  local_3c = param_1[0x60];
  FUN_004b0d60(local_34,param_1[0x20]);
  iVar2 = *param_1;
  local_24 = param_1[0xd];
  local_c = *(float *)(iVar2 + 0x8bc) * (float)param_1[4];
  local_8 = *(float *)(iVar2 + 0x8bc) * (float)param_1[6];
  local_1c = param_1[0x61];
  local_18 = param_1[0x62];
  local_14 = param_1[99];
  local_20 = param_1[0xc];
  local_4 = *(undefined4 *)(iVar2 + 0x8f4);
  if (*(char *)((int)param_1 + 0x241) != '\0') {
    if ((*(byte *)(iVar2 + 0x989) & 0x80) != 0) {
      FUN_007a24f0(&local_44);
      return;
    }
    FUN_007a24c0(&local_44);
    return;
  }
  bVar1 = *(byte *)(iVar2 + 0x98a);
  if ((bVar1 & 2) != 0) {
    FUN_007a2550(&local_44);
    return;
  }
  if ((bVar1 & 4) != 0) {
    FUN_007a2450(&local_44);
    return;
  }
  if ((bVar1 & 8) != 0) {
    FUN_007a2410(&local_44);
    return;
  }
  if ((*(byte *)(iVar2 + 0x989) & 0x80) != 0) {
    FUN_007a2520(&local_44);
    return;
  }
  FUN_007a2490(&local_44);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
