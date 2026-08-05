# Function record: UI_DefaultMessageHandler

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087b500` |
| **Canonical name** | `UI_DefaultMessageHandler` (INFERRED) |
| **Address** | `0x0087b500` |
| **Body** | `0x0087b500`–`0x0087b54f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI dialog / window message base |
| **Completion status** | **Dual A/B sealed** — 2026-07-29 W17-F |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0087b500`
- Legacy scaffold: `Named_CalleeOf_Mission_Client_ClaimSelectedReward_0087b500`
- Prefer **`UI_DefaultMessageHandler`** paths for dual seal

## Purpose

Default UI window/dialog **message fallthrough**:

1. Message codes **`7..15`** → return **1** (handled / swallow).
2. Else call **`this->vtbl+0xD8`**; if false → **0**.
3. If **`this+0x2B0`** parent non-null → forward `(msg, controlId)` to **`parent->vtbl+0x338`**.
4. Else → **0**.

Hot default for dialog jump-table cases that do not own a message class (close-btn non-activate, attribute-point non-handled events, claim-reward residual, etc.).

## Signature (machine-sealed)

```c
// __thiscall; ret 8
unsigned __thiscall UI_DefaultMessageHandler(void *pThis, int msg, unsigned controlId);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0087b500_FUN_0087b500.md`
- Annotated: `docs/reconstruction/raw/aa_0087b500_FUN_0087b500.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_DefaultMessageHandler.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0087b500_UI_DefaultMessageHandler.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0087b500_UI_DefaultMessageHandler.md`
- Legacy clean: `docs/reconstruction/reconstructed-exact/FUN_0087b500.cpp` (superseded)

## Callers / callees

| Direction | Notes |
|---|---|
| Callers | ~109 xrefs; dialog switches under `0x008*` (e.g. `UI_OnAttributePointClick_Inferred`, `UI_Case_CloseBtn_9c40`, many FUN_008*) |
| Callees | Virtual only: `this->vtbl+0xD8`, `parent->vtbl+0x338` (no direct FUN_* body calls) |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** (decomp ≡ machine) |
| `__thiscall` + `ret 8` + 2 stack args | **High** |
| Parent at `+0x2B0` | **High** |
| msg band `7..15` → 1 | **High** |
| Product class/method name | **Tentative** (INFERRED) |
| Semantic of `vtbl+0xD8` | **Tentative** |
