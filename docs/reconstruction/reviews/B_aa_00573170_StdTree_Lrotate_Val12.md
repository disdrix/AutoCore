# Review B (adversarial): `aa_00573170` StdTree_Lrotate_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573170` |
| **VA** | `0x00573170` |
| **Body** | `0x00573170`–`0x005731BE` exclusive (**78** B) |
| **Canonical name** | `StdTree_Lrotate_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00573170` |
| **Review date** | `2026-07-29` (W26-Q OWN-ONLY dual) |
| **Reviewer role** | Adversarial reconstruction review (Path B) |
| **Counterpart** | `reviews/A_aa_00573170_StdTree_Lrotate_Val12.md` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## Attack surface / falsification attempts

| Hypothesis | Result |
|---|---|
| Is this **right**-rotate mislabeled? | **Falsified** — first load is `x+8` (right child); final hang sets `y->left = x`. Rrotate twin uses `*x` (left). |
| Is isnil offset wrong for this tree? | **Unlikely** — `+0x19` matches sealed Val12 buynode (`StdTree_Buynode_Val12`); all 13 callers are Val12 rebalance paths. |
| cdecl / more stack args? | **Falsified** — every exit is `RET 4`; only one stack load `[esp+4]`. |
| Non-void return in EAX? | **No use** — pure store graph; callers do not consume EAX from this call. |
| Skill-status exclusive helper? | **Falsified** — 13 distinct callers across maps (cooldown, erase, insert clones). Prior `Named_CalleeOf_…RecvSkillStatusEffect` is **narrow**. |
| Inlined vs shared? | **Shared leaf** — single body, 26 xrefs. |

---

## Residual risks

1. **Demangle** — exact `std::_Tree<…>::_Lrotate` template args not recovered (not required for CF seal).  
2. **Nil sentinel** — assumes isnil bit semantics identical to Dinkumware; consistent with sibling units.  
3. **Runtime** — no golden tree rotate test executed.

---

## Agreement with Path A

A's sealed CF, ABI, body size, Lrotate identity, and Val12 layout are supported. No material disagreement.

**Verdict:** **accept**
