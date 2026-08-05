# Review A (reconstruction fidelity): `aa_00851630` Client_UI_MapView_DrawMarkersFovOverlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00851630` |
| **VA** | `0x00851630`–`0x00852428` (3576 B) |
| **Canonical name** | `Client_UI_MapView_DrawMarkersFovOverlay` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00851630` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-N) |
| **Counterpart** | `reviews/B_aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` |
| **System** | client UI / map-view overlay |
| **Verdict** | **accept-with-gaps** on CF / ABI / phases / constants; nested leaf duals + product symbol **open** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + `get_xrefs_to`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Map-view **composite overlay** draw for markers, auto-patrol, mission objectives, special point, squad, and player FOV/range visualization (quad + optional cone). thiscall method of a client map UI object with config at `this+0x488`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00851630_FUN_00851630.md` |
| Named record | `docs/reconstruction/functions/aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` |
| Raw | `docs/reconstruction/raw/aa_00851630_FUN_00851630.md` (+ W23-N live seal) |
| Annotated | `docs/reconstruction/raw/aa_00851630_FUN_00851630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_MapView_DrawMarkersFovOverlay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00851630.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00851630` |
| Live body | `read_memory` entry 64 B + epilogue region; body end `00852428` |
| Xrefs | DATA only `0x00a68204` |
| Related helpers | `FUN_008513d0` (icon), `FUN_00757890` (quad) |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of nested draw leaves (OWN-ONLY).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **3576 B** / end `00852428` | **Confirmed** | `get_function_by_address` |
| ABI **thiscall** ECX=this; plain **`C3`** | **Confirmed** | entry `mov edi,ecx`; epilogue `ret` |
| Gate includes config `+0x4fc` | **Confirmed** | decomp + entry loads `+0x488` then nested flag |
| Marker list `DAT_00d1d964` loop | **Confirmed** | decomp |
| Icon half-size `+0x538/+0x53c` | **Confirmed** | decomp |
| Marker tex `+0x600+type*4` type 0..8 | **Confirmed** | decomp |
| Phase order markers→patrol→mission→special→squad→FOV | **Confirmed** | decomp sequence + layer bumps |
| `DAT_00aaa8a8 = 300.0f` FOV scale | **Confirmed** | `read_memory` |
| `DAT_00aaa6c4 = 2.5f` cone angle scale | **Confirmed** | `read_memory` |
| Layer counters `+0x68/+0x70/+0x74` | **Confirmed** | decomp `param_1[0x1a/1c/1d]` |
| Vtbl DATA `@00a68204` | **Confirmed** | `get_xrefs_to` + `read_memory` |
| Clean ≡ live CF (phases) | **Confirmed** | identity of sealed phases |
| Nested draw leaf bit-exact | **Open** | out of OWN |
| Product / PDB name | **Open** | structural |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Entry align + frame 0x164 | Yes |
| Load this+0x488; multi-global gate | Yes |
| Marker circular walk + project + draw | Yes |
| Layer bump after markers | Yes |
| Auto-patrol vector walk | Yes |
| Mission tree RB walk + type 0x65 | Yes |
| Special point type 100 | Yes |
| Squad 0..3 when party flag | Yes |
| Camera pair FOV quad | Yes |
| Optional sin-cone when sin>0 | Yes |
| Early ret after textured FOV | Yes |
| Fail gate → plain ret | Yes |

---

## 5. Gaps

1. Product class/method English name.  
2. Full `MapConfig` field dictionary.  
3. Dual of `FUN_008513d0` / `FUN_00757890` / `FUN_0084f610`.  
4. Exact icon-type enum English (`0x65`, `'d'`/`'e'`).  
5. Runtime / bit-exact.

---

## 6. Verdict rationale

Phase map, ABI, key offsets, and float constants are independently confirmed from decompile + raw bytes. Structural name is role-accurate. Nested geometry/draw leaf formulas and product symbols remain residual → **accept-with-gaps**.
