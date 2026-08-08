# Review A (reconstruction fidelity): `aa_00402dd0` StdList_Resize_EsiList_EaxCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402dd0` |
| **VA** | `0x00402dd0`–`0x00402e1f` inclusive (**80 B** / `0x50`) |
| **Canonical name** | `StdList_Resize_EsiList_EaxCount_Inferred` |
| **Ghidra name** | `FUN_00402dd0` |
| **Review date** | `2026-08-05` (MEGA-127 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md` |
| **System** | MSVC-style `std::list` resize (ESI list / EAX count) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Resize circular doubly-linked list shell to target element count:

```text
if size < new:  insert (new-size) fill nodes via FUN_004034c0
if size == new: return
if size > new:  while size > new: unlink head->prev; delete; size--
```

Shared container utility; mission debug list is one of five consumers (all observed with `new=0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402dd0_FUN_00402dd0.md` (+ MEGA-127 append) |
| Annotated | `docs/reconstruction/raw/aa_00402dd0_FUN_00402dd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Resize_EsiList_EaxCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402dd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00402dd0_FUN_00402dd0.md` |
| Named record | `docs/reconstruction/functions/aa_00402dd0_StdList_Resize_EsiList_EaxCount_Inferred.md` |
| Live | decompile ≡ CF; body hex 80 B; 5 CALL xrefs; call-site ESI/EAX/PUSH |

---

## 3. Signature (sealed)

```c
// ESI = list*; EAX = new_size; stack fill; RET 4; void
void StdList_Resize_EsiList_EaxCount_Inferred(ListShell* list, uint32_t new_size, uint32_t fill);
```

| Slot | Source | Conf |
|---|---|---|
| list | **ESI** (`[ESI+4]` head, `[ESI+8]` size) | **High** |
| new_size | **EAX** → saved **EDI** | **High** |
| fill | stack (`RET 4`; grow `LEA ECX,[ESP+0x14]`) | **High** |
| cleanup | **`RET 4`** ×2 exits | **High** |

**Note:** Decompiler shows `void FUN_00402dd0(void)` with `unaff_ESI`/`in_EAX` — assembly + call sites seal register ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| CMP new vs size; JBE shrink/eq | **Yes** | **High** |
| Grow: SUB; CALL `004034c0`; RET 4 | **Yes** | **High** |
| Equal: JNC → POP EDI; RET 4 | **Yes** | **High** |
| Shrink: head->prev unlink | **Yes** | **High** |
| `operator_delete` + ADD ESP,4 + size-- | **Yes** (asm; decompiler misses) | **High** |
| Loop while new < size | **Yes** | **High** |
| Element type English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | 5 UNCONDITIONAL_CALL (`xref_count=5`) |
| Site roles | clear/resize list before rebuild (EAX=0 dominant) |
| Callees | `FUN_004034c0`, `operator_delete` |
| Related | insert `FUN_00402d10`; clear-only `StdList_Clear_ESI` `00415e90` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| List head@+4 / size@+8 | **Yes** |
| Circular next/prev unlink | **Yes** |
| Resize grow+shrink | **Yes** |
| ESI/EAX register ABI | **Yes** |
| Product type T name | **No** → `_Inferred` |
| Mission-only helper | **No** — shared; retire Named_CalleeOf scaffold |

**Name:** `StdList_Resize_EsiList_EaxCount_Inferred`

---

## 7. Gaps

- Product element type / sizeof(T) for fill.
- Dual of grow helper `004034c0` / insert `004040f0` residual.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/RET4/caller set sealed from live Ghidra. Residual product element English → **accept-with-gaps**.
