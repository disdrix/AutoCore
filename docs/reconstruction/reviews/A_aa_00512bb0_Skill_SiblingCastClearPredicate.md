# Review A (reconstruction fidelity): `aa_00512bb0` Skill_SiblingCastClearPredicate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512bb0` |
| **VA** | `0x00512bb0` |
| **Canonical name** | `Skill_SiblingCastClearPredicate` (**Inferred**; Ghidra `_INFERRED`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00512bb0_Skill_SiblingCastClearPredicate.md` |
| **Residual scratch** | `reviews/a_00512bb0.md` |
| **System** | `skills-abilities` |
| **Owner body of** | `aa_00514e20` `Skill_SiblingCastClear` (also inlined at `FUN_00517400`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

List-walk **predicate** for `CNDDoubleList_InvokePredicateAndRemove_Inferred`: decide whether a host-list heartbeat payload is a **sibling cast** of the given skill (and optionally an OK-to-cast-again HB), **Stop** it, and signal **remove**.

Not the list walker itself. Not binding-map clear. Not cast validate. Not wire I/O.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00512bb0_Skill_SiblingCastClearPredicate_Inferred.md` |
| Annotated | `docs/reconstruction/raw/aa_00512bb0_Skill_SiblingCastClearPredicate_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_SiblingCastClearPredicate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00512bb0_Skill_SiblingCastClearPredicate_Inferred.md` |
| Live Ghidra | decompile + `analyze_function_complete` `0x00512bb0` |
| Bytes | `read_memory` `0x00512bb0` length 200 (body through dual `ret 0x0C`) |
| RTTI memory | `0x00af8cec` / `0x00af8d98` / `0x00b0015c` |
| Parent dual | `A\|B_aa_00514e20_Skill_SiblingCastClear.md` |
| List utility dual | `A\|B_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred` |
| Skill HB ctor | `aa_005788d0` `CVOGHBSkillBase_ctor` (type 1; TFID `@+0x658`) |
| OKToCastAgain ctor | `aa_0051e240` (type 8; skill `*@+0x24`) |
| DATA xrefs | `0x00514e5b`, `0x00517520` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__stdcall` **`RET 0x0C`** (3 stack formals) | **Confirmed** | epilogue `C2 0C 00` both exit paths |
| Args: `(pHb, pCtx, pStopUnused)` | **Confirmed** | list dual callback shape; body never touches arg3 |
| Return 0 keep / 1 remove | **Confirmed** | `xor al,al` / `mov al,1` |
| Type tag field `HB+0x1c` | **Confirmed** | `mov ecx,[eax+0x1c]` |
| Type-1 arm → RTTI `CVOGHBSkillBase` | **Confirmed** | push `0x00af8cec` + string |
| Type-8 arm → RTTI `CVOGHBOKToCastAgain` | **Confirmed** | push `0x00b0015c` + string |
| Base RTTI `CVOGHBBase` `0x00af8d98` | **Confirmed** | both arms |
| Type-1 skillId `@+0x620` vs `*ctx` | **Confirmed** | `mov edx,[eax+0x620]` |
| Type-1 TFID base `@+0x658` | **Confirmed** | `lea edx,[eax+0x658]` |
| Partial TFID: 2 dwords + **1 byte** | **Confirmed** | `cmp` / `cmp dl,[ecx+0x10]`; dword3 spilled unused |
| Type-8 gate `ctx+0x18 ≠ 0` | **Confirmed** | `cmp byte [esi+0x18],0` before type==8 |
| Type-8 skillId via `*(hb+0x24)+0x5fc` | **Confirmed** | `mov ecx,[eax+0x24]`; `[ecx+0x5fc]` |
| On match: `thiscall vtbl+0x18(1,0)` then return 1 | **Confirmed** | `push 0; push 1; mov ecx,eax; call [edx+0x18]` |
| No write to stop out-param | **Confirmed** | all matches removed by list utility |
| No null-check after RTTI cast | **Confirmed** | asm; crash if cast fails |
| DATA xrefs: parent + `FUN_00517400` | **Confirmed** | two DATA sites |
| Product demangled symbol | **Open** | working title Inferred |
| `vtbl+0x18` English name | **High** Stop/End family | name open |

---

## 4. Control flow: clean ≡ decomp ≡ live asm

| Stage | Match |
|---|---|
| Type branch `+0x1c == 1` vs else | Yes |
| Type-1 RTTI + skillId + partial TFID | Yes |
| Type-8 flag then type==8 then RTTI + skillId | Yes |
| Match → `vtbl+0x18(1,0)` → return 1 | Yes |
| Fail → return 0 | Yes |
| `ret 0x0C` | Yes |
| Invent full-TFID16 / null checks | **No** (correctly absent) |

### Recovered CF (asm-sealed)

```c
// int __stdcall Skill_SiblingCastClearPredicate(
//   void *pHb, SiblingCastClearCtx *pCtx, void *pStopUnused /*never used*/)

struct SiblingCastClearCtx {
  int  skillId;       // +0x00
  int  _padUnset;     // +0x04
  u32  tfid0;         // +0x08
  u32  tfid1;         // +0x0c
  u32  tfid2;         // +0x10  (only low byte compared)
  u32  tfid3;         // +0x14  unused
  u8   alsoOkAgain;   // +0x18
};

int Skill_SiblingCastClearPredicate(void *pHb, SiblingCastClearCtx *pCtx, void * /*pStop*/)
{
  int type = *(int *)((char *)pHb + 0x1c);
  void *hbCast;
  bool match;

  if (type == 1) {
    hbCast = __RTDynamicCast(pHb, 0, &CVOGHBBase_RTTI, &CVOGHBSkillBase_RTTI, 0);
    if (*(int *)((char *)hbCast + 0x620) != pCtx->skillId) return 0;
    if (*(u32 *)((char *)hbCast + 0x658) != pCtx->tfid0) return 0;
    if (*(u32 *)((char *)hbCast + 0x65c) != pCtx->tfid1) return 0;
    match = (*(u8 *)((char *)hbCast + 0x660) == (u8)pCtx->tfid2);
  } else {
    if (pCtx->alsoOkAgain == 0) return 0;
    if (type != 8) return 0;
    hbCast = __RTDynamicCast(pHb, 0, &CVOGHBBase_RTTI, &CVOGHBOKToCastAgain_RTTI, 0);
    void *pSkill = *(void **)((char *)hbCast + 0x24);
    match = (*(int *)((char *)pSkill + 0x5fc) == pCtx->skillId);
  }

  if (!match) return 0;
  // thiscall Stop/End family
  (*(void (__thiscall **)(void *, int, int))(*(int *)hbCast + 0x18))(hbCast, 1, 0);
  return 1;
}
```

Offset cross-check: type-1 embed `skill@+0x24` field `+0x5fc` → HB absolute `+0x620` (parent dual / ctor dual).

---

## 5. Xrefs / consumers

| Site | Function | How used |
|---|---|---|
| `0x00514e5b` | `Skill_SiblingCastClear` | push imm; sole wrapper that packs ctx + list `host+0xB0` |
| `0x00517520` | `FUN_00517400` | same predicate; inlined InvokePredicateAndRemove; flag **0**; skill `+0x5fc`; host TFID `this+0x160` |

Wrapper callers of `Skill_SiblingCastClear` (flag matrix) live on **parent** dual (`ApplyStatusEffectLocal` / `FUN_00514e70` flag 0; `FUN_0052db50` flag **1**). Predicate dual only owns the match body.

---

## 6. Gaps / open

1. Product demangled name (role name sealed **Inferred**).
2. Partial TFID rationale; unused `tfid3` and ctx hole `+4`.
3. `vtbl+0x18(1,0)` product method name.
4. Runtime / bit-exact matrix.
5. Sibling: seal `FUN_00517400` product name (inlined consumer).

**Verdict:** **accept-with-gaps** — ABI, dual RTTI arms, partial TFID, flag gate, Stop-then-remove, and DATA xrefs sealed; product symbol and vtbl English open.
