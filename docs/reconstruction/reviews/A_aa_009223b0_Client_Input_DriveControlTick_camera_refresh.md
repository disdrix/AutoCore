# Review A refresh: DriveControlTick camera look-offset (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **Counterpart** | B camera refresh |
| **Scope** | Camera / look-offset residual only — **not** a full-function re-dual; **not** soft-steer dual body |
| **Evidence pass** | Live Ghidra re-decompile `0x009223b0` + `read_memory` DAT floats (2026-07-29 strengthen) |
| **Verdict** | **accept-with-gaps** (locals-vs-steer CF **High** / sealed structural; component semantics open) |

## Separation claim (strengthened)

Steer and look share **bind triggers** in SECTION 7, but they are **independent side-effects** with different storage, gates, value domains, and consumers.

| Axis of separation | Steer command | Look / camera offset | Confidence |
|---|---|---|---|
| **Storage** | `entity+0x618` (f32) only via `VehicleEntity_SetSteerInput` (`0x004f5620`) | Stack `local_d4`, `local_d0/cc/c8/c4` (never assigned to `+0x614/+0x618/+0x61c`) | **High** |
| **Gate** | DCT: `vehicle+0x101==0`; setter: wobj `0xC7` mask | Look local math **not** gated on `+0x101` | **High** |
| **Value domain (normal digital)** | Hard ±1.0 (`0x3f8…`/`0xbf8…`); soft ±0.5 (`0x3f0…`/`0xbf0…`) | `local_d4` seed `1.0`; hard step ±**0.03**; soft step ±**0.2** | **High** |
| **Consumer** | `applyAction` / physics (reads `+0x618`); Push does **not** send steer | Normalize → `FUN_0091a5f0(local_d4, &local_d0)`; SECTION 15 world slots; optional `pClient+0xa86` | **High** CF |
| **Analog SECTION 3** | Drive path: `SetLongitudinal` + `SetSteerInput` when vehicle and `+0x101==0` | Non-drive path (no vehicle **or** `+0x101!=0`): **only** `local_d*` + `pClient` vtbl `+0x44c` — **no** axis setters | **High** CF |

**Anti-confusion (UF-006 vs camera):** soft-steer body immediates ±**0.5** write **steer** `+0x618`. Soft look steps ±**0.2** (`DAT_00a0f70c`) adjust **`local_d4` only**. Do not merge these constants.

## Bind-site interleave matrix (SECTION 7)

Each hard/soft branch may do **both** (steer gated; look un-gated). Live decompile ≡ clean ≡ prior raw for this order.

| Bind | Flag DAT | Steer (if `+0x101==0`) | Look side-effect (normal mode: `DAT_00d1b644+0xf5==0` and `DAT_00d1b6d8+0x6b9==0`) |
|---|---|---|---|
| Hard R | `DAT_00d1bcc2` | `SetSteerInput(-1.0)` | `local_d4 -= 0.03`; `local_c8 += 5.0`; `local_d0 += local_a4` |
| Hard L | `DAT_00d1bc8e` | `SetSteerInput(+1.0)` | `local_d4 += 0.03`; `local_c8 += 5.0`; `local_d0 += -local_a4` |
| Soft L | `DAT_00d1bd2a` | `SetSteerInput(-0.5)` | `local_d4 -= 0.2`; `local_d0 += local_a4` (normal) |
| Soft R | `DAT_00d1bcf6` | `SetSteerInput(+0.5)` | `local_d4 += 0.2`; `local_d0 += -local_a4` (normal) |
| Clear | none (+ no analog) | `SetSteerInput(0)` | **no** look update on clear path |

Alternate / combat modes use other tables (`DAT_00aaa878`=0.004, `DAT_00aaa68c`=1.5, etc.) on the **same** `local_d*` sinks — still not `+0x618`.

## Camera locals inventory

| Concern | Storage | DCT writer | Confidence |
|---------|---------|------------|------------|
| Steer command | `entity+0x618` | `SetSteerInput` only | **High** |
| Look scale / aim param | stack `local_d4` | SECTION 1 seed `1.0`; SECTION 3/7 mode tables | **High** CF |
| Look vector | `local_d0, local_cc, local_c8, local_c4` | SECTION 1 seed `DAT_00d1a640..64c`; thr (5–6) + steer (7) side-effects | **High** CF |
| Apply look | `FUN_0091a5f0(local_d4, &local_d0)` | post-steer when look helper `piStack_a8 != 0` | **High** CF |
| Analog camera-only | `pClient` vtbl `+0x44c` | SECTION 3 when no vehicle or `+0x101 != 0` | **High** CF |
| World camera slots | `*(DAT_00d1b644+0xe894) + 0x11c/120/124` | SECTION 15 epilogue | **High** CF |

## SECTION index (camera residual)

| SECTION | Camera residual claim |
|---------|----------------------|
| 1 | Seed look locals; `local_d4 = 1.0`; `local_a4` from `DAT_00aaacc8` (**11.0**) unless mode flag `+0xf5` |
| 3 | Non-drive analog → camera path only (no axis setters); drive analog → setters only (no look apply in that arm) |
| 5–6 | Thr binds update `local_c8` (+ `bVar2`/`bVar3` for later look shaping); thr setters separate |
| 7 | Steer priority unchanged; **interleaved** `local_d4/d0/c8` mode tables |
| 7f+ | Normalize / scale look; `FUN_0091a5f0`; optional `pClient+0xa86` |
| 14 | Push thr/HB only — **not** steer, **not** look locals |
| 15 | Project into world camera floats (independent of `+0x618`) |

## Look constants sealed (`read_memory` reconfirm 2026-07-29)

| DAT | Hex LE | f32 | Typical use |
|-----|--------|----:|-------------|
| `DAT_00aaa8fc` | `8fc2f53c` | **0.03** | hard L/R `local_d4` ± step (normal mode) |
| `DAT_00a0f70c` | `cdcc4c3e` | **0.2** | soft L/R `local_d4` ± step (normal mode) |
| `DAT_00aaa878` | `6f12833b` | **0.004** | alternate-mode `local_d4` step |
| `DAT_00aaa688` | `0000a040` | **5.0** | hard-R/L look add to `local_c8` (normal) |
| `DAT_00aaa68c` | `0000c03f` | **1.5** | special/combat look table |
| `DAT_00aaacc8` | `00003041` | **11.0** | default look step `local_a4` |
| `DAT_00aaacc4` | `0000a0c0` | **−5.0** | reverse special look step |
| `DAT_00aaa664` | `17b7d138` | **1e-4** | `|local_d0|` / `|local_c8|` → `pClient+0xa86` |
| `DAT_00aaa620` | `acc52737` | **1e-5** | near-1.0 test on `local_d4` |

Clean ≡ raw ≡ live decompile for interleave order; constants match image floats (**High** body).

## Sink proof (no look → drive axis)

- `VehicleEntity_SetSteerInput` body: single store to `this+0x618` (gated). No other entity stores.
- DCT never assigns `local_d*` into `*(pVehicle+0x618)` or thr/HB slots.
- Post-steer join **reads** `*(pVehicle+0x618)` for thr-damp when steer≠0 — a **read** of steer, not a look write-back.
- `FUN_0091a5f0` is called with look args only; not used for steer axis store.

## Out of scope this refresh

- Soft-steer UF-006 body / labels (prior soft_analog refresh — do not rewrite here)
- Skills, air-stab, terrain, secondary weapons (UF-003 remainder)
- Full rename of `FUN_0091a5f0` / look-vector axes (yaw/pitch unproven)

## Gaps (accept)

1. Semantic names for `local_d0/cc/c8/c4` components — unproven.
2. Exact product meaning of `local_d4` (scale vs FOV vs blend) — only known as `FUN_0091a5f0` arg0.
3. Complete combat/special mode-table matrix (alternate branches exist; not fully named).
4. `FUN_0091a5f0` deep callee semantics — CF High as look apply; product dual open.
