# Review A (reconstruction fidelity): `aa_007300c0` PalToolNoMap_Host0x34_MeshBuildUpload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007300c0` |
| **VA** | `0x007300c0`–`0x007308b7` (**2040 B**) |
| **Canonical name** | `PalToolNoMap_Host0x34_MeshBuildUpload_Inferred` |
| **Ghidra name** | `FUN_007300c0` |
| **Review date** | `2026-07-29` (W36-J dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-J) |
| **Counterpart** | `reviews/B_aa_007300c0_PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.md` |
| **System** | palantir graphics / PalTool material + mesh upload |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (prologue/epilogue + body bounds) + `analyze_function_complete` + bulk xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Post-ctor mesh build/upload for HostPtrTable12 **slot6** host (`0x34`):

1. SEH + local mesh workspaces (`FUN_00981310` / `FUN_0098ef00` families).
2. Bind `PalToolMaterialNoMap.fx` + four material params into **`host+0x24`**; refcount swap.
3. Store counts **`host+0x20`**, **`host+0x1c`**, flag **`host+0x2c = 4`**.
4. Create/lock/copy VB (format `0x152`, lock `0x800`) and index path; attach via `FUN_0044bbc0(..., host+0x14, 0)`.
5. Return **0** success or **0xFFFFFFFF** failure.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007300c0_FUN_007300c0.md` (+ W36-J append) |
| Annotated | `docs/reconstruction/raw/aa_007300c0_FUN_007300c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.cpp` (structural) |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007300c0.cpp` |
| Function records | `aa_007300c0_FUN_007300c0.md`, named record |
| Live | decompile ≡ raw CF for bind/counts/returns; body 2040 B; epilogue `81c4f0000000c20400`; 1 xref `0073c9f5` |
| Context | W35-E HostPtrTable12 slot6 (`new(0x34)` + inline multi-vtbl) |

---

## 3. Signature (sealed)

```c
// stdcall 1 stack arg; RET 4; SEH LAB_009b1eb6
uint32_t PalToolNoMap_Host0x34_MeshBuildUpload_Inferred(void *host);
```

| Slot | Source | Conf |
|---|---|---|
| host | stack formal | **High** |
| return 0 / -1 | decompile + cleanup paths | **High** |
| RET 4 | epilogue bytes | **High** |
| thiscall | **No** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH + workspaces | **Yes** | **High** |
| Material @+0x24 + plate strings | **Yes** | **High** |
| Counts +0x1c/+0x20; +0x2c=4 | **Yes** | **High** |
| VB Lock/copy/IB path | **Yes** | **High** |
| return 0 / 0xFFFFFFFF | **Yes** | **High** |
| Second geometry stack aliases | partial (decompiler gap) | **Medium** |
| Product English | open | **Low** |

---

## 5. Gaps / open

1. Decompiler stack aliasing on second geometry block (`piRam00000010` family).
2. Product English for 0x34 multi-vtbl host.
3. Exact 0x24-byte vertex / 6-byte index packing.
4. Full unowned helper contracts.
5. Runtime / bit-exact / differential.
6. Clean is structural (not full SEH expansion) — raw remains authoritative for branch order.

**Verdict:** **accept-with-gaps** — ABI, material slot, counts, upload skeleton, sole caller, return codes sealed; decompiler second-path + product English open.
