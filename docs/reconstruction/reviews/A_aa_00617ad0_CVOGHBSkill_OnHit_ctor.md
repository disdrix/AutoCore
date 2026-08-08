# Review A (reconstruction fidelity): `aa_00617ad0` CVOGHBSkill_OnHit_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617ad0` |
| **VA** | `0x00617ad0`–`0x00617b33` |
| **Canonical name (Ghidra)** | `FUN_00617ad0` |
| **Proposed name** | `CVOGHBSkill_OnHit_ctor` |
| **Review date** | `2026-08-05` (R11-012 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00617ad0_CVOGHBSkill_OnHit_ctor.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Constructor** for `CVOGHBSkill_OnHit`: call sealed `CVOGHBSkillBase_ctor`, install OnHit vtbl, seed optional int at `this+0x6c0` from skill-blob float `+0x4c` with enable byte at `+0x6c4`. Intermediate base for hit-family HB skill factories (`operator_new(0x6d0)` then subclass vtbl overwrite).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` @ `0x00617ad0` |
| Assembly | `disassemble_function` (not `disassemble_bytes`) — full body listed |
| Bytes | `read_memory` entry + tail `RET 0x18` + `CC` pad |
| RTTI | `read_memory` COL `0x00aadbc4` → type_info `0x00af1d60` → `.?AVCVOGHBSkill_OnHit@@` |
| Vtbl | `PTR_FUN_009d0f1c`; COL dword at `0x009d0f18` |
| g_flZero | `0x00a0f518` = `00 00 00 00` |
| Callee | `CVOGHBSkillBase_ctor` `0x005788d0` (parent dual sealed) |
| Callers | `FUN_00617fc0`, `FUN_0061c430`, `FUN_00623330`, `FUN_00624d40` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00617ad0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, other VAs dual, `disassemble_bytes`.

---

## 3. Signature

```c
CVOGHBSkill_OnHit* __thiscall CVOGHBSkill_OnHit_ctor(
    CVOGHBSkill_OnHit *this,   // ECX
    void *pSourceObj,          // → base TFID seed
    void *pSkillBlob,          // skill runtime; float @ +0x4c
    uint32_t arg4,
    void *pTarget,             // ValidateTarget + AttachOwner (base)
    uint32_t *pTfid,
    uint32_t arg7);
// ret 0x18; EAX = this
```

| Item | Evidence |
|---|---|
| Convention | `MOV ESI,ECX`; terminal `RET 0x18` (both paths) |
| Vtbl | `MOV [ESI], 0x009d0f1c` after base CALL |
| Float gate | `MOVSS`/`UCOMISS`/`LAHF`/`TEST AH,0x44`/`JNP` |
| Truncate | `CVTTSS2SI` → `this+0x6c0` |
| Enable | `this+0x6c4` byte 1 / 0 |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base ctor then vtbl store | **Yes** |
| Float ≠ 0 → flag1 + truncate store | **Yes** |
| Float == 0 → flag0 only | **Yes** |
| Return this both paths | **Yes** |
| RET 0x18 both paths | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = `CVOGHBSkill_OnHit` | **Confirmed** | RTTI string |
| Role = ctor | **Confirmed** | vtbl install + base ctor + factories |
| Vtbl `PTR_FUN_009d0f1c` | **Confirmed** | store + COL chain |
| ABI thiscall + RET 0x18 | **Confirmed** | asm both exits |
| `+0x6c0` / `+0x6c4` offsets | **Confirmed** | asm absolute |
| `skillBlob+0x4c` float source | **Confirmed** | EDI = param_3 |
| Product English for `+0x6c0` field | **Open** | no string in unit |
| Size `0x6d0` | **High** | multi-caller `operator_new` |
| Subclass vtbl identity | **Out of unit** | callers only |

---

## 6. Gaps / open

1. Product design English for skill-blob float `+0x4c` / HB int `+0x6c0` (not inventing period/damage labels).
2. Uninitialized `+0x6c0` when flag=0 (asm does not write).
3. Dual of four callers / subclass vtbls (not OWN).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — class Confirmed; ctor CF/ABI/vtbl/offsets sealed; field English open.
