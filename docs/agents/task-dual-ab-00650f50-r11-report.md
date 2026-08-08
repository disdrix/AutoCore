# Dual A/B report — R11-025 OWN-ONLY (`0x00650f50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-025**  
**Scope:** VA `0x00650f50` (`aa_00650f50`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-025**.  
**Work item:** Residual dual seal — `CVOGHBSkillBase` subclass ctor (`skills-abilities`); parent score VA `0x005788d0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00650f50` CVOGHBSkill_XPAdder_ctor | **accept-with-gaps** — RTTI class / thiscall RET18 / base+vtbl+float0@+0x6c0 / size 0x6d0 / sole caller sealed; peer tick-end dual + runtime residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): MissionPatrol-merge / SpawnEntities-merge / base-identity / dword-width@0x1b0 / tick-in-ctor / multi-caller / runtime-confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00650f50` — sealed facts

1. **Body:** `0x00650f50`–`0x00650f8e` inclusive (**63 B** / `0x3F`); terminal **`C2 18 00`**; pad `CC`.
2. **ABI:** **`__thiscall`** — **ECX=this**; six stack dwords; **RET 0x18**; **EAX=this**.
3. **Semantics:** `CVOGHBSkill_XPAdder` subclass construct (no allocation):
   - `CALL CVOGHBSkillBase_ctor` (`0x005788d0`) with this + 6 stack args.
   - `*this = PTR_FUN_009e5304`.
   - `*(float*)(this+0x6c0) = 0.0f` via `XORPS` + `MOVSS` (decompiler shows `param_1[0x1b0]=0` as dword-index).
4. **RTTI:** COL @ `0x00ab1f30` → type_info `0x00af5178` → **`".?AVCVOGHBSkill_XPAdder@@"`**.
5. **Caller (1 fn / 2 sites):** `FUN_0061c940` @ `0x0061c9f3`, `0x0061ca93` after `operator_new(0x6d0)`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL; no DATA xrefs to entry.
7. **Callees:** `CVOGHBSkillBase_ctor` only.
8. **Family:** partition parent `0x005788d0` — one of 14 skill-base subclass ctors; do **not** merge with SpawnEntities (`00614dc0` / vtbl `009d0ec4` / ushort@`+0x6c4`) or MissionPatrol units.
9. **Name:** `CVOGHBSkill_XPAdder_ctor` (Ghidra `FUN_00650f50`). RTTI bar met → **no** `_Inferred`.
10. **Decompile ≡ raw CF** with documented hazards (thiscall into base; float width at `+0x6c0`).

### Gaps

- Peer duals: tick `0x00650f90`, on-end `0x006510b0`, factory `0x00651100`, dtor `0x00651190`.  
- Sole-caller dual `FUN_0061c940`.  
- Product glossary for float `+0x6c0` beyond XP residual (High from peers).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00650f50_CVOGHBSkill_XPAdder_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00650f50_CVOGHBSkill_XPAdder_ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00650f50_FUN_00650f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00650f50_FUN_00650f50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XPAdder_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00650f50.cpp` |
| Function | `docs/reconstruction/functions/aa_00650f50_FUN_00650f50.md` |
| Function named | `docs/reconstruction/functions/aa_00650f50_CVOGHBSkill_XPAdder_ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
Partition parent (base skill HB):
  FUN_005788d0  CVOGHBSkillBase_ctor  [dualed]
    └─ ValidateTarget / AttachOwner / period  [sealed on base]

This unit (R11-025):
  FUN_00650f50  CVOGHBSkill_XPAdder_ctor  [OWN]
    ├─ CVOGHBSkillBase_ctor
    ├─ vtbl PTR_FUN_009e5304  (RTTI CVOGHBSkill_XPAdder)
    └─ float this+0x6c0 = 0

Sole caller:
  FUN_0061c940  [not dualled]
    ├─ operator_new(0x6d0)
    ├─ FUN_00650f50  ×2 sites
    ├─ CVOGHBList_Enqueue / CVOGHBBase_Start  (accept)
    └─ vtbl delete (reject / no owner)

Peer vtbl (same class; not OWN):
  +0x00 FUN_00651190  scalar deleting dtor
  +0x04 FUN_00650f90  tick (Ghidra mislabel MissionPatrol_Tick; body is XP accumulate)
  +0x14 FUN_006510b0  on-end (subtract residual from character+0xc54)
```

Partition host `skills-abilities` matches class role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00650f50-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00650f50` | Port as **`CVOGHBSkill_XPAdder` ctor**. **thiscall** ECX=this, **6 stack args**, **RET 0x18**, size **0x6d0**. After base skill-HB ctor: vtbl=`PTR_FUN_009e5304`, **`float +0x6c0 = 0`**. |
| Do **not** | Treat `param_1[0x1b0]` as product dword index API; merge with SpawnEntities ushort@`+0x6c4`; import MissionPatrol names; allocate inside ctor. |
| Pair with | dualed `CVOGHBSkillBase_ctor` `005788d0`; residual caller `0061c940`; residual peers `00650f90` / `006510b0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_XPAdder_ctor` @ `0x00650f50` / `aa_00650f50`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00650f50`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + RTTI chain. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses RTTI product name; machine ABI corrections (thiscall into base; MOVSS float@`+0x6c0`).
- Odd behavior preserved: SSE float zero (not integer store); no allocation in unit.
- No invented English beyond RTTI class; `_Inferred` not required. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
