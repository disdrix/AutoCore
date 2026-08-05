# Review A (reconstruction fidelity): `aa_00985390` AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985390` |
| **VA** | `0x00985390`–`0x0098545e` exclusive (**206 B**) |
| **Canonical name** | `AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred` |
| **Ghidra name** | `FUN_00985390` |
| **Review date** | `2026-07-29` (W33-P dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-P) |
| **Counterpart** | `reviews/B_aa_00985390_AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.md` |
| **System** | assets / assPack free-map |
| **Evidence pass** | Live decompile + analyze_function_complete + full-body `read_memory` + xrefs + callee decompiles |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Release one pack allocation from a free-map host:

1. Map find+erase keyed by block pointer (`FUN_00445750` / `FUN_004477a0` on `host+4`).
2. If map count `@+0x0c == 0` → return **1**.
3. Else take `offset=@block+0x18`, `size=@block+0x1c`; lower-bound free-range vector `[+0x14,+0x18)`; coalesce next/prev or insert; return **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00985390_FUN_00985390.md` (+ W33-P append, full hex) |
| Annotated | `docs/reconstruction/raw/aa_00985390_FUN_00985390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985390.cpp` |
| Function records | `functions/aa_00985390_FUN_00985390.md` + named |
| Live | entry `mov edi,ecx; mov esi,eax`; map size `cmp [edi+0xc],0`; free vec loads; epi `xor al,al` / `mov al,1` |
| Xrefs | 1 caller `FUN_00985a30` @ `0x00985a85` |

---

## 3. Signature (sealed)

```c
uint8_t AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred(
    void* host /*ecx*/, void* block /*eax*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | ECX → EDI | **High** |
| block | EAX → ESI | **High** |
| return AL | `1` empty map / `0` else | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes for stages)

| Stage | Match | Conf |
|---|---|---|
| map lower_bound + erase | **Yes** | **High** |
| empty → return 1 | **Yes** | **High** |
| free-range lower_bound stride 8 | **Yes** | **High** |
| coalesce next / prev / insert | **Yes** | **High** |
| Product class English | residual | **Open** |
| Nested helper plates | residual | **Med** |

---

## 5. Gaps / open

1. Product/PDB names for host + block types.
2. Nested map/vector helpers not owned (`00445750`/`004477a0`/`00460a60`/`00445c80`).
3. Full meaning of caller `FUN_00985a30` type-2 branch beyond sole xref.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
