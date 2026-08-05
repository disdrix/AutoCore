# Review B (adversarial): `aa_00418c10` StdTree_Rrotate_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418c10` |
| **VA** | `0x00418c10` |
| **Body** | `0x00418c10`–`0x00418c62` exclusive (**82** B) |
| **Canonical name** | `StdTree_Rrotate_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00418c10` |
| **Review date** | `2026-07-29` (W26-Q OWN-ONLY dual) |
| **Reviewer role** | Adversarial reconstruction review (Path B) |
| **Counterpart** | `reviews/A_aa_00418c10_StdTree_Rrotate_Val12.md` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## Attack surface / falsification attempts

| Hypothesis | Result |
|---|---|
| Is this **left**-rotate mislabeled? | **Falsified** — first load is `*x` (left child); final hang sets `y->right = x`. Lrotate twin uses `x+8`. |
| Different node size than Lrotate? | **Falsified** — same isnil@+0x19; same caller set. |
| Extra formals / different ABI? | **Falsified** — `RET 4`, single stack arg; ECX this. |
| Skill-status exclusive? | **Falsified** — 13 callers / 32 xrefs across Val12 maps. Prior Named_* is **narrow**. |
| Color flips inside rotate? | **Falsified** — no color writes; pure topology. Recolor lives in insert/erase parents. |

---

## Residual risks

1. **Demangle** open.  
2. **Runtime** golden not run.  
3. Decompiler types `int` vs `int*` for the node arg differ slightly from Lrotate twin (same pointer meaning).

---

## Agreement with Path A

A's sealed CF, ABI, body size, Rrotate identity, and Val12 layout are supported. No material disagreement.

**Verdict:** **accept**
