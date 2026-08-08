# Raw capture: FUN_004cba60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cba60` |
| **Canonical name** | `FUN_004cba60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004cba60(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_004cb680();
  if (*(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0) {
    free((void *)**(undefined4 **)(param_1 + 0x10));
    operator_delete__(*(void **)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}
```

---

## Re-verify 2026-08-04 — WQ9E-A dual seal (append only)

| Field | Value |
|---|---|
| **Live tools** | `batch_decompile` / `analyze_function_complete` / `read_memory` / callers / `get_assembly_context` |
| **Decompile ≡ raw 2026-07-23** | **Yes** (identical CF) |
| **Ghidra body** | `004cba60`–`004cba93` inclusive |
| **Body size** | **52 B** / `0x34` (`004cba93 − 004cba60 + 1`) |
| **Entry bytes** | `56 8B F1` (`push esi; mov esi,ecx`) — **`__thiscall`** |
| **Exit bytes** | `5E C3` (`pop esi; ret`) — **bare ret**, no stack arg cleanup |
| **CC pad** | After `ret` at `004cba94+` |
| **Callers (2)** | `FUN_004cbdc0` @ `004cbde6` (`SkillCNDHash_Recreate_Inferred`); `FUN_0051de80` @ `0051dece` (skill hash dtor body) |
| **Callees** | `FUN_004cb680` (release chains → freelist); `free` IAT; `operator_delete[]` |
| **Canonical (dual)** | `SkillCNDHash_DestroyBucketTable_Inferred` |
| **System** | skills-abilities / skill-family CNDHash |
| **Disallowed** | `disassemble_bytes`; Launcher; parent ledger edits |

### Field / free semantics (sealed from live)

1. `*(hash+0x0c) = 0` — zeros **live entry count** at `+0xc` (**not** mask at `+0x08`).
2. `FUN_004cb680` — freelist-walk all bucket chains (0..mask inclusive while `+8` is mask); push nodes to freelist `@+0x20` (nested residual; not OWN).
3. If `*(hash+0x10) != 0`:
   - `free(**(hash+0x10))` — free **contiguous 0xc sentinel slab** (bucket[0] = slab base).
   - `operator_delete[](*(hash+0x10))` — free **pointer array**.
   - `*(hash+0x10) = 0`.
4. Does **not** write `+0x08`, ordered head/tail, freelist head, or lock.
