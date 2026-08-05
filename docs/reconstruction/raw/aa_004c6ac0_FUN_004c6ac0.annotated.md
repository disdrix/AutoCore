# Annotated low-level: FUN_004c6ac0

| Field | Value |
|---|---|
| Stable ID | `aa_004c6ac0` |
| VA | `0x004c6ac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c6ac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004c6ac0(int param_1,uint param_2)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  
  if ((param_2 & 0x125e) != 0) {
    if ((param_2 & 2) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1c4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1c4) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -0x1a4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1a4) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1c4) + *(int *)(param_1 + -0x1a4) == 0) {
        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);
        *puVar2 = *puVar2 & 0xfffffffd;
      }
    }
    if ((param_2 & 4) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1c0);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1c0) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -0x1a0);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1a0) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1c0) + *(int *)(param_1 + -0x1a0) == 0) {
        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);
        *puVar2 = *puVar2 & 0xfffffffb;
      }
    }
    if ((param_2 & 8) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1bc);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1bc) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -0x19c);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x19c) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1bc) + *(int *)(param_1 + -0x19c) == 0) {
        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);
        *puVar2 = *puVar2 & 0xfffffff7;
      }
    }
    if ((param_2 & 0x10) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1b8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1b8) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -0x198);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x198) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1b8) + *(int *)(param_1 + -0x198) == 0) {
        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);
        *puVar2 = *puVar2 & 0xffffffef;
      }
    }
    if ((param_2 & 0x40) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1b4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1b4) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -0x194);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x194) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1b4) + *(int *)(param_1 + -0x194) == 0) {
        puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x448 + param_1);
        *puVar2 = *puVar2 & 0xffffffbf;
      }
    }
    if ((param_2 & 0x200) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1b0);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1b0) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -400);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -400) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1b0) + *(int *)(param_1 + -400) == 0) {
        pbVar3 = (byte *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x447 + param_1);
        *pbVar3 = *pbVar3 & 0xfd;
      }
    }
    if ((param_2 & 0x1000) != 0) {
      if ((param_2 & 0x100000) == 0) {
        piVar1 = (int *)(param_1 + -0x1ac);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x1ac) = 0;
        }
      }
      else {
        piVar1 = (int *)(param_1 + -0x18c);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          *(undefined4 *)(param_1 + -0x18c) = 0;
        }
      }
      if (*(int *)(param_1 + -0x1ac) + *(int *)(param_1 + -0x18c) == 0) {
        pbVar3 = (byte *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x447 + param_1);
        *pbVar3 = *pbVar3 & 0xef;
      }
    }
    *(bool *)(param_1 + -0x1eb) =
         0 < *(int *)(param_1 + -0x1c4) + *(int *)(param_1 + -0x1c0) + *(int *)(param_1 + -0x1bc) +
             *(int *)(param_1 + -0x1b8) + *(int *)(param_1 + -0x1b4) + *(int *)(param_1 + -0x1b0) +
             *(int *)(param_1 + -0x1ac);
    FUN_004c4e80();
    return;
  }
  puVar2 = (uint *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x448);
  *puVar2 = *puVar2 & ~param_2;
  FUN_004c4e80();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
