# Review A (reconstruction fidelity): `aa_00581220` TtPhantom_CtorFromAabbDesc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581220` |
| **VA** | `0x00581220`–`0x005812c6` inclusive (**167 B** / `0xA7`) |
| **Canonical name** | `TtPhantom_CtorFromAabbDesc_Inferred` |
| **Ghidra name** | `FUN_00581220` |
| **Prior scaffold** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220` |
| **Rejected misname** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220`; bare `GetObjectsInArea` (parent, not this leaf) |
| **Review date** | `2026-08-05` (MEGA-037 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` |
| **System** | interaction-activation / physics (TtPhantom) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `get_function_by_address` + `disassemble_function` + `read_memory` + `get_assembly_context` + `search_strings` + parent decompile `0x004ea350` + dualed `TtPhantom_castRay`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **constructor** for retail **TtPhantom** (0x90-byte broadphase phantom / box-list query object). Copies an AABB box descriptor into the object, installs vtbl `PTR_FUN_009d45b0`, zeroes the overlap list that `TtPhantom_castRay` later walks, and returns `this`.

```text
TtPhantom_CtorFromAabbDesc_Inferred(this, srcDesc)
  refcount(+6) = 1
  zero / sentinel field block (+8..+0x50)
  self-link(+0x2c) = this
  vtbl = 009d45b0
  overlap(+0x80/+0x84) = empty; cap(+0x88)=0x80000000
  aabb(+0x60..+0x7c) = srcDesc[+0x20..+0x3c]   // 8 dwords
  lead(+0x28) = *srcDesc
  return this
```

Primary parent path: **`CVOGPhysicsUtils_GetObjectsInArea` mode-1** (partition hint: GetObjectsInArea mode-1 box/list).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (identity) |
| Full body | `get_function_by_address` `00581220–005812c6`; `disassemble_function` |
| Epilogue | `RET 0x4` @ `005812c4`; `read_memory` `C2 04 00` |
| Vtbl | `MOV [EAX],0x009d45b0` @ `00581273` |
| Sibling dtor | `FUN_005812d0` same vtbl; frees `+0x80` vector |
| Parent mode-1 | decompile `FUN_004ea350` — alloc 0x90 → this → `FUN_0055ff20` |
| Type plate | dualed `TtPhantom_castRay` `"TtPhantom::castRay"` @ `0x009d4574` + overlap `+0x80/+0x84` |
| Call-site ctx | `get_assembly_context` on all 6 xrefs |
| Prior parent dual | `A_aa_004ea350_CVOGPhysicsUtils_GetObjectsInArea.md` mode-1 note |

---

## 3. Signature (sealed)

```c
// ECX=this; stack const AabbDesc*; EAX=this; RET 4
TtPhantom* __thiscall TtPhantom_CtorFromAabbDesc_Inferred(
    TtPhantom* this,
    const uint32_t* aabbDesc);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → EAX (`MOV EAX,ECX`) | **Confirmed** |
| aabbDesc | stack `[ESP+4]` after entry | **Confirmed** |
| return | EAX = this | **Confirmed** |
| cleanup | `RET 4` (`C2 04 00`) | **Confirmed** |
| callees | none (leaf) | **Confirmed** |
| object size | callers alloc **0x90**; tag `*(uint16*)(this+4)=0x90` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Refcount word +6 = 1 | `MOV word [EAX+6],1` | **Confirmed** |
| Empty-vector caps `0x80000000` | three + overlap | **Confirmed** |
| Self-link `+0x2c = this` | after zero then rewrite | **Confirmed** |
| Vtbl install `009d45b0` | dword store | **Confirmed** |
| AABB 8-dword copy from src+0x20 | sequential MOV | **Confirmed** |
| Lead `*src` → `+0x28` | final stores | **Confirmed** |
| Single return / RET 4 | epilogue | **Confirmed** |
| No calls / no branches | leaf straight-line | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf ctor (worker) |
| External call sites | **6** UNCONDITIONAL_CALL |
| `0x004eaa5f` | `GetObjectsInArea` mode-1 box/list |
| `0x0064d129` | `hkVehicleFramework_preUpdate` → vehicle+0x38 |
| `0x004caaa2` | creature phantom @ +0x254 |
| `0x005dd1db` / `0x0093218b` / `0x0058e09f` | same alloc+ctor pattern |
| Callees | **none** |
| Register follow-up | parents call `FUN_0055ff20` (world insert) — **not** this VA |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Class plate via dualed `TtPhantom_castRay` + shared layout | **Yes** |
| Vehicle/creature phantom slot consumers | **Yes** |
| Parent dual mode-1 names this VA as box/list | **Yes** |
| Ctor plate / RTTI demangle on **this** entry | **No** |
| Scaffold VOG_DEBUG_STOP seed | **No** (reject) |

**Decision:** promote **`TtPhantom_CtorFromAabbDesc_Inferred`**. Class English sealed; method suffix **`_Inferred`**.

---

## 7. Gaps

- Full `009d45b0` vtbl slot English.
- Descriptor field names beyond AABB floats + lead dword.
- Semantic of `+0x24 = 2` and intermediate empty vectors at +0x38/+0x44/+0x50.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals CF/ABI/layout/callers and class identity via dualed castRay + parent mode-1; method English remains inferred → **accept-with-gaps**.
