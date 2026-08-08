# Dual A/B report — MEGA-101 OWN-ONLY (`0x00580ed0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-101**  
**Scope:** VA `0x00580ed0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_xrefs_to` + `get_function_callees` + `get_function_by_address` + `get_function_signature` + `disassemble_function` + `read_memory` + `search_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual seal — partition MEGA-101; system **input-drive-control**; hint CVOGMap_CastRay sibling (resolved as **phantom cast**, not map terrain).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00580ed0` TtPhantom_castRay | **accept-with-gaps** — CF/ABI/RET8/plate/callers/overlap+transform sealed; filter/this-field/runtime residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): map/skill/Named_CalleeOf/cdecl/RET4 merges **falsified**; filter+runtime gaps retained.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00580ed0` — sealed facts

1. **Body:** `0x00580ed0`–`0x005810fd` inclusive (**558 B** / `0x22E`); pad `CC CC` after `RET 8`.
2. **ABI:** **ECX** = this (phantom); stack `float *ray`, `void *result`; void; **`RET 8`** (`C2 08 00` @ `0x005810fb`).
3. **Semantics:** `TtPhantom::castRay`:
   - Profiler bookends (`"TtPhantom::castRay"` @ `0x009d4574` / exit `DAT_009d2878`).
   - Optional filter prep from ray flag `+0x20` and `this+8→+0xd0` (**not** passed to shape vcall in decompile).
   - Walk overlap list `this+0x80` / count `this+0x84`.
   - Per collidable: world→local ray via `R^T*(P−T)`; shape `vtbl[+0x20]`; stamp collidable @ `result+0x20`.
   - On hit: `FUN_005d6ae0` rotates normal body-local → world.
4. **Callees:** `FUN_005d6ae0` only (plus indirect shape castRay, rdtsc profiler).
5. **Callers (2):**  
   - `FUN_0064bbd0` @ `0x0064bc61` — wheel suspension packer (`ECX=*(fw+0x38)`, flag=1).  
   - `CVOGCreature_FindTerrainHeight` @ `0x004c629f` — when `creature+0x254` non-null; else **sibling** `CVOGMap_CastTerrainHeight`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL (same sites).
7. **Name:** `TtPhantom_castRay` (Ghidra `FUN_00580ed0`). Plate demangle sealed.  
   Retired: `Skill_TtPhantom_castRay`, `Named_CalleeOf_CVOGCreature_FindTerrainHeight_00580ed0`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + packer call site.

### Gaps

- Filter object / `ray[9]` unused in decompile (dead prep vs decompiler miss).  
- Framework field for this: packer uses `*(fw+0x38)`; stores `*(fw+0x1f8)` at ray+0x24.  
- Shape `vtbl+0x20` implementers not dualed here.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00580ed0_TtPhantom_castRay.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00580ed0_TtPhantom_castRay.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00580ed0_FUN_00580ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00580ed0_FUN_00580ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TtPhantom_castRay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00580ed0.cpp` |
| Function | `docs/reconstruction/functions/aa_00580ed0_FUN_00580ed0.md` |
| Function named | `docs/reconstruction/functions/aa_00580ed0_TtPhantom_castRay.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGCreature_FindTerrainHeight_00580ed0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Skill_TtPhantom_castRay.cpp` |

---

## Chain context (not dualled; evidence only)

```text
hkVehicleFramework_preUpdate / wheel path
  └─ FUN_0064bbd0  wheel collide packer  [not dualled here]
       └─ TtPhantom_castRay  0x00580ed0  [OWN MEGA-101]
            ├─ shape vtbl+0x20  (e.g. TthkShapeCollection::castRay family)
            └─ FUN_005d6ae0     normal local→world

CVOGCreature_FindTerrainHeight  0x004c6100  [prior dual context]
  ├─ no phantom (+0x254==0) → CVOGMap_CastTerrainHeight  [SIBLING]
  └─ phantom present        → TtPhantom_castRay  [OWN MEGA-101]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00580ed0-mega-101-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00580ed0` | Port as **phantom overlap raycast** (`TtPhantom::castRay`). **thiscall RET 8**. Inputs: world start/end ray + this phantom; outputs: fraction, world normal, hit collidable*. |
| Geometry-later | Do **not** reimplement Havok shapes for v1 wheels — inject `QueryWheelRay` with same I/O contract (see physics verified note). |
| Do not merge | `CVOGMap_CastTerrainHeight` (XZ→Y); `MapCollisionCtx_CastRay` `0x0055e530`. |
| Pair with | wheel packer `0x0064bbd0`; normal helper `0x005d6ae0`; creature `0x004c6100` phantom branch. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md` / coverage ledgers for `aa_00580ed0` → dual **accept-with-gaps**, name `TtPhantom_castRay`
- Do not claim runtime Confirmed without Launcher golden

---

## Live tool evidence summary

| Tool | Result |
|------|--------|
| `decompile_function` | full body; ≡ prior raw |
| `analyze_function_complete` | worker; 148 insn; 17 BB; cyclomatic 10; callees/callers/xrefs |
| `get_function_callers` | `CVOGCreature_FindTerrainHeight`, `FUN_0064bbd0` |
| `get_xrefs_to` | `004c629f`, `0064bc61` UNCONDITIONAL_CALL |
| `get_function_callees` | `FUN_005d6ae0` |
| `get_function_by_address` | body `00580ed0–005810fd` |
| `disassemble_function` | prologue/epilogue; packer call site; `RET 0x8` |
| `read_memory` | plate string; epilogue `C2 08 00`; packer/creature call bytes |
| `search_strings` | 1× `TtPhantom::castRay` @ `009d4574` |
