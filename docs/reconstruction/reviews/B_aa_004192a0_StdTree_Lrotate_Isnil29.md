# Review B (adversarial): `aa_004192a0` StdTree_Lrotate_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_004192a0` |
| **VA** | `0x004192a0` |
| **Body** | `0x004192a0`–`0x004192ed` exclusive (**77** B) |
| **Canonical name** | `StdTree_Lrotate_Isnil29` (inferred) |
| **Ghidra symbol** | `FUN_004192a0` |
| **Review date** | `2026-08-04` (WQ9D-C OWN-ONLY dual) |
| **Reviewer role** | Adversarial reconstruction review (Path B) |
| **Counterpart** | `reviews/A_aa_004192a0_StdTree_Lrotate_Isnil29.md` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## Attack surface / falsification attempts

| Hypothesis | Result |
|---|---|
| Is this **right**-rotate mislabeled? | **Falsified** — first load is `x+8` (right child); final hang sets `y->left = x`. Rrotate twin `004192f0` uses `*x` (left). |
| Same node size as Val12 Lrotate? | **Falsified** — isnil test is `+0x29` not `+0x19`; different family (Map_EraseNode large-node). |
| Extra formals / different ABI? | **Falsified** — `RET 4`, single stack arg; ECX this. |
| Skill-status exclusive? | **Falsified** — 10 callers / 21 xrefs across map erase/insert/aggro. Prior Named_* is **narrow**. |
| Color flips inside rotate? | **Falsified** — no color writes; pure topology. Recolor lives in insert/erase parents. |
| isnil is color? | **Falsified** — test is nil-child parent relink gate; Map_EraseNode seals color@+0x28 / isnil@+0x29. |

---

## Residual risks

1. **Demangle** open.  
2. **Runtime** golden not run.  
3. Payload English between header and color open (does not affect rotate CF).  
4. Twin `004192f0` not dualed in this OWN partition.

---

## Agreement with Path A

A's sealed CF, ABI, body size, Lrotate identity, and isnil@+0x29 layout are supported. No material disagreement.

**Verdict:** **accept**
