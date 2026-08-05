# Review A (reconstruction fidelity): `aa_00988a10` gfxIndexBufferImpl_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00988a10` |
| **VA** | `0x00988a10` |
| **Canonical name** | `gfxIndexBufferImpl_Serialize` |
| **System** | `graphics / gfx` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00988a10_gfxIndexBufferImpl_Serialize.md` |
| **Verdict** | **accept-with-gaps** |
| **Evidence** | Ghidra MCP `batch_decompile` 2026-07-29; raw/annotated/clean three-rep present |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00988a10_gfxIndexBufferImpl_Serialize.md` |
| Raw | `docs/reconstruction/raw/aa_00988a10_gfxIndexBufferImpl_Serialize.md` |
| Annotated | `docs/reconstruction/raw/aa_00988a10_gfxIndexBufferImpl_Serialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxIndexBufferImpl_Serialize.cpp` |

---

## 2. Purpose (from unit)

Serialize an **INDX** chunk (file fourCC **`XDNI`** = `0x494e4458`) at **version 2** via `stoChunkWriter_BeginChunk` / `EndChunk`. Body (per plate comment): `u32 id/hash + u16 indexSize(2|4) + u16 count + u32 count2 + raw index data (count2 × indexSize)`. Topology is **triangle lists** (not stored per chunk). Locks/unlocks device index buffer (`gfxDeviceIB`) around the write; unlock uses vtbl **`+0x30`** and a lock-count field at deviceIB **`[3]`**.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Chunk tag `0x494e4458` (INDX / XDNI), version **2** | **High** | Literal BeginChunk args |
| Device IB at `this+0x10`; lock uses `+0x18`, `+0x1c`, flags `0x810` | **High** | Decompile path |
| Lock helper `FUN_00743be0`; write helper `FUN_00734640(size, count-ish)` | **High** | Call sites; names unresolved |
| Fail path: lock null → `-1`; else `FUN_0044ed10` status | **High** | CF sealed |
| Unlock: dec lock count; underflow log + clamp 0; else vtbl+0x30 | **High** | gfxDeviceIB.cpp:0xca string |
| Fail log at gfxIndexBufferImpl.cpp:0x123 | **High** | String + line |
| Control flow clean ≡ raw | **High** | Scaffold rewrite |
| Full wire body field map of FUN_0044c9e0 / FUN_00439870 / FUN_0044ed10 | **Medium** | Callees not dual-owned here |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH setup; BeginChunk(INDX, 2) | **Yes** |
| if deviceIB(+0x10): Lock(+0x18,+0x1c,0x810); on success write payload | **Yes** |
| FUN_0044c9e0; FUN_00439870; status = −1 if no lock else FUN_0044ed10 | **Yes** |
| Unlock path (count / vtbl+0x30) | **Yes** |
| if status < 0 log fail; EndChunk; return status | **Yes** |

---

## 5. Gaps

1. Seal callee identities: `FUN_00743be0` (IB Lock), `FUN_00734640` (payload write), `FUN_0044c9e0` / `FUN_00439870` / `FUN_0044ed10` (chunk body writers).
2. Exact `this` layout beyond `+0x10` device, `+0x14` / `+0x18` / `+0x1c` fields used here.
3. Runtime serialize of a known retail mesh deferred.

**Verdict:** **accept-with-gaps**
