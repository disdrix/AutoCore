# Review A (reconstruction fidelity): `aa_0043ecf0` PodU32U8_CopyIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ecf0` |
| **VA** | `0x0043ecf0`–`0x0043ecfe` (**15 B**) |
| **Canonical name** | `PodU32U8_CopyIfNonNull` (**Inferred**) |
| **Ghidra name** | `FUN_0043ecf0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-N) |
| **Counterpart** | `reviews/B_aa_0043ecf0_PodU32U8_CopyIfNonNull.md` |
| **System** | STL / guarded ring-deque POD store helper |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (15 B + twin `0043ece0`) + `get_function_by_address` + `analyze_function_complete`; 1 caller / 1 xref |
| **Verdict** | **accept** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Null-safe store of a **dword + byte** POD into an 8-byte slot. Used exclusively by `GuardedVector_PushBack_Stride2_U32U8` after slot LEA.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043ecf0_FUN_0043ecf0.md` (+ 2026-07-29 W32-N append) |
| Annotated | `docs/reconstruction/raw/aa_0043ecf0_FUN_0043ecf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodU32U8_CopyIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ecf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043ecf0_FUN_0043ecf0.md` |
| Named record | `docs/reconstruction/functions/aa_0043ecf0_PodU32U8_CopyIfNonNull.md` |
| Live | decompile ≡ raw CF; full 15 B hex; twin delta sealed |

---

## 3. Signature (sealed)

```c
// EAX=dest; ECX=src; RET; void
void PodU32U8_CopyIfNonNull(uint8_t* dest /*EAX*/, const PodU32U8* src /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| dest | **EAX** (null-checked) | **High** |
| src | **ECX** | **High** |
| cleanup | plain **`RET`** | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if (EAX == 0) goto ret
[EAX]   = [ECX]        // u32
[EAX+4] = [ECX+4]      // u8
ret
```

| Stage | Match | Conf |
|---|---|---|
| Null gate on dest only | **Yes** | **High** |
| u32 + u8 write | **Yes** | **High** |
| No src null check | **Yes** | **High** |
| Leaf / no callees | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (15 B):

```
85c0740a8b1189108a4904884804c3
```

| Site | Bytes | Meaning |
|---|---|---|
| Gate | `85 C0 74 0A` | `test eax,eax / jz +10` |
| Dword | `8B 11 89 10` | copy `[ecx]` → `[eax]` |
| Byte | `8A 49 04 88 48 04` | copy byte at +4 |
| Exit | `C3` | `ret` |

Twin `0043ece0`: second field is dword (`8B 49 04 89 48 04`). Pad after body: `CC`.

---

## 6. Gaps

- Product/PDB element struct English.
- Trailing 3 bytes of 8-byte slot unwritten (by design).
- Runtime / bit-exact.

---

## 7. Verdict

ABI, 5-byte write width, null dest gate, and full 15 B sealed; twin relationship to `0043ece0` confirmed → **accept**.
