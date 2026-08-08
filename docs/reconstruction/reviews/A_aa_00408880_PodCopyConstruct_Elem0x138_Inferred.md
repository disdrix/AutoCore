# Review A (reconstruction fidelity): `aa_00408880` PodCopyConstruct_Elem0x138_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408880` |
| **VA** | `0x00408880`–`0x004088ef` |
| **Canonical name** | `PodCopyConstruct_Elem0x138_Inferred` |
| **Ghidra name** | `FUN_00408880` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9H-I) |
| **Counterpart** | `reviews/B_aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` |
| **System** | util / POD construct (Logic-UI event width 0x138) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **POD copy-construct** of one **0x138-byte** element:

1. Unrolled dword copy of 14 dwords (0x38 bytes).
2. `rep movsd` of **0x40** dwords from offset **+0x38** (0x100 bytes).
3. Total width **0x138**; void return; **RET 4**.

Callers: `LogicUiEventQueue_InsertN` (stack buffer construct) and placement helper `FUN_0040a6e0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00408880_FUN_00408880.md` (+ 2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_00408880_FUN_00408880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodCopyConstruct_Elem0x138_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408880.cpp` |
| Function record | `docs/reconstruction/functions/aa_00408880_PodCopyConstruct_Elem0x138_Inferred.md` |
| Parent dual | `LogicUiEventQueue_InsertN` (`0x004076a0`, W23-B) |
| Live | decompile ≡ raw; body 112 B; epilogue `C2 04 00` |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 4
void __thiscall PodCopyConstruct_Elem0x138_Inferred(void* dest /*ECX*/, const void* src /*Stack[0x4]*/);
```

| Formal | Source | Conf |
|---|---|---|
| dest | ECX → EAX alias for stores | **High** |
| src | Stack[0x4] → ECX after prologue | **High** |
| cleanup | `RET 4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
mov eax, ecx          ; dest
mov ecx, [esp+4]      ; src
// store dwords 0..9 unrolled
// store dwords 10..13 via +0x28 base
// rep movsd 0x40 from +0x38
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| thiscall dest + stack src | **Yes** | **High** |
| Width 0x138 (14 + 0x40 dwords) | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| RET 4 | **Yes** | **High** |
| InsertN @ 0x004076d0 uses as construct | **Yes** | **High** |
| Placement caller 0040a6e0 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body 112 B @ `0x00408880`; formals `8B C1 8B 4C 24 04`; loop count `B9 40 00 00 00 F3 A5`; epilogue `5F 5E C2 04 00`. Next function at `0x004088f0`.

---

## 6. Gaps

- Product English field map for 0x138 Logic-UI event record.
- Dual of placement wrapper `FUN_0040a6e0`.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/width sealed; product layout English residual.
