# Review A (reconstruction fidelity): `aa_0042b3a0` BitStream_BindFromBuffer

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b3a0` |
| **VA** | `0x0042b3a0` |
| **Canonical name** | `BitStream_BindFromBuffer` (inferred; Ghidra `FUN_0042b3a0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b3a0_BitStream_BindFromBuffer.md` |
| **System** | net / TNL BitStream |
| **Evidence pass** | Live `batch_decompile` + `read_memory` full body (`ret 8`); callers Damage/TNL unpack |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Initialize a **BitStream** object over an existing byte buffer (**non-owning** bind):

| Field | Offset | Value |
|---|---|---|
| vtable | +0x00 | `PTR_LAB_009d7b94` |
| ref / link | +0x04, +0x08 | 0 |
| data* | +0x0c | `buffer` arg |
| byte capacity | +0x10 | `size` arg |
| owns | +0x14 | **0** (does not free) |
| bitPos | +0x18 | 0 |
| error | +0x1c | 0 |
| flag +0x1d | +0x1d | 0 |
| bitMax / bitCap | +0x2c / +0x30 | `size * 8` |
| +0x34 | +0x34 | 0 |
| +0x38 string-cache flag area | +0x38 | 0 |

**Callers (combat/net unpack):** `EMSG_Sector_Damage_Unpack` (`0x00636f00`), `TNL_ByteBuffer_UnpackData` (`0x00637750`), siblings `0x006374f0` / `0x00637990`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0042b3a0_FUN_0042b3a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0042b3a0_FUN_0042b3a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0042b3a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0042b3a0_FUN_0042b3a0.md` |
| Live | body ends `ret 8`; vtbl imm `0x009d7b94` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = BitStream*
// stack: void* buffer, int sizeBytes   (ret 8)
void BitStream_BindFromBuffer(BitStream *this, void *buffer, int sizeBytes);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| buffer | stack → `this+0x0c` | **High** |
| sizeBytes | stack → `this+0x10`; bits = size*8 | **High** |
| Epilogue | `ret 8` | **High** (bytes) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| vtbl `009d7b94` | **Yes** | **High** |
| owns=0 | **Yes** | **High** |
| bitCap = size*8 | **Yes** | **High** |
| No realloc / no free | **Yes** | **High** |
| Zero bitPos / error | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Non-owning buffer bind | **High** | owns byte 0 |
| Layout offsets | **High** | live stores |
| Distinct from owning ByteBuffer ctor (`009d7b00`) | **High** | different vtbl |
| Product type name "TNL::BitStream" | **Tentative** | role sealed |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Full BitStream class product name / field dictionary beyond sealed offsets.
2. String-cache region at +0x38 only zeroed here — filled by string R/W helpers.

**Verdict:** **accept-with-gaps**
