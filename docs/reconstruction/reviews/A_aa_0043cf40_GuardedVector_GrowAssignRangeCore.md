# Review A (reconstruction fidelity): `aa_0043cf40` GuardedVector_GrowAssignRangeCore

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cf40` |
| **VA** | `0x0043cf40`–`0x0043d2f6` (**951 B**) |
| **Canonical name** | `GuardedVector_GrowAssignRangeCore` (**Inferred**) |
| **Ghidra name** | `FUN_0043cf40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-B) |
| **Counterpart** | `reviews/B_aa_0043cf40_GuardedVector_GrowAssignRangeCore.md` |
| **System** | STL / guarded ring-deque container |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (entry/epilogue) + `analyze_function_complete`; sole caller `0043cec0`; callees `0043ce10`/`0043c830`/`0043d300`/`0043d390` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Grow-path **range assign core** invoked only by `GuardedVector_GrowAssignRange` when `GuardedVector_CopyAssign` must enlarge dest to match source. Shorter-side construct/destroy + ring move helpers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043cf40_FUN_0043cf40.md` (+ 2026-07-29 W28-B append) |
| Annotated | `docs/reconstruction/raw/aa_0043cf40_FUN_0043cf40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_GrowAssignRangeCore.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043cf40.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043cf40_FUN_0043cf40.md` |
| Named record | `docs/reconstruction/functions/aa_0043cf40_GuardedVector_GrowAssignRangeCore.md` |
| Live | decompile ≡ raw CF; RET 0x20; sole xref `0x0043cee8`; parent trampoline sealed W27-C |

---

## 3. Signature (sealed)

```c
// stdcall 8 stack args; RET 0x20
void GuardedVector_GrowAssignRangeCore(
    int dest, uint32_t p2, uint dest_bound, int source, uint src_begin,
    int p6, uint src_end, uint32_t dest_again);
```

| Slot | Source | Conf |
|---|---|---|
| 8 formals cleanup | `RET 0x20` @ `0x0043d2f4` | **High** |
| dest | Stack[+4] (`param_1`) | **High** |
| 8th = dest | trampoline re-push | **High** |
| decompiler formals | shows 7 used | **High** (use of 8th open) |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
prefix = dest_bound - dest.begin
suffix = dest.size - prefix
src_len = src_end - src_begin
if prefix < suffix:
  if prefix < src_len:  ce10 excess + ce10 dest; d390; ret
  else:                 ce10 shrink walks; d390 internal; fallthrough
else:
  if suffix < src_len:  c830 excess + c830 dest; d390; ret
  else:                 c830 shrink walks; d300; fallthrough
d390 final source→dest assign
```

| Stage | Match | Conf |
|---|---|---|
| 4-way shorter-side tree | **Yes** | **High** |
| ce10 front / c830 back | **Yes** | **High** |
| d300/d390 calls present | **Yes** | **High** |
| Nested free packs | shape only | **Medium** |
| SEH frame | **Yes** (`LAB_009be0b0`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry:

```
55 8B EC 6A FF 68 B0 E0 9B 00 64 A1 00 00 00 00 …
```

Epilogue @ `0x0043d2f4`:

```
5B 8B E5 5D C2 20 00    ; RET 0x20
```

Body length **951 B** (`0x0043cf40`–`0x0043d2f6`).  
Callees: `0043ce10`, `0043c830`, `0043d300`, `0043d390`.  
Sole caller site: `0x0043cee8` (`E8 53 00 00 00` from trampoline).

---

## 6. Gaps

- Product/PDB English.
- Exact formal packing into unowned `FUN_0043d300` / `FUN_0043d390`.
- Full semantic labels for p2/p6/p8 beyond trampoline shape.
- Runtime / bit-exact for all four arms.

---

## 7. Verdict

ABI (8-arg / RET 0x20), sole-caller link, prefix/suffix CF tree, and construct helper polarity sealed. Nested move free residual → **accept-with-gaps**.
