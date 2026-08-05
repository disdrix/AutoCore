# Review A (reconstruction fidelity): `aa_0058e020` MapFloatTfid_DestroyTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e020` |
| **VA** | `0x0058e020` |
| **Canonical name** | `MapFloatTfid_DestroyTree_Inferred` (was `FUN_0058e020`) |
| **Ghidra symbol** | `FUN_0058e020` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058e020_MapFloatTfid_DestroyTree_Inferred.md` |
| **System** | skills-abilities / map teardown |
| **Dual status** | **Present** |
| **Verdict** | **accept** — erase-all + free head sealed |

---

## 1. Purpose

**Destroy** a float-key TFID map object:

1. `FUN_0058df60(&this, *head, head)` — erase full range (begin..end sentinel = head).
2. `operator_delete(head)` at `this+4`.

Decompiler marks `operator_delete` as no-return incorrectly; CF is erase then free head. Matches gather teardown pattern documented on `MapFloatTfid_EraseRange` dual.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0058e020` |
| Raw | `raw/aa_0058e020_FUN_0058e020.md` |
| Erase dual | `A_aa_0058df60_MapFloatTfid_EraseRange_Inferred.md` |

---

## 3. Body

```c
void __fastcall DestroyTree(Tree* this) {
  MapFloatTfid_EraseRange(this, &scratch, *this->head, this->head);
  operator_delete(this->head);  // this+4
}
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Full erase then free head | **High** |
| Head at this+4 | **High** |
| No per-value skill logic | **High** |

**Verdict:** **accept**
