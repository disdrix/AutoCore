# Review B (skeptical / adversarial): `aa_0091ce80` Client_Camera_ModeDispatchUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091ce80` |
| **VA** | `0x0091ce80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure stdcall this-on-stack | Entry `mov esi,eax`; first formal is dt only | **EAX = cam*** hybrid ABI |
| 2 | Mode 0 is default only | default arm catches 0,4,6,... not only 0 | **default = all non-listed** |
| 3 | Always rebuilds look | Mode 8 early-goto skips generic look | **Mode-8 special** |
| 4 | No FOV side effects | Child `+0xf0` band + dirty flags | **Has FOV band** |
| 5 | Multiple callers | Single xref @ `0x00924283` | **Sole call site** |
| 6 | Ghidra callee list complete | Omits mode arms | **Use decompile switch** |
| 7 | Product name recovered | No plate | **False** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 4` / EAX cam* | **Confirmed** | ABI break |
| Mode switch mapping | **Confirmed** | wrong mode ports |
| Links to dualed helpers | **Confirmed** | orphan mode paths |
| FOV band presence | **High** | missing post FX |
| Mode enum English | Open | docs only |
| Containing caller | Open | call-graph gap |
| Runtime / bit-exact | Open | |

---

## 3. Surviving contract

```
// RET 4; EAX = cam*
void Client_Camera_ModeDispatchUpdate_Inferred(float dt_or_scale)
{
  // focus; gate; ranges
  // switch(cam[0x331]) → mode helper
  // look / FOV band / optional velocity FOV
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product method name | No |
| R2 | Mode English labels | No |
| R3 | Duals for 1/3/8 helpers | Mild for full camera system |
| R4 | Caller containing function | Mild |
| R5 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x0091ce80` — matches scaffold raw CF.
2. `read_memory` entry: `mov esi,eax` after prolog/pushes.
3. `read_memory` epilog: `pop ebp; ret 4`.
4. Caller site: `push ebx; mov eax,edi; call 0091ce80`.
5. Constants: 4.0, 1.5, 0.05, 0.4, 1.5 band, π/180.
6. Cross-check with dualed `009168d0` / `0091b1c0` reviews.

---

## 6. Falsifications locked in

- **Reject** pure stack-this stdcall without EAX cam*.
- **Reject** claiming only mode 0 uses default helper.
- **Reject** omitting FOV band / dirty-flag side effects.
- **Reject** trusting incomplete Ghidra callee list over decompile switch.
