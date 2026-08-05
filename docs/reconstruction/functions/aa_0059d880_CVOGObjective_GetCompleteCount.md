# Function record: CVOGObjective_GetCompleteCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d880` |
| **Canonical name** | `CVOGObjective_GetCompleteCount` |
| **Prior** | `FUN_0059d880`; auto-alias `Named_CalleeOf_CVOGReaction_CompleteObjective_0059d880` |
| **Address** | `0x0059d880` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Human-refined getter** — three-rep + dual A/B sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Return objective template field **CompleteCount** at **`this+0x164`** (`uint32`). Pure load; no side effects.

Product name sealed by objective XML serializer `FUN_005468c0` → `fprintf(..., "<CompleteCount>%i</CompleteCount>", GetCompleteCount())`.

Production roles:

* Min required requirement-pass count in `CVOGReaction_CompleteObjective`
* Collect threshold in `CVOGCharacter_EvaluatePendingObjectives`

Sibling writer: `FUN_0059d890` @ `0x0059d890` (`*(this+0x164) = arg`).

## Signature (refined / sealed)

```c
// thiscall (or __fastcall with ECX=this). Bare RET. Result in EAX.
std::uint32_t __thiscall CVOGObjective_GetCompleteCount(void* objective /* ECX */);
```

## ABI / CF seals (2026-07-29 dual residual)

| Seal | Level | Notes |
|---|---|---|
| Body `mov eax,[ecx+0x164]; ret` | **High** | asm + hex `8b 81 64 01 00 00 c3` |
| Offset `+0x164` | **High** | |
| Product tag **CompleteCount** | **High** | string `0x009d0638` + dump |
| ECX = objective | **High** | 5/5 call sites |
| No stack formals | **High** | bare `ret` |
| Dual CALL real (CO + EP) | **High** | not decompiler noise |
| Static callers = 3 fn / 5 sites | **High** | xrefs complete |
| Pure read (no mutate) | **High** | |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059d880_FUN_0059d880.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d880_FUN_0059d880.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/CVOGObjective_GetCompleteCount.cpp` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_0059d880.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0059d880_CVOGObjective_GetCompleteCount.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0059d880_CVOGObjective_GetCompleteCount.md` |
| Scratch | `tmp/a_0059d880.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0059d880_FUN_0059d880.md` (superseded by this named record) |
| Parent CO | `docs/reconstruction/functions/aa_00533f90_CVOGReaction_CompleteObjective.md` |
| Parent EP | `docs/reconstruction/functions/aa_00534920_CVOGCharacter_EvaluatePendingObjectives.md` |

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `CVOGReaction_CompleteObjective` @ `0x00533f90` | sites `0x00534122`, `0x0053412d`; ECX=`EDI` objective; dual CALL; `TEST/JLE` then `CMP nPassed` |
| Caller | `CVOGCharacter_EvaluatePendingObjectives` @ `0x00534920` | sites `0x00534ae2`, `0x00534aed`; ECX=`[ESI]` def; dual CALL; `TEST/JZ` then `CMP success` |
| Caller | `FUN_005468c0` @ `0x005468c0` | site `0x00546952`; ECX=`ESI` objective; XML CompleteCount dump |
| Callees | **none** | |
| Sibling setter | `FUN_0059d890` @ `0x0059d890` | write `+0x164`; sole caller `FUN_00547050` |

## Gate usage (call-site — not this body)

| Path | Form |
|---|---|
| CompleteObjective | `min = Get(); if (min <= 0) need allOk\|force; else need nPassed >= min \| allOk \| force` |
| EvaluatePending | `(count != 0 && count <= success) \|\| allTrue` (+ parent `def+0x138==0`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / offset | **High** |
| Product field name CompleteCount | **High** |
| this = objective | **High** |
| Caller inventory | **High** |
| Canonical C++ method spelling | **Probable** |
| Signedness of stored values in content | **Tentative** |
| Runtime verification | **Open** |
