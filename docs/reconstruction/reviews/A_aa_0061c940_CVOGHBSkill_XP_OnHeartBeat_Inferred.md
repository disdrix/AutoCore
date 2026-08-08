# Review A (reconstruction fidelity): `aa_0061c940` CVOGHBSkill_XP_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061c940` |
| **VA** | `0x0061c940`–`0x0061caf0` |
| **Body** | **433 bytes** (`0x1B1`) |
| **Canonical name** | `CVOGHBSkill_XP_OnHeartBeat_Inferred` |
| **Prior scaffold** | `FUN_0061c940` |
| **Review date** | `2026-08-05` (R12-004 dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkill_XP specialized OnHeartBeat |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` + `get_xrefs_to` + `read_memory`. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**OnHeartBeat path** for class **`CVOGHBSkill_XP`** (vtbl **+0x0C**):

| Step | Action | Role |
|---|---|---|
| 1 | `dynamic_cast<CVOGCharacter>(this[+0x18])` | source character |
| 2 | Branch on `character[+0xcb0]` null | personal vs multi-slot table |
| 3a | Personal: `float this[+0x104] != 0` → `new(0x6d0)` XPAdder target=self | single residual apply |
| 3b | Multi: loop `i=0..3` via `FUN_00574760` + MI adjust | up to 4 targets |
| 4 | `pOwner` set → `Enqueue(world+0xe4ec)` + `Start`; else `vtbl[0](1)` | accept / reject |
| 5 | `Skill_HB_RescheduleStatus_Inferred(this, pOut)` | thin OnHB tail |
| 6 | `return pOut` / `ret 4` | ABI |

Not the multi-target **arm** at vtbl+0x2C (`0061c590` ApplyToTargetList — sibling, not OWN). Not SharedOnHB `0061b6f0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0061c940` |
| Complete analysis | `analyze_function_complete` (xrefs/callees/callers/disasm/vars) |
| Bytes | `read_memory` entry + personal arm + convoy loop + epilogue |
| RTTI | COL `0x00aade00` → type_info `0x00af29ec` → **`.?AVCVOGHBSkill_XP@@`** |
| Vtbl | `0x009d119c`; this VA at **+0x0C** (`0x009d11a8`) |
| Child ctor | `CVOGHBSkill_XPAdder_ctor` `0x00650f50` (R11-025 dual; not re-owned) |
| Tail | `Skill_HB_RescheduleStatus_Inferred` `0x005787a0` (MEGA-004; not re-owned) |
| Parent context | `CVOGHBSkill_XP_ApplyToTargetList_Inferred` `0x0061c590` (R11-015; not re-owned) |
| Raw / annotated / clean | `aa_0061c940_*`, named + scaffold cpp |

**Not performed:** Launcher, runtime, parent ledgers, dual of sibling vtbl slots / `FUN_00574760`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0061c940`–`0061caf0`, 433 B | **Confirmed** | `get_function_by_address` + epilogue `ret 4` |
| thiscall + 1 stack arg / return param_2 | **Confirmed** | `C2 04 00` + `mov eax, edi` |
| Class = `CVOGHBSkill_XP` | **Confirmed** | RTTI string on host vtbl |
| Sole inbound = vtbl DATA +0x0C | **Confirmed** | callers empty; xref `009d11a8` |
| Alloc size `0x6d0` | **Confirmed** | `push 0x6D0` ×2 arms |
| Child = XPAdder ctor `00650f50` | **Confirmed** | rel32 + prior dual |
| Enqueue list = `world+0xe4ec` | **Confirmed** | `8B 88/8A EC E4 00 00` |
| Slot loop bound 4 | **Confirmed** | `cmp ebx,4` / `jl` |
| Slot this = `*(character+0xcb0)` | **Confirmed** | `mov ebp,[eax+0xcb0]` / `mov ecx,ebp` |
| Tail RescheduleStatus | **Confirmed** | `call 005787a0` |
| Method English OnHeartBeat | **Inferred** | role; no PDB |
| `+0xcb0` product noun | Medium | structural multi-slot host only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog `LAB_009a87bb` | Yes |
| RTDynamicCast source → Character | Yes |
| Personal vs multi branch on `+0xcb0` | Yes |
| Personal float gate `+0x104` | Yes |
| `new(0x6d0)` + XPAdder ctor both arms | Yes (clean documents thiscall) |
| Enqueue/Start vs dtor(1) | Yes |
| 4-slot loop + MI adjust | Yes |
| RescheduleStatus + ret 4 | Yes |
| XPAdder thiscall ECX | Yes in annotated/clean (bytes); decompiler free-fn shape |

---

## 5. Gaps / open

1. Product method name on `CVOGHBSkill_XP` vtbl+0x0C (PDB).
2. Product English for `character+0xcb0` (convoy/party/group table).
3. Product meaning of float residual `this+0x104`.
4. Full type of `FUN_00574760` host beyond 4-pointer getter.
5. Runtime / bit-exact / differential.

**Verdict:** **accept**
