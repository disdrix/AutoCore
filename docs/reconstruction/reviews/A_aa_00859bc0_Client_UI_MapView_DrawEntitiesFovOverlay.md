# Review A (reconstruction fidelity): `aa_00859bc0` Client_UI_MapView_DrawEntitiesFovOverlay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00859bc0` |
| **VA** | `0x00859bc0`–`0x0085a9ef` (3631 B) |
| **Canonical name** | `Client_UI_MapView_DrawEntitiesFovOverlay` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00859bc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-N) |
| **Counterpart** | `reviews/B_aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` |
| **System** | client UI / map-view overlay |
| **Verdict** | **accept-with-gaps** on CF / ABI / phases / constants; entity-list English + nested leaf duals **open** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + `get_xrefs_to`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Map-view **entity-rich composite overlay**: world entity lists A/B, markers, auto-patrol, mission tree, special point, squad, and scaled FOV textured quad. thiscall method; config at `this+0x488`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00859bc0_FUN_00859bc0.md` |
| Named record | `docs/reconstruction/functions/aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` |
| Raw | `docs/reconstruction/raw/aa_00859bc0_FUN_00859bc0.md` (+ W23-N live seal) |
| Annotated | `docs/reconstruction/raw/aa_00859bc0_FUN_00859bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_MapView_DrawEntitiesFovOverlay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00859bc0.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00859bc0` |
| Live body | `read_memory` entry 64 B + epilogue; body end `0085a9ef` |
| Xrefs | DATA only `0x00a65a54` |
| Related helpers | `FUN_00859260`, `FUN_00859a90`, `FUN_00757890` |

**Not performed:** Launcher, runtime golden, bit-exact, deep dual of nested helpers (OWN-ONLY).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **3631 B** / end `0085a9ef` | **Confirmed** | `get_function_by_address` |
| ABI **thiscall** ECX=this; plain **`C3`** | **Confirmed** | entry `mov ebx,ecx`; epilogue `ret` |
| Gate config/local/world/listHost | **Confirmed** | decomp + entry bytes |
| World list A at host+0x28, B at +0x48 | **Confirmed** | decomp (ptr arithmetic) |
| Entity draw via `FUN_00859260` | **Confirmed** | callees |
| Icon dispatch via `FUN_00859a90` | **Confirmed** | callees + string VOG path |
| Marker tex `+0x624+type*4` | **Confirmed** | decomp |
| FOV final scale `DAT_00a0f298 = 0.5` | **Confirmed** | `read_memory` |
| Optional FOV scale uses min(1,1)/`+0x500` when `+0x5b9==0` | **Confirmed** | decomp + globals 1.0f |
| Layer counters `+0x68/+0x70/+0x74` | **Confirmed** | decomp |
| Vtbl DATA `@00a65a54` | **Confirmed** | xrefs + bytes |
| Clean ≡ live CF (phases) | **Confirmed** | |
| List A/B product English | **Open** | structure sealed |
| Nested filter full bit dictionary | **Open** | |
| Product / PDB name | **Open** | |
| Bit-for-bit / runtime | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Entry align + frame 0x104 | Yes |
| Load this+0x488; multi-global gate | Yes |
| Require list heads A/B | Yes |
| World list A filter + lazy + draw | Yes |
| Layer bump | Yes |
| World list B filter + ally tint + draw | Yes |
| Markers type 0..8 | Yes |
| Patrol / mission / special / squad | Yes |
| FOV quad with scale chain | Yes |
| Early ret after textured FOV | Yes |
| Fail gate → plain ret | Yes |
| No sin-cone path (unlike sibling) | Yes |

---

## 5. Gaps

1. Product class/method English.  
2. Semantic labels for world list A vs B.  
3. Full entity filter flag dictionary.  
4. Dual of `FUN_00859260` / `FUN_00859a90`.  
5. Runtime / bit-exact.

---

## 6. Verdict rationale

Phase map, ABI, list structure, and FOV scale chain confirmed from decompile + constants. Structural name role-accurate. Residual English for entity sets and nested leaves → **accept-with-gaps**.
