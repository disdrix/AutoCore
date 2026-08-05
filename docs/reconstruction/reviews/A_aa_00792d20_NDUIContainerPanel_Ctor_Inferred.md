# Review A (reconstruction fidelity): `aa_00792d20` NDUIContainerPanel_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792d20` |
| **VA** | `0x00792d20` |
| **Canonical name** | `NDUIContainerPanel_Ctor_Inferred` (Ghidra `FUN_00792d20`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00792d20_NDUIContainerPanel_Ctor_Inferred.md` |
| **System** | `client-ui` / NDUI container / inventory grid base |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** **Intermediate container/panel ctor** between base NDUI window and inventory grid:

1. `FUN_007b5dd0(this, 0)` base window.
2. Vtbl → `PTR_FUN_00a98f44`.
3. `FUN_0040fb90()` → store at `this+0x4e0` (`[0x138]`).
4. Init scroll/page/flags (many `+0x488`…`+0x4f8` fields).
5. Five `operator_new(0x34)` helper objects via `FUN_004280f0` / `FUN_00428480` / `FUN_00428700` / `FUN_00428980` / `FUN_004280f0` → slots `[0x132]…[0x136]`.

**Direct subclass:** `FUN_008609b0` (Trade inventory grid, size `0x578`) calls this then installs grid vtbl.

Also used as CreateChildWidgets callee chain root for grid-like hosts.

---

## 2. Artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00792d20_FUN_00792d20.md` |
| Annotated | `docs/reconstruction/raw/aa_00792d20_FUN_00792d20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00792d20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00792d20_FUN_00792d20.md` |
| Live | decompile ≡ raw (139 insn, 15 BB, CC 5, 12 calls) |

---

## 3. Signature / flow

```c
undefined4 * FUN_00792d20(undefined4 *param_1 /*this*/);
// returns this; SEH LAB_009b40aa
```

| Stage | Conf |
|---|---|
| Base + vtbl `00a98f44` | **High** |
| Helper `FUN_0040fb90` → `[0x138]` | **High** |
| Sentinel -1 triple `[0x126..0x128]` | **High** |
| Flag cluster `+0x48c..+0x497`, `+0xbf`, `[0x30]` | **High CF** |
| Dim default `[300]=DAT_00a0f71c` | **High** |
| Five 0x34 helpers at `[0x132..0x136]` (null-safe) | **High** |
| Mode ones `[0x13a..0x13e]=1` | **High** |

---

## 4. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Role = container/grid-base ctor | **High** | sole callee of grid ctor; base+helpers |
| Product class name | **Tentative** | NDUI list/scroll container family |
| Helper object types (0x34) | **Tentative** | same family as HostPrep `FUN_004280f0` |
| Runtime | **Open** | — |

---

## 5. Gaps

1. Product name for container vs grid.
2. Roles of five 0x34 helpers.
3. Full semantics of `FUN_0040fb90` result.
