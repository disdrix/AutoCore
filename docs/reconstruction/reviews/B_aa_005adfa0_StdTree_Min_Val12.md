# Review B (adversarial): `aa_005adfa0` StdTree_Min_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005adfa0` |
| **VA** | `0x005adfa0` |
| **Body** | `0x005adfa0`–`0x005adfba` exclusive (**26** B) |
| **Canonical name** | `StdTree_Min_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005adfa0` |
| **Review date** | `2026-07-29` (W28-O OWN-ONLY dual) |
| **Reviewer role** | Adversarial reconstruction review (Path B) |
| **Counterpart** | `reviews/A_aa_005adfa0_StdTree_Min_Val12.md` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## Attack surface / falsification attempts

| Hypothesis | Result |
|---|---|
| Is this **Tree_max** mislabeled? | **Falsified** — first child load is `[node]` (left@0), not `[node+8]`. Max twin is `0x00418bf0`. |
| Does it return the **nil** sentinel (decomp walk)? | **Falsified** — early exit when left isnil leaves original node in EAX; loop advances EAX before testing next left. Callers store result into `head->left` (must be non-nil data node or parent). |
| Void function (no return)? | **Falsified** — callers cast/assign return: `piVar3 = (int *)FUN_005adfa0(piVar6)`. |
| thiscall / RET 4 like rotates? | **Falsified** — `C3` only; no ECX this; stack arg only. |
| Isnil offset wrong? | **Unlikely** — `+0x19` matches sealed Val12 buynode/rotate/erase family. |
| Skill-status exclusive? | **Falsified** — 6 erase callers across Val12 maps. Prior `Named_CalleeOf_…RecvSkillStatusEffect` is **narrow**. |
| Successor / parent-climb helper? | **Falsified** — no parent loads (`+4`); pure left descent. |

---

## Residual risks

1. **Demangle** — exact `std::_Tree<…>::_Min` template args not recovered.  
2. **Decompiler residual** — future auto tools may re-introduce void CF if they trust Ghidra only.  
3. **Runtime** — no golden min walk executed.

---

## Agreement with Path A

A's sealed body size, cdecl ABI, byte-level Tree_min CF, Val12 isnil@+0x19, and reject-decomp-as-authority stance are supported. No material disagreement.

**Verdict:** **accept**
