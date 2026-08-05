# Review A (reconstruction fidelity): `aa_0041c7e0` LockedList_InsertPayloadTail_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c7e0` |
| **VA** | `0x0041c7e0` (0x0041c7e0–0x0041c8a2) |
| **Canonical name** | `LockedList_InsertPayloadTail_Inferred` |
| **Ghidra name** | `FUN_0041c7e0` |
| **Prior alias** | `Named_VOG_DEBUG_STOP_0041c7e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-F) |
| **Counterpart** | `reviews/B_aa_0041c7e0_LockedList_InsertPayloadTail_Inferred.md` |
| **System** | skills-abilities / CS-protected locked list |
| **Live tools** | Ghidra MCP `decompile_function` / `read_memory` / callers / callees (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` nested via `Hash_CollectKeyMatchesToLockedList` `aa_0041ac60` |

---

## 1. Purpose

CS-guarded **tail insert** of a payload into a 0x2C locked list:

1. `EnterCriticalSection(list+4)`.
2. If flag byte `list+0x28 != 0`: `FUN_007a4480(0,"VOG_DEBUG_STOP")`; throw `0x80070005` (`E_ACCESSDENIED`).
3. `node = (vtbl+4)(list, 0)` (thiscall). Null → throw `0x8007000e` (`E_OUTOFMEMORY`).
4. If head (`list+0x1C`) empty: head = node.
5. Doubly link at tail (`list+0x20`): `node+0x0C = old_tail`; if old_tail: `old_tail+0x08 = node`.
6. `node+0x04 = payload`; `count++` (`list+0x24`); `tail = node`.
7. `LeaveCriticalSection`; return `0`.

Matches sibling iterator layout in `LockedList_TryAdvanceIterator` (`aa_004022a0`: head `+0x1C`, payload `+4`, next `+8`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` @ `0x0041c7e0` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_0041c7e0_*`, `reconstructed-exact/FUN_0041c7e0.cpp` |
| Function record | `functions/aa_0041c7e0_FUN_0041c7e0.md` |
| Live bytes | `read_memory` @ `0x0041c7e0` length 200 — ends normal path `xor eax,eax` … `ret 8` |
| String | `read_memory` path via push imm `0x00a15844` = `"VOG_DEBUG_STOP"` |
| Parent dual | `reviews/A_aa_0041ac60_Hash_CollectKeyMatchesToLockedList_Inferred.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__stdcall` `ret 8` (list*, payload) | **High** | epilogue `c2 08 00` |
| CS at `+4`; flag at `+0x28`; head `+0x1C`; tail `+0x20`; count `+0x24` | **High** | body + parent ctor zeros |
| Tail insert doubly-linked (+8 next / +0xC prev) | **High** | write order in decompile |
| Alloc via `vtbl+4` arg 0; OOM throw | **High** | |
| Flag set ⇒ `VOG_DEBUG_STOP` + `E_ACCESSDENIED` | **High** | string + `0x80070005` |
| Shared helper beyond skill hash collect | **High** | 10 callers |
| Product type names | **Tentative** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from refined clean | **Yes** |
| Live `decompile_function` ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product C++ class name for locked list / node freelist (`vtbl+4` allocator).
2. Exact set of modes that raise `+0x28` (iterator-held confirmed by sibling; others unknown).
3. Node allocation size (layout implies ≥ `0x10`).

**Verdict:** Structural contract sealed from live decompile + `read_memory` + callers. Product names remain inferred. **accept-with-gaps.**
