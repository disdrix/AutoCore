# Review A (reconstruction fidelity): `aa_0043ec50` GuardedVector_RingAssignForward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ec50` |
| **VA** | `0x0043ec50`–`0x0043ecdc` (**140 B** / `0x8C`) |
| **Canonical name** | `GuardedVector_RingAssignForward` (**Inferred**) |
| **Ghidra name** | `FUN_0043ec50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-J) |
| **Counterpart** | `reviews/B_aa_0043ec50_GuardedVector_RingAssignForward.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (200 B) + `get_function_by_address` + `analyze_function_complete`; 4 callers / 7 xrefs; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Forward ring dword assign over capacity-wrapped block pages: copy `[src_idx, src_end)` into destination starting at `dst_idx`, then write final `{dst_cont, dst_idx}` into `out_pair`. Leaf for thiscall insert family forward arms (`InsertN_Thiscall`, `InsertRange`, `InsertRange_Thiscall`, `FUN_0043df90`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ec50_FUN_0043ec50.md` (+ 2026-07-29 W33-J append) |
| Annotated | `docs/reconstruction/raw/aa_0043ec50_FUN_0043ec50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignForward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ec50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ec50_FUN_0043ec50.md` |
| Named record | `docs/reconstruction/functions/aa_0043ec50_GuardedVector_RingAssignForward.md` |
| Live | decompile ≡ raw CF; full body hex; plain RET; leaf |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// 7 stack args; plain RET (caller cleans 0x1C)
GuardedVectorIteratorPair* GuardedVector_RingAssignForward(
    GuardedVectorIteratorPair* out_pair,
    GuardedVectorHeader* src_container, uint32_t src_index,
    GuardedVectorHeader* src_end_container, uint32_t src_end_index,
    GuardedVectorHeader* dst_container, uint32_t dst_index);
```

| Slot | Source | Conf |
|---|---|---|
| out_pair | stack `[esp+4]` | **High** |
| src_container / src_index | stack | **High** |
| src_end pair | stack | **High** |
| dst_container / dst_index | stack | **High** |
| cleanup | bare `RET` (`C3`) | **High** |
| container fields | slots@+4, capacity@+8 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
while (src_cont,src_idx) != (end_cont,end_idx):
  map src_idx → src_elem*  (block>>2, wrap, lane)
  map dst_idx → dst_elem*
  if dst_elem != src_elem: *dst_elem = *src_elem
  src_idx++; dst_idx++
out_pair = {dst_cont, dst_idx}
```

| Stage | Match | Conf |
|---|---|---|
| Forward +1 both indices | **Yes** | **High** |
| Block map + capacity wrap | **Yes** | **High** |
| Self-pointer skip | **Yes** | **High** |
| Out-pair write | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body length **140 B** (`0x8C`). Terminal bare `C3`. Pad `CC` then `FUN_0043ece0`. Full hex: raw W33-J append.

---

## 6. Gaps

- Product/PDB class English.
- Byte-level delta vs older-family `FUN_0043d390` `RingCopyElements` residual.
- Twin reverse `FUN_0043ebb0` free (unowned).
- Runtime / bit-exact on wrap edges.

---

## 7. Verdict

ABI, forward CF, ring map, self-skip, and out-pair sealed from live decompile + full-body `read_memory` + 7 call sites → **accept**.
