# Raw capture: FUN_0044adc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044adc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044adc0` |
| **Canonical name** | `FUN_0044adc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044adc0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009bcaea;
  pvStack_c = ExceptionList;
  local_4 = 1;
  piVar1 = param_1 + 3;
  ExceptionList = &pvStack_c;
  param_1[2] = 0;
  piVar3 = (int *)*piVar1;
  if (piVar3 != (int *)0x0) {
    piVar2 = piVar3 + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (**(code **)(*piVar3 + 8))();
    }
    *piVar1 = 0;
  }
  *param_1 = 0;
  piVar3 = (int *)param_1[1];
  if (piVar3 != (int *)0x0) {
    piVar2 = piVar3 + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (**(code **)(*piVar3 + 8))();
    }
    param_1[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00437150(piVar1);
  local_4 = 0xffffffff;
  FUN_00437150(param_1 + 1);
  ExceptionList = pvStack_c;
  return;
}
```

---

# APPEND 2026-07-29 W22-S live dual seal — do not alter body above

## Live re-decompile (Ghidra MCP `decompile_function` + `analyze_function_complete`, 2026-07-29)

```c
void FUN_0044adc0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009bcaea;
  pvStack_c = ExceptionList;
  local_4 = 1;
  piVar1 = param_1 + 3;
  ExceptionList = &pvStack_c;
  param_1[2] = 0;
  piVar3 = (int *)*piVar1;
  if (piVar3 != (int *)0x0) {
    piVar2 = piVar3 + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (**(code **)(*piVar3 + 8))();
    }
    *piVar1 = 0;
  }
  *param_1 = 0;
  piVar3 = (int *)param_1[1];
  if (piVar3 != (int *)0x0) {
    piVar2 = piVar3 + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (**(code **)(*piVar3 + 8))();
    }
    param_1[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00437150(piVar1);
  local_4 = 0xffffffff;
  FUN_00437150(param_1 + 1);
  ExceptionList = pvStack_c;
  return;
}
```

Live decompile ≡ 2026-07-23 raw. Bytes seal **`ret 4`** (`__stdcall` 1 stack arg) and SEH frame (`fs:[0]`, handler `LAB_009bcaea`).

## Machine bytes (`read_memory` @ `0x0044adc0`, length 256; body 145 B)

Hex (body through final `ret 4`):
```
64a1000000006aff68eaca9b005064892500000000568b74241457c7442410010000008d7e0cc74608000000008b0f85c97411834104ff75058b01ff5008c70700000000c706000000008b4e0483c60485c97411834104ff75058b11ff5208c7060000000057c644241400e820c3feff56c7442414ffffffffe812c3feff8b4c24085f64890d000000005e83c40cc20400
```

Range: **`0x0044adc0`–`0x0044ae50`** (145 B inclusive through final `00` of `ret 4`). Trailing `CC` pad.

## Byte-reconstructed control flow (≡ decompile + ABI fill)

```
// stack arg: pairBlock*  (ESI after frame)
// layout:
//   +0x00 owner/raw out 1  — cleared, no Release
//   +0x04 refcounted* A    — Release protocol
//   +0x08 owner/raw out 2  — cleared first
//   +0x0C refcounted* B    — Release protocol
// Ref protocol: obj+4 refcount--; if 0 call [vtbl+8]; clear slot
// then FUN_00437150(&slotB); FUN_00437150(&slotA)  (already null → no-op path)
// ret 4
```

Callee targets (rel32 sealed): both `E8` → **`FUN_00437150` @ `0x00437150`**.

## Callers (7 xrefs)

| Parent (Ghidra) | Role context |
|---|---|
| `ClientSpecialEvent_TeleportIn_ctor` | special-event dual-slot teardown |
| `ClientSpecialEvent_Respawn_Update` | same |
| `FUN_0096d550`, `FUN_0096d5c0`, `FUN_0096dc80` | pair bind sites (also call `Phy_CPConnection_AssertConnectionPoint`) |
| `FUN_009784f0`, `FUN_00855ff0` | related teardown |

Sibling `Phy_CPConnection_AssertConnectionPoint` (`0x0044af00`) binds into the same pair layout (`+4` / `+0xC` smart slots, `+0` / `+8` owner outs); failure path tears down via this unit.
