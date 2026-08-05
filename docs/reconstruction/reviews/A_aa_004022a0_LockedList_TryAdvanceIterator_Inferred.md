# Review A (reconstruction fidelity): `aa_004022a0` LockedList_TryAdvanceIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004022a0` |
| **VA** | `0x004022a0` |
| **Canonical name** | `LockedList_TryAdvanceIterator_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004022a0_LockedList_TryAdvanceIterator_Inferred.md` |
| **System** | `missions-progression` / LevelUp residual (also skill status) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thread-safe cursor advance over a critical-section-guarded singly-linked list:

- Host flag at `this+0x28` must be non-zero or returns `0`.
- `TryEnterCriticalSection(this+4)`; fail → `0x80070005` (ACCESS_DENIED-style HRESULT).
- If `*cursor == 0`: seed from head at `this+0x1c`, write payload `*out = head->+4`, set cursor to head; return `1` if head was null else `0`.
- Else if `cursor->+8` next non-null: advance cursor, `*out = next->+4`, return `0`.
- Else: clear cursor/out, return `1` (end).

Called from `CVOGCharacter_LevelUp` (list walk) and skill status-effect receive path (scaffold alias).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x004022a0` |
| Raw | `docs/reconstruction/raw/aa_004022a0_FUN_004022a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004022a0.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CS at `this+4`, enable flag `+0x28` | **High** | Body |
| Head pointer `this+0x1c` | **High** | Seed path |
| Node layout: `+4` payload, `+8` next | **High** | Reads |
| Returns 0 / 1 / `0x80070005` | **High** | Explicit |
| Product container type name | **Tentative** | INFERRED |

---

## 4. Gaps

1. Exact LevelUp list element type (mission auto-search ids vs other).
2. Whether failed TryEnter is expected under load or fatal for callers.

**Verdict:** **accept-with-gaps**
