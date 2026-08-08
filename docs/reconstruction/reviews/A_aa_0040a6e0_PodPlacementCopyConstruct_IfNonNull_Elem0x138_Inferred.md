# Review A (reconstruction fidelity): `aa_0040a6e0` PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a6e0` |
| **VA** | `0x0040a6e0`–`0x0040a729` exclusive (**74 B**) |
| **Canonical name** | `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` |
| **Ghidra name** | `FUN_0040a6e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9I-D) |
| **Counterpart** | `reviews/B_aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` |
| **System** | util / POD placement (Logic-UI event width 0x138) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-D** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **null-checked placement / uninitialized copy-construct** of one **0x138-byte** POD:

1. SEH install (`LAB_009bdcb1`).
2. If dest ≠ 0: thiscall leaf `PodCopyConstruct_Elem0x138_Inferred` (`0x00408880`).
3. Else: no-op.
4. SEH uninstall; bare `ret`.

Upstream ConstructN / uninit-copy parents stride **+0x138** through thin trampoline `FUN_00409f10`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040a6e0_FUN_0040a6e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040a6e0_FUN_0040a6e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040a6e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` |
| Leaf dual | `PodCopyConstruct_Elem0x138_Inferred` (WQ9H-I) |
| Live | decompile ≡ raw; body 74 B; epilogue `83 C4 10 C3` |

---

## 3. Signature (sealed)

```c
// cdecl; bare ret; parent ADD ESP,8
void PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred(
    void* dest,          // Stack[0x4]
    const void* src);    // Stack[0x8]
```

| Formal | Source | Conf |
|---|---|---|
| dest | Stack[0x4] → ECX for leaf | **High** |
| src | Stack[0x8] → PUSH before CALL leaf | **High** |
| cleanup | bare `C3`; wrapper cleans 8 | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH install (PUSH -1 / handler 0x009bdcb1 / FS:[0])
MOV ECX, [ESP+0x14]     ; dest
TEST ECX, ECX
JZ  skip
MOV EAX, [ESP+0x18]     ; src
PUSH EAX
CALL 0x00408880         ; thiscall ECX=dest, RET 4
skip:
SEH uninstall
ADD ESP, 0x10
RET
```

| Stage | Match | Conf |
|---|---|---|
| Null dest no-op | **Yes** | **High** |
| Non-null → dualed 0x138 POD leaf | **Yes** | **High** |
| cdecl formals / bare ret | **Yes** | **High** |
| Sole parent trampoline 00409f10 | **Yes** | **High** |
| Upstream stride 0x138 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body 74 B @ `0x0040a6e0`; SEH prefix `6A FF 68 B1 DC 9B 00`; gate `85 C9 74 0A`; leaf relcall `E8 6D E1 FF FF` → `00408880`; epilogue `83 C4 10 C3`; pad `CC`.

---

## 6. Gaps

- Product English field map for 0x138 Logic-UI event POD.
- Dual of trampoline `FUN_00409f10` / parents `00409cc0` / `0040a4a0` (not OWN).
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/width sealed; product layout English residual.
