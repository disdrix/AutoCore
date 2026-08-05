# Review A (reconstruction fidelity): `aa_0098fd80` PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fd80` |
| **VA** | `0x0098fd80`–`0x0098fee9` |
| **Canonical name** | `PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred` |
| **Ghidra name** | `FUN_0098fd80` |
| **Review date** | `2026-08-04` (W37-A dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-A) |
| **Counterpart** | `reviews/B_aa_0098fd80_PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.md` |
| **System** | palantir graphics / PalTool material (no-map) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_xrefs` + caller `FUN_0073c810` decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Post-ctor single-channel material init for HostPtrTable12 **slot9** host (size **0x30**):

1. Bind `PalToolMaterialNoMap.fx` into material slot **`host+0x28`**.
2. Set `DepthBias=0.001`, `GhostAlpha=0.1`.
3. Bind MatDiffuse / MatSpecular / MatEmissive (emissive RGBA **1,0.4,0.4,1**).
4. `FUN_0073d940` refcount-swap holder.
5. Return constant **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0098fd80_FUN_0098fd80.md` (+ W37-A re-verify append) |
| Annotated | `docs/reconstruction/raw/aa_0098fd80_FUN_0098fd80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098fd80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0098fd80_FUN_0098fd80.md` |
| Live decompile | ≡ raw CF (2026-08-04) |
| Body range | `get_function_by_address`: `0098fd80`–`0098fee9` |
| Xref | sole `UNCONDITIONAL_CALL` from `0073cac3` in `FUN_0073c810` |
| Caller | `operator_new(0x30)` → `FUN_00457ac0` → zero `+0x28` / flags → `FUN_0098fd80(pvVar2)` |
| Floats | `read_memory` `DAT_00a0f720`=`cd cc cc 3e` (0.4f); pool `@a0f72c`=0.001, `@a0f730`=0.1, `@a0f2a0`=1.0 |
| Callees | `FUN_00989e00`, `FUN_009701d0`, `FUN_00442640`, `FUN_00752370`, `FUN_0096fff0`, `FUN_0073d940` |
| Context | Sibling `PalToolNoMap_Host0x44_DualChannelInit_Inferred` (`0x00731130`); HostPtrTable12 bootstrap `FUN_0073c810` |

---

## 3. Signature (sealed)

```c
// stack host*; returns 0
uint32_t PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred(void *host);
```

| Slot | Source | Conf |
|---|---|---|
| host | stack formal; caller pushes `pvVar2` | **Confirmed** |
| return | constant 0 | **High** |
| thiscall | **No** — stack host | **High** |
| material field | `host+0x28` | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Name resolve + effect bind | **Yes** | **High** |
| DepthBias / GhostAlpha scalars | **Yes** (0.001 / 0.1) | **Confirmed** |
| MatDiffuse / Specular / Emissive null→-1 ladder | **Yes** | **High** |
| Emissive pack (1,0.4,0.4,1) | **Yes** | **Confirmed** |
| Refcount vtbl+4 / +8 swap | **Yes** | **High** |
| Always return 0 (no OR-status like 00731130) | **Yes** | **High** |
| Product English host class | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB English for 0x30 host type beyond effect plate.
2. Exact thiscall ECX wiring for `FUN_009701d0` / `FUN_00442640` (decompiler drops this).
3. Full contracts of unowned callees.
4. Runtime / bit-exact / differential.
5. Shared-float symbol names (`g_flMsToSeconds_Inferred`, `g_flMultiKillCountBlend`) are **not** product shader semantics — numeric values only.

**Verdict:** **accept-with-gaps** — ABI, sole caller, host size/slot, strings, float packs, refcount ladder sealed; product English + helper depth open.
