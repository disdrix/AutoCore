# Review A (reconstruction fidelity): `aa_00984c70` AssPackManager_AddDirectoryTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984c70` |
| **VA** | `0x00984c70`–`0x00984d25` (**182 B**) |
| **Canonical name** | `AssPackManager_AddDirectoryTree_Inferred` |
| **Ghidra name** | `FUN_00984c70` |
| **Review date** | `2026-07-29` (W33-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-E) |
| **Counterpart** | `reviews/B_aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` |
| **System** | AssPackManager / offline pack ingest |
| **Evidence pass** | Live Ghidra decompile + full-body `read_memory` + xrefs + nested `FUN_00984910` plate |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Directory-tree pack ingest:

1. SEH `LAB_009b113c`; zero local string vector.
2. `rc = FUN_009839b0(path /*ECX*/, &listing)`.
3. If `rc >= 0`: for each leaf (stride `0x1c`), copy string, call **`FUN_00984910`** with leaf c_str / pack host / mode / flags `1,0,0`.
4. Destroy listing (`FUN_00431ae0`); **return 0**.

Nested add-file logs `assPackManager.cpp` ("Added file %s") — seals AssPackManager family.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00984c70_FUN_00984c70.md` (+ W33-E append, full hex) |
| Annotated | `docs/reconstruction/raw/aa_00984c70_FUN_00984c70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_AddDirectoryTree_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984c70.cpp` |
| Function record | `docs/reconstruction/functions/aa_00984c70_FUN_00984c70.md` |
| Named record | `docs/reconstruction/functions/aa_00984c70_AssPackManager_AddDirectoryTree_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 182 B; **0 xrefs** |
| Nested plate | `FUN_00984910` → `assPackManager.cpp` |

---

## 3. Signature (sealed, bytes)

```c
// ECX = dir path; stack = AssPackManager*; EDI = mode (gap); bare RET; EAX = 0
int AssPackManager_AddDirectoryTree_Inferred(const char* dir_path /*ECX*/,
                                             void* ass_pack_manager /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| path | **ECX** (pushed into `009839b0`) | **High** (bytes) |
| pack | Stack formal / EBP → `00984910` | **High** (bytes) |
| mode | **EDI** pushed; never written here | **Open** (gap) |
| return | `XOR EAX,EAX` | **High** |
| cleanup | bare `RET` | **High** |

Decompiler `__thiscall(param_1,param_2)` + `unaff_EDI` is incomplete — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
listing = {}
rc = DirRecurseCollectLeafPaths(path, &listing)
if rc >= 0:
  for leaf in listing:
    AddFile(leaf, pack, mode_EDI, 1, 0, 0)
destroy(listing)
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Collect via `009839b0` | **Yes** | **High** |
| Per-leaf `00984910` | **Yes** | **High** |
| Flags `1,0,0` | **Yes** (bytes) | **High** |
| Always return 0 | **Yes** | **High** |
| Product wrapper plate | shape only | **Inferred** |

---

## 5. Gaps / open

1. Zero static callers — invocation path open.
2. EDI mode meaning / whether required by all call sites.
3. Full product plate for `FUN_00984910` formals (unowned).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
