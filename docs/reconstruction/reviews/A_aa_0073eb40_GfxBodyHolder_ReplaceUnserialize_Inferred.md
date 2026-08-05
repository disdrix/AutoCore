# Review A (reconstruction fidelity): `aa_0073eb40` GfxBodyHolder_ReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073eb40` |
| **VA** | `0x0073eb40`–`0x0073ebe6` exclusive (**166 B** / `0xA6`) |
| **Canonical name** | `GfxBodyHolder_ReplaceUnserialize_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0073eb40` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-R) |
| **Counterpart** | `reviews/B_aa_0073eb40_GfxBodyHolder_ReplaceUnserialize_Inferred.md` |
| **System** | client / graphics / gfxBody sto load |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 166 B) + `get_function_by_address` + xrefs/callers + callee decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Replace the GfxBody pointer at `holder+4` with a newly constructed `0x14C` body, peek the next sto chunk tag, and unserialize either:

- **SAMB** (`0x424D4153`) via `FUN_009615c0` (gfxBodyMaster / `gfxBodyMassageMachine.cpp`), or
- else **GBOD** via W37-S `GfxBody_UnserializeGBOD_Inferred` (`FUN_00765740`).

Returns the nested unserializer status in **EAX**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-R append) | `docs/reconstruction/raw/aa_0073eb40_FUN_0073eb40.md` |
| Annotated | `docs/reconstruction/raw/aa_0073eb40_FUN_0073eb40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxBodyHolder_ReplaceUnserialize_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0073eb40.cpp` |
| Function | `docs/reconstruction/functions/aa_0073eb40_FUN_0073eb40.md` |
| Named | `docs/reconstruction/functions/aa_0073eb40_GfxBodyHolder_ReplaceUnserialize_Inferred.md` |
| Peer GBOD | W37-S `aa_00765740` (sole static caller = this) |
| Peer Peek | `aa_0076a900` stoChunkReader_PeekChunkTag |
| Live | decompile + 166 B hex + rel32 call targets |

---

## 3. Signature (sealed)

```c
// thiscall; 1 stack formal; RET 4; EAX = status
uint32_t __thiscall GfxBodyHolder_ReplaceUnserialize_Inferred(
    void* holder, void* reader);
```

| Formal | Source | Conf |
|---|---|---|
| holder | `MOV EDI, ECX` | **High** |
| reader | stack; `MOV ESI,[ESP+…]` before peek | **High** |
| cleanup | `ADD ESP,0x10; RET 4` both arms | **High** |
| return | EAX from last unserialize call | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009b3f3c
if [holder+4]: vtbl[0](body, 1)
raw = operator_new(0x14C)
body = raw ? FUN_00764030(raw) : 0
[holder+4] = body
tag = PeekChunkTag()  // ESI=reader
PUSH reader
if tag == SAMB:
  PUSH body; CALL FUN_009615c0; ADD ESP,8; RET 4
else:
  PUSH body; CALL FUN_00765740 /* RET 8 */; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Body size 166 B | Yes | **High** |
| Scalar dtor + new 0x14C + ctor | Yes | **High** |
| SAMB cmp `3D 53 41 4D 42` | Yes | **High** |
| GBOD arm sole consumer of 00765740 | Yes (W37-S) | **High** |
| EAX status | Yes (no clobber after call) | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | **open** (Ghidra empty) |
| Callees | vcall dtor; `operator_new`; `FUN_00764030`; `FUN_0076a900`; `FUN_009615c0`; `FUN_00765740` |

---

## 6. Gaps

1. Inbound static / vtable callers not recovered.  
2. Product holder/body C++ English.  
3. Full dual of `FUN_009615c0` / `FUN_00764030` (unowned).  
4. Runtime / bit-exact / differential.

---

## 7. Verdict rationale

CF, ABI, sizes, tags, and dual unserialize arms are fully sealed by full-body hex + callee duals. Gaps are caller discovery + product English → **accept-with-gaps** (not full accept).
