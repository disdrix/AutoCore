# Annotated low-level: FUN_008fd1e0

| Field | Value |
|---|---|
| Stable ID | `aa_008fd1e0` |
| VA | `0x008fd1e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fd1e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint FUN_008fd1e0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EBX;
  undefined4 *puVar7;
  int local_128;
  uint local_124;
  int local_120;
  undefined4 local_118 [2];
  byte local_110;
  byte local_10f;
  
  *(undefined4 *)(unaff_EBX + 0x50c) = 0;
  if (*(void **)(unaff_EBX + 0x5fc) != (void *)0x0) {
    operator_delete__(*(void **)(unaff_EBX + 0x5fc));
  }
  *(undefined4 *)(unaff_EBX + 0x5fc) = 0;
  *(undefined4 *)(unaff_EBX + 0x530) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x534) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x538) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x53c) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x540) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x544) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x548) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x54c) = 0xffffffff;
  if ((DAT_00d1b6d8 != 0) && (iVar1 = *(int *)(DAT_00d1b6d8 + 0x250), iVar1 != 0)) {
    uVar2 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) +
                                    0x3c) + 0x716);
    *(uint *)(unaff_EBX + 0x50c) = uVar2;
    puVar3 = operator_new__(uVar2 * 0x110);
    *(undefined4 **)(unaff_EBX + 0x5fc) = puVar3;
    for (uVar2 = (uint)(*(int *)(unaff_EBX + 0x50c) * 0x110) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    *(undefined4 *)(unaff_EBX + 0x550) = *(undefined4 *)(iVar1 + 0x28c);
    *(undefined4 *)(unaff_EBX + 0x530) = *(undefined4 *)(iVar1 + 0x28c);
    *(undefined4 *)(unaff_EBX + 0x554) = *(undefined4 *)(iVar1 + 0x290);
    *(undefined4 *)(unaff_EBX + 0x534) = *(undefined4 *)(iVar1 + 0x290);
    *(undefined4 *)(unaff_EBX + 0x558) = *(undefined4 *)(iVar1 + 0x294);
    *(undefined4 *)(unaff_EBX + 0x538) = *(undefined4 *)(iVar1 + 0x294);
    *(undefined4 *)(unaff_EBX + 0x55c) = *(undefined4 *)(iVar1 + 0x298);
    *(undefined4 *)(unaff_EBX + 0x53c) = *(undefined4 *)(iVar1 + 0x298);
    *(undefined4 *)(unaff_EBX + 0x560) = *(undefined4 *)(iVar1 + 0x29c);
    *(undefined4 *)(unaff_EBX + 0x540) = *(undefined4 *)(iVar1 + 0x29c);
    *(undefined4 *)(unaff_EBX + 0x564) = *(undefined4 *)(iVar1 + 0x2a0);
    *(undefined4 *)(unaff_EBX + 0x544) = *(undefined4 *)(iVar1 + 0x2a0);
    *(undefined4 *)(unaff_EBX + 0x568) = *(undefined4 *)(iVar1 + 0x2a4);
    *(undefined4 *)(unaff_EBX + 0x548) = *(undefined4 *)(iVar1 + 0x2a4);
    *(undefined4 *)(unaff_EBX + 0x56c) = *(undefined4 *)(iVar1 + 0x2a8);
    iVar5 = 0;
    *(undefined4 *)(unaff_EBX + 0x54c) = *(undefined4 *)(iVar1 + 0x2a8);
    local_128 = 0;
    local_124 = 0;
    do {
      iVar6 = 0;
      local_120 = 0;
      if (0 < *(int *)(unaff_EBX + 0x50c)) {
        iVar4 = iVar5 * 0x110;
        do {
          puVar3 = (undefined4 *)
                   (iVar6 + *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac +
                                                      iVar1) + 0x3c) + 0x720));
          puVar7 = local_118;
          for (iVar5 = 0x44; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar7 = puVar7 + 1;
          }
          if (local_110 == local_124) {
            if (local_10f < 0x24) {
              if (local_110 == local_124) {
                local_128 = local_128 + 1;
                puVar3 = local_118;
                puVar7 = (undefined4 *)(*(int *)(unaff_EBX + 0x5fc) + iVar4);
                for (iVar5 = 0x44; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar7 = *puVar3;
                  puVar3 = puVar3 + 1;
                  puVar7 = puVar7 + 1;
                }
                iVar4 = iVar4 + 0x110;
              }
            }
            else {
              *(int *)(unaff_EBX + 0x50c) = *(int *)(unaff_EBX + 0x50c) + -1;
            }
          }
          local_120 = local_120 + 1;
          iVar6 = iVar6 + 0x110;
          iVar5 = local_128;
        } while (local_120 < *(int *)(unaff_EBX + 0x50c));
      }
      local_124 = local_124 + 1;
    } while ((int)local_124 < 8);
    if (iVar5 < *(int *)(unaff_EBX + 0x50c)) {
      *(int *)(unaff_EBX + 0x50c) = iVar5;
    }
    return CONCAT31((int3)(local_124 >> 8),*(undefined1 *)(unaff_EBX + 0x50c));
  }
  return DAT_00d1b6d8 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
