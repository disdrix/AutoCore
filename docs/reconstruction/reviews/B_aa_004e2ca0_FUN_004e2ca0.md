# Review B (skeptical / adversarial): `aa_004e2ca0` FUN_004e2ca0 (leave-FUN)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2ca0` |
| **VA** | `0x004e2ca0` |
| **Canonical name** | `FUN_004e2ca0` (**retained**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004e2ca0_FUN_004e2ca0.md` |
| **System** | hash / free-list |
| **Live tools** | Independent `force_decompile` + `read_memory` + `FUN_00537d30` decompile + multi-xref callers |
| **Verdict** | **leave-FUN** — accept A's CF; reject over-narrow mission-only / free-on-remove claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is the CS owner-list remove (`FUN_005085b0`) | **Falsified** — no CS; singly-linked `+0xC`; key at `+0x10` not `+4` |
| 2 | Frees the node | **Falsified** — returns node*; sole callee is integrity walker |
| 3 | Mission-only API | **Falsified** — 14 xrefs across FUN_005* / FUN_004e* / FUN_0060* domains |
| 4 | Skips integrity check on miss | **Falsified** — `FUN_00537d30` on all exits including empty |
| 5 | Doubly-linked prev pointer written | **Falsified** — only next-slot rewrite; prev is walk-local register |
| 6 | Alias `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` is meaningful | **Rejected** — scaffold noise from unrelated string proximity |
| 7 | `FUN_00537d30` is optional debug | **Falsified** — unconditional; repairs cycles when re-touch detected |
| 8 | Head-hit returns without integrity call | **Falsified** — head path falls through to `FUN_00537d30` then `return iVar3` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Key at `+0x10`, next at `+0xC` | **High** | Wrong hash node family |
| Unlink math (head vs mid) | **High** | Chain corruption |
| Return node* / 0 | **High** | Caller UAF or leak |
| No free here | **High** | Double-free if port frees twice |
| Multi-domain | **High** | Mission-only rename wrong |
| Product name | **None** | Registry pollution |

---

## 3. Integrity callee note (`FUN_00537d30`)

Walks chain from `*(this+4)`, stamps `*(node+4)=1`, detects already-touched next → logs `"HashListError: Went to node we already touched! Attempting repair!"`, severs, clears marks. **Always** invoked by this unit — not debug-only in retail CF.

---

## 4. Decompiler pitfalls

1. `FUN_00537d30()` printed with no args — true ABI passes list `this` (ECX).
2. Scaffold alias tying this to `VOG_DEBUG_STOP` — **ignore**.
3. Mid-hit early `return iVar3` vs head-hit fall-through — both return node*; both run integrity.

---

## 5. What is safe to claim

| Safe | Unsafe |
|---|---|
| Singly-list unlink-by-key @ `+0x10` | Product symbol |
| Return detached node* or 0 | “destructor” / free |
| Always integrity walk | Mission-exclusive API |
| leave-FUN | Promote `HashList_Remove` without RTTI |

---

## 6. CF challenge of Review A

- Force ≡ non-force body: **agree**
- Offsets + return contract: **agree High**
- leave-FUN: **agree**
- Reject free-on-remove + CS-list identity: **agree**

**Verdict:** **leave-FUN**
