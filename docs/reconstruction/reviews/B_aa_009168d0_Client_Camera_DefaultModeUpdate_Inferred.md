# Review B (skeptical / adversarial): `aa_009168d0` Client_Camera_DefaultModeUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009168d0` |
| **VA** | `0x009168d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is mode-1/orbit-only exclusive path | Caller switch sends modes 1/2/3/5/7/8 elsewhere; this is **default** | **Role = default**, not exclusive orbit-1 |
| 2 | thiscall on camera object | Epilogue `C2 14 00`; first arg is stack `param_1` | **Falsified** — **stdcall** free-style with explicit cam* |
| 3 | Does terrain-height Y cast only | Calls dualed `00916090` segment distance (filter 7), 8 directions | **Distinct** general collision pull |
| 4 | Returns float distance | Void function; writes globals/object fields | **Falsified if ST0 return claimed** |
| 5 | Probe count is dynamic | Inner loop `iStack_7c < 8` hard bound | **Fixed 8** |
| 6 | Always snaps eye | Branch on `DAT_00d1f0a0` integrate vs snap | **Both paths sealed** |
| 7 | Product name recovered | No body string | **False** — `_Inferred` |
| 8 | `00916090` is VOG_DEBUG-only | Dualed W23-O with this camera caller | **Falsified** (prior) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall `ret 0x14` / 5 args | **Confirmed** | ABI break |
| Default-mode sole caller | **High** | wrong mode ports |
| 8-probe + multi-pass pull CF | **High** | camera through walls |
| Uses `00916090` distance | **Confirmed** | wrong collision metric |
| Eye bus offsets | **High** | wrong camera object |
| Gate-byte English | Open | edge-case ports |
| `param_5` unit | Tentative | timing scale error |
| Product name | Tentative | cosmetic |
| Runtime / bit-exact | Open | |

---

## 3. Surviving contract

```
// stdcall RET 0x14
void Client_Camera_DefaultModeUpdate_Inferred(
    int *cam,
    float *focus_xyz,
    float range_a,
    float range_b,
    float dt_or_scale)
{
  // aim = f(focus, cos/sin(cam.yaw), range_a/b, cam.basis)
  // optional look-yaw -> cam+0x538
  // build look basis (normalize/cross)
  // multi-pass: for i in 0..7: probe; MapRaySegmentHitDistance; track pull
  // commit eye to DAT_00d17944+0x228..
  // optional ground/gamepad; write look @ client+0x250 +0x170
}
```

---

## 4. Residual uncertainty

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Product method name | No |
| R2 | Mode id table English | No (default arm sealed) |
| R3 | Gate flags dictionary | Mild for edge paths |
| R4 | `param_5` unit | Mild |
| R5 | Full decompiler stack-var noise | No — CF stages match |
| R6 | Runtime / diff | No for static seal |

---

## 5. Concrete checks performed

1. Re-decompile `0x009168d0` — matches scaffold raw CF (~400-line body).
2. `read_memory` entry: `push ebp; mov ebp,esp; and esp,-16; SEH; sub esp,0xC8`.
3. `read_memory` epilogue region: SEH teardown + **`ret 0x14`**.
4. `get_function_by_address`: body `009168d0`–`00917603`.
5. Callers: only `FUN_0091ce80`; callee list includes dualed `00916090`.
6. Caller decompile: switch default → this VA; other modes branch away.
7. Constants via `read_memory`: `1.5`, `3.5`, `12.0`, `0.2`, `~10000`, `0.05`, `1.0`, `-1.0`.

---

## 6. Falsifications locked in

- **Reject** labeling as mode-1 exclusive or free-look-only without default-arm evidence.
- **Reject** thiscall / `ret` without `0x14` cleanup.
- **Reject** equating collision path to terrain-height-only helper.
- **Reject** inventing a float return; side effects are bus/object stores.
