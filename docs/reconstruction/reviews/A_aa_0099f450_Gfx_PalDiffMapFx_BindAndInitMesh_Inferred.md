# Review A (reconstruction fidelity): `aa_0099f450` Gfx_PalDiffMapFx_BindAndInitMesh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099f450` |
| **VA** | `0x0099f450`–`0x0099f5c3` (**372 B** / `0x174`) |
| **Canonical name** | `Gfx_PalDiffMapFx_BindAndInitMesh_Inferred` |
| **Ghidra name** | `FUN_0099f450` |
| **Review date** | `2026-07-29` (W36-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-I) |
| **Counterpart** | `reviews/B_aa_0099f450_Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.md` |
| **System** | gfx / PalDiffMap.fx host material + mesh init |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `read_memory` (full 372 B) + `analyze_function_complete` + callers/xrefs + float4/`DiffuseTexture` string reads. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only. No Launcher. No parent ledger.

---

## 1. Purpose

On a dual-vtbl gfx host (HostPtrTable slot8):

1. Look up `"PalDiffMap.fx"` and bind into material slot **`host+0x20`**.
2. Resolve and set **MatAmbient / MatDiffuse / MatSpecular / MatEmissive** from constant float4s.
3. Optionally run DiffuseTexture path when entry **EAX≠0**.
4. Refcount-swap a derived material if `FUN_0073d940` returns one.
5. Init mesh/buffer via `FUN_0099f270(scale, 1.0f)` with **EDI=host**.
6. Return OR of status codes.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-I append + full hex) | `docs/reconstruction/raw/aa_0099f450_FUN_0099f450.md` |
| Annotated | `docs/reconstruction/raw/aa_0099f450_FUN_0099f450.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099f450.cpp` |
| Function records | `functions/aa_0099f450_FUN_0099f450.md`, `…_Gfx_PalDiffMapFx_BindAndInitMesh_Inferred.md` |
| Live | decompile ≡ raw CF; 372 B hex; 1 caller |
| Context | W35-E HostPtrTable12 slot8; ResourceCache_LookupByName |

---

## 3. Signature (sealed)

```c
// stdcall RET 8; optional EAX third (sole caller 0)
uint32_t Gfx_PalDiffMapFx_BindAndInitMesh_Inferred(void* host, uint32_t scale_bits);
```

| Slot | Source | Conf |
|---|---|---|
| host | stack `[esp+4]` after frame → ESI | **High** |
| scale_bits | stack `[esp+8]` → pushed to `0099f270` | **High** |
| optional EAX | `MOV EBX,EAX` at entry; sole caller `XOR EAX,EAX` | **High** |
| RET | `C2 08 00` | **High** |
| return | OR accumulator in EAX | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Lookup PalDiffMap.fx | **Yes** | **High** |
| mat = host+0x20; bind effect | **Yes** | **High** |
| Four Mat* params + float4 consts | **Yes** (`00afdf40` white, `00afdf30` blackA1) | **High** |
| Optional DiffuseTexture (`00a9ede4`) | **Yes** CF; dead at sole xref | **High** |
| Derived material refcount swap | **Yes** | **High** |
| Mesh init scale + 1.0f | **Yes** (`0x3f800000`) | **High** |
| Product host English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB plate for host dual-vtbl class (`00aa33fc` / `00aa33ec`).
2. Full duals of nested callees (`009701d0`, `0096fff0`, `0073d940`, `0099f270`, `0043ed30`) — not owned.
3. Optional EAX semantic when non-zero (no sealed live caller).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI/CF/strings/constants/sole-caller sealed; product English + nested residual.
