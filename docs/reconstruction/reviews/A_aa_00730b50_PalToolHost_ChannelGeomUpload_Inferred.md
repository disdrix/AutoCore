# Review A (reconstruction fidelity): `aa_00730b50` PalToolHost_ChannelGeomUpload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00730b50` |
| **VA** | `0x00730b50`–`0x00731123` (**1492 B**) |
| **Canonical name** | `PalToolHost_ChannelGeomUpload_Inferred` |
| **Ghidra name** | `FUN_00730b50` |
| **Review date** | `2026-08-04` (W37-U dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-U) |
| **Counterpart** | `reviews/B_aa_00730b50_PalToolHost_ChannelGeomUpload_Inferred.md` |
| **System** | palantir graphics / PalTool host channel upload |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (prologue/epilogue + body range) + `analyze_function_complete` + `get_function_by_address` + xrefs + caller decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Per-channel geometry upload for dual-channel PalTool host (`new(0x44)` slot5 family): three local 0x44 streams → VB fmt 0x152 Lock 0x800 → copy 0x24 verts → unlock (gfxDeviceVB plate) → IB stride 0x10/0x20 from material child → bind `host+0x24+ch*8`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00730b50_FUN_00730b50.md` (+ W37-U append) |
| Annotated | `docs/reconstruction/raw/aa_00730b50_FUN_00730b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalToolHost_ChannelGeomUpload_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00730b50.cpp` |
| Function records | `aa_00730b50_FUN_00730b50.md`, named record |
| Live | decompile ≡ raw CF; body `0x00730b50`–`0x00731123`; epilogue `C2 08 00` |
| Context | W36-J caller `FUN_00731130` dual-channel init; W35-E HostPtrTable12 slot5 |

---

## 3. Signature (sealed)

```c
// stdcall 2 stack args; RET 8
uint32_t PalToolHost_ChannelGeomUpload_Inferred(void *host, int channelIndex);
```

| Slot | Source | Conf |
|---|---|---|
| host | stack; indexed `+4+ch*4`, `+0xc+ch*4`, `+0x24+ch*8`, `+0x34+ch*8` | **High** |
| channelIndex | stack; sole caller passes 0 then 1 | **High** |
| return | EAX status / `0xFFFFFFFF` fail | **High** |
| RET | `C2 08 00` | **High** |
| thiscall | **No** — stack formals | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| 3×0x44 eh_vector streams + FUN_00982100×3 | **Yes** | **High** |
| counts `(n/3)*3` @ +4+ch*4; flag 4 @ +0xc+ch*4 | **Yes** | **High** |
| VB 0x152 + FUN_00414c20 + Lock 0x800 | **Yes** | **High** |
| 3-stream memcpy / Unlock plate | **Yes** | **High** |
| stride 0x10/0x20 via mat@+0x34+ch*8 | **Yes** | **High** |
| FUN_0044bbc0 → host+0x24+ch*8 | **Yes** | **High** |
| Product host English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB English for 0x44 host class.
2. Exact 0x24 vertex packing / stream field map.
3. Unowned helper full contracts.
4. Clean is structural (raw authoritative for full SEH).
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, channel offsets, VB/IB constants, sole dual-channel caller, gfxDeviceVB plate sealed; product English + helper depth open.
