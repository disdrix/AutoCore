# Review A (reconstruction fidelity): `aa_00578ce0` Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578ce0` |
| **VA** | `0x00578ce0`–`0x00578de0` exclusive (**0x100 B**) |
| **Canonical name** | `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` |
| **Ghidra name** | `FUN_00578ce0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | WQ9D-F OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — OnEnd role/CF/flag symmetry sealed; product English + nested cast-owner open |

---

## 1. Purpose

Shared skill HB **OnEnd** (`vtbl+0x10`) teardown body used directly in skill HB vtables and via thin subclass wrappers. Inverse of `Skill_HB_FireTail_FxTargetAndPeriodStamp` for cast-binding / owner counter / secondary flag polarity.

```c
// __thiscall; no stack args; tail-jmp empty base OnEnd
void Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred(SkillHb* this);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00578ce0_FUN_00578ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578ce0_FUN_00578ce0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00578ce0.cpp` |
| Live Ghidra | `decompile_function` / `analyze_function_complete` / `read_memory` body |
| Sibling FireTail | `A_aa_00578b30_Skill_HB_FireTail_FxTargetAndPeriodStamp` |
| ClearCast dual | `A_aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd` |

**No** `disassemble_bytes`. Constants/gates from `read_memory` on body.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00578ce0`–`0x00578de0` excl. | **Confirmed** | `get_function_by_address` + epilogue jmp |
| ECX=this; no stack args | **Confirmed** | `8B F1`; no `ret N` |
| Tail-jmp `0x005081f0` (not call) | **Confirmed** | `E9 10 F4 F8 FF` after pops |
| Slot **vtbl+0x10** OnEnd | **Confirmed** | DATA xrefs e.g. `0x009d0e28`; matches `CVOGHBBase_Stop` contract |
| Hook via `PTR_FUN_00af31e0(this,0)` | **Confirmed** | `FF 15 E0 31 AF 00` |
| Resolve uses world `+0x688` → `+0xe4e8` host | **Confirmed** | prolog loads before call |
| `FUN_00578ac0` clears vector `+0x6b0` | **High** | callee decompile + thiscall ECX=esi |
| Owner `vtbl+0x238` mode **1** | **Confirmed** | `6A 01` before call; skillId `+0x620` |
| Rank = i16(`+0x61a`)+i16(`+0x198`) | **Confirmed** | `66 03 96 98 01 00 00` |
| Flag `0x10` → `owner+0x26--` | **Confirmed** | `F6 … 10` / `80 40 26 FF` |
| Flag `0x02` → ClearCastBinding | **Confirmed** | callee `Skill_ClearCastBinding…`; TFID `+0x678…` |
| `+0x140` → `FUN_0051f880(0)` | **Confirmed** | `6A 00` before call; inverse of FireTail `1` |
| Live decompile ≡ raw CF | **Confirmed** | 2026-08-04 re-decompile |
| Product C++ name | **Inferred** | no string/RTTI on this VA |

---

## 4. Control flow vs FireTail

| Stage | FireTail `0x00578b30` | This OnEnd |
|---|---|---|
| Hook PTR | `00af31e4` | `00af31e0` |
| Resolve target | yes | yes |
| Vector `+0x6b0` | — | **clear** |
| Flag `0x10` / `owner+0x26` | **++** | **--** |
| Flag `0x02` cast map | **Insert** | **Clear** + CD restart gate |
| `+0x140` / `FUN_0051f880` | **1** | **0** |
| Period / FX | yes | no |

---

## 5. Gaps (acceptable)

1. Product / PDB symbol.
2. Owner `vtbl+0x238` English (skill-end notify arity sealed; product verb open).
3. Nested cast-owner chain product type (`vtbl+0x214` result).
4. Full inventory of DATA vtable hosts (24 xrefs; role sealed via slot offset).
5. Runtime / bit-exact / differential (Terminal false; no Launcher).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| ABI / epilogue sealed | **Pass** |
| OnEnd slot / Stop contract | **Pass** |
| FireTail inverse polarity | **Pass** |
| Clean uses meaningful names | **Pass** |
| Verdict | **accept-with-gaps** |
