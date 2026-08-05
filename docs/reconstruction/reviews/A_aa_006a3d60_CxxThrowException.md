# Review A (reconstruction fidelity): `aa_006a3d60` _CxxThrowException

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d60` |
| **VA** | `0x006a3d60` |
| **Body** | `0x006a3d60`–`0x006a3d65` (6 bytes) |
| **Canonical name** | `_CxxThrowException` |
| **Review date** | `2026-07-29` (W17-N dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006a3d60_CxxThrowException.md` |
| **System** | CRT / MSVC C++ EH |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

MSVC C++ **throw** entry import trampoline. Entire unit is `jmp dword ptr [IAT]`. Noreturn. No AutoAssault domain logic.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006a3d60_CxxThrowException.md` |
| Annotated | `docs/reconstruction/raw/aa_006a3d60_CxxThrowException.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CxxThrowException.cpp` |
| Function record | `docs/reconstruction/functions/aa_006a3d60_CxxThrowException.md` |

---

## 3. Byte seal (`read_memory` @ `0x006a3d60`, 6 B body)

```
FF 25 D8 64 9C 00     jmp dword ptr [0x009c64d8]
```

| Claim | Confidence | Evidence |
|---|---|---|
| Body is only import jmp | **High** | 6 bytes `FF 25 …`; Ghidra body end `006a3d65` |
| IAT at `0x009c64d8` | **High** | displacement in instruction |
| Symbol `_CxxThrowException` | **High** | Ghidra name + CRT signature |
| Noreturn | **High** | Ghidra `noreturn` + CRT contract |
| Decompiler jumptable warning | **noise** | indirect jmp via IAT, not multi-branch table |
| No game state touch | **High** | no loads/stores beyond jmp |

IAT dword read: `EE BC 6E 00` → `0x006ebcee` (static analysis resolution).

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Single jmp [IAT] | **Yes** |
| No local prologue | **Yes** |
| CRT args passthrough | **Yes** (implicit) |

---

## 5. Gaps / open

1. Live load-time IAT bind may differ from static dump.
2. Full MSVC ThrowInfo / unwind semantics are CRT-owned, out of this dual.
3. Exhaustive caller list not required for thunk seal.

**Verdict:** **accept**
