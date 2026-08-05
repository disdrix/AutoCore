# Review A (reconstruction fidelity): `aa_00788db0` MemZero_DestSize_ReturnOne_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00788db0` |
| **VA** | `0x00788db0`–`0x00788dfc` exclusive (**76 B** / `0x4C`) |
| **Canonical name** | `MemZero_DestSize_ReturnOne_Inferred` |
| **Ghidra name** | `FUN_00788db0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-O) |
| **Counterpart** | `reviews/B_aa_00788db0_MemZero_DestSize_ReturnOne_Inferred.md` |
| **System** | util / buffer zero leaf |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

cdecl leaf that zeros `size` bytes at `dest` and always returns **1**:

1. If signed `size > 4`: bulk `REP STOSD` of `floor((size-1)/4)` dwords; advance; remaining.
2. If signed remaining/`size > 0`: `REP STOSD` (`size>>2`) + `REP STOSB` (`size&3`).
3. `MOV EAX,1`; bare `RET`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-O) | `docs/reconstruction/raw/aa_00788db0_FUN_00788db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00788db0_FUN_00788db0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/MemZero_DestSize_ReturnOne_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00788db0.cpp` |
| Function records | `functions/aa_00788db0_FUN_00788db0.md`, `functions/aa_00788db0_MemZero_DestSize_ReturnOne_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex 76 B; 3 CODE callers; 0 callees |

---

## 3. Signature (sealed)

```c
// __cdecl; dest* [ESP+4], size [ESP+8]; bare RET; returns 1
uint32_t __cdecl MemZero_DestSize_ReturnOne_Inferred(void *dest, int size);
```

| Formal | Source | Conf |
|---|---|---|
| dest | `[ESP+4]` → EBX (`8B 5C 24 08` after push EBX) | **High** |
| size | `[ESP+8]` → ESI (`8B 74 24 10` after push EBX/ESI) | **High** |
| return | `B8 01 00 00 00` / EAX=1 | **High** |
| convention | bare `C3` + caller `ADD ESP,8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| size≤4 skip bulk | **Yes** (`CMP ESI,4` / `JLE`) | **High** |
| bulk dword count formula | **Yes** (`LEA EDX,[ESI-5]; SHR 2; ADD 1`) | **High** |
| `REP STOSD` bulk + tail | **Yes** (bytes; decompiler loops) | **High** |
| tail `REP STOSB` rem&3 | **Yes** | **High** |
| always return 1 | **Yes** | **High** |
| leaf (no calls) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry / loads | `53 8B 5C 24 08 56 8B 74 24 10 83 FE 04 57 8B FB` |
| Bulk STOSD | `F3 AB` after count setup |
| Tail STOSD/STOSB | `F3 AB` … `F3 AA` |
| Epilogue | `5F 5E B8 01 00 00 00 5B C3` |
| Size | **76 B** exclusive end `0x00788dfc` |
| Full hex | raw W37-O append |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product helper English (custom return-1 vs CRT memset).
- Whether any caller relies on return value (sites appear fire-and-forget).
- Runtime / bit-exact / differential.

---

## 7. Verdict

CF, ABI, size, return-1, leaf status sealed → **accept**.
