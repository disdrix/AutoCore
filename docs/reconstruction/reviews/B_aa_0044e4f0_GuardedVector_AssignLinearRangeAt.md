# Review B (skeptical / adversarial): `aa_0044e4f0` GuardedVector_AssignLinearRangeAt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e4f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-L) |
| **Counterpart** | `reviews/A_aa_0044e4f0_GuardedVector_AssignLinearRangeAt.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall / ECX container | **Falsified** — container from stack; plain RET |
| 2 | Ring-to-ring copy (`RingCopyRange` family) | **Falsified** — source is linear `first++` dword walk; dest is ring-mapped |
| 3 | Constructs / grows capacity | **Falsified** — pure assign into existing slots; no callees |
| 4 | Always stores | **Falsified** — `CMP slot,src / JE` self-assign skip |
| 5 | Exactly 5 stack args at all call sites | **Partial** — body uses 5; parent pushes 6 (`ADD ESP,0x18`); 6th residual unread |
| 6 | Stdcall `RET N` | **Falsified** — bare `C3`; caller cleans |
| 7 | Product name retail | **Overstated** — inferred `GuardedVector_AssignLinearRangeAt` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Cdecl 5-live + plain RET | **High** | Stack imbalance |
| Page map `>>2` / wrap / sub | **High** | Wrong slot / OOB |
| Self-assign skip | **High** | Spurious write |
| Out iter `{c, end_idx}` | **High** | Parent iterator corrupt |
| 6th residual unread | **High** | Over-specify formals |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Overlap edge cases |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for first != last:
    map dest_idx → slot; if slot!=first *slot=*first; dest_idx++
  out = {container, dest_idx}

bytes:
  MOV EAX,[ESP+0xC] last; MOV EBP,container; MOV ESI,first; MOV EDI,dest_idx
  JE empty; loop SHR/LEA/wrap/store; ADD ESI,4; INC EDI
  MOV [out+4],EDI; MOV [out],EBP; RET

parent InsertRange sites:
  push ×6; CALL 0044e4f0; ADD ESP,0x18  (one fallthrough path)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 100 B sealed. Sole parent `0044e1c0` (3 xrefs).

---

## 4. Surviving contract for AutoCore

```
// GuardedVector linear→ring assign leaf:
//   stack: out*, first*, last*, container, dest_idx  (+ optional unread 6th)
//   plain RET (cdecl); caller ADD ESP
//   page = idx>>2; wrap if capacity<=page; sub = idx - page*4
//   if slot != src: *slot = *src  (one dword)
//   out = {container, end_idx}
// Do not invent thiscall, ring-source walk, construct, or size mutation.
// Do not drop self-assign skip — bytes honor it.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/page map/leaf role; 6th residual + product name are non-blocking → **accept**.
