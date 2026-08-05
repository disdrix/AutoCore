# Review A (reconstruction fidelity): `aa_00767570` stoChunkReader_TestAndPopSoftSkipBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767570` |
| **VA** | `0x00767570`–`0x007675BD` |
| **Canonical name** | `stoChunkReader_TestAndPopSoftSkipBit` (**Inferred**) |
| **Prior scaffold** | `FUN_00767570` / `Named_CalleeOf_Named_gfxBody_00767570` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W38-I |
| **Counterpart** | `reviews/B_aa_00767570_stoChunkReader_TestAndPopSoftSkipBit.md` |
| **System** | `storage` / arda2 `stoChunk` |
| **Verdict** | **accept-with-gaps** — test+pop CF, EDI ABI, bit math, resize call sealed; product English + caller intent open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Test soft-skip bitset bit `(size-1)` and **pop** it by resizing size `N → N-1`. Return prior bit value as bool. Differs from test-only peer `stoChunkReader_SoftSkipIfBitSet` (`0x00767120`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767570_FUN_00767570.md` (+ W38-I live seal) |
| Annotated | `docs/reconstruction/raw/aa_00767570_FUN_00767570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_TestAndPopSoftSkipBit.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767570_stoChunkReader_TestAndPopSoftSkipBit.md` |
| Live decompile | Ghidra `decompile_function` `0x00767570` — ≡ raw (decompiler `FUN_004362c0(0)` shape) |
| Live bytes | `read_memory` `0x00767570` (80 B; ends `5B C3 CC CC`) |
| Peer | `stoChunkReader_SoftSkipIfBitSet` dual (W17-L) |
| Caller (context) | `FUN_00765740` decompile (not owned) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Soft-skip view | **EDI** (`unaff_EDI`; `MOV ECX,EDI` into resize) |
| Stack args | none; plain **`RET`** |
| Return | **AL** bool via `SETNE` / early `XOR AL,AL` |
| Body | `0x00767570`–`0x007675BD` (**0x4E** B) |

### 3.2 Bit math — **SEALED** (≡ SoftSkipIfBitSet)

```
size = *EDI
if size==0 → false
base = EDI[+8]; low = size & 0x1f; base += (size>>5)*4
idx = low - 1
return (word[idx>>5] & (1<<(idx&0x1f))) != 0
```

### 3.3 Pop via resize — **SEALED** (bytes over decompiler)

| Fact | Confidence |
|---|---|
| Capture bit **before** call (`TEST`/`SETNE` then `CALL`) | **High** |
| `PUSH 0; LEA EAX,[size-1]; MOV ECX,EDI; CALL FUN_004362c0` | **High** |
| New size = N-1 (not zero wipe) | **High** |
| Decompiler `FUN_004362c0(0)` is **incomplete** (0 is stack fill) | **High** |

### 3.4 Call graph — **SEALED**

| Fact | Confidence |
|---|---|
| Sole callee `FUN_004362c0` | **High** |
| Sole caller `FUN_00765740` @ `0x00765C96` | **High** |
| Caller discards return | **High** (decompile of caller) |

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| CF / bytes / pop | **High** | read_memory + dual decompile |
| Soft-skip family role | **High** | bit math peer + gfxBody call site |
| Product English name | **Inferred** | no plate string on this leaf |
| Resize helper internals | **Out of scope** | unowned `FUN_004362c0` |
| Runtime | **Open** | |

---

## 5. Gaps (non-blocking for CF seal)

1. Studio symbol / exact product name.
2. Full English for `+0`/`+8` fields (shared with SoftSkipIfBitSet).
3. Why gfxBody ignores the return (side-effect-only pop at end of v2 path).
4. `size & 0x1f == 0` edge (idx underflow) — same open as SoftSkipIfBitSet.
