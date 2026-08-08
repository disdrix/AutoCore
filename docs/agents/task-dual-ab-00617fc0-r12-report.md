# Dual A/B report — R12-039 OWN-ONLY (`0x00617fc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-039**  
**Scope:** VA `0x00617fc0` (`aa_00617fc0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent ctor `0x00617ad0`, sibling OnHit spawn `0x00617df0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + COL/type_info. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-039**.  
**Work item:** Residual dual seal — skills-abilities; parent dual `0x00617ad0` (`CVOGHBSkill_OnHit_ctor`).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00617fc0` CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred | **accept-with-gaps** — RTTI Reflect class Confirmed; multi-target spawn CF/ABI/vehicle-host remap/Enqueue sealed; method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): subclass-ctor / still-OnHit / merge-00617df0 / free-function / uses-virtual-this / return-as-count / always-Enqueue / period-in-body / parent-as-CODE-caller claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00617fc0` — sealed facts

1. **Body:** `0x00617fc0`–`0x006180fb` inclusive (**316 B** / `0x13C`); terminal **`C2 18 00`**; pad `CC` before next.
2. **ABI:** six stack formals; **RET 0x18**; **EAX = 1** on terminator. Virtual **ECX this unused** in body.
3. **Class:** RTTI **Confirmed** `.?AVCVOGHBSkill_Reflect@@` via COL `0x00aadc14` → type_info `0x00af28f4` on vtbl `PTR_FUN_009d0f7c`.
4. **Role:** virtual multi-target **Reflect HB spawn factory** (vtbl **+0x2c** @ `0x009d0fa8`):
   - List stride **0x10**; terminator `{−1,−1,type0}`.
   - `CVOGReaction_ResolveObjectTarget` thiscall with ECX=`*(world+0xe4e8)`.
   - If clone type `*(*(t+0xa8)+0x38) == 0xe`: `__RTDynamicCast` → `CVOGVehicle`, remap target to host `*(*(*(veh+4)+4)+veh+0xb0)`.
   - `operator_new(0x6d0)` + `CVOGHBSkill_OnHit_ctor` + install Reflect vtbl.
   - Owner `+0x18` non-null → Enqueue `*(world+0xe4ec)` + Start; else `vtbl[0](1)` (`FUN_00651190`).
5. **Xrefs:** 1 DATA (vtbl); **0** CODE callers.
6. **Callees:** ResolveObjectTarget, __RTDynamicCast, operator_new, OnHit_ctor (`0x00617ad0`), CVOGHBList_Enqueue, CVOGHBBase_Start, scalar dtor.
7. **Parent dual (callee, not OWN):** `CVOGHBSkill_OnHit_ctor` `0x00617ad0` — period seed lives there.
8. **Contrast (not OWN):** OnHit spawn `FUN_00617df0` (vtbl `009d0f1c` +0x2c; no vehicle remap; inlines base ctor).
9. **Name:** `CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred` (Ghidra `FUN_00617fc0`). Method English open → `_Inferred`.
10. **Decompile ≡ raw CF**; assembly corrects Resolve thiscall + vehicle host chain (decompile omits ECX).
11. **Partition parent** `0x00617ad0` is **callee** (OnHit ctor), not live CODE parent of this virtual.

### Gaps

- Product method English for slot +0x2c.  
- Virtual invokers / target-list producers.  
- Null-`operator_new` / null-RTDynamicCast crash paths.  
- Host product English for vehicle COM `+0xb0`.  
- Runtime / bit-exact / differential.  
- Parent OnHit ctor dual is separate OWN (R11-012).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00617fc0_FUN_00617fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00617fc0_FUN_00617fc0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00617fc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00617fc0_FUN_00617fc0.md` |
| Function named | `docs/reconstruction/functions/aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBSkill_Reflect  vtbl PTR_FUN_009d0f7c
  COL 0x00aadc14 → type_info 0x00af28f4  ".?AVCVOGHBSkill_Reflect@@"
  [+0x00] FUN_00651190  scalar-deleting dtor
  [+0x2c] FUN_00617fc0  SpawnActionsForTargetList  [OWN R12-039]
  construct: operator_new(0x6d0)
            └─ CVOGHBSkill_OnHit_ctor 0x00617ad0  [parent dual R11-012; callee]
                 └─ CVOGHBSkillBase_ctor 0x005788d0
            then overwrite vtbl → Reflect

Contrast — do not merge:
  CVOGHBSkill_OnHit     vtbl 009d0f1c  (ctor 00617ad0 / spawn 00617df0)
  Skill_HB_SpawnEntities vtbl 009d0ec4  (ctor 00614dc0 / execute 00615020)
  CVOGHBSkill_Virus      vtbl 009d14bc  (size 0x6e0)
```

Partition host "skills-abilities" / parent dual `0x00617ad0` names the **OnHit intermediate ctor** used as construction helper, not a direct CODE caller of this virtual.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00617fc0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00617fc0` | Port as **Reflect multi-target HB spawner**: list stride 0x10, resolve via reaction at world+0xe4e8, **vehicle type 0xe → host at COM +0xb0**, construct 0x6d0 via OnHit_ctor then Reflect vtbl, Enqueue world+0xe4ec then Start. RET 0x18; return always 1 on terminator. |
| Distinct from | OnHit spawn `00617df0`; OnHit ctor `00617ad0`; Virus; SpawnEntities execute. |
| Pair with | dualed `CVOGHBSkill_OnHit_ctor`; dualed `CVOGHBSkillBase_ctor`; ResolveObjectTarget; HB list Enqueue/Start; vehicle host `+0xb0` family. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred` @ `0x00617fc0` / `aa_00617fc0` (class `CVOGHBSkill_Reflect` Confirmed).
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00617fc0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + RTTI walk. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (Resolve thiscall; vehicle host; RET 0x18; ECX unused).
- Odd behavior preserved: ignores virtual this; unbounded loop without terminator; null-new UB; null-cast UB; return always 1.
- `_Inferred` on method English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
