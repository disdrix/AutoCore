# Review A (reconstruction fidelity): `aa_00614dc0` Skill_HB_SpawnEntities_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00614dc0` |
| **VA** | `0x00614dc0`–`0x00614e36` |
| **Body** | **119 bytes** |
| **Canonical name** | `Skill_HB_SpawnEntities_ctor_Inferred` |
| **Prior scaffold** | `FUN_00614dc0` |
| **Review date** | `2026-07-29` (W25-N dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| **System** | skill / CVOGHB multi-entity spawn action ctor |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Subclass **constructor** for the multi-entity spawn skill HB:

| Step | Action | Role |
|---|---|---|
| 1 | `CVOGHBSkillBase_ctor(...)` | base skill HB init |
| 2 | `*this = PTR_FUN_009d0ec4` | install subclass vtbl |
| 3 | skill `vfunc+0x27c` → `*(uint16*)(this+0x6c4)` | cache skill-side value |

Not the execute/precheck virtuals themselves (those live on the vtbl).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00614dc0` (+ base `0x005788d0`) |
| Bytes | `read_memory` 120 B — SEH, rel32 base, vtbl imm, call `[edx+0x27c]`, store `ax` @ `+0x6c4`, `ret 0x18` |
| Bounds | body `00614dc0`–`00614e36` |
| Caller | sole `0x00615b97` in execute (`new 0x6d0`) |
| Peer duals | Precheck `006170b0`, Execute `00615020` |
| Raw / clean | `aa_00614dc0_*`, `Skill_HB_SpawnEntities_ctor_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of base ctor internals.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = this (`mov esi,ecx`) | **Confirmed** | bytes |
| `ret 0x18` (six stack dwords) | **Confirmed** | `C2 18 00` |
| Base = `CVOGHBSkillBase_ctor` @ `005788d0` | **Confirmed** | rel32 |
| Vtbl imm `009d0ec4` | **Confirmed** | `C7 06 C4 0E 9D 00` |
| Store ushort @ `+0x6c4` | **Confirmed** | `66 89 86 C4 06 00 00` |
| Return this in EAX | **Confirmed** | `mov eax,esi` |
| Object size `0x6d0` | **Confirmed** | sole caller `operator_new` |
| Product subclass English | **Inferred** | role via execute/precheck peers |
| Meaning of vfunc `+0x27c` | **Open** | value only cached |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog | Yes |
| call base ctor | Yes |
| install vtbl | Yes |
| skill vfunc + store | Yes |
| return this / ret 0x18 | Yes (documented) |

---

## 5. Gaps / open

1. Product RTTI name for `PTR_FUN_009d0ec4` class.
2. Semantic of skill `+0x27c` ushort.
3. Named stack formals beyond base plate (source/target chain).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
