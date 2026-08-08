# Dual A/B report — R12-023 OWN-ONLY (`0x0054cbb0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-023**  
**Scope:** VA `0x0054cbb0` (`aa_0054cbb0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-023**.  
**Work item:** Residual dual seal — skills-abilities PossessCreature **default factory** (parent dual `0x00626240`).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0054cbb0` CVOGHBSkill_PossessCreature_DefaultFactory_Inferred | **accept-with-gaps** — CF + ABI bare-RET + size `0x6f0` + base DefaultCtor + vtbl `0x009d1ba4` + DATA factory slot sealed; dispatcher English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): full-ctor-merge / thiscall / RET4 / wrong-size / wrong-base-ctor / multi-CALL / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0054cbb0` — sealed facts

1. **Body:** `0x0054cbb0`–`0x0054cc02` inclusive (**83 B** / `0x53`); terminal **`C3`**; pad `CC` before next leaf `0x0054cc10`.
2. **ABI:** **cdecl**; **0** stack args; bare **`RET`**; EAX = object* or null.
3. **Semantics:** **PossessCreature default factory**:
   - SEH (`LAB_009a43fb`).
   - `operator_new(0x6f0)`.
   - Null → return null.
   - `CVOGHBSkillBase_DefaultCtor` (`0x00578830`, thiscall ECX=alloc).
   - Install vtbl **`0x009d1ba4`**.
   - Return object*.
4. **Class / size:** same family as parent dual R11-021 — RTTI Confirmed `CVOGHBSkill_PossessCreature`, size **0x6f0**, vtbl **0x009d1ba4** (class Confirmed inherited; factory role **Inferred**).
5. **Code xrefs:** **0** UNCONDITIONAL_CALL.
6. **DATA xrefs:** **1** — dword @ **`0x009d1bec`** = `0x0054cbb0` (factory function pointer adjacent to vtbl region).
7. **Callees:** `operator_new`, `CVOGHBSkillBase_DefaultCtor` (`0x00578830`).
8. **Name:** `CVOGHBSkill_PossessCreature_DefaultFactory_Inferred` (Ghidra `FUN_0054cbb0`).
9. **Decompile ≡ raw CF**; size/vtbl/ret sealed via `read_memory` (no `disassemble_bytes`).
10. **Not** full-arg ctor: does not call `0x00626240`, no creature dyn_cast, no `+0x6c*` subclass tail init.

### Gaps

- Product English for who loads/dispatches `0x009d1bec`.  
- Indirect call-site catalog beyond single DATA pointer.  
- Whether default-factory instances later receive full field bind elsewhere.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0054cbb0.cpp` |
| Function | `docs/reconstruction/functions/aa_0054cbb0_FUN_0054cbb0.md` |
| Function named | `docs/reconstruction/functions/aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0054cbb0.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0054a640  skill-HB type registry (id 0x1a family)
  └─ size 0x6f0; vtbl 0x009d1ba4

FUN_0054cbb0  DefaultFactory  [OWN R12-023]
  └─ operator_new(0x6f0)
  └─ CVOGHBSkillBase_DefaultCtor (0x00578830)  [dualed W23-S]
  └─ *vtbl = 0x009d1ba4
  DATA slot: 0x009d1bec → this entry

factory/spawn full-arg leaf (~0x00626320, not OWN)
  └─ operator_new(0x6f0)
  └─ FUN_00626240  CVOGHBSkill_PossessCreature_ctor  [parent dual R11-021]
        └─ CVOGHBSkillBase_ctor (0x005788d0)
        └─ __RTDynamicCast → CVOGCreature* @ +0x6c0
        └─ FUN_007a4480 ("VOG_DEBUG_STOP") optional
```

Do **not** merge with:
- full-arg `CVOGHBSkill_PossessCreature_ctor` (`0x00626240`)
- `CVOGHBActivatePlayer_*` (size `0x2c`, vtbl `0x009e3168`)
- `CVOGHBSkill_Virus_*` (size `0x6e0`, vtbl `0x009d14bc`)
- bare `CVOGHBSkillBase` default (vtbl `0x009d3fdc` only)

---

## AutoCore impact

| Port note |
|-----------|
| Port as **PossessCreature default factory**: `new(0x6f0)` → skill-base **default** ctor → subclass vtbl. Preserve null-new → null. Do **not** treat as full-arg ctor (no creature bind / no `ret 0x18` arg frame). Keep object size **0x6f0**. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs/callers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended**.  
- Name uses `_Inferred` (factory role); class identity High via parent RTTI — **never Runtime Confirmed**.  
- Avoid bare `undefined4` in clean (`void *` / `uint32_t`).

---

## This report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0054cbb0-r12-report.md` |
