# Dual A/B report — R11-021 OWN-ONLY (`0x00626240`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-021**  
**Scope:** VA `0x00626240` (`aa_00626240`) only. Dual A/B + raw append / annotated / clean named + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees/bulk xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-021**.  
**Work item:** Residual dual seal — skills-abilities PossessCreature skill HB ctor (parent score `0x005788d0`).  
**Hint retired:** `Named_VOG_DEBUG_STOP_00626240` (string-only scaffold misname).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00626240` CVOGHBSkill_PossessCreature_ctor | **accept-with-gaps** — CF + ABI RET0x18 + RTTI class + vtbl `0x009d1ba4` + size `0x6f0` + fields `+0x6c0/6c4/6c8/6c9` + non-fatal cast assert sealed; non-OWN vtbl English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): debug-stop-as-class / alloc-inside / fatal-cast / wrong-cast-subject / size-0x6c0 / multi-full-ctor / Enqueue claims **falsified**; string scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00626240` — sealed facts

1. **Body:** `0x00626240`–`0x006262e4` inclusive (**165 B** / `0xA5`); terminal **`C2 18 00`**; pad `CC` before next leaf `0x006262f0`.
2. **ABI:** **`__thiscall`** ECX = this; **6** stack dwords; **RET 0x18**; EAX = this.
3. **Semantics:** **`CVOGHBSkill_PossessCreature` ctor**:
   - SEH (`LAB_009a8ae8`).
   - `CVOGHBSkillBase_ctor` (`0x005788d0`) with full skill args.
   - Install vtbl **`0x009d1ba4`**.
   - Clear `+0x6c8`, `+0x6c4`, `+0x6c9`.
   - `__RTDynamicCast(pTarget, 0, CVOGClonedObjectBase, CVOGCreature, 0)` → `+0x6c0`.
   - Null → `FUN_007a4480(0, "VOG_DEBUG_STOP")` then **still return this**.
4. **RTTI:** COL@`0x00aae5ec` → TD@`0x00afecec` **`.?AVCVOGHBSkill_PossessCreature@@`** (**Confirmed**).
5. **Object size:** **0x6f0** (factory `push 0x6f0`; type-table id **`0x1a`** in `FUN_0054a640`).
6. **Code xrefs:** **1** UNCONDITIONAL_CALL from `0x006263ab`.
7. **DATA xrefs (vtbl):** registry `0x0054aec0`, default factory `0x0054cbeb`, install site `0x00626297`.
8. **Callees:** `CVOGHBSkillBase_ctor`, `__RTDynamicCast`, `FUN_007a4480`.
9. **Name:** `CVOGHBSkill_PossessCreature_ctor` (Ghidra `FUN_00626240`). Product class **RTTI Confirmed** (not `_Inferred`).
10. **Decompile ≡ raw CF**; RET 0x18 + field immediates sealed via `read_memory` (no `disassemble_bytes`).
11. **Partition parent** `0x005788d0` is skill-base ctor (dualed elsewhere); **live structural full-ctor caller** is site `0x006263ab` (not OWN).

### Gaps

- Product English for non-OWN vtbl methods on `0x009d1ba4`.  
- Producers of `+0x6c4` after construction (consumer visible off-OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00626240_CVOGHBSkill_PossessCreature_ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00626240_CVOGHBSkill_PossessCreature_ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00626240_FUN_00626240.md` |
| Annotated | `docs/reconstruction/raw/aa_00626240_FUN_00626240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00626240.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_00626240.cpp` |
| Function | `docs/reconstruction/functions/aa_00626240_FUN_00626240.md` |
| Function named | `docs/reconstruction/functions/aa_00626240_CVOGHBSkill_PossessCreature_ctor.md` |
| Scratch | `docs/reconstruction/tmp/a_00626240.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0054a640  skill-HB type registry
  └─ id 0x1a: operator_new(0x6f0); *vtbl = 0x009d1ba4

FUN_0054cbb0  default factory
  └─ operator_new(0x6f0); FUN_00578830(); *vtbl = 0x009d1ba4

factory/spawn leaf (~0x00626320, not OWN)
  └─ operator_new(0x6f0)
  └─ FUN_00626240  CVOGHBSkill_PossessCreature_ctor  [OWN R11-021]
        └─ CVOGHBSkillBase_ctor (0x005788d0)  [dualed parent]
        └─ __RTDynamicCast → CVOGCreature*
        └─ FUN_007a4480 ("VOG_DEBUG_STOP") optional

vtbl 0x009d1ba4 methods (not OWN this dual):
  e.g. FUN_00626160 EndOrDestroy-ish, FUN_00626400 pack, FUN_00626460 unpack, …
```

Do **not** merge with:
- `CVOGHBActivatePlayer_*` (size `0x2c`, vtbl `0x009e3168`)
- `CVOGHBSkill_Virus_*` (size `0x6e0`, vtbl `0x009d14bc`)
- bare `CVOGHBSkillBase` (vtbl `0x009d3fdc`)

---

## AutoCore impact

| Port note |
|-----------|
| Port as **PossessCreature skill HB ctor**: base skill construct → subclass vtbl → clear flags → bind creature via dyn_cast of **target** arg → non-fatal debug helper on null. Preserve **ret 0x18**, object size **0x6f0**, and cast-fail continuation. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + complete analysis / xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- No invented product names; RTTI Confirmed class used.  
- Avoid bare `undefined4` in clean (`uint32_t` / `uint8_t` / `void*`).

---

## This report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00626240-r11-report.md` |
