# Raw capture: FUN_0076cef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076cef0` |
| **Canonical name** | `FUN_0076cef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0076cef0(void)

{
  return;
}
```

---

## Live re-verify append (2026-07-29 W19-D)

| Check | Result |
|---|---|
| `decompile_function` @ `0x0076cef0` | empty `return;` — **≡** raw |
| `get_function_by_address` | Body `0076cef0`–`0076cef0` (1 byte; exclusive end `0076cef1`) |
| `read_memory` length 32 | **`c3`** then `cc` pad; next leaf `0076cf00` = `8b 41 04 c2 04 00` (Profiler_ScopeEnter) |
| ABI | bare **`ret`** (`c3`, not `ret n`); ignores ECX / stack / EAX |
| Callees | none — classification **stub** |
| Xrefs | **≥100** UNCONDITIONAL_CALL sites (profiler leave fan-in across AI/drive/physics/terrain) |
| Sibling | `aa_0076cf00` Profiler_ScopeEnter (`ret 4` + load timer `@+4`) — enter/leave pair |

**Not the same VA as** enter `0x0076cf00` or mass empties elsewhere. Role is **compiled-out profiler scope leave** (no stack teardown of enter's name arg — leave is bare `ret`).
