# Review A (reconstruction fidelity): `aa_005cd3b0` CVOGHBAICreatureBase_DoMovement

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd3b0` |
| **VA** | `0x005cd3b0` – `0x005ce989` |
| **Body span** | **~0x15d9** bytes (large SEH movement tick) |
| **Canonical name** | `FUN_005cd3b0` (Ghidra) |
| **Product name** | **`CVOGHBAICreatureBase::DoMovement`** (**High** — scope string) |
| **Prior scaffold alias** | `Named_VOG_DEBUG_STOP_005cd3b0` — **misleading** (NaN trap string only) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra W16-I) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile + key bytes) |
| **Counterpart** | `reviews/B_aa_005cd3b0_CVOGHBAICreatureBase_DoMovement.md` |
| **System** | combat / AI creature movement (HB) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **creature AI movement integrator** (`DoMovement`):

1. Scope-enter with product method string; SEH frame.
2. Early-out if AI link null, movement timer not elapsed, or entity type/flag rejects.
3. Sample host pose (physics body or fallback offsets); evaluate terrain / vertical clearance.
4. Branch on climb vs ground: impulses, angular/linear velocity, rotation, optional vtbl anim cues.
5. Optional local-position override write via **`FUN_004cb3e0`** (ungated leaf).
6. Optional teleport reaction; terrain height snap; network lerp window.
7. On NaN cascade: `FUN_007a4480(0, "VOG_DEBUG_STOP")`.
8. Scope-exit / SEH teardown.

**Not** a pure debug stub. **Not** the hash lookup. High fan-out into already-dualed physics leaves.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cd3b0_FUN_005cd3b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005cd3b0_FUN_005cd3b0.annotated.md` |
| Clean product | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoMovement.cpp` |
| Clean FUN alias | `docs/reconstruction/reconstructed-exact/FUN_005cd3b0.cpp` |
| Deprecated named | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_005cd3b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005cd3b0_FUN_005cd3b0.md` |
| Live decompile | Ghidra `decompile_function` @ `0x005cd3b0` |
| Live bytes | `read_memory` prologue `005cd3b0`, epilogue `005ce960`, string `009da8a8`, constants |
| Function meta | `get_function_by_address` → body `005cd3b0`–`005ce989` |
| Callees | `get_function_callees` |
| Xrefs | `get_xrefs_to` / `get_function_xrefs` → **DATA/vtable only** |
| Related duals (context) | `A/B_aa_004cb3e0_*`, `A/B_aa_004c55e0_*`, physics SetPosition/Rotation/AngVel |

**Not performed:** Launcher, runtime golden, bit-exact full-body image walk of every float stack slot, ledger updates, deep dual of every nested callee.

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = AI controller (CVOGHBAICreatureBase* family)
// stack: float dt  (param_2)
void CVOGHBAICreatureBase_DoMovement(void *self, float dt);
```

Prologue: `mov esi, ecx`; push `"CVOGHBAICreatureBase::DoMovement"`; `FUN_0076cf00`.

---

## 4. Control flow: clean ≡ raw ≡ live decompile (gate spine)

| Stage | Match | Confidence |
|---|---|---|
| SEH + scope string enter/exit | **Yes** (bytes + decompile) | **High** |
| Early-out `this+0x18 == 0` | **Yes** (`cmp [esi+0x18],0` / `je`) | **High** |
| Optional timer `this+0x34/+0x38` vs client tick | **Yes** | **High** CF |
| Host entity `this[0x19]` (`+0x64`) | **Yes** | **High** |
| Type/flag early-out (component `+0x38 == 0x14` path) | **Yes** | **High** CF |
| Pose sample + vertical / speed scale (`FUN_004c55e0`) | **Yes** | **High** |
| Climb vs ground branches + state bytes `+0x304/+0x308` | **Yes** | **High** CF |
| Physics apply / set pos/rot/angvel callees | **Yes** (callee list + body) | **High** |
| Ungated `FUN_004cb3e0` local pos store | **Yes** (site ~`005ce8a3` per leaf dual) | **High** |
| Teleport / terrain cast / TFID checks | **Yes** | **High** CF |
| NaN → `VOG_DEBUG_STOP` | **Yes** | **High** |
| Vtable dispatch (no direct CALL) | **Yes** (5 DATA xrefs) | **High** |
| Every intermediate float stack name | **Partial** | **Tentative** |

### 4.1 Product string (`read_memory` @ `0x009da8a8`)

```
"CVOGHBAICreatureBase::DoMovement\0"
```

Prologue push imm `0x009da8a8` immediately before `FUN_0076cf00` — **method-scoped logger / profiler**, not an unrelated string.

### 4.2 Key constants (`read_memory`)

| Addr / imm | Value | Role in body |
|---|---|---|
| `DAT_00a0f718` | 0.01f | vertical separation threshold |
| `DAT_009da864` | ~1.19e-7 | normalize epsilon |
| `DAT_009da8a0` | -14.0f | vertical velocity gate |
| `DAT_009da8a4` | 3.5f | vertical velocity gate |
| `DAT_00a0f298` | 0.5f | speed clamp factor |
| `DAT_00af418c` | 10.0f | downward adjust / related |
| `DAT_00a110d8` | 10.0f | terrain cast Y bias |
| `0x18ff` | 6399 | lerp window ms |

---

## 5. Callee inventory (OWN body → known duals)

| Callee | Role in this unit |
|---|---|
| `FUN_0076cf00` / `FUN_0076cef0` | Scope enter/exit with product name |
| `FUN_004c55e0` | Speed / look-scale float (dualed leaf) |
| `FUN_004cb3e0` | **Ungated** store local pos4 `@+0x240` |
| `FUN_0040d2a0` / `00404dc0` / `0040d040` | Set position / rotation / angular velocity |
| `CVOGPhysics_ApplyImpulseVector` | Linear/angular impulse apply |
| `CVOGMap_CastTerrainHeight` | Terrain Y sample |
| `CVOGReaction_TeleportTarget` | Teleport path when host `+0x314` |
| `FUN_004ba740` + `TFID_EqualsObjectId` | Target id validity |
| `FUN_0053e0b0` | Scratch pose buffer helper |
| `FUN_007a4480` | Debug stop on NaN |
| `_isnan` | Float validity cascade |

Deep math inside nested callees is **not** re-sealed here beyond call sites.

---

## 6. Callers / dispatch

| Kind | Sites |
|---|---|
| Direct `CALL` | **None found** |
| DATA / vtable | `009da9b4`, `009daf3c`, `009db0bc`, `009db11c`, `009db17c` (each holds `0x005cd3b0`) |

Port implication: wire as **virtual method** on HB AI creature base (and likely derived vtables sharing the slot).

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists; span `005cd3b0`–`005ce989` | **Confirmed** | Ghidra meta + bytes |
| Product name `::DoMovement` | **High** | prologue string |
| `__thiscall` + float dt | **High** | ESI=ECX; stack use of `param_2` |
| Host at `this+0x64` | **High** | pervasive `param_1[0x19]` |
| Early-outs + NaN trap | **High** | decompile ≡ prologue cmp |
| Writes pose via known physics leaves | **High** | callee list |
| Ungated `+0x240` store via `004cb3e0` | **High** | sibling dual + this body |
| Full English for all state bytes | **Tentative / Open** | offsets sealed; names not |
| Exhaustive float-stack bit-exact | **Open** | large residual |
| Which classes own each vtable slot | **Open** | 5 DATA sites |

---

## 8. Gaps / open

1. Full `CVOGHBAICreatureBase` layout / inheritance for all offsets.
2. English semantics of host flags `+0x304/+0x306/+0x308/+0x314` and AI `+0x96`.
3. Per-vtable-owner class names for 5 DATA slots.
4. Runtime golden: NPC climb/land/teleport under live ticks.
5. Bit-exact full-body re-encoding vs retail image.
6. Nested dual of residual `FUN_0053e0b0` / `FUN_004cdd90` / `FUN_005d1ce0` (out of OWN unless separately owned).

**Verdict:** **accept-with-gaps** — product name, ABI, early-outs, major branch spine, callee fan-out, vtable dispatch, and trap-vs-name distinction sealed; residual float-stack detail and flag English remain open. Package **not complete** for runtime/diff.
