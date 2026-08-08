# Review A (reconstruction fidelity): `aa_00409780` StdTree_BuyHeadNode_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409780` |
| **VA** | `0x00409780` |
| **Body** | `0x00409780`–`0x00409809` inclusive (**138** B / `0x8A`) |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00409780` |
| **Review date** | `2026-08-05` (WQ9J-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md` |
| **System** | STL / map-set head node |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate a blank **0x30** isnil@+0x2d-family node with links zeroed, color black, isnil=0. Tree **ctor wrapper** installs it as head (isnil=1 + self-link + size=0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-G re-verify) | `docs/reconstruction/raw/aa_00409780_FUN_00409780.md` |
| Annotated | `docs/reconstruction/raw/aa_00409780_FUN_00409780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuyHeadNode_Isnil2D_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00409780.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md` |
| Live body | `read_memory` @ `0x00409780` / bare `C3` @ `0x00409809` |
| Caller | `FUN_00406190` decompile + call-site bytes @ `0x004061aa` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 138 B + bare `ret` | **Confirmed** | analyze body + bytes |
| No stack args; EAX = node | **Confirmed** | caller `MOV [host+4],EAX` |
| `operator_new(0x30)` | **Confirmed** | `PUSH 0x30` |
| Zero L/P/R; color=1 @+0x2c; isnil=0 @+0x2d | **Confirmed** | `88 58 2c` / `88 50 2d` |
| Caller sets isnil=1 + self-link + size0 | **Confirmed** | sole site identical to isnil29 head pattern |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc660` |
| isnil2D / 0x30 family | **Confirmed** | Val32 region layout context |
| Not CNDHash freelist / not isnil29 head | **Confirmed** | different isnil offset vs `00408a30` |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x30) | **Yes** |
| Zero links (MSVC field checks) | **Yes** |
| color black + isnil0 | **Yes** |
| bare RET; EAX node | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| 0x30 node + isnil@+0x2d | **Yes** |
| Sole caller is tree-head installer | **Yes** |
| Self-link / isnil1 outside this unit | **Yes** (honest gap) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_BuyHeadNode_Isnil2D_Inferred`**. Reject freelist/CNDHash; reject claiming self-link inside this VA; reject merge with isnil29 BuyHeadNode `00408a30`.

---

## 6. Gaps

1. Product/PDB symbol for host tree types.
2. Full dual of ctor wrapper `FUN_00406190` (not OWN).
3. OOM crash shape if new returned null without throw (preserve odd).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
