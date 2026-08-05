# Review A (reconstruction fidelity): `aa_005a2120` ByteBuffer_RebindData

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2120` |
| **VA** | `0x005a2120` |
| **Canonical name** | `ByteBuffer_RebindData` (inferred; Ghidra `FUN_005a2120`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005a2120_ByteBuffer_RebindData.md` |
| **System** | network-bitstream / PostCorrectionEvent buffer attach |
| **Evidence pass** | Live `batch_decompile`; sole caller family `VehicleNet_PostCorrectionEvent`; pairs with ByteBuffer owns flag at +0x14 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Rebind data pointer / size / owns** on a ByteBuffer-shaped object:

```
if (this+0x14 owns != 0):
  this+0x14 = 0
  free(*(void**)(this+0x0C))   // free prior owned payload
this+0x0C = param_2   // new data*
this+0x10 = param_3   // new size
this+0x14 = param_4   // new owns flag
```

Does **not** touch vtbl or refcounts. Safe replace when owns was set; when owns was clear, prior pointer is abandoned without free (external lifetime).

**Caller:** `VehicleNet_PostCorrectionEvent` `0x005f7360` (B dual notes: alloc wrapper → `FUN_005a2120` → push).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a2120_FUN_005a2120.md` |
| Annotated | `docs/reconstruction/raw/aa_005a2120_FUN_005a2120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005a2120.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a2120_FUN_005a2120.md` |
| Related ctor | `reviews/A_aa_00424ce0_ByteBuffer_ctor_BindExternal.md` |

**Three-rep:** present.

---

## 3. Signature

```c
void __thiscall ByteBuffer_RebindData(void *this, void *data, uint32_t size, uint8_t owns);
```

| Off | Field | Role |
|---|---|---|
| +0x0C | data* | replaced |
| +0x10 | size | replaced |
| +0x14 | owns | free-if-set then replace |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| owns gate → clear + free | **Yes** | **High** |
| store data/size/owns | **Yes** | **High** |
| No vtbl / refcount touch | **Yes** | **High** |
| Clean ≡ raw | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Free-if-owns then rebind | **High** | body |
| Offsets match ByteBuffer layout | **High** | ctor twin +0xC/+0x10/+0x14 |
| Used by PostCorrectionEvent | **High** | sole caller |
| CRT free vs operator_delete | **High** | `free` in decompile |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Whether size param is bytes vs capacity in all call sites.
2. Interaction with refcount release (vtbl+8) on full object destroy — out of scope.

**Verdict:** **accept-with-gaps**
