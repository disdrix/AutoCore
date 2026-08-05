# Raw capture: FUN_0040abf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040abf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040abf0` |
| **Canonical name** | `FUN_0040abf0` → sealed `Item_CanAcceptStackQty` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0040abf0(int *param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1[0x2a] + 0x38) == 4) {
    uVar3 = 999999;
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4ba);
    uVar3 = (uint)uVar1;
    if (uVar1 == 0) {
      uVar3 = 200;
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x25c))();
  return CONCAT31((int3)(iVar2 + (uint)param_2 >> 8),
                  (int)(iVar2 + (uint)param_2) <= (int)(uVar3 & 0xffff));
}
```

---

## Live re-decompile (2026-07-29) — dual A/B seal

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` |
| **Canonical name (sealed)** | `Item_CanAcceptStackQty` |
| **Integrity** | Body ≡ 2026-07-23 raw; bytes seal formula + u16 mask |

### Live pseudocode

```c
undefined4 __thiscall FUN_0040abf0(int *param_1, ushort param_2)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;

  if (*(int *)(param_1[0x2a] + 0x38) == 4) {
    uVar3 = 999999;
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4ba);
    uVar3 = (uint)uVar1;
    if (uVar1 == 0) {
      uVar3 = 200;
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x25c))();
  return CONCAT31((int3)(iVar2 + (uint)param_2 >> 8),
                  (int)(iVar2 + (uint)param_2) <= (int)(uVar3 & 0xffff));
}
```

### Live bytes @ `0x0040abf0` (length 0x44 + pad)

```
8b81a8000000 83 78 38 04 56 75 07 be 3f420f00 eb 17
8b403c 668b80ba040000 6685c0 0fb7f0 77 05 be c8000000
8b11 ff925c020000 0fb74c2408 03c1 0fb7d6 33c9 3bc2
0f9ec1 8ac1 5e c20400
```

**Note:** `CONCAT31` is decompiler noise; retail returns **bool in AL** via `setle`/`mov al,cl`. Type-4 max compare uses `movzx edx,si` → effective **16959**.
