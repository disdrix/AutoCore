# Review A (reconstruction fidelity): `aa_00650f50` CVOGHBSkill_XPAdder_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650f50` |
| **VA** | `0x00650f50`–`0x00650f8e` |
| **Body** | **63 bytes** (`0x3F`) |
| **Canonical name** | `CVOGHBSkill_XPAdder_ctor` |
| **Prior scaffold** | `FUN_00650f50` |
| **Review date** | `2026-08-05` (R11-025 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00650f50_CVOGHBSkill_XPAdder_ctor.md` |
| **System** | `skills-abilities` / CVOGHB skill heartbeat |
| **Dual status** | **Present (R11 residual dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body, vtbl-4 COL, type_info string) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Subclass **constructor** for `CVOGHBSkill_XPAdder` (skill HB that applies an XP residual):

| Step | Action | Role |
|---|---|---|
| 1 | `CVOGHBSkillBase_ctor(...)` | base skill HB init (validate/attach/period) |
| 2 | `*this = PTR_FUN_009e5304` | install subclass vtbl |
| 3 | `*(float*)(this+0x6c0) = 0.0f` | clear XP residual (MOVSS) |

Not the tick/end virtuals (those live on the vtbl at `+0x04` / `+0x14`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00650f50` |
| Complete analysis | xrefs `0x0061c9f3`, `0x0061ca93`; callee `CVOGHBSkillBase_ctor` |
| Assembly | `disassemble_function` — body through `ret 0x18` |
| Bytes | `read_memory` 64 B @ `0x00650f50` |
| Vtbl / RTTI | `read_memory` @ `0x009e5300` COL → `0x00ab1f30` → type_info `0x00af5178` → `".?AVCVOGHBSkill_XPAdder@@"` |
| Caller | sole `FUN_0061c940` (`operator_new(0x6d0)`) |
| Base dual | `A|B_aa_005788d0_CVOGHBSkillBase_ctor` |
| Raw / clean | `aa_00650f50_*`, `CVOGHBSkill_XPAdder_ctor.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of peers `00650f90` / `006510b0` / caller `0061c940`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00650f50`–`0x00650f8e` (63 B) | **Confirmed** | disasm + bytes |
| `__thiscall` ECX=this; `ret 0x18` (six stack dwords) | **Confirmed** | `mov esi,ecx`; `C2 18 00` |
| Base = `CVOGHBSkillBase_ctor` @ `0x005788d0` | **Confirmed** | rel32 + named callee |
| Vtbl imm `0x009e5304` | **Confirmed** | `C7 06 04 53 9E 00` |
| Float zero @ `+0x6c0` via MOVSS | **Confirmed** | `F3 0F 11 86 C0 06 00 00` after `XORPS` |
| Return this in EAX | **Confirmed** | `mov eax,esi` |
| Object size `0x6d0` | **Confirmed** | sole caller `operator_new` |
| Class product name `CVOGHBSkill_XPAdder` | **Confirmed** | RTTI type string |
| Ctor role (not tick / not dtor) | **Confirmed** | CF; dtor is vtbl+0 @ `00651190` |
| Stack formal English (source/blob/target/…) | **High** | pass-through to sealed base plate |
| Float `+0x6c0` product English “XP residual” | **High** | peer tick/end R/W character `+0xc54` (not OWN dual) |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Push 6 stack args + `mov ecx,this` | **Yes** |
| `call CVOGHBSkillBase_ctor` | **Yes** |
| install vtbl `0x009e5304` | **Yes** |
| MOVSS zero @ `+0x6c0` | **Yes** |
| return this / `ret 0x18` | **Yes** |

Raw scaffold body preserved; R11 re-verify **appended** only.

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Class RTTI string | **Yes** — `CVOGHBSkill_XPAdder` |
| Ctor role (base + vtbl + return this) | **Yes** |
| `_Inferred` required? | **No** — RTTI bar met |

**Accepted name:** `CVOGHBSkill_XPAdder_ctor`

---

## 6. Gaps / open

1. Peer dual of tick `0x00650f90` / end `0x006510b0` (float consumers).
2. Sole-caller dual `FUN_0061c940` (spawn/enqueue path).
3. Product glossary for float `+0x6c0` beyond residual XP delta.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
