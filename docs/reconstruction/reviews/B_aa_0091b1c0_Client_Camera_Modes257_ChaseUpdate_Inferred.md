# Review B (skeptical / adversarial): `aa_0091b1c0` Client_Camera_Modes257_ChaseUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091b1c0` |
| **VA** | `0x0091b1c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Name from `VOG_DEBUG_STOP` | String only on null `+0x48` abort | **Reject** alias — role is chase modes 2/5/7 |
| 2 | thiscall ECX = cam | Epilog `ret 0x14`; cam in **EDI** | **Falsified as ECX thiscall** — hybrid EDI+stack |
| 3 | Same 8-probe multipass as default | Body calls `00916090` **once** vertical | **Distinct** simpler collision |
| 4 | Returns float distance | Void; side effects only | **Falsified if ST0 return claimed** |
| 5 | Used for all camera modes | Only switch cases 2/5/7 | **Mode-subset only** |
| 6 | `unaff_EDI` is decompiler junk | Call-site `mov edi,esi` | **Real ABI register** |
| 7 | Product name recovered | No body plate | **False** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall `ret 0x14` / 5 floats | **Confirmed** | ABI break |
| EDI = cam* | **Confirmed** | wrong object writes |
| Modes 2/5/7 only | **High** | wrong mode ports |
| Single vertical probe | **High** | over/under collision |
| Eye bus offsets | **High** | wrong camera bus |
| Product name | Tentative | cosmetic |
| Runtime / bit-exact | Open | |

---

## 3. Surviving contract

```
// stdcall RET 0x14; EDI = cam*
void Client_Camera_Modes257_ChaseUpdate_Inferred(
    float focus_x, float focus_y, float focus_z,
    float range_a, float range_b)
{
  // cache focus; quat forward; optional look-yaw
  // eye = f(focus, yaw, ranges, basis)
  // d = MapRaySegmentHitDistance vertical; optional pull
  // normalize look; render commit
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product method name | No |
| R2 | Mode 2/5/7 English labels | No |
| R3 | Wheel-scan head loop | No (dead CF) |
| R4 | Nested helper duals | Mild |
| R5 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x0091b1c0` — matches scaffold raw CF.
2. `read_memory` entry: `push ebp; mov ebp,esp; and esp,-16; sub esp,0x7C; push esi`.
3. `read_memory` epilog: `pop esi; mov esp,ebp; pop ebp; ret 0x14`.
4. Call-site @ `0x0091d020`: `mov edi,esi` then `call FUN_0091b1c0`.
5. Constants: 2.0, 5.0, 0.2, 12.0, 3.5, ±1e-6, -1.0.
6. Sole xref from `FUN_0091ce80`.

---

## 6. Falsifications locked in

- **Reject** `Named_VOG_DEBUG_STOP_0091b1c0` as role name.
- **Reject** pure ECX-thiscall / missing EDI.
- **Reject** equating to default 8-probe multipass (`009168d0`).
- **Reject** inventing a float return; stores only.
