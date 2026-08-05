# Review A (reconstruction fidelity): `aa_0046a350` StdUninitCopy_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a350` |
| **VA** | `0x0046a350`–`0x0046a372` exclusive (**34 B** / `0x22`) |
| **Canonical name** | `StdUninitCopy_Elem28_Inferred` |
| **Ghidra name** | `FUN_0046a350` |
| **Review date** | `2026-07-29` (W36-P dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-P) |
| **Counterpart** | `reviews/B_aa_0046a350_StdUninitCopy_Elem28_Inferred.md` |
| **System** | stl-helpers / POD uninit_copy (elem 0x1c) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 34 B) + xrefs/parent sites. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Leaf MSVC-style `std::uninitialized_copy` for POD T size **0x1c**:

1. If `src_begin == src_end` (EDX == EBX), return dst.
2. Else loop: if dest non-null, `REP MOVSD` 7 dwords; always advance src/dst by `0x1c`.
3. Bare `RET`; EAX = dest end.

Used by elem-28 ValueEdx insert-n (`FUN_00469f50`) for grow relocate and in-place arms.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-P append) | `docs/reconstruction/raw/aa_0046a350_FUN_0046a350.md` |
| Annotated | `docs/reconstruction/raw/aa_0046a350_FUN_0046a350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_Elem28_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0046a350.cpp` |
| Function records | `functions/aa_0046a350_FUN_0046a350.md`, `functions/aa_0046a350_StdUninitCopy_Elem28_Inferred.md` |
| Live | decompile ≡ bytes CF; 4 call sites in sole parent |
| Pair (this dual) | `StdVector_Resize_Elem28_Inferred` (`0x00466df0`) |

---

## 3. Signature (sealed — bytes win)

```c
// Register ABI; bare RET; leaf
// Decompiler: void __fastcall (phantom param_1, src* EDX) + in_EAX + unaff_EBX
Elem28* StdUninitCopy_Elem28_Inferred(
    Elem28* dst /*EAX*/,
    const Elem28* src_begin /*EDX*/,
    const Elem28* src_end /*EBX*/);
```

| Slot | Source | Conf |
|---|---|---|
| dst* | EAX (in/out as end) | **High** |
| src_begin* | EDX | **High** |
| src_end* | EBX | **High** |
| decompiler param_1 | empty storage phantom | **High** (not formal) |
| RET | bare `C3` | **High** |
| stride | `ADD …,0x1C` + `MOV ECX,7` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if src_begin == src_end: return dst
loop:
  if dst != null: copy 7 dwords (REP MOVSD)
  src_begin += 1 element
  dst       += 1 element
  if src_begin != src_end: goto loop
return dst
```

| Stage | Match | Conf |
|---|---|---|
| Empty-range early out | **Yes** (`CMP EDX,EBX` / `JE`) | **High** |
| Null dest skip stores | **Yes** (`TEST EAX` / `JE`) | **High** |
| 7-dword element copy | **Yes** (`REP MOVSD`) | **High** |
| Always advance 0x1c | **Yes** | **High** |
| Leaf | **Yes** (0 callees) | **High** |
| EAX live-out as dest_end | **Yes** (parent `MOV [EDI+8],EAX`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 34 B hex:

```
3bd3741d565785c0740bb9070000008bf28bf8f3a583c21c83c01c3bd375e75f5ec3
```

Entry: `CMP EDX,EBX; JE done; PUSH ESI; PUSH EDI`.  
Epilogue: `POP EDI; POP ESI; RET`. Pad `CC` then unrelated.

Call site example (`0x0046a1c4` region in `FUN_00469f50`): `MOV EAX,EBX; MOV EDX,ESI; … CALL 0x0046a350` then publish end from EAX.

---

## 6. Gaps / open

1. Product/MSVC demangle English.
2. Concrete POD T for the 0x1c element.
3. Runtime / bit-exact / differential.

Fidelity pass seals full 34 B body, three-register ABI, stride, null gate, and leaf classification. Residual product English is non-blocking → **accept**.
