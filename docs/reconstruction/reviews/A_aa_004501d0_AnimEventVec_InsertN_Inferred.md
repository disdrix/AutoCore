# Review A (reconstruction fidelity): `aa_004501d0` AnimEventVec_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004501d0` |
| **VA** | `0x004501d0`–`0x00450526` exclusive (**854 B** / `0x356`) |
| **Canonical name** | `AnimEventVec_InsertN_Inferred` |
| **Ghidra name** | `FUN_004501d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-O) |
| **Counterpart** | `reviews/B_aa_004501d0_AnimEventVec_InsertN_Inferred.md` |
| **System** | client / animation events |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full 854 B) + callee batch_decompile (`FUN_00450050`, `FUN_00450600`, `FUN_00450560`, `FUN_0044ffa0`, `FUN_00444100`, `FUN_004501a0`, `FUN_00450530`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a value element at `where` into a **0x1c**-stride vector used by the anim-event host chain:

- Local template from `value` (`PTR_FUN_009d4828`, `+4/+8`, nested `FUN_00444100`).
- Capacity/size via begin/end/capEnd and `/0x1c`.
- Too-long gate `0x9249249` → `FUN_004540b0`.
- Grow 1.5× + uninit_copy/fill/destroy; or in-place shift/fill/assign.
- Sole caller: resize `FUN_00450050` (insert at end when growing).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-O) | `docs/reconstruction/raw/aa_004501d0_FUN_004501d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004501d0_FUN_004501d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/AnimEventVec_InsertN_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004501d0.cpp` |
| Function records | `functions/aa_004501d0_FUN_004501d0.md`, `functions/aa_004501d0_AnimEventVec_InsertN_Inferred.md` |
| Related | `StdVector_Elem28_Size` W33-J; contrast `StdVector_InsertN_BasicString` W32-B |
| Live | full body hex; 1 xref CALL; epilogue `C2 10 00` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Signature (sealed)

```c
// 4 stack args; RET 0x10; void — NOT thiscall for vec
void AnimEventVec_InsertN_Inferred(void *vec, void *where, uint32_t count, void *value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | stack `[ebp+8]` → ESI | **High** |
| where | stack `[ebp+0xC]` | **High** |
| count | stack `[ebp+0x10]` → EDI | **High** |
| value | stack `[ebp+0x14]` | **High** |
| cleanup | `RET 0x10` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
build local template from value (vtbl 009d4828 + nested)
if count == 0: destroy local; return
size/cap via /0x1c
if size+count > 0x9249249: FUN_004540b0
if cap < size+count:
  newCap = max(cap+cap/2, size+count)  // may call StdVector_Elem28_Size
  reallocate + uninit_copy + fill_n + destroy old
else:
  in-place tail or mid path (FUN_00450600 / 450560 / 450530 / 44ffa0)
destroy local; RET 0x10
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0x356 / `RET 0x10` | **Yes** | **High** |
| 4 stack args (not thiscall vec) | **Yes** | **High** |
| Stride 0x1c / max / 1.5× | **Yes** | **High** |
| Grow vs in-place branches | **Yes** | **High** |
| Sole resize caller | **Yes** | **High** |

---

## 5. Gaps

- Product demangle for anim-event element / `PTR_FUN_009d4828`.
- Nested helpers free (uninit_copy / fill / destroy / assign / nested-range).
- Clean body is contract-level (not full EH-state line rewrite of 854 B).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, body bounds, stride, max/grow policy, and sole resize wiring. Nested element helpers and product English remain open → **accept-with-gaps**.
