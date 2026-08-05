# Review A (reconstruction fidelity): `aa_0040fb90` StdList_AllocEmptySentinel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040fb90` |
| **VA** | `0x0040fb90` |
| **Canonical name** | `StdList_AllocEmptySentinel_Inferred` |
| **Ghidra name** | `FUN_0040fb90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0040fb90_StdList_AllocEmptySentinel_Inferred.md` |
| **System** | shared `client::stdlist` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Allocate empty list sentinel node** (12 bytes):

```text
node = operator_new(0xc)
if (node)  *node = node           // next = self
if (node+4) *(node+4) = node      // prev = self  (always true if node non-null)
// EAX leaves as node* (callers assign return)
```

SEH frame (`LAB_009bc7d0`) around `operator_new`. Does **not** construct a full list object (no size store here) — callers pair head with a separate size dword (e.g. OnDeath stack: head @ `piStack_48`, size @ `iStack_44=0`).

---

## 2. ABI

| Slot | Role |
|------|------|
| args | none |
| **EAX out** | sentinel node* (decompiler wrongly shows `void`) |
| return | node* |

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `force_decompile` @ `0x0040fb90` |
| Raw/clean | `aa_0040fb90_*` |
| Callers | **70+** including `OnDeathAwardKillXp`, map load, UI, `004023f3`/`00402436` |
| Pair | destroy `00403430`, clear `00404060` |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| `operator_new(0xc)` | **High** |
| next/prev self-link | **High** |
| Empty circular sentinel | **High** |
| EAX return used by callers | **High** (caller assign) |
| Decompiler `void` return | **Known wrong** |

---

## 5. Gaps

1. Third dword of 0xc node (payload start vs pad) when elements inserted.
2. Whether some callers store into embedded list+allocator layout.

**Verdict:** **accept-with-gaps**.
