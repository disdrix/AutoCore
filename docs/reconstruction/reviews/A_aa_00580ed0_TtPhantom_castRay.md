# Review A (reconstruction fidelity): `aa_00580ed0` TtPhantom_castRay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580ed0` |
| **VA** | `0x00580ed0`–`0x005810fd` inclusive (**558 B** / `0x22E`) |
| **Canonical name** | `TtPhantom_castRay` |
| **Ghidra name** | `FUN_00580ed0` |
| **Prior scaffolds** | `Skill_TtPhantom_castRay`; `Named_CalleeOf_CVOGCreature_FindTerrainHeight_00580ed0` |
| **Rejected misnames** | `CVOGMap_CastRay`; `Skill_*`; map heightfield merge |
| **Review date** | `2026-08-05` (MEGA-101 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00580ed0_TtPhantom_castRay.md` |
| **System** | input-drive-control / physics |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_xrefs_to` + `get_function_callees` + `get_function_by_address` + `get_function_signature` + `disassemble_function` + `read_memory` + `search_strings`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**TtPhantom::castRay** — walk the phantom broadphase **overlap collidable list**, transform a world ray into each body's local frame, invoke **shape `vtbl[+0x20]`** (castRay) with a shared closest-hit result, stamp the hitting collidable at `result+0x20`, then rotate the hit normal body-local → world via `FUN_005d6ae0`.

```text
TtPhantom_castRay(phantom, ray, result)
  profiler "TtPhantom::castRay"
  optional filter prep (gap: not forwarded in decompile)
  for collidable in phantom.overlap[0..count):
    if shape:
      localStart/End = R^T * (world - T)
      shape->castRay(hitFlag, localRay, result)
      if hitFlag: result.collidable = collidable
  if result.collidable:
    result.normal = R * result.normal   // FUN_005d6ae0
  profiler exit
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF |
| Full body range | `get_function_by_address` `00580ed0–005810fd` |
| Epilogue | `disassemble_function` `RET 0x8` @ `005810fb`; `read_memory` `C2 08 00` |
| Plate string | `read_memory` `0x009d4574` = `TtPhantom::castRay\0`; entry `MOV [ESI],0x9d4574` |
| Callers | `get_function_callers` / `get_xrefs_to` — **2** UNCONDITIONAL_CALL |
| Wheel packer | `disassemble_function` `0x0064bbd0` — ECX=`*(fw+0x38)`, `RET 8` after call |
| Creature path | decompile `CVOGCreature_FindTerrainHeight`; bytes `MOV ECX,[ESI+0x254]` |
| Normal helper | decompile `FUN_005d6ae0` — `out = R·v`, w=0 |
| Prior physics note | `docs/reconstruction/physics/verified/fn_00580ed0_castRay.md` (geometry contract) |

---

## 3. Signature (sealed)

```c
// ECX = this (phantom); stack ray*, result*; void; RET 8
void __thiscall TtPhantom_castRay(void *phantom, float *ray, void *result);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (analyze: register; packer/creature set ECX) | **Confirmed** |
| ray | stack `[EBP+8]` / `param_2` | **Confirmed** |
| result | stack `[EBP+0xc]` / `param_3` | **Confirmed** |
| cleanup | `RET 8` (`C2 08 00`) | **Confirmed** |
| return | void (no meaningful EAX) | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Profiler entry plate + rdtsc | disasm + string | **Confirmed** |
| Filter enable / phantom+8→+0xd0 prep | decompile | **Confirmed** (use = gap) |
| Overlap count `+0x84` / list `+0x80` | decompile + disasm | **Confirmed** |
| World→local start/end (R^T · (P−T)) | decompile SSE sequence | **Confirmed** |
| Shape vtbl+0x20 | decompile | **Confirmed** |
| Stamp collidable @ result+0x20 | disasm `MOV [EDI+0x20],…` | **Confirmed** |
| Post-hit `FUN_005d6ae0` | sole CALL | **Confirmed** |
| Profiler exit `DAT_009d2878` | disasm | **Confirmed** |
| Single return / RET 8 | epilogue | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | **2** UNCONDITIONAL_CALL |
| `0x0064bc61` | wheel collide packer `FUN_0064bbd0` — suspension ray |
| `0x004c629f` | `CVOGCreature_FindTerrainHeight` — phantom ground refine |
| Callees | `FUN_005d6ae0` + indirect shape castRay |
| Cyclomatic | 10 (analyze_function_complete) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Plate `"TtPhantom::castRay"` @ entry | **Yes** |
| Unique string match (search_strings) | **Yes** (1) |
| Distinct from `CVOGMap_CastTerrainHeight` sibling | **Yes** (creature branch) |
| Skill system plate / RTTI | **No** |

**Decision:** promote **`TtPhantom_castRay`**. Retire `Skill_` prefix and `Named_CalleeOf_*` scaffolds. Not `_Inferred` — plate demangle sealed.

---

## 7. Gaps

- Filter object prepared (`local_1c`) but not passed into shape virtual in decompile.
- `ray[9]` / packer `*(fw+0x1f8)` stash unused in body.
- Packer this = `*(fw+0x38)` vs prior note claiming `*(fw+0x1f8)` — field identity residual.
- Shape implementers / closest-hit contract inside vtbl+0x20 not re-dualed here.
- Runtime / bit-exact / differential open (no Launcher).

---

## 8. Verdict

Fidelity path seals CF/ABI/RET8/plate/callers/transform loop with residual filter/this-field gaps → **accept-with-gaps**.
