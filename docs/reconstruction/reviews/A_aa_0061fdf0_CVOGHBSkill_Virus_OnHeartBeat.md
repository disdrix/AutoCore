# Review A (reconstruction fidelity): `aa_0061fdf0` CVOGHBSkill_Virus_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061fdf0` |
| **VA** | `0x0061fdf0`–`0x00620186` |
| **Canonical name (Ghidra)** | `FUN_0061fdf0` |
| **Proposed name** | `CVOGHBSkill_Virus_OnHeartBeat` |
| **Review date** | `2026-08-04` (WQ9R-B OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |
| **System** | `skills-abilities` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **OnHeartBeat** for skill heartbeat class **`CVOGHBSkill_Virus`**. After shared pulse and primary-target validation, **ally-mode area gather** (mode **1**) and **spawn child Virus HBs** for each resolved TFID, subject to RNG and budget counters.

Not cast validation, not `Skill_GatherTargetsInArea` itself, not base `CVOGHBBase_TryFire`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0061fdf0` |
| Bytes | `read_memory` prologue + gather site + epilogue `ret 4` |
| Meta | `get_function_by_address` body range |
| Xrefs | DATA only `0x009d14c8` (vtbl) |
| Callees | `get_function_callees` |
| RTTI | COL `0x00aae0b8` → type_info `0x00af2b08` → `.?AVCVOGHBSkill_Virus@@` |
| Ctor | `FUN_0061f940` installs `PTR_FUN_009d14bc` |
| Gather residual | `reviews/a_0058d330.md` caller row mode=1 filterA=-1 |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, dual of ctor/`FUN_0061b6f0`.

---

## 3. Signature

```c
void __thiscall CVOGHBSkill_Virus_OnHeartBeat(
    CVOGHBSkill_Virus *this, uint32_t *pOutStatus);
// ret 4
```

---

## 4. RTTI / vtbl seal

| Item | Value | Confidence |
|---|---|---|
| Class name | `CVOGHBSkill_Virus` | **Confirmed** |
| Vtbl | `0x009d14bc` | **High** |
| Slot +0x0c | this function | **High** |
| Slot +0x08 | `CVOGHBBase_TryFire` `0x005082c0` | **High** (peer dual) |
| Role | OnHeartBeat | **High** |

---

## 5. Control flow: clean ≡ raw ≡ live (stages)

| Stage | Match |
|---|---|
| Pulse `FUN_0061b6f0` | Yes |
| Resolve target + vtbl+0x198 gate | Yes |
| Flag `world+0x7e` + `this+0x10` | Yes |
| RNG `(u%100)>0x19` | Yes |
| Creature(+0x250)/Physics RTTI | Yes |
| Gather mode=1 filterA=-1 | Yes (bytes + residual) |
| maxTargets +0x102 default 4 | Yes |
| radius field / 50.f default | Yes |
| Decrement +0x6d0/+0x6d4 | Yes |
| new 0x6e0 + ctor + Enqueue + Start | Yes |
| Fail vtbl+0x18(1,1); *out=0 | Yes |
| Success *out = pulse status | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class RTTI name | **Confirmed** | type string |
| OnHeartBeat slot | **High** | TryFire dual map |
| Ally gather ABI | **High** | mode 1 / -1 |
| Child Virus ctor | **High** | same vtbl factory |
| Field English (`+0x7e`, `+0x102`) | **Tentative** | offsets sealed |
| Resolve loop uses advancing TFID | **Probable** | decompiler sticky base risk |
| Runtime | **Open** | no Launcher |

---

## 7. Gaps / open

1. Product design doc for "Virus" skill (spread semantics).  
2. Dual of `FUN_0061f940` / `FUN_0061b6f0` (not OWN this partition).  
3. `FUN_0051b720` pad consumer (WQ9R-A).  
4. Decompiler resolve-arg sticky vs `pA++` — static risk only.  
5. Runtime / bit-exact / stacking.

**Verdict:** **accept-with-gaps** — identity + multi-spread CF High; nested helper English residual.
