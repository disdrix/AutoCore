# Review A (reconstruction fidelity): `aa_006caaa0` LinkPair_SortedDiffWalk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006caaa0` |
| **VA** | `0x006caaa0`–`0x006cac19` |
| **Body** | **378 bytes** (`0x17A`) |
| **Canonical name** | `LinkPair_SortedDiffWalk_Inferred` |
| **Ghidra name** | `FUN_006caaa0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-N) |
| **Counterpart** | `reviews/B_aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md` |
| **System** | world-object / spatial-link merge |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

Sorted **two-range diff walk** over 8-byte link pairs:

1. Promote counts to exclusive end pointers (`base + count*2` ints).
2. While both live: compare primary keys at `*pair+4` and secondary at `pair[1]+4`.
3. Equal → advance both; right-only → handler vcall **+8**; left-only → predicate then optional handler vcall **+4**.
4. Drain remaining left (predicate + vcall+4) and right (vcall+8).

Called from bind/unbind complex branches (`*(obj+0x40) != 0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006caaa0_FUN_006caaa0.md` (+ 2026-07-29 W27-N append) |
| Annotated | `docs/reconstruction/raw/aa_006caaa0_FUN_006caaa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LinkPair_SortedDiffWalk_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006caaa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006caaa0_FUN_006caaa0.md` |
| Named record | `docs/reconstruction/functions/aa_006caaa0_LinkPair_SortedDiffWalk_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` prologue + epilogue `C2 14 00` |
| Caller duals | W26-D Unbind / W26-E Bind (complex branch) |

---

## 3. Signature (sealed)

```c
// thiscall; 5 stack formals; ret 0x14; void
void LinkPair_SortedDiffWalk_Inferred(
    void *handler_table /*ECX*/,
    int *left_pairs, int left_count,
    int *right_pairs, int right_count,
    void *predicate_obj);
```

| Formal | Source | Conf |
|---|---|---|
| handler_table | ECX (`MOV EBX,ECX`) | **High** |
| left_pairs / left_count | stack | **High** |
| right_pairs / right_count | stack | **High** |
| predicate_obj | stack | **High** |
| return | void | **High** |
| cleanup | `ret 0x14` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
left_end  = left  + left_count*2
right_end = right + right_count*2
while both live:
  if keys equal: ++left; ++right
  else if right < left: vcall_table(right)+8; ++right
  else: if predicate(left_nodes): vcall_table(left)+4; ++left
drain left tail (predicate + vcall+4)
drain right tail (vcall+8)
ret 0x14
```

| Stage | Match | Conf |
|---|---|---|
| Count→end promotion | **Yes** | **High** |
| Dual-key compare | **Yes** | **High** |
| Three-way branch + tails | **Yes** | **High** |
| Handler index formula | **Yes** | **High** |
| ret 0x14 thiscall | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

- Entry `0x006caaa0`: `51 8B 44 24 0C 53 55 ... 8B D9` (this→EBX).
- Exit `0x006cac12`: `5F 5E 5D 5B 59 C2 14 00` then `CC` pad.
- Body **378 B** exclusive-of-pad.

---

## 6. Gaps

- Product English for handler-table / pair node types.
- Predicate object contract (installed on bind/unbind stack).
- `+0x10` node header adjustment semantics.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, merge role vs bind/unbind callers sealed. Naming **INFERRED** from structure. Nested product types residual. → **accept**.
