# Annotated low-level: FUN_0047ccf0

| Field | Value |
|---|---|
| Stable ID | `aa_0047ccf0` |
| VA | `0x0047ccf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0047ccf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0047ccf0(byte *param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  int in_EAX;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (param_2 == 0xff) {
    bVar1 = *(byte *)(in_EAX + 0x10b);
    if (bVar1 < 8) {
      uVar3 = (uint)bVar1 * *(int *)(in_EAX + 200) + 7 >> 3;
    }
    else {
      uVar3 = (uint)(bVar1 >> 3) * *(int *)(in_EAX + 200);
    }
    pbVar5 = (byte *)(*(int *)(in_EAX + 0xec) + 1);
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pbVar5;
      pbVar5 = pbVar5 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      param_1 = param_1 + 1;
    }
    return;
  }
  bVar1 = *(byte *)(in_EAX + 0x10b);
  if (bVar1 == 1) {
    iVar7 = *(int *)(in_EAX + 200);
    pbVar5 = (byte *)(*(int *)(in_EAX + 0xec) + 1);
    local_10 = 0x80;
    if ((*(byte *)(in_EAX + 0x72) & 1) == 0) {
      iVar6 = 7;
      local_4 = 0;
      local_8 = -1;
      iVar8 = iVar6;
    }
    else {
      iVar6 = 0;
      local_4 = 7;
      local_8 = 1;
      iVar8 = iVar6;
    }
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      if ((local_10 & param_2) != 0) {
        bVar1 = (byte)iVar6;
        *param_1 = (byte)(0x7f7f >> (7 - bVar1 & 0x1f)) & *param_1 |
                   (*pbVar5 >> (bVar1 & 0x1f) & 1) << (bVar1 & 0x1f);
      }
      if (iVar6 == local_4) {
        pbVar5 = pbVar5 + 1;
        param_1 = param_1 + 1;
        iVar6 = iVar8;
      }
      else {
        iVar6 = iVar6 + local_8;
      }
      if (local_10 == 1) {
        local_10 = 0x80;
      }
      else {
        local_10 = (int)local_10 >> 1;
      }
    }
  }
  else if (bVar1 == 2) {
    local_c = *(int *)(in_EAX + 200);
    pbVar5 = (byte *)(*(int *)(in_EAX + 0xec) + 1);
    local_10 = 0x80;
    if ((*(byte *)(in_EAX + 0x72) & 1) == 0) {
      iVar7 = 6;
      local_4 = 0;
      local_8 = -2;
    }
    else {
      iVar7 = 0;
      local_4 = 6;
      local_8 = 2;
    }
    iVar6 = iVar7;
    if (local_c != 0) {
      do {
        if ((local_10 & param_2) != 0) {
          bVar1 = (byte)iVar6;
          *param_1 = (byte)(0x3f3f >> (6 - bVar1 & 0x1f)) & *param_1 |
                     (*pbVar5 >> (bVar1 & 0x1f) & 3) << (bVar1 & 0x1f);
        }
        if (iVar6 == local_4) {
          pbVar5 = pbVar5 + 1;
          param_1 = param_1 + 1;
          iVar6 = iVar7;
        }
        else {
          iVar6 = iVar6 + local_8;
        }
        if (local_10 == 1) {
          local_10 = 0x80;
        }
        else {
          local_10 = (int)local_10 >> 1;
        }
        local_c = local_c + -1;
      } while (local_c != 0);
      return;
    }
  }
  else if (bVar1 == 4) {
    local_4 = *(int *)(in_EAX + 200);
    pbVar5 = (byte *)(*(int *)(in_EAX + 0xec) + 1);
    local_10 = 0x80;
    if ((*(byte *)(in_EAX + 0x72) & 1) == 0) {
      iVar7 = 4;
      local_c = 0;
      local_8 = -4;
    }
    else {
      iVar7 = 0;
      local_c = 4;
      local_8 = 4;
    }
    iVar6 = iVar7;
    if (local_4 != 0) {
      do {
        if ((local_10 & param_2) != 0) {
          bVar1 = (byte)iVar6;
          *param_1 = (byte)(0xf0f >> (4 - bVar1 & 0x1f)) & *param_1 |
                     (*pbVar5 >> (bVar1 & 0x1f) & 0xf) << (bVar1 & 0x1f);
        }
        if (iVar6 == local_c) {
          pbVar5 = pbVar5 + 1;
          param_1 = param_1 + 1;
          iVar6 = iVar7;
        }
        else {
          iVar6 = iVar6 + local_8;
        }
        if (local_10 == 1) {
          local_10 = 0x80;
        }
        else {
          local_10 = (int)local_10 >> 1;
        }
        local_4 = local_4 + -1;
      } while (local_4 != 0);
      return;
    }
  }
  else {
    uVar3 = (uint)(bVar1 >> 3);
    local_c = *(int *)(in_EAX + 200);
    pbVar5 = (byte *)(*(int *)(in_EAX + 0xec) + 1);
    bVar2 = 0x80;
    if (local_c != 0) {
      do {
        if (((byte)param_2 & bVar2) != 0) {
          pbVar9 = pbVar5;
          pbVar10 = param_1;
          for (uVar4 = (uint)(bVar1 >> 5); uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined4 *)pbVar10 = *(undefined4 *)pbVar9;
            pbVar9 = pbVar9 + 4;
            pbVar10 = pbVar10 + 4;
          }
          for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pbVar10 = *pbVar9;
            pbVar9 = pbVar9 + 1;
            pbVar10 = pbVar10 + 1;
          }
        }
        param_1 = param_1 + uVar3;
        pbVar5 = pbVar5 + uVar3;
        if (bVar2 == 1) {
          bVar2 = 0x80;
        }
        else {
          bVar2 = bVar2 >> 1;
        }
        local_c = local_c + -1;
      } while (local_c != 0);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
