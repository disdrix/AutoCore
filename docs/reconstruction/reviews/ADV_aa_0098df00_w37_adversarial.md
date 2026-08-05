# Adversarial note (W37 spot-check): `aa_0098df00` stage-2 WireColor pack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098df00` |
| **VA** | `0x0098df00`–`0x0098e29f` |
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (not W37-A author) |
| **Scope** | Factual error in dual prose / tables only; clean twin CF body matches live decompile |
| **Tools** | `decompile_function` + `read_memory` (no `disassemble_bytes`) |

---

## Issue

W37-A dual A/B, agent report, function record, annotated prose, and named-clean header claim for **stage 2** (`host+0x30` · `PalVisibleShadowVolume.fx`):

| Param | Dual claim | Live decompile pack (`local_10`,`local_c`,`local_8`,`local_4` as RGBA) |
|---|---|---|
| SolidColor | **(0, 1, 0, 0.5)** | **Confirmed** — R=0, G=`g_flOne`, B=0, A=`DAT_00a0f298` |
| WireColor | **(0, 0, 1, 0.5)** | **Wrong** — decompile sets **(0, 1, 0, 0.5)** (G=`g_flOne`, B=0) |

### Live stage-2 WireColor assignments (Ghidra `decompile_function`)

```c
  local_10 = 0.0;                 // R
  local_8 = 0.0;                  // B
  local_c = g_flOne;              // G
  local_4 = (float)DAT_00a0f298;  // A → 0.5f
  // then FUN_00752370(..., "WireColor") + optional FUN_0096fff0
```

Contiguous stack order matches emissive stage packing used as RGBA: `local_10`=R, `local_c`=G, `local_8`=B, `local_4`=A (emissive seals as **(1, 0.2, 0.2, 1)** with the same layout).

### Stage 3 (for contrast — dual claim is correct)

| Param | Dual claim | Live decompile |
|---|---|---|
| SolidColor | (0, 0, 1, 0.5) | Confirmed (B=`g_flOne`) |
| WireColor | (0, 0, 1, 0.5) | Confirmed (B=`g_flOne`) |

### Corrected stage color summary

| Slot | Effect | Solid | Wire |
|---|---|---|---|
| `+0x28` | `PalToolMaterialNoMap.fx` | n/a (Mat*) | n/a |
| `+0x30` | `PalVisibleShadowVolume.fx` | **(0,1,0,0.5)** | **(0,1,0,0.5)** (not blue wire) |
| `+0x38` | `PalVisibleShadowVolume.fx` | **(0,0,1,0.5)** | **(0,0,1,0.5)** |

Design read (still tentative product intent): dual shadow-volume holders are **green channel @ +0x30** vs **blue channel @ +0x38**, each with matching Solid/Wire, not “green solid + blue wire” on stage 2.

---

## Where the wrong Wire claim appears

- `docs/agents/task-dual-ab-0098fd80-0098df00-w37a-report.md` (stage table)
- `docs/reconstruction/reviews/A_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` (surviving contract comments)
- `docs/reconstruction/functions/aa_0098df00_FUN_0098df00.md`
- `docs/reconstruction/raw/aa_0098df00_FUN_0098df00.annotated.md` (table + comment; **variable assign in annotated snippet already sets G=1 for Wire**, contradicting its own “(0,0,1)” comment)
- Named clean header comment in `PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.cpp` (PURPOSE block)

## What is still correct

- Clean twin **statement body** (`FUN_0098df00.cpp` / named clean) assigns the same locals as live decompile — executable CF reconstruction is fine; the bug is **prose interpretation** of stage-2 Wire.
- ABI (EAX host), sole caller, host size 0x40, three slots, effect plates, stage-1 emissive **(1,0.2,0.2,1)**, stage-3 colors, constant return 0, float pool bytes (`DAT_00a0f70c`=0.2f, `DAT_00a0f298`=0.5f) — all still confirmed on independent re-verify.

## Severity

**Medium for docs / port comments** (wrong default wire color on slot `+0x30` if someone ports from dual tables only).  
**Low for twin source** (assignments already match binary).

## Recommended fix (owner)

1. Change stage-2 WireColor prose to **(0, 1, 0, 0.5)** everywhere listed above.  
2. Optionally note annotated self-contradiction (comment said blue, assign was green).  
3. Do **not** change clean twin assignment order.

**No dual rewrite performed by this verifier** beyond this ADV note + parent spot-check report.
