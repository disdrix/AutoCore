# Independent adversarial spot-check — W37 duals `0x0098fd80` + `0x0098df00`

| Field | Value |
|---|---|
| **Date** | `2026-08-04` |
| **Role** | Independent adversarial verifier (**not** W37-A dual author) |
| **Workspace** | `C:\Users\josh\Documents\GitHub\AutoCore` |
| **Partition** | W37-A residual pair |
| **Tools** | Ghidra MCP `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs`; artifact read-through |
| **Forbidden** | `disassemble_bytes`; parent ledger edits; dual rewrite (except ADV note on factual error) |
| **Image** | `autoassault.exe` base `0x400000` |

---

## Inspected evidence

### Dual / report surfaces

| Path |
|---|
| `docs/agents/task-dual-ab-0098fd80-0098df00-w37a-report.md` |
| `docs/reconstruction/reviews/A_aa_0098fd80_PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0098fd80_PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.md` |
| `docs/reconstruction/reviews/A_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` |
| `docs/reconstruction/reviews/B_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` |

### Artifacts

| Kind | `aa_0098fd80` | `aa_0098df00` |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0098fd80_FUN_0098fd80.md` | `docs/reconstruction/raw/aa_0098df00_FUN_0098df00.md` |
| Annotated | `…/aa_0098fd80_FUN_0098fd80.annotated.md` | `…/aa_0098df00_FUN_0098df00.annotated.md` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098fd80.cpp` | `…/FUN_0098df00.cpp` |
| Clean named | `…/PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.cpp` | `…/PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0098fd80_FUN_0098fd80.md` | `…/aa_0098df00_FUN_0098df00.md` |

### Live Ghidra spot-checks

| Check | Result |
|---|---|
| `decompile_function(0x0098fd80)` | Live body ≡ raw capture (strings, slot `+0x28`, emissive pack, refcount ladder, `return 0`) |
| `decompile_function(0x0098df00)` | Live body ≡ raw (three stages, plates, slots, `return 0`); stage-2 Wire pack interpreted below |
| `decompile_function(0x0073c810)` | Sole bootstrap caller: `new(0x30)`→`FUN_00457ac0`→`unaff_EDI[9]`→`FUN_0098fd80(pvVar2)`; `new(0x40)`→`FUN_00457b30`→zero `+0x28/+0x30/+0x38`→`unaff_EDI[10]`→`FUN_0098df00()` (no stack host) |
| `get_function_by_address` | `0098fd80`–`0098fee9`; `0098df00`–`0098e29f` (**body ranges confirmed**) |
| `get_function_xrefs` | Sole call each: `0073cac3` / `0073cb1b` in `FUN_0073c810` |
| `read_memory` floats | See table below |

### Float pool (`read_memory`)

| Address | Hex (LE) | Float | Dual claim |
|---|---|---|---|
| `0x00a0f720` | `cd cc cc 3e` | **0.4f** | emissive G/B for `0098fd80` — **OK** |
| `0x00a0f70c` | `cd cc 4c 3e` | **0.2f** | emissive G/B for `0098df00` — **OK** |
| `0x00a0f298` | `00 00 00 3f` | **0.5f** | shadow alpha — **OK** |
| `0x00a0f72c` | `6f 12 83 3a` | **0.001f** | DepthBias — **OK** |
| `0x00a0f730` | `cd cc cc 3d` | **0.1f** | GhostAlpha — **OK** |
| `0x00a0f2a0` | `00 00 80 3f` | **1.0f** | `g_flOne` — **OK** |

---

## Confirmed claims

### `0x0098fd80` (`aa_0098fd80`)

| Claim | Verdict |
|---|---|
| Body range `0098fd80`–`0098fee9` | **Confirmed** |
| Live decompile ≡ raw CF | **Confirmed** |
| Stack formal host* (not ECX-thiscall); caller pushes `pvVar2` | **Confirmed** |
| Material holder `host+0x28` | **Confirmed** |
| Sole caller `FUN_0073c810` @ `0x0073cac3`; HostPtrTable slot9; `new(0x30)` + `FUN_00457ac0` | **Confirmed** |
| Plate `"PalToolMaterialNoMap.fx"`; params DepthBias / GhostAlpha / MatDiffuse / MatSpecular / MatEmissive | **Confirmed** |
| DepthBias=0.001, GhostAlpha=0.1 | **Confirmed** (bytes) |
| Emissive RGBA **(1, 0.4, 0.4, 1)** via `g_flOne` + `DAT_00a0f720`×2 | **Confirmed** |
| Null holder → `-1` handle path; bind only if handle ≥ 0 | **Confirmed** |
| `FUN_0073d940` refcount-swap (inc/`vtbl+4`, dec/`vtbl+8`) | **Confirmed** (pattern in body) |
| Always `return 0` (no OR-status) | **Confirmed** |
| Callee set as dualed | **Confirmed** in decompile |
| Shared-float *names* are not product shader English | **Confirmed** as dual hygiene (names reused) |
| Product host class English open; helper ECX open; no runtime/diff | **Fair residual** |
| Dual A/B both `accept-with-gaps`; structural `_Inferred` name preferred over plate-only | **Appropriate** |

### `0x0098df00` (`aa_0098df00`) — structural / ABI

| Claim | Verdict |
|---|---|
| Body range `0098df00`–`0098e29f` | **Confirmed** |
| Live decompile ≡ raw CF (statement order) | **Confirmed** |
| Host in **EAX** (`in_EAX`); call site `FUN_0098df00()` no stack host | **Confirmed** |
| Sole caller `FUN_0073c810` @ `0x0073cb1b`; slot10; `new(0x40)` + `FUN_00457b30` | **Confirmed** |
| Three stages at `+0x28` / `+0x30` / `+0x38` | **Confirmed** |
| Stage1 `PalToolMaterialNoMap.fx`; DepthBias/GhostAlpha; Mat* | **Confirmed** |
| Stage1 emissive **(1, 0.2, 0.2, 1)** ≠ sibling 0.4 | **Confirmed** (`DAT_00a0f70c`) |
| Stages 2–3 `PalVisibleShadowVolume.fx`; SolidColor/WireColor strings | **Confirmed** |
| Stage2 Solid **(0,1,0,0.5)** | **Confirmed** |
| Stage3 Solid **(0,0,1,0.5)**; Stage3 Wire **(0,0,1,0.5)** | **Confirmed** |
| Triple `FUN_0073d940` swap; always `return 0` | **Confirmed** |
| Do not merge contract with `0098fd80` (size/emissive/shadow stages) | **Confirmed** as dual guidance |
| Clean twin body assigns same locals as decompile | **Confirmed** |

---

## Residual gaps (honest; duals already flag most)

1. Product/PDB English for host types (0x30 / 0x40) beyond effect plates.  
2. Helper thiscall ECX recovery for `FUN_009701d0` / `FUN_00442640` (decompiler drops `this`).  
3. Full contracts of unowned callees.  
4. Dual shadow-volume product intent (why two holders) — still open.  
5. Runtime / bit-exact / differential (terminal coverage false; no Launcher).  
6. Ghidra `get_function_by_address` signature still shows `undefined FUN_*(void)` while decompile recovers stack/`in_EAX` host — duals correctly privilege decompile + caller over stale prototype (not dual failure).

---

## Factual error found (stage-2 WireColor)

**Stage-2 WireColor is documented as (0, 0, 1, 0.5) but live decompile packs (0, 1, 0, 0.5).**

Stack layout for color packs (same as emissive RGBA):

- `local_10` = R, `local_c` = G, `local_8` = B, `local_4` = A  

Stage-2 Wire sets `local_10=0`, `local_c=g_flOne`, `local_8=0`, `local_4=0.5` → **green wire**, not blue.

Corrected stage colors:

| Slot | Solid | Wire |
|---|---|---|
| `+0x30` | (0,1,0,0.5) | **(0,1,0,0.5)** ← dual prose wrong |
| `+0x38` | (0,0,1,0.5) | (0,0,1,0.5) |

Full write-up: [`ADV_aa_0098df00_w37_adversarial.md`](ADV_aa_0098df00_w37_adversarial.md).

Impact: dual **tables/comments** wrong; clean twin **assignments** already match binary. Severity medium for doc/port consumers of prose only.

---

## Dual quality verdict (not bare LGTM)

### `aa_0098fd80` — **PASS** (`accept-with-gaps` stands)

A/B are independent-enough in role (fidelity vs attack table), seal the same high-value facts (ABI, sole caller, slot, strings, floats, constant-0), and keep product English / helper ECX open. Independent re-verify found **no** CF, float, string, return, or caller contradictions. Artifact chain (raw + W37 re-verify append, annotated, clean twin, function record) is coherent.

### `aa_0098df00` — **PASS-WITH-ISSUE** (`accept-with-gaps` structural seal OK; **one sealed color claim fails**)

Strengths:

- Correct three-stage ladder vs sibling single-slot.  
- EAX host vs stack host sibling correctly distinguished and adversarial-attacked.  
- Host size 0x40, three zeroed holders, sole xref, emissive 0.2, plates, return 0 all re-confirmed.  
- Clean twin CF body is decompile-faithful.

Defect:

- Stage-2 WireColor **(0,0,1,0.5)** is a **false sealed claim** repeated across report, A, B, function record, annotated tables, and named-clean PURPOSE header. Annotated pseudocode even assigns green while commenting blue (self-inconsistency).  

This is not enough to reject the dual wholesale (ABI/slots/stages remain solid), but it is enough that **prose must not be treated as fully sealed on shadow color packs** until owner corrects stage-2 Wire. Documented in `ADV_aa_0098df00_w37_adversarial.md`; dual files **not** rewritten by this verifier.

### Pair / process quality

| Dimension | Assessment |
|---|---|
| Dual A+B present for both VAs | Yes |
| Cross-unit “do not merge” guidance | Sound (0x30 vs 0x40, 0.4 vs 0.2, shadow stages) |
| Shared-float name hygiene | Sound |
| Terminal coverage honesty | Sound (`false`) |
| OWN-ONLY hygiene / no ledger edits claimed | Outside this verifier’s rewrite scope |
| Spot-check vs Ghidra live | `0098fd80` clean; `0098df00` one color-table error |

---

## Summary

| VA | Dual quality | Verdict retention | Action |
|----|--------------|-------------------|--------|
| `0x0098fd80` | **PASS** | keep **accept-with-gaps** | none required |
| `0x0098df00` | **PASS-WITH-ISSUE** | keep **accept-with-gaps** for CF/ABI; **correct stage-2 Wire prose** | owner fix via ADV note |

**ADV artifacts written:**

- `docs/reconstruction/reviews/ADV_wave37_spotcheck_0098fd80_0098df00.md` (this file)  
- `docs/reconstruction/reviews/ADV_aa_0098df00_w37_adversarial.md` (WireColor factual error)
