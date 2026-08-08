# Dual A/B report — MEGA-038 OWN-ONLY (`0x0060df70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-038**  
**Scope:** VA `0x0060df70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual seal — UseItem object-event dispatch (events 9/10); caller of dualed ApplyObjectUseProgress `0x0060d630`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0060df70` CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred | **accept-with-gaps** — CF/ABI RET0x1C/event 9\|10/Match+Apply branch/vtbl+0x04/UseItem class sealed; event English + packet helper product open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): direct-caller / 5-arg-ABI / Match-or-Eval-misname / packet-success-return claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0060df70` — sealed facts

1. **Body:** `0x0060df70`–`0x0060e06a` inclusive (**251 B** / `0xFB`); pad `CC` before next.
2. **ABI:** **ECX** = UseItem requirement*; **7** stack dwords; **`RET 0x1C`** (`C2 1C 00`) ×2 exits; fail path **`XOR AL,AL`**.
3. **Stack (image):**
   - `+0x04` charCtx  
   - `+0x08` progress  
   - `+0x0C` eventId ∈ {**9**, **10**}  
   - `+0x10`,`+0x14`,`+0x18` unread in body  
   - `+0x1C` worldObj (COID @ `+0x160`..`+0x16C`)
4. **Semantics (object-event dispatch):**
   - Hard event filter 9|10.
   - Eval (`vtbl+8`) must be incomplete.
   - Optional `req+0x54` vs char MI `+0xFC`.
   - `MatchTargetCore` (`0x0060d460`).
   - **Apply** if event==10 OR `req+0x34==0` → `ApplyObjectUseProgress` (`0x0060d630`); return its AL.
   - Else event9 + flag: index self in parent objective vector `+0x158`; `FUN_005319d0`; return 0.
5. **Class:** `CVOGObjectiveRequirement_UseItem` via vtable `PTR_FUN_009dfc1c`; this method @ **vtbl +0x04** (`0x009dfc20`).
6. **Callees:** Eval vcall; MatchTargetCore; ApplyObjectUseProgress; FUN_005319d0.
7. **Callers:** **0** code; **1** DATA vtbl slot (virtual only).
8. **Name:** `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` (Ghidra `FUN_0060df70`). Product event English open → `_Inferred`. No Named_CalleeOf scaffold to retire.
9. **Decompile CF ≡ raw CF ≡ disassembly stages**; ABI arity sealed via image (`RET 0x1C`), not decompiler formal count.

### Gaps

- Product English for events **9 vs 10**.  
- Product name / full contract of `FUN_005319d0` (LogicUi packet `0xE` path).  
- Base-signature names for unread stack slots.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0060df70_FUN_0060df70.md` |
| Annotated | `docs/reconstruction/raw/aa_0060df70_FUN_0060df70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060df70.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_0060df70_FUN_0060df70.md` |
| Function named | `docs/reconstruction/functions/aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
CVOGObjectiveRequirement_UseItem  vtbl PTR_FUN_009dfc1c
  +0x04  FUN_0060df70  ObjectEventDispatch_Inferred  [OWN MEGA-038]
           ├─ vtbl+8  UseItem_Eval                    [dualed sibling]
           ├─ 0060d460 MatchTargetCore                [dualed]
           ├─ 0060d630 ApplyObjectUseProgress         [dualed WQ7R-H; sole caller = this]
           │     ├─ GiveMission / RemoveInventoryItem / give-by-cbid …
           └─ 005319d0 LogicUi UseItem packet helper  [residual]

Parent partition: MEGA-038; system missions-progression; P91
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0060df70-mega-038-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0060df70` | Port as **UseItem virtual object-event dispatch** (vtbl +0x04). **thiscall RET 0x1C** with **7** stack dwords. Gate events **9\|10**; Eval-incomplete; MatchTargetCore; then Apply (10 or `+0x34==0`) vs packet helper (9 + flag). Packet arm returns **0**. |
| Pair with | dualed Apply `0060d630`; dualed MatchTargetCore `0060d460`; dualed Eval `0060cfe0`; residual `FUN_005319d0`. |
| Do not | Treat as MatchTarget or Apply body; do not assume decompiler 5-arg arity; do not invent product event names without strings/runtime. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md` / coverage ledgers — **not touched** this agent  
- Name registry entry for `ObjectEventDispatch_Inferred` when product event English seals  

**Terminal:** false.
