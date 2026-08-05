# Review A (reconstruction fidelity): `aa_004cff70` CVOGMap_MarchDirToTerrain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cff70` |
| **VA** | `0x004cff70` |
| **Body span** | `004cff70` – `004d01bf` |
| **Canonical name** | `CVOGMap_MarchDirToTerrain_Inferred` (Ghidra still `FUN_004cff70`; product English open) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004cff70_CVOGMap_MarchDirToTerrain_Inferred.md` |
| **System** | `world-terrain` / drive+pick consumers |
| **Dual status** | **Present (this pass)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Heightfield-only step march** along a caller-supplied direction, owned by **`CVOGMap*`**:

1. Gate: `map+0xe4e0` (heightfield object*) non-null; else **return 0**.
2. Copy start `float4` → out `float4`; copy step dir components; `stepCount = 0`; `prevHfY = 0`.
3. Sample HF Y at start **(X,Z)** via **`FUN_005a58c0`** (thiscall HF; decompiler drops ECX — same family as `CVOGMap_CastTerrainHeight`).
4. **Above/on terrain** (`hfY <= startY`): enter surface-hit loop.
5. **Below terrain** (`hfY > startY`): march while still buried; when probe **emerges** (`hfY < curY`), **goto** surface-hit loop (no early success).
6. **Surface-hit loop** (while `stepCount < maxSteps`):
   - `pos += dir` (all 4 components)
   - write pos → out
   - sample HF at `(pos.x, pos.z)`
   - if `pos.y <= hfY`: compute abs-ratio blend on **X/Z** using `prevHfY`, **return 1**
   - else `prevHfY = hfY`; `stepCount++`
7. Exhaust steps / fall-through → **return 0** (out may still hold last marched pos).

**Not** `CVOGMap_CastTerrainHeight` (`0x004cfe60`): no vertical-only ray, no `FUN_0055e530` collision refine, no float Y return — **bool hit** + out position.

**Callers (5 xrefs, live):**

| Caller | Sites | `maxSteps` | Role |
|---|---|---:|---|
| `Client_Input_DriveControlTick` `0x009223b0` | 2 (`0x00922848`, `0x00923328`) | **400** | Drive path / secondary march (flag `client+0xa86`, `FUN_004c3a40` on hit; other site uses out length) |
| `Client_InteractClickPickTarget` `0x009247b0` | 2 (`0x0092496b`, `0x00924c26`) | **400** | Soft screen→world ray hit → gather radius |
| `FUN_005995a0` | 1 (`0x0059964d`) | **400** | `map = *(ctx+0x40)`; hit → vtbl **+0x5c** on `*(ctx+0x24)` |

Many sites load map from **`DAT_00d1b644`** into ECX.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cff70_FUN_004cff70.md` |
| Annotated | `docs/reconstruction/raw/aa_004cff70_FUN_004cff70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004cff70.cpp` |
| Named alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_DriveControlTick_004cff70.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cff70_FUN_004cff70.md` |
| Sibling verified | `docs/reconstruction/physics/verified/fn_004cfe60_castTerrain.md` |
| Consumers | DCT raw/clean; InteractClickPick dual residual name list |
| Live Ghidra | `decompile_function` + `force_decompile` @ `0x004cff70`; `decompile` `FUN_005a58c0` @ `0x005a58c0`; `FUN_005995a0` @ `0x005995a0`; `get_function_callers` / xrefs; `get_function_by_address` body; `get_assembly_context` on 5 call sites; entry neighbor shows prior fn **`RET 0x10`** |

**Not performed:** Launcher, runtime golden, bit-exact, product rename apply.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this` = map; gate `*(map+0xe4e0) != 0` else 0 | **High** | Live first load/branch; sibling HF offset sealed |
| Args: `start*`, `dir*`, `out*`, `maxSteps` (4 stack) | **High** | Decompile + caller LEA/PUSH; `RET 0x10` at exits |
| MSVC `__thiscall` map in ECX | **High** | Decompiler + call sites (`DAT_00d1b644` / `*(ctx+0x40)`) |
| Sole callee `FUN_005a58c0` HF sample (x,z) → ST0 Y | **High** | Callees list; sibling plate |
| Decompile omits ECX=HF on sample calls | **High CF residual** | Same pattern as CastTerrainHeight raw; null-check proves HF host |
| Start branch: `hfY <= startY` → surface path; else bury-emerge path | **High** | Live if/else |
| Emerge: `hfY < curY` → goto surface loop (not success) | **High** | `goto LAB_004d00db` |
| Surface hit: `curY <= hfY` → return **1** | **High** | Live |
| Step: `pos += dir` for all 4 floats | **High** | Live |
| Out written every step (and initial copy) | **High** | Live |
| Hit X/Z blend uses `ABS(outY - prevHfY) / (ABS(hfY - curY) + ABS(outY - prevHfY))` | **High structure** | Live formula |
| Hit X/Z may be **identity** if out was pre-stored as current (decompiler order) | **Probable residual** | If out≡current before blend, `(cur-out)*t+out` no-ops X/Z; Y/W not rewritten on hit |
| `prevHfY` init **0** (not start hfY); only updated on surface-loop miss | **High** | Live `local_34 = 0` |
| Exhaust / null HF / no-hit → return **0** | **High** | Live |
| Caller `maxSteps` **400** at all 5 sites | **High** | DCT, pick, `FUN_005995a0` immediates |
| Not collision-cast / not wheel `TtPhantom::castRay` | **High** | No `0055e530` / `580ed0` |
| Not float height return (≠ CastTerrainHeight) | **High** | EAX 0/1 |
| Product symbol / English name | **Open** | `_Inferred`; leave Ghidra FUN until rename pass |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Null HF gate | **Yes** |
| Copy start → out; cache dir; init counters | **Yes** |
| Initial HF sample + above/below split | **Yes** |
| Buried march + emerge goto | **Yes** |
| Surface march + hit blend + return 1 | **Yes** |
| Exhaust return 0 | **Yes** |
| No invented collision cast / vertical-only ray | **Yes** |

Scaffold clean is behavior-preserving raw paste (verbose whitespace); CF matches live.

---

## 5. Signature (recovered)

```c
// MSVC __thiscall — this = CVOGMap* in ECX; RET 0x10
int CVOGMap_MarchDirToTerrain_Inferred(
    CVOGMap* this,     // ECX; uses this+0xe4e0 heightfield*
    float*   start,    // [EBP+08] float4 xyzw world start
    float*   dir,      // [EBP+0C] float4 per-step delta (not necessarily unit)
    float*   outHit,   // [EBP+10] float4 out position (updated each step)
    int      maxSteps  // [EBP+14] march budget (callers use 400)
);
// return: 1 hit (probe Y crossed into HF), 0 miss / no HF
```

---

## 6. Gaps / open

1. Product / PDB English name (still `FUN_004cff70` in Ghidra).
2. Seal whether hit X/Z blend is intentional identity or decompiler store-order artifact (needs tight asm/pcode on hit block).
3. Whether hit should snap **out.y** to `hfY` (body leaves Y as probe Y).
4. Semantic role of w-component of float4 (copied/stepped; unused by sample).
5. Runtime golden vs heightfield assets; bit-exact.
6. Deep identity of `FUN_005a58c0` / bilinear grid (shared with CastTerrainHeight — not re-owned here).

**Verdict:** **accept-with-gaps** — march CF + HF gate + bool return + 400-step callers sealed High; name `_Inferred`; hit-blend X/Z residual noted.
