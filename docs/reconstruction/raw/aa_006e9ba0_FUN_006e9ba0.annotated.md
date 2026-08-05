# Annotated low-level: FUN_006e9ba0

| Field | Value |
|---|---|
| Stable ID | `aa_006e9ba0` |
| VA | `0x006e9ba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e9ba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006e9ba0(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined8 uVar1;
  float unaff_EBX;
  float unaff_ESI;
  float local_f4;
  float local_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  int iStack_9c;
  undefined4 *puStack_98;
  int iStack_94;
  undefined1 local_50 [76];
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtMopp";
    uVar1 = rdtsc();
    local_f4 = (float)uVar1;
    DAT_00bc5644[1] = local_f4;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_0063a3f0(*(int *)(param_2 + 8) + 0x20,param_1[2] + 0x20);
  (**(code **)(*(int *)*param_1 + 0x18))(local_50,*(undefined4 *)(param_3 + 8),&local_f0);
  FUN_005d6a40(*(int *)(param_2 + 8) + 0x20,param_3 + 0x10);
  fStack_a0 = *(float *)(param_3 + 8);
  puStack_98 = param_1;
  fStack_cc = (unaff_ESI + fStack_ec) * DAT_00a0f298;
  iStack_94 = param_2;
  fStack_c8 = (fStack_e8 + unaff_EBX) * DAT_00a0f298;
  fStack_c4 = (fStack_e4 + local_f4) * DAT_00a0f298;
  fStack_c0 = (fStack_e0 + local_f0) * DAT_00a0f298;
  fStack_bc = fStack_dc + fStack_cc;
  fStack_b8 = fStack_d8 + fStack_c8;
  fStack_b4 = fStack_d4 + fStack_c4;
  fStack_b0 = fStack_d0 + fStack_c0;
  fStack_ac = (fStack_ec - unaff_ESI) * DAT_00a0f298 + fStack_a0;
  fStack_a8 = (fStack_e8 - unaff_EBX) * DAT_00a0f298 + fStack_a0;
  fStack_a4 = (fStack_e4 - local_f4) * DAT_00a0f298 + fStack_a0;
  iStack_9c = param_3;
  fStack_a0 = (fStack_e0 - local_f0) * DAT_00a0f298 + fStack_a0;
  FUN_007004a0(&fStack_cc,param_4,param_5);
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
