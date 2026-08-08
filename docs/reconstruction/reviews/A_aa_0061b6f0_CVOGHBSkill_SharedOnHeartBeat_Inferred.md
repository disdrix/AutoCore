# Review A (reconstruction fidelity): `aa_0061b6f0` CVOGHBSkill_SharedOnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061b6f0` |
| **VA** | `0x0061b6f0`–`0x0061b955` |
| **Canonical name (Ghidra)** | `FUN_0061b6f0` |
| **Proposed name** | `CVOGHBSkill_SharedOnHeartBeat_Inferred` |
| **Review date** | `2026-08-04` (WQ9D-C OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |
| **System** | `skills-abilities` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared skill heartbeat **OnHeartBeat** pulse used as:

1. **vtbl+0x08** method for multiple `CVOGHBSkill_*` classes (Chain, InverseChain, Aggregate, …), and  
2. **Subroutine** called by specialized OnHB overrides (Virus) and wrappers (`FUN_0061ba80`).

Runs reschedule/status, increments pulse counter, optionally applies combat side-effect cascade, then writes status out.

Not cast validation, not Virus multi-spread, not `Skill_GatherTargetsInArea`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0061b6f0` |
| Bytes | `read_memory` prologue + epilogue `ret 4` |
| Meta | `get_function_by_address` body `0061b6f0`–`0061b955` |
| Xrefs | 2 UNCONDITIONAL_CALL + 9 DATA vtbl |
| Callees | `analyze_function_complete` |
| RTTI sample | COL→type_info: `.?AVCVOGHBSkill_Chain@@`, `…_InverseChain@@`, `…_Aggregate@@` |
| Consumer | Virus dual cites this as shared pulse |
| Constant | `DAT_00af4bd0` = **0x10** (`read_memory`) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, dual of nested effect leaves / `FUN_005787a0`.

---

## 3. Signature

```c
void __thiscall CVOGHBSkill_SharedOnHeartBeat_Inferred(
    int32_t *thisHb, uint32_t *pOutStatus);
// ret 4
```

---

## 4. Sealed CF (fidelity)

| Step | Result |
|---|---|
| `FUN_005787a0` → local status | **Yes** |
| `this[+0x6c8]++` | **Yes** |
| Gate: status≠0x10 ∧ flag@+0x20==0 ∧ (state>1 ∨ state==-1000) | **Yes** |
| Optional short@+0x74 → owner vtbl+0x214 → vtbl+0x88 + TFID@+0x668 | **Yes** |
| float@+0x114 → resolve → heat `00589bc0` | **Yes** |
| flag@+0x44 → flag8 (`005134e0`) → `vtbl+0x18(1,1)` | **Yes** (both MI branches) |
| bit2 @+0x648 → resolve → HP `00589c70` | **Yes** |
| float@+0x144 → resolve → shield `00589d90` | **Yes** |
| bit7 @+0x649 → resolve → `0058cc40` | **Yes** |
| bit0 @+0x648 → resolve multi-arg → `0058d8e0` | **Yes** |
| float@+0x110 → resolve + `DAT_00d02ac0` → impulse `0058c3b0` | **Yes** |
| `this.vtbl+0x50()` | **Yes** |
| `*pOutStatus = status` | **Yes** |
| Live ≡ raw | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body size / ret 4 | **High** | meta + epilogue bytes |
| Shared OnHB / multi-class vtbl+0x08 | **High** | DATA xrefs + RTTI sample |
| Effect cascade order | **High** | decompile ≡ raw |
| Name product English | **Inferred** | no plate; multi-class shared |
| Nested `FUN_005787a0` full semantics | residual | not OWN |
| Field English glossary | open | |
| Runtime / stacking | open | |

---

## 6. Gaps

1. Product design English for each effect field / bit.  
2. Dual of `FUN_005787a0` and effect leaves (not OWN).  
3. Complete census of all RTTI classes installing this vtbl slot.  
4. Why both MI branches of the flag8 gate call the same stop (decompiler duplication vs real CF).  
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
