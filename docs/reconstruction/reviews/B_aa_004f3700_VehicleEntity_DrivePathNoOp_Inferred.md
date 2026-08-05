# Review B (skeptical / adversarial): `aa_004f3700` VehicleEntity_DrivePathNoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3700` |
| **VA** | `0x004f3700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create**) |
| **Counterpart** | `reviews/A_aa_004f3700_VehicleEntity_DrivePathNoOp_Inferred.md` |
| **Scratch** | `reviews/a_004f3700.md` |
| **Verdict** | **accept-with-gaps** — empty body + call graph sealed; product name open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Real drive-axis work (thr/steer/HB) | Would invent setters | **Falsified** — body is `c3` only; axes live at sibling VAs |
| 2 | Hidden multi-byte body / thunk | Decompiler elision | **Falsified** — `read_memory` + disassemble = single `ret`; pad is `cc` |
| 3 | `ret 4` / stack arg ABI | Misread as SetHandbrake twin | **Falsified** — opcode `c3` not `c2 04 00`; no stack pop |
| 4 | Body uses `this` / writes entity | “Hook does work” | **Falsified** — no memory/reg ops |
| 5 | Always post-`SetHandbrake(1)` only | Overfit HB narrative | **Partially falsified as exclusive** — 3/4 sites yes; `FUN_0093e120` calls without HB arm |
| 6 | Same as `PushDriveAxesToController` | Confuse next callee | **Falsified** — Push is `0x004fbc10`; separate CALL at callers |
| 7 | Same as `SetFlag_109` / hard-stop | Offset-cluster confusion | **Falsified** — SetFlag is store at `0x004f3630` |
| 8 | No callers / dead code | Drop from drive map | **Falsified** — **4** live unconditional CALL sites |
| 9 | Canonical name is product-sealed | Over-promote | **Sustained risk** — keep `_Inferred`; no string/RTTI |
| 10 | Scaffold “~4 decompiler lines” implies logic | Auto CF noise | **Falsified** — only empty `return` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Machine body `c3` | **High** | Invented drive logic |
| Zero stack args | **High** | Wrong ABI / stack imbalance myth |
| ECX = vehicle at sites | **High** | Wrong this type |
| Body ignores this | **High** | Fake side effects in port |
| Caller count = 4 | **High** | Missed stop-path port sites |
| “Post-HB only” exclusive | **Medium–High falsified** | Overfit port ordering |
| Product English name | **Low / Open** | Wrong NAMING promote |
| Historical stripped-hook story | **Tentative** | Doc color only |

---

## 3. Cross-check against raw + bytes

```
// clean ≡ raw ≡ machine
// 0x004f3700: c3
void VehicleEntity_DrivePathNoOp_Inferred(VehicleEntity* /*this*/)
{
  return;   // no-op in this image
}
```

Live `force_decompile` 2026-07-29 ≡ frozen raw empty function ≡ `read_memory` `c3`.

Neighbor contrast (not this VA’s body):

| VA | Role |
|---|---|
| `0x004f3620` | `SetHandbrake` store `+0x61c`, `ret 4` |
| `0x004f3630` | `SetFlag_109` store `+0x109`, `ret 4` |
| `0x004f3700` | **this** — pure `ret` |
| `0x004fbc10` | `PushDriveAxesToController` (caller often next) |

---

## 4. Surviving contract for AutoCore

```
VehicleEntity_DrivePathNoOp_Inferred(entity):
  // retail body: RET only — safe no-op
  // Call sites (static):
  //   DriveControlTick @ 009235e4  after SetHandbrake(1) on brake arm
  //   FUN_00915670     @ 009156b9  HB1 path then PushDriveAxes
  //   FUN_0093a5c0     @ 0093a5ff  focus-loss HB1 path
  //   FUN_0093e120     @ 0093e20e  vehicle non-null (no HB in arm)
  // Port: may omit CALL entirely OR keep empty stub for call-graph parity
  // Do NOT invent thr/steer/HB/controller writes here
```

**Port tests that matter:**

* Omitting this CALL must not change axes (body is empty).
* Do not merge into SetHandbrake or PushDriveAxes.
* If a future build gains a real body, re-dual this VA (do not assume forever-empty).

---

## 5. Open questions

1. Runtime / differential (policy) — empty but still on hot brake path.
2. PDB / retail symbol.
3. Shared design intent across HB arms vs `FUN_0093e120` select path.
4. Whether any **data** xref / vtbl slot also points here (code xrefs sealed at 4 CALLs only this pass).

**Verdict:** **accept-with-gaps** — adversarial attacks on hidden body, axis writes, `ret 4` twin, and dead-code claim **closed**; product name + exclusive post-HB story + historical intent remain open.
