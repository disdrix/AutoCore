# Review A (reconstruction fidelity): `aa_0043d300` GuardedVector_RingAssignBackward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d300` |
| **VA** | `0x0043d300`–`0x0043d38d` (**142 B**) |
| **Canonical name** | `GuardedVector_RingAssignBackward` (**Inferred**) |
| **Ghidra name** | `FUN_0043d300` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-C) |
| **Counterpart** | `reviews/B_aa_0043d300_GuardedVector_RingAssignBackward.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 142 B); callers `0043c8c0`/`0043cb00`/`0043cf40`; leaf (no callees) |
| **Verdict** | **accept** |

---

## 1. Purpose

Reverse ring dword assign between source and destination index cursors:

1. While `(src_container, src_index) != (stop_container, stop_index)`.
2. Decrement src index; map through capacity-wrapped block table; same for dest.
3. `*dst_elem = *src_elem` (dword).
4. Write out iterator `{dst_container, final_dst_index}` and return it.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043d300_FUN_0043d300.md` (+ 2026-07-29 W28-C append) |
| Annotated | `docs/reconstruction/raw/aa_0043d300_FUN_0043d300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackward.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d300.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043d300_FUN_0043d300.md` |
| Named record | `docs/reconstruction/functions/aa_0043d300_GuardedVector_RingAssignBackward.md` |
| Live | decompile ≡ raw; body end `C3` before `FUN_0043d390`; 3 call xrefs |

---

## 3. Signature (sealed)

```c
// 7 stack args; plain RET; returns out_pair
int* GuardedVector_RingAssignBackward(int* out, int stop_c, uint stop_i,
    int src_c, uint src_i, int dst_c, uint dst_i);
```

| Slot | Source | Conf |
|---|---|---|
| out | Stack[+4] | **High** |
| stop/src/dst pairs | Stack[+8..+0x1c] | **High** |
| cleanup | plain `RET` | **High** |
| return | out in EAX | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
while stop_c != src_c || stop_i != src_i:
  src_i--; map block; dst_i--; map block; *dst = *src
out = {dst_c, dst_i}; RET
```

| Stage | Match | Conf |
|---|---|---|
| Reverse decrement both cursors | **Yes** | **High** |
| capacity wrap on block index | **Yes** | **High** |
| dword element assign | **Yes** | **High** |
| out pair write | **Yes** | **High** |
| Leaf (no calls) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full **142 B** hex sealed in raw. Entry `8B 44 24 1C`; epilogue `89 41 04 89 11 8B C1 5B C3`.

---

## 6. Gaps

- Product/PDB class English (`GuardedVector_*` structural).
- Runtime / bit-exact (not required for leaf CF seal).

---

## 7. Verdict

Full body sealed from live decompile ≡ raw ≡ bytes; ABI, reverse CF, ring map, and out-iterator closed with no nested free residual → **accept**.
