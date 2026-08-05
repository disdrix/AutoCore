# Review B (skeptical / adversarial): `aa_00435f30` stoChunkStream_ReadBytes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00435f30` |
| **VA** | `0x00435f30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00435f30_stoChunkStream_ReadBytes_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` + 8 xrefs + parent `00436090` dual |
| **Agent** | W18-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is f32 / typed element reader | Body is byte-count + `rep movs*`; no float ops | **Falsified typed** |
| 2 | `this` is full `stoChunkReader` | Callers pass `reader+0x14`; offsets match subobject | **Falsified full reader** |
| 3 | Always refills on short buffer | Only when `n ≤ maxChunk`; larger uses direct vtbl | **Falsified always-refill** |
| 4 | Silent fail on refill | `or eax,-1; ret 8` | **Falsified silent** |
| 5 | `unaff_EBX` is a real third input | Stack dest advanced + pushed to vtbl+0x14 | **Falsified decompiler** |
| 6 | `ret 4` / single stack arg | Three epilogues `C2 08 00` | **Falsified** |
| 7 | Writes without advancing cursor | All success paths `add [ebx+4], …` | **Falsified** |
| 8 | Same as `FUN_00435df0` | That is callee-only refill; this owns copy policy | **Falsified conflation** |
| 9 | Text/token path (`00767fd0`) | Not referenced in body | **Falsified** |
| 10 | Product name sealed without PDB | Name is role-inferred from callers/layout | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-read + three-path CF | **Confirmed** | Wrong asset load |
| ABI `ret 8` / 0|-1 | **Confirmed** | Caller stack smash |
| Subobject vs full reader | **Confirmed** | Offset bugs in ports |
| Direct vtbl pair | **Confirmed** | Miss large reads |
| Product / vtbl names | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs parent

`stoChunkReader_readF32Array` (`0x00436090`) owns **count-in-EAX**, mode `+0x4044`, and element loops. This unit owns **only** bulk bytes when `N≥16` on binary path with `ECX=reader+0x14`. Do not merge this VA into the parent dual ownership.

---

## 4. Byte anchors

```text
0x00435f30: 53 8B D9              ; push ebx; mov ebx, ecx
            8B 53 04  8B 43 0C    ; cursor / avail
            … 7E 70               ; jle bulk if fits
            3B 6B 10  7E 50       ; cmp n, maxChunk; jle refill
            … 8D 74 1A 18 F3 A5   ; lea src window; rep movsd
            … FF 50 04 / FF 50 14 ; vtbl +4 / +0x14
            … E8 … FUN_00435df0
            … 83 C8 FF C2 08 00   ; return -1
            … 33 C0 5B C2 08 00   ; return 0
```

---

## 5. What would reverse the seal?

- Live proof that `+0x10` is not a max-chunk threshold (e.g. different unit).
- Discovery that vtbl+0x14 is not a dest-filling read (would reclassify direct path).
- Bit-exact mismatch on cursor arithmetic for partial drain.

None observed from decompile + bytes + caller dual.
