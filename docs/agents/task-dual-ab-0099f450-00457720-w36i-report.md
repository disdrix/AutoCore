# Dual A/B report — W36-I OWN `aa_0099f450` + `aa_00457720`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-I  
**Scope:** VAs `0x0099f450`, `0x00457720` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs + string/float constant reads. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-I).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0099f450` Gfx_PalDiffMapFx_BindAndInitMesh_Inferred | **accept-with-gaps** — stdcall RET8 + mat@+0x20 + Mat* float4s + mesh tail sealed; product host English + nested residual |
| `aa_00457720` Class_00aa33a4_PlacementCtor_Inferred | **accept-with-gaps** — stack-this RET4 + vtbl + three 2×8 arrays + span 0x44 sealed; product English + unwritten head open |

---

## VA `0x0099f450` — sealed facts

1. **Body:** `0x0099f450`–`0x0099f5c3` (**372 B** / `0x174`; pad `CC`).
2. **ABI:** stdcall **2** stack formals (`host*`, `float scale_bits`); optional **EAX** third (saved → EBX); frame `SUB ESP,0x14` + EBX/EBP/ESI/EDI; **`RET 0x8`**; return **OR status** in EAX. Decompiler void/plate — **bytes win**.
3. **Semantics:**
   - `ResourceCache_LookupByName("PalDiffMap.fx")` (`FUN_00989e00`, ECX=`DAT_00d1eac8`).
   - Material slot **`host+0x20`**; `FUN_009701d0` bind effect.
   - For **MatAmbient / MatDiffuse / MatSpecular / MatEmissive**: index via `FUN_00752370` or −1 if mat null; on hit `FUN_0096fff0` with EAX = float4 const:
     - Ambient/Diffuse → `DAT_00afdf40` = **(1,1,1,1)**
     - Specular/Emissive → `DAT_00afdf30` = **(0,0,0,1)**
   - If entry EAX≠0: `FUN_0043ed30` with EAX=`"DiffuseTexture"` (`0x00a9ede4`); OR status. **Sole caller zeros EAX**.
   - `FUN_0073d940(*mat)`: if non-null, refcount-inc derived / dec old / store (vtbl+4 first ref, vtbl+8 last).
   - `FUN_0099f270(scale, 1.0f)` with **EDI=host**; OR final status.
4. **Classification:** **worker**.
5. **Callers (1):** `FUN_0073c810` @ `0x0073ca84` — HostPtrTable12 slot8; scale **10.0f** (`0x41200000`); `XOR EAX,EAX`.
6. **Callees:** `FUN_00989e00`, `FUN_009701d0`, `FUN_00752370`×4, `FUN_0096fff0`×4, `FUN_0043ed30` (gated), `FUN_0073d940`, `FUN_0099f270`.
7. **Name:** `Gfx_PalDiffMapFx_BindAndInitMesh_Inferred` (Ghidra `FUN_0099f450`; **Inferred** structural from strings + CF). **Reject** scaffold-only `Gfx_PalDiffMap_0099f450` without bind/mesh role.
8. **Decompile ≡ bytes** for CF ladder; **bytes win** on RET 8, optional EAX, float4-via-EAX, EDI host into mesh init.  
   Full hex: `83ec14535556578bd8689844a2008d44241450b9c8ead100e893a9feff8b7424288d4c241083c620518bcee8500dfdff8b0e83cfff85c98be8741168c0f8a2008d54241c52e8d62edbffeb08897c24148d4424148b0085c07c0e5056b840dfaf00e83a0bfdffeb028bc78b0e0be885c9741168ccf8a2008d44242050e89f2edbffeb08897c24148d4424148b0085c07c0e5056b840dfaf00e8030bfdffeb028bc78b0e0be885c97411685c6caa008d54242452e8682edbffeb08897c24148d4424148b0085c07c0e5056b830dfaf00e8cc0afdffeb028bc78b0e0be885c98d442414740d68b4f8a20050e8312edbffeb04897c24148b0085c07c0e5056b830dfaf00e8990afdffeb028bc70be885db740d53b8e4eda900e8c4f7a9ff0be88b0e518b0d1cf6d100e8c4e3d9ff8bd885db742383430401837b040175078b138bcbff52048b0e85c9740a01790475058b01ff5008891e8b4c242c8b7c2428680000803f51e8b8fcffff5f5e0bc55d5b83c414c20800`

### Gaps

- Product/PDB English for dual-vtbl host class.  
- Unowned nested callees’ full contracts.  
- Optional EAX meaning when non-zero (no sealed live site).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0099f450_Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0099f450_Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0099f450_FUN_0099f450.md` |
| Annotated | `docs/reconstruction/raw/aa_0099f450_FUN_0099f450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099f450.cpp` |
| Function | `docs/reconstruction/functions/aa_0099f450_FUN_0099f450.md` |
| Function named | `docs/reconstruction/functions/aa_0099f450_Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.md` |

---

## VA `0x00457720` — sealed facts

1. **Body:** `0x00457720`–`0x004577aa` (**139 B** / `0x8B`; pad `CC`).
2. **ABI:** stack **`self*`** placement ctor; SEH `LAB_009bca04`; ESI=self; **`RET 0x4`**; returns **self in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - `*self = &PTR_FUN_00aa33a4`.
   - `_eh_vector_constructor_iterator_(self+0x14, 8, 2, FUN_00437440, FUN_00437450)`.
   - Same at `self+0x24` with `LAB_00437630` / `FUN_00437640` (element: vtbl `00a9da80`, +4=0).
   - Same at `self+0x34` with `FUN_0096f530` / `FUN_0096f510` (**RefCountedPtr3Flags_DefaultCtor**, W35-G).
4. **Layout span 0x44** (matches sole caller `new(0x44)`):

| Off | Written | Content |
|-----|---------|---------|
| +0x00 | yes | vtbl `PTR_FUN_00aa33a4` |
| +0x04…+0x13 | **no** | unwritten by this ctor |
| +0x14…+0x23 | yes | 2 × 8-byte (vtbl `00a9db18`) |
| +0x24…+0x33 | yes | 2 × 8-byte (vtbl `00a9da80`) |
| +0x34…+0x43 | yes | 2 × RefCountedPtr3Flags |

5. **Classification:** **worker** (placement ctor).
6. **Callers (1):** `FUN_0073c810` @ `0x0073c99c` — HostPtrTable12 slot5; then `FUN_00731130` post-init (unowned).
7. **Callees:** `_eh_vector_constructor_iterator_` ×3 (element ctors/dtors above).
8. **Name:** `Class_00aa33a4_PlacementCtor_Inferred` (Ghidra `FUN_00457720`; **Inferred** from vtbl). **Reject** bare `FUN_00457720`.
9. **Decompile ≡ bytes** for three vector-ctor sites; **bytes win** on RET 4 + return-this.  
   Full hex: `64a1000000006aff6804ca9b005064892500000000568b742414685074430068407443006a026a088d4614c744241c0000000050c706a433aa00e8c5210300684076430068307643006a026a088d4e2451c644242001e8a92103006810f596006830f596006a026a088d563452c644242002e88d2103008b4c24048bc664890d000000005e83c40cc20400`

### Gaps

- Product/PDB class English.  
- Unwritten `+0x04…+0x13` (post-init residual).  
- Element product plates beyond vtbl/refcount shell.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00457720_Class_00aa33a4_PlacementCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00457720_Class_00aa33a4_PlacementCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00457720_FUN_00457720.md` |
| Annotated | `docs/reconstruction/raw/aa_00457720_FUN_00457720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00aa33a4_PlacementCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457720.cpp` |
| Function | `docs/reconstruction/functions/aa_00457720_FUN_00457720.md` |
| Function named | `docs/reconstruction/functions/aa_00457720_Class_00aa33a4_PlacementCtor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0099f450` | Port as **stdcall** `(host*, float scale) → status OR`; material at **`host+0x20`**. Defaults: ambient/diffuse white, specular/emissive (0,0,0,1). Mesh via nested `0099f270(scale, 1.0f)` with host in EDI convention. Do **not** invent ECX-thiscall. Bootstrap passes scale **10.0f** and optional EAX **0**. |
| `00457720` | Port as **stack placement ctor** size **0x44**, **RET 4**, return this. Three **2×8** arrays at +0x14/+0x24/+0x34; do **not** zero +0x04…+0x13 here. Pair slot5 with unowned post-init `00731130`. |

Shared: both are **sole callees of W35-E `HostPtrTable12_Bootstrap_EDI`** (slot8 init vs slot5 ctor). Co-owned only by W36-I partition; not the same object type.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0073c810` | W35-E HostPtrTable12_Bootstrap_EDI (sole caller of both) |
| `0x00989e00` | ResourceCache_LookupByName |
| `0x0096f530` / `0x0096f510` | W35-G RefCountedPtr3Flags default ctor / dtor |
| `0x00437440` / `0x00437630` | 8-byte vtbl-handle element ctors |
| `0x0099f270` | host mesh/buffer init (EDI=host) |
| `0x009701d0` / `0x0096fff0` / `0x0073d940` | material bind / set-param / derived lookup |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + get_function_by_address + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Rejected bare FUN plates and plate-only `Gfx_PalDiffMap` without bind/mesh role.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs / `uint8_t`).
