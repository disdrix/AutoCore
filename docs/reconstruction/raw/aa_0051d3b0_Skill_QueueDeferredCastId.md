# Raw capture: Skill_QueueDeferredCastId

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051d3b0` |
| **Canonical name** | `Skill_QueueDeferredCastId` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Skill_QueueDeferredCastId(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10) & 3U) == 0) &&
     (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 4U >> 2)) {
    FUN_0051c3b0(1);
  }
  uVar4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10);
  uVar3 = uVar4 >> 2;
  if (*(uint *)(param_1 + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(param_1 + 8);
  }
  if (*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)(param_1 + 4) + uVar3 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) + (uVar4 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}
```

---

## Append: live re-decompile + asm seal (2026-07-29)

**Tools:** Ghidra `decompile_function` `0x0051d3b0`, `read_memory` 120 B, pcode basic, `get_function_callers`, `get_xrefs_to`, caller `get_assembly_context` @ `0x00517bcd`.

**Integrity:** Original raw body above preserved. This section records verification only.

| Item | Result |
|---|---|
| Live decompile ≡ original raw CF | **Match** |
| Body range | `0x0051d3b0`–`0x0051d424` |
| Epilogue | `ADD [ESI+0x10],1` / `POP ESI` / **`RET 4`** (`C2 04 00`) |
| Grow math | asm `ADD EAX,4; SHR EAX,2` ⇒ **`(size+4)>>2`** (not size+1) |
| Grow call | `PUSH 1; MOV ECX,ESI; CALL FUN_0051c3b0` |
| Block alloc | `PUSH 0x10; CALL operator_new` |
| Sole xref | `Skill_ClearActiveCastCounterAndQueueId` @ `0x00517bd4` |
| `this` at call | slot from `FUN_005169c0`, not outer owner |
| Grow overflow string (callee chain) | `"deque<T> too long"` @ `FUN_0051b5f0` |

**C precedence note on raw line `*(int*)(param_1+0x10)+4U>>2`:** per language rules and asm, this is `(size + 4) >> 2`.
