# Review B (skeptical / adversarial): `aa_00518590` NDSpecialFX_BindHostAndRefresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518590` |
| **VA** | `0x00518590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_00518590_NDSpecialFX_BindHostAndRefresh_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body fails a mission / notifies fail | Callee `CVOGReaction_FailMissionNotify` | **Falsified** — peer dual seals callee as pure **`Vector_PushDword`**; historical name only |
| 2 | Vehicle-exhaust-only helper | Scaffold alias `Drive_s_VEHICLE_EXHAUST` | **Falsified** — 4 DATA (vtbl) xrefs + `FUN_005829d0` code caller; broad FX attach surface |
| 3 | `this` is always the FX object | Nested `004b73c0(host)` display | **Countered** — outer ECX is **host**; FX is stack `param_2`; nested FX thiscalls reload ECX |
| 4 | Always marks `fx+9=1` | Only branch seen first | **Falsified** — only when `modeFlag==0`; else vector push |
| 5 | Unconditionally sets `fx+0x230=3` | Write present | **Falsified** — gated on `vtbl+0x210` chain, `+0x250` non-null, `+0x103` char, and current value **&lt; 3** |
| 6 | Skips transform update | Could be bind-only | **Falsified** — always ends with `004b75d0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bind + refresh CF spine | **High** | Wrong FX attach order |
| FailMissionNotify ≠ mission fail | **High** | False mission coupling |
| Host vs FX this split | **High** | Wrong ECX in ports |
| Vector push target object | **Partial** | Deferred-list wrong owner |
| `+0x230` English | Open | Cosmetic / LOD guess only |
| Exhaust-only scope | **Falsified** | Miss multi-class uses |

---

## 3. Surviving contract

```
// thiscall hostObject; fxSession on stack
void BindHostAndRefresh(host, fx, modeFlag) {
  if (modeFlag == 0) fx->byte9 = 1;
  else Vector_PushDword(/*vector residual*/, &fx);  // pushes fx pointer value
  SetHostObject(fx, host);           // fx+0x10, TFID cache, child list
  fx->ctx_0x2c = *(host + 0xa4);     // gate for later update/setup
  FUN_004b9300(fx, 0);               // spatial/setup; 0 → use fx host
  o = host->vtbl[0x210](0);
  if (o && *(o+0x250) && *(*(o+0x250)+0x103) && fx->i_0x230 < 3)
    fx->i_0x230 = 3;
  UpdateParamMapTransforms(fx);
}
```

---

## 4. Falsifications locked in

- **Reject** mission-fail semantics from the historical callee name.
- **Reject** vehicle-exhaust-only scaffold as role label.
- **Reject** unconditional `+0x230=3` and unconditional `+9=1`.
- **Reject** “bind without refresh” — `004b75d0` always runs.
- **Reject** treating outer `this` as the FX session.

---

## 5. Open questions

1. ECX / object for the `Vector_PushDword` path when `modeFlag != 0`.
2. Product meaning of floor-to-3 at `fx+0x230` (FX type tier? lod? event class?).
3. Class owners of DATA xrefs at `0x009ce344`, `0x009d34bc`, `0x009d4244`, `0x009dbcf4`.

**Verdict:** **accept-with-gaps**
