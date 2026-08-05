# Raw capture: FUN_0052ade0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ade0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052ade0` |
| **Canonical name** | `FUN_0052ade0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0052ade0(int param_1,undefined4 param_2,int param_3)

{
  int local_4;
  
  local_4 = param_1;
  FUN_00418b80(&local_4,&param_2);
  if (local_4 != *(int *)(param_1 + 0x588)) {
    *(int *)(local_4 + 0x10) = param_3;
    if (*(int *)(local_4 + 0x14) < param_3) {
      *(int *)(local_4 + 0x10) = *(int *)(local_4 + 0x14);
    }
    *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;
  }
  return;
}
```

---

## W37-P re-verify (2026-08-04) — append only

| Field | Value |
|---|---|
| **Tools** | `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes` |
| **Body** | `0x0052ade0`–`0x0052ae21` inclusive (**66 B** / `0x42`); pad `CC` then next |
| **Live decompile** | ≡ 2026-07-23 raw CF |
| **Xrefs** | 1 CODE from `FUN_0094e530` (`Client_DebugCmd_AddDisciplinePoints`) @ `0x0094e5de` |
| **Callees** | `FUN_00418b80` (map lower_bound by int key) only |

### Full body hex (66 B)

```
51568bf18d44240c508d4c2408518d8e84050000e887ddeeff8b4424043b868805000074188b5424108950108b48143bd17e03894810838e34060000405e59c20800
```

### Byte-sealed ABI

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | `Character*` (this) | `MOV ESI,ECX`; map `LEA ECX,[ESI+0x584]` |
| **stack key** | int map key | `&key` pushed to lower_bound |
| **stack value** | int for `node+0x10` | `MOV EDX,[ESP+0x10]`; `MOV [EAX+0x10],EDX` |
| **RET** | `RET 8` (`C2 08 00`) | two stack formals |
| **Return** | void | no EAX out live |

### Byte-sealed CF

1. `FUN_00418b80(map=char+0x584, &out_node, &key)`.
2. If `out_node == *(char+0x588)` (end/sentinel): **no-op return** (does **not** insert).
3. Else: `*(node+0x10) = value`; if `*(node+0x14) < value` then `*(node+0x10) = *(node+0x14)` (clamp high side to current +0x14).
4. `*(char+0x634) |= 0x40` dirty (only on hit).

### Mission-adjacent note

Shares Val12 map @ `char+0x584` with sealed `CVOGCharacter_SetMissionCounter` (`0x005305b0`, writes **+0x14**) and GetResource path (`0x0052ada0`, reads **+0x10**). Sole retail CODE caller is debug slash `adddisciplinepoints` optional "set max" path (W31-T).
