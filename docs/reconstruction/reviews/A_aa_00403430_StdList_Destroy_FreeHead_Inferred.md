# Review A (reconstruction fidelity): `aa_00403430` StdList_Destroy_FreeHead_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403430` |
| **VA** | `0x00403430` |
| **Canonical name** | `StdList_Destroy_FreeHead_Inferred` |
| **Ghidra name** | `FUN_00403430` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00403430_StdList_Destroy_FreeHead_Inferred.md` |
| **System** | shared `client::stdlist` (MSVC circular list) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**List object destructor tail**: call clear helper `FUN_00404060`, then `operator_delete` the **sentinel head** at `list+4`.

```text
// ECX = list object*
// layout used: +4 = head/sentinel*, +8 = size (cleared by 00404060)
FUN_00404060(this);                 // orphan/clear nodes; size=0; head self-linked
operator_delete(*(void**)(this+4)); // free sentinel
// Ghidra marks delete as noreturn — false positive; normal free
```

Paired with `FUN_0040fb90` (alloc empty sentinel) and `FUN_00404060` (clear). Heavy use from mission/combat teardown and `CVOGCombat_OnDeathAwardKillXp` loot-list path.

---

## 2. ABI (SEALED)

| Slot | Role |
|------|------|
| **ECX** | list object* (`+4` head, `+8` size) |
| stack | none |
| return | void (delete does return) |

```c
void __fastcall StdList_Destroy_FreeHead(ListObj* list);
```

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `force_decompile` @ `0x00403430` |
| Raw / annotated / clean | `raw/aa_00403430_*`, `reconstructed-exact/FUN_00403430.cpp` |
| Function record | `functions/aa_00403430_FUN_00403430.md` |
| Callee | `FUN_00404060` then `operator_delete` |
| Callers (sample) | `CVOGCombat_OnDeathAwardKillXp` (`0x004daf…`), many `0x009a*` / map load teardown sites; **50+** xrefs |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Call clear `00404060` | **Yes** |
| `operator_delete(*(list+4))` | **Yes** |
| No other stores | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Destroy = clear + free head | **High** |
| Head at `+4` | **High** |
| MSVC circular list role | **High** (with 0040fb90/00404060) |
| English product name | **Probable** (`_Inferred`) |
| Clear frees **all** nodes (vs decompile single-delete) | **Probable** — see B / `00404060` dual |

---

## 6. Gaps

1. Full clear-loop recovery on `00404060` (Ghidra noreturn on `operator_delete` collapses loop).
2. Exact `list+0` field (allocator / padding) unused here.

**Verdict:** **accept-with-gaps**.
