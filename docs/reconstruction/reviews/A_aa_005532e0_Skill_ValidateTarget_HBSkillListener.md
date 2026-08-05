# Review A (reconstruction fidelity): `aa_005532e0` Skill_ValidateTarget_HBSkillListener

| Field | Value |
|---|---|
| **Stable ID** | `aa_005532e0` |
| **VA** | `0x005532e0` |
| **Canonical name** | `Skill_ValidateTarget_HBSkillListener` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean / annotated to asm + raw + RTTI) |
| **Counterpart** | `reviews/B_aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** — type tag + RTTI path + predicate ABI sealed; residual is handler catalog / vtbl+0x18 English |

---

## 1. Purpose

`CNDDoubleList_InvokePredicateAndRemove_Inferred` predicate for `Skill_ValidateTargetForSkill`. Selects skill-base HB nodes via type tag `+0x1c == 1` and RTTI `CVOGHBBase` → `CVOGHBSkillBase`, then re-probes skill handler `+0x5F0` / vtbl `+0x44` with the HB as third arg. Codes **1=reject** / **2=accept** update ValidateTarget context; accept + notify may call HB `vtbl+0x18(1,0)` and remove the list node.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |
| Annotated | `docs/reconstruction/raw/aa_005532e0_Skill_ValidateTarget_HBSkillListener.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ValidateTarget_HBSkillListener.cpp` |
| Function record | `docs/reconstruction/functions/aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |
| Three-rep | decompile + force_decompile (identical) + `read_memory` body / RTTI / string + high P-code |
| Parent dual | `reviews/A|B_aa_00553650_Skill_ValidateTargetForSkill.md` |
| List util dual | `reviews/A|B_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.md` |
| Ctor dual | `reviews/A|B_aa_005788d0_CVOGHBSkillBase_ctor.md` |

**Live Ghidra performed this pass** — not scaffold-only.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__stdcall` 3 args, `ret 0x0C` | **Confirmed** | body ends `c2 0c 00` (×3 exit paths) |
| Formals `(hbPayload, ctx, stopFlag*)` | **Confirmed** | list util call `pred(node[1], ctx, &local_stop)` |
| Type tag `hb+0x1c == 1` required | **Confirmed** | entry `cmp [eax+0x1c],1` |
| Tag written by `CVOGHBSkillBase_ctor` | **Confirmed** | ctor dual `self[7]=1` |
| RTTI src `CVOGHBBase` @ `0x00af8d98` | **Confirmed** | `read_memory` `".?AVCVOGHBBase@@"` |
| RTTI dst `CVOGHBSkillBase` @ `0x00af8cec` | **Confirmed** | `read_memory` `".?AVCVOGHBSkillBase@@"`; matches ctor COL path |
| Cast is `CVOGHBBase` → `CVOGHBSkillBase` | **Confirmed** | push order + decompile names |
| Gate `hb+0x20 == 0` | **Confirmed** | `cmp byte [edi+0x20],0` |
| Field `+0x20` = base `cStopped` | **High** | ctor layout dual; English not product-string sealed |
| Handler `skill+0x5F0`, vtbl `+0x44(target,skill,hb)` | **Confirmed** | asm ECX=handler; three stack args |
| Code 1 → `result=0`, `*stop=1`, return 0 | **Confirmed** | |
| Code 2 → `result=1`, `*stop=1`; notify → vtbl+0x18 + return 1 | **Confirmed** | |
| Null handler → log string + skillId@`+0x620` | **Confirmed** | string @ `0x009d254c` |
| Sole consumer ValidateTarget | **Confirmed** | single DATA xref `0x00553684` |
| Return AL = remove-node for list util | **Confirmed** | list util `while (cVar4 == 0)` / unlink on nonzero |
| No null-check after cast | **Confirmed** | asm falls through to `[edi+0x20]` |

---

## 4. Control flow: clean ≡ asm

| Stage | Match |
|---|---|
| Type tag gate | **Yes** |
| RTTI cast constants | **Yes** |
| `+0x20` skip | **Yes** |
| Handler null log | **Yes** |
| vcall + codes 1/2 | **Yes** |
| notify + remove only on 2 + flag | **Yes** |
| Default AL=0 | **Yes** |
| No invented range / outFlags | **Yes** |

---

## 5. Type tag + RTTI path (seal block)

```
CVOGHBSkillBase_ctor:
  this[+0x1c] = 1
  vtbl → COL 0x00aaede0 → type_info 0x00af8cec ".?AVCVOGHBSkillBase@@"
  (base is CVOGHBBase; type_info 0x00af8d98)

Skill_ValidateTarget_HBSkillListener:
  require this[+0x1c] == 1
  __RTDynamicCast(obj, 0, &CVOGHBBase@af8d98, &CVOGHBSkillBase@af8cec, 0)
  require this[+0x20] == 0
  → skill-HB legality re-probe
```

**Sealed:** type tag value, offset, writer, RTTI endpoints, cast direction.

---

## 6. Gaps / open (acceptable for accept)

1. Product type name of `skill+0x5F0` handler class.
2. Full catalog of vtbl+0x44 implementations.
3. Exact product name / semantics of HB `vtbl+0x18`.
4. Whether `+0x20` English is exactly `cStopped` vs “disabled/busy”.
5. Cast-null under corrupted memory (no check — binary undefined).

**Verdict:** **accept** — predicate ABI, type tag, RTTI path, handler codes, stop/remove polarity sealed statically.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches asm | **Pass** |
| Three-rep agreement | **Pass** (decomp≡force; bytes seal RTTI/ABI) |
| Type tag sealed with ctor | **Pass** |
| RTTI path sealed via `read_memory` | **Pass** |
| Sole caller named | **Pass** |
| List util remove polarity | **Pass** |
| Handler identity sealed | **Open** (documented; parent residual) |
| Verdict | **accept** |
