# Review A (reconstruction fidelity): `aa_00606180` CVOGHBWakeupSkill_Fire_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606180` |
| **VA** | `0x00606180`–`0x006061de` |
| **Canonical name** | `CVOGHBWakeupSkill_Fire_Inferred` |
| **Ghidra name** | `FUN_00606180` |
| **Review date** | `2026-07-29` (W18-I OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` |
| **System** | `skills-abilities` / heartbeat |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` body + vtbl + ctor. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Delayed-skill heartbeat **fire/complete** virtual for class **`CVOGHBWakeupSkill`**. When the list remove path runs `CVOGHBBase_EndOrDestroy(flag_onEnd=1)`, slot **`vtbl+0x14`** applies the skill that was embedded at HB construction (from `Skill_ApplyStatusEffectLocal` delay≥1 path). Local-cast gate + optional active-cast counter dec precede apply.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `0x00606180` |
| Bytes | `read_memory` 96 B @ entry |
| Vtbl | `read_memory` `PTR_FUN_009de7b4` @ `0x009de7b4` — slot +0x14 = this VA |
| Class RTTI | string `".?AVCVOGHBWakeupSkill@@"` @ `0x00af48f0` |
| Ctor | live decompile `0x006061e0` (field seed) |
| Sibling duals | ApplyEffects, LocalCastValidate, FUN_00514e00, EndOrDestroy, List_Tick, HB Start/Stop/TryFire |
| Raw / clean | `raw/aa_00606180_*`, `reconstructed-exact/CVOGHBWakeupSkill_Fire_Inferred.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `0x00606180`–`0x006061de` | **Confirmed** | Ghidra |
| `__thiscall` ECX=HB; no stack args | **High** | `mov esi,ecx`; plain ret path |
| Gate `*(this+0x18)!=0` | **Confirmed** | bytes + decomp |
| `+0x658==0` → `FUN_00514e00` with **ECX=owner** | **Confirmed** | ECX preserved from owner load; closes FUN_00514e00 residual ECX gap for this site |
| LocalCastValidate(owner, skipBusy=`+0x658`, skill=**NULL**, 0) | **Confirmed** | `push 0; push 0; push al` |
| ApplyEffects this = **`this+0x24`** (embedded skill) | **Confirmed** | `lea ecx,[esi+0x24]`; ctor copies skill blob to +0x24 |
| ApplyEffects args world/tfid/pos/seed @ `+0x654/+0x660/+0x66c/+0x670` | **Confirmed** | body + ctor stores |
| Tail empty `FUN_005081f0` | **Confirmed** | `jmp` target; decompile is bare `return` |
| Class RTTI CVOGHBWakeupSkill | **Confirmed** | type string + ctor vtbl install |
| Vtbl install at **+0x14** only | **Confirmed** | DATA xref sole |
| OnHeartBeat for this class still RescheduleAfterFire (+0x0C) | **High** | vtbl layout vs TryFire sealed comment |
| EndOrDestroy(+0x18) calls +0x14 when onEnd≠0 | **High** | sibling dual `aa_005083f0` |
| Product method English (Fire vs OnComplete) | **Inferred** | `_Inferred` required |
| `CONCAT31`/`in_EAX` flag mash | **Falsified** | reload `+0x658` |
| 2026-07-23 raw 5-arg ApplyEffects without skill this | **Superseded** | live + bytes |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Owner null → epilogue | **Yes** |
| Optional counter dec | **Yes** |
| LocalCastValidate then conditional ApplyEffects | **Yes** |
| Always empty tail | **Yes** |
| No invent net / period math in body | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Class RTTI | **Yes** — `CVOGHBWakeupSkill` |
| Method string / PDB | **No** |
| Sole virtual slot role | **Yes** — fire/apply on complete-remove |
| Prior residual call-site name | active-skill HB fire (ApplyEffects dual) |

**Decision:** promote **`CVOGHBWakeupSkill_Fire_Inferred`** (class Confirmed + role High; method English open → `_Inferred`).

---

## 6. Gaps

1. Product C++ method name on the class.
2. Full period/counter setup from ApplyStatusEffectLocal → ctor (sibling).
3. Runtime / bit-exact / image diff.
4. Whether Stop(+0x10) ever skips fire by setting cStopped before Remove.

**Verdict:** **accept-with-gaps**
