# Annotated low-level: CVOGHBAICreatureBase_DoMovement (`aa_005cd3b0`)

| Field | Value |
|---|---|
| Stable ID | `aa_005cd3b0` |
| VA | `0x005cd3b0` – `0x005ce989` |
| Product name | `CVOGHBAICreatureBase::DoMovement` (string @ `0x009da8a8`) |
| System | combat / AI creature movement (HB) |
| Date | 2026-07-29 (dual W16-I) |

## Machine-level notes

- **Prologue (image):** `push ebp; mov ebp,esp; and esp,0xfffffff0` — 16-byte align; SEH cookie `LAB_009a6f98`; `sub esp,0xe8`; save ebx/esi/edi; **`mov esi,ecx`** (this); push string **`0x009da8a8`** (`"CVOGHBAICreatureBase::DoMovement"`) and call **`FUN_0076cf00`** (scope enter). Epilogue **`FUN_0076cef0`** + restore ExceptionList.
- **ABI:** `__thiscall` ECX = AI controller (`CVOGHBAICreatureBase*`-family); stack `float dt` (`param_2`).
- **Host entity:** `this[0x19]` = `*(this+0x64)`.
- **Early outs:**
  1. `this[6] == 0` (`this+0x18`) → cleanup return.
  2. If `(float)this[0xd] != 0` (`this+0x34` duration): if `tickMs*msToSec - this[0xe] < duration` → return.
  3. If `entity[0x94] != 0` **and** component type `@ chain+0x38 != 0x14` → return.
- **NaN trap:** if position/delta/sqrt paths fail `_isnan` cascade → `FUN_007a4480(0,"VOG_DEBUG_STOP")` then cleanup. **Not** the method name.
- **Physics writers (owned sites only as callers of dualed leaves):**
  - `CVOGPhysics_ApplyImpulseVector` (multiple)
  - `FUN_0040d2a0` SetPosition, `FUN_00404dc0` SetRotation, `FUN_0040d040` SetAngularVelocity
  - `FUN_004cb3e0` **ungated** store local pos `@+0x240` (bypass vs gated `004c3a40`)
- **Speed scale:** `FUN_004c55e0`; optional clamp via `DAT_00a0f298` (0.5) when host `+0x279` set.
- **Dispatch:** **vtable DATA xrefs only** (5 slots) — virtual `DoMovement`; no direct `CALL` xrefs found.

## Gate map (high confidence CF)

| Gate | Condition | Effect |
|---|---|---|
| Link | `this+0x18 == 0` | skip all work |
| Timer | duration `this+0x34 != 0` and elapsed < duration | skip |
| Type/flag | entity `+0x250` path type ≠ `0x14` when flag `entity[0x94]!=0` | skip |
| Vertical step | `local_y - terrain_y` vs `DAT_00a0f718` (0.01) | climb vs grounded branch |
| State bytes | host `+0x304/+0x308/+0x314` | impulse damp / teleport / landing |
| Lerp window | host `+0x10` set and tick delta ≤ `0x18ff` (6399 ms) | blend path vs terrain snap |

## Constants (read_memory)

| Symbol / imm | Value |
|---|---|
| `DAT_00a0f718` | **0.01f** |
| `DAT_009da864` | **~1.192e-7** (eps) |
| `DAT_009da8a0` | **-14.0f** |
| `DAT_009da8a4` | **3.5f** |
| `DAT_00a0f298` | **0.5f** |
| `DAT_00af418c` / `DAT_00a110d8` | **10.0f** |
| `DAT_00af4188` | **2.5f** |
| `DAT_00aaa668` | **-1.0f** |
| vtbl-ish imm `0x3e4ccccd` | **0.2f** |
| `0x3d4ccccd` | **0.05f** |
| `0x3dcccccd` | **0.1f** |
| `0x18ff` | **6399** ms window |

## Pseudocode

See live decompile in raw (full ~530 lines) and clean `CVOGHBAICreatureBase_DoMovement.cpp`. Dual reviews seal gate inventory + callee roles; not every float stack temporary is re-typed.

## Open questions

- Full C++ layout of `CVOGHBAICreatureBase` beyond offsets touched here.
- English for host flags `+0x304/+0x306/+0x308/+0x314`.
- Which vtable owner classes share the 5 DATA slots.
- Runtime / differential movement under live NPCs.
