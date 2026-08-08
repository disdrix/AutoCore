# Review A (reconstruction fidelity): `aa_006202f0` CVOGHBSkill_SummonSnoop_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006202f0` |
| **VA** | `0x006202f0`–`0x00620323` |
| **Body** | **52 bytes** (`0x34`) |
| **Canonical name** | `CVOGHBSkill_SummonSnoop_Ctor` |
| **Prior scaffold** | `FUN_006202f0` / `Named_CalleeOf_Skill_Skill_d_had_invalid_template_d_006202f0` |
| **Review date** | `2026-08-05` (R11-016 dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Subclass **constructor** for `CVOGHBSkill_SummonSnoop`:

| Step | Action | Role |
|---|---|---|
| 1 | `CVOGHBSkillBase_ctor(...)` | base skill HB init (blob, ValidateTarget, AttachOwner, period) |
| 2 | `*this = PTR_FUN_009d156c` | install SummonSnoop subclass vtbl |

No extra field caches (contrast SpawnEntities ushort @+0x6c4 / Virus budget+period).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x006202f0` |
| Bytes | `read_memory` 64 B — push formals, rel32 base, vtbl imm, `ret 0x18` |
| Bounds | `get_function_by_address` body `006202f0`–`00620323` |
| RTTI | COL `0x00aae154` → type_info `0x00afed18` → `.?AVCVOGHBSkill_SummonSnoop@@` |
| Vtbl | `read_memory` `0x009d156c` |
| Caller | sole `0x006208f4` in `Skill_SpawnTemplateAndStartHB` (`new 0x6c0`) |
| Base plate | `aa_005788d0` `CVOGHBSkillBase_ctor` (parent context; not dualled here) |
| Raw / clean | `aa_006202f0_*`, `CVOGHBSkill_SummonSnoop_Ctor.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of base ctor / OnHB peers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = this (`mov esi,ecx`) | **Confirmed** | entry bytes |
| `ret 0x18` (six stack dwords) | **Confirmed** | `C2 18 00` |
| Base = `CVOGHBSkillBase_ctor` @ `005788d0` | **Confirmed** | rel32 `E8 B8 85 F5 FF` |
| Vtbl imm `009d156c` | **Confirmed** | `C7 06 6C 15 9D 00` |
| Return this in EAX | **Confirmed** | `mov eax,esi` |
| Object size `0x6c0` | **Confirmed** | sole caller `operator_new` |
| Class name SummonSnoop | **Confirmed** | RTTI string |
| Product design English | **Open** | beyond demangle |
| Peer OnHB semantics | **Open** | `FUN_00620340` not OWN |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| push 6 formals / `mov esi,ecx` | Yes |
| call base ctor | Yes |
| install vtbl | Yes |
| return this / ret 0x18 | Yes |
| no branches / no extra stores | Yes |

---

## 5. Gaps / open

1. Product English for SummonSnoop skill beyond RTTI demangle.
2. Dual of OnHB `0x00620340` / dtor `0x00651190` (siblings, not OWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
