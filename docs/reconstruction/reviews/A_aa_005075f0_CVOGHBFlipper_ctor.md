# Review A (reconstruction fidelity): `aa_005075f0` CVOGHBFlipper_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005075f0` |
| **VA** | `0x005075f0` |
| **Canonical name** | `CVOGHBFlipper_ctor` (inferred) |
| **Ghidra symbol** | `FUN_005075f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005075f0_CVOGHBFlipper_ctor.md` |
| **System** | `heartbeat` / `physics` (flipper constraint HB) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGHBBase`-derived **flipper** heartbeat constructor. Builds the HB, attaches owner object, once-inits a companion **flipper constraint object** (`FUN_00600140`, heap size `0x50`), stores it at `this+0x24`, then **registers** it into the sim via `FUN_0055fe50` (world from vehicle map `+0xe4a4`). Fail-null path logs the plate string:

> `Crazy null checking on the flipper has failed! v:%u m:%u w:%u f:%u`

Re-entry guard on host `+0x102`: if already set, tears down the partially-constructed HB via `FUN_005083f0(this, 0, 0)` and returns `this` without building the constraint.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005075f0_FUN_005075f0.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_005075f0_FUN_005075f0.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005075f0.cpp` | CF ≡ raw |
| Named alias | `Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoLogic_005075f0.cpp` | Prior scaffold |
| Function record | `docs/reconstruction/functions/aa_005075f0_FUN_005075f0.md` | Scaffold |
| Live decompile | Ghidra MCP `batch_decompile` `0x005075f0` | **≡ raw** |
| Live `read_memory` | entry + `DAT_00af18e0` block | axis tables + `0.1f` sealed |
| Downstream duals (this batch) | `00600140`, `0055fe50`, `005083f0` | Same wave |
| Prior | `fn_004fb660_createVehicleAction` (register path) | `FUN_0055fe50` role |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=`this` (HB storage); stack: host `param_2`, tag `param_3`; `ret 8` | **High** | Prologue `C2 08 00` path in early return; two stack args |
| `CVOGHBBase_ctor` then vtbl `PTR_FUN_009cda10` | **High** | Decompile + store |
| Re-entry: `host+0x102 != 0` → `FUN_005083f0(this,0,0)` + return | **High** | Asm `cmp [edi+0x102]`; dual-zero push |
| Else: attach owner, set `host+0x102=1`, period `(1,true)` | **High** | Callees sealed names |
| Fields: `this[2]=param_3`, `this[10]=host`, `this[9]=0` then constraint | **High** | dword indices ×4 → `+0x08/+0x28/+0x24` |
| Host vcall `(*host)+0x28` before build | **High** | Decompile |
| Axis select via vehicle mode `+0x4ce == 2` → `DAT_00af1900` else `DAT_00af18f0` | **High** | Same mode byte as VehicleAction analog path |
| Alloc `(0x50, 0x24)` via `DAT_00b05060` vtbl+0x10; tag word `0x50` at `+4` | **High** | Decompile + imm |
| Placement-new `FUN_00600140` with `host+8`, axis A=`DAT_00af18e0`, axis B=selected, float **`0.1f`** (`0x3dcccccd`) | **High** | `read_memory` on table; float imm |
| Null-check chain host / map(`host` MSVC layout `+0xa8`) / `map+0xe4a4` / constraint → `FUN_0055fe50` | **High** | Fail → `FUN_007a4480` log |
| English “flipper” | **High** | Embedded string |
| Product / PDB name | **Probable** | Ghidra still `FUN_*` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH frame + `CVOGHBBase_ctor` + derived vtbl | Yes |
| Re-entry early teardown | Yes |
| Attach / flag / period / field seeds / host vcall `+0x28` | Yes |
| Optional axis pack from mode `+0x4ce` | Yes |
| Alloc `0x50` + `FUN_00600140` + store `this+0x24` | Yes |
| Null gate → register **or** log fail | Yes |
| Always returns `this` (constructed storage) | Yes |

### Constant seal (`read_memory` `0x00af18e0`, 64 B)

| Addr | Floats (f32 LE) | Role |
|---|---|---|
| `DAT_00af18e0` | `(0, 1, 0, 0)` | Axis A (always) |
| `DAT_00af18f0` | `(0, 0, 1, 0)` | Axis B default (`+0x4ce ≠ 2`) |
| `DAT_00af1900` | `(1, 0, 0, 0)` | Axis B analog mode (`+0x4ce == 2`) |
| Imm | `0x3dcccccd` = **0.1f** | Last ctor scalar (limit/scale) |

---

## 5. Callers / callees

**Callees:** `CVOGHBBase_ctor`, `CVOGHBBase_AttachOwnerObject`, `CVOGHBBase_SetPeriodAndCounter`, `FUN_005083f0`, `FUN_00600140`, `FUN_0055fe50`, `FUN_007a4480`, host vtbl `+0x28`, allocator `DAT_00b05060` `+0x10`.

**Callers (Ghidra):** `FUN_005d73f0`, `FUN_0091d660`, `FUN_00950300` (incl. debug slash `forceflipper` neighborhood).

---

## 6. Gaps / open

1. Exact product type name for constraint at `FUN_00600140` / RTTI near `DAT_00af18e0+0x30`.
2. Semantics of host vtbl `+0x28` pre-build call.
3. Full meaning of log fields `v/m/w/f` beyond null components.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF, re-entry, axis tables, `0.1f`, register/fail path sealed; package not complete (RTTI, runtime).
