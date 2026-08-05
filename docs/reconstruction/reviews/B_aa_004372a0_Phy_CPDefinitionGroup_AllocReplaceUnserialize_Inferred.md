# Review B (skeptical / adversarial): `aa_004372a0` Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004372a0` |
| **VA** | `0x004372a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004372a0_Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 158 B + 4 xrefs + ctor/unserialize decomps + vtbl |
| **Agent** | W38-E OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void`/no-args ABI is complete | Bytes: `C2 04 00` ×2; callers `PUSH reader`; EDI slot ops | **Falsified complete** — stack reader + EDI + RET4 |
| 2 | ECX-thiscall on the group object | No `MOV ECX,obj` as this for the unit; EDI is slot | **Falsified thiscall** |
| 3 | OOM still replaces slot (like morph twin) | OOM branch never writes `[EDI]`; returns `-1` | **Falsified replace-on-OOM** |
| 4 | Scaffold gfxBody product role | Callee is phyCPDefinition.cpp CPDG | **Rejected scaffold** |
| 5 | Created size ≠ 0x14 | `PUSH 0x14` before new | **Falsified** |
| 6 | vtbl+4 is real work | `FUN_0056f570` is bare `RET` | **Sealed nop first-ref** |
| 7 | Product method name sealed | No plate/RTTI on this VA | **Accepted gap** (`_Inferred`) |
| 8 | Unserialize ABI pure cdecl(obj) | Bytes load EBX from stack reader before call | **Sealed hybrid** (unowned callee) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc-replace-unserialize role | **Confirmed** | Wrong asset load port |
| EDI slot + stack reader + RET 4 | **Confirmed** | Caller contract break |
| Slot-preserving OOM | **Confirmed** | Leak / stale pointer bugs |
| CPDG / phy group class | **Confirmed** | Wrong domain |
| English name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

gfxBody path (`0x007658c0` / `0x00765d18`):

```text
; EDI = slot (after ADD EDI,0x64 / prior LEA)
PUSH EBP          ; reader
CALL 0x004372a0
OR ESI, EAX       ; accumulate status
```

Asset path (`0x0095e495`): `LEA EDI,[EBX+0x64]; PUSH EBP; CALL` — same EDI+stack pattern.

---

## 4. Byte anchors

```text
0x004372a0: 6A FF 68 … 6A 14 E8 …   ; SEH + new(0x14)
            83 46 04 01 … FF 50 04  ; AddRef; vtbl+4
            8B 0F … FF 52 08        ; release *EDI; vtbl+8
            89 37 E8 … C2 04 00     ; store; unserialize; RET 4
            8B C3 … C2 04 00        ; EAX=-1; RET 4
```

---

## 5. What would reverse the seal?

- Proof reader is in a different register and stack arg is something else — contradicted by `MOV EBX,[ESP+0x1c]` immediately before push/call and every caller `PUSH EBP/reader`.
- Proof OOM writes the slot — contradicted by OOM branch never executing `MOV [EDI],…`.
- Proof product is graphics morph — contradicted by phyCPDefinition.cpp / CPDG strings on the only non-trivial callee.

None observed.
