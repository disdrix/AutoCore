# Review A (reconstruction fidelity): `aa_00423f40` CsSinglyLinkedList_TryNext_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423f40` |
| **VA** | `0x00423f40` (0x00423f40-0x00423fdc) |
| **Canonical name** | `CsSinglyLinkedList_TryNext_Inferred` |
| **Ghidra name** | `FUN_00423f40` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00423f40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00423f40_CsSinglyLinkedList_TryNext_Inferred.md` |
| **System** | container / thread-safe list (DB load cursor) |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

**Try-advance** a cursor on a CS-protected singly-linked list.

List (`ESI`): `+0x04` CRITICAL_SECTION, `+0x1c` head, `+0x28` enable flag.  
Node: `+0x04` payload, `+0x08` next.  
Cursor in `EDI`; `param_1` out payload*. **`ret 4`**.

Returns: **0** advanced, **1** exhausted, **0x80070005** (`E_ACCESSDENIED`) if disabled or `TryEnterCriticalSection` fails.

Parent `Skill_DbLoadSkillsCharacters` has **8** xrefs for row walks; also many 0078/007a/007e walkers.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x00423f40` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_00423f40_*`, `reconstructed-exact/FUN_00423f40.cpp` |
| Function record | `functions/aa_00423f40_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Uses TryEnter/LeaveCriticalSection | **Confirmed** | external callees |
| E_ACCESSDENIED 0x80070005 on lock fail / disabled | **High** | ret imm |
| Singly linked via node+8 | **High** | body |
| Payload at node+4 | **High** | body |
| ret 4 (stdcall one stack arg) | **High** | read_memory c2 04 00 |
| Not VOG_DEBUG_STOP identity | **High** | alias is seed-scan only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product type name of list/node.
2. Who sets +0x28 enable flag.
3. Payload type (row* vs variant).

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
