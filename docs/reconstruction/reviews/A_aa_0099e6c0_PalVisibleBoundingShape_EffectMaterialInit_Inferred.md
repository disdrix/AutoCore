# Review A (reconstruction fidelity): `aa_0099e6c0` PalVisibleBoundingShape_EffectMaterialInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099e6c0` |
| **VA** | `0x0099e6c0`–`0x0099e894` (**469 B**) |
| **Canonical name** | `PalVisibleBoundingShape_EffectMaterialInit_Inferred` |
| **Ghidra name** | `FUN_0099e6c0` |
| **Review date** | `2026-07-29` (W36-H dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-H) |
| **Counterpart** | `reviews/B_aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md` |
| **System** | mesh host FX / material init |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 469 B + strings) + `analyze_function_complete` + xrefs |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Post-ctor init for HostPtrTable12 **slot 0**: load **`PalVisibleBoundingShape.fx`**, configure solid/wire diffuse+emissive material params on `self+0x20`, refcount-swap resource handle, return OR of stage statuses.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0099e6c0_FUN_0099e6c0.md` (+ W36-H full hex) |
| Annotated | `docs/reconstruction/raw/aa_0099e6c0_FUN_0099e6c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalVisibleBoundingShape_EffectMaterialInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099e6c0.cpp` |
| Function records | `aa_0099e6c0_FUN_0099e6c0.md`, `…_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md` |
| Live | decompile ≡ raw CF; 469 B hex ends `83c468 c3`; 5 product strings via `read_memory` |
| Context | Sole caller W35-E HostPtrTable12 after `FUN_00748960` + dual vtbl |

---

## 3. Signature (sealed)

```c
uint32_t __fastcall PalVisibleBoundingShape_EffectMaterialInit_Inferred(void *self /* ECX */);
```

| Slot | Source | Conf |
|---|---|---|
| self | ECX (`MOV EDI,ECX`; uses `EDI+0x20`) | **High** |
| return | EAX = `uVar4\|uVar5\|…\|uVar10` | **High** |
| stack formals | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| FX path string | **Yes** (`0x00a244b0`) | **High** |
| Four material names | **Yes** (`0x00aa6ce8..b4`) | **High** |
| Handle @ `self+0x20` | **Yes** | **High** |
| `FUN_0098f2b0(200)` | **Yes** | **High** |
| Refcount AddRef/Release | **Yes** | **High** |
| Status OR return | **Yes** | **High** |
| Helper full contracts | open | **Low** |

---

## 5. Gaps / open

1. Dual-vtbl product plate for slot-0 subclass (`00aa37b4` / `00aa37a8`).
2. Unowned FX/material helper contracts.
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI + product FX/material strings + sole-caller wiring sealed; helper internals residual.
