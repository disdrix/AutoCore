# Review B (skeptical / adversarial): `aa_005ffc20` CVOGHBToken_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-K) |
| **Counterpart** | `reviews/A_aa_005ffc20_CVOGHBToken_OnEnd.md` |
| **Verdict** | **accept-with-gaps** |

---

## Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Direct-called helper, not virtual | **Falsified** — sole xref is DATA vtbl `0x009dde40`; no CALL sites |
| 2 | Class is generic HB base / not Token | **Falsified** — RTTI `.?AVCVOGHBToken@@` at type_info linked to this vtbl family |
| 3 | Always sets flag 1 | **Falsified** — requires related non-null, host non-null, and `this+0x10 < 1` |
| 4 | Sets flag 0 (clear) | **Falsified** — framed value is `1` (`push 1` before vcall/`005208e0`) |
| 5 | `vtbl+0x210(0,1)` both args for character resolve | **Partially open** — decompiler shows 2-arg form; machine matches UnpackGhost `push value; push 0; vcall 0x210; SetFlag` pattern. End effect **flag=1** remains High |
| 6 | Meaningful work in tail `FUN_005081f0` | **Falsified** — empty `ret` (sealed peer dual) |
| 7 | Slot is OnStart not OnEnd | **Falsified** — slot `+0x14` matches family OnEnd; `+0x04` is StampLastFireTime/OnStart default |

## Surviving contract

```text
// ECX = CVOGHBToken* (vtbl+0x14 OnEnd)
if this.related(+0x18):
  host = related.vfunc_1d4()
  if host and this.field_10 < 1:
    character = host.MI.vfunc_210(0)
    Character_SetFlagByte_plus529(character, 1)  // net dirty 0x100
// always: empty ret stub
```

## Residual risks

- Product English for Token `+0x10` and character `+0x529`.
- Whether `vtbl+0x210` ever consumes the `1` (would break SetFlag arg) — cross-check with multiple call sites all use `push value; push 0` and `005208e0` `ret 4` successfully in retail → **value survives as SetFlag arg (High practical)**.

**Verdict:** **accept-with-gaps.** Accept A. RTTI name + CF sealed; field English open.
