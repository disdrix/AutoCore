# Review B (skeptical / adversarial): `aa_0074ce60` phyBoundingBox_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ce60` |
| **VA** | `0x0074ce60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0074ce60_phyBoundingBox_Unserialize.md` |
| **Evidence** | Live decompile + body `read_memory` + 17 xrefs + 5 callers + call-site context + reader helper decomps |
| **Agent** | W38-H OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Only a gfx post-effect hook | Path `phyBoundingBox.cpp` + TAG/version logs; 5 callers beyond gfx piece | **Falsified sole-role** |
| 2 | Tag is not BBOX | Immediate `0x42424F58` = MSVC multi-char `'BBOX'` | **Falsified** |
| 3 | thiscall-only (no EBX reader) | Callers `MOV EBX,reader`; EnterChunkScope uses EBX; decompiler `unaff_EBX` | **Falsified** |
| 4 | Single version | Branch version−1 / version−2 / error | **Falsified** |
| 5 | Radius uses full 3D | SSE uses x (`+0`) & z (`+8`) vs x (`+0x20`) & z (`+0x28`) only | **Sealed xz-only** |
| 6 | v1/v2 identical | v2 reads bool first; v1 derives bool from scalar≤0 | **Sealed difference** |
| 7 | Always success return 0 | Final uses reader `+0x402c` → `(-1 < status) - 1` | **Falsified always-0** |
| 8 | Product name open | Path + three distinctive strings | **Name sealed High** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unserialize role + file identity | **Confirmed** | Wrong system port |
| ECX object / EBX reader | **Confirmed** | Caller contract break |
| Tag / versions / returns | **Confirmed** | Asset load failures |
| Field offsets + xz extent | **Confirmed** | Bad bounds |
| Float3 semantic labels | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

`gfxGeometryPiece_Unserialize` @ `0x0074b0c0`:

```text
LEA ECX,[EBP+0x24]     ; bbox embedded in piece
CALL FUN_0074ce60
; EBX = outer stoChunkReader (live)
```

`FUN_00765740` @ `0x007658b5`:

```text
MOV EBX,EBP            ; reader
LEA ECX,[EDI+0x4]      ; bbox*
CALL FUN_0074ce60
MOV ESI,EAX            ; capture 0/-1
```

Matches dual-register convention.

---

## 4. Byte anchors

```text
0x0074ce60: 6A FF 68 B3 1A 9B 00 …  ; SEH LAB_009b1ab3
            8B F1 …                 ; ESI = ECX (bbox)
            81 7C 24 14 58 4F 42 42 ; tag 'BBOX'
            … OR EAX,-1 / RET       ; error -1
            MOV EAX,3; CALL readF32Array ×3
            … SQRT / FABS → [ESI+0x10]
            … status @ [EBX+0x402c] → 0 / -1
0x0074d0b3: C3                      ; final RET; pad CC
```

---

## 5. What would reverse the seal?

- Proof object is not bbox (e.g. different type with borrowed strings) — contradicted by dedicated path + TAG string naming phyBoundingBox.
- Proof reader is stack formal only — contradicted by callers setting EBX without push of reader immediately before call (reader not on stack as sole arg).
- Proof 3D radius — contradicted by only two squared terms (x and z).

None observed.

**Verdict:** **accept**
