# Review A (reconstruction fidelity): `aa_004cd220` CVOGMap_SampleHeightfieldY

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd220` |
| **VA** | `0x004cd220` |
| **Body span** | `004cd220` – `004cd237` (24 bytes; leaf wrapper) |
| **Canonical name** | `CVOGMap_SampleHeightfieldY` (**Probable**; was `FUN_004cd220`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF + body bytes) |
| **Counterpart** | `reviews/B_aa_004cd220_CVOGMap_SampleHeightfieldY.md` |
| **System** | `world-terrain` (primary); DriveControlTick camera/ground consumer under `input-drive-control` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **CVOGMap** gate over the heightfield bilinear sample:

1. `this` = map in **ECX** (MSVC `__thiscall`).
2. Stack args: **`float x`**, **`float z`** (world XZ). Callee cleans with **`RET 8`**.
3. Load `hf = *(map + 0xe4e0)`.
4. If `hf != 0`: **tail-call** `FUN_005a58c0` with **ECX = hf** (stack `x,z` preserved) → return heightfield **Y**.
5. If `hf == 0`: load **`g_flZero`** (`0x00a0f518` = **0.0f**) into ST0 and return.

**Not** `CVOGMap_CastTerrainHeight` (`0x004cfe60`) — that path also samples HF then vertical collision-cast. This unit is **pure HF Y** (or 0).

**Not** a DriveControlTick-only helper — ~34 named callers including `CVOGCreature_FindTerrainHeight`, `Vehicle_ActivateEnterWorld`, and many spawn/AI/UI paths.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cd220_FUN_004cd220.md` |
| Annotated | `docs/reconstruction/raw/aa_004cd220_FUN_004cd220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMap_SampleHeightfieldY.cpp` |
| Named alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_DriveControlTick_004cd220.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cd220_CVOGMap_SampleHeightfieldY.md` |
| Sibling cast | `docs/reconstruction/physics/verified/fn_004cfe60_castTerrain.md` |
| Sibling dual | `reviews/A_aa_004cfe60_CVOGMap_CastTerrainHeight.md` |
| FindTerrainHeight record | `functions/aa_004c6100_CVOGCreature_FindTerrainHeight.md` |
| DriveControlTick raw (call site) | `raw/aa_009223b0_Client_Input_DriveControlTick.md` (~`0x009236d2`) |

**This pass (live):** Ghidra MCP `decompile_function` @ `0x004cd220` + `0x005a58c0` + `0x004c6100`; `get_function_callers` / `get_function_xrefs` / `analyze_function_complete`; `read_memory` body `0x004cd220` (24 B) + `g_flZero` `0x00a0f518`. **Not performed:** Launcher, runtime golden, bit-exact binary diff. **Scope:** OWN VA only (callee body summarized for ABI, not dualed).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this` = CVOGMap* in ECX | **High** | Same `+0xe4e0` HF slot as CastTerrainHeight; FindTerrainHeight / DCT call sites |
| Stack ABI: `(float x, float z)`, **RET 8** | **High** | Body `C2 08 00`; DCT `FUN_004cd220(fStack_88,fStack_80)`; FindTerrainHeight `(*pos, pos[2])` |
| Gate: `*(map+0xe4e0) != 0` else return 0.0 | **High** | Live decompile ≡ raw ≡ body bytes |
| Non-null path = **tail JMP** to `FUN_005a58c0` with ECX=hf | **High** | `E9 …` → `0x005a58c0`; not CALL/RET |
| Null path loads `g_flZero` @ `0x00a0f518` = **0.0f** | **High** | `read_memory` `00 00 00 00` |
| Return = heightfield **Y** (ST0 / float10) | **High** | Callers use as terrainY; HF sample sibling in castTerrain plate |
| `FUN_005a58c0` role = HF sample (scale/clamp/bilinear/÷scale) | **High structure** (callee body); product name open | Live decompile of callee; not dualed this pass |
| Args are **world X then Z** (not Y) | **High** | Xrefs pass `*pos` / `pos[2]`; DCT X/Z after transform |
| Shared multi-system API (not input-only) | **High** | 57 xrefs; named callers include FindTerrainHeight + DCT |
| Product C++ mangled name exact | **Probable / open** | Name **Inferred/Probable** from role + map layout |
| Runtime / differential / bit-exact | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ body

| Stage | Match |
|---|---|
| Load HF from `map+0xe4e0` into ECX | **Yes** (`8B 89 E0 E4 00 00`) |
| TEST / JZ null | **Yes** |
| Tail JMP `FUN_005a58c0` | **Yes** (not CALL) |
| FLD `g_flZero` + RET 8 | **Yes** |
| No invent physics cast / filter / lerp | **Yes** — pure gate+sample |
| No invent steer/thr/HB | **Yes** |

### 4.1 Body bytes (authoritative)

```
004cd220  8B 89 E0 E4 00 00   mov  ecx, [ecx+0xe4e0]
004cd226  85 C9               test ecx, ecx
004cd228  74 05               jz   short +0x5   ; → FLD zero
004cd22a  E9 91 86 0D 00      jmp  FUN_005a58c0 ; ECX = hf
004cd22f  D9 05 18 F5 A0 00   fld  dword ptr [g_flZero]
004cd235  C2 08 00            ret  8
```

### 4.2 Decompiler gap (sealed by body)

Default decompile shows `__fastcall (int param_1)` and `FUN_005a58c0()` with **no stack args**. **Body + callers fix ABI:**

```
float10 __thiscall CVOGMap_SampleHeightfieldY(map*, float x, float z)
  // RET 8; ST0 = Y or 0.0
```

Tail-call hides args from naive decompiler display — dual treats **body + call sites** as ABI truth.

### 4.3 DriveControlTick consumer (context only)

At ~`0x009236d2` after `PushDriveAxesToController`:

```
FUN_0075c340(&fStack_b4, &fStack_88, &fStack_7c);   // transform → world-ish basis
fVar10 = FUN_004cd220(fStack_88, fStack_80);        // HF Y at (X,Z)
// project look/camera hit using (Y - fVar10) / |dirY| into host+0x11c..+0x124
```

Confirms **(X,Z) → Y** sample role in the camera look-offset residual (UF-003 camera slice consumer). Full camera math is **out of this unit**.

### 4.4 FindTerrainHeight consumer (context only)

```
fVar4 = FUN_004cd220(*worldPos, worldPos[2]);  // initial HF sample
fStack_8c = (float)(fVar4 + bias);
// optional CastTerrainHeight / castRay refine when elevated
return fStack_8c + footOffset(+0x120);
```

---

## 5. Layout / constants

### Map (`this`)

| Offset | Type | Role |
|-------:|------|------|
| `+0xe4e0` | ptr | Heightfield object* — null → 0.0; else becomes `this` for `FUN_005a58c0` |

(Sibling cast also uses `map+0xe4a4` cast context — **unread** here.)

### Constants

| Symbol | Addr | LE bytes | Value | Role |
|--------|------|----------|------:|------|
| `g_flZero` | `0x00a0f518` | `00 00 00 00` | **0.0f** | Null-HF return |

---

## 6. Gaps / open

1. Exact product / PDB name for this method (vs inferred `CVOGMap_SampleHeightfieldY`).
2. Full product name / dual for `FUN_005a58c0` (HF bilinear sample) — **out of OWN scope**.
3. Runtime proof of map `this` register at every call site (static CF: FindTerrainHeight / DCT / castTerrain layout consistent).
4. Whether any caller expects non-zero sentinel on null HF instead of 0.0 (body returns 0.0 only).

**Verdict:** **accept-with-gaps** — body-sealed gate + ABI + HF sample role; product symbol open; package not complete (runtime/diff).
