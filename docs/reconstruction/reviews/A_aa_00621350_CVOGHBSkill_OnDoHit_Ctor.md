# Review A (reconstruction fidelity): `aa_00621350` CVOGHBSkill_OnDoHit_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621350` |
| **VA** | `0x00621350`–`0x00621383` |
| **Canonical name (Ghidra)** | `FUN_00621350` |
| **Proposed name** | `CVOGHBSkill_OnDoHit_Ctor` |
| **Review date** | `2026-08-05` (R11-017 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md` |
| **System** | skills-abilities |
| **Parent** | `0x005788d0` `CVOGHBSkillBase_ctor` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Constructor** for `CVOGHBSkill_OnDoHit`: call sealed skill-base ctor, install OnDoHit vtbl `PTR_FUN_009d15c4`, return `this`. No extra field stores. Two CODE callers further specialize the vtbl after this returns.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00621350` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/vars) |
| Bytes | `read_memory` 64 B @ entry |
| Meta | `get_function_by_address` body `00621350`–`00621383` |
| RTTI | COL `0x00aae1a0` → type_info `0x00af1d80` → name `.?AVCVOGHBSkill_OnDoHit@@` |
| Vtbl | `read_memory` `0x009d15c4` first slots |
| Callers | `FUN_00621f50` @ `0x00621fe9`; `FUN_006235e0` @ `0x0062361e` |
| Globals audit | `audit_globals_in_function` → sole global `PTR_FUN_009d15c4` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00621350` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`, other VAs as OWN targets.

---

## 3. Signature

```c
CVOGHBSkill_OnDoHit* __thiscall CVOGHBSkill_OnDoHit_Ctor(
    CVOGHBSkill_OnDoHit *this,  // ECX
    void *pSourceObj,           // param_2 — base TFID seed
    void *pSkillBlob,           // param_3 — skill runtime blob
    uint32_t arg4,              // param_4 → base +0x688
    void *pTarget,              // param_5 — ValidateTarget + AttachOwner
    void *pTfid16,              // param_6 → base +0x690..
    uint32_t arg7);             // param_7 → base +0x6a8
// ret 0x18; EAX = this
```

| Item | Evidence |
|---|---|
| Convention | `mov esi, ecx`; terminal `ret 0x18` |
| Vtbl | `mov [esi], 0x009d15c4` |
| Base | `CVOGHBSkillBase_ctor` / `FUN_005788d0` @ `0x005788d0` |
| Extra fields | **None** in this unit |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base ctor then vtbl install | Yes |
| Vtbl override after base | Yes |
| Return this | Yes |
| No branches / no extra stores | Yes |
| Live callee rename only | Yes (`FUN_005788d0` ↔ `CVOGHBSkillBase_ctor`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = CVOGHBSkill_OnDoHit | **Confirmed** | RTTI string |
| Role = ctor | **High** | vtbl install + new/subclass callers |
| ABI ret 0x18 / thiscall | **High** | terminal bytes |
| Pure vtbl subclass of SkillBase | **High** | no field stores |
| Product English “OnDoHit” design | **Open** | RTTI name only |
| Base arg English | **Tentative** | inherited from parent dual (not OWN re-prove) |

---

## 6. Gaps / open

1. Product design English for OnDoHit skill.  
2. Full vtbl method glossary beyond identity slots.  
3. Dual of callers `FUN_00621f50` / `FUN_006235e0` (not OWN).  
4. Runtime / bit-exact.

**Verdict:** **accept** — class Confirmed; ctor CF/ABI/vtbl High.
