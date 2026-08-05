# Review B (skeptical / adversarial): `aa_0046a260` StdUninitFillN_Elem28_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-M) |
| **Counterpart** | `reviews/A_aa_0046a260_StdUninitFillN_Elem28_CountEcx_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack formals / stdcall | **Falsified** — bare `C3`; no stack arg loads |
| 2 | Decompiler 1-arg `__fastcall` is complete ABI | **Incomplete** — omits EAX dest + EBX template; bytes + parents set them |
| 3 | Same as `FUN_0045f150` fill-n | **Falsified** — different ABI (here count ECX / dest EAX / tmpl EBX + REP MOVSD; sibling count EAX / dest EDX / tmpl ECX + explicit stores) |
| 4 | Stride is 4 (dword fill) | **Falsified** — `ADD EAX,0x1C` and 7-dword `REP MOVSD` |
| 5 | This is `Pod28_FillAssign_Forward` (`0045efe0`) | **Falsified** — count-n + null gate vs half-open [begin,end) range |
| 6 | Null dest aborts whole fill | **Falsified** — still advances EAX / decrements count |
| 7 | Has callees | **Falsified** — leaf |
| 8 | Scaffold `Named_CalleeOf_*assPackManag*` is product | **Rejected** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI ECX/EAX/EBX | **High** | Wrong port linkage |
| Stride 0x1c + null-safe + always-advance | **High** | Memory smash / OOM path miss |
| Leaf / bare RET | **High** | Invented callees |
| Product demangle / T English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + parents

```
// FUN_00469c80 single-append (bytes @ 0x00469cdb):
//   ECX = 1; EAX = end; EBX = value*; call FUN_0046a260; end += 0x1c

// FUN_00469f50 InsertN ValueEdx (W34-Q sealed):
//   fill-n hole/realloc arms call FUN_0046a260 with count/dest/tmpl registers
```

Full 34 B hex:

```
85c9761d568bd15785c0740bb9070000008bf38bf8f3a583c01c83ea0175e95f5ec3
```

Decompile 2026-07-29 ≡ scaffold. Parent W34-Q already listed this helper among fill-n callees.

---

## 4. Surviving contract for AutoCore

```
// Register ABI helper — do not invent stdcall formals:
void uninit_fill_n(Elem28* dst /*EAX*/, int n /*ECX*/, const Elem28* src /*EBX*/) {
  for (; n != 0; --n) {
    if (dst) *dst = *src; // 28-byte POD assign (REP MOVSD ×7)
    ++dst;
  }
}
// Pair with ValueEdx insert-n hole fill; do not conflate with FUN_0045f150 (diff ABI).
```

---

## 5. Verdict

Adversarial pass confirms A on full leaf contract. Residual product English / concrete T does not block the sealed helper → **accept**.
