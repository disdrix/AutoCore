# Annotated low-level: FUN_006fae60

| Field | Value |
|---|---|
| Stable ID | `aa_006fae60` |
| VA | `0x006fae60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fae60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006fae60(undefined1 *param_1,float *param_2)

{
  float fVar1;
  char *pcVar2;
  int iVar3;
  undefined1 uVar4;
  ushort local_ec [2];
  undefined2 local_e8;
  undefined1 local_e1;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  undefined1 local_b0 [56];
  ushort local_78;
  undefined1 local_70 [108];
  
  uVar4 = 0;
  FUN_006fb0c0();
  local_e8 = 0;
  FUN_006f8f00();
  pcVar2 = (char *)FUN_006f91d0(&local_e1);
  if (*pcVar2 != '\0') {
    iVar3 = FUN_006fabe0(local_70,local_ec,local_b0);
    if (iVar3 != 2) {
      *param_1 = 0;
      return;
    }
    uVar4 = 1;
    if (local_78 < 3) {
      FUN_006f8590(&local_e0,local_ec,local_b0);
    }
    else if (local_78 < 6) {
      FUN_006f8720(&local_e0,local_ec,local_b0);
    }
    else {
      FUN_006f87d0(&local_e0,local_ec,local_b0);
    }
    if (2 < local_ec[0]) {
      fVar1 = -local_d4;
      local_e0 = local_d0 * fVar1 + local_e0;
      local_dc = local_cc * fVar1 + local_dc;
      local_d8 = local_c8 * fVar1 + local_d8;
      local_d4 = local_c4 * fVar1 + local_d4;
    }
    param_2[4] = local_d0;
    param_2[5] = local_cc;
    param_2[6] = local_c8;
    param_2[7] = local_c4;
    param_2[2] = local_d8;
    param_2[3] = local_d4;
    *param_2 = local_e0;
    param_2[1] = local_dc;
    param_2[3] = local_d4;
  }
  *param_1 = uVar4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
