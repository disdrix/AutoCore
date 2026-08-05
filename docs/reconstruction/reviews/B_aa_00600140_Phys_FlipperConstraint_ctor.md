# Review B (skeptical / adversarial): `aa_00600140` Phys_FlipperConstraint_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00600140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00600140_Phys_FlipperConstraint_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Allocates its own `0x50` heap | Miss placement | **Falsified** — pure placement ctor; alloc is in flipper |
| 2 | Identity matrix init | Assume | **Falsified** — copies caller axes; flipper uses unit axis tables |
| 3 | `param_5` is 1.0f / gravity | Guess | **Falsified at call site** — flipper pushes **`0.1f`** |
| 4 | Multiple independent callers | | **Falsified** — sole xref `FUN_005075f0` |
| 5 | Same as VehicleAction ctor | Size/family mix | **Falsified** — different VA/vtbl; VehicleAction is separate path |
| 6 | Secondary vtbl at `+0` only | | **Falsified** — **two** installs: `+0` and `+8` |
| 7 | `param_6` sealed as 0 | Decompiler quiet | **Not sealed** — stack artifact risk; do not invent |
| 8 | Name PDB-proven | | **Not sealed** — Probable from flipper-only use |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement + dual vtbl | **High** | Wrong object shape |
| Axis offsets `+0x20/+0x30` | **High** | Wrong hinge axes in port |
| `+0x40` float from caller | **High** | Wrong limit/scale (must be 0.1f from flipper) |
| `+0x44` second float | **Low–Med** | Unknown default |
| Base `00636370` fields | **Low** | Incomplete layout |
| Product name | **Medium** | Doc |

---

## 3. Cross-check against raw

```text
// raw ≡ live
FUN_00636370(this, context);
*this = 0x009de0cc;
*(this+8) = 0x009de0b8;
memcpy(this+0x20, axisA, 16);
memcpy(this+0x30, axisB, 16);
*(float*)(this+0x40) = f5;
*(float*)(this+0x44) = f6;
return this;
```

Caller flipper:

```text
p = alloc(0x50); *(u16*)(p+4) = 0x50;
FUN_00600140(p, host+8, &DAT_00af18e0, &axisB, 0.1f, ?);
```

---

## 4. Surviving contract for AutoCore

```
Phys_FlipperConstraint_ctor(this /*0x50*/, context, axisA*, axisB*, fLimit, fExtra):
  BaseConstraint_Init(this, context)     // FUN_00636370
  this.vtbl = FlipperVtbl_009de0cc
  this.vtbl2(+8) = 009de0b8
  this.axisA(+0x20) = *axisA             // typically (0,1,0,0)
  this.axisB(+0x30) = *axisB             // (0,0,1,0) or (1,0,0,0)
  this.f0(+0x40) = fLimit                // 0.1f from flipper
  this.f1(+0x44) = fExtra
  return this
```

**Port tests:**

* No internal alloc.
* Must accept external axes (not hardcode only Y).
* Flipper path must pass **0.1f** into `+0x40`.

---

## 5. Open questions

1. `param_6` exact bits from flipper push sequence.
2. Dual `FUN_00636370` + full 0x50 field map.
3. Vtbl method inventory (`009de0cc`) — especially collect `+0x18` for `Phys_RegisterAction`.

**Verdict:** **accept-with-gaps**
