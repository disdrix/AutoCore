# Review B (skeptical / adversarial): `aa_0045f150` StdUninitFillN_Elem28_CountEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045f150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-L) |
| **Counterpart** | `reviews/A_aa_0045f150_StdUninitFillN_Elem28_CountEax_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack formals / stdcall | **Falsified** — bare `C3`; no stack arg loads |
| 2 | Decompiler 2-arg `__fastcall` is complete ABI | **Incomplete** — omits EAX count; bytes + parent set EAX before call |
| 3 | Same as `FUN_0046a260` fill-n | **Falsified** — different ABI (here count EAX / dest EDX / tmpl ECX; sibling count ECX / dest EAX / tmpl EBX + REP MOVSD) |
| 4 | Stride is 4 (dword fill) | **Falsified** — `ADD …,0x1C` and 7 dword stores |
| 5 | This is `basic_string` fill-assign (`00431450`) | **Falsified** — POD memcpy-style stores; no `operator=` |
| 6 | Null dest aborts whole fill | **Falsified** — still advances EDX/decrements count |
| 7 | Has callees | **Falsified** — leaf |
| 8 | Scaffold `Named_CalleeOf_*anmTrackMast*` is product | **Rejected** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI EAX/ECX/EDX | **High** | Wrong port linkage |
| Stride 0x1c + null-safe + always-advance | **High** | Memory smash / OOM path miss |
| Leaf / bare RET | **High** | Invented callees |
| Product demangle / T English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + parent

```
// StdVector_InsertN_Pod28 (FUN_0045cd30) fill path (sealed W34-P):
//   value snapshot at [ebp-0x30]
//   EAX = count; ECX = &snapshot; EDX = dest
//   call FUN_0045f150
```

Full 73 B hex:

```
568bf085f676408d421457eb038d490085d274278b39893a8b79048978f08b79088978f48b790c8978f88b79108978fc8b791489388b791889780483c21c83c01c83ee0175ca5f5ec3
```

Decompile 2026-07-29 ≡ scaffold. Parent W34-P already listed this helper among uninit-fill callees.

---

## 4. Surviving contract for AutoCore

```
// Register ABI helper — do not invent stdcall formals:
void uninit_fill_n(Elem28* dst /*EDX*/, int n /*EAX*/, const Elem28* src /*ECX*/) {
  for (; n != 0; --n) {
    if (dst) *dst = *src; // 28-byte POD assign
    ++dst;
  }
}
// Pair with insert-n hole fill; do not conflate with FUN_0046a260 or string fill-assign.
```

---

## 5. Verdict

Adversarial pass confirms A on full leaf contract. Residual product English / concrete T does not block the sealed helper → **accept**.
