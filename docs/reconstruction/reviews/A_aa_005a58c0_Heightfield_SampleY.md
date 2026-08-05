# Review A (reconstruction fidelity): `aa_005a58c0` Heightfield_SampleY

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a58c0` |
| **VA** | `0x005a58c0` |
| **Body span** | `005a58c0` – `005a5956` (151 bytes; worker) |
| **Canonical name** | `Heightfield_SampleY` (**Probable**; was `FUN_005a58c0` / `Named_CalleeOf_CVOGMap_CastTerrainHeight_005a58c0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — live Ghidra decompile + `read_memory` + `force_decompile`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF + body bytes) |
| **Counterpart** | `reviews/B_aa_005a58c0_Heightfield_SampleY.md` |
| **System** | `world-terrain` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Heightfield bilinear Y sample kernel** (`this` = heightfield object*, **not** `CVOGMap*`):

1. `this` in **ECX** (MSVC `__thiscall`); stack: **`float worldX`**, **`float worldZ`**; cleans with **`RET 8`**; return **ST0 / float10** = world **Y**.
2. Scale XZ into grid space:  
   `gx = *(hf+0x30) * worldX`  
   `gz = *(hf+0x38) * worldZ`
3. Truncate toward zero (`CVTTSS2SI`), clamp cell indices to  
   `cellX ∈ [0, *(hf+0x0C)−2]`, `cellZ ∈ [0, *(hf+0x10)−2]`  
   (upper bound **dim−2** so bilinear may fetch `cell+1`).
4. Fractional offsets: `fx = gx − (float)cellX`, `fz = gz − (float)cellZ`.
5. Call sole callee **`FUN_005a5810(cellX, cellZ, fx, fz)`** with **ECX = hf** (bilinear / corner fetch via HF vtbl — **not dualed**; OWN scope).
6. Return `rawY / *(float*)(hf+0x34)` (height scale).

**Not** map gate `CVOGMap_SampleHeightfieldY` (`0x004cd220`) — that unit null-checks `map+0xe4e0` then **tail-JMPs** here with ECX rewritten to HF.  
**Not** `CVOGMap_CastTerrainHeight` (`0x004cfe60`) — that samples here then vertical collision cast.  
**Not** wheel / `TtPhantom::castRay` contact.

Shared pure HF Y kernel used by CastTerrainHeight, SampleHeightfieldY, MarchDirToTerrain, terrain mesh/build helpers, and other map paths (~14 named callers / ~27 xrefs).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a58c0_FUN_005a58c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005a58c0_FUN_005a58c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Heightfield_SampleY.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005a58c0.cpp` |
| Named alias (legacy) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGMap_CastTerrainHeight_005a58c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a58c0_Heightfield_SampleY.md` |
| Sibling map gate dual | `reviews/A_aa_004cd220_CVOGMap_SampleHeightfieldY.md` |
| Sibling cast dual / plate | `reviews/A_aa_004cfe60_CVOGMap_CastTerrainHeight.md`, `physics/verified/fn_004cfe60_castTerrain.md` |

**This pass (live):** Ghidra MCP `decompile_function` + `force_decompile` @ `0x005a58c0`; `analyze_function_complete`; `get_function_by_address` (body `005a58c0`–`005a5956`); `get_function_callers`; `read_memory` entry (128 B) + epilogue @ `0x005a5940` (confirms `FDIV [ESI+0x34]` / `POP EDI` / `POP ESI` / **`RET 8`**). Callee `FUN_005a5810` decompiled for structure only (not dualed). **Not performed:** Launcher, runtime golden, bit-exact binary diff. **Scope:** OWN VA only.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this` = heightfield* in ECX (not map) | **High** | Callers set ECX from `map+0xe4e0` (gate/cast); body uses HF layout `+0x0C/+0x10/+0x30/+0x34/+0x38` |
| Stack ABI: `(float x, float z)`, **RET 8**, return ST0 | **High** | Epilogue `C2 08 00`; params at `[ESP+8]/[ESP+0xC]` after `PUSH ESI`; callers pass XZ |
| Scale: `gx=*(+0x30)*x`, `gz=*(+0x38)*z` | **High** | Live decompile ≡ raw ≡ body `MULSS` |
| Trunc = `CVTTSS2SI` (toward zero), not float bitcast | **High** | Body `F3 0F 2C …`; decompiler `(uint)float` is a CF synonym only for non-neg |
| Clamp cell to `[0, dim−2]` per axis | **High** | `ADD ECX,-2` then min with `max(0,trunc)` via SETLE idiom |
| Fracs = scaled − cell int | **High** | `CVTSI2SS` + `SUBSS` before call |
| Callee `FUN_005a5810` = bilinear corner sample | **High structure** (callee body summarized; product open) | Four-corner + frac blend; vtbl `+0x30` height get |
| Return `raw / *(hf+0x34)` | **High** | `FDIV dword ptr [ESI+0x34]` in ST0 |
| Pure function (no map cast / no entity write) | **High** | No stores to map/entity; single CALL + FDIV |
| Multi-caller terrain HF kernel | **High** | Callers include CastTerrainHeight, SampleHeightfieldY (`004cd220` tail), MarchDir (`004cff70`), others |
| Product / PDB mangled name exact | **Probable / open** | Role sealed; symbol string open |
| Runtime / differential / bit-exact | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ body

| Stage | Match |
|---|---|
| `ESI = ECX` (preserve this) | **Yes** |
| `gx = *(this+0x30) * x` | **Yes** |
| `gz = *(this+0x38) * z` | **Yes** |
| Trunc + clamp X to `[0, *(+0x0C)−2]` | **Yes** |
| Trunc + clamp Z to `[0, *(+0x10)−2]` | **Yes** |
| `CALL FUN_005a5810(cellX, cellZ, fx, fz)` this=hf | **Yes** |
| `ST0 = ST0 / *(this+0x34)` | **Yes** |
| `RET 8` | **Yes** (`C2 08 00`) |
| No invent collision cast / filter / lerp | **Yes** |
| No invent map `+0xe4e0` null gate | **Yes** — caller's job |

### 4.1 Authoritative contract (cleaned)

```c
// Heightfield_SampleY (Probable)
// thiscall ECX = Heightfield*; stack float worldX, float worldZ; RET 8; ST0 = Y
float10 __thiscall Heightfield_SampleY(Heightfield* hf, float worldX, float worldZ)
{
  float gx = hf->scaleX /*+0x30*/ * worldX;
  float gz = hf->scaleZ /*+0x38*/ * worldZ;

  int cellX = clamp_i(trunc_toward_zero(gx), 0, hf->dimX /*+0x0C*/ - 2);
  int cellZ = clamp_i(trunc_toward_zero(gz), 0, hf->dimZ /*+0x10*/ - 2);

  float fx = gx - (float)cellX;
  float fz = gz - (float)cellZ;

  float10 raw = Heightfield_BilinearSample(/*FUN_005a5810*/ hf, cellX, cellZ, fx, fz);
  return raw / (float10)hf->heightScale /*+0x34*/;
}
```

### 4.2 Clamp idiom (body-sealed)

Per axis, after `CVTTSS2SI` into `EAX` and `maxCell = dim - 2` in `ECX`:

1. `t = max(0, trunc)` via `SETLE` / `SUB 1` / `AND` (signed ≤0 → 0).
2. If `t < maxCell` → `cell = t`; else `cell = maxCell`.

Equivalent: `cell = min(max(0, trunc(g)), dim - 2)`.

### 4.3 Epilogue bytes (authoritative)

```
… CALL FUN_005a5810
005a594f  D8 76 34            fdiv  dword ptr [esi+0x34]
005a5952  5F                  pop   edi
005a5953  5E                  pop   esi
005a5954  C2 08 00            ret   8
```

`read_memory` @ `0x005a5940`: `… e8 c1 fe ff ff d8 76 34 5f 5e c2 08 00 cc…`

### 4.4 Decompiler gaps (sealed by body)

| Decompiler display | Body truth |
|---|---|
| `(uint)param_2` after float scale | **`CVTTSS2SI`** trunc toward zero |
| Signature sometimes `undefined (void)` in function metadata | **thiscall + 2×float, RET 8, float10 ST0** |
| `(float)(int)uVar2` frac base | Integer cell after clamp (EDI/ECX), not pre-clamp trunc alone |

---

## 5. Layout / constants

### Heightfield (`this`)

| Offset | Type | Role |
|-------:|------|------|
| `+0x0C` | int | Grid dimension X (cells); clamp max = value − 2 |
| `+0x10` | int | Grid dimension Z (cells); clamp max = value − 2 |
| `+0x30` | float | World→grid scale X (`gx = scaleX * worldX`) |
| `+0x34` | float | Height scale divisor (`Y = raw / scaleY`) |
| `+0x38` | float | World→grid scale Z (`gz = scaleZ * worldZ`) |

(Callee uses HF vtbl / corner fetch — out of OWN dual scope.)

### Callees / callers (inventory only)

| Kind | Symbol | Role |
|---|---|---|
| Callee | `FUN_005a5810` @ `0x005a5810` | Bilinear sample at (cellX, cellZ, fx, fz) |
| Caller | `CVOGMap_SampleHeightfieldY` `0x004cd220` | Null HF gate; **tail JMP** here |
| Caller | `CVOGMap_CastTerrainHeight` `0x004cfe60` | HF Y then vertical cast |
| Caller | `FUN_004cff70` (MarchDirToTerrain) | Step march HF probes |
| Callers | `FUN_004a8fb0`, `FUN_004ac660`, `FUN_004cf560`, `FUN_004d0ed0`, `FUN_004d10d0`, `FUN_004d1280`, `FUN_004d1680`, `FUN_004d2440`, `FUN_004d2c60`, `FUN_004d9f00`, `FUN_0061e410` | Terrain / placement / mesh helpers |

---

## 6. Gaps / open

1. Exact product / PDB name for this method (vs inferred `Heightfield_SampleY` / `CVOGHeightfield_SampleY`).
2. Full dual of `FUN_005a5810` (bilinear corners + vtbl `+0x30` height get) — **out of OWN scope**.
3. Semantic names of `+0x30/+0x38` (cells-per-world vs world-per-cell) — math is multiply-then-clamp; asset units open.
4. Whether `+0x34` is always non-zero (no div0 guard in body).
5. Runtime golden vs known heightfield asset samples.

**Verdict:** **accept-with-gaps** — body-sealed scale/clamp/bilinear-call/÷scale contract and ABI; product symbol + callee dual + runtime open.
