# Review A (reconstruction fidelity): `aa_00507350` VOGPhysics_QueryObject_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507350` |
| **VA** | `0x00507350`–`0x005073bd` inclusive (**110 B** / `0x6E`) |
| **Canonical name** | `VOGPhysics_QueryObject_Dtor_Inferred` |
| **Ghidra name** | `FUN_00507350` |
| **Review date** | `2026-08-05` (R13-028 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` |
| **System** | interaction-activation — query-object base **body dtor** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Body destructor for the physics query-object / shared base header that dualed SubInit `0x00581190` constructs under provisional vtbl `009cd99c`: release linked peer, free growable buffer when capacity live, clear high-bit flag via `FUN_005ffdb0`, cycle mid/base vtbls. **`__thiscall` + `RET 0`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13-028 re-verify) | `docs/reconstruction/raw/aa_00507350_FUN_00507350.md` |
| Annotated | `docs/reconstruction/raw/aa_00507350_FUN_00507350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_Dtor_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00507350.cpp` |
| Function record | `docs/reconstruction/functions/aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` |
| Live body | `read_memory` entry 128 B + epilogue `5E C3` |
| Callers | `FUN_005073f0` @ `0x005073f3`; `FUN_005074d0` @ `0x005075b7`; `FUN_006343d0` @ `0x0063443e` |
| Parent dual | `VOGPhysics_QueryObject_SubInit_Inferred` @ `0x00581190` (R12-027) |
| Vtbl | `read_memory` @ `0x009cd99c` (slot0 = scalar dtor `005073f0`) |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | self* | prolog `PUSH ESI; MOV ESI,ECX` |
| stack | none | no stack loads; `RET` not `RET n` |
| cleanup | **`ret 0`** | `C3` @ `0x005073bd` (`5E C3` @ `0x005073bc`) |
| Call sites | 3× thiscall | scalar + two derived dtors |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 110 B + `RET 0` | **Confirmed** | bytes + pad `CC` |
| thiscall ECX=self (not stack-arg dtor) | **Confirmed** | prolog / call sites |
| Linked release @ +0x0C / refcount +6 | **Confirmed** | opcodes + SubInit mirror |
| Pool free buffer@+0x30 cap@+0x38 tag 0x12 | **Confirmed** | `AND 7FFFFFFF; *8; PUSH 12` |
| Empty cap sentinel skip (`0x80000000`) | **Confirmed** | signed `JS` + SubInit seed |
| Flag high-bit @ +4 → `FUN_005ffdb0(this,0)` | **Confirmed** | `TEST AH; MOV ECX,ESI; PUSH 0` |
| Three-phase vtbl cycle | **Confirmed** | `009cd99c` → `009d81e8` → `009cc290` |
| Body dtor ≠ scalar deleting | **Confirmed** | scalar is peer `005073f0` |
| Pair with SubInit `00581190` | **Confirmed** | shared provisional vtbl + layout |
| Product class English | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| provisional vtbl + linked release | **Yes** |
| capacity test + pool free | **Yes** (bytes seal AND+*8) |
| mid vtbl + flag clear path | **Yes** (`FUN_005ffdb0` thiscall) |
| base vtbl + RET 0 | **Yes** |
| Decompile ≡ original raw CF | **Yes** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Same provisional vtbl as dualed SubInit `00581190` | **Yes** |
| Inverse of SubInit layout (link / cap / refcount offsets) | **Yes** |
| Vtbl slot0 at `009cd99c` = scalar deleting peer `005073f0` | **Yes** |
| Partition system interaction-activation | **Yes** |
| Product/PDB English class name | **No** |
| Runtime Confirmed | **No** |

**Decision:** promote **`VOGPhysics_QueryObject_Dtor_Inferred`**. Reject merge with scalar deleting `005073f0`; reject merge with derived dtors `005074d0` / `006343d0`; reject TtPhantom ctor merge; reject inventing product English; reject Runtime Confirmed.

---

## 7. Gaps

1. Product/PDB demangle for class owning vtbls `009cd99c` / `009d81e8` / `009cc290`.
2. Exact English type of `linked_obj*` and flag-word@+4 dual role (size vs ownership).
3. Dual of scalar deleting wrapper `FUN_005073f0` and derived chain parents.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
