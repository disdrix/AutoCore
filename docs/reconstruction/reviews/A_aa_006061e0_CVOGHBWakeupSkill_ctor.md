# Review A (reconstruction fidelity): `aa_006061e0` CVOGHBWakeupSkill_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006061e0` |
| **VA** | `0x006061e0`–`0x00606353` |
| **Canonical name** | `CVOGHBWakeupSkill_ctor` |
| **Ghidra name** | `FUN_006061e0` |
| **Review date** | `2026-07-29` (W19-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_006061e0_CVOGHBWakeupSkill_ctor.md` |
| **System** | `skills-abilities` / heartbeat |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry, epilogue, vtbl, DAT_009de7a0, RTTI string). No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Constructor** for delayed skill-apply heartbeat class **`CVOGHBWakeupSkill`** (size `0x674`). After `CVOGHBBase_ctor`, installs family vtbl, embeds skill runtime at `+0x24`, seeds world/flag/pos/seed and empty TFID vector, attaches owner, then materializes a TFID list terminated by invalid sentinel `DAT_009de7a0`. Fire path (`aa_00606180`, vtbl `+0x14`) later applies the embedded skill using these fields.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `0x006061e0` |
| Complete analysis | xrefs `0x0051ae04`, `0x00514f7d`; callees base ctor/attach/vector helpers |
| Bytes | `read_memory` 128 B @ entry; 128 B @ `0x006062e0` (epilogue / sentinel append) |
| Vtbl | `read_memory` `PTR_FUN_009de7b4` @ `0x009de7b4` |
| Invalid TFID | `read_memory` `DAT_009de7a0` @ `0x009de7a0` = `{-1,-1,0,0}` |
| RTTI string | `read_memory` @ `0x00af48f0` → `".?AVCVOGHBWakeupSkill@@"` |
| Sibling Fire dual | `A_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred` |
| Caller duals | ApplyStatusEffectLocal, ApplyLocalById |
| Raw / clean | `raw/aa_006061e0_*`, `reconstructed-exact/CVOGHBWakeupSkill_ctor.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `0x006061e0`–`0x00606353` | **Confirmed** | Ghidra function bounds |
| `__thiscall` ECX=this; `ret 0x20` (8 stack args) | **Confirmed** | epilogue `c2 20 00` |
| `CVOGHBBase_ctor` then vtbl `0x009de7b4` | **Confirmed** | decomp + `mov [ebp],0x009de7b4` |
| Skill copy `0x18c` dwords → `+0x24` | **Confirmed** | `mov ecx,0x18c` / `rep movsd`; `lea edi,[ebp+0x24]` |
| `+0x654` world, `+0x658` flag byte, `+0x66c` pos, `+0x670` seed | **Confirmed** | decomp stores; Fire dual consumers |
| `+0x0C/+0x10 = 1`, `+0x08 = param_2` | **Confirmed** | decomp |
| TFID vector begin/end/cap at `+0x660/+0x664/+0x668` | **Confirmed** | zero-init; capacity math `>> 4` |
| Container base `+0x65c` (fields at +4/+8/+0xC) | **High** | `lea esi,[ebp+0x65c]` in body; matches FUN_004cbfc0 layout |
| Walk until invalid TFID; always append `DAT_009de7a0` | **Confirmed** | decomp + push imm `0x009de7a0` |
| Grow path `FUN_004cbfc0` vs in-place `FUN_00608720` | **Confirmed** | both branches in decomp |
| Class RTTI CVOGHBWakeupSkill | **Confirmed** | type string + prior COL residual |
| Ctor role (not Fire / not dtor) | **Confirmed** | SEH ctor shape; returns this; callers `operator_new(0x674)` |
| `param_2` product English | **Inferred** | type/period seed only |
| `param_9` product English beyond skipBusy | **Inferred** | Fire uses `+0x658` as skipBusy |
| Decomp thiscall surface of FUN_004cbfc0 loses ECX | **High** noise | sealed via bytes: `mov ecx,esi` before grow call |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH + base ctor + vtbl install | **Yes** |
| Skill `rep movsd` 0x18c | **Yes** |
| Field seed + AttachOwner | **Yes** |
| TFID while + grow/in-place | **Yes** |
| Final invalid sentinel | **Yes** |
| Return this / ret 0x20 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Class RTTI string | **Yes** — `CVOGHBWakeupSkill` |
| Ctor role (new + field seed + vtbl) | **Yes** |
| Method string / PDB | **No** (ctor name synthetic) |
| Prior residual | sealed Confirmed in ApplyStatusEffectLocal dual |

**Decision:** promote **`CVOGHBWakeupSkill_ctor`** (class Confirmed + ctor role Confirmed; no `_Inferred` required on class-qualified ctor).

---

## 6. Gaps

1. Product English for `param_2` / full meaning of `param_9` beyond Fire skipBusy.
2. Named duals for `FUN_004cbfc0` / `FUN_00608720` (owned elsewhere).
3. Runtime / bit-exact / image diff.
4. Exact period semantics of writing `1` to `+0x0C`/`+0x10` before list Start (caller Start not in this body).

**Verdict:** **accept-with-gaps**
