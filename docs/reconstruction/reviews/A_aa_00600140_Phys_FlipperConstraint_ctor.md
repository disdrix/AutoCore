# Review A (reconstruction fidelity): `aa_00600140` Phys_FlipperConstraint_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00600140` |
| **VA** | `0x00600140` |
| **Canonical name** | `Phys_FlipperConstraint_ctor` (inferred) |
| **Ghidra symbol** | `FUN_00600140` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00600140_Phys_FlipperConstraint_ctor.md` |
| **System** | `physics` (flipper / hinge-like constraint object) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Placement constructor for the **0x50-byte** object allocated by `CVOGHBFlipper_ctor` (`0x005075f0`). Sole Ghidra caller: that flipper HB ctor.

Body:

1. Base init `FUN_00636370(param_2)` — `param_2` is `host+8` from flipper (owner/context).
2. Install vtbls: `*this = PTR_FUN_009de0cc`, `this+0x08 = PTR_LAB_009de0b8`.
3. Copy **axis A** (4 dwords / vec4) from `param_3` → `this+0x20 .. +0x2c`.
4. Copy **axis B** (4 dwords) from `param_4` → `this+0x30 .. +0x3c`.
5. Store scalar **`param_5`** at `this+0x40` (SSE `movss`), **`param_6`** at `this+0x44`.
6. Return `this`.

Flipper call site constants (`read_memory` + imm):

| Arg | Source | Value |
|---|---|---|
| storage | heap `0x50` | tagged `+4 = 0x50` |
| context | `host+8` | owner field |
| axis A | `DAT_00af18e0` | `(0, 1, 0, 0)` |
| axis B | `DAT_00af18f0` or `DAT_00af1900` | `(0,0,1,0)` or `(1,0,0,0)` by mode `+0x4ce` |
| param_5 | imm | **`0.1f`** (`0x3dcccccd`) |
| param_6 | stack residual / decompiler `uStack_44` | **caller-dependent** (may be uninitialized in decompiler view — treat carefully) |

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00600140_FUN_00600140.md` | ≡ live |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00600140.cpp` | CF ≡ raw |
| Live decompile | Ghidra MCP `0x00600140` | **≡ raw** |
| Live `read_memory` | body | vtbl stores + SSE float stores sealed |
| Caller dual | `A_aa_005075f0` | Alloc size, axes, 0.1f |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=`this` (0x50 storage); returns `this` | **High** | |
| Base `FUN_00636370(context)` first | **High** | |
| Primary vtbl `0x009de0cc`, secondary at `+8` `0x009de0b8` | **High** | Imm in bytes |
| Axis A → `+0x20` (4×u32) | **High** | |
| Axis B → `+0x30` (4×u32) | **High** | |
| Float `+0x40` / `+0x44` via `movss` | **High** | |
| Sole caller flipper ctor | **High** | Ghidra callers |
| Object is “flipper constraint / action-like” | **Probable** | Registered via `FUN_0055fe50`; size 0x50 |
| `param_6` exact retail value from flipper | **Tentative** | Decompiler shows messy stack (`uStack_44`); need caller asm for second float |
| Product RTTI name | **Tentative** | Nearby RTTI fragment near axis DAT |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| Base ctor with context | Yes |
| Dual vtbl install | Yes |
| Copy 8 dwords axes | Yes |
| Two float stores | Yes |
| Return this | Yes |
| No heap alloc inside (placement) | Yes |

### Layout (sealed subset)

| Offset | Content |
|---|---|
| `+0x00` | vtbl `PTR_FUN_009de0cc` |
| `+0x08` | vtbl/secondary `PTR_LAB_009de0b8` |
| `+0x20` | axis A xyzw |
| `+0x30` | axis B xyzw |
| `+0x40` | float param_5 (0.1f from flipper) |
| `+0x44` | float param_6 |

Base `FUN_00636370` may fill lower fields (`+0x04`..`+0x1c` etc.) — not re-derived here.

---

## 5. Callers / callees

**Callees:** `FUN_00636370` only.

**Callers:** `FUN_005075f0` only.

---

## 6. Gaps / open

1. Dual / purpose of base `FUN_00636370`.
2. Exact `param_6` from flipper call site (asm of pushes).
3. RTTI / true class name; method meanings on `009de0cc`.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — placement CF, vtbls, axis/float field map, sole-caller link sealed; base ctor + second float residual.
