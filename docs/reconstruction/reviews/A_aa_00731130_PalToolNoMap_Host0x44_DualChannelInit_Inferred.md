# Review A (reconstruction fidelity): `aa_00731130` PalToolNoMap_Host0x44_DualChannelInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00731130` |
| **VA** | `0x00731130`–`0x007313fd` (**718 B**) |
| **Canonical name** | `PalToolNoMap_Host0x44_DualChannelInit_Inferred` |
| **Ghidra name** | `FUN_00731130` |
| **Review date** | `2026-07-29` (W36-J dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-J) |
| **Counterpart** | `reviews/B_aa_00731130_PalToolNoMap_Host0x44_DualChannelInit_Inferred.md` |
| **System** | palantir graphics / PalTool material (no-map) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 718 B) + `analyze_function_complete` + bulk xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Post-ctor dual-channel init for HostPtrTable12 **slot5** host:

1. Bind `PalToolMaterialNoMap.fx` into material slots **`host+0x34`** then **`host+0x3c`**.
2. Set MatDiffuse / MatAmbient / MatSpecular / MatEmissive (missing → 0xFFFFFFFF status).
3. `FUN_004246a0` + `FUN_0073d940` refcount swap per channel.
4. `FUN_00730b50(host, 0)` then `FUN_00730b50(host, 1)`.
5. Return OR of all statuses.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00731130_FUN_00731130.md` (+ W36-J append + full hex) |
| Annotated | `docs/reconstruction/raw/aa_00731130_FUN_00731130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x44_DualChannelInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00731130.cpp` |
| Function records | `aa_00731130_FUN_00731130.md`, named record |
| Live | decompile ≡ raw CF; 718 B hex ends `83c408c20400`; 1 xref from `0073c9ad` |
| Context | W35-E HostPtrTable12 slot5 (`new(0x44)` + `FUN_00457720`) |

---

## 3. Signature (sealed)

```c
// stdcall 1 stack arg; RET 4
uint32_t PalToolNoMap_Host0x44_DualChannelInit_Inferred(void *host);
```

| Slot | Source | Conf |
|---|---|---|
| host | stack `[ESP+…]` after prologue; used as base for +0x34/+0x3c | **High** |
| return | OR-accumulated EAX | **High** |
| RET | `C2 04 00` | **High** |
| thiscall | **No** — ECX used as temp | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Dual channel +0x34 then +0x3c | **Yes** | **High** |
| Plate strings (effect + 4 mat params) | **Yes** | **High** |
| Refcount swap pattern | **Yes** | **High** |
| `FUN_00730b50(host,0|1)` | **Yes** | **High** |
| OR-return all statuses | **Yes** | **High** |
| Product English host class | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB English for 0x44 host type beyond effect plate.
2. Full contracts of unowned callees (`FUN_00730b50`, `FUN_0073d940`, material helpers).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, dual-channel ladder, strings, sole caller sealed; product English + unowned callee depth open.
