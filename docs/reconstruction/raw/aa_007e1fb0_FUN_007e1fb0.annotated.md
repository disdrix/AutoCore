# Annotated low-level: FUN_007e1fb0

| Field | Value |
|---|---|
| Stable ID | `aa_007e1fb0` |
| VA | `0x007e1fb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007e1fb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall
FUN_007e1fb0(char *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  uint uVar3;
  undefined2 extraout_var;
  uint uVar4;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  wchar_t local_90 [66];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b00e2;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    iVar1 = -0x7fffbffc;
  }
  else if (DAT_00d1793c == '\0') {
    ExceptionList = &local_c;
    iVar1 = FUN_007bfd10(param_1,param_2,param_4);
    if (-1 < iVar1) {
      local_100 = *param_4;
      local_cc = param_3[0xb];
      local_98 = param_3[0xc];
      local_c0 = param_3[0xd];
      pwVar2 = wcscpy(local_90,(wchar_t *)((int)param_3 + 0x52));
      local_9c = CONCAT22(extraout_var,*(undefined2 *)((int)param_3 + 0x3e));
      local_c4 = CONCAT22((short)((uint)pwVar2 >> 0x10),*(undefined2 *)(param_3 + 0xf));
      local_ac = param_3[8];
      local_ec = CONCAT22((short)((uint)local_ac >> 0x10),*(undefined2 *)(param_3 + 0x10));
      local_bc = CONCAT22(extraout_var,(ushort)(*(byte *)((int)param_3 + 0x3a) & 1));
      uVar3 = (uint)*(short *)((int)param_3 + 0x3a);
      local_e4 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 1) & 1));
      local_a4 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 2) & 1));
      local_dc = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 3) & 1));
      local_b4 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 4) & 1));
      local_d4 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 5) & 1));
      local_94 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 6) & 1));
      local_f8 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 7) & 1));
      local_d8 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 0xb) & 1));
      local_d0 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 0xc) & 1));
      local_c8 = CONCAT22(extraout_var,(ushort)((byte)(uVar3 >> 0xd) & 1));
      uVar4 = uVar3 >> 0xe & 0xffffff01;
      local_b8 = CONCAT22(extraout_var,(ushort)(byte)uVar4);
      local_b0 = CONCAT22((short)(uVar4 >> 0x10),(ushort)((byte)(uVar3 >> 0xf) & 1));
      local_f0 = param_3[2];
      local_e8 = param_3[3];
      local_a8 = CONCAT22((short)((uint)local_f0 >> 0x10),*(undefined2 *)((int)param_3 + 0x42));
      local_f4 = param_3[1];
      local_a0 = CONCAT22((short)((uint)local_e8 >> 0x10),*(undefined2 *)(param_3 + 0x11));
      local_e0 = param_3[7];
      local_fc = *param_3;
      iVar1 = FUN_007bfa70(param_3 + 0x35,&local_fc);
      if (-1 < iVar1) {
        local_118 = 0;
        local_114 = 0;
        local_110 = 0;
        local_10c = 0;
        local_108 = 0;
        local_104 = 0;
        local_4 = 0;
        FUN_004230d0(&local_118,&local_100);
        iVar1 = FUN_00422fb0(1,1,4);
        if (((((((((iVar1 < 0) || (iVar1 = FUN_00422fb0(1,2,1), iVar1 < 0)) ||
                 (iVar1 = FUN_00422fb0(1,3,4), iVar1 < 0)) ||
                (((iVar1 = FUN_00422fb0(1,4,4), iVar1 < 0 ||
                  (iVar1 = FUN_00422fb0(1,5,0x82), iVar1 < 0)) ||
                 ((iVar1 = FUN_00422fb0(1,6,2), iVar1 < 0 ||
                  ((iVar1 = FUN_00422fb0(1,7,2), iVar1 < 0 ||
                   (iVar1 = FUN_00422fb0(1,8,2), iVar1 < 0)))))))) ||
               (iVar1 = FUN_00422fb0(1,9,2), iVar1 < 0)) ||
              (((((iVar1 = FUN_00422fb0(1,10,2), iVar1 < 0 ||
                  (iVar1 = FUN_00422fb0(1,0xb,2), iVar1 < 0)) ||
                 (iVar1 = FUN_00422fb0(1,0xc,2), iVar1 < 0)) ||
                ((iVar1 = FUN_00422fb0(1,0xd,2), iVar1 < 0 ||
                 (iVar1 = FUN_00422fb0(1,0xe,4), iVar1 < 0)))) ||
               (iVar1 = FUN_00422fb0(1,0xf,2), iVar1 < 0)))) ||
             (((iVar1 = FUN_00422fb0(1,0x10,2), iVar1 < 0 ||
               (iVar1 = FUN_00422fb0(1,0x11,1), iVar1 < 0)) ||
              (((iVar1 = FUN_00422fb0(1,0x12,1), iVar1 < 0 ||
                (((iVar1 = FUN_00422fb0(1,0x13,4), iVar1 < 0 ||
                  (iVar1 = FUN_00422fb0(1,0x14,2), iVar1 < 0)) ||
                 (iVar1 = FUN_00422fb0(1,0x15,4), iVar1 < 0)))) ||
               (((iVar1 = FUN_00422fb0(1,0x16,4), iVar1 < 0 ||
                 (iVar1 = FUN_00422fb0(1,0x17,4), iVar1 < 0)) ||
                (iVar1 = FUN_00422fb0(1,0x18,4), iVar1 < 0)))))))) ||
            (((iVar1 = FUN_00422fb0(1,0x19,2), iVar1 < 0 ||
              (iVar1 = FUN_00422fb0(1,0x1a,2), iVar1 < 0)) ||
             ((iVar1 = FUN_00422fb0(1,0x1b,2), iVar1 < 0 ||
              (((iVar1 = FUN_00422fb0(1,0x1c,4), iVar1 < 0 ||
                (iVar1 = FUN_00422fb0(1,0x1d,2), iVar1 < 0)) ||
               (iVar1 = FUN_00422fb0(1,0x1e,2), iVar1 < 0)))))))) ||
           (((iVar1 = FUN_00422fb0(1,0x1f,2), iVar1 < 0 ||
             (iVar1 = FUN_00422fb0(1,0x20,2), iVar1 < 0)) ||
            (iVar1 = FUN_0041b670(&local_118,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar1 < 0)))) {
          FUN_00423170();
          FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcSimpleObject_Insert::Open");
          local_4 = 0xffffffff;
          FUN_0041a4b0(&local_118);
          iVar1 = 0;
        }
        else {
          FUN_00423170();
          local_4 = 0xffffffff;
          FUN_0041a4b0(&local_118);
        }
      }
    }
  }
  else {
    iVar1 = 0;
  }
  ExceptionList = local_c;
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
