# Review A (reconstruction fidelity): `aa_00617df0` CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617df0` |
| **VA** | `0x00617df0`–`0x00617f2c` inclusive |
| **Body** | **317 bytes** (`0x13D`) |
| **Canonical name (Ghidra)** | `FUN_00617df0` |
| **Proposed name** | `CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred` |
| **Review date** | `2026-08-05` (R11-013 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00617df0_CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs + COL/type_info. **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

Virtual **multi-target OnHit HB spawn** method (vtbl **+0x2c** on `CVOGHBSkill_OnHit`):

1. Walk `param_4` target list (stride **0x10**) until terminator `{-1,-1,type0}`.
2. Resolve each entry via `CVOGReaction_ResolveObjectTarget` (`this = *(world+0xe4e8)`).
3. `operator_new(0x6d0)` + `CVOGHBSkillBase_ctor` + install `PTR_FUN_009d0f1c`.
4. Optional period from skill float `+0x4c` → action `+0x6c0`/`+0x6c4`.
5. If `pOwner(+0x18) != 0`: `CVOGHBList_Enqueue(*(world+0xe4ec))` + `CVOGHBBase_Start`; else scalar-deleting dtor.

**Not** the subclass ctor (`FUN_00617ad0`); **not** SpawnEntities execute (`0x00615020` / different vtbl).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00617df0` |
| Assembly | `disassemble_function` full body through `RET 0x18` |
| Bytes | `read_memory` entry 256 B; terminal `C2 18 00 CC` @ `0x00617f2a` |
| Meta | `get_function_by_address` body `00617df0`–`00617f2c` |
| RTTI | COL `0x00aadbc4` → type_info `0x00af1d60` → **`.?AVCVOGHBSkill_OnHit@@`** |
| Vtbl | `read_memory` `0x009d0f1c`; slot +0x2c = `0x00617df0`; +0 = `0x00651190` |
| Xrefs | sole DATA `0x009d0f48`; no CODE callers |
| Base dual | `CVOGHBSkillBase_ctor` / `aa_005788d0` |
| Sibling ctor | `FUN_00617ad0` (same vtbl + period pattern; not OWN) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00617df0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
// virtual slot +0x2c; ECX this unused; ret 0x18; EAX = 1
uint32_t CVOGHBSkill_OnHit_SpawnActionsForTargetList_Inferred(
    void *pSourceObj,
    void *pSkillBlob,     // float +0x4c
    void *pWorld,         // +0xe4e8 / +0xe4ec
    TargetEntry16 *pList, // stride 0x10
    void *pTfid16,
    uint32_t arg7);
```

| Item | Evidence |
|---|---|
| Terminal | `C2 18 00` @ `0x00617f2a` |
| Vtbl imm | `C7 06 1C 0F 9D 00` after base ctor |
| Period stores | `MOV [ESI+0x6c4], imm8`; `MOV [ESI+0x6c0], ECX` after `CVTTSS2SI` |
| new size | `PUSH 0x6d0` → `operator_new` |
| Base ctor | `CALL 0x005788d0` with ECX=new |
| Enqueue list | `MOV ECX,[EBX+0xe4ec]` EBX=param_3 |
| Resolve this | `MOV ECX,[EBX+0xe4e8]` before `CALL 0x004bae70` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog / index=0 | Yes |
| Terminator triple check → return 1 | Yes |
| ResolveObjectTarget thiscall | Yes (assembly; decompile omits ECX) |
| new + base ctor + vtbl | Yes |
| Period zero vs non-zero branch | Yes |
| Owner gate → Enqueue/Start vs dtor(1) | Yes |
| index++ both arms; infinite loop | Yes |
| RET 0x18 | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = `CVOGHBSkill_OnHit` | **Confirmed** | RTTI string |
| Role = multi-target spawn OnHit HBs | **High** | CF + vtbl self-install |
| Object size `0x6d0` | **Confirmed** | `PUSH 0x6d0` |
| Period @ `+0x6c0`/`+0x6c4` from skill `+0x4c` | **Confirmed** | bytes |
| HB list @ world `+0xe4ec` | **Confirmed** | matches family |
| Method product English | **Open** | `_Inferred` |
| Virtual this unused intentionally | **High** (static) | no ECX consumer |
| Param English source/skill/world | **High** via base ctor map | arg7 Tentative |

---

## 6. Gaps / open

1. Product method name for slot +0x2c.  
2. Virtual call sites / list producers (not CODE xrefs).  
3. Dual of sibling ctor `FUN_00617ad0` (R11-012 OWN, not this unit).  
4. Null-`operator_new` crash path (static UB).  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — class Confirmed; CF/ABI/vtbl/period High; method English open.
