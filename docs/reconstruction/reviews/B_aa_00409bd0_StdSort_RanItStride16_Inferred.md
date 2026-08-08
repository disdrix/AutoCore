# Review B (skeptical / adversarial): `aa_00409bd0` StdSort_RanItStride16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409bd0` |
| **VA** | `0x00409bd0` |
| **Canonical name** | `StdSort_RanItStride16_Inferred` |
| **Review date** | `2026-08-05` (MEGA-043 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00409bd0_StdSort_RanItStride16_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context + callee batch decompile |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is PollBoundActions / input-action poll logic | **Falsified** — no action-map state; pure range sort; sole external caller is `FUN_00930360` sort-target-list |
| 2 | `__thiscall` / ECX = object this | **Falsified** — four stack args; ECX only LEA of local out-pair for partition; plain `RET` not `RET 4` |
| 3 | Element size 8 or 32 (SAR 3 / SAR 5) | **Falsified** — `SAR EAX,4` and `& 0xfffffff0` throughout body + caller |
| 4 | Stable quicksort only (no heap fallback) | **Falsified** — when `ideal ≤ 0` calls `0040a820`+`0040a380` (make/sort heap) |
| 5 | Insertion threshold 16 not 32 | **Falsified** — `CMP EAX,0x20` / `JLE` short path |
| 6 | `RET 4` / stdcall | **Falsified** — epilog bytes `5B 83 C4 08 C3`; caller `ADD ESP,0x10` |
| 7 | Same as soft-cast hit-list sort / other product sort wrappers | **Falsified** — different VA; this is the generic stride-16 `_Sort` body consumed by target-list builder |
| 8 | Depth halves only (`ideal/2`) | **Falsified** — `ideal/2 + (ideal/2)/2` (= ¾) dual CDQ/SAR |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
; entry
SUB ESP, 8
PUSH EBX
MOV EBX, [ESP+0x10]          ; first
...
MOV EDI, [ESP+0x20]          ; last
MOV EAX, EDI
SUB EAX, EBX
SAR EAX, 4                   ; count = bytes/16
CMP EAX, 0x20
JLE short_insert_path

MOV ESI, [ESP+0x24]          ; ideal
TEST ESI, ESI
JLE heap_fallback

; partition
PUSH pred
PUSH last
LEA ECX, [ESP+local_pair]
PUSH first
PUSH ECX
CALL FUN_00409f90            ; writes mid_lo/mid_hi
; ideal = ¾
; recurse smaller half; assign first/last to larger; loop

; epilog
POP EBX
ADD ESP, 8
RET                          ; C3
```

Call-site (`FUN_00930360` @ `0x009305fc`):

```text
PUSH 0x0092cdd0              ; pred
PUSH EBX                     ; count as ideal
PUSH ESI                     ; last
PUSH EDI                     ; first
CALL 0x00409bd0
ADD ESP, 0x10                ; cdecl cleanup
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + plain RET; 4 stack args | **High** | stack smash / wrong port |
| Stride 16 | **High** | wrong element size |
| Introsort / MSVC `_Sort` shape | **High** | wrong algorithm port |
| Sole external caller set | **High** | missing specialization |
| Product English (name plate) | Medium | naming only |
| Nested helper semantics detail | Medium | finishers residual |

---

## 4. Surviving contract for AutoCore

```csharp
// MSVC-style introsort for Elem16[] (sizeof == 16)
// void Sort(Elem16* first, Elem16* last, int ideal, Pred pred)  // cdecl
void SortStride16(Span<Elem16> range, Comparison<Elem16> pred)
{
    int ideal = range.Length; // caller seeds with count
    // while count > 32 and ideal > 0: partition; recurse smaller; ideal = ideal*3/4
    // if ideal exhausted: heap sort finishers
    // if count <= 32: insertion sort when count > 1
}
// Keep distinct from product wrappers (soft-cast sort, UI sort buttons).
// Do not attach PollBoundActions semantics.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/caller roles; PollBoundActions and thiscall claims die. Residual product English + undualed helpers → **accept-with-gaps**.
