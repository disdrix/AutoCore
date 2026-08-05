# Review A (reconstruction fidelity): `aa_004bbeb0` Host_ResetHashQueuesVectors_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbeb0` |
| **VA** | `0x004bbeb0`–`0x004bbf18` (**104 B**) |
| **Canonical name** | `Host_ResetHashQueuesVectors_Inferred` |
| **Ghidra name** | `FUN_004bbeb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-N) |
| **Counterpart** | `reviews/B_aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md` |
| **System** | host table reset |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body hex) + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Reset host table state: recreate CNDHash tableC (log2=5), drain three locked queues, clear three dword vectors, optional dual iface `vtbl[+4]`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-N append) | `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ResetHashQueuesVectors_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004bbeb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md` |
| Recreate dual | `aa_004bcce0` CNDHash_Recreate_009cb450 (W30-G **accept-with-gaps**) |
| Live | decompile ≡ stage order; bytes seal ECX targets + tail JMP |

---

## 3. Signature (sealed)

```c
// ECX = host; bare C3; void
void __fastcall Host_ResetHashQueuesVectors_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| return | void | **High** |
| cleanup | bare `C3` (or tail JMP path) | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
CNDHash_Recreate_009cb450(*(this+0x18), 5)
FUN_004bc580(*(this+0x1c))
FUN_004bc580(*(this+0x20))
FUN_004bc580(*(this+0x24))
FUN_00410420(this+0x48, 0, 0)
FUN_00410420(this+0x28, 0, 0)
FUN_00410420(this+0x38, 0, 0)
if flag@+0x0c: CALL (*(this+4))->vtbl[+4]
if flag@+0x0d: tail JMP (*(this+8))->vtbl[+4]
else RET
```

| Stage | Match | Conf |
|---|---|---|
| Recreate log2=5 on ptr+0x18 | `8B 4E 18; 6A 05; E8 → 004bcce0` | **High** |
| Three queue drains | three `MOV ECX,[ESI+disp]; E8 → 004bc580` | **High** |
| Three vector clears | three `LEA ECX,[ESI+disp]; push 0; push 0; E8 → 00410420` | **High** |
| Flag CALL vs tail JMP | `FF 50 04` vs `FF 62 04` | **High** |
| Decompiler jumptable warn | **false** (tail JMP) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (104 B) — see raw W31-N append.

Entry: `56 8B F1`. Epilogue: `5E C3` or tail `5E FF 62 04`. Pad `CC` then `FUN_004bbf20`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004d98f0`, `FUN_00943b80` (teardown after object sweeps) |
| Closes | W30-G residual “Host `FUN_004bbeb0` product role not OWN” (structural role now dualed; product English still open) |

---

## 7. Gaps

- Product/PDB host class name and global identity at call sites.
- Product names for three queues / three vectors / dual ifaces.
- Nested `FUN_004bc580` / `FUN_00410420` full dual ownership residual (not OWN here).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Stage order, ABI, ECX targets, and tail path sealed from bytes. Product English residual → **accept-with-gaps**.
