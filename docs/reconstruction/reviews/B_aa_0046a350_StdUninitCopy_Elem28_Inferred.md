# Review B (skeptical / adversarial): `aa_0046a350` StdUninitCopy_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-P) |
| **Counterpart** | `reviews/A_aa_0046a350_StdUninitCopy_Elem28_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack formals / stdcall | **Falsified** — bare `C3`; no stack arg loads |
| 2 | Decompiler 2-arg `__fastcall` is complete ABI | **Incomplete** — omits EAX dest + EBX end; invents phantom param_1 |
| 3 | Same as `FUN_004673b0` uninit_copy | **Different ABI** — here EDX begin / EBX end; peer uses ECX begin / stack last |
| 4 | Same as `FUN_0046a240` copy_backward | **Falsified** — forward advance `ADD 0x1C`, not reverse `SUB` |
| 5 | Same as `FUN_0046a260` fill-n | **Falsified** — range-copy from advancing src, not template fill |
| 6 | Stride is 4 (dword copy) | **Falsified** — `ADD …,0x1C` and `MOV ECX,7` |
| 7 | Null dest aborts whole copy | **Falsified** — still advances EDX/EAX |
| 8 | Has callees | **Falsified** — leaf |
| 9 | Scaffold `Named_CalleeOf_*` is product | **Rejected** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI EAX/EDX/EBX | **High** | Wrong port linkage |
| Stride 0x1c + null-safe + always-advance | **High** | Memory smash / bad reloc |
| Leaf / bare RET / EAX out | **High** | Invented callees / triad miss |
| Product demangle / T English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + parent

```
// StdVector_InsertN_Elem28_ValueEdx (FUN_00469f50) reloc arms (W34-Q sealed):
//   EAX = dest cursor; EDX = src begin; EBX = src end
//   CALL FUN_0046a350
//   publish end from EAX (e.g. MOV [EDI+8], EAX)
```

Full 34 B hex:

```
3bd3741d565785c0740bb9070000008bf28bf8f3a583c21c83c01c3bd375e75f5ec3
```

Decompile 2026-07-29 ≡ scaffold CF (7-dword inner). W34-Q already listed this helper among ValueEdx callees.

---

## 4. Surviving contract for AutoCore

```
// Register ABI helper — do not invent stack formals:
Elem28* uninit_copy(Elem28* dst /*EAX*/, const Elem28* first /*EDX*/, const Elem28* last /*EBX*/) {
  for (; first != last; ++first, ++dst) {
    if (dst) *dst = *first; // 28-byte POD assign / REP MOVSD ×7
  }
  return dst;
}
// Pair with ValueEdx insert-n reloc; do not conflate with 004673b0, 0046a240, or 0046a260.
```

---

## 5. Verdict

Adversarial pass confirms A on full leaf contract. Residual product English / concrete T does not block the sealed helper → **accept**.
