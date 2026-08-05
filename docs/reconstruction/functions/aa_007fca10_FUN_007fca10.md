# Function record: FUN_007fca10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fca10` |
| **Canonical name** | `FUN_007fca10` (leave-FUN; no string/RTTI) |
| **Informal alias** | CloseVisibleDialog / Flush invoker host (docs only) |
| **Address** | `0x007fca10` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` (generic UI; mission path is primary consumer for UF-010) |
| **Calling convention** | Custom: dialog in **EAX**, client host in **EBX** (decompiler `void FUN_007fca10(void)`) |
| **Completion status** | **Human-refined dual unit** — CF for Flush invoke sealed static 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (runtime not required for static seal) |

## Purpose

Generic host that closes a **visible** UI/dialog object: gate on `vtbl+0x3d8`, then invoke **`vtbl+0x440`**, then client-side detach / exclusive-dialog scan / optional restore.

For the **NPC mission dialog** (`client+0x1058`, vtable `0x00a4a51c`), slot `+0x440` is **`Client_MissionDialog_FlushPreparedResponse`** @ `0x008ab8f0` — the C2S **0x206E** send site. This unit is the **UF-010 static invoker** of that virtual method.

## Signature (decompiler-derived)

```c
void FUN_007fca10(void);
// live: EAX = dialog*, EBX = client*
```

## Sealed control flow — when Flush runs

```
if (*(client+0xf40) != 0 && dialog != null):
  if dialog.vtbl+0x3d8() != 0:          // visible
    dialog.vtbl+0x440()                 // ★ FlushPreparedResponse for mission class
    optional parent vtbl+0xb0
    scan client[+0x1030 .. +0x3a slots), skip index 0x16
      if other visible && obj[0x140]==1: skip restore
      else optional (client+0xf38).vtbl+0x3c4(...)
    optional (client+0x10b0)+0x664 → vtbl+0x47c
```

| Gate | Meaning | Confidence |
|---|---|---|
| `client+0xf40 != 0` | Parent/UI root present | High (offset); name Tentative |
| `dialog != null` | Object to close | High |
| `vtbl+0x3d8 != 0` | Visible/live predicate | High (call); name Probable |
| **`vtbl+0x440`** | Class-specific close; mission → Flush | **High** |

## Mission-dialog binding (UF-010)

| Item | Value | Evidence |
|---|---|---|
| Host field | `client+0x1058` | Show / UI init (prior chain) |
| Table index | **10** = `(0x1058-0x1030)/4` | arithmetic |
| Vtable base | `0x00a4a51c` | ctor `FUN_008ac3f0` |
| Method offset | **`+0x440`** | base + offset math |
| DATA slot | `0x00a4a95c` | `0x00a4a51c+0x440` |
| Slot target | **`0x008ab8f0`** | `read_memory` LE `f0 b8 8a 00` |
| Target name | `Client_MissionDialog_FlushPreparedResponse` | dual `aa_008ab8f0` |

## Mission-path callers

| Caller | Address | Call condition |
|---|---|---|
| `FUN_008aec40` | `0x008aec40` (site `0x008aef96`) | HandleButton success on `0x9c46..0x9c4d` **or** close `0x9c40` / case 40000 |
| `FUN_008af020` | `0x008af020` | HandleButton(0) success |
| (fan-in) | 100+ xrefs | Generic UI close — not mission-only |

**Not a caller of Flush via this path:** `Client_HideMissionDialogIfOpen` @ `0x0092ce50` (different host field `+0x107c`).

## UF-010 / UF-011 relation

| ID | Relation to this unit | Status after this dual |
|---|---|---|
| **UF-010** | Lifecycle that reaches Flush vtable slot | **Static invoker sealed here** — dispatch → this → `+0x440`; runtime still open |
| **UF-011** | Cancel-clear of `+0x650` before flush | **Not owned here** — this host never touches `+0x650`; residual on Flush/Prepare |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007fca10_FUN_007fca10.md` |
| Annotated | `docs/reconstruction/raw/aa_007fca10_FUN_007fca10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fca10.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_007fca10_FUN_007fca10.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_007fca10_FUN_007fca10.md` |
| Downstream Flush | `functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| Chain | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| `+0x3d8` gate then `+0x440` call order | **High** |
| Mission `+0x440` = Flush @ `0x008ab8f0` | **High** (`read_memory` + prior dual) |
| Mission dispatch → this (008aec40 / 008af020) | **High (static)** |
| Generic multi-caller close host | **High** (xref fan-in) |
| Register EAX/EBX convention | **High** (decompiler); formal ABI name Tentative |
| `+0xf40` / `+0xf38` / `+0x10b0` product types | Tentative |
| Table skip `0x16` / `[0x140]==1` semantics | Probable |
| Runtime accept → this → Flush | Open (static sealed only) |

## Open questions

1. Product names for parent slots (`+0xf40`, `+0xf38`, `+0x10b0`) and `vtbl+0x3d8`.
2. Why index `0x16` is skipped in the exclusive-dialog scan.
3. Whether every `FUN_008aec40` path loads mission dialog into EAX (inferred from dialog `this` event context — Probable/High for dialog-owned handler).
4. UF-011 clear policy (out of scope for this VA).
