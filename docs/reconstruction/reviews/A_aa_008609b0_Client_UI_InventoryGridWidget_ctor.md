# Review A (reconstruction fidelity): `aa_008609b0` Client_UI_InventoryGridWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008609b0` |
| **VA** | `0x008609b0` |
| **Canonical name** | `Client_UI_InventoryGridWidget_ctor` (Ghidra `FUN_008609b0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008609b0_Client_UI_InventoryGridWidget_ctor.md` |
| **System** | `inventory-transfer` / trade UI grid |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** **Inventory grid widget constructor** for the 2D trade dialog (and same class elsewhere if allocated with size `0x578`).

```
FUN_00792d20(this)                 // container base
*this = &PTR_FUN_00a6476c          // grid vtbl
init grid-only fields
return this
```

**Sole direct CALL xref (signature callers):** `CDlgTrade2d_CreateChildWidgets` @ `0x008847f0` — dual grids at host `+0x588` (you) / `+0x58c` (them), then XML load + `FUN_00860700` rebuild + optional `InventoryGrid_SetOwnerFlag_Inferred`.

---

## 2. Artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008609b0_FUN_008609b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008609b0_FUN_008609b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008609b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008609b0_FUN_008609b0.md` |
| Caller dual | `reviews/A_aa_008847f0_CDlgTrade2d_CreateChildWidgets.md` |
| Live | decompile ≡ raw (33 insn, 1 BB) |

---

## 3. Signature / field init

```c
undefined4 * Client_UI_InventoryGridWidget_ctor(undefined4 *this);
// operator_new(0x578) in Trade CreateChildWidgets
```

| Offset (byte) | Index | Value | Conf | Role (inferred) |
|---|---|---|---|---|
| vtbl | — | `PTR_FUN_00a6476c` | **High** | grid class |
| `+0x574` | `[0x15d]` | 0 | **High** | inv object* cleared (Trade later sets `+0x56c`) |
| `+0x490` | `[0x124]` byte | 0 | **High** | flag |
| `+0xbf` | — | 0 | **High** | host-prep related bit |
| `+0x4fc` | `[0x13f]` byte | 0 | **High** | flag |
| `+0x496` | — | 1 | **High** | enable-style |
| `+0x570/+0x56c` | `[0x15c]/[0x15b]` | 0 | **High** | slots / bound inv residual |
| `+0x504/+0x508` | `[0x141]/[0x142]` | 1 | **High** | page/scale ones |
| `+0x564` | `[0x159]` byte | 0 | **High** | flag |
| `+0x568` | `[0x15a]` | 0 | **High** | — |
| `+0x500` | `[0x140]` | 0 | **High** | — |

Note: Trade dual stores inventory object at **`grid+0x56c`** after ctor — index `[0x15b]` zeroed here is that slot.

---

## 4. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Role = inventory grid ctor | **High** | Trade dual + rebuild/owner-flag callees |
| Size `0x578` | **High** | Trade `operator_new` |
| Extends `FUN_00792d20` | **High** | sole callee |
| Full grid layout | **Tentative** | post-ctor fields from Trade dual |
| Runtime | **Open** | — |

---

## 5. Gaps

1. Product class name (CNDUIInventoryGrid?).
2. Exact meaning of all grid-only flags.
3. Whether other dialogs construct same type via indirect paths not in callers list.
