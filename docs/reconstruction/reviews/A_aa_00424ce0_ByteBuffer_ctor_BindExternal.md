# Review A (reconstruction fidelity): `aa_00424ce0` ByteBuffer_ctor_BindExternal

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424ce0` |
| **VA** | `0x00424ce0` |
| **Canonical name** | `ByteBuffer_ctor_BindExternal` (inferred; Ghidra `FUN_00424ce0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00424ce0_ByteBuffer_ctor_BindExternal.md` |
| **System** | network-bitstream / TNL ByteBuffer |
| **Evidence pass** | Live `batch_decompile` + xrefs; vtbl `PTR_LAB_009d7b00` sealed as ByteBuffer in skills HB + TNL duals; callers `VehicleNet_PostCorrectionEvent`, `FUN_0098b8b0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**ByteBuffer / refcounted buffer wrapper constructor** binding an **external** data pointer (does **not** take ownership):

```
this[4] = sizeOrCap (param_3)
this[1] = 0          // refcount seed path A
this[2] = 0
*this   = &PTR_LAB_009d7b00   // ByteBuffer vtbl (shared with TNL_ByteBuffer_* / skills HB wrap)
this[3] = dataPtr (param_2)
*(byte*)(this+5) = 0  // owns=0  (byte at offset +0x14)
```

Layout (0x18 object, dwords):

| Off | Field | Init |
|---|---|---|
| +0x00 | vtbl | `009d7b00` |
| +0x04 | ref A | 0 |
| +0x08 | ref B | 0 |
| +0x0C | data* | param_2 |
| +0x10 | size | param_3 |
| +0x14 | owns | 0 |

Contrast full owning ctor paths (e.g. skills HB `FUN_0042b250` family) that set owns=1. This unit always **owns=0** — external lifetime.

**Callers:** `VehicleNet_PostCorrectionEvent` (3 call sites in xrefs), `FUN_0098b8b0`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00424ce0_FUN_00424ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_00424ce0_FUN_00424ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00424ce0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00424ce0_FUN_00424ce0.md` |
| Related | `reviews/A_aa_00637750_TNL_ByteBuffer_UnpackData.md`, `A_aa_005b2690_VehicleNet_UnpackOwnerSkillsHB.md` |

**Three-rep:** present.

---

## 3. Signature

```c
void __thiscall ByteBuffer_ctor_BindExternal(void *this, void *data, uint32_t size);
// owns flag forced 0
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Field stores order as decompile | **Yes** | **High** |
| vtbl 009d7b00 | **Yes** | **High** |
| owns=0 | **Yes** | **High** |
| No heap / no free | **Yes** | **High** |
| Clean ≡ raw | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ByteBuffer-class ctor, vtbl 009d7b00 | **High** | shared evidence |
| External bind owns=0 | **High** | body |
| data@+0xC size@+0x10 | **High** | body |
| Exact C++ product name | **Probable** | TNL vs engine alias |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Distinguish sibling ctors that set owns=1 / allocate.
2. Refcount fields +0x4/+0x8 protocol (inc path not in this unit).

**Verdict:** **accept-with-gaps**
