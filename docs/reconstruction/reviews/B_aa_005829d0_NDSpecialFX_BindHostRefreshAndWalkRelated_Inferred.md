# Review B (skeptical / adversarial): `aa_005829d0` NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005829d0` |
| **VA** | `0x005829d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_005829d0_NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Vehicle-exhaust-only helper | Scaffold alias / parent string | **Falsified** — **12** xrefs; callers include `004ff850` hardpoint expand + `005a9760` |
| 2 | Outer `this` is the FX object | Decompiler param names | **Falsified** — ECX is **host**; FX is **stack param_2**; walk reloads ECX to FX |
| 3 | Always walks related | Optional if | **Falsified** — gated on `*(this-0x88) != 0` |
| 4 | BindHost ECX = raw host | Flat decompiler display | **Falsified** — bytes **MI-adjust** via `this-0x8C` before call |
| 5 | Walk uses host as ECX | First assumption | **Falsified** — `mov ecx, edi` (= param_2 / FX) |
| 6 | Walk args are (0,0,-1) only | Decompiler 4-arg display | **Countered carefully** — first stack arg is **related pointer**, then 0,0,-1 |
| 7 | BindHost takes exactly 2 stack args | Peer dual `aa_00518590` | **Partial** — this site **pushes 3**; peer docs 2; do not over-claim either side |
| 8 | Product name proven | NDSpecialFX family | **Survives as Inferred** — peer dual names BindHost; no string on this VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Two-stage wrapper CF | **High** | Miss attach or double-walk |
| Host vs FX this split | **High** | Wrong ECX in ports |
| MI -0x8C / related -0x88 | **High** | Wrong field layout |
| Exhaust-only scope | **Falsified** | Miss multi-class uses |
| -0x88 English | **Low–Tentative** | Mis-label attachment node |
| BindHost arity 2 vs 3 | **Partial** | Stack imbalance if ported wrong |
| `004b7030` product role | **Open** (out of OWN) | Wrong walk side effects |

---

## 3. Surviving contract

```
// thiscall host; ret 0xC
void BindHostRefreshAndWalkRelated(host, fx, a2, a3) {
  adj = MI_adjust(host, -0x8C);          // lea from *(host-0x8C)+4
  BindHostAndRefresh(adj, fx, a2[, a3]); // peer dual; arity residual
  related = *(host - 0x88);
  if (related)
    FUN_004b7030(/*ECX=fx*/, related, 0, 0, -1);
}
```

---

## 4. Falsifications locked in

- **Reject** exhaust-only / Drive_s_VEHICLE_EXHAUST role label as canonical name.
- **Reject** “this is the FX session” for outer ECX.
- **Reject** unconditional related walk.
- **Reject** BindHost without MI this-adjust.
- **Reject** walk thiscall ECX = host (it is FX / param_2).
- **Reject** hard product rename without string (keep `_Inferred`).

---

## 5. Open questions

1. What object lives at `host-0x88` (sibling FX? hardpoint child? attachment host)?
2. Full semantics of `FUN_004b7030` (W24-D).
3. Reconcile BindHost formal count (2 in peer dual vs 3 pushes here).
4. Which concrete host classes place this method on their vtbl / MI slice.

**Verdict:** **accept-with-gaps**
