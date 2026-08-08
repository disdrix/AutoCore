# Review A (reconstruction fidelity): `aa_005725a0` InventoryGrid_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005725a0` |
| **VA** | `0x005725a0`–`0x0057264d` inclusive (**174 B** / `0xAE`) |
| **Canonical name** | `InventoryGrid_CompleteDtor` |
| **Ghidra name** | `FUN_005725a0` |
| **Prior scaffold** | `FUN_005725a0` (2026-07-23 truncated decompile only) |
| **Review date** | `2026-08-05` (MEGA-061 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005725a0_InventoryGrid_CompleteDtor.md` |
| **System** | inventory-transfer / InventoryGrid MSVC complete dtor / `PTR_FUN_009d3390` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full 174 B) + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC complete-object destructor for InventoryGrid: reinstall vtbl, clear all items, free cell array, destroy map and list members, delete critical section. Does **not** free the host block (scalar-deleting dtor owns that).

```text
InventoryGrid_CompleteDtor(self)
  self.vtbl = PTR_FUN_009d3390
  ClearItemsAndReEmptyCells(self)          // 00570f70
  delete[] self.cellArray (+0x28); null
  map(+0x5c): erase-all; delete sentinel; zero
  list(+0x2c): vtbl 9d3384→004bc950; 9cb334→004bc950
  DeleteCriticalSection(+0x30)
  RET
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-061 append) | `docs/reconstruction/raw/aa_005725a0_FUN_005725a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005725a0_FUN_005725a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CompleteDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005725a0.cpp` |
| Function records | `functions/aa_005725a0_FUN_005725a0.md`, `…_InventoryGrid_CompleteDtor.md` |
| Live | decompile truncated; **bytes** seal full CF through `C3` |
| Scalar twin | dualed `InventoryGrid_ScalarDeletingDtor` WQ8R-E **accept** |
| Clear stage | dualed `ClearItemsAndReEmptyCells` MEGA-090 |
| Ctor reverse | `InventoryGrid_ctor_Inferred` `0x00572650` |

**Not performed:** `disassemble_bytes`, Launcher, bit-exact, differential.

---

## 3. Signature (sealed)

```c
// ECX=this; no stack formals; void; bare RET
void __thiscall InventoryGrid_CompleteDtor(InventoryGrid *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F9`) | **High** |
| stack args | none | **High** |
| return | void | **High** |
| cleanup | `C3` (not `C2 04`) | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Evidence | Conf |
|---|---|---|
| SEH frame | `6A FF 68 42 4F 9A 00` + FS:[0] | **High** |
| Vtbl reinstall | `C7 07 90 33 9D 00` | **High** |
| Clear items | `CALL 00570f70` | **High** |
| `delete[]` +0x28 | null-check + `0048981c` | **High** |
| Map erase + free | `00573700` + `00489822` + zero head/size | **High** |
| List dual drain | `9d3384`/`9cb334` + `004bc950`×2 | **High** |
| DeleteCS +0x30 | `ADD ESI,4` + IAT `[009c61f0]` | **High** |
| Epilogue | `5F 5E 5B … 83 C4 14 C3` | **High** |
| Body size 174 B | exclusive end `0057264e`; pad `CC`; ctor `@00572650` | **High** |
| Ghidra end `0057260b` wrong | false-noreturn on `operator_delete` | **High** (reject Ghidra bound) |

Full body hex (174 B):

```
6aff68424f9a0064a100000000506489250000000083ec085356578bf9897c240cc70790339d00c744241c01000000e89ce9ffff8b472833db3bc3740950e83972f1ff83c404895f288b47608b088d775c50518d442418508bce885c2428e8fd1000008b4e0451e81672f1ff895e04895e088d772c83c4048bcec70684339d00e82ba3f4ff8bcec70634b39c00e81ea3f4ff83c60456ff15f0619c008b4c24145f5e5b64890d0000000083c414c3
```

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | **1** UNCONDITIONAL_CALL from scalar dtor `@00573913` |
| Xrefs | 1 code site (analyze_function_complete) |
| Family | InventoryGrid — ctor installs same vtbl; cargo destroy uses vtbl[0](1) |

---

## 6. Naming

| Candidate | Result |
|---|---|
| `InventoryGrid_CompleteDtor` | **Accepted** — MSVC complete-dtor role + dualed scalar twin + ctor reverse |
| `FUN_005725a0` | Ghidra residual alias |
| Partition FreeCellArray / clear-only | **Rejected** — those are nested stages, not this VA |
| ScalarDeletingDtor | **Rejected** — that is `00573910` |

Product demangle string not recovered → naming structural (same bar as dualed scalar twin).

---

## 7. Gaps

1. Product/MSVC demangle for host class (naming-only; family sealed).  
2. Tree key English / dual of erase helper `00573700` (CF of this VA sealed).  
3. Full dual of list helper `004bc950` (call sites + empty second pass sealed).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, full 174 B CF, complete-vs-scalar separation, InventoryGrid layout reverse of ctor, and sole caller link are sealed with high confidence. Decompiler truncation is documented and overridden by bytes. Residual product demangle and nested helper duals do not block port of this unit → **accept**.
