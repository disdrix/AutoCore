# Review A (reconstruction fidelity): `aa_005b1360` VehicleNet_UnpackOwnerIdentityBlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b1360` |
| **VA** | `0x005b1360` |
| **Canonical name** | `VehicleNet_UnpackOwnerIdentityBlock` (inferred; Ghidra `FUN_005b1360`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b1360_VehicleNet_UnpackOwnerIdentityBlock.md` |
| **System** | input-drive-control / GhostVehicle unpack |
| **Evidence pass** | Live `batch_decompile` + `read_memory` body + callers; pack twin `aa_005b1290`; parent `aa_005f7720` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Owner / identity seed unpack** — mirror of `VehicleNet_PackOwnerIdentityBlock` (`0x005b1290`). Reads fixed-width identity fields from a BitStream into a dest seed struct.

| Order | Wire | Dest write |
|---|---|---|
| 1 | **64 bits** | `dest+0x90` / `+0x94` (TFID halves) |
| 2 | **1 flag** | `dest+0x98` via `BitStream_readFlag` |
| 3 | **20-bit int** | `dest+0x04` |
| 4 | **18-bit int** | `dest+0x14` |
| 5 | **16 bits** (signed-extend) | `dest+0x1c` |
| 6 | **16 bits** (signed-extend) | `dest+0x20` |

**Callers:** `VehicleNet_UnpackGhostVehicle` (`0x005f7720`), `GhostCreature_UnpackUpdate` (`0x005d2e40`), `FUN_0060a820`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b1360_FUN_005b1360.md` |
| Annotated | `docs/reconstruction/raw/aa_005b1360_FUN_005b1360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b1360.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b1360_FUN_005b1360.md` |
| Pack twin dual | `reviews/A_aa_005b1290_VehicleNet_PackOwnerIdentityBlock.md` |
| Live | decompile ≡ raw; widths 0x40 / flag / 0x14 / 0x12 / 0x10 / 0x10 |

**Three-rep:** present.

---

## 3. Signature

```c
// BitStream* in ECX-thiscall chain for subcalls; free function form (stack):
// stack: BitStream* stream, IdentitySeed* dest
void VehicleNet_UnpackOwnerIdentityBlock(BitStream *stream, IdentitySeed *dest);
```

| Formal | Source | Conf |
|---|---|---|
| stream | stack → EDI; BitStream_* thiscall targets | **High** |
| dest | stack → ESI; stores to +0x90..+0x20 | **High** |
| Decompiler `short param_1` | **stack-slot reuse** for 16-bit races — not a true input | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| 64b TFID → +0x90/+0x94 | **Yes** | **High** |
| Flag → +0x98 | **Yes** | **High** |
| 20b → +0x04 | **Yes** | **High** |
| 18b → +0x14 | **Yes** | **High** |
| 16b → +0x1c then +0x20 (MOVSX) | **Yes** | **High** |
| No loops / no HB walk | **Yes** | **High** |
| Wire order ≡ pack twin | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Identity seed unpack (not skills HB) | **High** | CF; sibling `0x005b2690` is HB list |
| Wire widths | **High** | immediates |
| Dest offsets | **High CF** | live stores |
| Dest English field names | **Tentative** | TFID/CBID-ish/race; residual |
| Product name | **Tentative** | inferred from pack twin |
| Bit-exact / runtime | **Open** | deferred |

---

## 6. Gaps

1. Full IdentitySeed product layout beyond sealed stores.
2. Whether 18b dest+0x14 is same semantic as pack vtbl+0x244 metric.
3. Race equal-collapse on pack side is **writer-only**; unpack always stores raw 16b values.

**Verdict:** **accept-with-gaps**
