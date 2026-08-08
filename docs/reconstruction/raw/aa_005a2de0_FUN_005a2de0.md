# Raw capture: FUN_005a2de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a2de0` |
| **Canonical name** | `FUN_005a2de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005a2de0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[4] = *param_4;
    puVar1[5] = param_4[1];
    puVar1[6] = param_4[2];
    puVar1[7] = param_4[3];
    puVar1[8] = param_4[4];
    puVar1[9] = param_4[5];
    *(undefined1 *)(puVar1 + 10) = param_5;
    *(undefined1 *)((int)puVar1 + 0x29) = 0;
  }
  return;
}
```

---

## Re-verify 2026-08-04 (WQ9F-A OWN-ONLY)

| Field | Value |
|---|---|
| **Tools** | `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs |
| **Body** | `0x005a2de0`–`0x005a2e3a` inclusive (**91 B** / `0x5B`); terminal **`C2 14 00`** + `CC` pad |
| **Entry** | `6A 30 E8 …` — `push 0x30; call operator_new` |
| **ABI** | **`__stdcall` RET 0x14** (5 stack args × 4); return node* in **EAX** (0 on OOM) |
| **Live decompile** | Identical CF to 2026-07-23 raw; decomp shows `void` — **wrong** (EAX = node) |
| **Callers (3)** | `FUN_004cbb60` @ `004cbbf2`; `FUN_0058da40` @ `0058dad2`; `FUN_005a3310` @ `005a33a2` |
| **Callees** | `operator_new` only |
| **Named** | `StdTree_Buynode_Isnil29_Val24_Inferred` |
| **Layout** | node **0x30**; left/parent/right @+0/+4/+8; **6 dwords value @+0x10**; color@**+0x28**; isnil=0@**+0x29** |

```c
// live 2026-08-04 — same init CF; RET 0x14 sealed by bytes
// returns EAX = node* (decomp void is false)
```
