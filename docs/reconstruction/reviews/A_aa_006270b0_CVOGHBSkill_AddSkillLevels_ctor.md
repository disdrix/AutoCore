# Review A (reconstruction fidelity): `aa_006270b0` CVOGHBSkill_AddSkillLevels_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006270b0` |
| **VA** | `0x006270b0`–`0x00627160` |
| **Body** | **177 bytes** (`0xB1`) |
| **Canonical name (Ghidra)** | `FUN_006270b0` |
| **Proposed name** | `CVOGHBSkill_AddSkillLevels_ctor` |
| **Review date** | `2026-08-05` (R11-022 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_xrefs` / callers + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Constructor** for `CVOGHBSkill_AddSkillLevels` (RTTI Confirmed):

| Step | Action | Role |
|---|---|---|
| 1 | `CVOGHBSkillBase_ctor(...)` | base skill HB init (validate/attach/period) |
| 2 | `*this = PTR_FUN_009d1c54` | install subclass vtbl |
| 3 | empty RB map @ `+0x6c4` / size 0 @ `+0x6c8` | `FUN_00439770` + self-links + `+0x15=1` |
| 4 | `pTarget->vtbl+0x210(0)` | if 0 → `AttachOwnerObject(this, null)` |

Not Enqueue/Start (sole caller owns those).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x006270b0` |
| Bytes | `read_memory` 200 B @ entry — SEH, rel32 base/alloc/attach, vtbl imm, `ret 0x18`, pad `CC` |
| Meta | `analyze_function_complete` — callees, sole caller, locals |
| Xrefs | `get_function_xrefs` — 1 UNCONDITIONAL_CALL from `006277ec` |
| RTTI | COL `0x00aae638` (`*(0x009d1c50)`) → type_info `0x00af22b4` → `.?AVCVOGHBSkill_AddSkillLevels@@` |
| Vtbl | `read_memory` `0x009d1c54` (slot table; includes `0x00627750` among peers) |
| Caller CF | raw `aa_00627750` — `operator_new(0x6d0)` + this ctor + owner gate |
| Raw / annotated / clean | `aa_006270b0_*`, `CVOGHBSkill_AddSkillLevels_ctor.cpp` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, dual of base/caller internals.

---

## 3. Signature

```c
CVOGHBSkill_AddSkillLevels* __thiscall CVOGHBSkill_AddSkillLevels_ctor(
    CVOGHBSkill_AddSkillLevels *this,
    void *pSource, void *pSkillBlob, void *arg4,
    void *pTarget, void *pTfid, void *arg7);
// ret 0x18; EAX = this
```

| Item | Evidence |
|---|---|
| Convention | `mov edi, ecx`; terminal `C2 18 00` |
| Vtbl | `C7 07 54 1C 9D 00` → `0x009d1c54` |
| Base | rel32 from `0x006270F4` → `0x005788d0` |
| Alloc node | rel32 → `0x00439770` |
| Attach | rel32 → `0x005083b0` |
| Map fields | `[this+0x6c4]` head; `[this+0x6c8]=0` |
| Object size | sole caller `operator_new(0x6d0)` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog | Yes |
| call `CVOGHBSkillBase_ctor` | Yes |
| install subclass vtbl | Yes |
| empty map init (`+0x6c4`/`+0x6c8`) | Yes |
| vfunc `+0x210` gate + optional detach | Yes |
| return this / `ret 0x18` | Yes |
| Decompiler `ExceptionList = param_1` | **Asm corrects** — restore prior FS:[0], `mov eax,edi` |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = `CVOGHBSkill_AddSkillLevels` | **Confirmed** | RTTI string |
| Role = subclass ctor | **High** | vtbl + new(0x6d0) caller |
| Empty map @ `+0x6c4` / size `+0x6c8` | **High** | bytes ≡ `FUN_004e7450` pattern |
| `ret 0x18` / 6 stack args | **Confirmed** | epilogue |
| Gate clears owner on vfunc fail | **High** | attach(null) path |
| Map key/value product type | **Open** | empty only here |
| `vtbl+0x210` English | **Open** | shared object virtual |
| Base formal English | **Tentative** | owned by parent dual |

---

## 6. Gaps / open

1. Map value/key type for AddSkillLevels table (not populated in ctor).  
2. Product design English beyond RTTI demangle.  
3. Dual of sole caller `FUN_00627750` (not OWN).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — class Confirmed; ctor CF/ABI/vtbl/map-init High; map payload + vfunc English open.
