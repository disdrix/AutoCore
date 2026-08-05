# Review B (skeptical / adversarial): `aa_0045dd60` Anm_KestChunk_ReadF32Array_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045dd60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-P) |
| **Counterpart** | `reviews/A_aa_0045dd60_Anm_KestChunk_ReadF32Array_Inferred.md` |
| **Scratch** | `tmp/a_0045dd60.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void` / no formals is truth | **Falsified** — `MOV ESI,ECX`; `PUSH EDI`; stack dest at call; parent `ADD ESP,4` |
| 2 | thiscall with ECX=reader | **Falsified** — ECX is count; reader is EDI; Enter uses scope in ECX |
| 3 | Tag is KEYS / KEYR | **Falsified** — imm `54 53 45 4B` = **KEST** `0x4B455354` (sibling `0045d810` uses different tag) |
| 4 | Float count = elem_count (not *7) | **Falsified** — lea/mul sequence yields ESI*7 before readF32Array |
| 5 | RET 4 / callee cleans dest | **Falsified** — bare `C3`; caller `ADD ESP,4` |
| 6 | Writes vector without parent resize | **Overstated** — this only fills buffer; parent owns resize |
| 7 | Scaffold Named_CalleeOf is product name | **Rejected** — structural `_Inferred` only |
| 8 | Related algorithmically to `0052ade0` | **Falsified** — co-owned wave pair only; different systems |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tag + *7 fill | **High** | Corrupt track buffer |
| ECX/EDI/stack ABI | **High** | Wrong port calling convention |
| bare RET | **High** | Stack imbalance |
| KEST English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SEH + sub esp,0x14
MOV ESI, ECX                 ; count
PUSH EDI                     ; reader
EnterChunkScope(scope, EDI)
CMP [scope.tag], KEST
JNE fail
MOV ECX, dest_stack
EAX = ESI*7
PUSH EDI; CALL readF32Array
leave if ok; return EAX
fail: leave if ok; return -1
```

Live 2026-08-04 ≡ raw 2026-07-23 CF; bytes seal formals.

---

## 4. Surviving contract for AutoCore

```
// After Pod28 resize of track vector:
status = Anm_KestChunk_ReadF32Array_Inferred(count, reader, (float*)begin);
// Retail: ECX=count, EDI=reader, push begin; bare RET; check status != -1
// Do NOT invent thiscall(reader) or omit *7 float packing.
// Server may map to a typed ReadArray<Pod28>(count) without EDI artifact.
```

---

## 5. Verdict

Adversarial pass **confirms** A: ABI, tag, *7 packing, bare RET sealed; product KEST English open → **accept-with-gaps**.
