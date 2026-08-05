# Review A (reconstruction fidelity): `aa_0045f360` StdUninitCopy_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045f360` |
| **VA** | `0x0045f360`–`0x0045f3AC` exclusive (**76 B**) |
| **Canonical name** | `StdUninitCopy_Pod28` |
| **Ghidra name** | `FUN_0045f360` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-K) |
| **Counterpart** | `reviews/B_aa_0045f360_StdUninitCopy_Pod28.md` |
| **System** | MSVC trivial uninit-copy, elem 0x1c |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body 76 B) + parent `0x0045cd30` decompile + 4 xref call sites. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Trivial range copy of POD elements size `0x1c` from `[src_begin, src_end)` into `dst`, returning advanced `dst_end`. Leaf helper for `StdVector_InsertN_Pod28` relocate/shift arms.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-K append) | `docs/reconstruction/raw/aa_0045f360_FUN_0045f360.md` |
| Annotated | `docs/reconstruction/raw/aa_0045f360_FUN_0045f360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_Pod28.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0045f360.cpp` |
| Function records | `functions/aa_0045f360_FUN_0045f360.md`, `functions/aa_0045f360_StdUninitCopy_Pod28.md` |
| Parent insert-n | W34-P `aa_0045cd30` StdVector_InsertN_Pod28 |
| Live | decompile + 76 B hex + parent call-site memory |

---

## 3. Signature (sealed)

```c
// EAX=dst, ECX=src_begin, EDI=src_end; bare RET; EAX = dst_end
Pod28* StdUninitCopy_Pod28(Pod28* dst, const Pod28* src_begin, const Pod28* src_end);
```

| Formal | Source | Conf |
|---|---|---|
| dst | EAX (live-in; advanced in loop) | **High** |
| src_begin | ECX → ESI | **High** |
| src_end | EDI (unaff / live-in) | **High** |
| cleanup | `C3` | **High** |
| return | EAX = advanced dst | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = ECX
if (ESI == EDI) goto done          // empty
ECX = EAX+0x14; EDX = ESI+0x14     // mid-pointers
loop:
  if (EAX != 0) copy 7 dwords ESI→EAX via mid ptrs
  ESI+=0x1c; EAX+=0x1c; ECX+=0x1c; EDX+=0x1c
  if (ESI != EDI) goto loop
done: POP EBX; POP ESI; RET
```

| Stage | Match | Conf |
|---|---|---|
| empty early-out | `3B F7 74 44` | **High** |
| null-dst skip stores | `85 C0 74 26` | **High** |
| 7-dword copy | seven MOV pairs | **High** |
| stride 0x1c | four `83 C? 1C` | **High** |
| sole parent Pod28 insert-n | 4 xrefs → `0045cd30` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (76 B) — see raw W35-K append.

Entry: `56 8B F1 3B F7 74 44 …`  
Epilogue: `5B 5E C3`  
Pad: `CC` from `0x0045f3AC`.

**Decompile ≢ bytes:** void / single ECX formal; omits EAX/EDI. **Bytes + parent win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Callers | `FUN_0045cd30` @ `0x0045ce99`, `0x0045cecc`, `0x0045cf83`, `0x0045cfe0` |
| Callees | none |

---

## 7. Gaps

1. Product/PDB English for Pod28 element type.  
2. Sibling fill-n `FUN_0045f150` not dual-owned.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

76 B leaf sealed: EAX/ECX/EDI ABI, 0x1c stride, 7-dword POD copy, parent-only use → **accept-with-gaps** (product T open only).
