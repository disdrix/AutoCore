# Review A (reconstruction fidelity): `aa_00494700` Host_EnsureRegionCellOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494700` |
| **VA** | `0x00494700`–`0x0049484f` exclusive (**335 B**) |
| **Canonical name** | `Host_EnsureRegionCellOwned_Inferred` |
| **Ghidra name** | `FUN_00494700` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-C) |
| **Counterpart** | `reviews/B_aa_00494700_Host_EnsureRegionCellOwned_Inferred.md` |
| **System** | host grid region ensure (ListTrackedObj per cell) |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ensure every cell in the host’s active integer region owns a heap `ListTrackedObj` (0x5E0) at `cell+0x24`, constructing and placing new ones as needed, MRU-touching existing ones, and optionally evicting under global list pressure. Busy flag `host+0x53` brackets the work.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-C append) | `docs/reconstruction/raw/aa_00494700_FUN_00494700.md` |
| Annotated | `docs/reconstruction/raw/aa_00494700_FUN_00494700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_EnsureRegionCellOwned_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00494700.cpp` |
| Function record | `docs/reconstruction/functions/aa_00494700_Host_EnsureRegionCellOwned_Inferred.md` |
| Owned dtor | `aa_004be2a0` ListTrackedObj_CompleteDtor (W30-P) |
| Host grid peers | W30-Q rebuild `0x004941b0`; W29-F Elem0x28 dtor |
| Live | decompile ≡ bytes for loops/flag/RET 4; callers `FUN_004951d0` / `FUN_00495130` |

---

## 3. Signature (sealed)

```c
// ECX = host; stack context; SEH LAB_009a0bd0; ADD ESP,0x18; RET 4
void __thiscall Host_EnsureRegionCellOwned_Inferred(void* host, void* ctx);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`8B F9`) | **High** |
| ctx | stack; `RET 4` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority)

```
SEH; EDI=host; busy@+0x53 = 0
for x in [+0x64, +0x6c):
  for y in [+0x68, +0x70):
    cell = *(+0x28) + (dimX@+4 * y + x) * 0x28
    if cell.owned@+0x24 == 0:
      p = new(0x5E0); ctor FUN_004becb0(p, cell, 0)
      p[+0x5D4] = ctx
      FUN_004bd890(p, x, y); FUN_004bf690(p)
      cell.owned = p
      if FUN_004bd660(&victim):
        map victim grid indices → cell; maybe flag owned@+0x5D0
        null owned; ListTrackedObj_CompleteDtor; delete
    else:
      FUN_004bd6f0(owned)  // MRU
busy@+0x53 = 1; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Busy flag 0→1 | `C6 47 53 00` / `01` | **High** |
| Cell index ×0x28 | imul/lea sequence | **High** |
| new(0x5E0) | `68 E0 05 00 00` | **High** |
| CompleteDtor + delete on eviction | call `004be2a0` then delete | **High** |
| RET 4 | `C2 04 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (335 B) — see raw W31-C append.  
Entry SEH: `6A FF 68 D0 0B 9A 00 …`.  
Epilogue: `… C6 47 53 01 … 83 C4 18 C2 04 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (region populate / ensure) |
| Callers | `FUN_004951d0` (static culling path); `FUN_00495130` |
| Pair with | host rebuild W30-Q; ListTrackedObj W30-P; Elem0x28 W29-F |

---

## 7. Gaps

1. Product English for host / ctx (`param_2`) types.  
2. `FUN_004bd660` pressure threshold product policy.  
3. `param_2+0x7d` flag product meaning.  
4. Nested place/populate callees (`004bd890` / `004bf690`) product detail.  
5. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Region ensure CF/ABI/cell formula/0x5E0 create/evict path sealed. Residual product host/context English → **accept-with-gaps**.
