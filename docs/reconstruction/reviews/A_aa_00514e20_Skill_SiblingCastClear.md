# Review A (reconstruction fidelity): `aa_00514e20` Skill_SiblingCastClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514e20` |
| **VA** | `0x00514e20` |
| **Canonical name** | `Skill_SiblingCastClear` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00514e20_Skill_SiblingCastClear.md` |
| **Residual scratch** | `reviews/a_00514e20.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host-side **sibling cast HB clear**: walk `*(host+0xB0)` (`CNDDoubleList` of `CVOGHBBase*`) with a skillId + partial source-TFID predicate; **Stop** matching cast heartbeats and remove their list nodes. Optional arm (flag≠0) also clears type-**8** `CVOGHBOKToCastAgain` HBs by skillId. Used when re-applying status effects with an active binding, when re-firing a skill with flag `skill+0x615`, and when tearing down a skill tree entry (flag=1).

Not binding-map clear (`Skill_ClearCastBindingAndMaybeRestartCd`). Not cast validate. Not wire I/O.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00514e20_FUN_00514e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00514e20_FUN_00514e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00514e20.cpp` (update → `Skill_SiblingCastClear`) |
| Function record | `docs/reconstruction/functions/aa_00514e20_FUN_00514e20.md` |
| Live Ghidra | re-decompile `0x00514e20`; force refresh; `read_memory` body |
| Pcode | basic block `0x00514e20`–`0x00514e6c` |
| Predicate | create+decompile `0x00512bb0` (`Skill_SiblingCastClearPredicate_INFERRED`) |
| List utility dual | `A\|B_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred` |
| Skill HB ctor dual | `aa_005788d0` `CVOGHBSkillBase_ctor` (type tag 1; TFID `@+0x658`) |
| OKToCastAgain dual | `aa_0051e240` (type tag 8; skill `*@+0x24`) |
| Caller dual | `aa_0051aa00` `Skill_ApplyStatusEffectLocal` |
| RTTI memory | `0x00af8cec` / `0x00af8d98` / `0x00b0015c` |
| Callers | 3 UNCONDITIONAL_CALL sites |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` host in ECX; `list = *(host+0xB0)` | **Confirmed** | `mov ecx,[ecx+0xB0]` |
| `RET 0x18` = 6 stack formals | **Confirmed** | epilogue |
| Stack formals: skillId + 4×u32 TFID pack + flag byte | **Confirmed** | body pack |
| Decompiler missing `this` | **Noise** | asm overrides |
| Sole callee: `CNDDoubleList_InvokePredicateAndRemove_Inferred` | **Confirmed** | |
| Predicate VA `0x00512bb0` | **Confirmed** | DATA xref + push imm |
| `nullPayloadFlag = 0` | **Confirmed** | `push 0` |
| Type-1 arm = `CVOGHBSkillBase` RTTI | **Confirmed** | type_info string |
| Type-8 arm = `CVOGHBOKToCastAgain` RTTI | **Confirmed** | type_info string |
| Type tag field `HB+0x1c` | **Confirmed** | ctor duals + predicate |
| SkillId compare `HB+0x620` ↔ `skill+0x5fc` via embed `@+0x24` | **Confirmed** | 0x24+0x5fc=0x620 |
| Source TFID seed `HB+0x658` from `source+0x160` | **Confirmed** | SkillBase ctor dual |
| Partial TFID match (2 dwords + 1 byte) | **Confirmed** | asm `cmp` sequence |
| Flag gates type-8 only | **Confirmed** | predicate early-out |
| On match: `vtbl+0x18(1,0)` then remove | **Confirmed** | predicate |
| Continues for all matches (no stop) | **High** | stop out-param unused |
| Callers: ApplyStatusEffectLocal / FUN_00514e70 / FUN_0052db50 | **Confirmed** | xrefs |
| Distinct from binding-map clear | **Confirmed** | different container |
| Product C++ symbol | **Open** | role name sealed High |
| `vtbl+0x18` product English | **High** role (Stop/End family) | name open |

---

## 4. Control flow: clean ≡ raw ≡ live asm

| Stage | Match |
|---|---|
| Pack ctx (skillId + TFID + flag) | Yes |
| Load list `*(this+0xB0)` | Yes (asm; decomp noise) |
| InvokePredicateAndRemove(pred, ctx, 0) | Yes |
| No invent binding map / wire / validate | Yes |

### Recovered CF (asm-corrected)

```c
// void __thiscall Skill_SiblingCastClear(
//   void *pHost, int nSkillId,
//   u32 t0, u32 t1, u32 t2, u32 t3, u8 bAlsoOkToCastAgain)

void Skill_SiblingCastClear(void *pHost, int nSkillId,
    u32 t0, u32 t1, u32 t2, u32 t3, u8 bAlsoOkToCastAgain)
{
  struct {
    int skillId;       // +0
    int _padUnset;     // +4 never written
    u32 tfid[4];       // +8 .. +0x14
    u8  alsoOkAgain;   // +0x18
  } ctx;

  ctx.skillId = nSkillId;
  ctx.tfid[0] = t0; ctx.tfid[1] = t1;
  ctx.tfid[2] = t2; ctx.tfid[3] = t3;
  ctx.alsoOkAgain = bAlsoOkToCastAgain;

  CNDDoubleList_InvokePredicateAndRemove_Inferred(
      *(void **)((char *)pHost + 0xB0),
      Skill_SiblingCastClearPredicate,
      &ctx,
      /*nullPayloadBeforeNodeDestroy=*/0);
}

// Predicate (payload HB*, ctx*, stop*):
//   if type==1: RTTI CVOGHBSkillBase;
//     match skillId@+0x620 && TFID partial @+0x658..
//   else if ctx.flag && type==8: RTTI CVOGHBOKToCastAgain;
//     match skill*@+0x24 → +0x5fc == skillId
//   if match: hb.vtbl+0x18(1,0); return 1; else 0
```

---

## 5. Callers (inventory)

| Caller | Site | flag | Notes |
|---|---|---|---|
| `Skill_ApplyStatusEffectLocal` | `0x0051ab93` | 0 | args: `skill+0x5fc`, caster `+0x160..+0x16c` |
| `FUN_00514e70` | `0x00514ee3` | 0 | gated `skill+0x615&1`; host TFID `this+0x160` (`[0x58]`) |
| `FUN_0052db50` | `0x0052dbae` | **1** | skill-tree teardown; also OKToCastAgain; then delete skill |

---

## 6. Gaps / open

1. Product demangled name (role name `Skill_SiblingCastClear` is working title).
2. Why TFID match is partial (2 dwords + 1 byte); `tfid[3]` unused.
3. `vtbl+0x18(1,0)` product method name.
4. `FUN_00514e70` / `FUN_0052db50` names and FUN_0052db50 this-adjust TFID base (`+0x164` vs `+0x160`).
5. Product field name for host `+0xB0` list.
6. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — ABI, list host, predicate RTTI arms, and caller roles sealed; product symbol and partial-TFID English open.
