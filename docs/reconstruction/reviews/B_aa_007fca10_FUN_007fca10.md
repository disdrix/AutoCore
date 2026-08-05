# Review B (skeptical / adversarial): `FUN_007fca10` @ `0x007fca10`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fca10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (wave3 dual — UF-010 invoker host) |
| **Counterpart** | `reviews/A_aa_007fca10_FUN_007fca10.md` |
| **Verdict** | **accept-with-gaps** on invoker CF; **do not** rename without RTTI; **do not** claim mission-only or cancel-safe |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This function *is* FlushPreparedResponse | Body never touches `+0x650` or send size; it only virtual-calls `+0x440` | **Attack succeeds as distinction** — host ≠ Flush. Correct framing: **invoker**. |
| 2 | Always flushes 0x206E | Only if EAX is mission dialog class with prepared opcode; many other callers | **Survives as conditional** — mission path only when dialog is that class + Prepare ran |
| 3 | `+0x440` is always Flush | Other UI classes install different vtables | **Survives with scope** — Flush proven only for vtable `0x00a4a51c` |
| 4 | Visible gate guarantees dialog still prepared | `+0x3d8` is UI-live, not "packet ready" | **Partial** — gate is visibility, not opcode |
| 5 | HideMissionDialogIfOpen also uses this | Hide uses `+0x107c` and different slots | **Hide is not invoker** — confirmed |
| 6 | Close button never reaches Flush | `FUN_008aec40` case 40000 → this → `+0x440` | **Falsified** — close does reach Flush path (UF-011) |
| 7 | Name should be Client_CloseVisibleDialog | No string/RTTI; leave-FUN policy | **Rename deferred** — informal alias only |
| 8 | Table scan is part of Flush | Scan runs **after** `+0x440` | **Flush not gated by scan** — sealed |

---

## 2. What the evidence actually proves

| Fact | Strength |
|---|---|
| Function calls `*(dialog+0)+0x440` after `+0x3d8` truthy | **Proven** (decompile ≡ raw) |
| Gates require `client+0xf40` and non-null EAX | **Proven** |
| For vtable `0x00a4a51c`, slot `+0x440` is `0x008ab8f0` | **Proven** (`read_memory` + math) |
| `FUN_008aec40` / `FUN_008af020` call this after dialog events | **Proven** (decompile) |
| Close `0x9c40` uses same LAB → this without HandleButton fill | **Proven** |
| High generic fan-in (not mission-only) | **Proven** (xrefs) |
| This never clears `+0x650` | **Proven** (no reference) |

| Fact | Strength |
|---|---|
| Live accept always hits this with EAX=mission dialog | **High static / runtime open** |
| `+0x3d8` product name IsVisible | **Probable only** |
| Every non-mission `+0x440` is "close" | **Unproven** (class-specific) |
| Cancel is safe | **Falsified risk** (UF-011) |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| This is the static invoker of Flush's virtual slot | **High** | Miss force-send path |
| Order: visible then `+0x440` | **High** | Wrong gate model |
| Mission slot target `0x008ab8f0` | **High** | Wrong send site |
| Mission dispatch → this | **High (static)** | Accept never flushes |
| Host is mission-only | **Falsified** | Over-narrow docs |
| Cancel-safe | **Low** | Spurious 0x206E |
| Rename to product CloseVisibleDialog | **Reject until RTTI** | False product name |

---

## 4. Surviving contract for AutoCore

```
Generic close host FUN_007fca10 @ 0x007fca10
  Inputs: EAX = dialog*, EBX = client*
  if client+0xf40 && dialog && dialog.vtbl+0x3d8():
    dialog.vtbl+0x440()     // mission class → FlushPreparedResponse
    // then detach / exclusive-dialog scan / restore — AFTER flush

Mission force-send path (UF-010 static):
  FUN_008aec40 / FUN_008af020
    → FUN_007fca10
      → vtbl+0x440 @ client+0x1058 / vtable 0x00a4a51c
        → Client_MissionDialog_FlushPreparedResponse @ 0x008ab8f0

Close (0x9c40) also reaches this host without HandleButton body fill.
This host does not clear dialog+0x650 (UF-011 residual elsewhere).
Do NOT equate HideMissionDialogIfOpen with this invoker.
```

---

## 5. Open questions (must not be papered over)

1. ~~Does anything call vtbl+0x440 for Flush besides this host?~~ **No other code xref to Flush body** (DATA-only); this is the known force-send invoker.
2. Runtime: EAX always mission dialog on accept? (static yes via dialog event `this`)
3. UF-011: clear `+0x650` on cancel? (**Not here.**)
4. Product names for parent fields / `+0x3d8`.
5. What is table index `0x16` reserved for?

---

## 6. Verdict

**accept-with-gaps.**

Adversarial position: **UF-010's missing invoker is sealed at static level** — decompile-proven path event dispatch → `FUN_007fca10` → `vtbl+0x440` with mission slot proven by memory. Do **not** rename. Do **not** claim mission exclusivity or cancel safety. UF-011 remains open on Flush/Prepare, not on this host's body.
