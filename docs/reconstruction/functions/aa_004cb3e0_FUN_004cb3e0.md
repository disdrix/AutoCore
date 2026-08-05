# Function record: FUN_004cb3e0 / CVOGObject_StoreLocalPosition4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb3e0` |
| **Canonical name** | `FUN_004cb3e0` (Ghidra) |
| **Proposed name** | `CVOGObject_StoreLocalPosition4_Inferred` |
| **Address** | `0x004cb3e0` |
| **Body span** | `004cb3e0` – `004cb409` (42 B; `ret 4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object pose / local position override (`this+0x240..+0x24c`) |
| **Completion status** | **Dual sealed (OWN-ONLY A+B, 2026-07-29)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold: `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb3e0` (misleading — parent trap string only)
- Dual reviews: `reviews/A_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md`, `reviews/B_aa_004cb3e0_CVOGObject_StoreLocalPosition4_Inferred.md`
- Scratch: `reviews/a_004cb3e0.md`

## Purpose

Unconditional **4×dword (float4)** store into **`this+0x240, +0x244, +0x248, +0x24c`**. No NaN trap, no flag gate, no callees. Gating lives in callers (`FUN_004c3a40`); bypass also calls this leaf (`FUN_005cd3b0`).

## Signature (sealed)

```c
// MSVC __thiscall — ECX = object; stack = const float* / uint32_t* (4 elements); ret 4
void __thiscall CVOGObject_StoreLocalPosition4_Inferred(void *self, const uint32_t *in);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cb3e0_FUN_004cb3e0.md`
- Annotated: `docs/reconstruction/raw/aa_004cb3e0_FUN_004cb3e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004cb3e0.cpp`
- Named scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb3e0.cpp`

## Callers / callees

| Direction | Target | Site / notes |
|---|---|---|
| Caller | `FUN_004c3a40` | `0x004c3aa6` — gated SetLocalPosition4 |
| Caller | `FUN_005cd3b0` | `0x005ce8a3` — bypass path |
| Callees | *(none)* | Straight-line stores only |

## Confidence

| Claim | Level |
|---|---|
| Control flow / four offsets / `ret 4` | **High** |
| No gate/NaN in this body | **High** |
| Caller inventory (2 sites) | **High** |
| “Local position” semantic label | **Probable** |
| Product English name | **Open** (`_Inferred`) |
