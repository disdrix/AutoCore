# Function record: CVOGObjective_MatchTargetEvaluators

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d9c0` |
| **Canonical name** | `CVOGObjective_MatchTargetEvaluators` |
| **Prior** | `FUN_0059d9c0`; auto-alias `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059d9c0` |
| **Address** | `0x0059d9c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` / missions-progression (active-objective match) |
| **Completion status** | **Human-refined helper** — three-rep + dual A/B strengthened 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Walk objective evaluator array `[this+0x158, this+0x15c)`. Return **1** if any evaluator’s **vtable+0x40** predicate succeeds on `(argA, argB)`, else **0** (first hit wins; empty range → 0).

**Production role:** sole callee of `CVOGCharacter_FindActiveObjectiveIdForInteract` (`0x00524520`) — the **+0x40** path that supplies interact / IfInteractable objective id matching.

Sibling: `CVOGObjective_MatchTargetEvaluators_Slot44` (`aa_0059da10` / `0x0059da10`) — identical loop with **vtable+0x44** (ForPick).

## Signature (refined / sealed)

```c
// thiscall; stack cleaned by callee (RET 8). Result in AL as 0/1.
std::uint32_t __thiscall CVOGObjective_MatchTargetEvaluators(
    void* objective,   /* ECX — objective instance/def with evaluator vector */
    void* argA,        /* production: Character* */
    void* argB);       /* production: world Object* */
```

## ABI / CF seals (2026-07-29 dual residual)

| Seal | Level | Notes |
|---|---|---|
| `RET 0x8` both paths | **High** | asm epilogues |
| ECX = objective | **High** | body + sole call site `MOV ECX,EDI` (objInst) |
| Slot `call [vtbl+0x40]` | **High** | `ff 50 40` |
| Range `+0x158` / `+0x15c`, stride +4 | **High** | decompile + asm |
| First true → 1; empty → 0 | **High** | |
| Sole caller `0x00524520` @ `0x005245aa` | **High** | xrefs |
| Production args (character, worldObject) | **High** | call-site push order |
| Byte-clone of Slot44 except imm 0x40 vs 0x44 | **High** | dual residual pair |
| Not +0x38 MatchTarget / not +0x44 pick | **High** | slot family |

## Artifacts

| Kind | Path |
|---|---|
| Raw (named) | `docs/reconstruction/raw/aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| Raw (scaffold) | `docs/reconstruction/raw/aa_0059d9c0_FUN_0059d9c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d9c0_FUN_0059d9c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_MatchTargetEvaluators.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0059d9c0_CVOGObjective_MatchTargetEvaluators.md` |
| Sibling record | `docs/reconstruction/functions/aa_0059da10_CVOGObjective_MatchTargetEvaluators_Slot44.md` |
| Parent walker | `docs/reconstruction/functions/aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0059d9c0_FUN_0059d9c0.md` (superseded by this named record) |

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller (sole) | `CVOGCharacter_FindActiveObjectiveIdForInteract` @ `0x00524520` (call `0x005245aa`) | ECX=objInst; stack (character, worldObject) |
| Callees | **indirect only** — evaluator vtbl **`+0x40`** | no direct `FUN_*` |
| Default eval stub (many types) | `FUN_004cc820` @ `0x004cc820` | `XOR AL,AL; RET 8` always false |

## Slot family

| Slot | Path | Upstream |
|---|---|---|
| `+0x38` | `Client_FindObjectiveMatchingTarget` `0x00525bd0` (inline) | objective **def\*** |
| **`+0x40`** | **this** ← ForInteract | objective **id** |
| `+0x44` | Slot44 ← ForPick | objective **id** |

## Implementer samples (partial)

| Class | Vtable | `+0x40` body | Interact via this unit? |
|---|---|---|---|
| Collect | `0x009e12c4` | `004cc820` always false | No |
| Kill | `0x009e19e4` | `004cc820` always false | No |
| Deliver | `0x009e0f24` | `004cc820` always false | No |
| UseItem | MatchTarget @ `+0x38` = `0x0060d7f0`; dword @ base+0x40 = `0x0060d800` SerializeXml | **Not a match predicate** | No (uses +0x38 path) |

Full non-stub +0x40 matrix: **open**.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm | **High** |
| ABI / slot / sole caller / arg binding | **High** |
| Parameter semantic names (production path) | **High** |
| Product name of +0x40 virtual | **Tentative** |
| Per-type +0x40 implementers | **Partial** (samples High; matrix Open) |
