# Review A (reconstruction fidelity): `aa_00404180` StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404180` |
| **VA** | `0x00404180` |
| **Body** | `0x00404180`–`0x00404202` exclusive (**130** B / `0x82`) |
| **Canonical name** | `StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred` |
| **Ghidra symbol** | `FUN_00404180` |
| **Review date** | `2026-08-04` (WQ9K-C OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` epilogue + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x29** tree node with **Val24** payload for insert path `FUN_004069f0`, using the **EAX-this** node ctor twin of the dualed thiscall buynode `0x00407e30`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9K-C re-verify) | `docs/reconstruction/raw/aa_00404180_FUN_00404180.md` |
| Annotated | `docs/reconstruction/raw/aa_00404180_FUN_00404180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00404180.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x004041ff` → `C2 14 00` |
| Ctor | dualed `aa_00409880` / `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` |
| Parent insert | undualed `FUN_004069f0` (string `"map/set<T> too long"`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 130 B + `ret 0x14` | **Confirmed** | disasm bounds + epilogue bytes |
| `__stdcall` 5 stack args; EAX return | **Confirmed** | disasm; no ECX this on entry |
| `operator_new(0x30)` | **Confirmed** | `PUSH 0x30` + call |
| Ctor via EAX-this `00409880` | **Confirmed** | `MOV EAX,ESI` + register/stack setup before CALL |
| Sole caller insert `004069f0` | **Confirmed** | 1 xref @ `0x00406a56` |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc701` |
| Distinct from thiscall twin `00407e30` | **Confirmed** | different ctor VA only |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x30) | **Yes** |
| null skip / else EAX-ctor | **Yes** (disasm fills decomp arg gaps) |
| return node; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size + isnil@+0x29 family | **Yes** (via dualed ctor) |
| Val24 (6 dwords) from ctor | **Yes** |
| EAX-this ctor path vs thiscall twin | **Yes** |
| Parent insert string map/set | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred`**. Reject chain-of-caller Client/RecvSpecial scaffold; reject merge with `00407e30` (ABI twin only); reject freelist/CNDHash.

---

## 6. Gaps

1. Product/PDB symbol for Val24 value_type.
2. Full dual of parent insert `FUN_004069f0` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
