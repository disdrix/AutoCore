# Review B (skeptical / adversarial): `aa_004cc820` MatchTargetEval_DefaultReturnFalse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc820` |
| **VA** | `0x004cc820` |
| **Review type** | Skeptical / adversarial dual residual |
| **Date** | `2026-08-05` (MEGA-030 OWN dual) |
| **Counterpart** | `reviews/A_aa_004cc820_MatchTargetEval_DefaultReturnFalse_Inferred.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

**Tools:** same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Body is non-trivial / has hidden work | Bytes `32 C0 C2 08 00` only; pad `CC` | **Falsified** — pure stub |
| 2 | Bare `RET` / void dtor style | Epilogue is `C2 08 00` not `C3` | **Falsified** — **RET 8** |
| 3 | Returns true / non-zero success | `XOR AL,AL` zeros AL | **Falsified** — always **false** |
| 4 | Uses ECX / stack formals | No memory ops / no ESP loads | **Falsified** — formals ignored |
| 5 | Direct CALL callers into body | Live adjustor sites are **JMP**; function-graph callers empty | **Falsified** — **JMP adjustors + DATA** |
| 6 | Ghidra “UNCONDITIONAL_CALL” means CALL insn | `get_assembly_context` shows `JMP 0x004cc820` | **Falsified as label** — code-flow JMP |
| 7 | This is UseItem MatchTarget `0060d7f0` | Different VA; UseItem MatchTarget is +0x38 real method | **Falsified** — do not merge |
| 8 | Same as EmptyDtorStub `0074b580` | EmptyDtor is `C3` (1 B); this is 5 B RET 8 bool | **Falsified** |
| 9 | Same as EmptyRet `0056f570` | Neighbor vtbl entry; different body | **Falsified** if claimed alias |
| 10 | Product name fully demangled | No RTTI/string on this leaf | **Survives as gap** — keep `_Inferred` |
| 11 | Only one vtbl / one type | 80 DATA xrefs across many tables | **Falsified** — **shared default** |
| 12 | `void` / no-arg signature from decompiler is authoritative | `RET 8` + dualed walker pushes 2 args | **Falsified** — decompiler under-types |
| 13 | Always-true twin at same VA | Single body; always 0 | **Falsified** |
| 14 | Slot is always exactly +0x40 on every host | Parent dual seals +0x40 for walker path; some DATA pairs may be other slots | **Partially survives** — role High, exhaustive map Open |
| 15 | Runtime Confirmed | No Launcher / no CE | **Falsified as claim** — Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / CF / always false | **High** | Port returns wrong match |
| RET 8 arity | **High** | Stack smash on call |
| Leaf / no side effects | **High** | False coupling |
| Shared default across types | **High** | Miss multi-install |
| MatchTarget family role | **High** | Wrong system placement |
| Formal English (char/world) | **Probable** | Naming only |
| Product demangle | **Open** | Naming only |
| Full slot inventory | **Open** | Overclaim +0x40 everywhere |
| Runtime | **Open** | Residual |

---

## 3. Cross-check against raw / live

| Source | Observation |
|---|---|
| Raw scaffold decompile | `return 0` — CF match |
| Live decompile 2026-08-05 | identical |
| Live disasm | `XOR AL,AL` / `RET 0x8` |
| Live memory | `32 c0 c2 08 00 cc…` |
| analyze_function_complete | classification `stub`; callees []; callers []; xref_count 86 |
| Parent dual `aa_0059d9c0` | explicitly cites `004cc820` as always-false +0x40 default |
| Partition map MEGA-030 | “MatchTarget eval stub default” |

No CF conflict. Sole reconstruction correction is **ABI arity** (decompiler void → thiscall + RET 8).

---

## 4. Surviving contract for AutoCore

```c
// Default evaluator MatchTarget virtual (many types)
// Always fail match; ignore this and args.
bool __thiscall MatchTargetEval_DefaultReturnFalse(void* self, void* a, void* b) {
    (void)self; (void)a; (void)b;
    return false;  // XOR AL,AL; RET 8
}
```

Port notes:

- **Do not** implement as bare `return;` / dtor.
- **Do** use **stdcall-clean 8** / thiscall two formals so walkers remain ABI-compatible.
- Types that need real match must override the slot (e.g. UseItem **+0x38** path) — installing this stub means **never match** on that virtual.
- MI-derived classes may route via **adjustor thunks**; keep one shared body.

---

## 5. Gaps (accepted)

1. Product/PDB English.
2. Exhaustive DATA-site slot offsets per host type.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — body/ABI/role sealed; product map residual.
