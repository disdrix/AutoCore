# Review A (reconstruction fidelity): `aa_00404060` StdList_Clear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404060` |
| **VA** | `0x00404060` |
| **Canonical name** | `StdList_Clear_Inferred` |
| **Ghidra name** | `FUN_00404060` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00404060_StdList_Clear_Inferred.md` |
| **System** | shared `client::stdlist` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Clear MSVC circular list** without freeing the list object or (necessarily) the sentinel:

```text
// ECX = list*
head = *(list+4)
first = *head                  // head->_Next
*head = head                   // head->_Next = head
*(head+4) = head               // head->_Prev = head
*(list+8) = 0                  // _Mysize = 0
if (first != head)
  operator_delete(first)       // decompile shows only first free
```

**Intent (High):** classic `std::list::clear` / `_Tidy` node free after re-ringing sentinel.  
**Decompile gap (High):** Ghidra marks `operator_delete` **noreturn**, so any free-loop after the first call is **dead-code-eliminated** in the decompiler. Live multi-node use from `OnDeathAwardKillXp` implies full walk in binary.

Does **not** free sentinel (that is `00403430`).

---

## 2. ABI

| Slot | Role |
|------|------|
| **ECX** | list* (`+4` head, `+8` size) |
| return | void |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `force_decompile` @ `0x00404060` (same as raw) |
| Raw/annotated/clean | `aa_00404060_*` |
| Callers | `00403430` (dtor), `OnDeathAwardKillXp`, UI/map sites (`008eddd3`, `00952e86`, …) ~12 xrefs |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Re-ring sentinel next/prev to self | **High** |
| Zero size at `+8` | **High** |
| Free path when non-empty | **High** |
| Free **all** nodes (loop) | **Probable** (decompile incomplete) |
| Name `StdList_Clear` | **Probable** |

---

## 5. Gaps

1. Recover free-loop with non-noreturn delete typing / pcode (no `disassemble_bytes` in this dual).
2. Node payload size/ownership (POD vs owned ptr at `+8` of 0xc node).

**Verdict:** **accept-with-gaps**.
