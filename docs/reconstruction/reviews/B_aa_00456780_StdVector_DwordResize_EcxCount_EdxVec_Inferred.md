# Review B (skeptical / adversarial): `aa_00456780` StdVector_DwordResize_EcxCount_EdxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00456780` |
| **VA** | `0x00456780` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00456780_StdVector_DwordResize_EcxCount_EdxVec_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 117 B + 58 xrefs + callee decomps + pool/physics call sites |
| **Agent** | W38-H OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler formals are complete ABI | Bytes: `RET 4` ×3; grow `LEA EAX,&fill`; call sites `PUSH fill` | **Falsified complete** — fill formal required |
| 2 | Same as `FUN_0044a380` | That twin uses **ECX=vec / EAX=n**; different grow/shrink callees | **Falsified merge** |
| 3 | Same as `FUN_004367f0` | Twin uses stack n + `RET 8` | **Falsified merge** |
| 4 | Element size ≠ 4 | `SAR 2` / `LEA [reg+reg*4]` throughout | **Falsified** |
| 5 | Grow ignores count (decompiler) | `SUB ECX,ESI` before InsertN; empty path `XOR ESI,ESI` then same | **Falsified no-count** |
| 6 | Shrink destroys non-POD | `FUN_00456660` memmove-publish end | **Sealed POD dword** |
| 7 | Scaffold gfxBody name is product | 35 multi-domain callers | **Rejected scaffold** |
| 8 | ECX is vec (thiscall) | Entry uses **EDX** for begin/end; callers `MOV EDX,vec` / `LEA EDX,…` | **Falsified thiscall-vec** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resize role + dword stride | **Confirmed** | Wrong container port |
| EDX + ECX + fill + RET 4 | **Confirmed** | Caller contract break |
| Grow/shrink split | **Confirmed** | Capacity bugs |
| Distinction from `0044a380` / `004367f0` | **Confirmed** | Wrong RET / arg count |
| Product name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

Pool freelist shrink (`0x009860ce`):

```text
PUSH 0                 ; fill
LEA ECX,[size-1]       ; newCount
; EDX = host+0x10 freelist vec (live)
CALL FUN_00456780
```

Clear (`0x004665d6`):

```text
PUSH EBP               ; fill
XOR ECX,ECX            ; n=0
MOV EDX,ESI            ; vec
CALL FUN_00456780
```

Matches EDX=vec + ECX=n + one stack fill + RET 4.

---

## 4. Byte anchors

```text
0x00456780: 8B 42 04 …        ; begin from [EDX+4]
            3B F1 73 34 …     ; size < n → grow
            … C2 04 00        ; RET 4 grow (empty)
            … C2 04 00        ; RET 4 grow (non-empty)
            85 C0 74 21 …     ; begin null → done
            3B CE 73 11 …     ; n >= size → done
            8D 04 88 50 52 …  ; begin+n*4; PUSH EDX; shrink
            … C2 04 00        ; RET 4
```

---

## 5. What would reverse the seal?

- Proof newCount is stack and ECX is scratch — contradicted by `CMP ESI,ECX` before any stack load of count, and callers loading ECX then single `PUSH fill`.
- Proof `RET 8` — contradicted by three `C2 04 00`.
- Proof vec in ECX — contradicted by `[EDX+4]` / `[EDX+8]` and caller `MOV EDX` / `LEA EDX`.

None observed.

**Verdict:** **accept**
