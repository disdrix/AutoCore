# Review A (reconstruction fidelity): `aa_004cb4f0` StdTree_Predecessor_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4f0` |
| **VA** | `0x004cb4f0` |
| **Body** | `0x004cb4f0`–`0x004cb540` exclusive (**80** B / `0x50`) |
| **Canonical name** | `StdTree_Predecessor_Isnil29_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_004cb4f0` |
| **Prior / alias** | `Named_CalleeOf_…_VOGClient_004cb4f0` (**reject** product) |
| **Review date** | `2026-08-04` (WQ9G-B OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` |
| **System** | std tree predecessor (isnil29) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, callers/xrefs, `get_assembly_context` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf** helper: advance `*it` to the in-order **predecessor** of a red-black tree node whose **isnil** flag is at **`+0x29`**. Shared by dualed isnil29 insert-or-find and insert-hint shells.

| Offset | Field |
|---|---|
| `+0x00` | left* |
| `+0x04` | parent* |
| `+0x08` | right* |
| `+0x29` | isnil (u8); non-zero ⇒ head/end sentinel |

Control flow (sealed):

1. **`cur = *it`**. If **`cur->isnil`**: `*it = cur->right` and return.
2. Else if **`cur->left` not isnil**: set `*it` to **rightmost** of left subtree.
3. Else climb parents while `cur == parent->left`; if final parent not isnil, `*it = parent`.

**No** allocation, rebalance, key compare, color touch, or map-shell access.

**ABI:** **ECX = Node**** (`8B 01`); bare **`C3`**; no stack args. Distinct from isnil15 peers (`Map_Tree_Predecessor_Isnil15` / `_Edx`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9G-B append) | `docs/reconstruction/raw/aa_004cb4f0_FUN_004cb4f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb4f0_FUN_004cb4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Predecessor_Isnil29_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004cb4f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | 80 B hex in raw append |
| Call-site | `LEA ECX,[ESP+…]` → `CALL 0x004cb4f0` (e.g. `004cc2db`) |
| Insert-hint parent | dualed `StdTree_InsertHint_Isnil29_Inferred` @ `0x004cc220` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry load *it | `8B 01` — **ECX** |
| isnil | `80 78 29 00` / `80 7A 29 00` — **@+0x29** |
| right / parent / left | loads at +8 / +4 / +0 |
| rightmost walk | `while right->isnil==0: p=right` |
| climb while left-child | `CMP [ECX],[EAX]` style break |
| Epilogue | bare `C3` ×3 arms |
| Body end | exclusive `0x004cb540` (pad `CC` then `004cb550`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (80 B) |
| ECX = Node**; bare RET | **pass** |
| isnil@+0x29; left/parent/right layout | **pass** |
| Three-arm predecessor (not successor) | **pass** |
| Leaf (no callees) | **pass** |
| Clean meaningful names | **pass** |
| Product English / demangle | **gap** |
| Runtime / differential | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ECX ABI | **High** | live ≡ raw; bytes + call-site LEA ECX |
| isnil@+0x29 layout | **High** | `80 xx 29 00` |
| Role = predecessor | **High** | algorithm + insert-hint prev use |
| Shared helper (5 callers) | **High** | xrefs |
| Name structural `_Inferred` | **Inferred** | no product plate |
| Runtime | Open | |

---

## 6. Gaps (acceptable)

1. Product / MSVC demangle for node value_type.  
2. Whether `FUN_00406040` / `FUN_005a3b00` share exact value_type with isnil29 skill maps.  
3. Runtime edge cases; bit-exact image diff.
