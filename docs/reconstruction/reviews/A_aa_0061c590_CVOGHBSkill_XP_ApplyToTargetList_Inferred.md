# Review A (reconstruction fidelity): `aa_0061c590` CVOGHBSkill_XP_ApplyToTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061c590` |
| **VA** | `0x0061c590`–`0x0061c6af` |
| **Body** | **288 bytes** (`0x120`) |
| **Canonical name** | `CVOGHBSkill_XP_ApplyToTargetList_Inferred` |
| **Prior scaffold** | `FUN_0061c590` |
| **Review date** | `2026-08-05` (R11-015 dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkill_XP multi-target arm |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_xrefs` + `get_function_callers` + `get_xrefs_to` + `read_memory`. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Apply / arm path** for class **`CVOGHBSkill_XP`**:

| Step | Action | Role |
|---|---|---|
| 1 | Walk `param_4` as **0x10-byte** TFID rows | multi-target list |
| 2 | Sentinel `{-1,-1, mode0}` → **return 1** | terminator |
| 3 | `ResolveObjectTarget(*(world+0xe4e8), mode, lo, hi)` | live object* |
| 4 | `operator_new(0x6c0)` + `CVOGHBSkillBase_ctor` | base skill HB |
| 5 | Install vtbl **`PTR_FUN_009d119c`** | XP subclass |
| 6 | `HB[+0x08] = skillBlob[+0x1c]`; `SetPeriodAndCounter(-1000,true)` | pulse + always-ready |
| 7 | Owner set → `Enqueue(world+0xe4ec)` + `Start`; else `vtbl[0](1)` | accept / reject |

Not a leaf OnHeartBeat (that is sibling slot +0x0C @ `0x0061c940`, not OWN).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0061c590` |
| Bytes | `read_memory` entry + epilogue + mid-body resolve/ctor/vtbl |
| RTTI | COL `0x00aade00` → type_info `0x00af29ec` → **`.?AVCVOGHBSkill_XP@@`** |
| Vtbl | `0x009d119c`; this VA at **+0x2C** (`0x009d11c8`) |
| Parent | `CVOGHBSkillBase_ctor` `0x005788d0` (dual sealed; not re-owned) |
| Resolve | `CVOGReaction_ResolveObjectTarget` `0x004bae70` (dual sealed) |
| Raw / annotated / clean | `aa_0061c590_*`, named + scaffold cpp |

**Not performed:** Launcher, runtime, parent ledgers, dual of sibling vtbl slots.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0061c590`–`0061c6af`, 288 B | **Confirmed** | epilogue `ret 0x18` |
| Six stack formals / return 1 | **Confirmed** | `C2 18 00` + `mov eax,1` |
| Class = `CVOGHBSkill_XP` | **Confirmed** | RTTI string |
| Vtbl imm `009d119c` | **Confirmed** | `C7 06 9C 11 9D 00` |
| Base ctor `005788d0` | **Confirmed** | rel32 + Ghidra name |
| Resolve this = `world+0xe4e8` | **Confirmed** | `8B 8B E8 E4 00 00` |
| Enqueue list = `world+0xe4ec` | **Confirmed** | `8B 8B EC E4 00 00` |
| Alloc size `0x6c0` | **Confirmed** | `push 0x6C0` |
| Period `-1000,true` | **Confirmed** | push imm + SetPeriod dual |
| Method English ApplyToTargetList | **Inferred** | role; no PDB |
| Sole inbound = vtbl DATA | **Confirmed** | no CALL callers |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog | Yes |
| Row loop / sentinel return 1 | Yes |
| Resolve + new + base ctor + vtbl | Yes |
| Pulse +0x08 + SetPeriod(-1000,true) | Yes |
| Enqueue/Start vs dtor(1) | Yes |
| `ret 0x18` | Yes (documented) |
| Resolve thiscall ctx | Yes in annotated/clean (bytes); decompiler omits |

---

## 5. Gaps / open

1. Product method name on `CVOGHBSkill_XP` (PDB).
2. Producer / max length of the 0x10-byte row table.
3. Whether dispatchers pass unused ECX `this` into this slot.
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
