# Review A (reconstruction fidelity): `aa_009847c0` AssPackManager_PrepReplaceExistingEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009847c0` |
| **VA** | `0x009847c0`–`0x0098488c` exclusive (**204 B**) |
| **Canonical name** | `AssPackManager_PrepReplaceExistingEntry_Inferred` |
| **Ghidra name** | `FUN_009847c0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-Y) |
| **Counterpart** | `reviews/B_aa_009847c0_AssPackManager_PrepReplaceExistingEntry_Inferred.md` |
| **System** | assPackManager replace-prep |
| **Evidence pass** | Live Ghidra `decompile_function` / `force_decompile` + `analyze_function_complete` + `read_memory` (full body) + callers/xrefs + `get_assembly_context` @ `0x00984a18` + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Prepare an existing pack entry for replace (lookup + clear sentinel + deferred push) under optional CS; return 0 hit / −1 miss.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-Y append) | `docs/reconstruction/raw/aa_009847c0_FUN_009847c0.md` |
| Annotated | `docs/reconstruction/raw/aa_009847c0_FUN_009847c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_PrepReplaceExistingEntry_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_009847c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009847c0_AssPackManager_PrepReplaceExistingEntry_Inferred.md` |
| Parent | `AssPackManager_AddOrReplaceFileInPack_Inferred` @ `0x00984a18` |

---

## 3. Signature (sealed)

```c
// ECX=pathBuf*, EDX=host*, stack nameOrCookie*; RET 4
int AssPackManager_PrepReplaceExistingEntry_Inferred(
    char* pathBuf,
    void* host,
    const char* nameOrCookie);
```

| Formal | Source | Conf |
|---|---|---|
| pathBuf* | **ECX** → ESI (caller `LEA ECX,[ESP+0x80]`) | **High** |
| host* | **EDX** → EDI (caller host load; CS `@+0x38` / gate `@+0x50`) | **High** |
| nameOrCookie* | stack0 (caller `PUSH EBP` = parent `param_6`); **`RET 4`** | **High** |
| return | 0 / `0xFFFFFFFF` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH + optional EnterCS | decompile + bytes | **High** |
| Path normalize + cache lookup + map find | decompile + callees | **High** |
| Miss `it == host+8` → −1 | decompile + bytes | **High** |
| Hit: `entry+0x1C = DAT_00d1eac0`; `FUN_00469c80` | decompile + bytes | **High** |
| LeaveCS both paths; RET 4 | bytes `C2 04 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (204 B) — raw W37-Y append.

SEH: `6A FF 68 A1 F7 9A 00 …`.  
Epilogue: `C2 04 00`. Pad `CC`×4 then `FUN_00984890`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00984910` ×1 @ `0x00984a18` |
| Callees | CS APIs, `FUN_00719630`, `FUN_00989e00`, `FUN_0044e8c0`, `FUN_00469c80` |

---

## 7. Gaps

1. Product English for `nameOrCookie` vs filesystem path.  
2. Exact map-node field plates (`+0x1C`, `+0x24` container).  
3. `FUN_00469c80` push value construction (nested, not OWN).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

ABI (incl. RET 4), CS layout, miss/hit returns, clear-sentinel + push stage sealed against parent replace branch. Nested product plates open → **accept-with-gaps**.
