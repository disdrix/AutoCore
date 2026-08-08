# Review B (skeptical / adversarial): `aa_00489f20` SoftCastHitList_QuickSortRange_KeyFloat14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489f20` |
| **VA** | `0x00489f20` |
| **Canonical name** | `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` |
| **Review date** | `2026-08-05` (MEGA-115 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | **thiscall** / ECX = array | **Falsified** — `MOV EBX,[EBP+8]`; no ECX this; bare `RET` + caller `ADD ESP,0x10` |
| 2 | Full **0x30 memcpy** swap | **Falsified** — only +0x00..+0x14 and +0x20 written; +0x18/+0x1C/+0x24..+0x2C untouched |
| 3 | **Descending** sort | **Falsified** — left advances while `key < pivot`; right while `pivot < key` (ascending) |
| 4 | Key at **+0x00** or **+0x20** | **Falsified** — pivot `FLD [mid*0x30+base+0x14]`; scans use same +0x14 |
| 5 | Element size **0x14** or **0x20** | **Falsified** — `LEA r,[i+i*2]; SHL r,4` = **0x30**; scan steps `ADD/SUB ECX,0x30` |
| 6 | **STL** `std::sort` / comparator thunk | **Falsified** — hand-rolled Hoare body; no comparator call; only self-call |
| 7 | Multi external callers / skill inventory sort | **Falsified** — xrefs = self + sole external `FUN_0048a060` soft-cast gate |
| 8 | Cookie/param_4 participates in compare | **Falsified** — only re-pushed; never loaded into FPU/compare |
| 9 | Same function as gate `0048a060` | **Falsified** — gate is 35 B count>1 trampoline; this is 318 B qsort core |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
// prologue (cdecl frame, 16-byte align)
PUSH EBP / MOV EBP,ESP / AND ESP,0xFFFFFFF0 / SUB ESP,0x64
MOV EBX, [EBP+8]     // base
MOV EDI, [EBP+0xC]   // lo
MOV EDX, [EBP+0x10]  // hi

// pivot
LEA EAX, [EDI+EDX]; SAR EAX,1
LEA EAX, [EAX+EAX*2]; SHL EAX,4    // *0x30
FLD  dword [EAX+EBX+0x14]
FSTP dword [ESP+0x54]

// left scan: FCOMP pivot; TEST AH,5; JP done; INC ESI; ADD ECX,0x30
// right scan: symmetric DEC EDX; SUB ECX,0x30

// swap (partial): copy [j]↔[i] at +0,+4,+8,+c,+10,+14,+20 only
// recurse: PUSH cookie; PUSH j; PUSH lo; PUSH base; CALL self; ADD ESP,0x10
// tail: MOV EDI,ESI; store lo; JMP outer

POP EDI/ESI/EBX; MOV ESP,EBP; POP EBP; RET   // bare C3
```

Parent call site `0x0048a079`:

```text
// ECX = SoftCastHitList* this (gate)
PUSH cookie (this&~0xFF)
PUSH count-1
PUSH 0
PUSH [ECX+0x10]     // array base
CALL 0x00489f20
ADD ESP,0x10
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hoare qsort CF + mid pivot | **High** | wrong order / infinite loop |
| cdecl + bare RET + 4 args | **High** | stack smash |
| Stride 0x30 / key float +0x14 | **High** | corrupt hits |
| Partial swap field set | **High** | silent field sticky bugs |
| Sole external caller | **High** | missing specialization |
| Product key English | Medium | naming only |
| Unswapped field meaning | Medium | layout docs only |

---

## 4. Surviving contract for AutoCore

```csharp
// Soft-cast hit array quicksort [lo, hi] inclusive.
// Elem size 0x30; ascending float key at +0x14; mid pivot.
// Partial swap: +0x00..+0x14 and +0x20 only.
// cdecl; caller cleans 16 bytes. cookie ignored.
void SoftCastHitList_QuickSortRange(HitElem* base, int lo, int hi, uint cookie)
{
    while (true) {
        float pivot = base[(lo + hi) >> 1].Key14;
        int i = lo, j = hi;
        do {
            while (base[i].Key14 < pivot) i++;
            while (pivot < base[j].Key14) j--;
            if (j < i) break;
            if (j != i) SwapPartial(ref base[i], ref base[j]);
            j--; i++;
        } while (i <= j);
        if (lo < j) SoftCastHitList_QuickSortRange(base, lo, j, cookie);
        lo = i;
        if (hi <= i) return;
    }
}
// Keep distinct from gate SoftCastHitList_SortIfCountGt1 (0x0048a060).
// Do not full-memcpy 0x30; preserve sticky fields at +0x18..+0x1C / +0x24..+0x2C.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/key/partial-swap/caller. Residual product key English + unswapped-field semantics → **accept-with-gaps**.
