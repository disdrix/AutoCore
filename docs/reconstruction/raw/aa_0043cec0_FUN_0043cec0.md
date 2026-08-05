# Raw capture: FUN_0043cec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043cec0` |
| **Canonical name** | `FUN_0043cec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0043cec0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_0043cf40(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return;
}
```

---

## Live re-verify — 2026-07-29 (OWN-ONLY W27-C)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `analyze_function_complete` + `read_memory` |
| **Program** | `autoassault.exe` base `0x400000` |
| **Live ≡ raw scaffold** | **Yes** (CF/pseudocode match 2026-07-23 body) |
| **Body span** | `0x0043cec0`–`0x0043ceef` (**48 B** / `0x30`; next fn `FUN_0043cef0`) |
| **Classification** | worker / thin trampoline (1 callee) |
| **Xrefs (1)** | `0x0043c7c5` (`FUN_0043c730` grow path only) |
| **Callers** | `FUN_0043c730` (`GuardedVector_CopyAssign`) only |
| **Callees** | `FUN_0043cf40` @ call `0x0043cee8` |

### ABI (bytes)

| Slot | Role |
|---|---|
| **Stack[0x04..0x1c]** | seven `uint32_t` formals (`param_1`…`param_7`) |
| Epilogue | `RET 0x1c` (**stdcall** cleans 7×4) |
| Behavior | re-push all seven args, then push `param_1` again as 8th; `CALL FUN_0043cf40` |

### Control flow (sealed)

```
FUN_0043cf40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_1);
return;
```

Sole parent grow call shape (`FUN_0043c730`):

```
FUN_0043cec0(dest, dest, dest.size+dest.begin,
             source, source.begin+dest.size,
             source, source.size+source.begin);
```

### Full body hex (48 B)

```
8b4424048b4c241c8b542418508b442418518b4c2418528b542418508b442418518b4c2418525051e853000000c21c00
```

```
8B 44 24 04       MOV EAX, [ESP+4]     ; param_1
…                 ; re-stack param_7..param_1 for 8-arg call
E8 53 00 00 00    CALL FUN_0043cf40    ; @ 0x0043cee8 → 0x0043cf40
C2 1C 00          RET 0x1c
```
