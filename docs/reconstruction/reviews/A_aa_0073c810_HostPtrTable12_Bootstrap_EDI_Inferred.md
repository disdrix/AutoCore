# Review A (reconstruction fidelity): `aa_0073c810` HostPtrTable12_Bootstrap_EDI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073c810` |
| **VA** | `0x0073c810`–`0x0073cb6d` (**862 B**) |
| **Canonical name** | `HostPtrTable12_Bootstrap_EDI_Inferred` |
| **Ghidra name** | `FUN_0073c810` |
| **Review date** | `2026-07-29` (W35-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-E) |
| **Counterpart** | `reviews/B_aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md` |
| **System** | host pointer-table bootstrap |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 862 B) + `analyze_function_complete` + xrefs (empty) + neighbor decompile |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Bootstrap **12** subsystem hosts into `EDI[0..11]`:

1. SEH frame `LAB_009b2f9d`.
2. For each slot: `operator_new(size)` → null-safe construct → store pointer → post-init callee.
3. Final `FUN_007647c0(EDI[8])`; return **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0073c810_FUN_0073c810.md` (+ W35-E append + full hex) |
| Annotated | `docs/reconstruction/raw/aa_0073c810_FUN_0073c810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostPtrTable12_Bootstrap_EDI_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073c810.cpp` |
| Function records | `aa_0073c810_FUN_0073c810.md`, `aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md` |
| Live | decompile ≡ raw CF; 862 B hex; 0 xrefs |
| Context | W34-E NestedHash0x10; W34-G NestedHashBag0x18 sole caller site; neighbor gfxToolFactory.cpp |

---

## 3. Signature (sealed)

```c
// EDI = void** host_table; no stack args; return 0; plain RET
uint32_t HostPtrTable12_Bootstrap_EDI_Inferred(void **table /* EDI */);
```

| Slot | Source | Conf |
|---|---|---|
| table | EDI live (no PUSH EDI; stores `89 0F` / `89 4F xx`) | **High** |
| return | `33 C0` → 0 | **High** |
| stack formals | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| 12 stores EDI[0..11] | **Yes** | **High** |
| Alloc sizes 0xC4 / 0x44 / 0x34 / 0x30 / 0x40 / 0x14C | **Yes** | **High** |
| NestedHash0x10 @ slot9 | **Yes** | **High** |
| NestedHashBag0x18 @ slot10 | **Yes** | **High** |
| float 10.0f (`0x41200000`) @ slot8 init | **Yes** | **High** |
| return 0 | **Yes** | **High** |
| Product English / callers | open | **Low** |

---

## 5. Gaps / open

1. **No Ghidra callers/xrefs** — entry path unknown.
2. Product/PDB English for host class and each dual-vtbl subclass.
3. Full contracts of unowned init callees.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI + 12-slot ladder sealed; callers + product plates open.
