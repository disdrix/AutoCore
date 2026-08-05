# Review B (skeptical / adversarial): `aa_004f5620` VehicleEntity_SetSteerInput

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh) |
| **Counterpart** | `reviews/A_aa_004f5620_VehicleEntity_SetSteerInput.md` |
| **Scratch** | `reviews/a_004f5620.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Also writes thr / HB | Wrong axis layout | **Falsified** — only `+0x618` |
| 2 | Always writes | No gate | **Falsified** — null-or-`0xC7` suppress |
| 3 | Applies steer ramp / DI curve | Overfit reconstruction | **Falsified** — raw store only |
| 4 | Mask `199` is decompiler fiction | Trust only hex | **Falsified** — imm8 `0xC7` in `test byte` |
| 5 | Deadband / SetSteerInput bypasses gate | Stale drive-controller-spec | **Falsified** — callee applies gate; proportional reimplements same mask |
| 6 | NPC inline gate is a different chain | Spec parenthesization drift | **Falsified** — live `0x4fc650` same `*(*(*(this+4)+4)+this+0xb0)` |
| 7 | All `+0x618` writers are gated | System parity | **Falsified as universal** — SetDriveAxes / setDrivingInputs store ungated |
| 8 | PushDriveAxes copies steer | Consumer mis-map | **Falsified** — thr/HB only |
| 9 | Soft L/R signs are properties of this fn | Plate attachment | **Falsified** — caller-owned values |
| 10 | “Lock” bit meanings sealed | Semantic inflation | **Not sealed** — mask proven; producers open (**no UF invent**) |
| 11 | Instruction seal needs runtime unit test | Static insufficient? | **Static High** for CF; runtime remains policy-open only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x618` layout / store | **High** | No steer axis |
| Suppress gate CF + mask imm | **High** | Stuck / free steer under suppress |
| Sibling parity (`+0x614`) | **High** | Divergent thr lock story |
| MoveToTarget chain/bit identity | **High** | AI steer ignore lock |
| Caller list (6) | **High** | Incomplete stop/AI packs |
| Ungated bypass writers | **High** | Network force-steer wrong under “always gate” port |
| applyAction consumer | **High** | Steer never reaches wheels |
| `wobj` type / bit producers | **Low–Med** | Naming / full suppress parity only |
| Soft L/R plate polarity | **Medium** (caller docs) | Input feel only |

---

## 3. Cross-check against raw

```
wobj = *(*(*(this+4)+4) + this + 0xb0);
if (wobj==0 || (*(u8*)(wobj+0xb4) & 0xC7)==0)
    *(f32*)(this+0x618) = steer;
// clean ≡ raw ≡ read_memory 2026-07-29
```

Instruction-level mask and store offset close prior residual R1 (body size / imm not re-measured).

---

## 4. Surviving contract for AutoCore

```
SetSteerInput(entity, steer):
  // gated steer axis only
  wobj = *(*(*(entity+4)+4) + entity + 0xb0);
  if (wobj==null || (wobj.flags_u8(+0xb4) & 0xC7)==0)
      entity.steer(+0x618) = steer;
  // else retain

// Pair: SetLongitudinalInput → +0x614 (identical gate)
// Contrast: SetHandbrake → +0x61c (ungated)

// Same gate, alternate sites:
//   MoveToTarget proportional: inline store +0x618 under same chain/bits
//   MoveToTarget deadband: calls this setter

// Bypass (ungated +0x618):
//   SetDriveAxes, setDrivingInputs  — network / bundled API

// Consumer:
//   applyAction ramps VA+0x24 toward entity+0x618
//   PushDriveAxes does NOT copy steer
```

**Port tests that matter:**

* Under any `0xC7` bit set on non-null `wobj`, setter and MoveToTarget proportional must **not** change `+0x618`.
* SetDriveAxes / ghost setDrivingInputs **must still** write `+0x618` (bypass).
* Setter must not clamp; must not touch thr/HB.
* Intermediate null `p0`/`p1` is undefined (fault) — pure models that only null-check final `wobj` are gate-predicate models, not full chain emulators.

---

## 5. Open questions

1. Runtime / differential under forced `wobj+0xb4` (matrix policy) — not dual residual.
2. Producers of `0xC7` bits / `wobj` type (**UF open — not invented this pass**).
3. Full English naming of `FUN_00636ba0` / stop-pack callers.
4. Exhaustive residual scan of every `+0x618` store (optional).
5. Soft L/R DriveControlTick polarity plate consistency (caller unit).

**Verdict:** **accept-with-gaps** — adversarial residuals on **gate chain, mask immediate, sibling/MoveToTarget identity, bypass writers, and consumers** **closed**; runtime + UF bit-story remain open.
