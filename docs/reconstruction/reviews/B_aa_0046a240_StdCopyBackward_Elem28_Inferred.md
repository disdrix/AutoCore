# Review B (skeptical / adversarial): `aa_0046a240` StdCopyBackward_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-L) |
| **Counterpart** | `reviews/A_aa_0046a240_StdCopyBackward_Elem28_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack formals / stdcall | **Falsified** — bare `C3`; no stack arg loads |
| 2 | Decompiler `__fastcall (param_1, param_2)` is complete ABI | **Incomplete** — phantom `param_1` unused; real formals are EAX dest_end, EDX src_end, EBX src_begin |
| 3 | Forward `copy` / `memmove` | **Falsified** — exclusive ends step **backward** by 0x1c before each copy |
| 4 | Stride is 4 or string-aware | **Falsified** — `SUB …,0x1C` + `MOV ECX,7` + `REP MOVSD`; no `operator=` |
| 5 | Same as `BasicString_CopyBackward_Thunk_0x1c` | **Falsified** — that unit is a trampoline to string assign; this is POD leaf |
| 6 | ECX is a formal | **Falsified** — ECX loaded with constant 7 for REP only |
| 7 | Has callees | **Falsified** — leaf |
| 8 | Scaffold `Named_CalleeOf_*anmTrackMast*` is product | **Rejected** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI EAX/EDX/EBX | **High** | Wrong port linkage / mid-insert smash |
| Backward direction + stride 0x1c | **High** | Overlap corruption |
| Leaf / bare RET | **High** | Invented callees |
| Product demangle / T English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + parents

```
// Insert-n mid arm pattern (FUN_00466ea0 / FUN_00469f50 / FUN_0045cd30):
//   extend end via forward uninit-copy of tail
//   EAX = dest_end; EDX = src_end; EBX = where (src_begin)
//   call FUN_0046a240   ; reverse-shift middle
//   call FUN_0045efe0   ; assign-fill hole
```

Full 30 B hex:

```
3bda7419565783ea1c83e81c3bd3b9070000008bf28bf8f3a575eb5f5ec3
```

Decompile 2026-07-29 ≡ scaffold. W34-P/Q already named this helper as reverse-move / `FUN_0046a240` under insert-n mid arms.

---

## 4. Surviving contract for AutoCore

```
// Register ABI helper — do not invent stdcall formals:
void copy_backward(Elem28* dest_end /*EAX*/, Elem28* src_end /*EDX*/,
                   const Elem28* src_begin /*EBX*/) {
  while (src_begin != src_end) {
    --src_end; --dest_end;
    *dest_end = *src_end; // 28-byte POD
  }
}
// Mid-insert MUST reverse-walk for overlap safety; do not use forward copy.
```

---

## 5. Verdict

Adversarial pass confirms A on full leaf contract. Residual product English / concrete T does not block the sealed helper → **accept**.
