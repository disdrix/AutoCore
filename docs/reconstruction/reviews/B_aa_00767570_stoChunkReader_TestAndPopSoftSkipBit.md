# Review B (skeptical / adversarial): `aa_00767570` stoChunkReader_TestAndPopSoftSkipBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00767570_stoChunkReader_TestAndPopSoftSkipBit.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs. No `disassemble_bytes`. Own VA `0x00767570` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as SoftSkipIfBitSet (test-only leaf) | This calls `FUN_004362c0`; peer has no callees | **Falsified** equality — **test+pop** |
| 2 | ECX thiscall like SoftSkipIfBitSet | Body uses `unaff_EDI`; `MOV ECX,EDI` only for callee | **Falsified** — **EDI** view |
| 3 | `FUN_004362c0(0)` clears entire bitset to empty | Bytes: `LEA EAX,[EDX-1]` → new size = N-1 | **Falsified** — **pop one** |
| 4 | Return is always used by callers | Only xref in gfxBody; decompile shows bare call | **Falsified** as "must use return" — site ignores |
| 5 | This is a gfxBody-only product API | Body is generic bitset math; plate-less sto helper | **Survives** as storage helper; gfxBody is sole *known* caller |
| 6 | Decompiler is complete for resize ABI | Hides EAX new-size | **Falsified** completeness — bytes required |
| 7 | Three-rep diverges on CF | live ≡ raw; bytes refine only callee ABI | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI view, plain RET, AL bool | **High** | Wrong register / stack |
| Test bit (size-1) | **High** | Soft-skip desync |
| Pop N→N-1 via resize | **High** | Bitset leak / double-fire |
| Soft-skip English | **Inferred** | Doc-only |
| Resize fill arg meaning | **Tentative** | Unowned helper |
| Runtime | **Open** | Shipping load |

---

## 3. Cross-check against raw + bytes

```
raw/live:
  if *EDI==0 → false
  bit = test(size-1)
  FUN_004362c0(...)
  return bit

bytes:
  early XOR AL,AL; RET
  mask in EBX; TEST [ESI],EBX; SETNE BL
  PUSH 0; LEA EAX,[EDX-1]; MOV ECX,EDI; CALL FUN_004362c0
  MOV AL,BL; RET
  pad CC
```

**No conflict** on owned CF. Resize body not re-proven.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkReader_TestAndPopSoftSkipBit @ 0x00767570
// retail: EDI = view (size@0, bitset@+8), plain RET, AL = prior bit

bool TestAndPopSoftSkipBit(StoSoftSkipView view)
{
    if (view.Size == 0) return false;
    bool was = TestBit(view, view.Size - 1);
    ResizeBitset(view, view.Size - 1); // FUN_004362c0
    return was;
}
```

---

## 5. Verdict

**accept-with-gaps** — CF sealed; name Inferred; unowned resize + caller intent open.
