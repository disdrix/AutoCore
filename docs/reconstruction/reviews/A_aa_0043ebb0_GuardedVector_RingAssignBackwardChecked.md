# Review A (reconstruction fidelity): `aa_0043ebb0` GuardedVector_RingAssignBackwardChecked

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ebb0` |
| **VA** | `0x0043ebb0`–`0x0043ec43` (**148 B**) |
| **Canonical name** | `GuardedVector_RingAssignBackwardChecked` (**Inferred**) |
| **Ghidra name** | `FUN_0043ebb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-K) |
| **Counterpart** | `reviews/B_aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` |
| **System** | STL / guarded ring-vector container |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 148 B) + `analyze_function_complete`; 4 callers; leaf |
| **Verdict** | **accept** |

---

## 1. Purpose

Reverse ring dword assign between source and destination index cursors with self-alias skip:

1. While `(src_container, src_index) != (stop_container, stop_index)`.
2. Decrement src index; map through capacity-wrapped block table; same for dest.
3. If `dst_elem != src_elem`, `*dst_elem = *src_elem` (dword).
4. Write out iterator `{dst_container, final_dst_index}`; return it in EAX.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.md` (+ 2026-07-29 W33-K append) |
| Annotated | `docs/reconstruction/raw/aa_0043ebb0_FUN_0043ebb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_RingAssignBackwardChecked.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ebb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ebb0_FUN_0043ebb0.md` |
| Named record | `docs/reconstruction/functions/aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` |
| Live | decompile ≡ raw CF; body end `C3` before pad/`FUN_0043ec50`; 4 call xrefs |

---

## 3. Signature (sealed)

```c
// 7 stack args; plain RET; returns out_pair in EAX (bytes win vs decompiler void)
GuardedVectorIteratorPair* GuardedVector_RingAssignBackwardChecked(
    GuardedVectorIteratorPair* out, GuardedVectorHeader* stop_c, uint32_t stop_i,
    GuardedVectorHeader* src_c, uint32_t src_i,
    GuardedVectorHeader* dst_c, uint32_t dst_i);
```

| Slot | Source | Conf |
|---|---|---|
| out | Stack[+4] | **High** |
| stop/src/dst pairs | Stack[+8..+0x1c] | **High** |
| cleanup | plain `RET` | **High** |
| return | out in EAX | **High** (bytes) |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
while stop_c != src_c || stop_i != src_i:
  src_i--; map; dst_i--; map; if dst!=src: *dst=*src
out = {dst_c, dst_i}; RET (EAX=out)
```

| Stage | Match | Conf |
|---|---|---|
| Reverse decrement both cursors | **Yes** | **High** |
| capacity wrap on block index | **Yes** | **High** |
| dword element assign + self-guard | **Yes** | **High** |
| out pair write + EAX | **Yes** (bytes) | **High** |
| Leaf (no calls) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full **148 B** hex sealed in raw. Epilogue: `MOV EAX,out; … MOV [EAX],EDX; MOV [EAX+4],ECX; POP EBX; RET`.

---

## 6. Gaps

- Product/PDB class English.  
- Twin rationale vs `0043d300` (self-guard present here only).  
- Runtime / bit-exact.

---

## 7. Verdict

Fidelity seals ABI, reverse CF, map math, self-guard, and out-pair return. Closes W32-F / InsertRange nested reverse-move residual → **accept**.
