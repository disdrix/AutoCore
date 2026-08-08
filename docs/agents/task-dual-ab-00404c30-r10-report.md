# Dual A/B report — R10-022 OWN-ONLY (`0x00404c30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-022**  
**Scope:** VA `0x00404c30` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent dual `0x00404c60` write ownership).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + caller decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R10 — partition row R10-022 / skills-abilities residual under parent dual `0x00404c60`.  
**Parent dual (evidence only):** `Object_Store16At80_Inferred` @ `0x00404c60` (MEGA-053 sealed).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404c30` Object_Store16At90_Inferred | **accept-with-gaps** — CF/ABI/RET4/+0x90/16B/leaf/5 callers sealed; product field English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-string identity / out-copy / twin-merge / cdecl / ECX=src / non-leaf / 4-caller-only claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404c30` — sealed facts

1. **Body:** `0x00404c30`–`0x00404c59` inclusive (**42 B** / `0x2A`); pad `CC` after `RET 4` before twin at `0x00404c60`.
2. **ABI:** **ECX** = destination object; stack `const uint32_t src[4]*`; void; **`RET 4`**.
3. **Semantics:** leaf **16-byte field store** into **`this+0x90..0x9c`**:
   - `mov eax, [esp+4]` → src  
   - four dword pairs `this[0x90+4i] ← src[i]`  
   - no branches; no callees; no float ops in body.
4. **Callees:** none (leaf).
5. **Callers (5):**  
   - `FUN_0058a1b0` @ `0x0058a271` (skill/creature apply; after twin)  
   - `FUN_005c76f0` @ `0x005c7804` (`CLoadNode::_initPhysics`; type `0xe`)  
   - `FUN_00620480` @ `0x00620633` (skill template path)  
   - `FUN_00812360` @ `0x008124f2` (teleport/reaction; when `*(obj+8)==0`)  
   - `FUN_0091da70` @ `0x0091dcad` (client net / local-player pack)
6. **Xrefs:** 5 `UNCONDITIONAL_CALL`.
7. **Twin (not OWN):** `FUN_00404c60` @ `0x00404c60` / `Object_Store16At80_Inferred` — identical shape, dest **`+0x80..0x8c`**.
8. **Name:** `Object_Store16At90_Inferred` (Ghidra `FUN_00404c30`). Product field English open → `_Inferred`.  
   Retired: `Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00404c30`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB symbol for +0x90 field (pos vs quat vs generic blob).  
- Shared multi-inh object layout plate.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00404c30_Object_Store16At90_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00404c30_Object_Store16At90_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00404c30_FUN_00404c30.md` |
| Annotated | `docs/reconstruction/raw/aa_00404c30_FUN_00404c30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_Store16At90_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404c30.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00404c30.cpp` |
| Function | `docs/reconstruction/functions/aa_00404c30_FUN_00404c30.md` |
| Function named | `docs/reconstruction/functions/aa_00404c30_Object_Store16At90_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00620480  skill template / spawn path  [parent; string on other branch]
  ├─ FUN_00404c60  Object_Store16At80_Inferred  [MEGA-053 dual]
  ├─ FUN_00404c30  Object_Store16At90_Inferred  [OWN R10-022]
  └─ … Skill_EnsureLoadedInTree / CVOGReaction / HB enqueue …

FUN_0058a1b0  skill/creature apply  [parent plate family]
  ├─ FUN_00404c60  [MEGA-053]
  └─ FUN_00404c30  [OWN R10-022]  (flag-gated)

FUN_005c76f0  CLoadNode::_initPhysics
  └─ FUN_00404c60 / FUN_00404c30  (type==0xe path)

FUN_00812360  teleport / reaction path
  └─ FUN_00404c30  [OWN R10-022]  (when *(resolved+8)==0)

FUN_0091da70  client net / local player pack
  └─ FUN_00404c60 then FUN_00404c30  [OWN R10-022]

Peers (shape contrast; dualed elsewhere):
  FUN_0040aff0  Object_CopyTfid16At228_Inferred     [out-copy FROM this]
  FUN_0061b960  Skill_HB_CopyTfid16At668_Inferred   [out-copy FROM this]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00404c30-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00404c30` | Port as **object 16-byte field store** at **`this+0x90`**. **thiscall RET 4**. Leaf only — do not invent skill format strings or float math. Keep distinct from twin store `00404c60` (+0x80) and from TFID **out-copy** helpers `0040aff0` / `0061b960`. |
| Pair with | twin `00404c60` (MEGA-053); skill parents `00620480` / `0058a1b0`; physics load `005c76f0`; teleport `00812360`; client pack `0091da70`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (skills-abilities consumers + generic object field)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00404c30`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + twin offset check. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin retained; `Named_CalleeOf_*` scaffold **retired**.  
- Odd behavior preserved: no float ops in body despite float-packing callers; multi-inh this adjustment only at call sites.  
- `_Inferred` where product field English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
