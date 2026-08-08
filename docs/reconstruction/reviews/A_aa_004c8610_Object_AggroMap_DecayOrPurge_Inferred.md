# Review A (reconstruction fidelity): `aa_004c8610` Object_AggroMap_DecayOrPurge_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8610` |
| **VA** | `0x004c8610` |
| **Body** | `0x004c8610`–`0x004c8779` exclusive (**361** B) |
| **Canonical name** | `Object_AggroMap_DecayOrPurge_Inferred` |
| **Ghidra symbol** | `FUN_004c8610` |
| **Review date** | `2026-08-04` (WQ9F-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md` |
| **System** | object aggro / threat map |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body/float/DAT_009cb8c0) + callers/xrefs + peer decompile `004c8780` / caller `00638ac0`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Tick/decay object-hosted isnil29 map of TFID→score entries; erase zeros (or force-purge all); clear host selection if erased entry was the selected TFID.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004c8610_FUN_004c8610.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8610_FUN_004c8610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_AggroMap_DecayOrPurge_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004c8610.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md` |
| Float | `read_memory` `0x00aaa680` → `9A 99 59 3F` (0.85f) |
| Erase dual | `aa_004cb740` StdTree_EraseAndRebalance_Isnil29_Inferred |
| Peer | `FUN_004c8780` + `Object_ResolveFromTFID` |
| Caller | `FUN_00638ac0` push 0 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 361 B + `ret 4` | **Confirmed** | bounds + `C2 04 00` |
| `__thiscall` ECX=object; char forcePurge | **Confirmed** | `MOV EDI,ECX`; stack BL |
| Map shell @ +0x154 / head @ +0x158 | **Confirmed** | LEA ECX,[EDI+0x154]; load [EDI+0x158] |
| Score *= 0.85f @ +0x20 | **Confirmed** | MULSS + store [ESI+0x20] |
| Keep when forcePurge==0 && score changed | **Confirmed** | TEST BL / CMP ECX,EAX branch |
| Erase via dualed isnil29 erase | **Confirmed** | CALL 004cb740 |
| TFID key @ +0x10 family | **High** | peer ResolveFromTFID; host +0x44 match |
| Clear-target vtbl+0x258 | **High** | CALL [EAX+0x258] + DAT_009cb8c0 |
| Aggro/threat product English | **Inferred** | structural + AI caller; no PDB string in body |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Empty map early out | **Yes** |
| Decay store then branch | **Yes** |
| Keep successor vs purge+erase | **Yes** |
| RET 4 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Map erase dualed isnil29 | **Yes** |
| Peer TFID resolve on same map | **Yes** |
| AI caller cadence | **Yes** |
| Product/PDB method name | **No** |

**Decision:** promote **`Object_AggroMap_DecayOrPurge_Inferred`**. Reject pure `Named_CalleeOf_Erase`; reject skill-cast rename without strings.

---

## 6. Gaps

1. Product/PDB English for method and host class.
2. Live callers of forcePurge!=0 (none in this image xrefs).
3. Nested dual of peer `004c8780` / clear-target slot (not OWN).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
