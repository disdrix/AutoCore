# Annotated: Skill_SiblingCastClearPredicate_Inferred @ 0x00512bb0

| Field | Value |
|---|---|
| Stable ID | `aa_00512bb0` |
| VA | `0x00512bb0` |
| System | `skills-abilities` |
| Date | 2026-07-29 dual A/B |
| Parent | `aa_00514e20` Skill_SiblingCastClear packs ctx + list walk |

## Machine-level notes

- **ABI:** `__stdcall` **`ret 0x0C`** — formals `(pHb, pCtx, pStopUnused)`.
- Decompiler shows 2 args / thiscall-ish vcall — **noise** on third formal and on `this` for `vtbl+0x18` (asm: `mov ecx,eax` before call).
- RTTI imm constants sealed via `read_memory` type_info strings.
- Callback only (DATA xrefs); never CALLed as normal relative call.

## Annotated CF

```c
// int __stdcall Skill_SiblingCastClearPredicate(
//   CVOGHBBase *pHb, SiblingCastClearCtx *pCtx, void *pStopUnused)

int Skill_SiblingCastClearPredicate_INFERRED(int pHb, int *pCtx /* , void *pStop */)
{
  int type = *(int *)(pHb + 0x1c);
  int *pCast;
  bool match;

  if (type == 1) {
    // CVOGHBBase → CVOGHBSkillBase
    pCast = __RTDynamicCast(pHb, 0, &CVOGHBBase_TD /*0x00af8d98*/,
                                   &CVOGHBSkillBase_TD /*0x00af8cec*/, 0);
    // skillId embed @+0x620 ≡ skill blob @+0x24 field +0x5fc
    if (pCast[0x188] != pCtx[0]) return 0;           // +0x620
    if (pCast[0x196] != pCtx[2]) return 0;           // +0x658 vs ctx+8
    if (pCast[0x197] != pCtx[3]) return 0;           // +0x65c vs ctx+0xc
    match = (char)pCast[0x198] == (char)pCtx[4];     // +0x660 lo vs ctx+0x10 lo
    // note: +0x664 and ctx tfid3 never compared
  } else {
    if ((char)pCtx[6] == 0) return 0;                // ctx+0x18 flag
    if (type != 8) return 0;
    // CVOGHBBase → CVOGHHBOKToCastAgain
    pCast = __RTDynamicCast(pHb, 0, &CVOGHBBase_TD,
                                   &CVOGHBOKToCastAgain_TD /*0x00b0015c*/, 0);
    match = *(int *)(pCast[9] + 0x5fc) == pCtx[0];    // *(+0x24)+0x5fc
  }

  if (!match) return 0;
  // thiscall: pCast->vtbl[+0x18](1, 0)  — Stop/End family
  (**(code **)(*pCast + 0x18))(1, 0);
  return 1; // remove node
}
```

## Open (owned gaps)

- Product demangled name (keep `_Inferred`).
- Partial TFID rationale; `vtbl+0x18` English.
- Runtime / bit-exact.
