# Review A (reconstruction fidelity): `aa_0061f940` CVOGHBSkill_Virus_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061f940` |
| **VA** | `0x0061f940`–`0x0061f998` |
| **Canonical name (Ghidra)** | `FUN_0061f940` |
| **Proposed name** | `CVOGHBSkill_Virus_Ctor` |
| **Review date** | `2026-08-04` (WQ9D-B OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Constructor** for `CVOGHBSkill_Virus`: intermediate HB base init, install Virus vtbl, seed multi-spread budget (`+0x6d0`) and period (`+0x6d4` + `SetPeriodAndCounter`). Sole CALL from `CVOGHBSkill_Virus_OnHeartBeat` child-spawn path.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `decompile_function` @ `0x0061f940` |
| Bytes | `read_memory` 128 B @ entry |
| Meta | `get_function_by_address` body `0061f940`–`0061f998` |
| RTTI | `read_memory` type_info `0x00af2b08` → `.?AVCVOGHBSkill_Virus@@` |
| Vtbl | `read_memory` `0x009d14bc`; slot +0x0c = `0x0061fdf0` |
| Caller | `FUN_0061fdf0` @ `0x0062008d` (`operator_new(0x6e0)`) |
| Peer dual | `CVOGHBSkill_Virus_OnHeartBeat` WQ9R-B |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0061f940` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
CVOGHBSkill_Virus* __thiscall CVOGHBSkill_Virus_Ctor(
    CVOGHBSkill_Virus *this,
    void *pPrimaryTarget, void *pSkillBlob, void *pWorld,
    void *pNewTarget, void *pTfidArg, uint32_t arg7,
    int remainBudget,   // → this+0x6d0
    int remainPeriod);  // → this+0x6d4 + SetPeriodAndCounter
// ret 0x20; EAX = this
```

| Item | Evidence |
|---|---|
| Convention | `mov esi, ecx`; terminal `ret 0x20` |
| Vtbl | `mov [esi], 0x009d14bc` |
| Budget/period | stores `+0x6d0` / `+0x6d4` |
| Base | `FUN_00618180(..., 0, 0x3f800000)` |
| Period API | `CVOGHBBase_SetPeriodAndCounter(this, param_9, true)` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base ctor then field stores | Yes |
| Vtbl override after base | Yes |
| SetPeriodAndCounter(true) | Yes |
| Return this | Yes |
| No branches | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = CVOGHBSkill_Virus | **Confirmed** | RTTI string |
| Role = ctor | **High** | vtbl install + new(0x6e0) caller |
| +0x6d0 budget / +0x6d4 period | **High** | bytes + OnHeartBeat use |
| Product English “Virus” beyond RTTI | **Open** | design residual |
| Base ctor field English | **Tentative** | not OWN |

---

## 6. Gaps / open

1. Product design English for Virus skill.  
2. Full semantic names for base-ctor args / `arg7`.  
3. Dual of `FUN_00618180` (not OWN).  
4. Runtime / bit-exact.

**Verdict:** **accept** — class Confirmed; ctor CF/ABI/vtbl High.
