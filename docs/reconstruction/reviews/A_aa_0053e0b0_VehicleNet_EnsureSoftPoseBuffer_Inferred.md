# Review A (reconstruction fidelity): `aa_0053e0b0` VehicleNet_EnsureSoftPoseBuffer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e0b0` |
| **VA** | `0x0053e0b0` |
| **Canonical name** | `VehicleNet_EnsureSoftPoseBuffer_Inferred` (was `FUN_0053e0b0`) |
| **Ghidra symbol** | `FUN_0053e0b0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053e0b0_VehicleNet_EnsureSoftPoseBuffer_Inferred.md` |
| **System** | `input-drive-control` / shared soft-buffer accessor |
| **Dual status** | **Present** |
| **Verdict** | **accept** — lazy alloc at this+0x28 sealed |

---

## 1. Purpose

**Lazy get-or-allocate** for the soft pose buffer pointer at **`this+0x28`**:

```
if (*(this+0x28) == 0)
  *(this+0x28) = FUN_0053e020();  // 0x40 soft buffer
return *(this+0x28);
```

Used by network soft path (via direct alloc sites and integrate), air-stab speed gate consumers, creature graphics paths, etc. **Does not** fill pose fields — only ensures storage.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0053e0b0` |
| Raw | `raw/aa_0053e0b0_FUN_0053e0b0.md` |
| Alloc sibling | `FUN_0053e020` dual this batch |

---

## 3. Confidence

| Claim | Confidence |
|---|---|
| Gate on this+0x28 null | **High** |
| Alloc via 0053e020 | **High** |
| Returns buffer pointer | **High** |
| Interprets buffer as velocity | **Consumer residual** (airStab reads float[3] at returned ptr; layout may be pos@0 or consumer-specific fill) |

**Verdict:** **accept**
