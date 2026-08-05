# Review B (adversarial): `aa_00418bf0` StdTree_Max_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418bf0` |
| **VA** | `0x00418bf0` |
| **Body** | `0x00418bf0`–`0x00418c0b` exclusive (**27** B) |
| **Canonical name** | `StdTree_Max_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00418bf0` |
| **Review date** | `2026-07-29` (W28-O OWN-ONLY dual) |
| **Reviewer role** | Adversarial reconstruction review (Path B) |
| **Counterpart** | `reviews/A_aa_00418bf0_StdTree_Max_Val12.md` |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## Attack surface / falsification attempts

| Hypothesis | Result |
|---|---|
| Is this **Tree_min** mislabeled? | **Falsified** — first child load is `[node+8]` (right), not `[node]`. Min twin is `0x005adfa0`. |
| Is this the start of **Rrotate** (`0x00418c10`)? | **Falsified** — body ends `00418c0b` with `C3`+`CC`; Rrotate is separate sealed unit (W26-Q). |
| Does it return the **nil** sentinel (decomp walk)? | **Falsified** — same early-exit/last-non-nil pattern as Min; callers store into `head->right`. |
| Void function (no return)? | **Falsified** — `uVar4 = FUN_00418bf0(piVar6); *(head+8) = uVar4`. |
| thiscall / RET 4 like rotates? | **Falsified** — `C3` only; no tree this pointer. |
| Isnil offset wrong? | **Unlikely** — `+0x19` matches sealed Val12 family. |
| Skill-status exclusive? | **Falsified** — same 6 erase callers as Min. Prior Named_* alias is **narrow**. |

---

## Residual risks

1. **Demangle** — exact `std::_Tree<…>::_Max` template args not recovered.  
2. **Decompiler residual** — void CF must not be re-ported from raw-only pipelines.  
3. **Runtime** — no golden max walk executed.

---

## Agreement with Path A

A's sealed body size, cdecl ABI, byte-level Tree_max CF, Val12 isnil@+0x19, and reject-decomp-as-authority stance are supported. No material disagreement.

**Verdict:** **accept**
