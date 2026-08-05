# Review A (reconstruction fidelity): `aa_0098df00` PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098df00` |
| **VA** | `0x0098df00`–`0x0098e29f` |
| **Canonical name** | `PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred` |
| **Ghidra name** | `FUN_0098df00` |
| **Review date** | `2026-08-04` (W37-A dual seal; wave36 residual) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-A) |
| **Counterpart** | `reviews/B_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` |
| **System** | palantir graphics / PalTool material + visible shadow volume |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_xrefs` + caller `FUN_0073c810` decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Post-ctor **three-stage** material init for HostPtrTable12 **slot10** host (size **0x40**):

| Stage | Slot | Effect | Notable params |
|---|---|---|---|
| 1 | `+0x28` | `PalToolMaterialNoMap.fx` | DepthBias 0.001, GhostAlpha 0.1, Mat* emissive **(1,0.2,0.2,1)** |
| 2 | `+0x30` | `PalVisibleShadowVolume.fx` | Solid **(0,1,0,0.5)**, Wire **(0,1,0,0.5)** (ADV 2026-08-04: was wrongly sealed as blue wire) |
| 3 | `+0x38` | `PalVisibleShadowVolume.fx` | Solid **(0,0,1,0.5)**, Wire **(0,0,1,0.5)** |

Each stage ends with `FUN_0073d940` refcount-swap. Always returns **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0098df00_FUN_0098df00.md` (+ W37-A re-verify append) |
| Annotated | `docs/reconstruction/raw/aa_0098df00_FUN_0098df00.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098df00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0098df00_FUN_0098df00.md` |
| Live decompile | ≡ raw CF (2026-08-04) |
| Body range | `get_function_by_address`: `0098df00`–`0098e29f` |
| Xref | sole `UNCONDITIONAL_CALL` from `0073cb1b` in `FUN_0073c810` |
| Caller | `operator_new(0x40)` → `FUN_00457b30` → zero `+0x28/+0x30/+0x38` + flags → `FUN_0098df00()` (host left in **EAX**) |
| Floats | `read_memory` `DAT_00a0f70c`=`cd cc 4c 3e` (0.2f); `DAT_00a0f298`=`00 00 00 3f` (0.5f) |
| Callees | same set as `0098fd80` (multi-stage) |
| Context | Sibling `0098fd80` (single-slot Host0x30); HostPtrTable12 bootstrap `FUN_0073c810` slot10 |

---

## 3. Signature (sealed)

```c
// host in EAX; no stack formal at call site
uint32_t PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred(void *host /* EAX */);
```

| Slot | Source | Conf |
|---|---|---|
| host | decompiler `in_EAX` + caller store-then-call | **High** |
| return | constant 0 | **High** |
| stack args | **none** at call site | **High** |
| slots | `+0x28`, `+0x30`, `+0x38` | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Stage1 PalToolMaterialNoMap + Mat* | **Yes** | **High** |
| Stage1 emissive (1,0.2,0.2,1) ≠ sibling 0.4 | **Yes** | **Confirmed** |
| Stage2 Solid green / Wire blue @ +0x30 | **Yes** | **Confirmed** |
| Stage3 Solid blue / Wire blue @ +0x38 | **Yes** | **Confirmed** |
| Triple refcount-swap | **Yes** | **High** |
| Always return 0 | **Yes** | **High** |
| Product English / dual-shadow intent | open | **Tentative** |

---

## 5. Gaps / open

1. Product/PDB English for 0x40 host and dual shadow-volume slots.
2. Why two nearly-identical shadow-volume materials (green solid vs blue solid).
3. Exact thiscall ECX for helpers; unowned callee full contracts.
4. Runtime / bit-exact / differential.
5. Shared-float pool names are numeric-only (not product shader labels).

**Verdict:** **accept-with-gaps** — three-stage ladder, ABI (EAX host), sole caller, host size/slots, strings, float packs sealed; product English + dual-shadow intent open.
