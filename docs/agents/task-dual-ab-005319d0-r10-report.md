# Dual A/B report — R10-012 OWN-ONLY (`0x005319d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-012**  
**Scope:** VA `0x005319d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` / `get_function_callers` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — character UseItem objective action + LogicUI type `0x0E` (parent dual `0x0060df70` ObjectEventDispatch packet arm).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005319d0` CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred | **accept-with-gaps** — CF/ABI RET0x18/hash+vec/type0xC/RTTI UseItem/LogicUI 0xE/sole caller sealed; UI product English + `FUN_00522b30` name open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-function / always-send / void-return / wrong-arity / non-UseItem / parent-forwards-AL claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005319d0` — sealed facts

1. **Body:** `0x005319d0`–`0x00531afd` inclusive (**302 B** / `0x12E`); pad `CC` @ `0x00531afe`.
2. **ABI:** **ECX** = character*; **6** stack dwords; **`RET 0x18`** (`C2 18 00`) ×2 exits; **AL** bool (`B0 01` success).
3. **Stack (image):**
   - `+0x04` objectiveKey (active-hash key)
   - `+0x08` evaluator index
   - `+0x0C`..`+0x18` COID×4 (caller: `worldObj+0x160`..`+0x16C`)
4. **Semantics:**
   - dual-base = `*( *( *(this+4)+4 ) + this + 0xA8 )`
   - If dual `+0x7E == 0`: skip validation → LogicUI **0x0E** → return **1**
   - Else: `CNDHash_LookupByKey(char+0x548, key)`; index def evaluators `+0x158/+0x15c`; require vtbl `+0x50 == 0x0C`; RTTI → `CVOGObjectiveRequirement_UseItem`; `FUN_00522b30(*(use+0x34), coid×4, *(use+0x3c))`; fail → **0**; success → send
   - Send: type **0x0E**, key + CDQ, index @ packet[0]; queue this = dual **`+0xE8B8`**
5. **Callees:** `CNDHash_LookupByKey`; `__RTDynamicCast`; `FUN_00522b30`; `Client_SendLogicUiPacket`.
6. **Callers:** **1** code — `FUN_0060df70` @ `0x0060e04a` (parent clears AL after call).
7. **Name:** `CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred` (Ghidra `FUN_005319d0`). Product UI/stage English open → `_Inferred`.
8. **Decompile CF ≡ original raw CF ≡ live re-decompile**; ABI arity sealed via image `RET 0x18`.

### Gaps

- Product English for LogicUI type **0x0E**.  
- Product name / full contract of residual `FUN_00522b30`.  
- UseItem `+0x34` / `+0x3c` field English.  
- Full 0x138 packet interior map.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_005319d0_FUN_005319d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005319d0_FUN_005319d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005319d0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_005319d0_FUN_005319d0.md` |
| Function named | `docs/reconstruction/functions/aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
CVOGObjectiveRequirement_UseItem  ObjectEventDispatch  0x0060df70  [parent dual MEGA-038]
  packet arm (event 9 + req+0x34≠0):
    └─ CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred  0x005319d0  [OWN R10-012]
           ├─ CNDHash_LookupByKey (char+0x548)
           ├─ RTTI → CVOGObjectiveRequirement_UseItem
           ├─ FUN_00522b30  residual stage on UseItem+0x34
           └─ Client_SendLogicUiPacket  type 0x0E

Partition: R10-012; system missions-progression; parent dual 0x0060df70
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005319d0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005319d0` | Port as **character UseItem objective action + LogicUI 0x0E notify**. **thiscall RET 0x18** with **6** stack dwords `(key, index, coid0..3)`. Gate dual `+0x7E` clear → send without stage. Live path requires type **0x0C** UseItem + residual stage helper. Pair with dualed ObjectEventDispatch `0060df70`; do **not** forward AL from parent (parent clears). |
| Pair with | dualed `0060df70` ObjectEventDispatch; residual `FUN_00522b30`; dualed active-obj patterns on `char+0x548`. |
| Do not | Treat as free function; invent product name for LogicUI 0x0E; assume parent uses return value. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md` / coverage ledgers — **not touched** this agent  
- Name registry entry when product UI English seals  
- Residual dual for `FUN_00522b30` when scheduled  

**Terminal:** false.
