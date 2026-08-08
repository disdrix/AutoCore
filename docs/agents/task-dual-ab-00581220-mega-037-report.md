# Dual A/B report — MEGA-037 OWN-ONLY (`0x00581220`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-037**  
**Scope:** VA `0x00581220` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `get_function_by_address` + `disassemble_function` + `read_memory` + `get_assembly_context` + `search_strings` + parent decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual seal — nested undualed callee of dualed **CVOGPhysicsUtils_GetObjectsInArea** (`0x004ea350`): mode-1 box/list **TtPhantom** ctor.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` (MEGA-037).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00581220` TtPhantom_CtorFromAabbDesc_Inferred | **accept-with-gaps** — CF/ABI/RET4/EAX=this/layout/6 callers/class family sealed; method English inferred; vtbl residual; runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): GetObjectsInArea-identity / VOG_DEBUG_STOP seed / cdecl / void-return / mode-2 merge / in-ctor query claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00581220` — sealed facts

1. **Body:** `0x00581220`–`0x005812c6` inclusive (**167 B** / `0xA7`); pad `CC` before dtor twin `FUN_005812d0` @ `0x005812d0`.
2. **ABI:** **ECX** = this; stack `const AabbDesc*`; **EAX** = this; **`RET 4`** (`C2 04 00`).
3. **Semantics:** leaf **TtPhantom** ctor (alloc size **0x90**):
   - refcount word @ `+0x06` = 1;
   - type tag @ `+0x24` = 2; self-link @ `+0x2c` = this;
   - empty-vector caps `0x80000000` @ `+0x38/+0x44/+0x50/+0x88`;
   - vtbl `PTR_FUN_009d45b0`;
   - empty overlap list @ `+0x80/+0x84` (same slots dualed **`TtPhantom_castRay`** walks);
   - copy 8 dwords AABB from `src+0x20` → `this+0x60`; lead `*src` → `+0x28`.
4. **Callees:** **none** (leaf).
5. **Callers / xrefs:** **6** UNCONDITIONAL_CALL — `GetObjectsInArea` mode-1 @ `0x004eaa5f`; `FUN_00932060`; `FUN_004ca9f0` (creature+0x254); `FUN_005dd080`; `hkVehicleFramework_preUpdate` (vehicle+0x38); thin factory @ `0x0058e09f`.
6. **Type identity:** sibling dtor same vtbl; vehicle/creature phantom slots feed dualed `TtPhantom_castRay` (`"TtPhantom::castRay"` @ `0x009d4574`); parent dual already names mode-1 box/list via this VA.
7. **Name:** `TtPhantom_CtorFromAabbDesc_Inferred` (Ghidra `FUN_00581220`). Retire `Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Full `009d45b0` vtbl slot English.  
- Descriptor field names beyond AABB floats + lead dword; meaning of `+0x24=2`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify APPEND) | `docs/reconstruction/raw/aa_00581220_FUN_00581220.md` |
| Annotated | `docs/reconstruction/raw/aa_00581220_FUN_00581220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TtPhantom_CtorFromAabbDesc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00581220.cpp` |
| Function | `docs/reconstruction/functions/aa_00581220_FUN_00581220.md` |
| Function named | `docs/reconstruction/functions/aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` |

**Retired scaffold clean (do not promote):**  
`docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_00581220.cpp`

---

## Chain context (not dualled here; evidence only)

```text
CVOGPhysicsUtils_GetObjectsInArea  FUN_004ea350  [dualed parent]
  ├─ mode==1:
  │     expand AABB center±radius
  │     alloc 0x90
  │     FUN_00581220  TtPhantom_CtorFromAabbDesc_Inferred  [OWN MEGA-037]
  │     FUN_0055ff20  world register
  │     iterate phantom[+0x80] count[+0x84]
  ├─ mode==2: FUN_006c7fa0 / FUN_005ebec0  (0xd0 path; residual)
  └─ else: AABB profile string + world vtbl query

hkVehicleFramework_preUpdate
  └─ FUN_00581220 → vehicle+0x38 → TtPhantom_castRay  [dualed MEGA-101]

FUN_004ca9f0
  └─ FUN_00581220 → creature+0x254 → FindTerrainHeight phantom path

FUN_005812d0  dtor twin (same vtbl)  [residual / not OWN]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00581220-mega-037-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00581220` | Port as **TtPhantom field-init ctor from AABB desc**. **thiscall RET 4**, **EAX=this**. Object **0x90**. Empty overlap list; no query inside. |
| Pair with | dualed parent `004ea350`; dualed `TtPhantom_castRay` `00580ed0`; residual dtor `005812d0`; residual register `0055ff20`; mode-2 ctors residual. |
| Do not | Merge with GetObjectsInArea manager; claim VOG_DEBUG_STOP; implement mode-2 sphere path here; drop `_Inferred` without plate. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` interaction-activation / physics residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00581220`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + parent/castRay cross-check. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine twin keeps `FUN_*`; ABI corrections (thiscall RET 4; EAX=this).  
- Odd behavior preserved: decompiler `void` corrected; `+0x2c` zero-then-self rewrite; callers stamp size tag before ctor.  
- `_Inferred` where method English unproven; class family sealed via dualed castRay plate. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
